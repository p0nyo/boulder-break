#define CAVE_SIZE 10

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
            if (cave[i][j] == '2') {
                player.x = i;
                player.y = j;
            }
        }
    }
    // Determines which direction player is moving
    if (move == 'w') {
        player.y++;
    }
    else if (move == 'a') {
        player.x--;
    }
    else if (move == 's') {
        player.y--;
    }
    else if (move == 'd') {
        player.x++;
    }
    // If player walks into empty space or treasure
    if (cave[player.x][player.y] == 0 || cave[player.x][player.y] == 4) {
        for (int i = 0; i < CAVE_SIZE; i++) {
            for (int j = 0; j < CAVE_SIZE; j++) {
                if (cave[i][j] == 2) {
                    cave[i][j] = 0;
                }
            }
        }
        cave[player.x][player.y] = 2;
    }
    // If player walks through the exit
    if (cave[player.x][player.y] == -1) {
        return 2;
    }
    // If player walks into a hole
    else if (cave[player.x][player.y] == 3) {
        return 1;
    }
    else {
        return 0;
    }
    // If player pushes/walks into a boulder
    if (cave[player.x][player.y] == 5) {
        cave[player.x][player.y] = 0;
        while (cave[player.x][player.y] != 1 || cave[player.x][player.y] <= 3 || cave[player.x][player.y] != 4 || cave[player.x][player.y] != 5) {
            cave[player.x][player.y] = 0;
            if (move == 'w') {
                player.y++;
                if (cave[player.x][player.y+1] == 1 || cave[player.x][player.y+1] == 4 || cave[player.x][player.y+1] == 5) {
                    cave[player.x][player.y] = 5;
                }
            }
            else if (move == 'a') {
                player.x--;
                if (cave[player.x-1][player.y] == 1 || cave[player.x-1][player.y] == 4 || cave[player.x-1][player.y] == 5) {
                    cave[player.x][player.y] = 5;
                }
            }
            else if (move == 's') {
                player.y--;
                if (cave[player.x][player.y-1] == 1 || cave[player.x][player.y-1] == 4 || cave[player.x][player.y-1] == 5) {
                    cave[player.x][player.y] = 5;
                }
            }
            else if (move == 'd') {
                player.x++;
                if (cave[player.x+1][player.y] == 1 || cave[player.x+1][player.y] == 4 || cave[player.x+1][player.y] == 5) {
                    cave[player.x][player.y] = 5;
                }
            }
            if (cave[player.x][player.y] == 3) {
                cave[player.x][player.y] = 0;
            }
        }
    }  
    
}

int main() 
{
    
}