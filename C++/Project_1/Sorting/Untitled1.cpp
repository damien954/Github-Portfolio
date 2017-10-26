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

int MAX=10;
int queue_array[10];
int rear = - 1;
int front = - 1;
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
    
} /*End of display() */
void insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
    display();
} /*End of insert()*/

 
int main()
{
	
   //----------------------------------------------------------------------
   // Declare variables for program.
   //----------------------------------------------------------------------
   
insert();
system("PAUSE");
   return 0;
   
}//main

