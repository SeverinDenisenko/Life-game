#include "bitcontainer.h"
#include <stdlib.h>

bitcontainer* new_bit_container(size_t n){
    bitcontainer* container = (bitcontainer*) malloc(sizeof(bitcontainer));
    container->n = n;
    container->container = malloc((n + 7) / 8);

    return container;
}

void delete_bit_container(bitcontainer* container){
    free(container->container);
    free(container);
}

void set_bit(bitcontainer *container, int i, int value)
{
    int byte = i / 8;
    char mask = 1 << (i % 8);
    if (value)
        container->container[byte] |= mask;
    else
        container->container[byte] &= ~mask;
}

int get_bit(bitcontainer *container, int i)
{
    int byte = i / 8;
    char mask = 1 << (i % 8);
    return container->container[byte] & mask ? 1 : 0; 
}
