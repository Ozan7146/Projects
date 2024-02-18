// Sudoku

#include<iostream>
using namespace std;




bool check_row(int x,int y,int num,int arr[9][9])
{
	int flag = 0;
	int flag1 = 0;
	for(;y<9;y++)
	{
		if(num != arr[x][y])
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	
	for(;0<y;y--)
	{
		if(num != arr[x][y])
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	
	if(flag == 1 && flag1 == 1)
	{
		return true;	
	}
	else
		return false;
}

////////////////

bool check_column(int x,int y,int num,int arr[9][9])
{
	
	int flag = 0;
	int flag1 = 0;
	for(;x<9;x++)
	{
		if(num != arr[x][y])
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	
	for(;0<x;x--)
	{
		if(num != arr[x][y])
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	
	if(flag == 1 && flag1 == 1)
	{
		return true;	
	}
	else
		return false;
}
	
///////////////////	
	
	
bool is_empty(int x,int y,int arr[9][9])
{
	for(int i = 1;i<10;i++)
	{
		if(arr[x][y] == i)
		{
			return false;
		}
		
		else
			return true;
	}
}

/////////////////////

bool three_to_three_square(int x, int y,int num,int arr[9][9])
{
	// 1.dokuzluk kareler
	if(x < 3 && -1 < x && y < 3 && -1 < y)
	{
		int flag = 0;
		for(int i=0;i<3;i++)
		{
			for(int k=0;k<3;k++)
			{
				if(arr[i][k] == num)
				{
					flag = 0;
				} 
				
			}
		
		}
		
		if(flag == 0)
		{
			return false;
		}
		else
			return true;
	}
	
	
	else if(x < 3 && -1 < x && y < 6 && 2 < y)
	{
		
			int flag = 0;
			for(int i=0;i<3;i++)
			{
				for(int k=3;k<6;k++)
				{
					if(arr[i][k] == num)
					{
						flag = 0;
					} 
					
				}
			
			}
			
			if(flag == 0)
			{
				return false;
			}
			else
				return true;
	}
	
	
	else if(x < 3 && -1 < x && y < 9 && 5 < y)
	{
		
				int flag = 0;
				for(int i=0;i<3;i++)
				{
					for(int k=6;k<9;k++)
					{
						if(arr[i][k] == num)
						{
							flag = 0;
						} 
						
					}
				
				}
				
				if(flag == 0)
				{
					return false;
				}
				else
					return true;
				
			}
	
	
	// 2.dokuzluk kareler
	else if(x < 6 && 2 < x && y < 3 && -1 < y)
	{
		
		int flag = 0;
		for(int i=3;i<6;i++)
		{
			for(int k=0;k<3;k++)
			{
				if(arr[i][k] == num)
				{
					flag = 0;
				} 
				
			}
		
		}
		
		if(flag == 0)
		{
			return false;
		}
		else
			return true;
	}
	
	else if(x < 6 && 2 < x && y < 6 && 2 < y)
	{
		
		int flag = 0;
		for(int i=3;i<6;i++)
		{
			for(int k=3;k<6;k++)
			{
				if(arr[i][k] == num)
				{
					flag = 0;
				} 
				
			}
		
		}
		
		if(flag == 0)
		{
			return false;
		}
		else
			return true;
	}
	
	else if(x < 6 && 2 < x && y < 9 && 5 < y)
	{
		
		int flag = 0;
		for(int i=3;i<6;i++)
		{
			for(int k=6;k<9;k++)
			{
				if(arr[i][k] == num)
				{
					flag = 0;
				} 
				
			}
		
		}
		
		if(flag == 0)
		{
			return false;
		}
		else
			return true;
	}
	
	//3.dokuzluk kareler
	else if(x < 9 && 5 < x && y < 3 && -1 < y)
	{
	
		int flag = 0;
		for(int i=6;i<9;i++)
		{
			for(int k=0;k<3;k++)
			{
				if(arr[i][k] == num)
				{
					flag = 0;
				} 
				
			}
		
		}
		
		if(flag == 0)
		{
			return false;
		}
		else
			return true;
	}
	
	else if(x < 9 && 5 < x && y < 6 && 2 < y)
	{
		
		int flag = 0;
		for(int i=6;i<9;i++)
		{
			for(int k=3;k<6;k++)
			{
				if(arr[i][k] == num)
				{
					flag = 0;
				} 
				
			}
		
		}
		
		if(flag == 0)
		{
			return false;
		}
		else
			return true;
	}
	
	else if(x < 9 && 5 < x && y < 9 && 5 < y)
	{
		
		int flag = 0;
		for(int i=6;i<9;i++)
		{
			for(int k=6;k<9;k++)
			{
				if(arr[i][k] == num)
				{
					flag = 0;
				} 
				
			}
		
		}
		
		if(flag == 0)
		{
			return false;
		}
		else
			return true;
	}
	
	
	
	
}
 ///////////////



int main()
{
	// kullanýcýdan aldýðýn sütun ve satýrý 1 eksilterek gönder yukardaki fonksiyonlarda asýl indeksi kullanarak yapýyorsun.
	int sudoku[9][9];
	int number = 1;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout << "Enter the " << i+1 << ".row and " << j+1 << ".column: ";
			cin >> sudoku[i][j];
		}
	}
	
	
	for(int a=0;a<9;a++)
	{
		number = 1;
		for(int b=0;b<9;b++)
		{
			if(check_row(a,b,number,sudoku) == true && check_column(a,b,number,sudoku) == true && is_empty(a,b,sudoku) == true && three_to_three_square(a,b,number,sudoku) == true)
 			{
 				sudoku[a][b] = number;
				number++;
			//	b=0;
				//sudoku[a][b] = sudoku[a][0];
				
			}
			if(number > 9 )
				break;
			
		}
		

	}
	
	for(int i=0;i<9;i++)
	{
		for(int k=0;k<9;k++)
		{
			cout << sudoku[i][k] << "   ";
		}
		cout << endl;
	}
	
	
	
	
	
	return 0;
}
