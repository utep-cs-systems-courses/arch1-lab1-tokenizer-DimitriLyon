#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c) {
  return (c == ' ' || c == '\t') && (c != '\0');
}

int non_space_char(char c) {
  return (c != ' ' && c != '\t') && (c != '\0');
}

char *word_start(char *str) {
  char *start_ptr;
  start_ptr = str;
  while(space_char(*start_ptr)) {
    start_ptr++;
  }
  if(*start_ptr == '\0') {
    start_ptr = NULL;
  }
  return start_ptr;
}

char *word_terminator(char *word) {
  char *end_ptr;
  end_ptr = word;
  while(non_space_char(*end_ptr)){
    end_ptr++;
  }
  if(*end_ptr == '\0') {
    end_ptr = NULL;
  }
  return end_ptr;
}

int count_words(char *str) {
  char *iter;
  iter = str;
  int wd_ct = 0;
  while(iter != NULL) {
    iter = word_start(iter);
    if (iter == NULL) {
      return wd_ct;
    }
    wd_ct++;
    iter = word_terminator(iter);
  }
  return wd_ct;
}

char *copy_str(char *inStr, short len) {
  //This loop will lower len if it is greater than the number
  //of characters in inStr.
  for(short i = 0; i < len; i++) {
    if(inStr[i] == 0) {
      len = i;
    }
  }
  char *copy = (char *)calloc(len + 1, sizeof(char));
  for(short i = 0; i < len; i++) {
    copy[i] = inStr[i];
  }
  return copy;
}
