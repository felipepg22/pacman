struct map {
    char** matrix;
    int lines;
    int columns;
};

typedef struct map MAP;


void allocateMemory(MAP* map);
void move(MAP* map, char direction);