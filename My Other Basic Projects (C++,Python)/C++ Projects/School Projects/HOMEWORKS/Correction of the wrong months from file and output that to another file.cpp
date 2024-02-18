#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

class Date
{
	public:
		
		int day;
		string month;
		int year;
		
	
		Date(int d,string m,int y)
		{
			day = d;
			month = m;
			year = y;
			
		}

};


class Player
{
	private:
		
		string first;
		string last;
		Date birthdate;
	
	public:	
		
		Player(string f,string l,int d,string m,int y) : birthdate(d,m,y) //sending d,m,y values to Date class for initializton
		{
			first = f;
			last = l;
		}
		
		void setMonth(string a) //for correcting the wrong value and chaning with the true month name
		{
			birthdate.month = a;
		}
		
		void printInfo(ostream &fout) //for printing the output file
		{
			fout << first << " " << last << " " << getDay() << " " << birthdate.month << " " << getYear() << endl;
		}
	
		int getDay()
		{
			return birthdate.day;
		}
		
		int getYear()
		{
			return birthdate.year;
		}

};


int main()
{
	
	string name,surname,month;
	int date,year;
	
	
	ifstream fin("input.txt"); //file opening,for reading 
	ofstream fout("output.txt"); //we opened the file for writing
	
	while(!fin.eof()) // keep going until the end of the file 
	{
		fin >> name >> surname >> date >> month >> year;	//getting the values string by string 
	
		try //for correction the wrong months
		{
			if(month.substr(0,3) == "Jan")		
			{
				string a = "January"; 
				throw a;
			}
			
			else if(month.substr(0,3) == "Feb")		
			{
				string a ="February";
				throw a;
			}
			
			else if(month.substr(0,3) == "Mar")		
			{
				string a ="March";
				throw a;
			}
			
			else if(month.substr(0,3) == "Apr")		
			{
				string a = "April";
				throw a;
			}
	
			else if(month.substr(0,3) == "May")		
			{
				string a ="May";
				throw a;
			}
			
			else if(month.substr(0,3) == "Jun")		
			{
				string a = "June";
				throw a;
			}
			
			else if(month.substr(0,3) == "Jul")		
			{
				string a ="July";
				throw a;
			}
			
			else if(month.substr(0,3) == "Aug")		
			{
				string a ="August";
				throw a;
			}
			
			else if(month.substr(0,3) == "Sep")		
			{
				string a ="September";
				throw a;
			}
	
			else if(month.substr(0,3) == "Oct")		
			{
				string a ="October";
				throw a;
			}
			
			else if(month.substr(0,3) == "Nov")		
			{
				string a ="November";
				throw a;
			}
			
			else if(month.substr(0,3) == "Dec")		
			{
				string a = "December";
				throw a;
			}
			
			
			
		} //end of try
		
		catch(string x)
		{
			Player p(name,surname,date,month,year);
			
			
			
			if(x != month)
			{
				p.setMonth(x);
				cout << "Incorrectly inputted month:" << month << " is corrected to " << x << endl;
			}
			
			p.printInfo(fout);
		} //end of catch
		
		
		
	}	//end of while
	
	fin.close();    //closing file
	fout.close();	//closing file
	return 0;
}
