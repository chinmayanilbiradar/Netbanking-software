#include<stdio.h>
#include "string.h"
#include "header1.h"
void upipass(FILE* f1, struct customer* c1)
{
    char upi2[50], pass1[50], pass2[50], pass3[50];
    f1=fopen("Client_details.txt", "a+");
    printf("Enter UPI Handle: ");
    scanf("%s", upi2);
    while(strcmp(upi2,c1->upi)!=0)
    {
        printf("No user exists with the entered UPI handle. Enter a valid UPI Handle: ");
        scanf("%s", upi2);
    }
    printf("Enter password: ");
    scanf(" %s", pass1);
    while(strcmp(pass1,c1->upi_pswd)!=0)
    {
        printf("Password entered is incorrect. Enter correct password: ");
        scanf(" %s", pass1);
    }
    printf("Enter new password: ");
    scanf(" %s", pass2);
    while(strlen(pass2)<8)
    {
        printf("Password entered is too short. Enter a different password: ");
        scanf(" %s", pass2);
    }
    printf("Re-enter password to confirm: ");
    scanf(" %s", pass3);
    while(strcmp(pass3,pass2)!=0)
    {
        printf("Password doesnot match previously entered password. Enter correct password: ");
        scanf(" %s", pass3);
    }

    strcpy(c1->upi_pswd,pass2);
    fprintf(f1,"%s\t%s\nCUSTOMER NAME: %s\nIFSC CODE: %s\nUPI HANDLE: %s\nUPI PASSCODE: %s\nACCOUNT NUMBER: %d\nCURRENT SAVINGS: %d\n",__DATE__,__TIME__,c1->name, c1->ifsc, c1->upi, c1->upi_pswd, c1->acct_no, c1->balance);
    printf("*******************************THANK YOU****************************************");
}
