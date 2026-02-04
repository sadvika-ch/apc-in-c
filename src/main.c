#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

    // Validation
	if(cla_validation(argc,argv)==FAILURE)
		return 0;
    // Create 2 lists of operands
	create_list(argv[1],&head1,&tail1);
	create_list(argv[3],&head2,&tail2);
    // Remove pre zeros
	remove_pre_zeros(&head1);
	remove_pre_zeros(&head2);
    char oper = argv[2][0];

    switch(oper)
    {
	case '+':  //for addition
		addition(tail1,tail2,&headR,&tailR);
	    break;

	case '-':   //for subtraction
		int ret=compare_list(head1,head2);
		if(ret==OPERAND1)
			subtraction(tail1,tail2,&headR,&tailR);
		else if(ret==OPERAND2){
			subtraction(tail2,tail1,&headR,&tailR);	
			printf("-");
		}
		else	
			insert_first(&headR,&tailR,0);
	    break;

	case 'x':  //for multiplication
	case 'X':
		multiplication(tail1,tail2,&headR,&tailR);
	    break;

	case '/':  //for division
		if(head2->data==0){
			printf("Runtime error : Divide by zero\n");
			return 0;
		}
		division(head1,head2,tail2,&headR,&tailR);
	    break;

	default:
	    printf("Invalid operator\n");
    }
	//printing the result 
	printf("RESULT AFTER OPERATION : ");
	print_list(headR);
}

