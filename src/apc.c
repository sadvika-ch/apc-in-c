#include "apc.h"
//all additional function definitions
//comparing 2 lists 
int compare_list(node *head1, node *head2){  //comparing 2 numbers which is greater
    int len1=list_len(head1);
    int len2=list_len(head2);
    if(len1>len2)    //if len1 is greater then we can say that 1st num is greater
        return OPERAND1;
    else if(len1<len2)  //else if len2 is greater then we can say num2 is greater 
        return OPERAND2;
    else{          //else we are checking for digit by digit and which is higher we are returning that macro
        while(head1 || head2){
            if(head1->data > head2->data)
                return OPERAND1;
            else if(head1->data < head2->data)
                return OPERAND2;
            head1=head1->next;
            head2=head2->next;    
        }
        return SAME;  //else we can say both are equal so returning same macro
    }  
}  
        
//finding length of the list
int list_len(node *head){  // to find the length of the number
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}

//to remove all pre zeros
void remove_pre_zeros(node **head){  //to remove the zeros which are before number
                                        
    while((*head)->data==0){
         if((*head)->next==NULL)  //if only single 0 or multiple 0 and no other dgit we are returning because if we remove-
            return;                  //that  zero or zeros also we will get segmentation fault
         //if we found 0 at start removing and updating head
        *head=(*head)->next;
        free((*head)->prev);
        (*head)->prev=NULL;
        
    }
}

//command line arguments validation
int cla_validation(int argc, char *argv[]){  //validation function
    if(argc!=4){                             //arguments should be 4 . a.out,2 operands and 1 operator
        printf(RED"Invalid number of CLAs\n"RESET);
        return FAILURE;
    }
    int i=0;
    if(argv[1][i]=='-' || argv[1][i] == '+')
        i++;
    while(argv[1][i]){           //2nd argument should be all digits
        if(argv[1][i]<'0' || argv[1][i]>'9'){
            printf(RED"Invalid Operand 1\n"RESET);
            return FAILURE;
        }
        i++;
    }
    i=0;
    if(argv[3][i]=='-' || argv[3][i] == '+')
        i++;
    while(argv[3][i]){           //and 4th argument should be all digits
        if(argv[3][i]<'0' || argv[3][i]>'9'){
            printf(RED"Invalid Operand 3\n"RESET);
            return FAILURE;
        }
        i++;
    }
    return SUCCESS;
    
}

//creating lists
void create_list(char *opr, node **head, node **tail){  //to create list with the numbers
    int i=0;
    if(opr[i]=='-' || opr[i] == '+')
        i++;
    while(opr[i]){
        insert_last(head,tail,opr[i]-48); // converting to digits because we are scanning through CLA(as strings)
        i++;
    }
}

int insert_first(node **head, node **tail, int data)  //function to insert 1 st in the list
{
    node *new=malloc(sizeof(node));
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    if(*head ==NULL){   //if list is empty
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    new->next=*head;
    (*head)->prev=new;
    *head=new;
    return SUCCESS;
}

int insert_last(node **head, node **tail, int data)  //to insert at last in the list
{
    node *new=malloc(sizeof(node));
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    if(*head ==NULL){
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    new->prev=*tail;
    (*tail)->next=new;
    *tail=new;
    return SUCCESS;
}

int delete_list(node **head, node **tail)  //to delete the list
{
    if(*head==NULL)      // if list is empty
        return FAILURE;
    while(*head){
        *tail=(*head)->next;
        free(*head);
        *head=*tail;
    }
    *head=NULL;
    *tail=NULL;
    return SUCCESS;
}


void print_list(node *head)   //to print the list
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf(RED"INFO : List is empty\n"RESET);
	}
	else
	{
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
    	printf("\n");
    }
}