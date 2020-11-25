#include <stdio.h>
#include "myBank.h"


int main(){
    char choice;
    int bankAccount;
    double ammount;
    int balanceOf;
    double add;
    double interest_rate;
    double pull;

    do{
        printf("please enter (capital): \n 'O' to Open new bank account\n 'B' to check balance on opened account\n 'D' to deposite money to opened account\n 'W' to withdraw from opened account\n 'C' to close an opened account\n 'I' to add interest to all opened accounts\n 'P' to print all opened accounts and their balance\n 'E' to escape \n");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'O':
                 printf("transection type?: O\n");
                 printf("please enter ammount to initial bank account \n");
                 scanf("%lf", &ammount);
                 if(ammount < 0){
                     printf("err:cant open account with negative ammount of money \n");
                     break;
                 }
                 bankAccount = open(ammount);
                 if(bankAccount == -1){
                     printf("err:no free accounts \n");
                     break;
                 }
                 printf("initial deposite?: %0.2lf\n", ammount);
				 printf("your account number is: %d\n" , bankAccount);
                 break;                
        case 'B':
                 printf("transection type: B\n");
                 printf("please enter account number (901 - 950) to check balance \n");
                 scanf("%d",&bankAccount);
                 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
                     printf("err: this account does not exist\n");
                     break;
                }
                 balanceOf = balance(bankAccount);
                 if(balanceOf == -1){
                     printf("err: this account is closed\n");
                     break;
                 }
                 printf("account_number?: %d your balance is: %0.2lf\n", bankAccount, balanceOf);     
        case 'D':
                 printf("transection type: D\n");
                 printf("please enter account number (901-950) and the ammount you want to deposit, seperated with space \n");
                 scanf(" %d %lf",&bankAccount, &add);
                 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
					printf("err: this account does not exist\n"); 
					break;
				 }
                 if(add < 0){
					printf("err: cant deposit negative ammount of money\n");
					break;
				}
				double added = deposit(bankAccount,add);
				if(added == -1){
					printf("err: the account is closed\n");
					break;
				}
				printf("account_number?: %d \n you added %0.2lf \n and your new balance is: %0.2lf \n", bankAccount, add, added);
				break;			
        case 'W':
                 printf("transection type: W\n");
				 printf("please enter account number (901-950) and the ammount you want to withdraw, seperated with space \n");
				 scanf(" %d %lf",&bankAccount, &pull);
				 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
					printf("err: this account does not exist\n"); 
					break;
				 }
				
				 if(pull < 0){
					printf("err: cant withdraw negative ammount of money\n");
					break;
				 }
				double withdrew = withdraw(bankAccount, pull);
				if (withdrew == -1){
					printf("err: the account is closed\n");
					break;
				}
				if(withdrew == -2){
					printf("err: you don't have enough money to withdraw\n");
					break;
				}
				printf("account_number?: %d \n you withdrew %0.2lf \n and your new balance is: %0.2lf \n", bankAccount, pull, withdrew);
				break;
        case 'C':
                 printf("transection type?: C\n");
				 printf("please enter account number (901-950) to close this account \n");
				 scanf(" %d", &bankAccount);
                 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
					printf("err: this account does not exist\n"); 
					break;
				 }
                 close(bankAccount);
                 break;
        case 'I':
                 printf("transection type?: I\n");
				 printf("please enter interest to add to all open accounts \n");
				 scanf("%lf", &interest_rate);
                 interest(interest_rate);
				 printf("interest added to all open accounts\n");
				 break;	
        case 'P':
                 printf("transection type: P\n");
				 printf("printing all bank accounts and their balance...\n");
                 print();
                 break;
        case 'E':
                 printf("transection type: D\n");
                 escape();
                 break;
        default :
            printf("ERR; Please enter valid input.\n");
            break;
        }
    }while (choice != 'E');   
return 0;
}
