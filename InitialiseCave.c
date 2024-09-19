#include <stdio.h>
#define CAVE_SIZE 10


void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout)
{
    int count = 0;
    for (int i = 0; i < CAVE_SIZE; i++) {
        for (int j = 0; j < CAVE_SIZE; j++) {
            if (layout[count] == '1') {
                cave[i][j] = 1;
                count++;
            }
            else if (layout[count] == '0') {
                cave[i][j] = 0;
                count++;
            }
            else if (layout[count] == 'E') {
                cave[i][j] = -1;
                count++;
            }
        }
    }
}