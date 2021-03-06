#include "calc.h"
#define MAXOP 100

int main(void){
	int i, type, var;
	int last_type;
	double op2, v;
	char s[MAXOP];
	double variable[26];

	v = 0.0;
	var = 0;
	last_type = 'l';
	for(i = 0; i < 26; i++)
		variable[i] = 0.0;
	while((type = getop(s)) != EOF){
		switch (type){
			case NUMBER:
				push(atof(s));
				break;
            case NAME:
                mathfnc(s);
                break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '=':
				pop();
				if(var >= 'A' && var <= 'Z')
					variable[var - 'A'] = pop();
				else
					printf("error: no variable name\n");
				break;
			case '\n':
				if(last_type != 'l' && last_type != '='){
					v = pop();
					printf("result is %.8g\n", v);
					break;
				}
				else if(last_type == '='){
					printf("value had been assigned\n");
					break;
				}
			default:
				if(type >= 'A' && type <= 'Z')
					push(variable[type - 'A']);
				else if(type == 'v')
					push(v);
				else
					printf("error: unknown command %s\n", s);
		}
		var = type;
		last_type = type;
	}
	return 0;
}


void mathfnc(char s[]){
    double op2;
    if(strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if(strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if(strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if(strcmp(s, "pow") == 0){
        op2 = pop();
        push(pow(pop(), op2));
    }                                                                                                                 
    else
        printf("error: %s not supported\n", s);
}