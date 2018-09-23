#ifndef FUNKS_H
#define FUNKS_H

void disp_matrix(char matrix[3][3]);
char proverka(char matrix[3][3]);
int get_player_move(char player, char matrix[3][3], int x, int y);
void get_computer_move(char matrix[3][3]);
void get_computer_move2(char matrix[3][3]);
void playzer_vs_computer();
void playzer_vs_player();
void computer_vs_computer();

#endif	
