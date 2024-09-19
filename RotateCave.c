#define CAVE_SIZE 10

void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE]) 
{
    int temp[CAVE_SIZE][CAVE_SIZE], temprows = -1, tempcols = -1;
    // cols
    for (int cols = 0; cols < CAVE_SIZE; cols++) {
        temprows++;
        // rows
        for (int rows = CAVE_SIZE-1; rows >= 0; rows--) {
            tempcols++;
            temp[temprows][tempcols] = cave[rows][cols];
            // printf("%d\n", cave[rows][cols]);
        }
        tempcols = -1;
    }
    for (int i = 0; i < CAVE_SIZE; i++) {
        for (int j = 0; j < CAVE_SIZE; j++) {
            cave[i][j] = temp[i][j];
        }
    }
}