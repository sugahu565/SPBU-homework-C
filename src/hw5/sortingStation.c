#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define isOperator(c) (c == '+' || c == '-' || c == '*' || c == '/')
#define isNumber(c) ('0' <= c && c <= '9')

int opPriority(char c) {
  if (c == '(')
    return -1;
  if (c == '*' || c == '/')
    return 1;
  return 0;
}

int tokenToNum(char c) {
  switch (c) {
  case '+':
    return 0;
  case '-':
    return 1;
  case '*':
    return 2;
  case '/':
    return 3;
  case '(':
    return 4;
  case ')':
    return 5;
  default:
    return -1;
  }
}

char numToToken(int num) { return "+-*/("[num]; }

int read(char **input) {
  int maxLen = 32, len = 0;
  *input = malloc(maxLen * sizeof(char));

  if (*input == NULL)
    return -1;

  char curr = getchar();

  while (curr != '\n') {
    if (len >= maxLen) {
      maxLen *= 2;
      char *temp = realloc(*input, maxLen * sizeof(char));

      if (temp == NULL) {
        free(*input);
        return -1;
      } else
        *input = temp;
    }
    (*input)[len++] = curr;
    curr = getchar();
  }
  return len;
}

void sortingStat(stack s, char *input, int len) {
  for (int i = 0; i < len; ++i) {
    char curr = input[i];

    if (curr == ' ')
      continue;

    if (isNumber(curr))
      printf("%c ", curr);
    else if (isOperator(curr)) {
      while (s.len > 0 && opPriority(curr) <= opPriority(numToToken(get(&s))))
        printf("%c ", numToToken(pop(&s)));
      push(&s, tokenToNum(curr));
    } else if (curr == '(')
      push(&s, tokenToNum(curr));
    else if (curr == ')') {
      while (numToToken(get(&s)) != '(')
        printf("%c ", numToToken(pop(&s)));
      pop(&s);
    }
  }
  while (s.len > 0)
    printf("%c ", numToToken(pop(&s)));
}

int main() {
  stack s;
  init(&s);

  char *input;
  int lenght = read(&input);
  if (input == NULL)
    return -1;

  sortingStat(s, input, lenght);

  destroy(&s);
  free(input);
  return 0;
}