#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pacman.h"
#include "file-helper.h"
#include "map.h"

MAP gameMap;

int main() {   

    FILE* file = fopen("mapa.txt", "r");

    if (file == 0) {
        printf("Failed to read file for gameMap");
        exit(1);
    }    

    gameMap.lines = countLines(file);    
    gameMap.columns = 10;   
    
    allocateMemory(&gameMap);
    readFileForGameMap(file);   
    do
    {           

        for(int i = 0; i <= gameMap.lines; i++) {
            printf("%s\n", gameMap.matrix[i]);
        }
        
        char direction;
        scanf(" %c", &direction);
        move(&gameMap, direction);
    
    } while (!endOfGame());
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

