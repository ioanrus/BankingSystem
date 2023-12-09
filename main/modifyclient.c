#include "modifyclient.h"
#include "logintitlu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "newclient.h"
#include <math.h>

#define nsave 9

typedef struct{
    int id;
    char Seria[3];
    char NR[7];
    char CNP[14];
    char last_name[40];
    char first_name[100];
    char addres[150];
}Identity_card;

void menu_cu1(char *s){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 240);
    printf(" %s ",s);
}
void menu_fara1(char *s){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 5);
    printf(" %s ",s);
}
void identifyprint(Identity_card saveclient,Identity_card newsave_client){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    printf("\n\tid: ");
    if(saveclient.id>0){
        SetConsoleTextAttribute(hConsole, 2);
        printf("%d",saveclient.id);
    }
    else if(saveclient.id<0){
        SetConsoleTextAttribute(hConsole, 4);
        printf("%d",saveclient.id);
    }
    if(newsave_client.id>0){SetConsoleTextAttribute(hConsole, 2);printf("  \tactivated");}

    if(newsave_client.id<0){SetConsoleTextAttribute(hConsole, 4);printf("  \tsuspended");}

    SetConsoleTextAttribute(hConsole, 9);
    printf(" \n\tCNP:%s",saveclient.CNP);
    if(strcasecmp(newsave_client.CNP,"[")!=0){SetConsoleTextAttribute(hConsole, 6);printf("  \t%s\n",newsave_client.CNP);}
        else printf("\n");
    SetConsoleTextAttribute(hConsole, 9);
    printf("\tSeria: %s",saveclient.Seria);
    if(strcasecmp(newsave_client.Seria,"[")!=0){SetConsoleTextAttribute(hConsole, 6);printf("  \t%s\n",newsave_client.Seria);}
       else printf("\n");
    SetConsoleTextAttribute(hConsole, 9);
    printf("\tNr: %s",saveclient.NR);
    if(strcasecmp(newsave_client.NR,"[")!=0){SetConsoleTextAttribute(hConsole, 6);printf("  \t%s\n",newsave_client.NR);}
        else printf("\n");
    SetConsoleTextAttribute(hConsole, 9);
    printf("\tFitst name: %s",saveclient.first_name);
    if(strcasecmp(newsave_client.first_name,"[")!=0){SetConsoleTextAttribute(hConsole, 6);printf("  \t%s\n",newsave_client.first_name);}
        else printf("\n");
    SetConsoleTextAttribute(hConsole, 9);
    printf("\tLast name: %s",saveclient.last_name);
    if(strcasecmp(newsave_client.last_name,"[")!=0){SetConsoleTextAttribute(hConsole, 6);printf("  \t%s\n",newsave_client.last_name);}
        else printf("\n");
    SetConsoleTextAttribute(hConsole, 9);
    printf("\tAddres: %s",saveclient.addres);
    if(strcasecmp(newsave_client.addres,"[")!=0){SetConsoleTextAttribute(hConsole, 6);printf("  \n\t%s\n",newsave_client.addres);}
        else printf("\n");
    SetConsoleTextAttribute(hConsole, 9);
    SetConsoleTextAttribute(hConsole, 6);


}

int saving_data(Identity_card *saveclient){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Identity_card newsave_client={ {0},{"["},{"["},{"["},{"["},{"["},{"["} };
    int i=0,o=0,n;
    char c;
    char *a[nsave]= {"id","CNP","Seria","NR","First name","Last name","Address","Save","Abort"};
    do
    {
        titlu();
        for(int i=0; i<nsave; i++)
            if(i==o)    menu_cu1(a[i]);
                else    menu_fara1(a[i]);
        identifyprint(*saveclient,newsave_client);
        SetConsoleTextAttribute(hConsole, 15);
        c=_getch();
        n=(int)c;

        if(n==-32)
        {
            c=_getch();
            n=(int)c;
            if(n==75)
                if(o>0)
                    o--;
                else
                    o=nsave-1;
            else if(n==77)
                if(o<nsave-1)
                    o++;
                else
                    o=0;
        }
        if(c==13)
        switch(o){
            case 0:{
                char x[30];
                SetConsoleTextAttribute(hConsole, 11);
                printf("\nTo suspend the account tap \"suspend\" and to activate tap \"activate\": ");
                scanf("%s",x);
                if(strcmp(x,"suspend")==0 ){
                        if(saveclient->id>0){
                            newsave_client.id=(-1)*(saveclient->id);
                            SetConsoleTextAttribute(hConsole, 12);
                            printf("\nThe account with id: %d is suspended.",saveclient->id);
                        }
                        else  {
                                newsave_client.id=saveclient->id;
                                SetConsoleTextAttribute(hConsole, 4);
                                printf("\nThe account with id: %d it is  suspended!!",saveclient->id);
                        }
                    }
                if(strcmp(x,"activate")==0 ){
                        if( saveclient->id<0){
                            newsave_client.id=(-1)*saveclient->id;
                            SetConsoleTextAttribute(hConsole, 2);
                            printf("\nThe account with id: %d is activated.",saveclient->id);
                        }
                        else {
                                newsave_client.id=saveclient->id;
                                SetConsoleTextAttribute(hConsole, 4);
                                printf("\nThe account with id: %d it is  activated!!",saveclient->id);
                    }
                }
                c=_getch();
                break;
            }
            case 1:{
                int k=0;char x[24];
                SetConsoleTextAttribute(hConsole, 11);
                printf("\nOld CNP: %s",saveclient->CNP);
                if(strcmp(newsave_client.CNP,"[")==0){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("\nEnter your NEW CNP: ");
                    scanf("%s",newsave_client.CNP);
                    if(check_CNP(newsave_client.CNP)!=0){SetConsoleTextAttribute(hConsole, 4);printf("Invalid CNP!!!");strcpy(newsave_client.CNP,"[");}
                        else {SetConsoleTextAttribute(hConsole, 2);printf("Valid CNP!!!");}
                }
                else  {
                        SetConsoleTextAttribute(hConsole, 13);
                        printf("\nNew CNP: %s",newsave_client.CNP);
                        SetConsoleTextAttribute(hConsole, 7);
                        printf("\nTap \"seria\" if you want to change the CNP: ");
                        scanf("%s",x);
                        if(strcmp(x,"seria")==0){
                            SetConsoleTextAttribute(hConsole, 12);
                            printf("\nEnter your NEW CNP: ");
                            scanf("%s",newsave_client.CNP);
                            if(check_CNP(newsave_client.CNP)!=0){SetConsoleTextAttribute(hConsole, 4);printf("Invalid CNP!!!");strcpy(newsave_client.CNP,"[");}
                                else {SetConsoleTextAttribute(hConsole, 2);printf("Valid CNP!!!");}
                        }
                    }
                c=_getch();
                break;
            }
            case 2:{
                int k=0;char x[24];
                SetConsoleTextAttribute(hConsole, 11);
                printf("\nOld Seria: %s",saveclient->Seria);
                if(strcmp(newsave_client.Seria,"[")==0){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("\nEnter your NEW Seria: ");
                    scanf("%s",newsave_client.Seria);
                    if(check_SERIA(newsave_client.Seria)!=0){SetConsoleTextAttribute(hConsole, 4);printf("Invalid Seria!!!");strcpy(newsave_client.Seria,"[");}
                        else {SetConsoleTextAttribute(hConsole, 2);printf("Valid Seria!!!");strcpy(newsave_client.Seria,toupper(newsave_client.Seria));}
                }
                else  {
                        SetConsoleTextAttribute(hConsole, 13);
                        printf("\nNew Seria: %s",newsave_client.Seria);
                        SetConsoleTextAttribute(hConsole, 7);
                        printf("\nTap \"seria\" if you want to change the Seria: ");
                        scanf("%s",x);
                        if(strcmp(x,"seria")==0){
                            SetConsoleTextAttribute(hConsole, 12);
                            printf("\nEnter your NEW Seria: ");
                            scanf("%s",newsave_client.Seria);
                            if(check_SERIA(newsave_client.Seria)!=0){SetConsoleTextAttribute(hConsole, 4);printf("Invalid Seria!!!");strcpy(newsave_client.Seria,"[");}
                                else {SetConsoleTextAttribute(hConsole, 2);printf("Valid Seria!!!");strcpy(newsave_client.Seria,toupper(newsave_client.Seria));}
                        }
                    }
                c=_getch();
                break;
            }
            case 3:{
                char x[24];
                SetConsoleTextAttribute(hConsole, 11);
                printf("\nOld NR: %s",saveclient->NR);
                if(strcmp(newsave_client.NR,"[")==0){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("\nEnter your NEW NR: ");
                    scanf("%s",newsave_client.NR);
                    if(check_NR(newsave_client.NR)!=0){SetConsoleTextAttribute(hConsole, 4);printf("Invalid NR!!!");strcpy(newsave_client.NR,"[");}
                        else {SetConsoleTextAttribute(hConsole, 2);printf("Valid NR!!!");}
                }
                else  {
                        SetConsoleTextAttribute(hConsole, 13);
                        printf("\nNew NR: %s",newsave_client.NR);
                        SetConsoleTextAttribute(hConsole, 7);
                        printf("\nTap \"nr\" if you want to change the NR: ");
                        scanf("%s",x);
                        if(strcmp(x,"nr")==0){
                            SetConsoleTextAttribute(hConsole, 12);
                            printf("\nEnter your NEW NR: ");
                            scanf("%s",newsave_client.NR);
                            if(check_NR(newsave_client.NR)!=0){SetConsoleTextAttribute(hConsole, 4);printf("Invalid NR!!!");strcpy(newsave_client.NR,"[");}
                                else {SetConsoleTextAttribute(hConsole, 2);printf("Valid NR!!!");}
                        }
                    }
                c=_getch();
                break;
            }
            case 4:{
                char x[24];
                SetConsoleTextAttribute(hConsole, 11);
                printf("\nOld First Name: %s",saveclient->first_name);
                if(strcmp(newsave_client.first_name,"[")==0){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("\nEnter your NEW First Name: ");
                    scanf("%s",newsave_client.first_name);
                    SetConsoleTextAttribute(hConsole, 2);printf("Valid First Name!!!");
                }
                else  {
                        SetConsoleTextAttribute(hConsole, 13);
                        printf("\nNew First Name: %s",newsave_client.first_name);
                        SetConsoleTextAttribute(hConsole, 7);
                        printf("\nTap \"first\" if you want to change the First Name: ");
                        scanf("%s",x);
                        if(strcmp(x,"first")==0){
                            SetConsoleTextAttribute(hConsole, 12);
                            printf("\nEnter your NEW First Name: ");
                            scanf("%s",newsave_client.first_name);
                            SetConsoleTextAttribute(hConsole, 2);printf("Valid First Name!!!");
                        }
                    }

                c=_getch();
                break;
            }
            case 5:{
                char x[24];
                SetConsoleTextAttribute(hConsole, 11);
                printf("\nOld Last Name: %s",saveclient->last_name);
                if(strcmp(newsave_client.last_name,"[")==0){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("\nEnter your NEW Last Name: ");
                    fflush(stdin);
                    scanf("%[^\n]",newsave_client.last_name);
                    SetConsoleTextAttribute(hConsole, 2);printf("Valid Last Name!!!");
                }
                else  {
                        SetConsoleTextAttribute(hConsole, 13);
                        printf("\nNew Last Name: %s",newsave_client.last_name);
                        SetConsoleTextAttribute(hConsole, 7);
                        printf("\nTap \"last\" if you want to change the Last Name: ");
                        scanf("%s",x);
                        if(strcmp(x,"last")==0){
                            SetConsoleTextAttribute(hConsole, 12);
                            printf("\nEnter your NEW Last Name: ");
                            fflush(stdin);
                            scanf("%[^\n]",newsave_client.last_name);
                            SetConsoleTextAttribute(hConsole, 2);printf("Valid Last Name!!!");
                        }
                    }

                c=_getch();
                break;
            }
            case 6:{
                char x[24];
                SetConsoleTextAttribute(hConsole, 11);
                printf("\nOld Addres: %s",saveclient->addres);
                fflush(stdin);
                if(strcmp(newsave_client.addres,"[")==0){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("\nEnter your NEW Addres: ");
                    scanf("%[^\n]",newsave_client.addres);
                    SetConsoleTextAttribute(hConsole, 2);printf("Valid Addres!!!");
                }
                else  {
                        SetConsoleTextAttribute(hConsole, 13);
                        printf("\nNew Last Name: %s",newsave_client.addres);
                        SetConsoleTextAttribute(hConsole, 7);
                        printf("\nTap \"addres\" if you want to change the Addres: ");
                        scanf("%s",x);
                        if(strcmp(x,"addres")==0){
                            SetConsoleTextAttribute(hConsole, 12);
                            printf("\nEnter your NEW Addres: ");
                            fflush(stdin);
                            scanf("%[^\n]",newsave_client.addres);
                            SetConsoleTextAttribute(hConsole, 2);printf("Valid Addres!!!");
                        }
                    }
                c=_getch();
                break;
            }
            case 7:{
                if(newsave_client.id!=0)saveclient->id=newsave_client.id;
                if(strcmp(newsave_client.CNP,"[")!=0)strcpy(saveclient->CNP,newsave_client.CNP);
                if(strcmp(newsave_client.NR,"[")!=0)strcpy(saveclient->NR,newsave_client.NR);
                if(strcmp(newsave_client.Seria,"[")!=0)strcpy(saveclient->Seria,newsave_client.Seria);
                if(strcmp(newsave_client.first_name,"[")!=0)strcpy(saveclient->first_name,newsave_client.first_name);
                if(strcmp(newsave_client.last_name,"[")!=0)strcpy(saveclient->last_name,newsave_client.last_name);
                if(strcmp(newsave_client.addres,"[")!=0)strcpy(saveclient->addres,newsave_client.addres);
                return 0;
                c=_getch();
                break;
            }
        }
        system("CLS");
    }
    while(o!=nsave-1||(int)c!=13);

return 0;
}


int search_client(Identity_card *clientlist,int ID,int id){
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int i;
    for( i = 0;i < ID;i++ ){
        if(id==abs((clientlist+i)->id)){

            SetConsoleTextAttribute(hConsole, 9);
            printf("\n\tid: %d\n",(clientlist+i)->id);
            printf("  \tCNP:%s\n",(clientlist+i)->CNP);
            printf("\tSeria: %s\n",(clientlist+i)->Seria);
            printf("\tNr: %s\n",(clientlist+i)->NR);
            printf("\tFitst name: %s\n",(clientlist+i)->first_name);
            printf("\tLast name: %s\n",(clientlist+i)->last_name);
            printf("\tAddres: %s\n",(clientlist+i)->addres);
            SetConsoleTextAttribute(hConsole, 6);
            printf("\n\t\tPress anything to continue!:)");
            _getch();
            system("cls");
            saving_data((clientlist+i));
            return 1;
        }

    }
return 0;
}

int function_modifyclient(){
    int ID=0;
    Identity_card *clientlist=NULL;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    FILE *client_data=fopen("client_data.txt","a+");
    if( client_data==NULL){printf("FILE Error!");exit(1);}

    //citire file
    char buff[5];
    fscanf(client_data,"%d",&ID);
    clientlist=(Identity_card*)malloc(ID*sizeof(Identity_card));
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

    int k=0,id;char x;

    printf("\n\n\tPlease enter the client-id:");
    fflush(stdin);
    scanf("%d",&id);

    if(search_client(clientlist,ID,id)==0){SetConsoleTextAttribute(hConsole, 4);printf("\n\t\t INVALID id!!!");return 0;}

    FILE *writeclient_data=fopen("client_data.txt","w");
    fprintf(writeclient_data,"%d\n",ID);
     for(i=0;i<ID;i++){
        fprintf(writeclient_data,"%d ",(clientlist+i)->id);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->CNP);
        fprintf(writeclient_data,"%s ",(clientlist+i)->Seria);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->NR);
        fprintf(writeclient_data,"%s ",(clientlist+i)->first_name);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->last_name);
        fprintf(writeclient_data,"%s\n",(clientlist+i)->addres);
     }
    fclose(client_data);
    free(clientlist);
return 1;
}
