#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "pacman.h"

char enemyDesign[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char wallDesign[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char heroDesign[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char bombDesign[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char emptyDesign[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void printMap(MAP* map) {
    for(int i = 0; i < map->lines; i++) {
        for(int partOfDesign = 0; partOfDesign < 4; partOfDesign++) {
            for(int j = 0; j < map->columns; j++) {
                switch(map->matrix[i][j]) {
                    case ENEMY:
                        printDesign(enemyDesign, partOfDesign);
                        break;
                    case HERO:
                        printDesign(heroDesign, partOfDesign);
                        break;
                    case BOMB:
                        printDesign(bombDesign, partOfDesign);
                        break;
                    case EMPTY:
                        printDesign(emptyDesign, partOfDesign);
                        break;
                    case HORIZONTAL_WALL:
                    case VERTICAL_WALL:
                        printDesign(wallDesign, partOfDesign);
                        break;
                }
            }        
            printf("\n");       
        }            
    }
}

void printDesign(char design[4][7], int partOfDesign) {
    printf("%s", design[partOfDesign]);
}
