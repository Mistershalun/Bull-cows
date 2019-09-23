#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>
char word[4];
char pl[4];

void set()
{
	bool c = 1;
 while( c )
 {
 	srand(time(NULL));
 for( int i = 0; i < 4; i++)
  word[i] = rand()%10;
  c = 0;
  for( int i = 0; i < 4; i++)
   for( int j = i + 1; j < 4; j++)
   if( word[i] == word[j] ) c = 1; }
}

bool check()
{
 	for( int i = 0; i < 4; i++)
 	if(pl[i]>9) return 0;

 	for( int i = 0; i < 4; i++)
   for( int j = i + 1; j < 4; j++)
   if( pl[i] == pl[j] ) return 0; 
   return 1;
}

void BullCow()
{
int b=0, c=0;
for( int i = 0; i < 4 ; i++)
if(word[i] == pl[i])b++;

  for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (word[i] == pl[j] && i != j)
                c++;
printf("Bulls - %d\nCows-%d \n\n",b,c);
}

void input(int att)
{

printf("Guess the number!\nAttempt %d\nInput number - ",att);	
scanf("%4s", pl);

for( int i = 0; i < 4; i++)
pl[i] = pl[i] - 48;
if( check() ) { BullCow();}
else printf("\nInvalid input!\n"); 

}

bool res()
{
 for( int i = 0; i < 4; i++)
 if( word[i] != pl[i])	return 0;
 return 1;
}

void game( int att )
{
 	input(att);
 	if(!res())
 	game(att+1);
 	else {printf("You win!!!"); 	
	scanf("%d");}
}

void menu()
{
		printf("1.Game\n2.Autors\n3.exit\n");
 	int c;
 	scanf("%d", &c);
 	if( c == 1 ) {system("cls");set();game(1);system("cls");}
 	if( c == 2 ) {system("cls");printf("Zaripov D.");scanf("%d");system("cls"); }
 	if( c == 3 ) {return;};
 	menu();
}

int main()
{
	menu();
}