#include <stdio.h>

int main(int argc, char* argv[]){

  printf("The number of arguments is/are: %d\n", argc);

  for(int i = 0; i<argc; i++){
    printf("argument number %d is: %s", argc+1, argv[i]);
  }
  return 0;

}
