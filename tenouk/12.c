#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUL '\0'
#define DEFAULT_BUFFER_SIZE 2
#define NUM_WORDS 15

void clear(void);
void enter(void);
void clearInputBuffer(void);
char getLetter(void);
int letterIsInWord(char*, char);
void empty(void);
void init(void);
void welcome(void);
void head(void);
void body(void);
void leftArm(void);
void rightArm(void);
void leftLeg(void);
void rightLeg(void);
void stick(void);
void rope(void);
void loser(void);
void winner(void);
int game(char*, int, int);

int main(void)
{
    srand(time(0));
    int upper = NUM_WORDS - 1;
    int lower = 0;
    int counter = 0;
    int wins = 0;
    int loses = 0;
    char words[NUM_WORDS][30] = {
        "OLLA", "CUCHARA", "COCINA", "RUBIK", "FAMILIA",
        "SILLA", "TELEVISOR", "IMPRESORA", "CASCO", "TELEFONO",
        "COBIJA", "ALMOHADA", "COLCHON", "PARLANTE", "CLOSET"
    };

    clear();
    welcome();
    enter();

    do {
        int position =(rand() % (upper - lower + 1)) + lower;
        char* word = words[position];
        int isWinner = game(word, wins, loses);

        clear();
        isWinner ? winner() : loser();
        sleep(2);

        if (isWinner) {
            for (int c = position; c < upper - 1; c++) {
                strcpy(words[c], words[c + 1]);
            }

            --upper;
            ++wins;
        } else {
            ++loses;
        }
    } while (upper > 0 && counter <= 100);

    return 0;
}

int game(char* word, int wins, int loses)
{
    int wordLength = strlen(word);
    char* wordShow = (char *) malloc(sizeof(char) * wordLength);
    char letter;
    int isWinner = 1;
    int lives = 8;
    int counter = 0;
    int wordFound = 0;

    for (int i = 0; i < wordLength; ++i) {
        wordShow[i] = '_';
    }

    do {
        clear();

        printf("Ganadas %d\t Perdidas %d\n", wins, loses);
        printf("*****************\n");

        switch (lives)
        {
            case 8:
                init();
                break;

            case 7:
                head();
                break;

            case 6:
                body();
                break;

            case 5:
                leftArm();
                break;

            case 4:
                rightArm();
                break;

            case 3:
                leftLeg();
                break;

            case 2:
                rightLeg();
                break;

            case 1:
                stick();
                break;

            case 0:
            default:
                rope();
                break;
        }

        printf("\n");
        for (int i = 0; i < wordLength; i++) {
            printf("%c", wordShow[i]);
        }
        printf("\n\n");

        printf("Ingresa una letra a ver como te va, recuerda: son %d letras\n", wordLength);
        printf("Probar suerte con: ");

        letter = getLetter();
        int letterExists = letterIsInWord(word, letter);

        if (letterExists == 1) {
            for (int i = 0; i < wordLength; i++) {
                if (word[i] == letter) {
                    wordShow[i] = word[i];
                    ++wordFound;
                }
            }
        } else {
            lives -= 1;
        }

        clearInputBuffer();

        if (lives == 0) {
            isWinner = 0;
        } else if (wordLength == wordFound) {
            counter = 100;
        }

        ++counter;

        // printf("lives %d --> counter %d --> wordLength %d --> wordFound %d\n", lives, counter, wordLength, wordFound);
        // enter();
    } while(lives >= 0 && counter <= 100);

    free(wordShow);

    clear();

    sleep(1);

    return isWinner;
}

void clear(void)
{
    printf("\e[1;1H\e[2J");
}

void enter(void)
{
    char enter[100];

    printf("Presiona <Enter> para continuar...");
    fgets(enter, 100, stdin);

    return;
}

void clearInputBuffer()
{
    char c = NUL;

    while ((c = getchar()) != '\n' && c != EOF) {
        // Do nothing until input buffer fully flushed.
    }
}

char getLetter()
{
    char* result = NULL;
    char* inputBuffer = malloc(sizeof(char) * DEFAULT_BUFFER_SIZE);
    memset(inputBuffer, NUL, DEFAULT_BUFFER_SIZE);

    while (result == NULL) {
        result = fgets(inputBuffer, DEFAULT_BUFFER_SIZE, stdin);

        if (inputBuffer[strlen(inputBuffer) - 1] == '\n') {
            clearInputBuffer();

            result = NULL;
        }
    }

    result = NULL;

    return toupper(inputBuffer[0]);
}

int letterIsInWord(char* word, char letter)
{
    int wordLength = sizeof(word) / sizeof(char);

    for (int i = 0; i < wordLength; ++i) {
        if (letter == word[i]) {
            return 1;
        }
    }

    return 0;
}

void welcome(void)
{
    printf("                 \n");
    printf("                 \n");
    printf("   BIENVENID@    \n");
    printf("                 \n");
    printf("  *************  \n");
    printf("      ESTE       \n");
    printf("       ES UN     \n");
    printf("      JUEGO      \n");
    printf("       CLÁSICO   \n");
    printf("  *************  \n");
    printf("                 \n");
    printf("                 \n");

    return;
}

void empty(void)
{
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");

    return;
}

void init(void)
{
    printf("                 \n");
    printf("   _             \n");
    printf("  |_|            \n");
    printf("  |_|            \n");
    printf("                 \n");
    printf("                 \n");
    printf("...A ver cuánto  \n");
    printf("                 \n");
    printf("    te duran las \n");
    printf("                 \n");
    printf("  ocho vidas...  \n");
    printf("                 \n");

    return;
}
void head(void)
{
    printf("                 \n");
    printf("   _             \n");
    printf("  | |            \n");
    printf("    |   ***      \n");
    printf("        * *      \n");
    printf("        ***      \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");

    return;
}

void body(void)
{
    printf("                 \n");
    printf("   _             \n");
    printf("  |_             \n");
    printf("  |_|   ***      \n");
    printf("        * *      \n");
    printf("        ***      \n");
    printf("         *       \n");
    printf("         *       \n");
    printf("         *       \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");

    return;
}

void leftArm(void)
{
    printf("                 \n");
    printf("   _             \n");
    printf("  |_             \n");
    printf("   _|   ***      \n");
    printf("        * *      \n");
    printf("        ***      \n");
    printf("         *       \n");
    printf("       * *       \n");
    printf("      *  *       \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");

    return;
}

void rightArm(void)
{
    printf("                 \n");
    printf("                 \n");
    printf("  |_|            \n");
    printf("    |   ***      \n");
    printf("        * *      \n");
    printf("        ***      \n");
    printf("         *       \n");
    printf("       * * *     \n");
    printf("      *  *  *    \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");

    return;
}

void leftLeg(void)
{
    printf("                 \n");
    printf("   _             \n");
    printf("   _|            \n");
    printf("   _|   ***      \n");
    printf("        * *      \n");
    printf("        ***      \n");
    printf("         *       \n");
    printf("       * * *     \n");
    printf("      *  *  *    \n");
    printf("        *        \n");
    printf("       *         \n");
    printf("      *          \n");

    return;
}

void rightLeg(void)
{
    printf("                 \n");
    printf("   _             \n");
    printf("   _|            \n");
    printf("  |_    ***      \n");
    printf("        * *      \n");
    printf("        ***      \n");
    printf("         *       \n");
    printf("       * * *     \n");
    printf("      *  *  *    \n");
    printf("        * *      \n");
    printf("       *   *     \n");
    printf("      *     *    \n");

    return;
}

void stick(void)
{
    printf("                 \n");
    printf("         ******* \n");
    printf("    |          * \n");
    printf("    |   ***    * \n");
    printf("        * *    * \n");
    printf("        ***    * \n");
    printf("         *     * \n");
    printf("       * * *   * \n");
    printf("      *  *  *  * \n");
    printf("        * *    * \n");
    printf("       *   *   * \n");
    printf("      *     *  * \n");

    return;
}

void rope(void)
{
    printf("                 \n");
    printf("   _     ******* \n");
    printf("  | |    *     * \n");
    printf("  |_|  ***     * \n");
    printf("        * *    * \n");
    printf("  Perdí! ***   * \n");
    printf("         *     * \n");
    printf("       * * *   * \n");
    printf("      *  *  *  * \n");
    printf("        * *    * \n");
    printf("       *   *   * \n");
    printf("      *     *  * \n");

    return;
}

void loser(void)
{
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf(" ¡PERDER ES      \n");
    printf("                 \n");
    printf("   GANAR         \n");
    printf("                 \n");
    printf("    UN POQUITO!  \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");

    return;
}

void winner(void)
{
    printf("                 \n");
    printf("                 \n");
    printf("                 \n");
    printf(" ¡FELICIDADES!   \n");
    printf("                 \n");
    printf("   SABIA QUE     \n");
    printf("    PODIAS       \n");
    printf("     GANAR       \n");
    printf("                 \n");
    printf("                 \n");
    printf("...(no es cierto)\n");
    printf("                 \n");

    return;
}

