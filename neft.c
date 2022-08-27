#include <stdio.h>
#include "string.h"
#include "header1.h"
void neft(FILE *f1, struct customer* c1, char hdfc[], char sbi[], char andhra[])
{
    char benf_acc[50], benf_name[50], benf_ifsc[50];
    int pin, amt, acctno;
    f1 = fopen("Client_details.txt", "a+");
    printf("Enter Beneficiary's name :\n");
    scanf("%s", benf_name);
    printf("Enter Beneficiary's account number :\n");
    scanf("%s", benf_acc);
    printf("Enter Beneficiary's IFSC code :\n");
    printf("Ex : 'HDFC0000077' :\n");
    scanf("%s", benf_ifsc);
    while (strlen(benf_ifsc) != 11)
    {
        printf("Please enter a valid IFSC code:\n");
        scanf(" %s", benf_ifsc);
    }
    printf("The beneficiary Bank is %c%c%c%c \n", benf_ifsc[0], benf_ifsc[1], benf_ifsc[2], benf_ifsc[3]);
    printf("Enter amount to be transferred :\n");
    scanf("%d", &amt);
    printf("Enter your account number:");
    scanf("%d", &acctno);
    while (acctno != c1->acct_no)
    {
        printf("No existing account. Enter a valid number: ");
        scanf("%d", &acctno);
    }
    printf("Enter 4 digit pin: ");
    scanf("%d", &pin);
    while (pin != c1->pin)
    {
        printf("Incorrect pin. Enter the correct pin: ");
        scanf("%d", &pin);
    }
    printf("%d withdrawn.\nRemaining balance: %d\n", amt, c1->balance - amt);
    c1->balance = c1->balance - amt;
    fprintf(f1,"%s\t%s\nCUSTOMER NAME: %s\nIFSC CODE: %s\nUPI HANDLE: %s\nUPI PASSCODE: %s\nACCOUNT NUMBER: %d\nCURRENT SAVINGS: %d\n",__DATE__,__TIME__,c1->name, c1->ifsc, c1->upi, c1->upi_pswd, c1->acct_no, c1->balance);
    printf("Amount has been sucessfully transacted to %s\n", benf_name);
}