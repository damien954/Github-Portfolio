//Alexis R. Caldwell
//COP3530 Project 1
//Randomly sorted array

#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;


bool wayToSort(int i, int j) { return i > j; }


void poorbubbleSort(int arr[], int size, int compareCounter, int exchangeCounter)
{
 int swap;
 for(int counter =  size - 1; counter >= 0; counter--)
  {
   for(int i = 0; i < size; i++)
    {
      if(arr[i] > arr[i+1])
       {
       swap = arr[i+1];
       arr[i+1] = arr[i];
       arr[i] = swap;
       compareCounter += 1;
       exchangeCounter += 1;
       }// end if statement
    }// end for
  }// end for loop
cout << "\nNumber of comparisons: " << compareCounter;
cout << "\nNumber of exchanges: " << exchangeCounter;
}// end poor bubble sort
//bool wayToSort(int i, int j) { return i > j; }



void smartbubbleSort(int arr[], int n, int compareCounter, int exchangeCounter) 
{
      bool swapped = true;
      int j = 0;
      int tmp;
      while (swapped) 
      {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) 
            {
                  if (arr[i] > arr[i + 1]) 
                  {
                        tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        swapped = true;
                        compareCounter += 1;
                        exchangeCounter += 1;
                  }// end if statement
            }// end for loop
      }// end while loop
cout << "\nNumber of comparisons: " << compareCounter;
cout << "\nNumber of exchanges: " << exchangeCounter;
}// end smart bubble sort



void insertionsort(int arr[], int length, int compareCounter, int exchangeCounter)
{
 int j, temp; 
 for (int i = 0; i < length; i++)
         {
  j = i;
  compareCounter++;
  while (j > 0 && arr[j] < arr[j-1])
                  { 
            temp = arr[j];
            arr[j] = arr[j-1];
     arr[j-1] = temp;
     j--;
                   exchangeCounter += 1;
            }// end while loop
  }//for loop
cout << "\nNumber of comparisons: " << compareCounter;
cout << "\nNumber of exchanges: " << exchangeCounter;
}// end insertion sort



void shellsort(int arr[], int n, int compareCounter, int exchangeCounter)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2)
     {
        for (i = gap; i < n; i++)
         {
            for (j=i-gap; j>=0 && arr[j]>arr[j+gap]; j-=gap) 
            {
                temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;
                exchangeCounter += 1;
            }// end for loop
         }// end for loop
     }//end for loop
     cout << "# of exchanges" << exchangeCounter<<endl;
     cout << "# of compares" << temp << endl;
}//end shell sort




//void merge(int *,int, int , int, int & , int &);
void merge(int *a, int low, int high, int mid, int compareCounter, int exchangeCounter)
{
    int i, j, k, c[100000];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        compareCounter += 1;
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
            exchangeCounter += 1;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
            exchangeCounter += 1;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
        exchangeCounter += 1;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
        exchangeCounter += 1;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
        exchangeCounter += 1;
    }
    cout << "exchanges " << exchangeCounter<< endl;
    cout << "compares " << compareCounter<< endl;
}// end merge



void Mergesort(int *arr, int low, int high, int compareCounter, int exchangeCounter)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        Mergesort(arr,low,mid, compareCounter, exchangeCounter);
        Mergesort(arr,mid+1,high, compareCounter, exchangeCounter);
        merge(arr,low,high,mid,compareCounter, exchangeCounter);
    }
    return;
}// end mergesort




void mergesort(int *arr, int low, int high, int compareCounter, int exchangeCounter)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        Mergesort(arr,low,mid, compareCounter, exchangeCounter);
        Mergesort(arr,mid+1,high, compareCounter, exchangeCounter);
        merge(arr,low,high,mid,compareCounter, exchangeCounter);
    }
cout << "\nNumber of comparisons: " << compareCounter;
cout << "\nNumber of exchanges: " << exchangeCounter;
    return;
}// end mergesort



void Quicksort(int arr[], int left, int right, int compareCounter, int exchangeCounter) 
{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            compareCounter += 1;
            exchangeCounter += 1;
            }
      }
      if (left < j)
          { Quicksort(arr, left, j, compareCounter, exchangeCounter);
            compareCounter += 1;}
      if (i < right)
         {  Quicksort(arr, i, right, compareCounter, exchangeCounter);
            compareCounter += 1;}
}// end Quicksort



void quicksort(int arr[], int left, int right, int compareCounter, int exchangeCounter) 
{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            compareCounter += 1;
            exchangeCounter += 1;
            }
      }
      if (left < j)
          { Quicksort(arr, left, j, compareCounter, exchangeCounter);
            compareCounter += 1;}
      if (i < right)
         {  Quicksort(arr, i, right, compareCounter, exchangeCounter);
            compareCounter += 1;}
cout << "\nNumber of comparisons: " << compareCounter;
cout << "\nNumber of exchanges: " << exchangeCounter;
}//end quicksort


void shuffle(int *arr, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        srand(time(NULL));
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = arr[j];
          arr[j] = arr[i];
          arr[i] = t;
        }
    }
}


int main()
{
    int i;
    int sorted[10000];
    for (i=0; i<10000; i++){
        sorted[i] = i;
    }
shuffle(sorted, 10000);
//uncomment the sorting method you want to use to sort the array

//poorbubbleSort(sorted, 10000,0,0);
//smartbubbleSort(sorted,10000,0,0);
//insertionsort(sorted,10000,0,0);
//shellsort(sorted,10000,0,0);
//merge(sorted,0,10000,4999,0,0);
//mergesort(sorted,0,10000,0,0);
//quicksort(sorted,0,9999,0,0);

}
