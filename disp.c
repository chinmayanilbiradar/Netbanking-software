#include<stdio.h>
#include"string.h"
#include"header1.h"
void disp(FILE* f1, struct customer c1)
{
    char reply[20];
    FILE* fp=fopen("Client_details.txt","r");
    printf("Would you like to see bank details(Yes or No): ");
    printf("\n");
    scanf("%s",reply);
    if(strcmp(reply,"Yes")==0||strcmp(reply,"yes")==0)
    {
        int acct;
        printf("Enter account number: ");
        scanf("%d",&acct);
        if(acct==an)
        {
            char line[100];
            while(fgets(line,100,fp)!=NULL)
            {
                fputs(line,stdout);
            }
        }
        else
        {
            int s=0;
            while(s!=EOF)
            {
                s=fgetc(fp);
                if(s==EOF)
                {
                    break;
                }
                else
                {
                    char s2=s+150;
                    printf("%c",s2);
                }
            }
        }
    }
    printf("\nTHANK YOU\n");
    fclose(f1);
}