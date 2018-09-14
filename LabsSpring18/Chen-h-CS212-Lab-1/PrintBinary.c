#include <stdio.h>

int main()
{
  int n, c, k;
 
  printf("Enter an integer in decimal number system from 0 to 32\n");
  scanf("%d", &n);
 
  printf("%d in binary is:\n", n);

  if (0<=n && n<=32)          // makes sure integer is from 0 to 32
  { 
  	for (c = 5; c >= 0; c--)  // c = 5 since 32 requires 6 bits from 0 to 5
  	{
    	k = n >> c;      // shifts in binary but still read as a int so we need the (k&1)
 
    	if (k & 1)	     // and by 1 so we will keep the one after the shift
      		printf("1"); // print starts at the left and continues printing to the right of it 
    	else		     // note: we do not start at a new line
      		printf("0");
    }
  }
  else
  { 
  	printf("ERROR: Please enter an integer from 0 to 32!");
	return -1;
  }
  printf("\n");
 
  return 0;
}
