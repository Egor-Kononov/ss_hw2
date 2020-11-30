#include <stdio.h>
#include "myBank.h"
#define SIZE 50
#define FIRST_ACCOUNT 901
#define LAST_ACCOUNT 950

double bank[2][bank_accounts] = {0};

int open(double amount){
    int account_number = -1;
    for(int i = 0; i < SIZE; i++){
        if(bank[0][i]== 0){
           bank[0][i] = 1;
           bank[1][i] = amount;
           account_number = FIRST_ACCOUNT+i;
           return account_number;
        }
    }
return account_number;
}

double balance(int bankAccount){
    double current_balance;
        current_balance = bank[1][bankAccount-FIRST_ACCOUNT];
    return current_balance;
}

double deposit(int bankAccount, double amount){
        bank[1][bankAccount-FIRST_ACCOUNT] += amount;
        double newBalance =  bank[1][bankAccount-FIRST_ACCOUNT];
    return newBalance;
}

 double withdraw(int bankAccount, double withdraw){
     double newBalance = -2;
     if(withdraw <= bank[1][bankAccount-FIRST_ACCOUNT] ){ 
        bank[1][bankAccount-FIRST_ACCOUNT]-= withdraw;
        newBalance = bank[1][bankAccount-FIRST_ACCOUNT];   
     }
     return newBalance;
 }

 void close(int bankAccount){
         bank[0][bankAccount-FIRST_ACCOUNT]= 0;
         bank[1][bankAccount-FIRST_ACCOUNT]= 0;
         printf("Closed account number %d \n", bankAccount);
 }

 void interest(double inter){
      for(int i = 0; i < SIZE; i++){
          if(bank[0][i]==1){
              bank[1][i] += (bank[1][i]*(inter/100));
          }
      }
 }

 void print(){
     for(int i = 0; i < SIZE; i++){
         if(bank[0][i]==1){
             printf("The balance of account nuber %d is: %0.2lf\n", i+FIRST_ACCOUNT , bank[1][i]);
         }
     }
 }

 void escape(){
     for(int i = 0; i < SIZE; i++){
         if(bank[0][i]==1){
             bank[0][i]=0;
             bank[1][i]=0;
         }
     }
 }

