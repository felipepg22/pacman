#define EMPTY '.'

struct map {
    char** matrix;
    int lines;
    int columns;
};

struct position {
    int x;
    int y;
};

typedef struct map MAP;
typedef struct position POSITION;

void allocateMemory(MAP* map);
void move(MAP *map, POSITION *position, char direction);
void moveInMap(MAP *map, int originX, int originY, int nextX, int nextY);
void find(MAP *map, POSITION *position, char character);
int isValueInArray(char c, char validLetters[], int arraySize);
int isDirectionValid(MAP *map, int x, int y);
void copyMap(MAP *source, MAP *destination);
void freeMemory(MAP* map); 