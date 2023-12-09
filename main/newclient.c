#include "newclient.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int id;
    char Seria[3];
    char NR[7];
    char CNP[14];
    char last_name[40];
    char first_name[100];
    char addres[150];
}Identity_card;

int check_CNP(char CNP[13]){
    char  luna[3]={CNP[3],CNP[4],'\0'},zi[3]={CNP[5],CNP[6],'\0'},c,CNP_file[14]={};
    int i=0;
    char read[50];
    Identity_card readcnp;
    if(strlen(CNP)!=13)return 1;
    if(atoi(luna)==0 || atoi(luna)>=13 )return 1;/*verific sa nu fie luna 34*/
    if(atoi(zi)==0 || atoi(zi)>=32 )return 1;/*verific sa nu fie ziua 34*/
    for(i=0;i<strlen(CNP);i++)if((int)CNP[i]>57 || (int)CNP[i]<48)return 1;
    FILE *client_data=fopen("client_data.txt","r");
    char buff[5];
    int ID;
    fscanf(client_data,"%d",&ID);
    for(i=0;i<ID;i++){
        fscanf(client_data,"%d",&readcnp.id);
        fgets(buff,2,client_data);
        fgets(readcnp.CNP,sizeof(readcnp.CNP),client_data);
        fgets(buff,2,client_data);
        fgets(readcnp.Seria,sizeof(readcnp.Seria),client_data);
        fgets(buff,2,client_data);
        fgets(readcnp.NR,sizeof(readcnp.NR),client_data);
        fscanf(client_data,"%s",readcnp.first_name);
        fgets(buff,2,client_data);
        fscanf(client_data,"%[^\n]",readcnp.last_name);
        fgets(buff,3,client_data);
        fscanf(client_data,"%[^\n]",readcnp.addres);
        if(strcmp(CNP,readcnp.CNP)==0){fclose(client_data);return 1;}
}
    fclose(client_data);
    return 0;
}

int check_SERIA(char SERIA[2]){
    char x[3];int contor=1;
    FILE *fseria=fopen("seria_cnp.txt","r");
    if(strlen(SERIA)!=2)return 1;

    int i=0;
    for(i=0;i<strlen(SERIA);i++)SERIA[i]=toupper(SERIA[i]);

    while(fgets(x,3,fseria)!=NULL){
    for(i=0;i<strlen(x);i++)x[i]=toupper(x[i]);
       if (strcmp(SERIA,x)==0)return 0;
    }
fclose(fseria);
return 1;
}

int check_NR(char NR[6]){
    int i=0;
     Identity_card readcnp;
    if(strlen(NR)!=6)return 1;
    for(i=0;i<strlen(NR);i++)if((int)NR[i]>57 || (int)NR[i]<48)return 1;
    FILE *client_data=fopen("client_data.txt","r");

    char buff[5];
    int ID;
    fscanf(client_data,"%d",&ID);
    for(i=0;i<ID;i++){
        fscanf(client_data,"%d",&readcnp.id);
        fgets(buff,2,client_data);
        fgets(readcnp.CNP,sizeof(readcnp.CNP),client_data);
        fgets(buff,2,client_data);
        fgets(readcnp.Seria,sizeof(readcnp.Seria),client_data);
        fgets(buff,2,client_data);
        fgets(readcnp.NR,sizeof(readcnp.NR),client_data);
        fscanf(client_data,"%s",readcnp.first_name);
        fgets(buff,2,client_data);
        fscanf(client_data,"%[^\n]",readcnp.last_name);
        fgets(buff,3,client_data);
        fscanf(client_data,"%[^\n]",readcnp.addres);

        if(strcmp(NR,readcnp.NR)==0){fclose(client_data);return 1;}
}
    fclose(client_data);

    return 0;
}

int function_newclient(){

    int ID=0;
    Identity_card new_client,*clientlist=NULL;

    FILE *client_data=fopen("client_data.txt","a+");
    if( client_data==NULL){printf("FILE Error!");exit(1);}

    int k;char x;
    //citire file

    fscanf(client_data,"%d",&ID);

    clientlist=(Identity_card*)malloc(ID*sizeof(Identity_card));
    char buff[5];
    int i=0;
    for(i=0;i<ID;i++){
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
    fclose(client_data);
  /* for(i=0;i<ID;i++){
        printf("id: %d\n",(clientlist+i)->id);
        printf("CNP:%s\n",(clientlist+i)->CNP);
        printf("Seria: %s\n",(clientlist+i)->Seria);
        printf("NR: %s\n",(clientlist+i)->NR);
        printf("Fitst name: %s\n",(clientlist+i)->first_name);
        printf("Last name: %s\n",(clientlist+i)->last_name);
        printf("Adres: %s\n",(clientlist+i)->addres);
    }

        printf("id: %d\n",(clientlist+0)->id);
        printf("CNP:%s\n",(clientlist+0)->CNP);
        printf("Seria: %s\n",(clientlist+0)->Seria);
        printf("NR: %s\n",(clientlist+0)->NR);
        printf("Fitst name: %s\n",(clientlist+0)->first_name);
        printf("Last name: %s\n",(clientlist+0)->last_name);
        printf("Adres: %s\n",(clientlist+0)->addres);*/

    new_client.id=ID+1;
    printf("\n\n\tNew Client->");
    printf("\tid: %d",new_client.id);

    printf("\n\t\t       CNP: ");
    scanf ("%s",new_client.CNP);
    k=0;
    while(check_CNP(new_client.CNP)!=0){
        printf("\t\t\t    ------------- |Incorect CNP|\n\t\t\t   ");
        if( k>= 2 ){
                printf("You want to abort[Y/N]->");

                scanf("%s",&x);
                if(toupper(x)=='Y' || (toupper(x)!='Y' && toupper(x)!='N')){/*printf("\n\n\tProcces was canceled, try again!\n")*/;return 0;}
                printf("\t\t\t   ");
        }
        printf(":");
        scanf ("%s",new_client.CNP);
        k++;
    }

    printf("\t\t     Seria: ");
    scanf ("%s",new_client.Seria);
    k=0;
    while(check_SERIA(new_client.Seria)!=0){
        printf("\t\t\t    ------------- |Incorect Seria|\n\t\t\t   ");
        if( k>= 2 ){
                printf("You want to abort[Y/N]->");

                scanf("%s",&x);
                if(toupper(x)=='Y' || (toupper(x)!='Y' && toupper(x)!='N')){/*printf("\n\n\tProcces was canceled, try again!\n");*/return 0;}
                printf("\t\t\t   ");
        }
        printf(":");
        scanf ("%s",new_client.Seria);
        k++;
    }


    printf("\t\t        NR: ");
    scanf("%s",new_client.NR);
    k=0;
    while(check_NR(new_client.NR)!=0){
        printf("\t\t\t    ------------- |Incorect Seria|\n\t\t\t   ");
        if( k>= 2 ){
                printf("You want to abort[Y/N]->");

                scanf("%s",&x);
                if(toupper(x)=='Y' || (toupper(x)!='Y' && toupper(x)!='N')){/*printf("\n\n\tProcces was canceled, try again!\n");*/return 0;}
                printf("\t\t\t   ");
        }
        printf(":");
        scanf ("%s",new_client.NR);
        k++;
    }

    fflush(stdin) ;
    printf("\t        First name: ");
    scanf (" %s",new_client.first_name);

    fflush(stdin) ;
    printf("\t\t Last name: ");
    scanf ("%[^\n]",new_client.last_name);

    fflush(stdin) ;
    printf("\t\t    Addres: ");
    scanf (" %[^\n]",new_client.addres);

   /* for(i=0;i<ID;i++){
        printf("id: %d\n",(clientlist+i)->id);
        printf("CNP:%s\n",(clientlist+i)->CNP);
        printf("Seria: %s\n",(clientlist+i)->Seria);
        printf("NR: %s\n",(clientlist+i)->NR);
        printf("Fitst name: %s\n",(clientlist+i)->first_name);
        printf("Last name: %s\n",(clientlist+i)->last_name);
        printf("Adres: %s\n",(clientlist+i)->addres);
    }
        printf("id: %d\n",new_client.id);
        printf("CNP:%s\n",new_client.CNP);
        printf("Seria: %s\n",new_client.Seria);
        printf("NR: %s\n",new_client.NR);
        printf("Fitst name: %s\n",new_client.first_name);
        printf("Last name: %s\n",new_client.last_name);
        printf("Adres: %s\n",new_client.addres);*/

    //we add in the client
    FILE *writeclient_data=fopen("client_data.txt","w");
    ID=ID;
    fprintf(writeclient_data,"%d\n",ID+1);
     for(i=0;i<ID;i++){
        fprintf(writeclient_data,"%d ",(clientlist+i)->id);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->CNP);
        fprintf(writeclient_data,"%s ",(clientlist+i)->Seria);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->NR);
        fprintf(writeclient_data,"%s ",(clientlist+i)->first_name);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->last_name);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->addres);
     }
        fprintf(writeclient_data,"%d ",new_client.id);
        fprintf(writeclient_data,"%s\n",new_client.CNP);
        fprintf(writeclient_data,"%s ",new_client.Seria);
        fprintf(writeclient_data,"%s\n",new_client.NR);
        fprintf(writeclient_data,"%s ",new_client.first_name);
        fprintf(writeclient_data,"%s\n",new_client.last_name);
        fprintf(writeclient_data,"%s\n",new_client.addres);

free(clientlist);
fclose(writeclient_data);
return 1;
}
