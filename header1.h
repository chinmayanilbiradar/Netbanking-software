#include<stdio.h>
struct customer
{
    char name[100];
    char nat[50];
    char dob[50];
    char ifsc[50];
    char upi[100]; 
    char upi_pswd[100];
    int  balance;
    int acct_no;
    int pin;
}C[100];

void neft(FILE* f1, struct customer*, char [], char [], char []);
void deb_cred(FILE* f1,struct customer*);
void upipass(FILE* f1, struct customer*);
void disp(FILE* f1, struct customer);