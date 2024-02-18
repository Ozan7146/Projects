// Hangman Project

#include<iostream>
#include<string.h>
#include<string>

using namespace std;

char guessed_letter[10];
char list[10];
int j=0,o=0;
char is_equal(char w[],char p,int* c,int l,int k)
{
	string a ;
	a=p;
	guessed_letter[k] = p;	
	for(int i=0;i<strlen(w);i++)
	{
		if(w[i] == p) 
		{
			*c = i;
			list[l] = p; // liste sadece kullanýcýnýn doðru olarak bildiði deðerleri(harfleri) tutuyor		
			
			return p;
		}	
	}	
	
}



int main()
{
	char guess_out[10],dash[10];
	char word[10];
	string last_word;
	char func_return;
	int lives, flag;
	char player_guess;
	
	char x[10];
	int t=0;
	cout << "Enter the word: ";
	cin >> word;
	
	lives = strlen(word) ;//- 2;
	
	for(int k=0;k<strlen(word);k++)
	{
		cout << '_';
	} 
	
	cout << endl;
	
	while(lives > 0 && strlen(word) > 0)
	{
		
		//for(int i=0;i<lives;i++) //for dash
		//{
			cout << "Enter the letter: ";
			cin >> player_guess;
			
			func_return = is_equal(word,player_guess, &flag,j,o) ;
			j++;
			o++;
			
			cout << "You have guessed this letters:" ;
			for(int i=0;i<o;i++)
			{
				cout << guessed_letter[i] << " ";
			}
			cout << endl;
			lives--;
			
			
		
				 
			for(int r=0;r<strlen(word);r++)				
			{
				
				
				for(int k=0;k<strlen(list);k++)
				{
					if(list[r] == word[k])
					{
						//cout << list[r];
						//if()
						x[t]=list[r];
						t++;
						
					}
					else if(strlen(x) <= strlen(word))
						{
							//cout << "_";
						//	if(x[t] =='_')
						//	{
							
							x[t]='_';
							t++;
						//	}
					
						}
				
				}
			
		}
			
			
				t=0;
				/*for(int k=0;k<strlen(word);k++)				
				{	
				
				
				//if(x[t] == '_') //alfabeden deðilse yani == '_'
				//{
					
					if(word[flag] == word[k])
					{	
						x[t]=func_return;
						cout << func_return;	 
					}
					
				//else
				//	{
				//	x[t]='_';
				//	cout << "_";
				//	}
				//}
				t++;
			}
			*/
			
			for(int i=0;i<strlen(word);i++)
			{
				cout << x[i];
				if(x==word)
				{
					cout << "You won!";
					break;
				}
			}
			cout << endl;	
			
			
			if(lives == 0)
			{
				cout << "You dont have any rights.You need guess the word:";
				cin >> last_word;
					if(last_word==word)
					{
						cout << "You won!" << endl; 
					}
			}
			
			
			
			
					
		//}
		
		
		
	}
	

	return 0;
}
