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
   int array[] = {10, 4, 1};
   float c1, c2;

   Player p1(20, 3, array);
   Player p2(20, 3, array);

   Game g = Game();

   for(int i = 0; i < 10; i++){
//      c1 = p1.choose(g.get_history(), 4);
//      c2 = p2.choose(g.get_history(), 4);
      c1 = p1.choose(g);
      cout << "c1: " << c1 << endl;
      c2 = p2.choose(g);
      cout << "c2: " << c2 << endl;
      g.round(c1, c2);
      cout << g << endl;
   }

   Queue history[4];


   return 0;
}
