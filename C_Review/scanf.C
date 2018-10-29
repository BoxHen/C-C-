#include <stdio.h> //refer to 1.

int main(){
  int number;
  printf("enter number: ");
  scanf("%d", &number);
  printf("the number is %d ",number);
  return 0;
}
/*
Notes:
1."#" pound sign was used A pound sign or a hash is a direction instruction or
  directive # was probably chosen arbitrarily as an otherwise unused character in
  C syntax.
  include is used to include a file (called as header file)which has function
  parameters of functions that you will be needing frequently in main .

  What is stdio.h? The prototype for standard input output functions like to scan or
  to print are saved in the stdio.h body so that we can directly use it without
  defining the prototype.

  You must be wondering if its only the prototype where is the function body of
  the functions .It is defined in the C library and is mostly in machine language
  for performance reason and is linked to the program during runtime.

  Also , there are two ways to include a header file :
    a.WITH ANGULAR BRACKETS - #include<stdio.h> -This is used when we want to check
    the default folder (generally the bin/include folder) for the .h file.
    b.If you have created a separate .h file and which is in the same folder ,as the
    source code , then you can use #include”headername.h” .It forces the compiler to
    first search in the same folder and then into the default folder .
*/
