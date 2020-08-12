import numpy as np
from matplotlib import pyplot as plt

class Game:
    def __init__(self, *args):
        self.players = [arg for arg in args]
        self.payoffs = [[(3, 3), (1, 4)], [(4, 1), (2, 2)]]
        self.strategies_history = [[0 for i in range(10)], [0 for i in range(10)]]
        self.results_history = [[0 for i in range(10)], [0 for i in range(10)]]
        self.num_rounds = 0

    def new_round(self):
        c1 = self.players[0].get_choice(self.strategies_history, self.results_history)
        c2 = self.players[1].get_choice(self.strategies_history, self.results_history)
        payoffs_1, payoffs_2 = self.judge(c1, c2)
        self.update_history(c1, c2, payoffs_1, payoffs_2)
        self.num_rounds += 1
        self.players[0].payoffs += payoffs_1
        self.players[1].payoffs += payoffs_2
        self.players[0].num_rounds += 1
        self.players[1].num_rounds += 1

    def judge(self, c1, c2):
        #respective choices are c1, c2
        #return a tuple of (payoffs_1, payoffs_2)
        return self.payoffs[0 if c1 < 0 else 1][0 if c2 < 0 else 1]

    def update_history(self, c1, c2, payoffs_1, payoffs_2):
        self.strategies_history[0].append(c1)
        self.strategies_history[1].append(c2)
        self.strategies_history[0].pop(0)
        self.strategies_history[1].pop(0)

        self.results_history[0].append(payoffs_1)
        self.results_history[1].append(payoffs_2)
        self.results_history[0].pop(0)
        self.results_history[1].pop(0)

    def play(self, num_rounds):
        for i in range(num_rounds):
            self.new_round()

        return (self.strategies_history, self.results_history)

        #for i in range(len(self.players)):
        #    res = 0
        #    for result in self.results_history[i]:
        #        res += result
        #    self.players[i].evaluate(float(res/10))



class Player:
    def __init__(self, initialize_weights=True, weights=None, bias=None, mutate_factor=0.1):
        self.num_layers = 3
        self.num_nodes = [10, 4, 1]
        self.payoffs = 0
        self.num_rounds = 0
        self.mutate_factor = mutate_factor
        if(initialize_weights):
            self.weights = [
                    np.random.rand(10, 40) * 2 - 1,
                    np.random.rand(4, 10) * 2 - 1,
                    np.random.rand(1, 4) * 2 - 1
            ]

            self.bias = [
                    np.random.rand(10),
                    np.random.rand(4),
                    np.random.rand(1)
            ]
        else:
            self.weights = weights
            self.bias = bias
            self.mutate()
    
    def mutate(self):
        new_weights = [
                (np.random.rand(10, 40) * 2 - 1) * self.mutate_factor,
                (np.random.rand(4, 10) * 2 - 1) * self.mutate_factor,
                (np.random.rand(1, 4) * 2 - 1) * self.mutate_factor
        ]

        new_bias = [
                (np.random.rand(10) * 2 - 1) * self.mutate_factor,
                (np.random.rand(4) * 2 - 1) * self.mutate_factor,
                (np.random.rand(1) * 2 - 1) * self.mutate_factor
        ]

        for i in range(len(self.weights)):
            self.bias[i] = np.add(new_bias[i], self.bias[i])
            self.weights[i] = np.add(new_weights[i], self.weights[i])

    def get_choice(self, strategies_history, results_history):
        #vector = self.flatten(strategies_history, results_history)
        #x = self.compute(vector, weights[0], bias[0])
        
        x = self.flatten(strategies_history, results_history)
        for i in range(len(self.weights)):
            x = self.compute(x, self.weights[i], self.bias[i])

        assert len(x) == 1
        x = int(x[0])
        return x
    
    def compute(self, input_vector, weights, bias):
        assert len(weights) == len(bias)
        output = []
        for i in range(len(weights)):
            node_sum = 0
            for j in range(len(input_vector)):
                node_sum += input_vector[j] * weights[i][j]
            output.append(-1 if node_sum < bias[i] else 1)
        return output

    def evaluate(self):
        return float(self.payoffs) / self.num_rounds

    def flatten(self, strategies_history, results_history):
        flat = []
        for i in strategies_history:
            flat += i
        for i in results_history:
            flat += i
        assert len(flat) == 40
        return flat

class Session:
    def __init__(self, num_players=100, games_per_epoch=100, num_selected=10, temperature=0.1):
        self.weights = None
        self.bias = None
        self.num_players = int(num_players)
        self.games_per_epoch = int(games_per_epoch)
        self.num_selected = num_selected
        self.temperature = temperature
        self.history = {
                'performance_history' : [],
                'strategies_history' : [[], []],
                'results_history' : [[], []]
                }

    def train(self, rounds):
        for i in range(rounds):
            self.epoch(i)

    def epoch(self, n):
        if(self.weights):
            players = [Player(
                        initialize_weights=False, 
                        weights = self.weights, 
                        bias = self.bias,
                        mutate_factor = self.temperature) for i in range(self.num_players)]
        else:
            players = [Player(
                        initialize_weights=True,
                        mutate_factor = self.temperature) for i in range(self.num_players)]

        for i in range(int(self.num_players/2)):
            game = Game(players[i], players[i + int(self.num_players/2)])
            strategies_history, results_history = game.play(100) 
            self.history['strategies_history'][0] += strategies_history[0]
            self.history['strategies_history'][1] += strategies_history[1]
            self.history['results_history'][0] += results_history[0]
            self.history['results_history'][1] += results_history[1]

            print("generation %d, pair number %d" % (n, i), end='\r')
           
        top_players = []
        performance = {index : player.evaluate() for index, player in enumerate(players)}
        for item in performance.items():
            self.history['performance_history'].append(item[1])

        sort_perf = sorted(performance.items(), key = lambda x:x[1])
        for i in range(self.num_selected):
            top_players.append(sort_perf[i][0])

        self.update_weights(players, top_players)



    def update_weights(self, players, top_players):
        weights = [
                np.zeros((10, 40)),
                np.zeros((4, 10)),
                np.zeros((1, 4))
        ]

        bias = [
                np.zeros((10)),
                np.zeros((4)),
                np.zeros((1))
        ]
        for index in top_players:
            p = players[index]
            for i in range(len(p.weights)):
                weights[i] += p.weights[i]
                bias[i] += p.bias[i]

        self.weights = [w / len(top_players) for w in weights]
        self.bias = [b / len(top_players) for b in bias]


def plot_history(history):
    plt.plot(history['results_history'][0], label="player 1 results")
    plt.plot(history['results_history'][1], label="player 2 results")
    plt.plot(history['strategies_history'][0], label="player 1 strategies")
    plt.plot(history['strategies_history'][1], label="player 2 strategies")
    plt.legend()
    plt.show()
        

if __name__ == "__main__":
    pd = Session(temperature=0.5)
    pd.train(10)
    plot_history(pd.history)




