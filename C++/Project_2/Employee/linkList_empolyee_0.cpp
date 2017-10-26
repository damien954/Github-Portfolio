#include <iostream>
#include <string>

using namespace std;



void Menu_Choice(int choice)
{
	string E_Fname;
	string E_Lname;

	struct Employee
	{
    	string Fname;
		string Lname; // or char name[] with the max number of characters allowed in a name
    
    	Employee *next;  //pointer to the next employee
	};

	switch (choice)
   {
   		case 1:
   			Employee *head;
    		head = NULL;  

			for (int i = 0; i < 2; i++)
			{
				cout << "what is the employees First name: ";
				cin >> E_Fname;
				cout << "what is the employees Last name: ";
				cin >> E_Lname;

			Employee *newEmployee;
			Employee *Employee_ptr;
			newEmployee = new Employee;
			newEmployee->Fname = E_Fname;
			newEmployee->Lname = E_Lname;


			newEmployee->next = NULL;

				if(!head)
					head = newEmployee;
				else
				{
					Employee_ptr = head;

					while(Employee_ptr -> next)
						Employee_ptr = Employee_ptr -> next;

					Employee_ptr->next = newEmployee;
				}

				cout << endl;
			}
   			     
  			break;
  		case 2:
  			
			Employee *Display_ptr;
			Display_ptr = head;

			while (Display_ptr)
			{
   				cout << Display_ptr->Fname << endl;
   				cout << Display_ptr->Lname[0] << endl;

 				Display_ptr = Display_ptr->next;
  				cout << endl;
			}	
		  	
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
	cout << "1. Enter a employee record. " << endl;
	cout << "2. List all employee records. " << endl;
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
