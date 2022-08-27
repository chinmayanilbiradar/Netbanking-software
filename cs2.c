#include<stdio.h>
#include <stdlib.h>
#include "header1.h"
#include "string.h"
#include"time.h"
int main()
{
    struct customer c1;
    char ch;
    char op;
    char hdfc[50]="HDFC0000077", sbi[50]="SBIN0020852", andhra[50]="ANDB0002363";
    FILE* f1;
    f1=fopen("Client_details.txt", "a+");
    printf("************************************WELCOME*************************************\n");
    printf("Enter Customer name: ");
    scanf("%[^\n]s", c1.name);
    printf("Enter date of birth(dd/mm/yyyy): ");
    scanf("%s",c1.dob);
    printf("Enter Nationality: ");
    scanf("%s",c1.nat);
    fflush(stdin);
    printf("To link your account to HDFC Bank, click 1.\nTo link your account to SBI Bank, click 2.\nTo link your account to Andhra Bank, click 3\n");
    scanf(" %c",&ch);
    switch(ch)
    {
        case '1': strcpy(c1.ifsc,hdfc);
                  printf("IFSC Code is %s\n", c1.ifsc);
                break;
        case '2': strcpy(c1.ifsc,sbi);
                    printf("IFSC Code is %s\n", c1.ifsc);
                    break;
        case '3': strcpy(c1.ifsc,andhra);
                  printf("IFSC Code is %s\n", c1.ifsc); 
                break;
    }
    srand(time(NULL));
    c1.acct_no = rand();
    printf("Your bank account number is: %d\n", c1.acct_no);
    printf("Enter UPI Handle(<username>@<bankname>): ");
    scanf("%s", c1.upi);
    printf("Enter password (minimum 8 characters): ");
    scanf("%s", c1.upi_pswd);
    while(strlen(c1.upi_pswd)<8)
    {
        printf("Password entered is too short.\nEnter password: ");
        scanf("%s", c1.upi_pswd);
    }
    printf("Set a 4 digit pin: ");
    scanf("%d", &c1.pin);
    if(c1.pin<1000||c1.pin>9999)
    {
        printf("Enter a valid pin: ");
        scanf("%d", &c1.pin);
    }
    printf("Enter Amount to be deposited: ");
    scanf("%d", &c1.balance);
    do 
    {
        printf("To enable NEFT Transcation, click 1.\nTo enable debit transaction, click 2.\nTo change UPI Password, click 3.\nTo exit, click 4\n");
        scanf(" %c", &op);
        switch(op)
        {
        case '1': neft(f1, &c1, hdfc, sbi, andhra);
                    break;
        case '2':  deb_cred(f1, &c1);
                    break;
        case '3':  upipass(f1, &c1);
                    break;
        case '4': break;
        }
    }while(op!='4');
    fprintf(f1,"%s\t%s\nCUSTOMER NAME: %s\nDATE OF BIRTH: %s\nNATIONALITY:%s\nIFSC CODE: %s\nUPI HANDLE: %s\nUPI PASSCODE: %s\nACCOUNT NUMBER: %d\nCURRENT SAVINGS: %d\n",__DATE__,__TIME__,c1.name,c1.dob, c1.nat,c1.ifsc, c1.upi, c1.upi_pswd, c1.acct_no, c1.balance);
    fclose(f1);

    FILE* f2=fopen("Client_details.txt","r");
    disp(f2,c1);
return 0;
}