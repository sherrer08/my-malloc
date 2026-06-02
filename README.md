# Custom Memory Allocator

A simple implementation of malloc and free in C using a free list 
and sbrk() system call for educational purposes.

## Concepts Demonstrated
- Heap memory management
- Linked list free list
- Pointer arithmetic
- Systems programming in C

## Known Limitations / Future Improvements
- sbrk() is deprecated on modern systems
- No block splitting or coalescing
- No error handling for failed allocations