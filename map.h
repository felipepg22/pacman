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
void move(MAP* map, POSITION* position, char direction);
void find(MAP* map, POSITION* position, char character);
int isValueInArray(char c, char validLetters[], int arraySize);