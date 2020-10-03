#include<iostream>			
#include<string>			
using namespace std;		
#define max 100;

class personalinfo								//student is friend class of personalinfo
{
    string lic, dob, bldgrp;    
public:
    personalinfo();                 //DECLARE DEFAULT CONSTRUCTOR
    personalinfo(personalinfo&);       //DECLARE COPY CONSTRUCTOR
    ~ personalinfo()                 //DESTRUCTOR
    {
        cout << "\nDESTRUCTOR IS CALLED!!!!!" << endl;
        cout<< "RECORD DELETED SUCCESSFULLY" << endl;
    }
    friend class student;                     //FRIEND FUNCTION
};
class student   							//STUDENT CLASS
{
    string name, address, year;				
    char div;
    int roll_no;
    long long int mob;
    static int count; 						//    STATIC VARIABLE
public:
    void getdata(personalinfo&);				
    void displaydata(personalinfo&);			//TO DISPLAY DATABASE

    inline static void keepcount()                //STATIC FUNCTION

    {
        count++;
    }
    inline static void showcnt()               //STATIC FUNCTION
                                      //INLINE FUNCTION
    {
        cout << "\nTOTAL NO OF DATABASES STORED ARE : " << count;
    }
    student();                           //DEFAULT CONSTRUCTOR
    student(student&);                  //COPY CONSTRUCTOR 
    ~student()                          //DESTRUCTOR
    {
        cout << "\nDESTRUCTOR IS CALLED!!!" << endl << "RECORD DELETED SUCCESSFULLY" << endl;
    }
};

int student::count;              // STATIC MEMBER//
student::student()                //CONSTRUCTOR
{
    name = "None";
    address = "None";
    year = "SE COMPUTER";
    div = 'A';
    roll_no = 00;
    mob = 1234567890;
}
personalinfo::personalinfo()             //CONSTRUCTOR DEFINITION
{
    lic = "123erfghyu78";
    dob = "(DD/MM/YYYY)";
    bldgrp = "A+";
}
student::student(student & obj)			// COPY CONTRUCTOR
{
    this->name = obj.name;			//this pointer
    this->address = obj.address;	
    this->year = obj.year;
    this->div = obj.div;
    this->roll_no = obj.roll_no;
    this->mob = obj.mob;
}
personalinfo::personalinfo (personalinfo& obj)		// COPY CONTRUCTOR
{
    lic = obj.lic;
    dob = obj.dob;
    bldgrp = obj.bldgrp;
}
void student::getdata (personalinfo& obj)
{
    cout << "\nNAME : " << endl;
    cin >> name;
    cout << "\nADDRESS : " << endl;
    cin >> address;
    cout << "\nDATE OF BIRTH : " << endl;
    cin >> obj.dob;
    cout << "\nYEAR : " << endl;
    cin >> year;
    cout << "\nDIVISION: " << endl;
    cin >> div;
    cout << "\nROLL NUMBER : " << endl;
    cin >> roll_no;
    cout << "\nBLOOD GROUP : " << endl;
    cin >> obj.bldgrp;
    cout << "\nLICEINCE NUMBER : " << endl;
    cin >> obj.lic;
    cout << "\nPHONE NUMBER : " << endl;
    cin >> mob;
}

void student::displaydata(personalinfo& obj)
{
    cout << "\n=========================================================================\n";
    cout << "\nNAME OF STUDENT : " << name << endl;
    cout << "\nADDRESS OF STUDENT : " << address << endl;
    cout << "\nDATE OF BIRTH : " << obj.dob << endl;
    cout << "\nYEAR : " << year << endl;
    cout << "\nDIVISION : " << div << endl;
    cout << "\nROLL NO : " << roll_no << endl;
    cout << "\nBLOOD GROUP : " << obj.bldgrp << endl;
    cout << "\nLICEINCE NUMBER : " << obj.lic << endl;
    cout << "\nPHONE NUMBER : " << mob << endl;
    cout << "\n=========================================================================\n";
}
int main()
{
    int n;				//NUMBER OF STUDENTS
    int ch;
    char ans;

    cout << "\nENTER NO OF STUDENTS :" << endl;
    cin >> n;
    cout << "\n=========================================================================\n";
    student* sobj = new student[n];				// DYNAMIC MEMORY 
    personalinfo* pobj = new personalinfo[n];		// DYNAMIC MEMORY 

    do
    {
        cout << "\n Menu \n 1. Create Database \n 2. Display Databse \n 3. Copy Constructor\n 4. Default Constructor \n 5. Delete (Destructor)";
        cout << "\n Enter your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1: // create database
        {
            for (int i = 0; i < n; i++)
            {
                sobj[i].getdata(pobj[i]);
                sobj[i].keepcount();

            }
        }
        break;
        case 2: // Display Database
        {
            sobj[0].showcnt(); 	//to display the total count of students
           
            for (int i = 0; i < n; i++)
            {
                sobj[i].displaydata(pobj[i]);
            }
        }
        break;
        case 3: // Copy Constructor
        {
            student obj1;
            personalinfo obj2;
            obj1.getdata(obj2);
            student obj3(obj1);		// copy constructor 

            personalinfo obj4(obj2);		 // copy constructor 
            cout << "\n Copy Constructor is called ";
            obj3.displaydata(obj4);
        }
        break;
        case 4: // Default Constructor
        {
            student obj1;	// default constructor 
            personalinfo obj2;	//default constructor 
            cout << "\n Default Constructor is called ";
            obj1.displaydata(obj2);
        }
        break;
        case 5: // destructor

            delete[] sobj;			
            delete[] pobj;		
        }				                
        cout << "\nDo You Want To Continue ? (y/n) : ";
        cin >> ans;
    } while (ans == 'y');


    return 0;
}