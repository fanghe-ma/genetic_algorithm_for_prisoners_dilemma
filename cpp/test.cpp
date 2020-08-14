#include <iostream>
#include <time.h>
#include "matrix.h"
#include "queue.h"
#include "player.h"

using namespace std;

int main(){
   //setup
   srand((unsigned) time(NULL));
   cout.setf(6);
   int array[3] = {10, 4, 1};
   Queue qarray[4];

   Player p1(20, 3, array);
   cout << p1.choose(qarray, 4) << endl;;

   return 0;
}
