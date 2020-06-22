#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

char*
stringToTokenize()
{
  int cap = 100; //total char allowed in a string
  char* string = (char*)malloc(cap);
  printf(">"); //symbol to signal to start writing
  fgets(string,cap,stdin); //user input
  return string;
}

int
space_char(char c)
{
  if(c==' '|| c=='\t'&& c!='\0')//return true if space or tabed and not the EOL(end of line)
    return 1;
  return 0;
}

int
non_space_char(char c)
{
  if(c==' '|| c=='\t' || c=='\0')//returns true if not space, tab or EOL
    return 0;
  return 1;
}

char
word_start(char *str)
{
  while(space_char(*str)==1)//while space char
    {
      str++;//increment through pointer
    }
  return *str; //return beggining of word
}

char
*word_terminator(char *str)
{
  while(non_space_char(*str)==1)
    {
      str++;
    }
  return str;
}

int
count_words(char *str)
{
  int counter =0;
  while(*str!='\0')//stops when EOL is reached
    {
      *str = word_start(str);//points to the address at the start of the word
      if(non_space_char(*str)==1)//if non_spac char
	{
	  str=word_terminator(str);//looks for the end of the word
	  counter++;//counts word
	}
    }
  return counter;
}

