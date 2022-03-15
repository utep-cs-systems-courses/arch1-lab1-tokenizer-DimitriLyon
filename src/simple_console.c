#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include "dimitri_lib.h"

int match_hstry_call(char *str) {
  if (*str != '!')
    return 0;
  str++;
  while(non_space_char(*str)) {
    if(*str < '0' || *str > '9') {
      return 0;
    }
    str++;
  }
  return 1;
}

/*Extracts the number from the str in the format !<number>
 */
int get_id(char *str) {
  int tally = 0;
  char *iter = str;
  //increment past the '!'
  iter++;
  //Multiply tally by 10
  //Get number - '0'
  //add it to tally.
  //increment iter
  while(non_space_char(*iter)) {
    tally *= 10;
    tally += (*iter) - '0';
    iter++;
  }
  return tally;
}

int main() {
  char *input = "";
  List *hstry = init_history();
  char **tokens;
  printf("Type a string when prompted with '>' to see it tokenized.\n");
  printf("Typed strings are automatically added to the history.\n");
  printf("Access history by typing \"!<number>\".  History is 0 indexed.\n");
  printf("Quit the program by typing \"quit\"\n");
  while(!string_equals(input, "quit")) {
    printf("History is:\n");
    print_history(hstry);
    printf("> ");
    input =  get_userinput();
    printf("\n");
    if(string_equals(input, "quit")) {
      printf("Quitting program\n");
      break;
    }
    if(match_hstry_call(input)) {
      int id = get_id(input);
      tokens = tokenize(get_history(hstry, id));
      free(input);
    } else {
      tokens = tokenize(input);
      add_history(hstry, input);
    }
    
    print_tokens(tokens);
    free_tokens(tokens);
    //Don't free index because the address is stored in the history list.
  }
  //Free History here.  My string method uses calloc, so it should be compatible.
  free_history(hstry);
  return 0;

}


