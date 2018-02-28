#include <stdio.h>


int fib_iter_c(int n){
  int f1=0;
  int f2=1;
  int f;
  if(n <= 1){
    return 1;
  }else{
    for(int i = 1; i < n; i++){
      f = f1+f2;
      f1 = f2;
      f2 = f;
    }
    return f; 
  }
}



