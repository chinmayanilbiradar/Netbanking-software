#include<stdio.h>
#include "header1.h"
void deb_cred(FILE* f1,struct customer* c1)
{
    int pin, acctno, amt;
    printf("Enter account number to withdraw money: ");
    scanf("%d", &acctno);
    while(acctno!=c1->acct_no)
    {
        printf("No existing account. Enter a valid number: ");
        scanf("%d", &acctno);
    }
    printf("Enter 4 digit pin: ");
    scanf("%d", &pin);
    while(pin!=c1->pin)
    {
        printf("Incorrect pin. Enter the correct pin: ");
        scanf("%d",&pin);
    }
    printf("Enter amount to be withdrawn: ");
    scanf("%d", &amt);
    printf("%d withdrawn.\nRemaining balance: %d\n", amt, c1->balance-amt);
    c1->balance=c1->balance-amt;
    fprintf(f1,"CUSTOMER NAME: %s\nIFSC CODE: %s\nUPI HANDLE: %s\nUPI PASSCODE: %s\nACCOUNT NUMBER: %d\nCURRENT SAVINGS: %d\n", c1->name, c1->ifsc, c1->upi, c1->upi_pswd, c1->acct_no, c1->balance);
    printf("Transaction successful\n");

}