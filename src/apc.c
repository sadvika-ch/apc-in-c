#include "apc.h"

void remove_pre_zeros(node **head){
    while((*head)->data==0){
        node * temp=*head;
        *head=(*head)->next;
        (*head)->prev=NULL;
        free(temp);
    }
}
int cla_validation(int argc, char *argv[]){
    if(argc!=4){
        printf("Invalid number of CLAs\n");
        return FAILURE;
    }
    int i=0;
    while(argv[1][i]){
        if(argv[1][i]<'0' || argv[1][i]>'9'){
            printf("Invalid operand 1\n");
            return FAILURE;
        }
        i++;
    }
    i=0;
    while(argv[3][i]){
        if(argv[3][i]<'0' || argv[3][i]>'9'){
            printf("Invalid operand 3\n");
            return FAILURE;
        }
        i++;
    }
    return SUCCESS;
    
}
void create_list(char *opr, node **head, node **tail){
    int i=0;
    while(opr[i]){
        insert_last(head,tail,opr[i]-48);
        i++;
    }
}
// Function definitions
int insert_first(node **head, node **tail, int data)
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
    new->next=*head;
    (*head)->prev=new;
    *head=new;
    return SUCCESS;
}

int insert_last(node **head, node **tail, int data)
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

int delete_list(node **head, node **tail)
{
    if(*head==NULL)
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


void print_list(node *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
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