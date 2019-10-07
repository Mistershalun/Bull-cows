#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

char word[4];
char player_word[4];

void set_word() {
  bool c = 1;
  int i, j;
  while (c) {
    srand(time(NULL));
    for (i = 0; i < 4; i++) word[i] = rand() % 10;
    c = 0;
    for (i = 0; i < 4; i++)
      for (j = i + 1; j < 4; j++)
        if (word[i] == word[j]) c = 1;
  }
}

bool input_check() {
  int i, j;
  for (i = 0; i < 4; i++)
    if (player_word[i] > 9) return 0;

  for (i = 0; i < 4; i++)
    for (j = i + 1; j < 4; j++)
      if (player_word[i] == player_word[j]) return 0;
  return 1;
}

void count_bullscows() {
  int b = 0, c = 0;
  int i, j;
  for (i = 0; i < 4; i++)
    if (word[i] == player_word[i]) b++;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if (word[i] == player_word[j] && i != j) c++;
  printf("Bulls - %d\nCows-%d \n\n", b, c);
}

void input(int att) {
  printf("Guess the number!\nAttempt %d\nInput number - ", att);
  scanf("%4s", player_word);
  int i;
  for (i = 0; i < 4; i++) player_word[i] = player_word[i] - 48;
  if (input_check()) {
    count_bullscows();
  } else
    printf("\nInvalid input!\n");
}

bool check_end() {
  int i;
  for (i = 0; i < 4; i++)
    if (word[i] != player_word[i]) return 0;
  return 1;
}

void game(int att) {
  input(att);
  if (!check_end())
    game(att + 1);
  else {
    printf("You win!!!");
    scanf("%d");
  }
}

