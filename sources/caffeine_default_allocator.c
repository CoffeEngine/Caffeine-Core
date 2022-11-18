#include "caffeine_memory.h"

static AllocatorInterface* _i_caffeine_default_allocator = NULL;


void* defaul_alloc(void* context, size_t size, size_t alignment) {
	return malloc(size);
}

void* default_realloc(void* context, void* ptr, size_t size, size_t alignment) {
	return realloc(ptr, size);
}

void default_free(void* context, void* ptr, size_t alignment) {
	free(ptr);
}

size_t default_size(void* context, void* ptr, size_t alignment) {
#if CFF_COMP == MSVC
	return _msize(ptr);
#endif
	return 0;
}

void* defaul_alloc_a(void* context, size_t size, size_t alignment) {
#if CFF_COMP == MSVC
	return _aligned_malloc(size, alignment);
#endif
}

void* default_realloc_a(void* context, void* ptr, size_t size, size_t alignment) {
#if CFF_COMP == MSVC
	return _aligned_realloc(ptr, size, alignment);
#endif
}

void default_free_a(void* context, void* ptr, size_t alignment) {
#if CFF_COMP == MSVC
	_aligned_free(ptr);
#endif
}

size_t default_size_a(void* context, void* ptr, size_t alignment) {
#if CFF_COMP == MSVC
	return _aligned_msize(ptr, alignment, 0);
#endif
	return 0;
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

