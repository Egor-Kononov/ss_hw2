#include <stdio.h>
#include "myBank.h"


int main(){
    char choice;
    int bankAccount;
    double ammount;
    double balanceOf;
    double add;
    int interest_rate;
    double pull;
    int check;

    do{
        printf("Please choose a transation type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'O':
                 printf("Please enter amount for deposit: ");
                 check = scanf("%lf", &ammount);
                 if(check != 1){
                     printf("Failed to read the amount\n\n");
                     break;
                 }
                 if(ammount < 0){
                     printf("Invalid Amount\n\n");
                     break;
                 }
                 bankAccount = open(ammount);
                 if(bankAccount == -1){
                     printf("err:no free accounts \n");
                     break;
                 }
				 printf("New account number is: %d\n\n" , bankAccount);
                 break;                
        case 'B':
                 printf("Please enter account number: ");
                 check = scanf("%d",&bankAccount);
                 if(check != 1){
                     printf("Failed to read the account number\n\n");
                     break;
                 }
                 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
                     printf("Invalid account number\n\n");
                     break;
                }
                 if(bank[0][bankAccount-FIRST_ACCOUNT] == 0){
                     printf("This account is clossed\n\n");
                     break;
                 }
                 balanceOf = balance(bankAccount);
                 printf("The balance of account number %d is: %0.2lf\n\n", bankAccount, balanceOf);
                 break;     
        case 'D':
                 printf("Please enter account number: ");
                 check = scanf("%d",&bankAccount);
                 if(check != 1){
                     printf("Failed to read the account number\n\n");
                     break;
                 }
                 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
					printf("Invalid account number\n\n"); 
					break;
				 }
                  if(bank[0][bankAccount-FIRST_ACCOUNT] == 0){
                     printf("This account is clossed\n\n");
                     break;
                 }
                 printf("Please enter the ammount to deposit: ");
                 check = scanf("%lf",&add);
                 if(check != 1){
                     printf("Failed to read the amount\n\n");
                     break;
                 }
                 if(add < 0){
					printf("Cannot deposit a negative amount\n\n");
					break;
				 }
				double added = deposit(bankAccount,add);
				 printf("The new balance is: %0.2lf \n\n",added);
				 break;			
        case 'W':
				 printf("Please enter account number: ");
				 check = scanf("%d",&bankAccount);
                 if(check != 1){
                     printf("Failed to read the account number\n\n");
                     break;
                 }
				 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
					printf("Invalid account number\n\n"); 
					break;
				 }
                 if(bank[0][bankAccount-FIRST_ACCOUNT] == 0){
                     printf("This account is clossed\n\n");
                     break;
                 }
				 printf("Please enter the amount to withdraw: ");
                 check = scanf("%lf",&pull);
                 if(check != 1){
                     printf("Failed to read amount\n\n");
                     break;
                 }
				double withdrew = withdraw(bankAccount, pull);
				if(withdrew == -2){
					printf("Cannot withdraw more than the balance\n\n");
					break;
				}
				printf("The new balance is: %0.2lf \n\n", withdrew);
				break;
        case 'C':
				 printf("Please enter account number: ");
				 check = scanf(" %d", &bankAccount);
                 if(check != 1){
                     printf("Failed to read the account number\n\n");
                     break;
                 }
                 if(bankAccount < FIRST_ACCOUNT || bankAccount > LAST_ACCOUNT){
					printf("Invalid account number\n\n"); 
					break;
				 }
                 if(bank[0][bankAccount-FIRST_ACCOUNT] == 0){
                     printf("This account is already clossed\n\n");
                     break;
                 }
                 close(bankAccount);
                 printf("\n");
                 break;
        case 'I':
				 printf("Please enter interest rate: ");
				 check = scanf("%d", &interest_rate);
                 if(check != 1){
                     printf("Failed to read the interest rate\n\n");
                     break;
                 }
                 if(interest_rate > 100 || interest_rate < 0){
                     printf("Invalid interest rate\n\n");
                     break;
                 }
                 interest(interest_rate);
                 printf("\n\n");
				 break;	
        case 'P':
                 print();
                 printf("\n");
                 break;
        case 'E':
                 escape();
                 break;
        default :
            printf("Invalid transaction type\n\n");
            break;
        }
    }while (choice != 'E');   
return 0;
}
