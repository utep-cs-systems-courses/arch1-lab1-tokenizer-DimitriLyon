#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int word_len(char *word) {
  int len = 0;
  while(non_space_char(word[len])) {
    len++;
  }
  return len;
}

char **tokenize(char *str) {
  int num = count_words(str);
  if(num == 0) {
    return NULL;
  }
  char *word = str;
  char **tokens = calloc(num + 1, sizeof(char *));
  for(int i = 0; i < num; i ++) {
    word = word_start(word);
    tokens[i] = copy_str(word, word_len(word));
    //Advances word to the next word in str
    word = word_terminator(word);
  }
  return tokens;
}

void print_tokens(char **tokens) {
  char **iter = tokens;
  int num = 0;
  while(*iter != 0) {
    printf("%i: [%s]\n", num, *iter);
    num++;
    iter++;
  }
}

void free_tokens(char **tokens) {
  int i = 0;
  while(tokens[i] != 0) {
    free(tokens[i]);
    i++;
  }
  free(tokens[i]);
  free(tokens);
}
