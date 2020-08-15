#include <iostream>
#include <time.h>
#include "matrix.h"
#include "queue.h"
#include "player.h"
#include "game.h"

using namespace std;

int main(){
   //setup
   srand((unsigned) time(NULL));
   cout.setf(6);
   int array[3] = {10, 4, 1};

   Player p1(20, 3, array);

   Game g = Game();
   cout << g << endl;
   g.round(p1.choose(&(g.history), 4), p1.choose(&(g.history), 4));
   cout << g << endl;

   return 0;
}
