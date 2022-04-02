#ifndef BIT_CONTAINER_H
#define BIT_CONTAINER_H

#include <stdlib.h>

struct bitcontainer
{
    size_t n;
    char* container;
};

typedef struct bitcontainer bitcontainer;

bitcontainer* new_bit_container(size_t n); // n - количество БИТОВ.
void delete_bit_container(bitcontainer* bit_container);

void set_bit(bitcontainer* container, int i, int value); // i - номер БИТА, к которому идет обращение.
int get_bit(bitcontainer* container, int i);

#endif
