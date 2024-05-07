#include <stdio.h>
#include <stdlib.h>

int main() {
    char gameMap[5][11];

    FILE* file = fopen("mapa.txt", "r");

    if (file == 0) {
        printf("Failed to read file for gameMap");
        exit(1);
    }

    for(int i = 0; i <= 5; i++) {
        fscanf(file, "%s", gameMap[i]);
    }

    fclose(file);

    for(int i = 0; i <= 5; i++) {
        printf("%s\n", gameMap[i]);
    }
}

