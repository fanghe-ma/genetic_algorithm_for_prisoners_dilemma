# Genetic algorithm for prisoners' dilemma simulation 

## Main features

Based on perceptrons that take in past history of play and corresponding results as inputs. This corresponds to the assumption of common knowledge. Players make decision at each round without knowledge of opponent's current play, this corresponds to the simultaneous nature of games.

For the first epoch, weights and biases are initiated randomly. In each epoch, 100 players are instantiated. Each of the 50 pairs play for 100 rounds, and the 10 best performing players are selected. Their weights and biases are averaged, and are used to instantiate the next batch.

When instantiating new players, weights are allowed to fluctuate between 0.1 to introduce variation. 

## Results

During initial fluctuation phase, players vary between cooperating and defecting at irregular intervals.

This is followed by 2 subsequent phases where players simultaneously cooperate, and then a period where players simultaneously defect.

The players eventually settle on alternating between paretto efficient outcome and Nash Equilibrium. 

