#define CAVE_SIZE 10

int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
    int k, flag = 0;
    k = CAVE_SIZE-1;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < CAVE_SIZE; j++){
            if (cave[i*k][j] == 0) {
                flag++;
            }
        }
    }
    for (int i = 1; i < CAVE_SIZE-2; i++){
        for (int j = 0; j < 2; j++){
            if (cave[i][j*k] == 0) {
                flag++;
            }
        }
    }   
    if (flag > 0) {
        return 0;
    }
    else {
        return 1;
    }
}