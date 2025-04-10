*Features*: simple, portable, middle level, procedural, provides memory management, supports low-level operations

*Data types*: Basic (int, char, float, double), Derived (array, structure, union, enumeration), User-defined (struct, union)
Union: a data structure that can store different data types in the same memory location, but only one at a time
Enumeration: a user-defined data type that consists of a set of named integer constants

*Use of static functions*: those functions have scope restricted to the function in which they are declared
*Use of static variables*: those variables retain their value even after the function has exited

*Dynamic memory allocation functions*: malloc(), calloc(), realloc(), free()
malloc(): allocates a specified number of bytes and returns a pointer to the first byte
calloc(): allocates memory for an array of elements, initializes them to zero, and returns a pointer to the first element       
realloc(): changes the size of previously allocated memory block
free(): deallocates memory that was previously allocated

*Pointers*: variables that store memory addresses
*Dangling pointer*: pointer that points to a memory location that has been freed or is no longer valid
*Double pointer*: pointer that points to another pointer

*memory leak*: occurs when a program allocates memory but fails to deallocate it, leading to wasted memory resources

*Call by value*: passing a copy of the variable's value to the function
*Call by reference*: passing the address of the variable to the function (allows the function to modify the original variable)

*Storage classes*: automatic, static, external, register

*Macros Vs Functions*:
- Macros are preprocessed, functions are compiled
- Macros execution is faster than functions
- Macro name is replaced by macro value before compilation, function implies transfer control during function call
- Macros increase code length, functions do not

