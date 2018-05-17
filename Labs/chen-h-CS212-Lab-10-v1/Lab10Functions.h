#ifndef Lab10Functions_H
#define Lab10Functions_H
#include <stdio.h>
/*------------------------------------------------Prototypes------------------------------------------------*/
int isOperand(char ch);
int isOperator(char ch);
int precedence(char ch);
void infixToPostfix();
void evalPostFix();

#endif
