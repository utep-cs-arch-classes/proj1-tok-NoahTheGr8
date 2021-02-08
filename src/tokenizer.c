#include <stdio.h>

//symbolic constant
#define MAX 20

void main(){

  /*
    First milestone - create a simple UI that takes in user input and shoots out 
    user input in same order
  */

  char input[MAX];
  printf("* GREETINGS USER *\n");
  printf("> ");
  scanf("%s",input);
  printf("%s\n", input);
}
