#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "pacman.h"


void allocateMemory(MAP* map) {
    int memoryToAllocForLines = sizeof(int*) * map->lines;
    int memoryToAllocForColumns = sizeof(int) * map->columns;

    map->matrix = malloc(memoryToAllocForLines);

    for(int i = 0; i <= map->lines; i ++) {
        map->matrix[i] = malloc(memoryToAllocForColumns);
    }
}

void move(MAP* map, POSITION* position, char direction) {

    char validLetters[4] = {UP, DOWN, RIGHT, LEFT};

    if (!isValueInArray(direction, validLetters, 4)) return;

    int nextX = position->x;
    int nextY = position->y;

    switch(direction) {
        case LEFT:
            nextY--;
            break;
        case UP:
            nextX--;
            break;
        case DOWN:
            nextX++;
            break;
        case RIGHT:
            nextY++;
            break;
    }

    if(!isDirectionValid(map, nextX, nextY)) return;

    moveInMap(map, position, nextX, nextY);
}

void moveInMap(MAP *map, POSITION *position, int nextX, int nextY)
{
    map->matrix[position->x][position->y] = EMPTY;
    map->matrix[nextX][nextY] = HERO;

    position->x = nextX;
    position->y = nextY;
}

int isDirectionValid(MAP* map, int x, int y) {
  if (x >= map->lines || y >= map->columns || map->matrix[x][y] != EMPTY) {
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