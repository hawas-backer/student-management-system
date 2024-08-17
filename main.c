#include <stdio.h>
#include <stdlib.h>
#include "student.h"
FILE *f2;
void displaymenu()
{
    printf("1.ADD STUDENTS\n");
    printf("2.VIEW STUDENTS\n");
    printf("3.UPDATE STUDENTS\n");
    printf("4.DELETE STUDENTS\n");
    printf("5.DISPLAY STUDENT\n");
    printf("6.EXIT STUDENTS\n");
}
int main()
{
     
     
   
    int choice;
    while(1)
    {
     printf("\n")  ;
     displaymenu(); 
     printf("Enter your choice:");
     scanf("%d",&choice);
     if(choice==6)
        break;
    switch(choice)
    {
        case 1: f2=fopen("data.bin","ab+");
               add();
               fclose(f2);
               break;
        case 2:f2=fopen("data.bin","ab+");
              view();
              fclose(f2);
              break;
        case 3:f2=fopen("data.bin","ab+");
               update();
               fclose(f2);
               break;
        case 4:f2=fopen("data.bin","ab+");
               delete();
               fclose(f2);
              break;
        case 5:f2=fopen("data.bin","ab+");
               display();
               fclose(f2);
              break;
        default:printf("NOT A VALID CHOICE");
                break;
    }
    }
    return 1;
}
