#include<iostream>
#include<string>
#define MAX 100									//Maximum Size of Array
using namespace std;

class Student
{
private:
	string name;
	int roll;
	string add;
	long long int mobileno;
	string dob;
	string dln;
public:
	static string Class;
	static char sec;
	void getdata();							//Get Data Func
	void displaydata();					//DIsplay Func

	Student();							//Constructor
	~Student() {}					//Destructor
};
string Student::Class = "Second Year";				//Static Variable 01
char Student::sec = 'A';										//Static Variable 02
void Student::getdata()
{
	cout << "Enter The name of the student : ";
	cin >> name;
	cout << "Enter the Roll No.  as a digit : ";
	cin >> roll;
	cout << "Enter the Address : ";
	cin >> add;
	cout << "Please enter mobile number : ";
	cin >> mobileno;
	cout << "Enter Your Date of Birth  ( DD / MM / YYYY ) in the given form :";
	cin >> dob;
	cout << "Enter The Driving Licence Number Of the Student : ";
	cin >> dln;

}
void Student::displaydata()
{
	cout << "Name : " << name << endl;
	cout << "Class and Section : " << Class << " - " << sec << endl;					//Static Variable Called
	cout << "Roll No. : " << roll << endl;
	cout << "Address : " << add << endl;
	cout << "Mobile Number : " << mobileno << endl;
	cout << "Date Of Birth   ( DD / MM / YYYY ) : " << dob << endl;
	cout << "Driving Licence Number : " << dln << endl;
}
Student::Student()
{
	name = "None";
	roll = 00;
	add = "None";
	mobileno = 1234567890;
	dob = "DD / MM / YYYY";
	dln = "None";
}
int main()
{
	int i{ 1 }, n{ 0 };
	Student sample;
	cout << "---------------------------Sample of default constructor when OBJ is used without initialization --------------------- \n \n";
	sample.displaydata();
	Student stud[MAX];
	cout << "\n------------------------------------------------------------------------------------------------------------------------------------ \n \n";
	cout << "\nEnter the number of Students Database u wanna develop (less than 100) : ";
	cin >> n;
	cout << "\n=============================Enter Database =====================================\n";
	do										//Get Data
	{
		stud[i].getdata();
		cout << "\n=========================================================================\n";
		i++;
	} while (i <= n);
	i = 1;
	cout << "\n--------------------------------------------Displaying Entered Database ---------------------------------------------------\n";
	do										//Display Data
	{
		stud[i].displaydata();
		cout << "\n=========================================================================\n";
		i++;
	} while (i <= n);
	cout << "\n--------------------------------------------End Of Program------------- ---------------------------------------------------\n";
	return 0;
}