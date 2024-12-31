#include<stdio.h>
#define MAX 5
int Queue[MAX];
int front=-1;
int rear=-1;

void insertQ()
{
int data;
if(rear == MAX)
{
printf("\n Linear Queue is full");
return;
}
else
{
printf("\n Enter data: ");
scanf("%d", &data);
Queue[rear] = data;
rear++;
printf("\n Data Inserted in the Queue ");
}
}

void deleteQ()
{
if(rear == front)
{
printf("\n\n Queue is Empty..");
return;
}
else
{
printf("\n Deleted element from Queue is %d",Queue[front]);
front++;
}
}
void displayQ()
{
int i;
if(front == rear)
{
printf("\n\n\t Queue is Empty");



return;
}
else
{
printf("\n Elements in Queue are:\n ");
for(i = front; i < rear; i++)
{
printf("%d\t", Queue[i]);
}
}
}
int main(){
int choice;
 while(1){
    printf("Enter 1 for INSERT\n");
    printf("Enter 2 for DELETE\n");
    printf("Enter 3 for exit\n");
    printf("Enter 4 for DISPLAY\n");

    scanf("%d",&choice);


    switch(choice){
    case 1:
        insertQ();
        break;
    case 2:
        deleteQ();
        break;
    case 3:
        printf("Terminating the programme ...");
       break;
    case 4:
         displayQ();
    default:
        printf("/n invalid Input...");
        break;


    }

 }


return 0;
}


