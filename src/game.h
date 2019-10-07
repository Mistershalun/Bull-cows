#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

char word[4];
char pl[4];

void set() {
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

bool check() {
  int i, j;
  for (i = 0; i < 4; i++)
    if (pl[i] > 9) return 0;

  for (i = 0; i < 4; i++)
    for (j = i + 1; j < 4; j++)
      if (pl[i] == pl[j]) return 0;
  return 1;
}

void BullCow() {
  int b = 0, c = 0;
  int i, j;
  for (i = 0; i < 4; i++)
    if (word[i] == pl[i]) b++;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if (word[i] == pl[j] && i != j) c++;
  printf("Bulls - %d\nCows-%d \n\n", b, c);
}

void input(int att) {
  printf("Guess the number!\nAttempt %d\nInput number - ", att);
  scanf("%4s", pl);
  int i;
  for (i = 0; i < 4; i++) pl[i] = pl[i] - 48;
  if (check()) {
    BullCow();
  } else
    printf("\nInvalid input!\n");
}

bool res() {
  int i;
  for (i = 0; i < 4; i++)
    if (word[i] != pl[i]) return 0;
  return 1;
}

void game(int att) {
  input(att);
  if (!res())
    game(att + 1);
  else {
    printf("You win!!!");
    scanf("%d");
  }
}

