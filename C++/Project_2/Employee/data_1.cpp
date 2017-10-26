#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define M 10
#define FLUSH while(getchar() != '\n')

typedef struct
{
        int StudentID[10];
        char Fname[50];
        char Lname[30];
        char midIn[2];
        char Course[20];
        float QPA [3];
        char address[50];
}Student;

void menu(char *);
void addRec(Student stud[], int cnt);
void editIn(Student stud[], int cnt);
void deleteStudRec(Student stud[], int cnt);
void viewIn(Student stud[], int cnt);
void viewAll(Student stud[], int cnt);
void exit1(char *answer);

int main(void)
{
    Student stud[M];
    char choice;
    int cnt=0;
    char answer= 'n';
    do
    {
        menu(&choice);
        switch(choice)
        {
                   case '1':
                              system("cls");
			      if (cnt < M)
			      {
                              	addRec(stud, cnt);
                              	cnt++;
			      }
			      else
				printf("\nNO MORE SPACE FOR NEW STUDENT RECORD");
                              break;
                   case 'a':
		   case 'A':
                              system("cls");
                              editIn(stud, cnt);
                              break;
                   case '2':
                              system("cls");
                              editIn(stud, cnt);
                              break;
                   case '3':         
                              system("cls");
                              viewIn(stud, cnt);
                              break;
                   case '4':
                              system("cls");
                              viewAll(stud, cnt);
                              break;
                   case '5':
                             exit1(&answer);
                             if(answer=='Y' || answer=='y')
                                ;
                             break;
                   default:
                             ;
        }
    } while(answer == 'N' || answer == 'n');
    printf("\nThank you.");
    getch();
    return 0;
}

void menu(char *choice)
{
     char ch;
     system("cls");
     printf("\n\n\nStudent Records");
     printf("\n\n1. Add student personal info and scores");
     printf("\n\t a. Edit student first name");
     printf("\n2. View student record (by last name)");
     printf("\n3. View all student records");
     printf("\n4. Exit");
     printf("\n\nChoice: ");
     scanf("%c", &ch);
     *choice=ch;
}

void addRec(Student stud[], int count)
{
     printf("ADD STUDENT PERSONAL INFORMATION");
FLUSH;
     printf("\n\nLast name: ");
     gets(stud[count].Lname);
     //FLUSH;
     printf("First name: ");
     gets(stud[count].Fname);
     printf("Middle Initial: ");
     gets(stud[count].midIn);
     printf("Address: ");
     gets(stud[count].address);

     getch();
}

void editIn(Student stud[], int count)
{
     int i, res;
     char ln[20], fn[40];
     FLUSH;
     printf("EDIT STUDENT PERSONAL INFORMATION");
     if(count == 0)
     {
              printf("\n\nNO RECORDS AVAILABLE");
              getch();
     }
     else
     {
         printf("\n\nLast Name: ");
         gets(ln);
         for(i=0; i<count; i++)
         {
              res= strcmp(ln, stud[i].Lname);
              if(res==0)
              {
                      FLUSH;
                      printf("%s, %s %s\n\n", stud[i].Lname, stud[i].Fname, stud[i].midIn);
		      printf("\n\nFirst name: ");
                      gets(fn);
                      strcpy(stud[i].Fname, fn);
                      printf("\n\nSuccessful. Firstname has been changed to %s", stud[i].Fname);
                      getch();
                      break;
              }
         }
         if(res!=0)
         {
             printf("\nRECORD NOT FOUND.");
             getch();
         }
     }
}
void viewIn(Student stud[], int count)
{
     int i, res;
     char ln[20];
     FLUSH;
     printf("VIEW STUDENT RECORD");
     if(count == 0)
              printf("\n\nNO RECORDS AVAILABLE");
     else
     {
         printf("\n\nLast Name: ");
         gets(ln);
	 //FLUSH;
         for(i=0; i<count; i++)
         {
              res= strcmp(ln, stud[i].Lname);
              if(res==0)
              {
                        printf("\n %s, %s %s", stud[i].Lname, stud[i].Fname, stud[i].midIn);
                        printf("\n\nLastname: %s", stud[i].Lname);
			printf("\nFirstname: %s", stud[i].Fname);
			printf("\nMiddle Initial: %s", stud[i].midIn);
			printf("\nAddress: %s", stud[i].address);
                        //FLUSH;

              }
         }
	if (res != 0)
		printf("\nRECORD NOT FOUND.");
     }
     getch();
}

void viewAll(Student stud[], int count)
{
     int i;
     printf("VIEW ALL STUDENT RECORDS");
     if(count == 0)
              printf("\n\nNO RECORDS AVAILABLE");
     else
     {
         for(i=0; i<count; i++)
         {
                   printf("\n %s, %s %s \t%s", stud[i].Lname, stud[i].Fname, stud[i].midIn, stud[i].address);


         }
     }
     getch();
}

void exit1(char *answer)
{
     char a;
     FLUSH;
     printf("\n\nExit? [Y/N]: ");
     scanf("%c", &a);
     *answer=a;
}
