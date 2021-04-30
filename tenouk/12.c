#include <stdio.h>
// toupper function
#include <ctype.h>
// malloc function
#include <stdlib.h>
// strcpy function
#include <string.h>
// srand, rand function
#include <time.h>
#define NUL '\0'
#define DEFAULT_BUFFER_SIZE 2
#define DEFAULT_WORD_SIZE 50

void clear(void);
void enter(void);
void draw(int);
void stats(int, int, int);
int getRamdonNumber(int, int);
char* getMaskWord(char*, int);
char* getUnmaskWord(char*, char*, int, char);
void clearInputBuffer(void);
void printWordHidden(char*, int);
char getLetter(void);
int letterIsInWord(char*, int, char);
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
void winner(char*);
int game(char*, int, int, int);

char* copyWords(char* source, int size)
{
    char* words[size];

    for (int i = 0; i < size; ++i) {
        words[i]  = source + (i * size);
    }

    return *words;
}

int main(void)
{
    int counter = 0;
    int rounds = 0;
    int wins = 0;
    int loses = 0;
    int upper = 0;
    int lower = 0;
    int isCustom = 0;
    char option;
    char* words = NULL;

    clear();
    stats(rounds, wins, loses);
    welcome();
    printf("Dígita el número de la opción: ");
    option = getLetter();

    switch (option)
    {
        case 49: // 1
            clear();
            printf("¿Con cuántas palabras quieren jugar? ");
            scanf("%d", &upper);

            isCustom = 1;
            char text[DEFAULT_WORD_SIZE] = {0};
            int textLength = 0;
            words = realloc(words, (sizeof(char) * DEFAULT_WORD_SIZE) * upper);

            if (!words) {
                printf("No se puede iniciar....");
                return 0;
            }

            printf("Al final de cada palabra presiona <Enter>.\n");
            printf("Solo se permiten palabras SIN espacios :(\n\n");

            for (int i = 0; i < upper; ++i) {
                printf("La palabra %d es: ", (i + 1));
                scanf("%s", text);
                textLength = strlen(text);

                for (int j = 0; j < textLength; ++j) {
                    text[j] = toupper(text[j]);
                }

                strcpy(words + (i * DEFAULT_WORD_SIZE), text);
                // printf("%s %d %s\n", text, textLength, words + (i * DEFAULT_WORD_SIZE));

                clearInputBuffer();
            }


//            for (int i = 0; i < upper; ++i) {
//                printf("Word before en %d es %s\n", i, words + (i * DEFAULT_WORD_SIZE));
//            }

            words = copyWords(words, DEFAULT_WORD_SIZE);

//            for (int i = 0; i < upper; ++i) {
//                printf("Word after en %d es %s\n", i, words + (i * DEFAULT_WORD_SIZE));
//            }

//            for (int i = 2; i < upper; ++i) {
//                printf("Word position en %d es %s\n", i, words + (i * DEFAULT_WORD_SIZE));
//                strcpy(words + (i * DEFAULT_WORD_SIZE), words + ((i + 1) * DEFAULT_WORD_SIZE));
//            }
//
            --upper;

//            for (int i = 0; i < upper; ++i) {
//                printf("Word after en %d es %s\n", i, words + (i * DEFAULT_WORD_SIZE));
//            }

            break;
        case 50: // 2
            // Animals
            upper = 49;
            char animals[][DEFAULT_WORD_SIZE] = {
                "ABEJA", "AGUILA", "ARMADILLO", "AVISPA", "BALLENA", "BISONTE", "BUFALO", "BURRO", "CABALLO", "CAMELLO",
                "CANARIO", "CANGREJO", "CANGURO", "CARACOL", "CEBRA", "CERDO", "CHIMPANCE", "CIERVO", "CISNE", "COCODRILO",
                "ELEFANTE", "ESCARABAJO", "ESCORPION", "FOCA", "GALLINA", "GALLO", "GATO", "GOLONDRINA", "HIPOPOTAMO", "HORMIGA",
                "JABALI", "JIRAFA", "LEON", "LORO", "MOSCA", "MOSQUITO", "OSO", "OVEJA", "PERDIZ", "PERRO",
                "PINGUINO", "POLLO", "SALTAMONTES", "SERPIENTE", "TIGRE", "TOPO", "TORO", "TORTUGA", "VACA", "ZORRO"
            };

            words = copyWords(animals, DEFAULT_WORD_SIZE);
            break;
        case 51: // 3
            // States
            upper = 31;
            char states[][DEFAULT_WORD_SIZE] = {
                "AMAZONAS", "ANTIOQUIA", "ARAUCA", "ATLANTICO", "BOGOTA", "BOLIVAR", "BOYACA", "CALDAS", "CAQUETA", "CASANARE",
                "CAUCA", "CESAR", "CHOCO", "CORDOBA", "CUNDINAMARCA", "GUAINIA", "GUAVIARE", "HUILA", "GUAJIRA", "MAGDALENA",
                "META", "NARINO", "NORTE", "PUTUMAYO", "QUINDIO", "RISARALDA", "SANTANDER", "SUCRE", "TOLIMA", "VALLE DEL CAUCA",
                "VAUPES", "VICHADA"
            };

            words = copyWords(states, DEFAULT_WORD_SIZE);
            break;
        case 48: // 0
            // Exit
        default:
            return 0;
            break;
    }

    ++rounds;

    do {
        // for (int i = 0; i < (upper); ++i) {
            // // printf("Word en %d es %s\n", i, words + (i * DEFAULT_WORD_SIZE));
        // // }

//         for (int i = 0; i <= upper; ++i) {
//             printf("%s\n", words + (i * sizeof(char) * DEFAULT_WORD_SIZE));
//         }

        int position = getRamdonNumber(upper, lower);
        char* word = words + (position * DEFAULT_WORD_SIZE);
        printf("%s - %d - %d - %d\n", word, upper, lower, position);
        int isWinner = game(word, rounds, wins, loses);

        clear();
        stats(rounds, wins, loses);
        isWinner ? winner(word) : loser();
        enter();

        if (isWinner) {
            for (int i = position; i < upper; ++i) {
                strcpy(words + (i * DEFAULT_WORD_SIZE), words + ((i + 1) * DEFAULT_WORD_SIZE));
                //if (isCustom == 1) {
                    // printf("%d %d %s --> %s\n",__LINE__, c ,words + (c * sizeof(char) * DEFAULT_BUFFER_SIZE), words + ((c + 1) * sizeof(char) * DEFAULT_BUFFER_SIZE));
                    // strcpy(words + (c * sizeof(char) * DEFAULT_BUFFER_SIZE), words + ((c + 1) * sizeof(char) * DEFAULT_BUFFER_SIZE));
                //} else {
                    //printf("%d %d %s --> %s\n",__LINE__, c, words + c, words + (c + 1));
                    //strcpy(words + c, words + (c + 1));
                //}
            }
            enter();

            --upper;
            ++wins;
        } else {
            ++loses;
        }

        ++rounds;
        ++counter;
    } while (upper >= 0 && counter <= 1000);

    free(words);

    return 0;
}

int game(char* word, int rounds, int wins, int loses)
{
    int wordLength = strlen(word);
    char* wordShow = malloc(sizeof(char) * wordLength);
    char letter;
    int isWinner = 1;
    int lives = 8;
    int counter = 0;
    int wordFound = 0;

    wordShow = getMaskWord(wordShow, wordLength);

    do {
        clear();

        stats(rounds, wins, loses);
        draw(lives);
        printWordHidden(wordShow, wordLength);

        printf("Ingresa una letra. Pista: son %d letras\n", wordLength);
        printf("Probar suerte con: ");

        letter = getLetter();
        int letterExists = letterIsInWord(word, wordLength, letter);

        if (letterExists > 0) {
            getUnmaskWord(wordShow, word, wordLength, letter);
            wordFound += letterExists;
        } else {
            lives -= 1;
        }

        if (lives == 0) {
            isWinner = 0;
        } else if (wordLength == wordFound) {
            counter = 100;
        }

        ++counter;

        printf("lives %d --> counter %d --> wordLength %d --> wordFound %d --> letter %c --> letterExists %d\n", lives, counter, wordLength, wordFound, letter, letterExists);
        //enter();
    } while(lives >= 0 && counter <= 100);

    free(wordShow);

    clear();

    return isWinner;
}

void stats(int rounds, int wins, int loses)
{
    printf("Rondas: %d\tGanadas: %d\tPerdidas: %d\n", rounds, wins, loses);
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    return;
}

int getRamdonNumber(int upper, int lower)
{
    srand(time(0));

    return (rand() % (upper - lower + 1)) + lower;
}

char* getMaskWord(char* wordShow, int wordLength)
{
    for (int i = 0; i < wordLength; ++i) {
        wordShow[i] = '_';
    }

    return wordShow;
}

char* getUnmaskWord(char* wordShow, char* word, int wordLength, char letter)
{
    for (int i = 0; i < wordLength; i++) {
        if (word[i] == letter) {
            wordShow[i] = word[i];
        }
    }

    return wordShow;
}


void printWordHidden(char* word, int wordLength)
{
    printf("\n");
    printf("     -->  ");

    for (int i = 0; i < wordLength; i++) {
        printf("%c", word[i]);
    }

    printf("\n\n");

    return;
}

void clear(void)
{
    printf("\e[1;1H\e[2J");
}

void draw(int lives)
{
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

    return;
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

    clearInputBuffer();

    return toupper(inputBuffer[0]);
}

int letterIsInWord(char* word, int wordLength, char letter)
{
    int wordFound = 0;

    for (int i = 0; i < wordLength; ++i) {
        if (letter == word[i]) {
            ++wordFound;
        }
    }

    return wordFound;
}

void welcome(void)
{
    printf(" ________________________________________________ \n");
    printf("|                                                |\n");
    printf("|     **                                         |\n");
    printf("|    *  * *  *                                   |\n");
    printf("|    **** *  * ****                              |\n");
    printf("|    *  * **** *  * ****                         |\n");
    printf("|    *  * *  * *  * *  * ****                    |\n");
    printf("|         *  * *  * **** *     **                |\n");
    printf("|              **** * *  *    *  * ***           |\n");
    printf("|                   *  * *    **** *  *  **      |\n");
    printf("|                        **** *  * *  * *  *     |\n");
    printf("|                             *  * *  * *  *     |\n");
    printf("|                                  ***  *  *     |\n");
    printf("|    1. Personalizado                    **      |\n");
    printf("|    2. Animales                                 |\n");
    printf("|    3. Departamentos                            |\n");
    printf("|    0. Salir                                    |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|________________________________________________|\n");

    return;
}

void empty(void)
{
    printf(" ________________________________________________ \n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|________________________________________________|\n");

    return;
}

void init(void)
{
    printf(" ________________________________________________ \n");
    printf("|       |                                        |\n");
    printf("|  **   |                                        |\n");
    printf("| *  *  | Tienes ocho oportunidades.             |\n");
    printf("|  **   | Salva al inocente usando tu sabiduria. |\n");
    printf("| *  *  |                                        |\n");
    printf("|  **   |    <El conocimiento es poder>          |\n");
    printf("|_VIDAS_|                    Sr Francis Bacon    |\n");
    printf("|          ***                    *****          |\n");
    printf("|     ****    ***           **** *     *         |\n");
    printf("|    *           *         *    *       ***      |\n");
    printf("|    **************       *            *   *     |\n");
    printf("|                        *******************     |\n");
    printf("|                                                |\n");
    printf("|       ¿Quién es el inocente?        ____       |\n");
    printf("|                                    |    |      |\n");
    printf("|         *                        __|    |      |\n");
    printf("|        /|\\                      |  |    |_     |\n");
    printf("|         |\\                      |  |    | |    |\n");
    printf("|________________________________________________|\n");

    return;
}
void head(void)
{
    printf(" ________________________________________________ \n");
    printf("|       |         **      *        *  *     *    |\n");
    printf("| ****  |        *         *        **       *   |\n");
    printf("|    *  |       *                   *         *  |\n");
    printf("|   *   |       *                             *  |\n");
    printf("|   *   |       *******************************  |\n");
    printf("|   *   |                                        |\n");
    printf("|_VIDAS_|                                        |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|________________________________________________|\n");

    return;
}

void body(void)
{
    printf(" ________________________________________________ \n");
    printf("|       |                                        |\n");
    printf("|  **   |                                        |\n");
    printf("| *     |                                        |\n");
    printf("| ****  |                                        |\n");
    printf("| *  *  |                                        |\n");
    printf("|  **   |                                        |\n");
    printf("|_VIDAS_|                                        |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|________________________________________________|\n");

    return;
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
    printf(" ________________________________________________ \n");
    printf("|       |                                        |\n");
    printf("| ****  |                                        |\n");
    printf("| *     |                                        |\n");
    printf("| ****  |                                        |\n");
    printf("|    *  |                                        |\n");
    printf("| ****  |                                        |\n");
    printf("|_VIDAS_|                                        |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|________________________________________________|\n");

    return;
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
    printf(" ________________________________________________ \n");
    printf("|       |                                        |\n");
    printf("| *  *  |                                        |\n");
    printf("| *  *  |                                        |\n");
    printf("| ****  |                                        |\n");
    printf("|    *  |                                        |\n");
    printf("|    *  |                                        |\n");
    printf("|_VIDAS_|                                        |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|________________________________________________|\n");

    return;
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
    printf(" ________________________________________________ \n");
    printf("|       |                                        |\n");
    printf("| ****  |                                        |\n");
    printf("|    *  |                                        |\n");
    printf("| ****  |                                        |\n");
    printf("|    *  |                                        |\n");
    printf("| ****  |                                        |\n");
    printf("|_VIDAS_|                                        |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|________________________________________________|\n");

    return;
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
    printf(" ________________________________________________ \n");
    printf("|       |                                        |\n");
    printf("| ****  |                                        |\n");
    printf("|    *  |                                        |\n");
    printf("| ****  |                                        |\n");
    printf("| *     |                                        |\n");
    printf("| ****  |                                        |\n");
    printf("|_VIDAS_|                                        |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|________________________________________________|\n");

    return;
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
    printf(" ________________________________________________ \n");
    printf("|       |                                        |\n");
    printf("|    *  |                                        |\n");
    printf("|  * *  |                                        |\n");
    printf("|    *  |                                        |\n");
    printf("|    *  |                                        |\n");
    printf("|    *  |                                        |\n");
    printf("|_VIDA__|                                        |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|________________________________________________|\n");

    return;
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
    printf(" ________________________________________________ \n");
    printf("|      |                                         |\n");
    printf("| **** |                                         |\n");
    printf("| *  * |                                         |\n");
    printf("| *  * |                                         |\n");
    printf("| *  * |                                         |\n");
    printf("| **** |                                         |\n");
    printf("|______|                                         |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|                                                |\n");
    printf("|________________________________________________|\n");

    return;
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

void winner(char* word)
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
    printf("-> %s\n", word);
    printf("                 \n");

    return;
}

