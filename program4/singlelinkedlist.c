#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;// note that it's a pointer to it's own type
}node;

int traverse(node* head){

    node* temp = head;
    int count = 0;
    while(temp != NULL){
        printf("%d\n",temp->data);
        count++;
        temp = temp->next;
    }

    return count;
}

node* findPrevNode(node* head,node* target){

    node* temp = head;
    while(temp != NULL){

        if(temp->next == target){
            return temp;
        }
        temp = temp->next;
    }

    return temp;
}
//this insert wont work for inserting the new node as the first node
//in that case we also take the head node and make a func or a condition for it
void insert_node(node* prevNode, node* newNode,int data){
    
    newNode->next = prevNode->next;
    newNode->data = data;
    prevNode->next = newNode;

}

node* delete_node(node* head,node* target){
    if (target == head)
    {
        node* ptr;
        ptr = head;
        head=head->next;
        free(ptr);
        return head;
    }
    //  vid 18 
    
    findPrevNode(head,target)->next = target->next;
    free(target);

}

node* deleteAtVAlue(node* head,int data){
    node* p = head;
    node* q = head->next;
    while (q->data != data && q->next != NULL)  
    {
        q = q->next;
        p = p->next;
    }
//if the loop was terminated due to null case then we dont have to delete the node, hence an if condition to sort that
    if(q->data == data){
        p->next = q->next;
    free(q);
    }
    return head;

    
}


int main(){
    
    node* head;
    node* second;
    node* third;
    node* fourth;

    head = malloc(sizeof(node));
    second = malloc(sizeof(node));
    third = malloc(sizeof(node));
    fourth = malloc(sizeof(node));
    
    head->data = 7;
    head->next = second;

    second->data = 18;
    second->next = third;

    third->data = 69;
    third->next = fourth;

    fourth->data = 99;
    fourth->next = NULL;

    traverse(head);

    //the below not only prints the return value of the function but also prints the statements from the function
    // printf("%d",traverse(head));

    printf("\n");
    
    node* new = malloc(sizeof(node));
    
    insert_node(second,new,44);
    traverse(head);

    printf("\n");
    
    head = delete_node(head,head);
    traverse(head);

    printf("\n");
    
    deleteAtVAlue(head,69);
    traverse(head);

return 0;
}
