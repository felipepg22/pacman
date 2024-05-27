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

    map->matrix[position->x][position->y] = '.';

    switch(direction) {
        case 'a':
            map->matrix[position->x][position->y-1] = '@';
            position->y--;
            break;
        case 'w':
            map->matrix[position->x-1][position->y] = '@';
            position->x--;
            break;
        case 's':
            map->matrix[position->x+1][position->y] = '@';
            position->x++;
            break;
        case 'd':
            map->matrix[position->x][position->y+1] = '@';
            position->y++;
            break;
    }

    
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