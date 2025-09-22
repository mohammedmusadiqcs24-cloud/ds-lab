#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void Push(int);
void Pop();
void Display();

int stack[SIZE],top=-1;

void main(){
    int value,choice;
while(1){
        printf("\nMENU : \n");
    printf("1.Push \n2.Pop \n3.Display \n4.exit(0)\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);


    switch(choice){
        case 1:printf("\n Enter the value to be inserted : ");
        scanf("%d",&value);
        Push(value);
        break;
        case 2:Pop();
        break;
        case 3:Display();
        break;
        case 4:exit(0);
        default: printf("Enter a valid option !!");
    }
    }
}
void Push(int value){
    if(top==SIZE-1){
        printf("\n Stack is overloaded !!");
    }
    else{
        top++;
        stack[top]=value;
        printf("\n Insersion Done !!");
    }
}

void Pop(){
    if(top==-1){
        printf("The stack is underloaded !!");
    }
    else{
        printf("The item which is deleted is %d ",stack[top]);
        top--;
        printf("Deletion done");
    }
}
void Display(){
    if(top==-1){
        printf("Stalk is empty !!");}
    else{
        int i;
        for (i=top;i>=0;i--){
            printf("%d\t ",stack[i]);}

        }

}

