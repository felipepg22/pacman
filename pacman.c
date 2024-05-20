#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pacman.h"
#include "file-helper.h"

struct map gameMap;

int main() {   

    FILE* file = fopen("mapa.txt", "r");

    if (file == 0) {
        printf("Failed to read file for gameMap");
        exit(1);
    }    

    gameMap.lines = countLines(file);    
    gameMap.columns = 10;   
    
    allocateMemory();
    readFileForGameMap(file);   
    do
    {           

        for(int i = 0; i <= gameMap.lines; i++) {
            printf("%s\n", gameMap.matrix[i]);
        }
        char direction;
        scanf(" %c", &direction);
        move(direction);
    
    } while (!endOfGame());
    

   
}

void move(char direction) {
    int x;
    int y;

    for (int i = 0; i <= gameMap.lines; i++) {
        for (int j = 0; j <= gameMap.columns; j++) {
            if (gameMap.matrix[i][j] == '@') {
                x = i;
                y = j;
            }
        }        
    }

    switch(direction) {
        case 'a':
            gameMap.matrix[x][y-1] = '@';
            break;
        case 'w':
            gameMap.matrix[x-1][y] = '@';
            break;
        case 's':
            gameMap.matrix[x+1][y] = '@';
            break;
        case 'd':
            gameMap.matrix[x][y+1] = '@';
            break;
    }

    gameMap.matrix[x][y] = '.';
}

void allocateMemory() {
    int memoryToAllocForLines = sizeof(int*) * gameMap.lines;
    int memoryToAllocForColumns = sizeof(int) * gameMap.columns;

    gameMap.matrix = malloc(memoryToAllocForLines);

    for(int i = 0; i <= gameMap.lines; i ++) {
        gameMap.matrix[i] = malloc(memoryToAllocForColumns);
    }
}

int endOfGame() {
    return 0;
}

void readFileForGameMap(FILE* file) {    

    for(int i = 0; i <= gameMap.lines; i++) {
        fscanf(file, "%s", gameMap.matrix[i]);
    }   

    fclose(file);   
}

int countLines(FILE* fp) { 
  int ch=0;
  int lines=0; 

  lines++;
  while ((ch = fgetc(fp)) != EOF) {
      if (ch == '\n') {
        lines++;
      }
    }
  
  rewind(fp);
  return lines;
}

int countColumns(FILE* file, int numberOfLines) {

    char line[1024]; // Assuming maximum line length is 1024 characters
    int num_columns = 0;

    if (fgets(line, numberOfLines, file) != NULL) {
        // Count columns in the first line
        char *token = strtok(line, "-"); // Assuming columns are separated by space or tab
        while (token != NULL) {
            num_columns++;
            token = strtok(NULL, "-");
        }
    } else {       
        return -1; // Empty file
    }

    return num_columns;
}

