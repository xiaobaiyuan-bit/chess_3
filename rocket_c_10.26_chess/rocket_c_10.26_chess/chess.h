#ifndef __CHESS_H_
#define __CHESS_H_

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

#define ROWS 3
#define COLS 3

void show(char showboard[][COLS], int rows, int cols);
char play(char showboard[][COLS], int rows, int cols);
void game();




#endif //__CHESS_H_
