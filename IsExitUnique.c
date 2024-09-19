#define CAVE_SIZE 10

int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE]) 
{
    int count = 0;
    for (int i = 0; i < CAVE_SIZE; i++) {
        for (int j = 0; j < CAVE_SIZE; j++) {
            if (cave[i][j] == -1) {
                count++;
            }
        }
    }
    if (count == 1) {
        return 1;
    }
    else {
        return 0;
    }
}