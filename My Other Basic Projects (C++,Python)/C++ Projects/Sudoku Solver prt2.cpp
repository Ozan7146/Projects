
#include<iostream>
using namespace std;
int sudoku[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 0, 0, 0, 0, 3, 0, 8, 5},
                      {0, 0, 1, 0, 2, 0, 0, 0, 0},
                      {0, 0, 0, 5, 0, 7, 0, 0, 0},
                      {0, 0, 4, 0, 0, 0, 1, 0, 0},
                      {0, 9, 0, 0, 0, 0, 0, 0, 0},
                      {5, 0, 0, 0, 0, 0, 0, 7, 3},
                      {0, 0, 2, 0, 1, 0, 0, 0, 0},
                      {0, 0, 0, 0, 4, 0, 0, 0, 9}}; 

bool check_row(int num,int place[9][9],int a)
{
	int flag = 0;
	for(int j=0;j<9;j++)
	{
		if(place[a][j] != num)
		{
			flag = 1;
		}  
		else
		{
			flag = 0;
			break;
		}
	
	}
	
	if(flag==0)
		return false;
	else
		return true;
}


bool check_column(int num,int place[9][9],int b)
{
	int flag1 = 0;
	for(int i=0;i<9;i++)
	{
		if(place[i][b] != num)
		{
			flag1 = 1;
		}
		else
		{
			flag1 = 0;
			break;
			
		}
		
	}
	
	if(flag1==0)
		return false;
	else
		return true;
}


bool is_empty(int place[9][9],int a,int b)
{
	if(place[a][b] == 0 )
		return true;
	else
		return false;
}



bool th2th(int num,int arr[9][9],int x,int y)
{
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


bool is_done(int a,int arr[9][9])
{
	int flag2 = 0;
	for(int j=0;j<9;j++)
	{
		if(arr[a][j] ==0 )
			{
			flag2 = 0;
			break;
			}
		else 
			flag2 = 1;
	}
	
	if(flag2==0)
	{
		return false;
	}
	else
		return true;
}


int main()
{
	
	
	
	
	int number=1;
	

	
	
	for(int row=0;row<9;)
	{
		for(int column=0;column<9;column++)
		{
			if(check_column(number,sudoku,row) == true && check_row(number,sudoku,column) == true && is_empty(sudoku,row,column) == true &&th2th(number,sudoku,row,column) == true)
			{
				sudoku[row][column] = number;	
			}
		}
		if(is_done(row,sudoku) == true)
		{
			row++;
			number=0;
		}
		number++;
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