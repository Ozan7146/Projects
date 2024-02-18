//Sudoku Projesi

#include<iostream>

using namespace std;

int main()
{
	char ch;
	int value,row,column;
	int Sudoku[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, // deðer yanlýþsa 0 olarak kalmalý
                      {0, 0, 0, 0, 0, 3, 0, 8, 5},
                      {0, 0, 1, 0, 2, 0, 0, 0, 0},
                      {0, 0, 0, 5, 0, 7, 0, 0, 0},
                      {0, 0, 4, 0, 0, 0, 1, 0, 0},
                      {0, 9, 0, 0, 0, 0, 0, 0, 0},
                      {5, 0, 0, 0, 0, 0, 0, 7, 3},
                      {0, 0, 2, 0, 1, 0, 0, 0, 0},
                      {0, 0, 0, 0, 4, 0, 0, 0, 9}}; 
	
	int Answers[9][9] = {{9, 8, 7, 6, 5, 4, 3, 2, 1}, 
                      {2, 4, 6, 1, 7, 3, 9, 8, 5},
                      {3, 5, 1, 9, 2, 8, 7, 4, 6},
                      {1, 2, 8, 5, 3, 7, 6, 9, 4},
                      {6, 3, 4, 8, 9, 2, 1, 5, 7},
                      {7, 9, 5, 4, 6, 1, 8, 3, 2},
                      {5, 1, 9, 2, 8, 6, 4, 7, 3},
                      {4, 7, 2, 3, 1, 9, 5, 6, 8},
                      {8, 6, 3, 7, 4, 5, 2, 1, 9}}; 
		
	while(1)
	{
		
		
		//	cout << "[" << j+1 << "]" ;
			
		//	cout << "[" << i+1 << "]" ;
		
		cout << "Sudoku [1] " << "[2] " << "[3] " << "[4] " << "[5] " << "[6] " << "[7] " << "[8] " << "[9]" << endl;
		cout << "__________________________________________" << endl << endl;
		for(int i=0;i<9;i++)
		{
			
			cout << "[" << i+1 << "]" << "  " ;
			cout << "|  "; 
			
			for(int j=0;j<9;j++)
			{
				
				cout << Sudoku[i][j];
				cout << "  ";
				if((j+1)%3 == 0)
				{
					cout << "|  "; 
				}
				
				
			}	
			
			
			cout << endl;
			if((i+1)%3 == 0 )
				{
					cout << "__________________________________________" << endl;
				}
			cout << endl;
		}
		
		
		
		cout << "Enter the row: " ;
		cin >> row;
		row -=1;
		cout << "Enter the column: " ;
		cin >> column;
		column -=1;
		
		cout << "Enter the number: " ;
		cin >> value;
		if(row <= 10 &&  0 <= row )
		{
			if(column <= 10 &&  0 <= column )
			{
				if(Answers[row][column] == value)
				{
					Sudoku[row][column] = value;
					cout << "Correct" << endl;
				}
				else
					cout << "It's not " << value << ".Try another number."<< endl;
			}	
			
			else
				cout << "Wrong column try again (1-9)" << endl;
		}
		
		else
			cout << "Wrong row try again (1-9)" << endl;
		
		cout << endl << endl;
		cout << "Sudoku [1] " << "[2] " << "[3] " << "[4] " << "[5] " << "[6] " << "[7] " << "[8] " << "[9]" << endl;
		cout << "__________________________________________" << endl << endl;
		for(int i=0;i<9;i++)
		{
			
			cout << "[" << i+1 << "]" << "  " ;
			cout << "|  "; 
			
			for(int j=0;j<9;j++)
			{
				
				cout << Sudoku[i][j];
				cout << "  ";
				if((j+1)%3 == 0)
				{
					cout << "|  "; 
				}
				
				
			}	
			
			
			cout << endl;
			if((i+1)%3 == 0 )
				{
					cout << "__________________________________________" << endl;
				}
			cout << endl;
		}
		
		cout << "Do you want to exit(e,n): ";
		cin >> ch; 
		cout << endl << endl;
		if(ch=='e')
			break;
	}		
			

	return 0;
}
