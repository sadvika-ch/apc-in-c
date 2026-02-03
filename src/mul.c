#include "apc.h"
void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node * headR2=NULL, *tailR2=NULL, *head_AR=NULL,*tail_AR=NULL;  //taking extra links for adding 2
    int carry=0,count=0;
    node * temp1=tail1,*temp2=tail2;
    while(temp2){        //while loop for 2nd digit
        carry=0;
        for(int i=0;i<count;i++)
            insert_first(&headR2,&tailR2,0);   //adding zeros according to placevalues
        count++;                      
        while(temp1){     //taking 1 digit from 2nd num and multiplying with all digits of num1
            int num1=temp1->data;
            int num2=temp2->data;
            int mul=num1*num2+carry;  //adding carry
            int data=mul%10;
            carry=mul/10;
            if(count==1)    //for 1st digit storing in R list
                insert_first(headR,tailR,data);
            else    
                insert_first(&headR2,&tailR2,data);      //else all are storing in R2
            temp1=temp1->prev;    
        }    
        if(carry){                //if after temp1 reaches null if we still have carry we have to insert carry
                if(count==1)
                    insert_first(headR,tailR,carry);
                else    
                    insert_first(&headR2,&tailR2,carry);    
            }
        addition(*tailR,tailR2,&head_AR,&tail_AR);  //adding R and R2
        delete_list(headR,tailR);            //deleting R ,so that we can store the addition result
        delete_list(&headR2,&tailR2);       //deleting R2 ,so that we can store the next digit multiplied value
        *headR=head_AR;                //updating the R with the addition result
        *tailR=tail_AR;               //to not use R1 we used one temp list AR
        head_AR=tail_AR=NULL;        //making it NULL so we can reuse it for next addition
        temp2=temp2->prev;          //updating 2nd num to next digit
        temp1=tail1;               //updating 1st num to again LSB
    }
    remove_pre_zeros(headR);      //removing pre zeros

}

