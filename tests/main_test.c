#define CTEST_MAIN
#include <stdlib.h>
#include <stdio.h>
#include <ctest.h>
#include <time.h>
#include "funks.h"
#define SPACE ' '

CTEST(proverka_test, data1)
{
    char matrix[3][3] = {
    { 'X', SPACE, SPACE },
    { 'O', 'X', SPACE },
    { 'O', SPACE, 'X' }
    };
    int result = proverka(matrix);
    int expect = 'X';
    ASSERT_EQUAL(expect, result);
}

CTEST(proverka_test, data2)
{
    char matrix[3][3] = {
    { 'X', SPACE, SPACE },
    { 'O', 'O', 'O' },
    { SPACE, SPACE, 'X' }
    };
    int result = proverka(matrix);
    int expect = 'O';
    ASSERT_EQUAL(expect, result);
}

CTEST(proverka_test, noone_win_data)
{
    char matrix[3][3] = {
    { 'X', SPACE, SPACE },
    { 'O', SPACE, 'O' },
    { SPACE, SPACE, 'X' }
    };
    int result = proverka(matrix);
    int expect = SPACE;
    ASSERT_EQUAL(expect, result);
}

CTEST(get_player_move, ok)
{
    char matrix[3][3] = {
    { SPACE, SPACE, SPACE },
    { 'O', SPACE, 'O' },
    { SPACE, SPACE, 'X' }
    };
    int result = get_player_move('X', matrix, 1, 1);
    int expect = 0;
    ASSERT_EQUAL(expect, result);
}

CTEST(get_player_move, not_ok)
{
    char matrix[3][3] = {
    { 'X', SPACE, SPACE },
    { 'O', SPACE, 'O' },
    { SPACE, SPACE, 'X' }
    };
    int result = get_player_move('X', matrix, 3, 3);
    int expect = 1;
    ASSERT_EQUAL(expect, result);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
