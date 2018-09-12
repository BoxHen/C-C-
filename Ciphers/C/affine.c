#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
  //affine cipher : (ax + b) mod26
  int shift = 0, mult = 1, ch, letter; // take in ch as an int so we can do operations on it
  if(argc>1) shift = atoi(argv[1]); // we put shift first since if we dont want to use affine then we can just do a shift
  if(argc>2) mult = atoi(argv[2]); // if both parameters are entered then it will be an affine cipher

  while( (ch=getchar())!= EOF ){
    if( isalpha(ch) ){
      letter = ch & 0x1f; // converts alphabets to 1 - 26 with a at 1z
      letter = ((mult*letter)+shift)%26;
      if(letter==0) letter=26; // done so we dont get zero after we mod26(same as z or 26th alphabet)
      ch = (ch&0xe0)+letter; // based off ascii table. This is for lower case so we need the alpha to start at 0x60 so first three bits of 11100000 stay
      // change to 0xc0 for upper case. starts ar 0x40 instead of 0x60
    }
    putchar(ch);
  }
  return 0;
}
