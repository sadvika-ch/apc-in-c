#include "apc.h"

void division(node *headL1, node *headOPR2,node * tailOPR2, node **headR, node **tailR)
{
    node * headOPR1=NULL,* tailOPR1=NULL,*temp=headL1,*head_SR=NULL,*tail_SR=NULL;
    insert_last(&headOPR1,&tailOPR1,temp->data);
    while(compare_list(headOPR1,headOPR2)==OPERAND2){  //loop till 2nd num is greater sp that we can divide
        temp=temp->next;
        if(!temp){           //if num1 is less than number 2
            insert_last(headR,tailR,0);   //we are storing 0 
            return;
        }   
        insert_last(&headOPR1,&tailOPR1,temp->data);  //else we are taking next digit also
    }
    while(temp){
        int count=0;      //count to store the quotient
        remove_pre_zeros(&headOPR1);
        while(compare_list(headOPR1,headOPR2)!=OPERAND2){  //here we taking help of subtraction to get the quotient
            subtraction(tailOPR1,tailOPR2,&head_SR,&tail_SR);   //calling subtraction func
            count++;          //increasing
            delete_list(&headOPR1,&tailOPR1);
            headOPR1=head_SR;
            tailOPR1=tail_SR;
            head_SR=tail_SR=NULL;
        }
        insert_last(headR,tailR,count);
        temp=temp->next;
        if(temp)
            insert_last(&headOPR1,&tailOPR1,temp->data);
        else    
            break;    
    }
        
}
