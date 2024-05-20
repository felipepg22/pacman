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

void move(MAP* map, char direction) {
    int x;
    int y;

    for (int i = 0; i <= map->lines; i++) {
        for (int j = 0; j <= map->columns; j++) {
            if (map->matrix[i][j] == '@') {
                x = i;
                y = j;
            }
        }        
    }

    switch(direction) {
        case 'a':
            map->matrix[x][y-1] = '@';
            break;
        case 'w':
            map->matrix[x-1][y] = '@';
            break;
        case 's':
            map->matrix[x+1][y] = '@';
            break;
        case 'd':
            map->matrix[x][y+1] = '@';
            break;
    }

    map->matrix[x][y] = '.';
}