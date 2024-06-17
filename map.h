#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'

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
int find(MAP *map, POSITION *position, char character);
int isValueInArray(char c, char validLetters[], int arraySize);
int isDirectionValid(MAP *map, int x, int y, char character);
int isInLimit(MAP* map, int x, int y );
int isAWall(MAP* map, int x, int y);
int isCharacter(MAP* map, int x, int y, int character);
void copyMap(MAP *source, MAP *destination);
void freeMemory(MAP* map); 
int countLines(FILE* fp);
int countColumns(FILE* file, int numberOfLines);
void explodeBomb(MAP* map, POSITION* position);
void explodeBombInDirections(MAP* map, int x, int y, int sumX, int sumY, int quantity);