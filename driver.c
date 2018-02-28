
#include <stdio.h>
int sum_array_s(int *array, int n);
int sum_array_c(int *array, int n);
int find_max_c(int *array, int n);
int find_max_s(int *array, int n);
int fib_iter_c(int n);
int fib_iter_s(int n);
int fib_rec_c(int n);
int fib_rec_s(int n);


int main(int argc, char* argv){
  int array_size = 5;
  int array[5] = {1,2,5,4,3};
  int res;

  res  = sum_array_c(array, array_size);
  printf("sum_array_c({1,2,5,4,3},5) = %d\n", res);
  res  = sum_array_s(array, array_size);
  printf("sum_array_s({1,2,5,4,3},5) = %d\n", res);
  res  = find_max_c(array, array_size);
  printf("find_max_c({1,2,5,4,3},5) = %d\n", res);
  res  = find_max_s(array, array_size);
  printf("find_max_s({1,2,5,4,3},5) = %d\n", res);
  printf("fib_iter_c(20)\n");
    for(int i = 1; i <= 20; i++){
      printf(" %d ",fib_iter_c(i));
    }
    printf("\n");

    printf("fib_iter_s(20)\n");
    for(int i = 1; i <= 20; i++){
      printf(" %d ",fib_iter_s(i));
    }
    printf("\n");

    printf("fib_rec_c(20)\n");
    for(int i = 1; i <= 20; i++){
      printf(" %d ",fib_rec_c(i));
    }
    printf("\n");

        printf("fib_rec_s(20)\n");
    for(int i = 1; i <= 20; i++){
      printf(" %d ",fib_rec_s(i));
    }
    printf("\n");
  


  fib_iter_c(20);
  return 0;
}
