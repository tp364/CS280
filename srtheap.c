/*
 *
 *  srtheap.c file
 *
 */

#include <stddef.h>
#include "srt.h"

static void heapify(void *base, size_t nelem, size_t i, size_t size, int (*compar)(const void *, const void *));

void srtheap(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {
    char *qb = (char *)base;

    
    for (size_t i = nelem / 2; i > 0; --i) {
        heapify(base, nelem, i - 1, size, compar);
    }

    
    for (size_t i = nelem - 1; i > 0; --i) {
        
        swap(qb, qb + size * i, size);

        
        heapify(base, i, 0, size, compar);
    }
}

static void heapify(void *base, size_t nelem, size_t i, size_t size, int (*compar)(const void *, const void *)) {
    char *qb = (char *)base;
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    
    if (left < nelem && compar(qb + size * left, qb + size * largest) > 0) {
        largest = left;
    }

    
    if (right < nelem && compar(qb + size * right, qb + size * largest) > 0) {
        largest = right;
    }

    
    if (largest != i) {
        swap(qb + size * i, qb + size * largest, size);

        
        heapify(base, nelem, largest, size, compar);
    }
}
