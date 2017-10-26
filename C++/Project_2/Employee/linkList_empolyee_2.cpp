#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

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
	
	unsigned thisYear;
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	thisYear=timePtr->tm_year+1900;

	int size;
	int total_Sal=0;

	struct Employee
	{
    	string Fname;
		string Lname; // or char name[] with the max number of characters allowed in a name
    	unsigned month;
		unsigned day;
		unsigned year;
		float annual_salary;
		char dept_code;  //    Note: may be enter in either upper or lower case
		string phone_number;
		int Age;

    	Employee *next;  //pointer to the next student
	};

	switch (choice)
   {
   		case 1:
   			Employee *Head;
			Head=NULL;

			for(int i=0; i<5; i++)
			{
				cout << "what is the employee First name: ";
				cin >> E_Fname;
				cout << "what is the employee Last name: ";
				cin >> E_Lname;
				cout << "what is the employee Month of brith: ";
				cin >> E_month;
				cout << "what is the employee Day of brith: ";
				cin >> E_day;
				cout << "what is the employee Year of brith: ";
				cin >> E_year;
				cout << "what is the employee Salary: ";
				cin >> E_annual_salary;
				total_Sal=total_Sal+E_annual_salary;
				cout << "what is the employee Dept. Code: ";
				cin >> E_dept_code; 
				cout << "what is the employee Phone Number: ";
				cin >> E_phone_number;
				E_Age= thisYear-E_year;
				

		
				Employee *newEmployee;	
        		Employee *last_pointer;
        		Employee *curr_pointer;
        
				newEmployee = new Employee;
        
        ////////////////////////////////////////////////////////////////////////
				newEmployee->Fname = E_Fname;
				newEmployee->Lname = E_Lname;
				newEmployee->month = E_month;
				newEmployee->day   = E_day;
				newEmployee->year  = E_year;
				newEmployee->annual_salary= E_annual_salary;
				newEmployee->dept_code= E_dept_code; 
				//newEmployee->phone_number[12]= E_phone_number[12];
				newEmployee->Age = E_Age; 
		////////////////////////////////////////////////////////////////////////
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
        			while (curr_pointer && curr_pointer->Lname < E_Lname)
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


				cout << endl;
			};

  			break;
  		case 2:
  			
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
   				// phone number
				cout <<setw(5)<<Display_ptr->Age;
   				
   			
   			

 				Display_ptr = Display_ptr->next;
  				cout <<setfill (' ')<< endl;
  				
  				
			}	
			cout<<"Total Salary: "<<total_Sal<<endl;
		  	
  			break;	
  		case 3:
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
