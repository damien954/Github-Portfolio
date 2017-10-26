#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <ctime>
using namespace std;
const int TABLE_SIZE = 37;
 
class HashNode
{
    public:
		int value;//account num
		int key;
		string Lname;
		string Fname;
		unsigned month;
		unsigned day;
		unsigned year;
		float Annsalary;
		char dept_code;  //    Note: may be enter in either upper or lower case
		char phone_number[12];
		string phone_number1=phone_number;
		
		HashNode* next;
        HashNode(int key, int value)
        {
            this->key = key;
	    	this->value = value;
			this->Lname= Lname;
			this->Fname= Fname;
			this->day= day;
			this->year= year;
			this->Annsalary= Annsalary;
			this->dept_code= dept_code;
			this->phone_number1= phone_number1;
	    	this->next = NULL;

        }
};
class DeletedNode:public HashNode
{
    private:
        static DeletedNode *entry;
        DeletedNode():HashNode(-1, -1)
        {}
    public:
        static DeletedNode *getNode()
        {
            if (entry == NULL)
                entry = new DeletedNode();
            return entry;
        }
};
DeletedNode *DeletedNode::entry = NULL;
class HashMap
{
    private:
        HashNode** htable;
    public:
        HashMap()
        {
            htable = new HashNode*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                htable[i] = NULL;
        }
        ~HashMap()
        {
			for (int i = 0; i < TABLE_SIZE; ++i)
	    	{
                HashNode* entry = htable[i];
                while (entry != NULL)
	        	{
                    HashNode* prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
            delete[] htable;
        }
        int HashFunc(int key)
        {
            return key % TABLE_SIZE;
        }
        void Insert(int key, int value)
        {

            int hash_val = HashFunc(key);
            HashNode* prev = NULL;
            HashNode* entry = htable[hash_val];
            while (entry != NULL)
            {
                prev = entry;
                entry = entry->next;
            }
            if (entry == NULL)
            {
                entry = new HashNode(key, value);
                if (prev == NULL)
	        	{
                    htable[hash_val] = entry;
                }
	        	else
	        	{
                    prev->next = entry;
            	}
            }
            else
            {
                entry->value = value;
                
                
	          
			}
        }
        void Remove(int key)
        {
            int hash_val = HashFunc(key);
            HashNode* entry = htable[hash_val];
            HashNode* prev = NULL;
            if (entry == NULL || entry->key != key)
            {
            	cout<<"No Element found at key "<<key<<endl;
				return;
            }
            while (entry->next != NULL)
			{
                prev = entry;
                entry = entry->next;
            }
            if (prev != NULL)
            {
                prev->next = entry->next;
            }
            delete entry;
            cout<<"Element Deleted"<<endl;

        }
        int Search(int key)
        {
            bool flag = false;
            int hash_val = HashFunc(key);
            HashNode* entry = htable[hash_val];
            int count=0;
            while (entry != NULL)
			{ 

                if (entry->key == key&& count<1)
	        	{
                    cout<<entry->value<<" ";
                    flag = true;
                    count++;
                }
                else
                {
                    cout<<"*"<<entry->value<<" ";
                    flag = true;
                }
                entry = entry->next;
            }
            if (!flag)
                return -1;

        }


};

int main()
{
    HashMap hash;
	int value;			//Account_num
	float totsalary=0;
	int count=0;
	string Lname;
	string Fname;
	unsigned month;
	string Months[12]={
                           "Jan.","Feb.","Mar.","Apr.",
					       "May ","Jun.","Jul.","Aug.",
					       "Sep.","Oct.","Nov.","Dec."
                          };
    
	unsigned day;
	unsigned year;
	float Annsalary;
	char dept_code;  //    Note: may be enter in either upper or lower case
	char phone_number[12];

	ifstream inF;
	inF.open("hash.dat");
    int key;

    int choice;
    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Show collusion of Hash Table"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
		cout << endl;

        switch(choice)
        {
        	case 1:
                    cout <<setw(10)<<"Last"<<" account"<<setw(12)<<" Date of"<<setw(7)
                         <<" Annual"<<" Department"<< endl;
                    cout <<setw(10)<< "Name"<<" number"<<setw(12)<<" birth "<<setw(7) 
                         <<" salary"<<"   code"<<"\t Age"<<endl<<endl<<endl;

                    while(inF>> Lname)
                    {
	                   inF >> Fname >> value >> month>> day>> year>> Annsalary >>dept_code>> phone_number;
	                   count ++;
	                   key=value%TABLE_SIZE;
	                   dept_code=toupper(dept_code);
	                   cout<<setw(10)<< Lname <<" "<<setw(3)<<value<<"   ";
	                   cout<<Months[month-1]<<" "<<setw(2)<<day<<" "<<year<<"   ";
	                   // age calculator
	                   struct tm date = {0};
	                   date.tm_year = year-1900;
                       date.tm_mon  = month-1;
                       date.tm_mday = day;
                       time_t normal = mktime(&date);
                       time_t current;
                       time(&current);
                       long d = (difftime(current, normal) + 86400L/2) / 86400L;
                       int age=d/365;
                       //////////////////
	                   cout<<"$"<<setw(7)<<setprecision(2)<<fixed<<Annsalary<<"     ";
	                   cout<<dept_code<<" "<<age<<endl;
	
	                   totsalary+= Annsalary;
	                   hash.Insert(key, value);
                    }
                    cout << "Total Annual Salary: " << totsalary << endl;
                    cout << "Total record count: " << count;
                    break;
            case 2:
                    for(int i=0; i<TABLE_SIZE; i++)
	                {
	        	      key=i;
	        	      cout<<"Hash["<<i<<"] :  " ;
	        	      if (hash.Search(key) == -1)
            	      {
	        		     cout<<"NULL"<<endl;
	        		     continue;
	    		      } cout<<endl;	
			         }
                    break;
            case 3:
                    exit(1);
            default:
                    cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}

