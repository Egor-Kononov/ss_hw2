#ifndef myBank_h
#define myBank_h
#define bank_accounts 50
#define FIRST_ACCOUNT 901
#define LAST_ACCOUNT 950

extern double bank[2][bank_accounts];

int open(double ammount); // if the user typed "O". 
double balance(int bankAccount); //if the user typed "B".
double deposit(int bankAccount, double amount); //if the user typed "D".
double withdraw(int bankAccount, double withdraw); //if the user typed "W". 
void close(int bankAccount); //if the user typed "C". 
void interest(double inter); //if the user typed "I". 
void print(); //if the user typed "P". 
void escape(); //if the user typed "E".

#endif