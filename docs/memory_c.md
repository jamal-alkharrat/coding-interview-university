# Memory in C

[Memory Layout of C Programs](https://www.geeksforgeeks.org/c/memory-layout-of-c-program/)
[Dynamic Memory Allocation in C](https://www.geeksforgeeks.org/c/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)

Stack
..
..
..
Heap
Uninitialized global/static variables (BSS) 
Initialized global/static variables 
Text (code)

## Stack Segment

Stack stores local variables, function parameters, and return addresses for each function call.
Each function call creates a stack frame in this segment
When the stack and heap meet, the program’s free memory is exhausted

## Heap

Heap is used for dynamic memory allocation
It uses malloc(), realloc(), and free()
Memory persists even after the function that allocated it finishes, allowing functions to return pointers to it. 

### malloc()

- The malloc() (stands for memory allocation) function is used to allocate a single block of contiguous memory on the heap at runtime.
- The memory allocated by malloc() is uninitialized, meaning it contains garbage values.

```bash
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int) * 5);
    
    // Checking if failed or pass
    if (ptr == NULL) {
        printf("Allocation Failed");
        exit(0);
    }
    
    // Populate the array
    for (int i = 0; i < 5; i++)
        ptr[i] = i + 1;
        
    // Print the array
    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);
    return 0;
}
```
```
```

### calloc()

- The calloc() (stands for contiguous allocation) function is similar to malloc(), but it initializes the allocated memory to zero. 
- It is used when you need memory with default zero values.

```bash
#include <stdio.h> 
#include <stdlib.h>

int main() {
    int *ptr = (int *)calloc(5, sizeof(int));
    
    // Checking if failed or pass
    if (ptr == NULL) {
        printf("Allocation Failed");
        exit(0);
    }
    
    // No need to populate as already
    // initialized to 0
        
    // Print the array
    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);
    return 0;
}
```

### free()

- The memory allocated using functions malloc() and calloc() is not de-allocated on their own. 
- The free() function is used to release dynamically allocated memory back to the operating system.
- It is essential to free memory that is no longer needed to avoid memory leaks.
- After calling free(), it is a good practice to set the pointer to NULL to avoid using a "dangling pointer," which points to a memory location that has been deallocated.

```bash
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)calloc(5, sizeof(int));
    
    // Do some operations.....
    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);
        
    // Free the memory after completing
    // operations
    free(ptr);
    
    return 0;
}
```

### realloc()

- realloc() function is used to resize a previously allocated memory block. It allows you to change the size of an existing memory allocation without needing to free the old memory and allocate a new block.
- It is important to note that if realloc() fails and returns NULL, the original memory block is not freed, so you should not overwrite the original pointer until you've successfully allocated a new block. To prevent memory leaks, it’s a good practice to handle the NULL return value carefully

```bash
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *)malloc(5 * sizeof(int));

    // Reallocation
    int *temp = (int *)realloc(ptr, 10 * sizeof(int));

    // Only update the pointer if reallocation is successful
    if (temp == NULL)
        printf("Memory Reallocation Failed\n");
    else
        ptr = temp;

    return 0;
}
```

## Loops

- entry-controlled loop, which means that the condition is checked before the loop's body executes.
- exit-controlled loop, which means that the condition is checked after executing the loop body. Due to this, the loop body will execute at least once irrespective of the test condition.


