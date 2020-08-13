#include <iostream>
#include <time.h>
#include "matrix.h"
#include "queue.h"
#include "player.h"

using namespace std;

int main(){
   srand((unsigned) time(NULL));
   Queue q1(5);
   cout << q1 << endl;
   Matrix m1(q1);
   cout << m1 << endl;

   int array[3] = {10, 4, 1};
   Queue qarray[4];
   for(int i = 0; i < 4; i++){
      qarray[i] = Queue(5);
   }

   Player p1(10, 3, array);
   cout << "choosing: " << endl;
   cout << p1.choose(qarray, 4) << endl;;

   return 0;
}
