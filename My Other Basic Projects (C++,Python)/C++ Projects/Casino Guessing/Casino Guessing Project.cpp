#include<iostream>
#include<cstdlib>

using namespace std;

int randRange(int M, int N)
{
     return M + rand() / ( RAND_MAX / ( N - M ) + 1 ); // first value is always 1??
}



int main()
{
	
	int number,total_money,bet_amount,guess_number,flag;
	char ch;
	total_money = 200;
	flag=0;
	
	while(1)
	{
		int j=0;
		cout << "Your total money: " << total_money << endl;
		
		/*while(1)
		{
			
			number = rand();
			if(number <= 15 && 0 <= number)
			{
				cout << number << endl;
				break;		
			}
		}
		*/
		
		number=randRange(1,15);
		//cout << number << endl;
		
		cout << "Enter the bet amount that you want to play: " << endl; 
		cin >> bet_amount;
		
		if(total_money >= bet_amount)
		{
			cout << "Guess the number between 1-15 (You have 3 right to find):" << endl;
			for(int i=0;i<3;i++)
			{
				
				j++;
				cin >> guess_number;
				if(number==guess_number)
				{
					cout << "YOU WON!" << endl;
					flag = 1;
					total_money+=bet_amount*10;
					break;
				}
				
				else if(number < guess_number)
				{
					cout << "Try lower number" << endl;
					cout << "Try again.You have " << 3-j << " chance." << endl;
				}
				
				else
				{
					cout << "Try higher number" << endl;
					cout << "Try again.You have " << 3-j << " chance." << endl;
				}
			
					
			}	
			
			if(flag==0)
			{
				cout << "You lost!" << endl;
				total_money-=bet_amount;
			}
		
		}
		
		cout << "Your total money is: " << total_money <<endl;
		
		if(total_money == 0 )
		{
			cout << "See You!!";
			break;
		}
		
		cout << "Do you want to play('y' for Yes , 'n' for No): " << endl;
		cin >> ch;	
		if(ch == 'n')
			break;
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
