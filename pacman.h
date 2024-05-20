void readFileForGameMap();
void allocateMemory();
int endOfGame();
void move(char direction);

struct map {
    char** matrix;
    int lines;
    int columns;
};

typedef struct map MAP;