#include "calc.h"
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

// 如果缓冲区中有字符，优先输出缓冲区中的字符
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// 如果缓冲区满了就报错，没满就回收丢失的字符
void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}