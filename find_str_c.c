#include <stdio.h>
#include <string.h> 
int find_str_c(char* string, char* sub){
  int j,k,res;
  int i = 0;
  
  while(string[i] != '\0'){ // While not end of array
    if(string[i] == sub[0]){
      j = i + 1; // start from i + 1 
      k = 1; // Start k from 1
      res = i; // Return index
      while(string[j] == sub[k]){ 
	if(sub[k+1] == '\0'){ // If last value of substring
	  return res;
	}
	j += 1;
	k += 1;
      }      
    }
    i += 1;
  }
  return -1;
}
