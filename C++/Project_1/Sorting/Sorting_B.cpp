// ------------------------------------------------------------------
// File name:   Sorting_B.cpp
// Assign :     Sorting program  step #1 
// 
// Author:      Damien Cunningham
//
// ------------------------------------------------------------------


#include <iostream>
#include <stdlib.h>  
#include <cmath>
#include <iomanip>      // std::setw
using namespace std;

 int size=20;

void print_data(int array[],int size)
{
	int count=0;
  	for(int i=size-1; i>=0; i--)
  	{
  	
  		if (i>size-11 || i<10 )
		{
			cout<<setw(4)<<array[i]<<" ";
			count++;
				if (count == 10)
				{
					cout<<"||";
				}
		} 
	}cout<<endl;
}
void printdata(int array[],int size)
{
	int count=0;
  	for(int i=0; i<size; i++)
  	{
  	
  		if (i>size-11 || i<10 )
		{
			cout<<setw(4)<<array[i]<<" ";
			count++;
				if (count == 10)
				{
					cout<<"||";
				}
		} 
	}cout<<endl;
}
int sort_data( int array[], int size)
{
	cout<<"sorted"<<endl;
	int count=0;
  	for(int i=size; i>=0; i--)
  	{
  		array[i]=i;
  
	}cout<<endl;
}
int unsort_data( int array[], int size)
{
  	for(int i=size-1; i>=0; i--)
  	{
  		array[i]=i;
  		
	}
}

int random(int array[], int size)
{
	cout<<"Random"<<endl;
		int count=0;
  	for(int i=0;i<size; i++)
 	{
 				
 		array[i]=rand()% 300;
 		for(int y=0; y<i; y++)
 		{
 			if(array[i]==array[y])
 			{
 				y=i;
 				i--;
			}	
		}	
 	}
 
}

int BubbleSort( int array[], int size)
{
	int hold,count=0;
	for(int i=0; (i<size-1); i++)
	{
	
		for(int j=0; j<size-1; j++)
		{
		
		if(array[j]>array[j+1])
		{
			hold=array[j];
			array[j]=array[j+1];
			array[j+1]=hold;
		 
		
		}
		
		} 	
	}

 	for(int i=0; i<size; i++)
	{

		if(i<10 || i>size-11)
		{
			cout<<setw(4)<<array[i]<<" ";
			count++;
				if (count == 10)
				{
					cout<<"||";
				}
		}
	
 	}cout<<endl;		
}

int BubbleSort_Smart( int array[], int size)
{
	int hold,flag=1,count=0;
	for(int i=0; (i<size-1) && flag; i++)
	{
		flag =0;
		for(int j=0; j<size-1; j++)
		{
		
		if(array[j]>array[j+1])
		{
			hold=array[j];
			array[j]=array[j+1];
			array[j+1]=hold;
			flag = 1; 
		
		}
		
		} 	
	} 
	
	for(int i=0; i<size; i++)
	{

		if(i<10 || i>size-11)
		{
			cout<<setw(4)<<array[i]<<" ";
			count++;
				if (count == 10)
				{
					cout<<"||";
				}
		}
	
 	}cout<<endl;
}

int Insertion_Sort(int array[], int size)
{
	int j, temp,count=0;
		
	for (int i = 0; i < size; i++)
	{
		j = i;
		
		while ( j > 0 && array[j] < array[j-1] )
		{
			  temp = array[j];
			  array[j] = array[j-1];
			  array[j-1] = temp;
			  j--;
			  
		}
	}

	
	for(int i=0; i<size; i++)
	{

		if(i<10 || i>size-11)
		{
			cout<<setw(4)<<array[i]<<" ";
			count++;
				if (count == 10)
				{
					cout<<"||";
				}
		}
	
 	}cout<<endl;
}

void shell_Sort (int array[], int size)
{
  int j,count=0;
 
  //Narrow the array by 2 everytime
  for (int gap = size / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < size; ++i)
    {
      int temp = array[i];
      for (j = i; j >= gap && temp < array[j - gap]; j -= gap)
      {
        array[j] = array[j - gap];
      }
      array[j] = temp;
    } 
  }
  
  	for(int i=0; i<size; i++)
	{
       
		if(i<10 || i>size-11)
		{
			cout<<setw(4)<<array[i]<<" ";
			count++;
				if (count == 10)
				{
					cout<<"||";
				}
		}
	
 	}cout<<endl;
  
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
  
    
}

void quickSort(int arr[], int left, int right) 
{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j)
	  {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) 
			{
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
    
}

void printArray(int A[], int size)
{
    int count=0;
    for(int i=0; i<size; i++)
	{
       
		if(i<10 || i>size-11)
		{
			cout<<setw(4)<<A[i]<<" ";
			count++;
				if (count == 10)
				{
					cout<<"||";
				}
		}
	
 	}cout<<endl;
}

void Menu_Choice(int choice)
{
   int count=0;
   int A[size];
   switch (choice)
   {
   		case 1:
   			cout<<"sorted"<<endl;
  			sort_data(A,size);
  			printdata(A,size);
  			
  			cout<<"poor bubble sort"<<endl;
  			sort_data(A,size);
  			BubbleSort(A,size);	
  			
  			cout<<"bubble sort"<<endl;
  			sort_data(A,size);
  		    BubbleSort_Smart(A,size);
  		    
  	     	cout<<"insertion sort"<<endl;
  	     	sort_data(A,size);
  			Insertion_Sort(A,size);
  			
  			cout<<"shell sort"<<endl;
  			sort_data(A,size);
  			shell_Sort(A,size);
  			
  			cout<<"merge sort"<<endl;
  			sort_data(A,size);
  			mergeSort(A, 0, size - 1);
  			printArray( A, size);
  			
  			cout<<"quick sort"<<endl;
  			sort_data(A,size);
  			quickSort( A,0,size-1);
  			printArray( A, size);
  			
  			break;
  		
			
  		case 2:
  			cout<<"unsorted"<<endl;
  			unsort_data(A,size);
  			print_data(A,size);
  			
  			cout<<"poor bubble sort"<<endl;
  			unsort_data(A,size);
  			BubbleSort(A,size);	
  			
  			cout<<"bubble sort"<<endl;
  			unsort_data(A,size);
  		    BubbleSort_Smart(A,size);
  		    
  	     	cout<<"insertion sort"<<endl;
  	     	unsort_data(A,size);
  			Insertion_Sort(A,size);
  			
  			cout<<"shell sort"<<endl;
  			unsort_data(A,size);
  			shell_Sort(A,size);
  			
  			cout<<"merge sort"<<endl;
  			unsort_data(A,size);
  			mergeSort(A, 0, size - 1);
  			printArray( A, size);
  			
  			cout<<"quick sort"<<endl;
  			unsort_data(A,size);
  			quickSort( A,0,size-1);
  			printArray( A, size);
  			
  			break;	
  		case 3:
  			cout<<"Random"<<endl;
  			random(A,size);
  			print_data(A,size);
  			
  			cout<<"poor bubble sort"<<endl;
  			BubbleSort(A,size);
  			
  			cout<<"bubble sort"<<endl;
  			BubbleSort_Smart(A,size);
  			
  			cout<<"insertion sort"<<endl;
  			Insertion_Sort(A,size);
  			
  			cout<<"shell sort"<<endl;
  			shell_Sort(A,size);
  			
  			cout<<"merge sort"<<endl;
  			mergeSort(A, 0, size - 1);
  			printArray( A, size);
  			
  			cout<<"quick sort"<<endl;
  			quickSort( A,0,size-1);
  			printArray( A, size);
  			
  			break;		
  		default:
  			cout << endl << "BAD MENU CHOICE ... retry" << endl<<endl;
    		break;//default
   }//end_switch
} //Menu_Choice

int Menu( )
{
   int Choice;  // Menu choice.
   //-| --------------------------------------------------------------
   //-|  Display the menu.
   //-| --------------------------------------------------------------
   
   cout<<"Option 1: Sorted array"<<endl;
   cout<<"Option 2: Unsorted array"<<endl;
   cout<<"Option 3: Random sorted array"<<endl;
   cout<<"Option 4: Quit";
   cout << endl<<endl;
   //-| --------------------------------------------------------------
   cout << "Enter Menu Choice: ";
   cin >> Choice;
   cout << endl;

   return Choice;
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

