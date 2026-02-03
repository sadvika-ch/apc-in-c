#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow=0;
    while(tail1){          //running loop till greater number length
        int diff=0;
        if(borrow){           //if borrow is present we have to make the before number -- 
            (tail1->data)--;
            borrow=0;
        }
        int num=0;          
        if(tail2)      //num2 len can be less than num1 len
        {
            num=tail2->data;     //so of num2 len is exceeded our num will be 0 only
            tail2=tail2->prev;
        }
        if(tail1->data >= num){
            diff=tail1->data-num;
        }
        else{
            diff=(tail1->data)+10-num;    //adding 10 for -ve diff
            borrow=1;
        }
        insert_first(headR,tailR,diff);  //inserting into the result list
        tail1=tail1->prev;
            
    }
    remove_pre_zeros(headR);   //removing pre zeros in the result
}
