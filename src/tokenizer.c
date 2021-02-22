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
  //var to store the whether c is nsc (a letter)
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
  printf("------------WORD START------------\n");
  //check if it doesnt contain any words
  printf("Pointer address> %p\n",&str);//prints *str address
  printf("Address that we are storing> %p\n",str);//prints contents in *str
  printf("First value of the address we are storing> %c\n",*str);//prints pointers stored address values
  printf("First values adress from address being stored from the word> %p\n", str);
  
  //iterate using the pointer to access next value
  for( ; *str != '\0'; str++){
    printf("-Current Address during iteration> %p\n",str);
    //pass each char to nsc()
    if( non_space_char(*str) == 1 ){
    	printf("FIRST CHAR ENCOUNTERED> %c\n", *str);
	return str;
    }
  }//for
  
  return '\0';

}//word start


/* Returns a pointer terminator to the first space character or string-terminator
   following str in a zero terminated string.
   str is assumed to be pointing to a non-space character*/
char *word_end(char *str){
  printf("------------WORD END------------\n");
  //check if it doesnt contain any words
  printf("Pointer address being passed> %p\n",&str);//prints *str address
  printf("Address that we are storing in pointer> %p\n",str);//prints contents in *str
  printf("First value of the address we are storing> %c\n",*str);//prints pointers stored first address values
  printf("First address being stored from the word> %p\n", str);
  
  //iterate using the pointer to access next value
  for( ; *str != '\0'; str++){
    printf("Current Address during iteration> %p\n",str);
    //pass each char to sc()
    if( space_char(*str) == 1 ){
    	printf("FIRST SPACE CHAR ENCOUNTERED> %c\n", *str);
	return str;
    }
  }//for
  
  return '\0';
}//word end

/* Counts the number of space seperated words in the string argument. 

I think of this function as a switch where 
everytime we see the start of a word, we lift the switch and when the word ends we drop the switch and increment the number of words we have

*/
int count_words(char *str){
  printf("------------COUNT WORDS------------\n");
  //Think of a switch we turn on/off = 1 word
  int words = 0;
  int swtch = 0;
  for( ; *str != '\0'; str++){
    if(non_space_char(*str)==1){
      swtch = 1;
    }
    if((swtch==1) && (space_char(*str)==1)){
      words++;
      swtch=0;
    }
  }//for
  //if there was a word we didnt finish considering because of '\0'
  if(swtch == 1){
    words++;
  }
  return words;
}
