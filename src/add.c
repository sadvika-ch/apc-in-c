#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int carry=0;            
    while(tail1 || tail2 || carry){
        int sum=carry;           //if carry is present we need to add it no next number 
        if(tail1){
            sum+=tail1->data;   //adding first list value to sum
            tail1=tail1->prev;
        }
        if(tail2){
            sum+=tail2->data;   //adding second list value to sum
            tail2=tail2->prev;
        }
        insert_first(headR,tailR,sum%10);  //then storing the result in result list
        carry=sum/10;                    //taking carry 
    }
}