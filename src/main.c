#include "tokenizer.c"

void
main()
{
  char* tokenize=stringToTokenize();
  printf("Tokenize: %s",tokenize);
  int countWords = count_words(tokenize);
  printf("Number of words:  %d\n",countWords);
}
