int main(int argc, char *argv[]){
  int letter, ch, key_length, key_pos = 0,
  key_length = strlen(argv[1]);

  while( (ch=getchar())!=EOF ){
    if( isalpha(ch) ){
      letter = ch & 0x1f; // gets the alpha into form 1 - 26
      keyletter =  argv[1][key_pos & 0x1f];

      letter = (letter + keyletter)%26;
      if(letter = 0) letter = 26;
      ch = (ch & 0xe0) + letter;

      key_pos = (++key_pos) % key_length;
    }
    putchar(ch);
  }
  return 0;
}
