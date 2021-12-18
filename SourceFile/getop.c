#include <ctype.h>
#include "calc.h"

int getop(char s[]){
    int c;
    int i;

    // 读取到第一个不是空白符号的字符然后截断
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    // 判断这个第一个不是空白符号的字符是否是数字字符或数字字符的一部分
    if(!isdigit(c) && c != '.' && c !='-')
        return c;
    i = 0;

    // 判断'-'号是否是程序的一部分
    if(!isdigit(s[++i] = c = getch()) && c != '.'){
        ungetch(c);
        return '-';
    }


    if(isdigit(c)){
        while(isdigit(s[++i] = c = getch()))
            ;
    }

    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;

    // 顶替了最后一个不是数字的字符
    s[i] = '\0';

    ungetch(c);

    return NUMBER;
}