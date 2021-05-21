#include<stdio.h>
#include<stdlib.h>
int size=0;

typedef struct node{
    int data;
    struct node* next;
}node;

int counting(node *head)
{
    int count = 0;
    node *temp = head;
    while(temp!= NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

node* del_begin(node* head){    // Can return anything
node* temp = head->next;
return temp;
}

node* del_last(node *head){
    node* temp = head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    temp->next = NULL;// to Break the link
    return head;
}

node* InsertBegin(node *head , int data)
{
    node *new_node = (node*)calloc(1,sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head =new_node;
    size +=1;
    return head;
}

node* InsertEnd(node *head , int data)// star star head use..??
{
    printf("Inserted at the end \n");
    node* new_node= (node*)calloc(1, sizeof(node));
    new_node->data=data;
    new_node->next=NULL;

    if(head ==NULL){
        head = new_node;
         new_node-> next = NULL;
         size+=1;

    }

    else{
        node* last = (head);
        while(last -> next!=NULL){
            last=last->next;
        }
        last->next = new_node;
        size+=1;
    }
    return head;
}

void printList(node * head)
{
    printf("\n");
    printf("List : ");
    node *temp= head ;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp-> next;
    }
    printf("\n");
}

node* InsertAfter(node* head, int data , int x){
    node* new_node= (node*) (calloc(1,sizeof(node)));// new node , spo memory allocation
    new_node-> data= data;
    node* temp= head;
    while(temp -> data!=x){// temp is node storuing x
        temp= temp -> next;
    }
    new_node -> next = temp -> next;
    temp-> next =new_node;
    size+=1;
    return;
}

node* del_mid(node* head , int mid)
{
    int count=0;
    node *temp = head;   // temp created to travese in function...
    while(count!= mid-2)
    {
        count++;
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = temp2->next;

    return head;
}

void print_even(node** head){
    node* temp= *head;
int count=1;
printf("\n");
printf("Printing even position number ");
    while(temp!=NULL){
        if (count%2==0){
            printf("%d ", temp->data);}
            count++;
            temp=temp->next;
    }
}

void sumOfOdd(node* head, int *n ){// could have taken without int rather USING POINTER ON SUM....
    *n =0;                                                        //check as going forward to infinte... WHENEVER TWO -> -> as loop
 node* temp = head;
while(temp!=NULL){
    *n=*n+(temp->data);

    if(temp->next==NULL){

        temp= temp->next;
        }

    else if(temp->next->next!=NULL && temp->next!=NULL ){
    temp = temp->next->next;
        }
    }
}


node* rev(node *head, int count){

node* temp = head;

while(temp->next!=NULL){
    temp = temp-> next;
}
node *temp2 =head;


while(count-2){
InsertAfter(head,temp2->data,temp->data );
head =del_begin(head);

temp2 =head;

InsertAfter(head,temp2->data,temp->data );
head =del_begin(head);
count --;

}
return head;

}
void deleteAlternateNodes(node *head) {
   if (head == NULL)
      return;
   node *prev = head;
   node *node = head->next;
   while (prev != NULL && node != NULL) {
      prev->next = node->next;
      free(node);
      prev = prev->next;
      if (prev != NULL) {
         node = prev->next;
      }
   }
}
int main(){
    node *head=NULL;  // pointer head...
    int m;
    printf("Enter the data for beginging: ");
    scanf("%d", &m);



    head = InsertBegin(head , m);
    printf("Inserting first into the linklist we get \n",m);
    printList(head);




    printf("Enter the data for beginging\n");
    scanf("%d", &m);




    head = InsertBegin(head , m);
    printf("Inserting first into the linklist we get \n",m);
    printList(head);





    printf("Enter data to be stored at the end\n");
    scanf("%d", &m);
    head = InsertEnd(head ,m );
    printf("After inserting the last element \n");
    printList(head);
    int x=0;
    int y=0;
    printf("write the no. after which the data should be printed");
    scanf("%d", &x);
    printf("\nInsert the value to be entered\n");
    scanf("%d", &y);

    InsertAfter(head, y, x);
    printList(head);


    printf("Enter the data for beginging\n");
    scanf("%d", &m);



    head = InsertBegin(head , m);
    printf("Inserting first into the linklist we get \n",m);
    printList(head);



    int count = counting(head);
    int mid;
    printf("%d", count);
    (count%2 ==0)?(mid = count/2):(mid=(count+1)/2); //New way of terneatory operator

    head = del_mid(head, mid);

    printf("\n After deleting the middle element we get ");
    printList(head);

    printf("After deleting the last");
    head = del_last(head);
    printList(head);

    print_even(&head);
    printf("\nThe sum of odd digits number is -> ");
    int n = 0;
    sumOfOdd(head, &n);     // TRY must passing using pointer...
    printf("%d\n", n);
    count = counting(head);
    head=rev(head, count);
    printList(head);


    printf("Enter the data for beginging\n");
    scanf("%d", &m);



    head = InsertBegin(head , m);
    printf("Inserting first into the linklist we get \n",m);
    printList(head);



    printf("Enter the data for beginging\n");
    scanf("%d", &m);



    head = InsertBegin(head , m);
    printf("Inserting first into the linklist we get \n",m);
    printList(head);

        deleteAlternateNodes(head);
        printList(head);
return 0;}
