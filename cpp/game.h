#ifndef GAME_H_
#define GAME_H_
#include <iostream>

class Game{
   private:
      float payoffs[2][2][2];
   public:
      Queue history[4]; //results 1, results 2, history 1, history 2
      Game();
      ~Game();
      void round(float c1, float c2);

      friend std::ostream & operator<<(std::ostream & os, const Game & g);
};

#endif
