#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

void printarray(char grid[][23]);
bool issink(int x, int y, char grid[][23]);
bool isstable(char grid[][23]);
bool isworld(int x, int y);
void dropsand(char (*grid)[23]);
void topple(char (*grid)[23],int x, int y);
int topplecheck(char grid[][23]);



int main(){

    char g [23][23];
    int x, y;
    char size;

    for(int i = 0; i < 23; i++){
        for(int j = 0; j < 23; j++){
            g[i][j] = '0';
        }
    }

    while(x != -2 && y != -2 && size != -2){
        printf("input format: X Y (amount of sand)/#\nexample input: 0 0 8\namount of sand has to be <= 8 && > 0\nenter -2 -2 -2 to exit\n");
        scanf("%d %d %c", &x, &y, &size);
        if(size == '#'){
            g[x][y] = '#';
        }
        else{
            g[x][y] = size;
        }
    }
    printf("\n");
    while(!isstable(g)){
        topplecheck(g);
        printarray(g);
    }
}


int topplecheck(char (*grid)[23]){
    int topples = 0;
    for(int i = 0; i < 23; i++){
        for(int j = 0; j < 23; j++){
            if(grid[i][j] > '8'){
                topple(grid, i, j);
                topples++;
            }
        }
    }
    return topples;
}

void printarray(char grid[][23]){
    for(int i = 0; i < 23; i++){
        for(int j = 0; j < 23; j++){
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void dropsand(char (*grid)[23]){ 
    grid[11][11] = grid[11][11] + 1;
}

void topple(char (*grid)[23], int x, int y){
    if(grid[x][y] > '8'){
        if(isworld(x + 1, y) && grid[x + 1][y] != '#'){
            grid[x + 1][y] += 1;
        }
        if(isworld(x + 1, y - 1) && grid[x + 1][y - 1] != '#'){
            grid[x+1][y-1] += 1;
        }
        if(isworld(x, y - 1) && grid[x][y - 1] != '#'){
            grid[x][y-1] += 1;
        }
        if(isworld(x - 1, y - 1) && grid[x - 1][y - 1] != '#'){
            grid[x-1][y-1] += 1;
        }
        if(isworld(x - 1,y) && grid[x - 1][y] != '#'){
            grid[x-1][y] += 1;
        }
        if(isworld(x - 1,y + 1) && grid[x - 1][y + 1] != '#'){
            grid[x-1][y+1] += 1;
        }
        if(isworld(x,y + 1) && grid[x][y + 1] != '#'){
            grid[x][y+1] += 1;
        }
        if(isworld(x + 1,y + 1) && grid[x + 1][y + 1] != '#'){
            grid[x+1][y+1] += 1;
        }
        grid[x][y] = '1';
    }
}



bool issink(int x, int y, char grid[][23]){
    if(grid[x][y] == '#') return true;
    
    return false;
}


bool isstable(char grid[][23]){
    for(int i = 0; i < 23; i++){
        for(int j = 0; j < 23; j++){
            if(grid[i][j] > '8' && grid[i][j] != '#'){
                return false;
            }
        }
    }
    return true;
}

bool isworld(int x, int y){
    if((x < 23 && y < 23) && (x >= 0 && y >= 0)) return true;

    return false;
}