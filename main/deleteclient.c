#include "deleteclient.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

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


int function_deleteclient()
{
    int ID=0,del;
    Identity_card *clientlist=NULL;

    FILE *client_data=fopen("client_data.txt","r");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



    if( client_data==NULL)
    {
        printf("FILE Error!");
        exit(1);
    }


    printf("\nEnter the id for the client to suspend: ");
    scanf("%d",&del);


    //citire file
    char buff[5];
    fscanf(client_data,"%d",&ID);

    clientlist=(Identity_card*)malloc(ID*sizeof(Identity_card));
    int i=0;
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
    del--;

    //printf("%d", (clientlist+ID)->id);
    if((clientlist+(del))->id<0)
    {
        printf("The client %s %s is already suspended",(clientlist+del)->first_name,(clientlist+del)->last_name);
    }
    else
    {
        (clientlist+(del))->id*=-1;
        printf("The client %s %s was suspended succesfully",(clientlist+del)->first_name,(clientlist+del)->last_name);


    }


    fclose(client_data);

    //we add in the client
    FILE *writeclient_data=fopen("client_data.txt","w");
    ID=ID;
    fprintf(writeclient_data,"%d\n",ID);
    for(i=0; i<ID; i++)
    {
        fprintf(writeclient_data,"%d ",(clientlist+i)->id);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->CNP);
        fprintf(writeclient_data,"%s ",(clientlist+i)->Seria);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->NR);
        fprintf(writeclient_data,"%s ",(clientlist+i)->first_name);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->last_name);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->addres);
    }
    free(clientlist);
    fclose(writeclient_data);
    return 1;

}
