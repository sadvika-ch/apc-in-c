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
	case '+':
		addition(tail1,tail2,&headR,&tailR);
	    break;

	case '-':
	    break;

	case 'x':
	case 'X':
	    break;

	case '/':
	    break;

	default:
	    printf("Invalid operator\n");
    }
	print_list(head1);
	print_list(head2);
	print_list(headR);
}

