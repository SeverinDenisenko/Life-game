#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include "bitcontainer2d.h"

int main(){
    int n = 30;
    int frame_count = 13;

    bitcontainer2d* world1 = new_bit_container2d(n, n);
    bitcontainer2d* world2 = new_bit_container2d(n, n);

    srand(time(NULL));

    #pragma omp parallel for
    for(int i = n/2 - 2; i < n - n/2 + 2; i++)
    {
        for (int j = n/2 - 2; j < n - n/2 + 2; ++j) {
            set_bit_2d(world1, i, j, rand() % 2);
        }
    }

    for (int frame = 0; frame < frame_count; ++frame) {

        #pragma omp parallel for
        for(int i = 1; i < n-1; i++)
        {
            #pragma omp parallel for
            for (int j = 1; j < n-1; ++j) {
                int tmp = get_bit_2d(world1, i + 1, j + 1) + get_bit_2d(world1, i - 1, j - 1) + 
                get_bit_2d(world1, i - 1, j + 1) + get_bit_2d(world1, i + 1, j - 1) + 
                get_bit_2d(world1, i, j + 1) + get_bit_2d(world1, i + 1, j) + 
                get_bit_2d(world1, i - 1, j) + get_bit_2d(world1, i, j - 1);

                if (tmp == 3){
                    set_bit_2d(world2, i, j, 1);
                } else if (!get_bit_2d(world1, i, j) && tmp == 2)
                {
                    set_bit_2d(world2, i, j, 1);
                } else {
                    set_bit_2d(world2, i, j, 0);
                }
                
            }
        }

        printf("Frame: %d\n", frame);
        for (size_t i = 1; i < n - 1; i++)
        {
            for (size_t j = 1; j < n - 1; j++)
            {
                if (get_bit_2d(world1, i, j))
                {
                    printf("#");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
        

        bitcontainer2d world3 = *world1;
        *world1 = *world2;
        *world2 = world3;
    }


    return 0;
}
