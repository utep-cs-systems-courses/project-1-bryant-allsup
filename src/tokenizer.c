#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

int
space_char(char c)
{
  if(c==' '|| c=='\t')//return true if space or tabed and not the EOL(end of line)
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
*word_start(char *str)
{
  while(space_char(*str))//while space char
    {
      str++;//increment through pointer
    }
  return str; //return starting char
}

char
*word_terminator(char *str)
{
  while(non_space_char(*str))//goes until it finds a space
    {
      str++;
    }
  return str;
}

int
count_words(char *str)
{
  int counter =0;
  
  while(*str)//stops when EOL is reached
    {
      str=word_start(str);//points to the address at the start of the word
      str=word_terminator(str);//looks for the end of the word
      counter++;//counts number of words
    }
  return counter;
}

char
*copy_str(char *inStr,short len)//whatever is given has a copy created at a new address
{
  char *copy =(char*)malloc((len+1)*sizeof(char*));
  int c=0;
  for(;c<len;c++)
    {
      copy[c] = inStr[c];//copy
    }
  copy[c]='\0';//end of string
  return copy;
}
/*copy str is used so you have a copy of the orginal string
and have a tokenized version of the string as well
 */

char
**tokenize(char* str)
{
  char **tokenized = (char**)malloc((count_words(str)+1)*sizeof(char**));
  char *begin , *end;
  short length = 0;
  begin=word_start(str);//find first non_space char
  int read;
  for(read =0; read<count_words(str);read++)
    {
      end    = word_terminator(begin);//find end of first word
      length = end-begin;
      tokenized[read]=copy_str(begin,length);
      begin  = word_start(end);//find beginning of next word
    }
  tokenized[++read]="\0";//marks EOL
  return tokenized; 
}

void
print_tokens(char **tokens)
{
  
  for(int t = 0; tokens[t]!="\0";t++)
    {
      printf("Print tokens: %s \n",tokens[t]);
    }
}

void
free_tokens(char **tokens)
{
  int t=0;
  while(tokens[t])
    {
      free(tokens[t]);
      t++;
    }
  free(tokens);
}
