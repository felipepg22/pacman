#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'
#define HERO '@'
#define ENEMY 'E'

void readFileForGameMap();
int endOfGame();
void enemies();
int chooseEnemyMovement(int originX, int originY, int* nextX, int*nextY);
