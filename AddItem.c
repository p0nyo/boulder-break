#define CAVE_SIZE 10

void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element) 
{
    // Blank space is empty room (0) or exit (-1)
    // # is solid wall (1)
    // X is a player (2)
    // * is a hole (3)
    // + is treasure (4)
    // O is a boulder (5)
    int count = 0;
    if (cave[row][col] == 0){
        if (strcmp(element, "player") == 0) {
            for (int i = 0; i < CAVE_SIZE; i++) {
                for (int j = 0; j < CAVE_SIZE; j++) {
                    if (cave[i][j] == 2) {
                        count++;
                    }
                }
            }
            if (count == 0) {
                cave[row][col] = 2;
            }
        }
        if (strcmp(element, "hole") == 0) {
            cave[row][col] = 3;
        }
        if (strcmp(element, "treasure") == 0) {
            cave[row][col] = 4;
        }
        if (strcmp(element, "boulder") == 0) {
            cave[row][col] = 5;
        }

    }
}