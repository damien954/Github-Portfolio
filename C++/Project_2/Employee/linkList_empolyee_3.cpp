// ------------------------------------------------------------------
// File name:   linkList_empolyee_3.cpp
// Assign :     linkList_empolyee_record
// 
// Author:      Damien Cunningham
//
// ------------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;



void Menu_Choice(int choice)
{
	string E_Fname;
	string E_Lname;
	unsigned E_month;
	unsigned E_day;
	unsigned E_year;
	float E_annual_salary;
	char E_dept_code;  //    Note: may be enter in either upper or lower case
	char E_phone_number[12];
	int E_Age;
	ifstream File;
	int size=50;
    int cap=0;
	
	unsigned thisYear;
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	thisYear=timePtr->tm_year+1900;

	float total_Sal=0;

	struct Employee
	{
    	string Fname;
		string Lname; 
    	unsigned month;
		unsigned day;
		unsigned year;
		float annual_salary;
		char dept_code;
		string phone_number;
		int Age;

    	Employee *next;  //pointer to the next employee
	};

	switch (choice)
   {
   		case 1:
   			Employee *Head;
			Head=NULL;
			File.open ("Employee_info_1.txt");
			 if (File.fail())
  			 {
         		cout<<"FATAL ERROR: Can not open 'Employee'";
         		cout<<" PROGRAM TERMINATING ...\n";
	  			exit(1);
  			 }
			//"what is the employee First name: ";	
			while(File>>E_Fname && cap<=size-1)//read while capcity is less size
			{
		    	//"what is the employee Last name: ";
				File >> E_Lname;
				//"what is the employee Month of brith: ";
				File >> E_month;
				//"what is the employee Day of brith: ";
				File >> E_day;
				//"what is the employee Year of brith: ";
				File >> E_year;
				//"what is the employee Salary: ";
				File >> E_annual_salary;
				total_Sal=total_Sal+E_annual_salary;
				//"what is the employee Dept. Code: ";
				File >> E_dept_code; 
			    //"what is the employee Phone Number: ";
				File >> E_phone_number;
				E_Age= thisYear-E_year;
				cap++;//capcity for linked list

		
				Employee *newEmployee;	
        		Employee *last_pointer;
        		Employee *curr_pointer;
        
				newEmployee = new Employee;
				newEmployee->Fname = E_Fname;
				newEmployee->Lname = E_Lname;
				newEmployee->month = E_month;
				newEmployee->day   = E_day;
				newEmployee->year  = E_year;
				newEmployee->annual_salary= E_annual_salary;
				newEmployee->dept_code= E_dept_code; 
				newEmployee->Age = E_Age; 
	
				newEmployee->next = NULL;
		
		
    			if (Head == NULL)
				{
        			newEmployee->next = Head;
        			Head = newEmployee;
    			}
				else
				{
        			curr_pointer = Head;
        			last_pointer    = Head;
        			while (curr_pointer && curr_pointer->Lname < E_Lname)//sorting in order lastname
					{
            			last_pointer = curr_pointer;
           		 		curr_pointer = curr_pointer->next;
       				}

        			if (curr_pointer == Head)
					{
            			/* Insert before 1st Node */
           	 			newEmployee->next = Head;
            			Head = newEmployee;
        			}
        			else
					{
            			/* Insert between last_pointer and curr_pointer 
               			or at the end of the list */
            			last_pointer->next = newEmployee;
            			newEmployee->next = curr_pointer;
        			}
     			}


				
			};
 			File.close();
  			break;
  		case 2:
  			//Display linked list
  			//Last Name  First Name       D.O.B         Salary Dept Code  Age
            //Bray           T.         02/28/1989     23500.00     B     27
			Employee *Display_ptr;
			Display_ptr = Head;
			cout <<"Employee Record"<<endl;
				cout <<setw(15)<<"Last Name"<<setw(12)<<"First Name";
				cout <<setw(12)<<"D.O.B"<<setw(15)<<"Salary";
				cout <<setw(10)<<"Dept Code";
				cout <<setw(5)<<"Age"<<endl;
			while (Display_ptr)
			{
   				cout <<setw(15)<< Display_ptr->Lname <<setw(12)<< Display_ptr->Fname[0]<<".    ";
   				cout <<setw(2)<<fixed << setfill ('0')<<Display_ptr->month <<"/";
				cout <<setw(2)<< Display_ptr->day <<"/";
				cout <<setw(4)<<Display_ptr->year<<"  ";
				cout <<setfill (' ');
   				cout <<setw(9)<<fixed <<setprecision (2)<< Display_ptr->annual_salary << "   ";
   				cout <<setw(8)<< Display_ptr->dept_code << "  ";
				cout <<setw(5)<<Display_ptr->Age;
 				Display_ptr = Display_ptr->next;
  				cout <<setfill (' ')<< endl;
  			
			}	
			cout<<"Total Salary: "<<total_Sal<<endl;
		  	
  			break;			
  		default:
  			cout << endl << "BAD MENU CHOICE ... retry" << endl<<endl;
    		break;//default
   }//end_switch
	
}

 int Menu( )
{
   int Choice;  // Menu choice.
   //-| --------------------------------------------------------------
   //-|  Display the menu.
   //-| --------------------------------------------------------------
    cout << "What would you like to do?" << endl;
	cout << "=========================" << endl;
	cout << "1. Enter a student record. " << endl;
	cout << "2. List all student records. " << endl;
	cout << "3. Exit program. " << endl;
	cout << endl;
	cin  >> Choice;
    cout << endl;

    return Choice;
}

int main() 
{
   cout << "Employee Record Program." << endl << endl;
   int choice;
	do
	{
		choice = Menu();
		Menu_Choice(choice);
	}
	while (choice != 3);  
 
   system("pause");
   return 0;
} 
