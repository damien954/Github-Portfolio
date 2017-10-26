// studentGPAquery.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <list>
using namespace std;
struct Employee
{
	string Fname;
	string Lname;
	Employee(){}
	~Employee(){}
	struct Employee *next;
};
Employee *head = NULL;
void mainMenu()
{
	cout<<endl;
	cout << "\t\t====== Employee INFORMATION SYSTEM ======";
    cout <<"\n\n                                          ";
    cout << "\n\n";
    cout << "\n \t\t\t 1. Add    Records";
    cout << "\n \t\t\t 2. View   Records";
    cout << "\n \t\t\t 3. Modify Records";
    cout << "\n \t\t\t 4. Delete Records";
    cout << "\n \t\t\t 5. Exit   Program";
    cout << "\n\n";
	cout<<endl;
}
void addRecord()
{
	cout<<endl;
	cout<<"Add record:"<<endl;
	cout<<endl;
	//struct Employee *newEmployee, *Employee_ptr;
	Employee *newEmployee;
	//Employee *Employee_ptr;
	Employee *last_pointer;
    Employee *curr_pointer;
    string E_Fname;
    string E_Lname;
	//newEmployee = new Employee;
	newEmployee = new Employee;
	cout<<"What is the Employee's last name: ";
	cin>>E_Lname;
	cout<<"What is the Employee's first name: ";
	cin>>E_Fname;
	newEmployee->Fname = E_Fname;
	newEmployee->Lname = E_Lname;

	newEmployee->next = NULL;
	
    if (head == NULL)
	{
       	newEmployee->next = head;
       	head = newEmployee;
   	}
	else
	{
       	curr_pointer = head;
       	last_pointer    = head;
       	while (curr_pointer && curr_pointer->Lname < E_Lname)
		{
           	last_pointer = curr_pointer;
           	curr_pointer = curr_pointer->next;
       	}

      	if (curr_pointer == head)
		{
            /* Insert before 1st Node */
           	newEmployee->next = head;
            head = newEmployee;
       	}
        else
		{
            /* Insert between last_pointer and curr_pointer 
            or at the end of the list */
            last_pointer->next = newEmployee;
            newEmployee->next = curr_pointer;
        }
   	}




}
void deleteRecord()
{
	cout<<endl;
	cout<<"Delete record:"<<endl;
	cout<<endl;
	Employee *del;
	del = head;
	del = del->next;
	if(del->next == NULL)
		cout<<"End of the list."<<endl;
	else
		del = del->next;
	if(del == head)
		cout<<"Beginning of list."<<endl;
	else
	{
		Employee *prev;
		prev = head;
		while(prev->next != del)
		{
			prev = prev->next;
		}
		del = prev;
	}
	cout<<endl;
	cout<<"Name to delete: ";
	cin>>del->Lname;
	
	if(del->next == NULL)
		cout<<"Nothing follows."<<endl;
	else
	{
		Employee *newEmployee;
		newEmployee = del->next;
		del->next = newEmployee->next;
		delete newEmployee;
	}
}
void viewRecord()
{
	cout<<endl;
	cout<<"All records:";
	cout<<endl;
	struct Employee *newEmployee;
	newEmployee = head;
	do
	{
		if(newEmployee == NULL)
			cout<<"Nothing follows."<<endl;
		else
		{
		cout<<"Name: "<<newEmployee->Lname<<", ";
		cout<<newEmployee->Fname<<endl;
		cout<<endl;
		newEmployee = newEmployee->next;
		}
	}
	while(newEmployee != NULL);
}
void modify()
{
	cout<<"modify node"<<endl;
}
int main()
{
	char choice;
	
	do{
		mainMenu();
			cout<<"Command?: ";
			if(cin>>choice)
				switch(choice)
				{
				case '1':
					addRecord();
					break;
				case '2':
					viewRecord();
					break;
				case '3':
					modify();
					break;
				case '4':
					deleteRecord();
					break;
				}
	}
	while(choice != '5');
		cout<<endl;
		cout<<"Terminating.."<<endl;
	system("PAUSE");
	return 0;
}
