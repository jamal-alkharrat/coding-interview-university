// Implement a vector (mutable array with automatic resizing)
#include <stdio.h>
#include <stdlib.h> 
int main() { 
  int i = 0; 
  for (i=0; i<20; i++) { 
    printf("i = %d\n", i); 
    switch(i) { 
      case 0: printf("Case 0: %d\n",i);i += 5; printf("Case 0: %d\n",i);
      case 1: printf("Case 1: %d\n",i);i += 2; printf("Case 1: %d\n",i);
      case 5: printf("Case 5: %d\n",i);i += 5; printf("Case 5: %d\n",i);
      default: printf("Default: %d\n",i);i += 4; printf("Default: %d\n",i); break; 
    } 
    printf("result = %d\n", i); 
  } 
  return 0; 
}
