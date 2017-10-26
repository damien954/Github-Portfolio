// ------------------------------------------------------------------
// File name:   Sorting_A.cpp
// Assign :     Sorting program  step #1 
// 
// Author:      Damien Cunningham
//
// ------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>  
#include <cmath>
using namespace std;

int Menu( )
{
   int Choice;  // Menu choice.
   //-| --------------------------------------------------------------
   //-|  Display the menu.
   //-| --------------------------------------------------------------
   
   cout<<"Option 1: create a sorted array"<<endl;
   cout<<"Option 2: create a unsorted array"<<endl;
   cout<<"Option 3: create a random sorted array"<<endl;
   cout<<"Option 4: quit";
   cout << endl<<endl;
   //-| --------------------------------------------------------------
   cout << "Enter Menu Choice: ";
   cin >> Choice;
   cout << endl;

   return Choice;
} //Menu_Choice

void Menu_Choice(char choice)
{
   
   int size=500000; //size is the capcity of the array 
   int count=0; // count is the incrementer that transverse through the array
   int A[size]; //
   switch (choice)
   {
   		case 1: // case 1 is for sorted numbers in ascending  order (0  through capcity-1)  
  			cout<<"sorted"<<endl;
			for(int i=0; i<size; i++)
			{
				A[i]=i;
				if (i<10 ||i>size-11 ) // display the first and last 10  elements of the array
				{
					
					cout<<A[i]<<endl;
					count++;
					if (count == 10)
					{
						cout<<endl;
					}
				}
			}
			cout<<endl<<endl;break;// display sorted data
			
  		case 2:// case 1 is for sorted numbers in descending order  (capcity-1  through  0)
  			cout<<"umsorted"<<endl;
  			for(int i=size; i>=0; i--)
  			{
  				A[i]=i;
  				if (i>size-10 || i<10 )// display the first and last 10  elements of the array
				{
					cout<<A[i]<<endl;
					count++;
					if (count == 10)
					{
						cout<<endl;
					}
				} 
			}
			cout<<endl<<endl;break;// display sorted data
			
  		case 3:
  			
  			cout<<"Random"<<endl;
  			for(int i=0;i<size; i++)
 			{
 				
 				A[i]=rand()% size*100;; // random generator  only fills array with unique numbers
 				for(int y=0; y<i; y++)
 				{
 					if(A[i]==A[y])
 					{
 						y=i;
 						i--;
					}	
				}	
 			}
 				for(int n=0; n<size;n++)
 				{
 						if (n<10 ||n>size-11 )// display the first and last 10  elements of the array
						{
							cout<<A[n]<<endl;
							count++;
							if (count == 10)
							{
								cout<<endl;
							}
						} 
				}break;//display random data
				
  		default:
  			cout << endl << "BAD MENU CHOICE ... retry" << endl<<endl;
    		break;//default
      

   }//end_switch

} //Menu_Choice


int main()
{
   //----------------------------------------------------------------------
   // Declare variables for program.
   //----------------------------------------------------------------------
   int choice;    

   do
   { 
      choice = Menu();
	Menu_Choice(choice);
   }
   while (choice != 4);
   
   return 0;
}//main
