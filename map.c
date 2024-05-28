#include <stdio.h>
#include <stdlib.h>
#include "map.h"


void allocateMemory(MAP* map) {
    int memoryToAllocForLines = sizeof(int*) * map->lines;
    int memoryToAllocForColumns = sizeof(int) * map->columns;

    map->matrix = malloc(memoryToAllocForLines);

    for(int i = 0; i <= map->lines; i ++) {
        map->matrix[i] = malloc(memoryToAllocForColumns);
    }
}

void move(MAP* map, POSITION* position, char direction) {

    char validLetters[4] = {'w', 'a', 's', 'd'};

    if (!isValueInArray(direction, validLetters, 4)) return;

    int nextX = position->x;
    int nextY = position->y;

    switch(direction) {
        case 'a':
            nextY--;
            break;
        case 'w':
            nextX--;
            break;
        case 's':
            nextX++;
            break;
        case 'd':
            nextY++;
            break;
    }

    if(!isDirectionValid(map, nextX, nextY)) return;

    moveInMap(map, position, nextX, nextY);
}

void moveInMap(MAP *map, POSITION *position, int nextX, int nextY)
{
    map->matrix[position->x][position->y] = '.';
    map->matrix[nextX][nextY] = '@';

    position->x = nextX;
    position->y = nextY;
}

int isDirectionValid(MAP* map, int x, int y) {
  if (x >= map->lines || y >= map->columns || map->matrix[x][y] != '.') {
    return 0;
  }   

  return 1;
}

void find(MAP* map, POSITION* position, char character) {
    for (int i = 0; i <= map->lines; i++) {
        for (int j = 0; j <= map->columns; j++) {
            if (map->matrix[i][j] == character) {
                position->x = i;
                position->y = j;
                break;
            }
        }        
    }
}

int isValueInArray(char c, char validLetters[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (validLetters[i] == c) {
            return 1;
        }
    }
    return 0;
}