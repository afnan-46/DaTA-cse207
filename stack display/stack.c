#include<stdio.h>
#define max 7
int stack[max];
int top=0;

void pop()
{
if(top == 0)
{
printf("\n\nStack Underflow..");
return;
}
else
printf("\n\n popped element is: %d ", stack[--top]);

}

void push()
{
int data;
if(top == max)
{
printf("\n\nStack Overflow..");
return;
}
else
{
printf("\n\nEnter data: ");
scanf("%d", &data);
stack[top] = data;
top = top + 1;
printf("\n\nData Pushed into the stack");
}
}

void display(){
if(top == 0){
    printf("The stack is empty:\n ");
    return;
}
else{

    for(int i= top-1;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}

}

int main(){

int choice;
 while(1){
    printf("Enter 1 for push\n");
    printf("Enter 2 for pop\n");
    printf("Enter 3 for exit\n");
    printf("Enter 4 for Display\n");

    scanf("%d",&choice);


    switch(choice){
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        printf("Terminating the programme ...");
       break;
    case 4:
        display();
    default:
        printf("invalid Input...");
        break;


    }

 }



return 0;
}




