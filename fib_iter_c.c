#include <stdio.h>

// Function that returns the n'th fibonacci sequence number
int fib_iter_c(int n){
  int f1 = 0;
  int f2 = 1;
  int f, i;
  
  if(n > 1){
    for(i = 1; i < n; i++){
      f = f1 + f2;
      f1 = f2;
      f2 = f;
    }
    return f; 
  }
   return 1;
}



