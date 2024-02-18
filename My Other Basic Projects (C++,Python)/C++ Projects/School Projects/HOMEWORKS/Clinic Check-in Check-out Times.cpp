#include<iostream>

using namespace std;

class Hours{
	
	public:
	
		int hour;
		int minutes;
		
		friend ostream& operator << (ostream& cout,Hours& hr1)
		{
			cout << hr1.hour << ":" << hr1.minutes;
			return cout;
		}
		friend istream& operator >> (istream& cin,Hours& hr1)
		{
			cin >> hr1.hour >> hr1.minutes ;
			return cin;
		}			
};

class Animals{
	
	protected:	
		
		string id;
		string animalName;
		string ownerName;
		string ownerSurname;
		

	public:	
		
		Hours totalHours;	
		int totalMins;
		
	public:	
		Animals(string id,string animalName,string ownerName,string ownerSurname) // string id1,string animalName1,string ownerName1,string ownerSurname1
			{
				//member initialization
				this->id = id;
				this->animalName = animalName;
				this->ownerName = ownerName;
				this->ownerSurname = ownerSurname;	
			}
		
		double calculateMinutes(Hours h_1,Hours h_2)
			{
			// h_1-> check in time h_2-> check out time
				if(h_1.hour <= h_2.hour && h_1.minutes <= h_2.minutes)
				{
					totalHours.hour = (h_2.hour-h_1.hour)*60  ;
					totalMins=totalHours.hour+h_2.minutes-h_1.minutes;
					return totalMins;
			
				}
			
				else if(h_1.hour < h_2.hour && h_1.minutes > h_2.minutes )
				{
					totalHours.minutes=h_2.minutes + 60;
					totalHours.hour=h_2.hour-1;
					totalHours.minutes=totalHours.minutes-h_1.minutes;
					totalHours.hour=totalHours.hour-h_1.hour;
					totalMins=(totalHours.hour*60)+totalHours.minutes;	
					return totalMins;			
				}
			
				else 
				{
					cout << "Please enter an appropriate time." << endl;
				}
			
			}
};

class Cat : public Animals{
	protected:
	
		string type;

	public:
		
		Cat(string typ,string id,string animalName,string ownerName,string ownerSurname) : Animals(id,animalName,ownerName,ownerSurname)
		{
			type=typ;
		}
	
		void printInfo()
		{
		// inheritance variables except type
		cout << "Id of the animal is " << id << endl;
		cout << "Name of the animal is " << animalName << endl;
		cout << "Name of the animal's owner is " << ownerName << endl ;
		cout << "Surname of the animal's owner is " <<ownerSurname << endl; 
		cout << "Type of the animal is " << type << endl;
		}
	
};
int main(){

	Cat c("Cat","123456","Goofy","Kobe","Bryant");
	c.printInfo();
	// h1->check in time // h2->check out time 
	Hours h1,h2;
	cout << "Enter the check in time of the animal: " << endl;
	cin >> h1;
	
	cout << "Enter the check out time of the animal: " << endl;
	cin >> h2;
	
	cout << "Check in and Check out times are "<< h1 << "/" << h2 << endl;
	
	cout << "The total time that animal stays in the clinic is " << c.calculateMinutes(h1,h2) << " minutes. !" << endl;

	
	return 0;
}



