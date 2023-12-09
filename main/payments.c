#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

typedef struct
{
    float ballance;
    int n_awating, n_completed;
    float *awating, *completed;

} Payment;
typedef struct
{
    int id;
    char Seria[3];
    char NR[7];
    char CNP[14];
    char last_name[40];
    char first_name[100];
    char addres[150];
} Identity_card;


int Payments()
{
    int N,i;

    FILE *ptr_payments=NULL;

    ptr_payments=fopen("payments.txt","r");
    if(ptr_payments==NULL)
    {
        printf("FILE Error!");
        exit(1);
    }
    fscanf(ptr_payments,"%d",&N);
    Payment *p=NULL;

    p=(Payment* )malloc(sizeof(Payment)*N);

    for(i=0; i<N; i++)
    {

        fscanf(ptr_payments,"%f",&p[i].ballance);


        fscanf(ptr_payments,"%d",&p[i].n_completed);
        p[i].completed=(float *)malloc(sizeof(float)*p[i].n_completed);
        for(int j=0; j<p[i].n_completed; j++)
            fscanf(ptr_payments,"%f",&p[i].completed[j]);


        fscanf(ptr_payments,"%d",&p[i].n_awating);
        p[i].awating=(float *)malloc(sizeof(float)*(p[i].n_awating));
        for(int j=0; j<p[i].n_awating; j++)
            fscanf(ptr_payments,"%f",&p[i].awating[j]);
    }
    fclose(ptr_payments);
     //citire file

    FILE *client_data=fopen("client_data.txt","r");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



    if( client_data==NULL)
    {
        printf("FILE Error!");
        exit(1);
    }
    int ID;
    char buff[5];
    fscanf(client_data,"%d",&ID);
     Identity_card *clientlist=NULL;
    clientlist=(Identity_card*)malloc(ID*sizeof(Identity_card));
    for(i=0; i<ID; i++)
    {

        fscanf(client_data,"%d",&(clientlist+i)->id);
        fgets(buff,2,client_data);
        fgets((clientlist+i)->CNP,sizeof(clientlist->CNP),client_data);
        fgets(buff,2,client_data);
        fgets((clientlist+i)->Seria,sizeof(clientlist->Seria),client_data);
        fgets(buff,2,client_data);
        fgets((clientlist+i)->NR,sizeof(clientlist->NR),client_data);
        fscanf(client_data,"%s",(clientlist+i)->first_name);
        fgets(buff,2,client_data);
        fscanf(client_data,"%[^\n]",(clientlist+i)->last_name);
        fgets(buff,3,client_data);
        fscanf(client_data,"%[^\n]",(clientlist+i)->addres);

    }
    SetConsoleTextAttribute(hConsole, 11);
    for(i=0;i<ID;i++){
        printf("\n\t%s %s",(clientlist+i)->first_name,(clientlist+i)->last_name);
        printf("\n\t\tBALLANCE    %f$",p[i].ballance);
        printf("\n\n\t\tCompleted payments:\n\t\t");
        for(int j=0;j<p[i].n_completed;j++)
            printf("%f$ ",p[i].completed[j]);
        printf("\n");
        printf("\n\t\tAwating payments:\n\t\t");
        for(int j=0;j<p[i].n_awating;j++)
            printf("%f$ ",p[i].awating[j]);
        printf("\n\n");
    }
    free(clientlist);
    for(i=0;i<N;i++)
    {
        free(p[i].completed);
        free(p[i].awating);
    }
    free(p);
}
