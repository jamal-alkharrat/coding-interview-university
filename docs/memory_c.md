# Memory in C

[Memory Layout of C Programs](https://www.geeksforgeeks.org/c/memory-layout-of-c-program/)

Stack
..
..
..
Heap
Uninitialized global/static variables (BSS) 
Initialized global/static variables 
Text (code)

## Stack Segment

stack stores local variables, function parameters, and return addresses for each function call.
Each function call creates a stack frame in this segment
When the stack and heap meet, the program’s free memory is exhausted

## Heap

is used for dynamic memory allocation
malloc(), realloc(), and free()


