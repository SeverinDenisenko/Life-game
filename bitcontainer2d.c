#include <stdlib.h>
#include "bitcontainer2d.h"

bitcontainer2d* new_bit_container2d(size_t m, size_t n){
    bitcontainer2d* container = (bitcontainer2d*) malloc(sizeof(bitcontainer2d));
    container->m = m;
    container->n = n;
    container->container = (bitcontainer**) malloc(sizeof(bitcontainer*) * m);
    for (size_t i = 0; i < n; i++)
    {
        container->container[i] = new_bit_container(n);
    }
    return container;
}

void delete_bit_container2d(bitcontainer2d* bit_container2d){
    for (size_t i = 0; i < bit_container2d->m; i++)
    {
        delete_bit_container(bit_container2d->container[i]);
    }
    free(bit_container2d);
}

void set_bit_2d(bitcontainer2d *container, int x, int y, int value){
    set_bit(container->container[y], x, value);
}

int get_bit_2d(bitcontainer2d *container, int x, int y){
    return get_bit(container->container[y], x);
}

