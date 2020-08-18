#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include "queue.h"

class Game{
   private:
      static float payoffs[2][2][2];
      Queue history[4]; //results 1, results 2, history 1, history 2
      friend class Player;
   public:
      Game();
      ~Game();
      void round(float c1, float c2);
      const Queue * get_history()const;

      friend std::ostream & operator<<(std::ostream & os, const Game & g);
};

#endif
