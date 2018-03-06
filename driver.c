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
  int i;
  for(i = 1; i < size + 1; i++){
    array[i - 1] = i;
  }
}

//function used to print all values in an array
void print_values(int* array, int size){
  int i;
  for(i = 0; i < size; i++){
    if(i + 1 == size){ // If last value print value without comma
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
  
  
  if(size > 10){ // if array size is greater than 10 print only start and end values
    printf("sum_array_c({%d,%d,%d,...,%d}, %d) = %d\n", array[0], array[1], array[2], array[size-1], size,sum_c);
    printf("sum_array_s({%d,%d,%d,...,%d}, %d) = %d\n", array[0], array[1], array[2], array[size-1], size,sum_s);
  }else{ // Print all values in array
    printf("sum_array_c({");
    print_values(array, size);
    printf("}, %d) = %d\n", size, sum_c);
    
    printf("sum_array_s({");
    print_values(array, size);
    printf("}, %d) = %d\n", size, sum_s);
  }
}

//Run ARM and C function to find the max value in an array and print result 
void find_max_test(int* array, int size){
  int max_c =  find_max_c(array, size);
  int max_s =  find_max_s(array, size);
  
  if(size > 10){
    printf("find_max_c({%d,%d,%d,...,%d}, %d) = %d\n", array[0], array[1], array[2], array[size-1], size, max_c);
    printf("find_max_s({%d,%d,%d,...,%d}, %d) = %d\n", array[0], array[1], array[2], array[size-1], size, max_s);
  }else{
    printf("find_max_c({");
    print_values(array, size);
    printf("}, %d) = %d\n", size, max_c);
    
    printf("find_max_s({");
    print_values(array, size);
    printf("}, %d) = %d\n", size, max_s);
  }
}

//Function that call's test for summing array, for each array  
void run_sum_array_tests(int* array1, int* array2, int* array3, int* array4){
  printf("====== Testing summing array ======\n");
  sum_array_test(array1, 10);
  sum_array_test(array2, 10);
  sum_array_test(array3, 10);
  sum_array_test(array4, 2000);
}

//Function that call's test for finding the max value of  each array
void run_find_max_tests(int* array1, int* array2, int* array3, int* array4){
  printf("\n====== Testing find max number ======\n");
  find_max_test(array1, 10);
  find_max_test(array2, 10);
  find_max_test(array3, 10);
  find_max_test(array4, 2000);
}

// Function to print all n fibonacci sequence numbers from iterativ functions
void run_fib_iter_test(int n){
  int i;
  
  printf("\n====== Testing iterativ fibonacci sequence to: %d ======\n", n); 
  printf("fib_iter_c: ");
  for(i = 1; i <= n; i++){ // Print n fib numbers from iterativ c function
    if(i == n){
      printf("%d\n", fib_iter_c(i));   
    }else{
      printf("%d, ", fib_iter_c(i));   
    }
  }
  
  printf("fib_iter_s: ");
  for(i = 1; i <= n; i++){ // Print n fib numbers from iterativ ARM function
    if(i == n){
      printf("%d\n", fib_iter_s(i));   
    }else{
      printf("%d, ", fib_iter_s(i));   
    }
  }
}

// Function to print all n fibonacci sequence numbers from recursive functions
void run_fib_rec_test(int n){
  int i;
  
  printf("\n====== Testing recursively fibonacci sequence to: %d ======\n", n);
  printf("fib_rec_c: ");
  for(i = 1; i <= n; i++){ // Print n fib numbers from recursive c function
    if(i == n){
      printf("%d\n", fib_rec_c(i));   
    }else{
      printf("%d, ", fib_rec_c(i));   
    }
  }
  
  printf("fib_rec_s: ");
  for(i = 1; i <= n; i++){ // Print n fib numbers from recursive ARM function
    if(i == n){
      printf("%d\n", fib_rec_s(i));   
    }else{
      printf("%d, ", fib_rec_s(i));   
    }
  }
}

// Function that call's find_str_* and prints the result
void find_sub_string_test(char* string, char *substring){
  printf("find_str_c(%s, %s): %d \n", string, substring, find_str_c(string, substring));
  printf("find_str_s(%s, %s): %d \n", string, substring, find_str_s(string, substring));
}

// Function to run all test's to find a substring
void run_find_substring_tests(char* string1, char* substring1, char* string2, char* substring2, char* substring3){
  printf("\n====== Testing find substring  ======\n");
  
  find_sub_string_test(string1, substring1); // Test where sub is present
  find_sub_string_test(string1, substring2); // Test where sub is not present 
  find_sub_string_test(string2, substring3); // Test empty string
} 

// Function that creates all arrays and call's all test's
int main(int argc, char* argv){
  int array1[] = {1,2,3,4,5,6,7,8,9,10};
  int array2[] = {-5,-8,-3,-4,-1,-6,-7,-2,-9,-10};
  int array3[] = {-1,0,8,2,0,0,-2, 3, 7,-5};
  int array4[2000];
  char string1[] = "abcddfghijdde";
  char substring1[] = {"dfgh"};
  char substring2[] = {"ddee"};
  char string2[] = {" "};
  char substring3[] = {" "};
  
  populate_large_array(array4, 2000); // Populate array 4 with values from 1-2000 

  run_sum_array_tests(array1, array2, array3, array4); // Test to find sum of all the arrays
  run_find_max_tests(array1, array2, array3, array4); // Test to find max value for all arrays
  run_fib_iter_test(20); // Test first 20 fibonacci fibonacci sequence numbers
  run_fib_rec_test(20); // Test first 20 fibonacci fibonacci sequence numbers
  run_find_substring_tests(string1, substring1, string2, substring2, substring3);
 
  return 0;
}
