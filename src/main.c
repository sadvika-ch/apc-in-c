#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
	int positive_flag1=0, positive_flag2=0, negative_flag1=0, negative_flag2=0,neg=0;
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
	if(argv[1][0]=='-')
		negative_flag1=1;
	else if(argv[1][0]=='+')	
		positive_flag1=1;
	if(argv[3][0]=='-')
		negative_flag2=1;
	else if(argv[3][0]=='+')	
		positive_flag2=1;	
    switch(oper)
    {
	case '+':  //for addition
		if(negative_flag1 && negative_flag2){
			addition(tail1,tail2,&headR,&tailR);
			neg=1;
			break;
		}
		if(negative_flag1){
			if(compare_list(head1,head2)==OPERAND1){
				subtraction(tail1,tail2,&headR,&tailR);
				neg=1;
			}

			else if(compare_list(head1,head2)==OPERAND2)
				subtraction(tail2,tail1,&headR,&tailR);	
			else
				insert_first(&headR,&tailR,0);
			break;	
		}
		if(negative_flag2){
			if(compare_list(head1,head2)==OPERAND1)
				subtraction(tail1,tail2,&headR,&tailR);
			else if(compare_list(head1,head2)==OPERAND2){
				subtraction(tail2,tail1,&headR,&tailR);
				neg=1;	
			}
			else
				insert_first(&headR,&tailR,0);
			break;	
		}	
		else
			addition(tail1,tail2,&headR,&tailR);	
	    break;

	case '-':   //for subtraction
		int ret=compare_list(head1,head2);
		if(negative_flag1&&negative_flag2){
			if(ret==OPERAND1){
				subtraction(tail1,tail2,&headR,&tailR);
				neg=1;
			}
			else if(ret==OPERAND2)
				subtraction(tail2,tail1,&headR,&tailR);	
			else
				insert_first(&headR,&tailR,0);
			break;
		}
		if(negative_flag1){
			addition(tail1,tail2,&headR,&tailR);
			neg=1;
			break;
		}
		if(negative_flag2){
			addition(tail1,tail2,&headR,&tailR);
			break;
		}	
		else{
			if(ret==OPERAND1)
				subtraction(tail1,tail2,&headR,&tailR);
			else if(ret==OPERAND2){
				subtraction(tail2,tail1,&headR,&tailR);	
				neg=1;
			}
			else	
				insert_first(&headR,&tailR,0);
			break;
		}

	case 'x':  //for multiplication
	case 'X':
		if(negative_flag1&&negative_flag2)
			neg=0;
		else if(negative_flag1 || negative_flag2)
			neg=1;
		multiplication(tail1,tail2,&headR,&tailR);
	    break;

	case '/': 
		 //for division
		if(head2->data==0){
			printf(RED"Runtime error : Divide by zero\n"RESET);
			return 0;
		}
		if(negative_flag1&&negative_flag2)
			neg=0;
		else if(compare_list(head1,head2) !=OPERAND2 && negative_flag1 || compare_list(head1,head2) !=OPERAND2 && negative_flag2)
			neg=1;
		division(head1,head2,tail2,&headR,&tailR);
	    break;

	default:
	    printf(RED"Invalid Operator\n"RESET);
		return 0;
    }

	printf(YELLOW "========================================\n" RESET);
	printf(SKYBLUE "             APC CALCULATOR             \n" RESET);
	printf(YELLOW "========================================\n" RESET);

	// OPERATION line
	printf(PURPLE "OPERATION : " RESET WHITE "%s %s %s\n" RESET, argv[1], argv[2], argv[3]);

	// RESULT label
	printf(PURPLE "RESULT : " RESET);

	// minus sign in PINK
	if(neg)
		printf(PINK "-" RESET);

	// actual result number in PINK
	printf(WHITE);
	print_list(headR);
	printf(RESET);

}
