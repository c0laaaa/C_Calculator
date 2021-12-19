#define NUMBER '0'
#define NAME 'n'

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
void mathfnc(char []);

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>