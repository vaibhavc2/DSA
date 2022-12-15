// Everything below is in context with memory.

// Both stack and heap memory are present in RAM only... and they grow towards one another as they get larger
// (not in cache memory or cpu registers) :: these are accessible in very low level languages like assembly language


// stack memory:
// used for static memory allocation (allocated at compile time)
// contiguous and follows LIFO (Last In First Out)
// it is very limited in a machine, no matter the size of RAM (as allocated and managed by the OS of the machine)
// fast access, and simple to keep track of everything, since it is managed by a stack pointer by the OS
// Elements allocated in stack are dependent on LIFO order and can't be accessed randomly

// heap memory:
// used for dynamic memory allocation (allocated at run time)
// slower to access than stack memory
// size of heap is only limited by the size of RAM (and Virtual memory available) in a computer
// can access Randomly and as needed
// Element of the heap have no dependencies with each other and can always be accessed randomly at any time.


// ** IMP Explanation:

// To what extent are they controlled by the OS or language runtime?
// The OS allocates the stack for each system-level thread when the thread is created.
// Typically the OS is called by the language runtime to allocate the heap for the application.

// What is their scope?
// The stack is attached to a thread, so when the thread exits the stack is reclaimed. The heap is typically allocated at application startup by the runtime, and is reclaimed when the application (technically process) exits.

// What determines the size of each of them?
// The size of the stack is set when a thread is created. The size of the heap is set on application startup, but can grow as space is needed (the allocator requests more memory from the operating system).

// What makes one faster?
// The stack is faster because the access pattern makes it trivial to allocate and deallocate memory from it (a pointer/integer is simply incremented or decremented), while the heap has much more complex bookkeeping involved in an allocation or deallocation. Also, each byte in the stack tends to be reused very frequently which means it tends to be mapped to the processor's cache, making it very fast. Another performance hit for the heap is that the heap, being mostly a global resource, typically has to be multi-threading safe, i.e. each allocation and deallocation needs to be - typically - synchronized with "all" other heap accesses in the program.
// while the stack is allocated by the OS when the process starts (assuming the existence of an OS), it is maintained inline by the program. This is another reason the stack is faster, as well - push and pop operations are typically one machine instruction, and modern machines can do at least 3 of them in one cycle, whereas allocating or freeing heap involves calling into OS code

// You can use the stack if you know exactly how much data you need to allocate before compile time and it is not too big. You can use heap if you don't know exactly how much data you will need at runtime or if you need to allocate a lot of data.

// In a multi-threaded situation each thread will have its own completely independent stack but they will share the heap. Stack is thread specific and Heap is application specific. The stack is important to consider in exception handling and thread executions.