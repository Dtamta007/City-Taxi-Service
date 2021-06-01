#include<bits/stdc++.h>
using namespace std;

class taxi
{
	private:
		char taxi_id[10];
		char driver[10];
		char brand[10];
		char model[10];
		char color[10];
		char license[10];
		static int pass;
		int served;
	public:
		taxi();
		void read();
};

//MEMBER FUNCTION DECLARATION

taxi::taxi()
{
	strcpy(taxi_id, " ");
	strcpy(driver, " ");
	strcpy(brand, " ");
	strcpy(model, " ");
	strcpy(color, " ");
	strcpy(license, " ");
	served = 0;
}

int taxi::pass=0;

//VALUE INPUT FOR PROJECT 1

void taxi :: read()
{
	fstream file("CTC.dat", ios::binary | ios::out | ios::trunc);
	int count = 0;
	char ch;
	while(file)
	{
		cout<<"Enter Taxi Id: ";
		cin>>taxi_id;
		cout<<"Enter driver's Name: ";
		cin>>driver;
		cout<<"Enter name of maker of car: ";
		cin>>brand;
		cout<<"Enter model of car: ";
		cin>>model;
		cout<<"Enter color of car: ";
		cin>>color;
		cin.ignore();
		cout<<"Enter License Number: ";
		cin.getline(license, 10);
		count++;
		cout<<"Enter another record?(Y/N)";
		cin>>ch;
		cout<<endl<<endl;
		if(count==50)
		{
			break;
		}
		file.write((char*)this, sizeof(taxi));

		if(ch=='N')
		{
			break;
		}
		
	}
	file.close();
}

int main()
{

	taxi data;
	data.read();

	return 0;
}

