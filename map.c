#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "pacman.h"

int hasBomb = 0;
void allocateMemory(MAP* map) {
    int memoryToAllocForLines = sizeof(int*) * map->lines;
    int memoryToAllocForColumns = sizeof(int) * map->columns;

    map->matrix = malloc(memoryToAllocForLines);

    for(int i = 0; i <= map->lines; i ++) {
        map->matrix[i] = malloc(memoryToAllocForColumns);
    }
}

void explodeBomb(MAP* map, int x, int y, int quantity) {
    if (!hasBomb) {
        printf("You don't have a bomb!\n");   
        return;    
    }

    if (quantity == 0) {
        hasBomb = 0;
        return;
    }

    map->matrix[x][y+1] = EMPTY;

    explodeBomb(map, x, y+1, quantity-1);
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

    if(!isDirectionValid(map, nextX, nextY, HERO)) return;

    if (isCharacter(map, nextX, nextY, BOMB)) {
        hasBomb = 1;
    }

    moveInMap(map, position->x, position->y, nextX, nextY);
    position->x = nextX;
    position->y = nextY;
}

void moveInMap(MAP *map, int originX, int originY, int nextX, int nextY) {
    char character = map->matrix[originX][originY];
	map->matrix[nextX][nextY] = character;
	map->matrix[originX][originY] = EMPTY;
}

int isDirectionValid(MAP* map, int x, int y, char character) {
  return !isAWall(map, x, y)
         && !isInLimit(map, x, y)
         && !isCharacter(map, x, y, character);
  }

int isInLimit(MAP* map, int x, int y ) {
    return x >= map->lines || y >= map->columns;
}

int isAWall(MAP* map, int x, int y) {
    return map->matrix[x][y] == HORIZONTAL_WALL || map->matrix[x][y] == VERTICAL_WALL;
}

int isCharacter(MAP* map, int x, int y, int character) {
    return map->matrix[x][y] == character;
}

int find(MAP* map, POSITION* position, char character) {
    for (int i = 0; i <= map->lines; i++) {
        for (int j = 0; j <= map->columns; j++) {
            if (map->matrix[i][j] == character) {
                position->x = i;
                position->y = j;
                return 1;                
            }
        }        
    }

    return 0;
}

int isValueInArray(char c, char validLetters[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (validLetters[i] == c) {
            return 1;
        }
    }
    return 0;
}

void copyMap(MAP *origin, MAP *destination) {
    destination->columns = origin->columns;
    destination->lines = origin->lines;

    allocateMemory(destination);
    for (int i = 0; i < destination->lines; i++)
    {
        strcpy(destination->matrix[i], origin->matrix[i]);
    }
}

void freeMemory(MAP* map) {
	for(int i = 0; i < map->lines; i++) {
		free(map->matrix[i]);
	}

	free(map->matrix);
}