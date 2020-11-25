#include <stdio.h>
#include "myBank.h"


int main(){
    char choice;
    double ammount;
    do{
        printf("please enter (capital): \n 'O' to Open new bank account\n 'B' to check balance on opened account\n 'D' to deposite money to opened account\n 'W' to withdraw from opened account\n 'C' to close an opened account\n 'I' to add interest to all opened accounts\n 'P' to print all opened accounts and their balance\n 'E' to escape \n");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'O':
                 printf("transection type?: O\n");
                 printf("please enter ammount to initial bank account \n");
                 
        case :
            break; 
        case :
            break;
        case :
            break;
        case :
            break;
        case :
            break;
        case :
            break;
        case :
            break;                    
        default:
            printf("ERR; Please enter valid input.\n");
            break;
        }
    }

}
