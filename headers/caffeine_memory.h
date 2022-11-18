#ifndef CAFFEINE_MEMORY_H
#define CAFFEINE_MEMORY_H

#include "caffeine_flags.h"

#if CFF_COMP == MSVC
#include <malloc.h>
#include <memory.h>
#endif // CFF_COMP == MSVC

#include <stdlib.h>

struct AllocatorInterface_s
{
	void* (*alloc)(void* context, size_t size, size_t alignment);
	void* (*realloc)(void* context, void* ptr, size_t size, size_t alignment);
	void (*free)(void* context, void* ptr, size_t alignment);
	size_t (*get_size)(void* context, void* ptr, size_t alignment);
	void* context;
};

typedef struct AllocatorInterface_s AllocatorInterface;

void* cff_allocator_alloc(AllocatorInterface* allocator, size_t size, size_t alignment);
int cff_allocator_realloc(AllocatorInterface* allocator, void* ptr, size_t size, size_t alignment, void** out);
void cff_allocator_free(AllocatorInterface* allocator, void* ptr, size_t alignment);
size_t cff_allocator_mem_size(AllocatorInterface* allocator, void* ptr, size_t alignment);

// default allocator
AllocatorInterface* cff_get_default_allocator();
void caffeine_set_default_allocator(AllocatorInterface* allocator);

//heap
void* cff_heap_alloc(size_t size, size_t alignment);
int cff_heap_realloc(void* ptr, size_t size, size_t alignment, void** out);
void cff_heap_alloc_free(void* ptr);

//stack
void* cff_stack_alloc(size_t size);
int cff_stack_realloc(void* ptr, size_t old_size, size_t size, void** out);
void cff_stack_alloc_free(void* ptr);

//utils
size_t cff_mem_size(void* ptr, size_t alignment);

int cff_memcmp(const void* a, const void* b, size_t size);
void cff_memcpy(const void* const src, void* const dest, size_t src_size, size_t dest_size);
void cff_memmove(const void* const src, void* const dest, size_t src_size, size_t dest_size);
void cff_memset(void* dest, int value, size_t size);

int cff_memcmp_8(const void* const a, const void* const b, size_t size);
int cff_memcmp_16(const void* const a, const void* const b, size_t size);
int cff_memcmp_32(const void* const a, const void* const b, size_t size);
int cff_memcmp_64(const void* const a, const void* const b, size_t size);

void cff_memcpy_8(const void* const src, void* const dest, size_t size);
void cff_memcpy_16(const void* const src, void* const dest, size_t size);
void cff_memcpy_32(const void* const src, void* const dest, size_t size);
void cff_memcpy_64(const void* const src, void* const dest, size_t size);

void cff_memset_8(void* const dest, char value, size_t size);
void cff_memset_16(void* const dest, short value, size_t size);
void cff_memset_32(void* const dest, int value, size_t size);
void cff_memset_64(void* const dest, long long int value, size_t size);

#endif