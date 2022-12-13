// dynamic memory allocation: (on heap)

// malloc() function:
// implemented as a linked-list in C & C++
// returns void pointer to the head of the memory block (allocated as a linked-list)
// doesn't initialize memory
// faster than calloc() in allocation

// calloc() function:
// implemented as a stack/array
// allocates contiguous blocks of memory in heap memory
// returns a void pointer to the head of the memory stack allocated on the heap memory
// is slower than malloc() in allocation
// initializes allocated memory blocks to '0'

// to implement dynamic arrays(vectors), stacks, queues and other similar DS in C language, use calloc() function & not malloc() function
// memory allocated with calloc is faster to traverse upon, since it is allocated in the form of an array of contiguous blocks - O(1)
// memory allocated with malloc is slower to traverse upon, since it is allocated in the form of a linked-list - O(n)