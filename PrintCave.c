#define CAVE_SIZE 10

void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
    // Blank space is empty room (0) or exit (-1)
    // # is solid wall (1)
    // X is a player (2)
    // * is a hole (3)
    // + is treasure (4)
    // O is a boulder (5)
    int count = 1;
    printf("\n");
    for (int i = 0; i < CAVE_SIZE; i++) {
        for (int j = 0; j < CAVE_SIZE; j++) {
            if (cave[i][j] == 0 || cave[i][j] == -1) {
                if (count%10 == 0) {
                    printf(" \n");
                }
                else {
                    printf(" ");
                }
                count++;
            }
            else if (cave[i][j] == 1) {
                if (count%10 == 0) {
                    printf("#\n");
                }
                else {
                    printf("#");
                }
                count++;
            }
            // player
            else if (cave[i][j] == 2) {
                printf("X");
                count++;
            }
            // hole
            else if (cave[i][j] == 3) {
                printf("*");
                count++;
            }
            // treasure
            else if (cave[i][j] == 4) {
                printf("+");
                count++;
            }
            // boulder
            else if (cave[i][j] == 5) {
                printf("O");
                count++;
            }
        }
    }
}

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