#include "push_swap.h"
int main()
{
    void *array;

    array = malloc(5);
    array[0] = "hello";
    array[1] = 3;

    printf("%d \n", array[1]);
    printf("%s", array[0]);
}