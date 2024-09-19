#include <stdio.h>
#include <string.h>
#define CAVE_SIZE 10

// DO BACKGROUND STORY FUNCTION!!!!!!
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE]);
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout);
int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE]);
int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE]);
int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE]);
void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element);
void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE]);
int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move);



int main()
{
    int caveA[CAVE_SIZE][CAVE_SIZE] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    int caveB[CAVE_SIZE][CAVE_SIZE] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 4, 0, 3, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, -1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    // int caveD[CAVE_SIZE][CAVE_SIZE] = {
    //     {1, 1, 1},
    //     {1, 0, 0},
    //     {1, 1, 1},
    // };
    // char layout[200] = "11111100011000E1000111111";
    char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111";
    int caveC[CAVE_SIZE][CAVE_SIZE] = {0};
    printf("\nCave A:\n");
    PrintCave(caveA);
    printf("\nCave B:\n");
    AddItem(caveB, 1, 1, "player");
    // AddItem(caveB, 6, 7, "player");
    AddItem(caveB, 6, 8, "hole");
    AddItem(caveB, 4, 4, "treasure");
    AddItem(caveB, 1, 2, "boulder");
    AddItem(caveB, 2, 1, "boulder");
    PrintCave(caveB);
    InitialiseCave(caveC, layout);
    printf("\nCave C:\n");
    PrintCave(caveB);
    // printf("Cave B Rotated:\n");
    // RotateCave(caveB);
    printf("\n");
    PrintCave(caveB);
    printf("\n%d\n", MakeMove(caveB, 'd'));
    // MakeMove(caveB, 's');
    PrintCave(caveB);
    MakeMove(caveB, 's');
    PrintCave(caveB);
    AddItem(caveB, 1, 2, "treasure");
    PrintCave(caveB);
    MakeMove(caveB, 'd');
    PrintCave(caveB);
    printf("\nCOMPLETE??? %d\n", IsBorderComplete(caveC));
    printf("UNIQUE????? %d\n", IsExitUnique(caveC));
    printf("ACCESSIBLE? %d", IsExitAccessible(caveC));
    

    return 0;

}


// BACKGROUND STORY FUNCTION









// BACKGROUND STORY FUNCTION




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

int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
    int k;
    k = CAVE_SIZE-1;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < CAVE_SIZE; j++){
            if (cave[i*k][j] == 0) {
                return 0;
            }
        }
    }
    for (int i = 1; i < CAVE_SIZE-2; i++){
        for (int j = 0; j < 2; j++){
            if (cave[i][j*k] == 0) {
                return 0;
            }
        }
    }   
    return 1;
}

int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE]) 
{
    int count = 0;
    for (int i = 0; i < CAVE_SIZE; i++) {
        for (int j = 0; j < CAVE_SIZE; j++) {
            if (cave[i][j] == -1) {
                count++;
                if (count > 1 || count == 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
    for (int i = 1; i < CAVE_SIZE-1; i++) {
        for (int j = 1; j < CAVE_SIZE-1; j++) {
            if (cave[i][j] == -1) {
                return 0;
            }
        }
    }
    if ((cave[0][0] == -1) || (cave[0][CAVE_SIZE-1] == -1) || (cave[CAVE_SIZE-1][0] == -1) || (cave[0][CAVE_SIZE-1] == -1)) {
        return 0;
    }
    return 1;
}

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
        else if (strcmp(element, "hole") == 0) {
            cave[row][col] = 3;
        }
        else if (strcmp(element, "treasure") == 0) {
            cave[row][col] = 4;
        }
        else if (strcmp(element, "boulder") == 0) {
            cave[row][col] = 5;
        }

    }
}

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

int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move) 
{
    typedef struct {
        int x;
        int y;
    } Coords;
    Coords player;
    // Finds player on the board
    for (int i = 0; i < CAVE_SIZE; i++) {
        for (int j = 0; j < CAVE_SIZE; j++) {
            if (cave[i][j] == 2) {
                player.x = i;
                player.y = j;
                // Player.x is the rows, so y direction
                // Player.y is the columns, so x direction
            }
        }
    }
    // Determines which direction player is moving
    if (move == 'w') {
        player.x--;
    }
    else if (move == 'a') {
        player.y--;
    }
    else if (move == 's') {
        player.x++;
    }
    else if (move == 'd') {
        player.y++;
    }
    // If player walks into empty space, treasure, hole or exit
    if (cave[player.x][player.y] == 0 || cave[player.x][player.y] == 4 || cave[player.x][player.y] == -1 || cave[player.x][player.y] == 3) {
        for (int i = 0; i < CAVE_SIZE; i++) {
            for (int j = 0; j < CAVE_SIZE; j++) {
                if (cave[i][j] == 2) {
                    cave[i][j] = 0;
                }
            }
        }
        // If player walks through the exit
        if (cave[player.x][player.y] == -1) {
            return 2;
        }
        // If player walks into a hole
        else if (cave[player.x][player.y] == 3) {
            cave[player.x][player.y] = 3;
            return 1;
        }
        else {
            cave[player.x][player.y] = 2;
            return 0;
        }
    }
    // If player pushes/walks into a boulder
    if (cave[player.x][player.y] == 5) {
        cave[player.x][player.y] = 0;
        while (cave[player.x][player.y] != 1 || cave[player.x][player.y] != 3 || cave[player.x][player.y] != 4 || cave[player.x][player.y] != 5) {
            cave[player.x][player.y] = 0;
            if (move == 'w') {
                player.x--;
                if (cave[player.x][player.y] == 1 || cave[player.x][player.y] == 3 || cave[player.x][player.y] == 4 || cave[player.x][player.y] == 5) {
                    if (cave[player.x][player.y] == 3) {
                        cave[player.x][player.y] = 0;
                        return 0;
                    }
                    cave[player.x+1][player.y] = 5;
                    return 0;
                }
            }
            else if (move == 'a') {
                player.y--;
                if (cave[player.x][player.y] == 1 || cave[player.x][player.y] == 3 || cave[player.x][player.y] == 4 || cave[player.x][player.y] == 5) {
                    if (cave[player.x][player.y] == 3) {
                        cave[player.x][player.y] = 0;
                        return 0;
                    }
                    cave[player.x][player.y+1] = 5;
                    return 0;
                }
            }
            else if (move == 's') {
                player.x++;
                if (cave[player.x][player.y] == 1 || cave[player.x][player.y] == 3 || cave[player.x][player.y] == 4 || cave[player.x][player.y] == 5) {
                    if (cave[player.x][player.y] == 3) {
                        cave[player.x][player.y] = 0;
                        return 0;
                    }
                    cave[player.x-1][player.y] = 5;
                    return 0;
                }
            }
            else if (move == 'd') {
                player.y++;
                if (cave[player.x][player.y] == 1 || cave[player.x][player.y] == 3 || cave[player.x][player.y] == 4 || cave[player.x][player.y] == 5) {
                    if (cave[player.x][player.y] == 3) {
                        cave[player.x][player.y] = 0;
                        return 0;
                    }
                    cave[player.x][player.y-1] = 5;
                    return 0;
                }
            }
        }
    }  
    return 0;
    
}





