#include <stdio.h>
#include "myBank.h"


int main(){
    char choice;
    int bankAccount;
    double ammount;
    double balanceOf;
    double add;
    double interest_rate;
    double pull;
    int check;

    do{
        printf("please enter (capital): \n 'O' to Open new bank account\n 'B' to check balance on opened account\n 'D' to deposite money to opened account\n 'W' to withdraw from opened account\n 'C' to close an opened account\n 'I' to add interest to all opened accounts\n 'P' to print all opened accounts and their balance\n 'E' to escape \n");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'O':
                 printf("transection type: O\n");
                 printf("please enter ammount to initial bank account \n");
                 check = scanf("%lf", &ammount);
                 if(check != 1){
                     printf("err: not a real number\n");
                     break;
                 }
                 if(ammount < 0){
                     printf("err:cant open account with negative ammount of money \n");
                     break;
                 }
                 bankAccount = open(ammount);
                 if(bankAccount == -1){
                     printf("err:no free accounts \n");
                     break;
                 }
                 printf("initial deposite: %0.2lf\n", ammount);
				 printf("your account number is: %d\n" , bankAccount);
                 break;                
        case 'B':
                 printf("transection type: B\n");
                 printf("please enter account number (901 - 950) to check balance \n");
                 check = scanf("%d",&bankAccount);
                 if(check != 1){
                     printf("err: not a real number\n");
                     break;
                 }
                 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
                     printf("err: this account does not exist\n");
                     break;
                }
                 balanceOf = balance(bankAccount);
                 if(balanceOf == -1){
                     printf("err: this account is closed\n");
                     break;
                 }
                 printf("account_number: %d your balance is: %0.2lf\n", bankAccount, balanceOf);
                 break;     
        case 'D':
                 printf("transection type: D\n");
                 printf("please enter account number (901-950) \n");
                 check = scanf("%d",&bankAccount);
                 if(check != 1){
                     printf("err: not a real number\n");
                     break;
                 }
                 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
					printf("err: this account does not exist\n"); 
					break;
				 }
                 printf("please enter the ammount that you want to deposit \n");
                 check = scanf("%lf",&add);
                 if(check != 1){
                     printf("err: not a real number\n");
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
				 printf("account_number: %d \n you added %0.2lf \n and your new balance is: %0.2lf \n", bankAccount, add, added);
				 break;			
        case 'W':
                 printf("transection type: W\n");
				 printf("please enter account number (901-950) \n");
				 check = scanf("%d",&bankAccount);
                 if(check != 1){
                     printf("err: not a real number\n");
                     break;
                 }
				 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
					printf("err: this account does not exist\n"); 
					break;
				 }
				 printf("please enter the ammount that you want to withdraw \n");
                 check = scanf("%lf",&pull);
                 if(check != 1){
                     printf("err: not a real number\n");
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
				printf("account_number: %d \n you withdrew %0.2lf \n and your new balance is: %0.2lf \n", bankAccount, pull, withdrew);
				break;
        case 'C':
                 printf("transection type: C\n");
				 printf("please enter account number (901-950) to close this account \n");
				 check = scanf(" %d", &bankAccount);
                 if(check != 1){
                     printf("err: not a real number\n");
                     break;
                 }
                 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
					printf("err: this account does not exist\n"); 
					break;
				 }
                 close(bankAccount);
                 break;
        case 'I':
                 printf("transection type: I\n");
				 printf("please enter interest to add to all open accounts \n");
				 check = scanf("%lf", &interest_rate);
                 if(check != 1){
                     printf("err: not a real number\n");
                     break;
                 }
                 interest(interest_rate);
				 printf("interest added to all open accounts\n");
				 break;	
        case 'P':
                 printf("transection type: P\n");
				 printf("printing all bank accounts and their balance...\n");
                 print();
                 break;
        case 'E':
                 printf("transection type: E\n");
                 escape();
                 break;
        default :
            printf("ERR; Please enter valid input.\n");
            break;
        }
    }while (choice != 'E');   
return 0;
}