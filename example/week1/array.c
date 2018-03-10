#include <stdio.h>

int main(void)
{
    int first[5] = {1, 2, 3, 4, 5};
    int second[5] = {0, };

    second[0] = 5;
    second[1] = 4;

    return 0;
}
