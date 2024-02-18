//Login Register system

#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
using namespace std;

int main()
{
	int x,flag=0;
	string temp,temp1;
	string username,password;
	string a,b;
	
	
	while(1){
	try
	{
	cout << "1: Register" << endl << "2: Login" << endl << "Your choice:";
	cin >> x;
	if(x != 1 && x!=2)
		{
		throw 404;
		}
		
	} 
	
	catch(int d)
	{
		if(d==404)
		break;
	}
	switch(x)
	{
		case 1:
		
		{
			cout << "Select a username: " ;
			cin >> username;
			//cout << endl;
			
			cout << "Select a password: " ;
			cin >> password;
			//cin.getline(password,20);
			
			ofstream fout(username.c_str());
			fout << username << "\n" << password;
			cout << endl;
			fout.close();
		}
			break;
		
		case 2:
		{
						
			cout << "Enter username:";
			//cin.getline(temp,20); 
			cin >> temp;
			//cout << endl;
			cout << "Enter password:";
			cin >> temp1;
			//cin.getline(temp1,20);
			
			ifstream fin(temp.c_str());	
			
			if(!fin)
			{
				cout << "Wrong username" << endl;
				flag=1;
				break;
			}
			
			
			while(!fin.eof())
			{
				fin >> a >> b;
			}
			
			if(a == temp)
			{
			
				if(b == temp1)
				{
					cout << "Successfully logged in!" ;
					flag =1;
				}		
				
				else
				cout << "wrong password" << endl;
				flag=1;
			}
			
			
		fin.close();	
		}
		break;
		
		default:
		/*	{
			cout << "Enter correct number 1 or 2";
			}*/
			break;
	}
	
	if(flag==1)
	break;
	
/*	char a;
	cout << "Do you want to continue:";
	cin >> a;
	if(a=='n')
	break;*/
	}

	return 0;
}
