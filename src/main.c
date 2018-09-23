#include <stdio.h>
#include "funks.h"

#define SPACE ' '

int main()
{
    char a;
        printf("vyberite rezhim:\n");
        printf("  1 - igrok protiv kompyutera\n");
        printf("  2 - igrok protiv igroka\n");
        printf("  3 - computer protiv computer\n");
        printf("  0 - exit\n");
        scanf("%c", &a);
        switch (a) {
        case '1':playzer_vs_computer();break;
        case '2': playzer_vs_player();break;
        case '3':computer_vs_computer();break;
        case '0':return 0;
        default:printf("nevernoe znachenie");return 0;
        }
    return 1;
}
