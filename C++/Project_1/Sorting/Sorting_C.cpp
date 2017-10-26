// ------------------------------------------------------------------
// File name:   Sorting_C.cpp
// Assign :     Sorting program  step #3 
// 
// Author:      Damien Cunningham
//
// ------------------------------------------------------------------


#include <iostream>
#include <stdlib.h>  
#include <cmath>
#include <iomanip>      // std::setw
using namespace std;

 int size=100;
 int swaps=0;

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
int swapin(int &swaps)
{
	 swaps=0;
	return swaps;
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

	int count=0;
  	for(int i=size; i>=0; i--)
  	{
  		array[i]=i;
  
	}cout<<endl;
}
int unsort_data( int array[], int size)
{
  	for(int i=0; i<size; i++)
  	{
  		array[i]=size-(i+1);
  		
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
int random_reset(int array[],int temp[], int size)
{
 for(int i=0; i<size; i++ )
 {
 	temp[i]=array[i];
 }
 
}


int BubbleSort( int array[], int size, int &swaps)
{
	int hold;
	for(int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-1; j++)
		{
		
		if(array[j]>array[j+1])
		{
			hold=array[j];
			array[j]=array[j+1];
			array[j+1]=hold; 
			swaps++;
		}
		
		} 
	}
	
}

int BubbleSort_Smart( int array[], int size, int &swaps)
{
	int hold,flag=1;
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
			swaps++;
		}
		
		} 
	} 

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
}int Insertion_Sort(int array[], int size, int &swaps)
{
	int j, temp;
		
	for (int i = 0; i < size; i++)
	{
		j = i;
		
		while ( j > 0 && array[j] < array[j-1] )
		{
			  temp = array[j];
			  array[j] = array[j-1];
			  array[j-1] = temp;
			  j--;
			  swaps++;
		}
	}
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
void shell_Sort (int array[], int size,int &swaps)
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
        array[j] = array[j - gap];swaps++;
      }
      array[j] = temp;
      
    } 
  }
  
  	
}

void merge(int arr[], int l, int m, int r, int &swaps)
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
            swaps++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            swaps++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        swaps++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        swaps++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r, swaps);
    }
  
    
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

void quickSort(int arr[], int left, int right, int &swaps) 
{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j)
	  {
            while (arr[i] < pivot)
                  i++;
                  swaps++;
            while (arr[j] > pivot)
                  j--;
                  swaps++;
            if (i <= j) 
			{
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
                  swaps++;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j,swaps);
      if (i < right)
            quickSort(arr, i, right,swaps);
    
}


void Menu_Choice(int choice)
{
   int count=0;
   int swap=0;
   int A[size],B[size],C[size],D[size];
   switch (choice)
   {
   		case 1:
   			
  			sort_data(A,size);
  			cout<<"sorted"<<endl;
  			printdata(A,size);
  			cout<<"unsorted"<<endl;
  			unsort_data(B,size);
  			printdata(B,size);
  			random(C,size);
  			random_reset(C,D,size);
  			print_data(C,size);
  			swapin(swap);
  		
  			//header
  			cout<<setw(20)<<"table"<<endl;
  			cout<<setw(20)<<"sort types"<<setw(20)<<"sorted"<<setw(20)<<"unsorted"
			    <<setw(20)<<"random"<<endl<<endl;
			//bubble sort(poor)
  			cout<<setw(20)<<"bubble sort(poor): ";
  			BubbleSort( A,size, swap);
			cout<<setw(20)<<swap;swapin(swap);
			BubbleSort( B,size, swap);
  			cout<<setw(20)<<swap;swapin(swap);
  			BubbleSort( C,size, swap);
			cout<<setw(20)<<swap<<endl;swapin(swap);
			
			/////
			sort_data(A,size);
  			unsort_data(B,size);
  			random_reset(D,C,size);
			/////  
			
			//bubble sort
			cout<<setw(20)<<"bubble sort: ";
  			BubbleSort_Smart( A,size, swap);
			cout<<setw(20)<<swap;swapin(swap);
			BubbleSort_Smart( B,size, swap);
  			cout<<setw(20)<<swap;swapin(swap);
  			BubbleSort_Smart( C,size, swap);
			cout<<setw(20)<<swap<<endl;swapin(swap);
  		
  			/////
			sort_data(A,size);
  			unsort_data(B,size);
  			random_reset(D,C,size);
			/////  
			
			//insertion
			cout<<setw(20)<<"insertion: ";
  			Insertion_Sort(A,size,swap);
			cout<<setw(20)<<swap;swapin(swap);
			Insertion_Sort(B,size,swap);
  			cout<<setw(20)<<swap;swapin(swap);
  			Insertion_Sort(C,size,swap);
			cout<<setw(20)<<swap<<endl;swapin(swap);
			
			/////
			sort_data(A,size);
  			unsort_data(B,size);
  			random_reset(D,C,size);
			/////  
			
			//shell
			cout<<setw(20)<<"shell sort: ";
  			shell_Sort (A, size,swap);
			cout<<setw(20)<<swap;swapin(swap);
			shell_Sort (B, size,swap);
  			cout<<setw(20)<<swap;swapin(swap);
  			shell_Sort (C, size,swap);
			cout<<setw(20)<<swap<<endl;swapin(swap);
			
			/////
			sort_data(A,size);
  			unsort_data(B,size);
  			random_reset(D,C,size);
  			swapin(swaps);
			/////  
			
			//merge
			cout<<setw(20)<<"merge sort: ";
  			mergeSort(A, 0, size - 1);
			cout<<setw(20)<<swaps;swapin(swaps);
			mergeSort(B, 0, size - 1);
  			cout<<setw(20)<<swaps;swapin(swaps);
  			mergeSort(C, 0, size - 1);
			cout<<setw(20)<<swaps<<endl;swapin(swaps);swapin(swap);
			
			/////
			sort_data(A,size);
  			unsort_data(B,size);
  			random_reset(D,C,size);
			/////  
			
			//quick
			cout<<setw(20)<<"quick sort: ";
  			quickSort( A,0,size-1,swap);
			cout<<setw(20)<<swap;swapin(swap);
			quickSort( B,0,size-1,swap);
  			cout<<setw(20)<<swap;swapin(swap);
  			quickSort( C,0,size-1,swap);
			cout<<setw(20)<<swap<<endl;swapin(swap);
			
  			cout<<endl<<endl;
  			
  			break;
  		case 2:	
  			break;	
  		case 3:
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
   
   cout<<"Option 1: Test"<<endl;
   cout<<"Option 2: Quit";
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
   while (choice != 2);
   
   return 0;
   
}//main

