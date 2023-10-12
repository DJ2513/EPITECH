#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

// grid: lqnelooelbtelqte
int main(int argc, char *argv[]) {
    bool running = true;
    bool inputWord = false;
    bool inputGrid = false;
    size_t gridSize = 17;
    size_t wordSize =20;
    char gridChain[gridSize];
    char word[wordSize];
    char wordTemp[wordSize];

    for(int i=1; i< argc; i++){
        if(argv[i][0] == '-'){
            switch (argv[i][1]) {
                case 'g':
                    strncpy(gridChain, argv[i+1], gridSize);
                    inputGrid = true;
                    continue;
                case 'w':
                    strncpy(word, argv[i+1],wordSize);
                    inputWord = true;
                    continue;
                case 's':
                    gridSize = atoi(argv[i+1]);
                    continue;
                default:
                    if(argv[i][1] == '\0'){
                        continue;
                    }

            }
        }
    }
    while (running) {
        if(!inputWord ) {
            printf("+++++++++++\n");
            for (int i = 0; i < 4; i++) {
                printf("|");
                for (int j = 0; j < 4; j++) {
                    printf(" %c ", gridChain[i * 4 + j]);
                }
                printf("|\n");
            }
            printf("+++++++++++\n");
            scanf("%s", word);
        }

        int cont = 0;
        // We get the word or letters from the grid
        for (int i = 0; i < gridSize; i++) {
            if (word[cont] != '\0') {
                if(gridChain[i] == word[cont]) {
                    wordTemp[cont] = gridChain[i];
                    cont++;
                }
            }
            else {
                wordTemp[cont] = '\0';
                break;
            }
        }
        // We compare the result found on the grid with the actual word
        cont =0;
        int value = strcmp(word, wordTemp);
        if(value == 0){
            printf("+++++++++++\n");
            for (int i = 0; i < 4; i++) {
                printf("|");
                for (int j = 0; j < 4; j++) {
                    if(gridChain[i*4+j] == '\0'){
                        printf("   ");
                    }else {
                        if (gridChain[i * 4 + j] == word[cont]) {
                            printf(" %c ", gridChain[i * 4 + j] - 32);
                            cont++;
                        } else {
                            printf(" %c ", gridChain[i * 4 + j]);
                        }
                    }
                }
                printf("|\n");
            }
            printf("+++++++++++\n");
            running = false;
        }
        else{
            printf("The word '%s' is not in the grid\n", word);
            *word = '\0';
        }
    }
    return 0;
}
