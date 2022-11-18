#include "caffeine_memory.h"

static AllocatorInterface* _i_caffeine_default_allocator = NULL;


void* defaul_alloc(void* context, size_t size, size_t alignment) {
	return cff_heap_alloc(size,alignment);
}

void* default_realloc(void* context, void* ptr, size_t size, size_t alignment) {
	void* out = NULL;
	cff_heap_realloc(ptr, size,alignment,&out);
	return out;
}

void default_free(void* context, void* ptr, size_t alignment) {
	cff_heap_alloc_free(ptr);
}

size_t default_size(void* context, void* ptr, size_t alignment) {
	return cff_mem_size(ptr,alignment);
}


AllocatorInterface* __cff_build_default_allocator() {
	static  AllocatorInterface default_allocator = {
		.context = 0,
		.alloc = defaul_alloc,
		.free = default_free,
		.get_size = default_size,
		.realloc = default_realloc
	};

	return &default_allocator;
}

AllocatorInterface* cff_get_default_allocator() {
	if (_i_caffeine_default_allocator == NULL)  _i_caffeine_default_allocator = __cff_build_default_allocator();
	return _i_caffeine_default_allocator;
}

void caffeine_set_default_allocator(AllocatorInterface* allocator) {
	_i_caffeine_default_allocator = allocator;
}

