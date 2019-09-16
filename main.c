#include<stdio.h>
#include<stdlib.h>
#include <time.h>

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
void input()
{
 for( int i = 0; i < 4; i++)
 printf("%d",word[i]);	
}
bool checkN()
{
 	for( int i = 0; i < 4; i++)
 	if(pl[i]>9) return 0;

 	for( int i = 0; i < 4; i++)
   for( int j = i + 1; j < 4; j++)
   if( pl[i] == pl[j] ) return 0; 
   return 1;
}

int main()
{
	set();
input();
 
  	
	
}
