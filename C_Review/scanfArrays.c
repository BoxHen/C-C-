#include <stdio.h>

int main(){
  int arr[50], num, i;

  printf("enter how many numbers to enter\n");
  scanf("%d", &num);

  printf("enter %d numbers \n", num);
  for(i=0; i<num; i++){
    scanf("%d", &arr[i]);
  }

  printf("the array is: ");
  for(i = 0; i<num; i++){
    printf("%d", arr[i]);
  }
  return 0;
}
