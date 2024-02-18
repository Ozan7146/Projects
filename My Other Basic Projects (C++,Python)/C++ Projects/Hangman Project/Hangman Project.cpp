// Hangman Project

#include<iostream>
#include<string.h>
#include<string>
#include<cstdlib>

using namespace std;

char guessed_letter[10];
char list[10];
int j=0,o=0;
char is_equal(char w[],char p,int* c,int k) // void tipi de olabilir buranonýn tek önemi list[l] = p; bu kýsým 
{
	string a ;
	a=p;
	guessed_letter[k] = p;	
	for(int i=0;i<strlen(w);i++)
	{
		if(w[i] == p) 
		{
			*c = i;
			list[j] = p; // liste sadece kullanýcýnýn doðru olarak bildiði deðerleri(harfleri) tutuyor		
			j++;
			return p;
		}	
	}	
	
}

string random_choice() // sýkýntý var !!!!!!!!!!!!!!!!!!
{
	string word_list[] = {"exciting","exclusive","exotic","expensive","exuberant","exultant","fabulous","faded","faint","fair","faithful","fallacious","false","familiar","famous","fanatical","fancy","fantastic","far"};

	char random[20];
	
	int random1;
	random1 = rand() % 19 + 1;
	while(random1 <19 && 1 < random1)
	{
	   	
			return word_list[random1];
										
	}
	
	//random = random1;
	return random;
	
}

int main()
{
	char guess_out[10],dash[10];
	char word[10];
	string last_word;
	char func_return;
	int lives, flag;
	char player_guess;
	string g;
	char x[10];
	int t=0;
	cout << "Enter the word: ";
	cin >> word;
	cout << "-------------------------------------" << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << "***********************************" << endl;
	
	//random kýsmýnda sýkýntý var!!!!!!!!!!!!!!!!
	//g = random_choice();
	
	//word[10] = g;
	//strcpy(word, g.c_str()); 
	//cout << word <<endl;
	//word = g;
	lives = strlen(word)  ;
	
	for(int k=0;k<strlen(word);k++)
	{
		x[k]='_';
		cout << '_';
	} 
	
	cout << endl;
	
	while(lives > 0 && strlen(word) > 0)
	{
		
		//for(int i=0;i<lives;i++) //for dash
		//{
			cout << "Enter the letter: ";
			cin >> player_guess;
			
			func_return = is_equal(word,player_guess, &flag,o);
			o++;
			
			cout << "You have guessed this letters:" ;
			for(int i=0;i<o;i++)
			{
				cout << guessed_letter[i] << " ";
			}
			cout << endl;
			lives--;
			
			
		
				 
			for(int r=0;r<strlen(list);r++)				
			{
				
				t=0;
				for(int k=0;k<strlen(word);k++)
				{
					if(list[r] == word[k])
					{
						//cout << list[r];
						x[t]=list[r];
						t++;
						
					}
					else                                        //if(strlen(x) <= strlen(word))
						{
							//cout << "_";
							if(x[t] =='_')
							{
							x[t]='_';
							t++;
							}
							else
								t++;
						}
				
				}
			
		}
			
			
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
			string b;
			for(int i=0;i<strlen(word);i++)
			{
				cout << x[i];
			}
			
			cout << endl;
			
			b=x;
			
			if(b==word)
			{
				cout << "You Won!";
				break;
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
				
	}
	

	return 0;
}
