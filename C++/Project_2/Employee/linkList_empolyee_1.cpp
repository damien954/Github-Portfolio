#include <iostream>
#include <string>

using namespace std;



void Menu_Choice(int choice)
{
	string E_Fname;
	string E_Lname;
	int size;

	struct Employee
	{
    	string Fname;
		string Lname; // or char name[] with the max number of characters allowed in a name
    
    	Employee *next;  //pointer to the next employee
	};

	switch (choice)
   {
   		case 1:
   			Employee *Head;
			Head=NULL;

			for(int i=0; i<2; i++)
			{
				cout << "what is the employees First name: ";
				cin >> E_Fname;
		
				Employee *Employee;	
        		Employee *last_pointer;
        		Employee *curr_pointer;
        
				newEmployee = new Employee;
        
        ////////////////////////////////////////////////////////////////////////
				newEmployee->Fname = E_Fname;
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
        			while (curr_pointer && curr_pointer->Fname < E_Fname)
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

			while (Display_ptr)
			{
   				cout << Display_ptr->Fname << endl;
   				cout << Display_ptr->Lname[0] << endl;

 				Display_ptr = Display_ptr->next;
  				cout << endl;
			}	
		  	
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
