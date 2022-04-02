#ifndef BIT_CONTAINER_2D_H
#define BIT_CONTAINER_2D_H

#include <stdlib.h>
#include "bitcontainer.h"

struct bitcontainer2d
{
    size_t m;
    size_t n;
    bitcontainer** container; // Имеет длинну m
};

typedef struct bitcontainer2d bitcontainer2d;

bitcontainer2d* new_bit_container2d(size_t m, size_t n); // m, n - размеры матрицы в БИТАХ.
void delete_bit_container2d(bitcontainer2d* bit_container2d);

void set_bit_2d(bitcontainer2d *container, int x, int y, int value); // x, y - индексы БИТОВ в матрице.
int get_bit_2d(bitcontainer2d *container, int x, int y);

#endif
