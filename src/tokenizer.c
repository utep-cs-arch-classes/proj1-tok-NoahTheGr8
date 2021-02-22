#include <stdio.h>
#include "tokenizer.h"

#define LIMIT 100

/* Return true (non-zero) if c is a whitespace characer
   (' ', '\t', or '\n').
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  
  int validity;
  if(c==' ' || c == '\t' || c== '\n'){
    validity = 1;
  } else{
    validity = 0;
  }
  return validity; 
}

/* Return true (non-zero) if c is a non-whitespace
   character (not space, tab, or newline).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c) {
  
  int validity;
  if(c == ' ' || c == '\t' || c == '\n'){
    validity = 0;
  } else{
    validity = 1;
  }
  return validity;
}

/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str.  Return a zero pointer if
   str does not contain any words.
   str is assumed to be pointing to a space character */
// pointer to first nonspace char in first word s
char *word_start(char *str){

  //check if it doesnt contain any words
  printf("Pointer address> %p\n",&str);//prints *str address
  printf("Address that we are storing> %p\n",str);//prints contents in *str
  printf("Value of the address we are storing> %c\n",*str);//prints pointers stored address values
  printf("First Adress being stored from the word> %p\n", str);
  
  //iterate using the pointer to access next value
  for( ; *str != '\0'; str++){
    printf("Current Address during iteration> %p\n",str);
    //pass each char to nsc()
    if( non_space_char(*str) == 1 ){
    	printf("FIRST CHAR ENCOUNTERED> %c\n", *str);
	return str;
    }
  }//for
  
  return '\0';

}
/* Returns a pointer terminator to the first space character or string-terminator
   following str in a zero terminated string.
   str is assumed to be pointing to a non-space character*/
char *word_end(char *str){


  return 0;
}

/* Counts the number of space seperated words in the string argument. */
int count_words(char *str){return 0;}
