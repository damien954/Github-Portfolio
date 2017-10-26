
#include <iostream>
#include <string>
#include <list>
using namespace std;
struct student
{
	string first_name;
	string last_name;
	double GPA;
	student(){}
	~student(){}
	struct student *next;
};
student *head = NULL;
void mainMenu()
{
	cout<<endl;
	cout<<"++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"            MAIN MENU             "<<endl;
	cout<<"    Choose from the following:    "<<endl;
	cout<<"[N]umber of students in the class "<<endl;
	cout<<"[A]dd a record                    "<<endl;
	cout<<"[D]elete a record                 "<<endl;
	cout<<"[V]iew all records                "<<endl;
	cout<<"[T]raverse all records            "<<endl;
	cout<<"[Q]uit program                    "<<endl;
	cout<<"++++++++++++++++++++++++++++++++++"<<endl;
	cout<<endl;
}
void addRecord()
{
	cout<<endl;
	cout<<"Add record:"<<endl;
	cout<<endl;
	struct student *temp, *alt;
	temp = new student;
	cout<<"What is the student's last name: ";
	cin>>temp->last_name;
	cout<<"What is the student's first name: ";
	cin>>temp->first_name;
	cout<<"What is student's GPA: ";
	cin>>temp->GPA;
	temp->next = NULL;
	if(head == NULL)
		head = temp;
	else
	{
		alt = head;
		while(alt->next != NULL)
		{
			alt = alt->next;
		}
		alt->next = temp;
	}
}
void deleteRecord()
{
	cout<<endl;
	cout<<"Delete record:"<<endl;
	cout<<endl;
	student *del;
	del = head;
	del = del->next;
	cout<<endl;
	cout<<"Name to delete: ";
	cin>>del->last_name;
	
	if(del->next == NULL)
		cout<<"Nothing follows."<<endl;
	else
	{
		student *temp;
		temp = del->next;
		del->next = temp->next;
		delete temp;
	}
	if(del->next == NULL)
		cout<<"End of the list."<<endl;
	else
		del = del->next;
	if(del == head)
		cout<<"Beginning of list."<<endl;
	else
	{
		student *prev;
		prev = head;
		while(prev->next != del)
		{
			prev = prev->next;
		}
		del = prev;
	}
	
}
void viewRecord()
{
	cout<<endl;
	cout<<"All records:";
	cout<<endl;
	struct student *temp;
	temp = head;
	do
	{
		if(temp == NULL)
			cout<<"Nothing follows."<<endl;
		else
		{
		cout<<"Name: "<<temp->last_name<<", ";
		cout<<temp->first_name<<endl;
		cout<<"GPA: "<<temp->GPA<<endl;
		cout<<endl;
		temp = temp->next;
		}
	}
	while(temp != NULL);
}
void traverseRecord()
{
	struct student *temp;
	temp = head;
	if(temp != 0)
	{
		while(temp != 0)
		{
			cout<<"Name: "<<temp->last_name<<", ";
			cout<<temp->first_name<<endl;
			cout<<"GPA: "<<temp->GPA<<endl;
			cout<<endl;
			temp = temp->next;
		}
	}
	while(temp != NULL)
	{
		cout<<"Name: "<<temp->last_name<<", ";
		cout<<temp->first_name<<endl;
		cout<<"GPA: "<<temp->GPA<<endl;
		cout<<endl;
		temp = temp->next;
	}
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
				case 'A':
					addRecord();
					break;
				case 'D':
					deleteRecord();
					break;
				case 'V':
					viewRecord();
					break;
				case 'T':
					traverseRecord();
					break;
				}
	}
	while(choice != 'Q');
		cout<<endl;
		cout<<"Terminating.."<<endl;
	system("PAUSE");
	return 0;
}
