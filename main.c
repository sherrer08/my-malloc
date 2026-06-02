#include <stddef.h>
#include <unistd.h>

typedef struct Block {
    size_t size;
    int is_free;
    struct Block* next;
} Block;

static Block* free_list  = NULL;

void* my_malloc(size_t size) {
    // 1. Search the free list for a big enough block
    Block* curr = free_list;
    while (curr != NULL) {
        if (curr->is_free && curr->size >= size) {
            curr->is_free = 0;
            return (void*)(curr + 1);
        }
        curr = curr->next;
    }

    // 2. No block found - ask OS for more memory
    Block* block = sbrk(sizeof(Block) + size);
    block->size = size;
    block->is_free = 0;
    block->next = free_list;
    free_list = block;

    return (void*)(block + 1);
}

void my_free(void* ptr) {
    // Step back to find the header
    Block* block = (Block*)ptr - 1;
    block->is_free = 1;
}