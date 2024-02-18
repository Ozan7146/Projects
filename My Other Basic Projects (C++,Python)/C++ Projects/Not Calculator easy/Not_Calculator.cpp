#include<iostream>
using namespace std;

int main(){
	float mid1,mid2,final,homework[3],final_Lab;
	float sum,x=0;	
	cout << "Enter mid1,mid2,final,final_Lab:" << endl;
	cin >> mid1 >> mid2 >> final >> final_Lab;
	
	for(int i=0;i<3;i++)
	{
	cout << "Enter the homework grade number " << i+1 << ":";
	cin >> homework[i];
	x += homework[i];
	}
//	cout << "x:" << x/3 << endl;
//	cout << (x*10)/100 << endl;
	sum = (mid1*25)/100 + (mid2*25)/100 + (final*30)/100 +  (x/3)*10/100 + (final_Lab*10)/100;
	cout << sum;
	
}
