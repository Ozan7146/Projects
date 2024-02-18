#include <iostream>

using namespace std;


class DigitalBookArchive{
	
	private:
		string name;								
		string type;
		int digitalBookCount=20;
		
	public:
		
		DigitalBookArchive(string x)				//Overloading part a
		{
			name=x;	
		}
				
		
		DigitalBookArchive(string x,string y)	//Overloading part b
		{
			cout<<"Enter the name of Digital Book Archive"<<endl;
			cin>>x;
			cout<<"Enter the type of the digital book: "<<endl;
			cin>>y;	
			
			name=x;
			type=y;
			cout<<"Digital Book Archive name set to "<<name<<endl;  //We can change "name" part with getName() function it will show us the same value of name(or x)
			cout<<"Digital Book Type is: "<<type<<endl;
			
		}
		
		
	
		void print();			//We must define the funcitons here because we write the functions outside of our class
		string getName();
		void addBook();
		void readBook();
		 
};


void DigitalBookArchive::addBook()
{
	digitalBookCount=digitalBookCount+1;
	cout<<"A new digital book is added."<<endl;
}


void DigitalBookArchive::readBook()
{
	digitalBookCount=digitalBookCount-1;
	 cout<<"You've read a digital book"<<endl;
}

string DigitalBookArchive::getName()	
{
	return name;
}

void DigitalBookArchive::print()
{
cout<<"The number of remaining digital book is "<<digitalBookCount<<endl;	
}




int main() {
	
	char val;	
	string x,y;
	
    DigitalBookArchive B1(x);		//Overloading parts
	DigitalBookArchive B2(x,y);
	
	
	do{
	cout<<"Do you want to add or read a digital book (a/r),or enter (C) for exit the system: "<<endl;
	cin>>val;
	
	if(val=='a')
	{
	 B2.addBook(); 
	}
	else if(val=='r')
	{
	 B2.readBook();
	}
	
	else if(val=='c' || val=='C')	//if we enter 'c' or 'C' it will break the loop while 
	{
	break;
	}
	
	}while(1);
	
	B2.print();		//For the remainig book count
	
	return 0;
}
