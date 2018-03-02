
#include <stdio.h>
int sum_array_s(int *array, int n);
int sum_array_c(int *array, int n);
int find_max_c(int *array, int n);
int find_max_s(int *array, int n);
int fib_iter_c(int n);
int fib_iter_s(int n);
int fib_rec_c(int n);
int fib_rec_s(int n);
int find_str_c(char* string, char* substring);
int find_str_s(char* string, char* substring);

//Function used to populate large arrays
void populate_large_array(int* array, int size){
  for(int i = 1; i < size + 1; i++){
    array[i-1] = i;
  }
}

//function used to print all values in an array
void print_values(int* array, int size){
    for(int i = 0; i < size; i++){
      if(i+1 == size){
	printf("%d", array[i]);
      }else{
	printf("%d,", array[i]);
      }
    }
}

//Run ARM and C function to find the sum of an array and print result 
void sum_array_test(int* array, int size){
  int sum_c =  sum_array_c(array, size);
  int sum_s =  sum_array_s(array, size);
  
  if(size > 10){
    printf("sum_array_c({%d,%d,%d,...,%d},%d) = %d\n", array[0], array[1], array[2], array[size-1], size,sum_c);
    printf("sum_array_s({%d,%d,%d,...,%d},%d) = %d\n", array[0], array[1], array[2], array[size-1], size,sum_s);
  }else{
    printf("sum_array_c({");
    print_values(array, size);
    printf("},%d) = %d\n", size, sum_c);
    
    printf("sum_array_s({");
    print_values(array, size);
    printf("},%d) = %d\n", size, sum_s);
  }
}

//Run ARM and C function to find the max value in an array and print result 
void find_max_test(int* array, int size){
  int max_c =  find_max_c(array, size);
  int max_s =  find_max_s(array, size);
  
  if(size > 10){
    printf("find_max_c({%d,%d,%d,...,%d},%d) = %d\n", array[0], array[1], array[2], array[size-1], size, max_c);
    printf("find_max_s({%d,%d,%d,...,%d},%d) = %d\n", array[0], array[1], array[2], array[size-1], size, max_s);
  }else{
    printf("find_max_c({");
    print_values(array, size);
    printf("},%d) = %d\n", size, max_c);
    
    printf("find_max_s({");
    print_values(array, size);
    printf("},%d) = %d\n", size, max_s);
  }
}


//Function that call's test for summing array, for each array  
void print_sum_array_test(int* array1, int* array2, int* array3, int* array4){
  printf("\n====== Testing summing array ======\n");
  sum_array_test(array1,10);
  sum_array_test(array2,10);
  sum_array_test(array3,10);
  sum_array_test(array4,2000);
}

//Function that call's test for finding the max value of  each array
void print_find_max_test(int* array1, int* array2, int* array3, int* array4){
  printf("\n====== Testing find max number ======\n");
  find_max_test(array1,10);
  find_max_test(array2,10);
  find_max_test(array3,10);
  find_max_test(array4,2000);
}

void print_fib_iter(int n){
  printf("\n====== Testing iterativ fibonacci sequence to: %d ======\n", n);
  printf("fib_iter_c: ");
  for(int i = 1; i <= n; i++){
    if(i==n){
      printf("%d", fib_iter_c(i));   
    }else{
      printf("%d, ", fib_iter_c(i));   
    }
    
  }
  printf("\n");
  printf("fib_iter_s: ");
  for(int i = 1; i <= n; i++){
    if(i == n){
      printf("%d", fib_iter_s(i));   
    }else{
    printf("%d, ", fib_iter_s(i));   
    }

  }
  printf("\n");
}

void print_fib_rec(int n){
  printf("\n====== Testing recursively fibonacci sequence to: %d ======\n", n);
  printf("fib_rec_c: ");
  for(int i = 1; i <= n; i++){
    if(i==n){
      printf("%d", fib_rec_c(i));   
    }else{
      printf("%d, ", fib_rec_c(i));   
    }
  }
  printf("\n");
  printf("fib_rec_s: ");
  for(int i = 1; i <= n; i++){
    if(i == n){
      printf("%d", fib_rec_s(i));   
    }else{
    printf("%d, ", fib_rec_s(i));   
    }
  }
  printf("\n");
}

void print_find_sub_string(char* string, char *substring){
  printf("find_str_c(%s,%s): %d \n", string, substring, find_str_c(string,substring));
  printf("find_str_s(%s,%s): %d \n", string, substring, find_str_s(string,substring));
}

// Function that creates all arrays and calls all test's
int main(int argc, char* argv){
  int array1[] = {1,2,3,4,5,6,7,8,9,10};
  int array2[] = {-5,-8,-3,-4,-1,-6,-7,-2,-9,-10};
  int array3[] = {-1,0,8,2,0,0,-2, 3, 7,-5};
  int array4[2000];
  char string1[14] = "abcddfghijdde";
  char substring1[5] = {"dfgh"};
  char string2[14] = "abcddfghijdde";
  char substring2[5] = {"ddee"};
  populate_large_array(array4,2000);

  print_sum_array_test(array1,array2,array3,array4);
  print_find_max_test(array1,array2,array3,array4);
  print_fib_iter(20);  
  print_fib_rec(20);
  print_find_sub_string (string1, substring1);
  print_find_sub_string (string2, substring2);
  

  return 0;
}
