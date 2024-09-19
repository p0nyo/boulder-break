#include <stdio.h>
#define CAVE_SIZE 10

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
    int count = 0;
    for (int i = 1; i < CAVE_SIZE-1; i++) {
        for (int j = 1; j < CAVE_SIZE-1; j++) {
            if (cave[i][j] == -1) {
                count++;
            }
        }
    }
    if ((cave[0][0] == -1) || (cave[0][CAVE_SIZE-1] == -1) || (cave[CAVE_SIZE-1][0] == -1) || (cave[0][CAVE_SIZE-1] == -1)) {
        count++;
    }
    if (count > 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int main()
{
    int caveB[CAVE_SIZE][CAVE_SIZE] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, -1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    printf("%d", IsExitAccessible(caveB));
}