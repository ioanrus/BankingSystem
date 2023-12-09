#include "logintitlu.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void titlu(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 12);
  printf("  ############");
printf("\n  #");
SetConsoleTextAttribute(hConsole, 10);
    printf("$GreenBank");
SetConsoleTextAttribute(hConsole, 12);
printf("#");
printf("\n  ############\n");
}
typedef struct{
    char id[30],password[30];
}logare;
void switch_print(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 1);
printf("\nThis is the login menu.");
SetConsoleTextAttribute(hConsole, 9);
printf("\n1.Login\n2.Create account\n3.Exit");
SetConsoleTextAttribute(hConsole, 9);
SetConsoleTextAttribute(hConsole, 7);
printf("\nPress your choice: ");
}

int login_button(char *id_in,char *pas_in){

    FILE *pas=fopen("pass.txt","r");
    if( pas==NULL){printf("FILE Error!");exit(1);}
    logare *log;
    int log_number;
    log=(logare*)malloc(sizeof(logare)*log_number);
    fscanf(pas,"%d",&log_number);
    int i=0;
    for(i=0;i<log_number;i++){
    fscanf(pas,"%s %s",(log+i)->id,(log+i)->password);
    if(strcmp(id_in,(log+i)->id)==0 && strcmp(pas_in,(log+i)->password)==0){return 1;}
    }
    fclose(pas);
    free(log);
return 0;
}

int create_button(char *id_in,char *pas_in){

    FILE *pas=fopen("pass.txt","a+");
    if( pas==NULL){printf("FILE Error!");exit(1);}
    logare *log;
    int log_number;
    fscanf(pas,"%d",&log_number);
    log=(logare*)malloc(sizeof(logare)*log_number);
    int i=0;
    for(i=0;i<log_number;i++){
    fscanf(pas,"%s%s",(log+i)->id,(log+i)->password);
    }

    fclose(pas);

    log_number=log_number+1;

    FILE *pasw=fopen("pass.txt","w");
    if( pasw==NULL){printf("FILE Error!");exit(1);}
    fprintf(pasw,"%d",log_number);
    for(i=0;i<log_number-1;i++){
        fprintf(pasw,"\n%s %s",(log+i)->id,(log+i)->password);
    }
    fprintf(pasw,"\n%s %s",id_in,pas_in);

    fclose(pasw);
    free(log);
return 1;
}
int login(){
    char choice;

    char id_in[30],pas_in[30];
    while(choice!=3){
    titlu();
    switch_print();
    fflush(stdin);
    scanf("%c",&choice);

    switch (choice){
        case '1':{
            printf("\nEnter the id: ");
            fflush(stdin);
            scanf("%s",id_in);
            printf("\nEnter the password: ");
            scanf("%s",pas_in);
            if(login_button(id_in,pas_in)==1)return 1;
            break;
        }
        case '2':{
            printf("\nEnter the id: ");
            fflush(stdin);
            scanf("%s",id_in);
            printf("\nEnter the password: ");
            scanf("%s",pas_in);
            if(create_button(id_in,pas_in)==1)return 1;
            break;
        }
        case '3':{
            return 0;
        }
        default: printf("Error! choice is not correct");

    }
    _getch();
    system("CLS");
    }


return 1;
}
