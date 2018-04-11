#include <stdio.h>

int main()
{
  int i, j, k, length;
  char str[101]; // this will declare a string with a length o up to 100 characters

  // 101 since null character takes up last characters
  printf("Please enter a string: ");
  gets(str); // store entered string
  printf("String is: %s", str);
  length = strlen(str);
  printf("\n length is: %d \n", length);

  for(i=(length-1); i>=0; i--) // print in reverse order
    printf("%c", str[i]); // Note: use %c and not %s since we are printing back characters

  printf("\n");
  printf("The odd-numbered elements of the array: ");
  for(j=1; j<length; j+=2) // odd print out
  {
    printf("%c", str[j]);
  }

  printf("\n");
  printf("The even-numbered elements of the array: ");
  for(k=0; k<length; k+=2) // even print out
  {
    printf("%c", str[k]);
  }

  return(0);
}
