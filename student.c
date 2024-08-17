#include <stdio.h>
#include <stdlib.h>
#include "student.h"

FILE *f2;

void display()
{    int id,found=0;
     struct students student;
     printf("Enter the student id:");
     scanf("%d",&id);
    rewind(f2);
    //printf("ID\tNAME\tDEPARTMENT\n\n");
    while(fread(&student,sizeof(student),1,f2))
    {
        if(student.flag==1)
        {
            continue;
        }
       if(student.id==id)
       {
         printf("student id:%d\t",student.id);
         printf("student name:%s\t",student.name);
         printf("student department%s\n",student.department);
         found=1;
          break;
       }
    }
    if(found!=1)
    {
        printf("There is no student with id %d",id);
    }

}

void add(){
    int found=0;
    struct students student,student1;
    
    printf("ENTER THE ID:");
    scanf("%d",&student.id);
    printf("ENTER THE NAME:");
    scanf("%s",student.name);
    printf("ENTER THE DEPARTMENT:");
    scanf("%s",student.department);
    student.flag=0;
    rewind(f2);
    while(fread(&student1,sizeof(student1),1,f2))
    {
       if(student1.flag==1)
       {
        found=1;
        break;
       } 
       
    }
    if(found==1)
    {
       fseek(f2,-sizeof(student),SEEK_CUR);
       fwrite(&student,sizeof(student),1,f2);
       return;
    }
    //rewind(f1);
    fwrite(&student,sizeof(student),1,f2);
}
void view()
{   
    struct students student;
    rewind(f2);
    printf("ID\tNAME\tDEPARTMENT\n\n");
    while(fread(&student,sizeof(student),1,f2))
    {
        if(student.flag==1)
        {
            continue;
        }
        printf("%d\t",student.id);
        printf("%s\t",student.name);
        printf("%s\n",student.department);
    }
}
void update(){
    struct students student;
   int id,choice,found=0;
   printf("Enter the student id:");
   scanf("%d",&id);
   rewind(f2);
   while(fread(&student,sizeof(student),1,f2))
    {
        
        if(id==student.id && student.flag!=1)
        {
            found=1;
            break; 
        }
        
    }
    if(found!=1)
    {
        printf("There is no student with id %d",id);
        return;
    }
    printf("\nENTER THE VALUE NEEDED TO BE UPDATED\n1.ID,2.NAME,3.DEPARTMENT:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the new id:");
               scanf("%d",&student.id);
               break;
        case 2:printf("Enter the new name:");
               scanf("%s",student.name);
               break;
        case 3:printf("Enter the new department:");
               scanf("%s",student.department);
                break;
        default:
               printf("invalid choice.");
              break;
    }
    
    fseek(f2,-sizeof(student),SEEK_CUR);
    fwrite(&student,sizeof(student),1,f2);
    printf("Record update succesfully.");

}
void delete(){
    struct students student;
    int id,found=0;
    printf("Enter the id of student to delete:");
    scanf("%d",&id);
    while(fread(&student,sizeof(student),1,f2))
    {
        
        if(id==student.id && student.flag!=1)
        {
            found=1;
            break; 
        }
        
    }
    if(found!=1)
    {
        printf("There is no student with id %d",id);
        return;
    }
    student.flag=1;
     fseek(f2,-sizeof(student),SEEK_CUR);
    fwrite(&student,sizeof(student),1,f2);
    printf("Record delete succesfully.");


}
