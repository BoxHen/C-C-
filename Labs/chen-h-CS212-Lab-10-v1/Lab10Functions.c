#include "Lab10Functions.h"
#include "math.h" // used for exponents

#include "queueFunctions.h"
#include "queueFunctions2.h"
#include "stackFunctions.h"
#include "stackFunctions2.h"

#include <stdlib.h>
char item, item1;
int isOperand(char ch){
    return (ch >= '0' && ch <= '9'); // function to check if the given int is operand
}

int isOperator(char ch){ // checks if it is a operator
  if(ch == '*'){return 2;} // used to check for "**"
  else if(ch == '*' || ch == '/' || ch == '+' || ch =='-'){return 1;}
	else{return 0;}
}

int precedence(char ch){
    switch (ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(){
    ResetQueue(0);
    PushStack('('); PushQueue(')');
    item = FrontQueue(); // read front of queue for 1st value

    while(item != '\0'){ // break if we reach '\0' which is end of queue
      if(item == '('){ PushStack(item);}

      else if( isOperand(item) ){ PushQueue2(item);}

      else if( item == ')'){ // output until '('
        int temp = PopStack();
        while(temp != '('){
          PushQueue2(temp);
          temp = PopStack();
        }
      }

      else if( isOperator(item) ){
        if(isOperator(item) == 2){ // check if *
          item = GetNextQueue(0);
          if(isOperator(item) == 2 ){ //Check if another *
             item = '^';
          }
          else item = GetNextQueue(1); // reverse, so we undo what we peeked
        }

        int temp1 = PopStack();
        while( isOperator(temp1) && (precedence(temp1) >= precedence(item)) ){
          PushQueue2(temp1);
          temp1 = PopStack();
        }
        PushStack(temp1); // add back what we popped since it did not satisfy conditions
        PushStack(item);
      }

      else{printf("\nINVALID EXPRESSION\n");}
      item = GetNextQueue(0); // goes towards rear to get next
    }// END while
}

void evalPostFix(){
  ResetQueue(0);
  item1 = FrontQueue2();
  printf("postfix is: ");
  while(item1 != '\0'){
    printf("%c ", item1 ); // Print the post fix
    if( isOperand(item1) ){ PushStack2((item1-'0')); } // cast to integers
    else{
      double temp1 = PopStack2(); double temp2 = PopStack2();
      switch(item1){
      		case '+': PushStack2(temp2 + temp1); break;
      		case '-': PushStack2(temp2 - temp1); break;
      		case '*': PushStack2(temp2 * temp1); break;
      		case '/': PushStack2(temp2 / temp1); break;
          case '^': PushStack2(pow(temp2, temp1)); break;
      }
        //case '**': PushStack2(pow(temp2, temp1)); break;
    }
    item1 = GetNextQueue2(0);
  }// end while
  printf("\nThe answer is: %f \n", PopStack2());
}
