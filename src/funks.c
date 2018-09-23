#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funks.h"
#define SPACE ' '

int get_cord(int f)
{
    int i;
    if (!f) {
    printf("pozhalujsta vvedite koordinaty vashego hoda.\n");
    printf("ryad? ");
    }
    else {
    printf("kolonna? ");
    }
    scanf("%d", &i);
    return i;
}

void disp_matrix(char matrix[3][3])
{
    int t;
    for (t = 0; t < 3; t++) {
    printf("%1c |%1c |%1c\n", matrix[t][0], matrix[t][1], matrix[t][2]);
    if(t!=2) printf("\n--------\n");
    }
    printf("\n");
}

char proverka(char matrix[3][3])
{
    int t;
    char* p;
    for (t = 0; t < 3; t++) //proverka strok
    {
    p = &matrix[t][0];
    if (*p == *(p + 1) && *(p + 1) == *(p + 2)) {
    return *p;
    }
    }
    for (t = 0; t < 3; t++) //proverka stolbcov
    {
    p = &matrix[0][t];
    if (*p == *(p + 3) && *(p + 3) == *(p + 6)) {
    return *p;
    }
    }
    /* proverka pobedy po diagonali */
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
    return matrix[0][0];
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
    return matrix[0][2];
    }
    return SPACE;
}

int get_player_move(char player, char matrix[3][3], int x, int y)
{
    x--;
    y--;
    if (x < 0 || y < 0 || x > 2 || y > 2 || matrix[x][y] != SPACE) {
    return 1;
    }
    else {
    matrix[x][y] = player;
    return 0;
    }
}

void get_computer_move(char matrix[3][3]) //hod kompytera
{
    int x, y;
    int t;
    char* p;
    p = (char*)matrix;
    printf("vvojy koordinati moego hoda.\n");
    //printf("ryad? ");
    x = 1 + rand() % 3;
    printf("%d", x);
    //printf("kolonna? ");
    y = 1 + rand() % 3;
    printf("%d", y);
    printf("\n");
    x--;
    y--;
    for (t = 0; *p != SPACE && t < 9; ++t)
    if (t == 9) {
    printf("nichya \n");
    exit(0);
    }
    if (x < 0 || y < 0 || x > 3 || y > 3 || matrix[x][y] != SPACE || matrix[x][y] == 'X') {
    printf("isvinite oshibsia.\n");
    get_computer_move(matrix);
    }
    else
    matrix[x][y] = 'O';
}

void get_computer_move2(char matrix[3][3]) //hod kompytera
{
    int x, y;
    int t;
    char* p;
    p = (char*)matrix;
    printf("vvojy koordinati moego hoda.\n");
    //printf("ryad? ");
    x = rand() % 3;
    printf("%d", x);
    //printf("kolonna? ");
    y = 1 + rand() % 3;
    printf("%d", y);
    printf("\n");
    for (t = 0; *p != SPACE && t < 9; ++t)
    if (t == 9) {
    printf("nichya \n");
    exit(0);
    }
    if (x < 0 || y < 0 || x > 3 || y > 3 || matrix[x][y] != SPACE || matrix[x][y] == 'X') {
    printf("isvinite oshibsia.\n");
    get_computer_move(matrix);
    }
    else
    matrix[x][y] = 'X';
}

void computer_vs_computer()
{
    char matrix[3][3] = {
    { SPACE, SPACE, SPACE },
    { SPACE, SPACE, SPACE },
    { SPACE, SPACE, SPACE }
    };
    char done;
    done = SPACE;
    do {
    disp_matrix(matrix); //vyvod igrovoj doski
    get_computer_move2(matrix); //hodit igrok
    done = proverka(matrix); //proverka na pobedu
    if (done != SPACE)
    break; //pobeditel
    disp_matrix(matrix); //vyvod igrovoj doski
    get_computer_move(matrix); //hodit kompyukter
    done = proverka(matrix); //proverka na pobedu
    } while (done == SPACE);
    disp_matrix(matrix); //otobrazhenie rezultiruyushchego polozheniya
    if (done == 'X')
    printf("\n pozdravlyayu ti pobedil!!!\n");
    else
    printf("\n ty proigral,no v sleduyushchiu raz tebe tochno povezyot :-)\n");
    //system("CLS");
    exit(0);
}

void playzer_vs_computer()
{
    char matrix[3][3] = {
    { SPACE, SPACE, SPACE },
    { SPACE, SPACE, SPACE },
    { SPACE, SPACE, SPACE }
    };
    char done;
    do {
    disp_matrix(matrix); //vyvod igrovoj doski
    int x, y, r;
    x = get_cord(0);
    y = get_cord(1);
    r = get_player_move('X', matrix, x, y); //hodit igrok
    if (r) {
    printf("nevernyj hod povtorite popytku.\n");
    r = get_player_move('X', matrix, x, y); //hodit igrok
    }
    done = proverka(matrix); //proverka na pobedu
    if (done != SPACE)
    break; //pobeditel
    disp_matrix(matrix); //vyvod igrovoj doski
    get_computer_move(matrix); //hodit kompyukter
    done = proverka(matrix); //proverka na pobedu
    } while (done == SPACE);
    disp_matrix(matrix); //otobrazhenie rezultiruyushchego polozheniya
    if (done == 'X')
    printf("\n pozdravlyayu ti pobedil!!!\n");
    else
    printf("\n ty proigral,no v sleduyushchiu raz tebe tochno povezyot :-)\n");
    //system("CLS");
    exit(0);
}

void playzer_vs_player()
{
    char matrix[3][3] = {
    { SPACE, SPACE, SPACE },
    { SPACE, SPACE, SPACE },
    { SPACE, SPACE, SPACE }
    };
    char done;
    done = SPACE;
    do {
    disp_matrix(matrix); //vivod igrovoj doski
    int x, y, r;
    x = get_cord(0);
    y = get_cord(1);
    r = get_player_move('X', matrix, x, y); //hodit igrok
    if (r) {
    printf("nevernyj hod povtorite popytku.\n");
    r = get_player_move('X', matrix, x, y); //hodit igrok
    }
    done = proverka(matrix); //proverka na pobedu
    if (done != SPACE)
    break; //pobeditel
    disp_matrix(matrix);
    x = get_cord(0);
    y = get_cord(1);
    r = get_player_move('O', matrix, x, y); //hodit igrok
    if (r) {
    printf("nevernyj hod povtorite popytku.\n");
    r = get_player_move('O', matrix, x, y); //hodit igrok
    }
    done = proverka(matrix); //proverka na pobedu
    } while (done == SPACE);
    disp_matrix(matrix); //otobrazhenie rezultiruyushchego polozheniya
    if (done == 'X')
    printf("\n pozdravlyayu pobedil pervyj igrok!!!\n");
    else
    printf("\n pozdravlyayu pobedil vtoroj igrok!!!\n");
    exit(0);
}
