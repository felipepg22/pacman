#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'
#define USE_BOMB 'b'
#define HERO '@'
#define ENEMY 'E'
#define BOMB 'B'

void readFileForGameMap();
int endOfGame();
void enemies();
int chooseEnemyMovement(int originX, int originY, int* nextX, int*nextY);
