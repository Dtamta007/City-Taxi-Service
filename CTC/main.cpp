#include<bits/stdc++.h>
using namespace std;

//CLASS TAXI

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
		int display(int i);
		int getserved();
		string getname();
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

int taxi::getserved()
{
	return served;
}

string taxi::getname()
{
	return driver;
}

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

//VALUE BEING READ FROM FILE OF PROJECT 1

int taxi::display(int i)
{
	int ans;
	fstream  fin("CTC.dat", ios::binary | ios::in);
	srand(time(nullptr));
	taxi::pass = rand() % (6 + 1 -1) +1 ;
	fin.seekg(sizeof(taxi)*i);
	ans = served;
	while(fin.read((char*)this, sizeof(taxi)))
	{
			cout<<"Taxi "<<taxi_id<<" a "<<color<<" "<<brand<<" "<<model<<" driven by "<<driver<<" will pick you up in a few minutes. "<<"(Taxi "<<taxi_id<<" determined that there were "<<taxi::pass<<" passengers)"<<endl<<endl;
			ans += taxi::pass;
			served = ans;
			break;
	}
	fin.close();
	return taxi::pass;
}

//MAIN CODE

int main()
{
	taxi data;
	taxi t[6];		//ARRAY OF OBJECTS
	int i;
	int project;
	int check=1;
	int count=0;
	char ch;
	cout<<"Welcome to CTC"<<endl<<endl;
	while(ch!='N')
	{
		cout<<"Do You Need a Taxi? "<<endl;
		cin>>ch;
		cout<<endl;
		if(ch=='Y')
		{
			srand(time(nullptr));
	 		i = rand() % (5 + 0 - 0) +0;
	 		count+=t[i].display(i);
	 		
		}
		else if (ch!='N' && ch!='Y')
		{
			cout<<"Enter a valid input!"<<endl<<endl;
		}
    }

	cout<<"CTC served a total of "<<count<<" passengers today "<<endl<<endl;
	for(i=0; i<6; i++)
	{
		if(t[i].getserved()==0)
		{
			continue;
		}
		cout<<t[i].getname()<<" served "<<t[i].getserved()<<" passengers. "<<endl<<endl;
	}
//		cout<<"To exit press 0 else press 1 ";
//		cin>>check;
//	cout<<endl<<endl;
	return 0;
}

