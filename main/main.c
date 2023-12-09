
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "modifyclient.h"
#include "newclient.h"
#include "logintitlu.h"

#define no 5



int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int i=0,o=0,n;
    char c;
    char *a[no]= {"New Client","Modify Client","Delete Client","Payments","exit"};
    //  printf("%s",a[3]);
    // menu_cu(a[2]);

    if(login()==0)return 0;
        else system("CLS");

    do
    {
        titlu();
        for(int i=0; i<no; i++)
            if(i==o)    menu_cu(a[i]);
                else    menu_fara(a[i]);
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
                    o=no-1;
            else if(n==77)
                if(o<no-1)
                    o++;
                else
                    o=0;
        }
        if(c==13)
        switch(o){
            case 0:{
                if(function_newclient()==1){SetConsoleTextAttribute(hConsole, 2);printf("\t||The data was saved!||");}
                    else {SetConsoleTextAttribute(hConsole, 4);printf("\t||The data was lost, try again!||");}
                c=_getch();
                break;

            }
            case 1:{
                function_modifyclient();
                c=_getch();
                break;

            }
            case 2:{
                function_deleteclient();
                c=_getch();
                break;

            }
            case 3:{
                Payments();
                c=_getch();
                break;
            }
        }
        system("CLS");
    }
    while(o!=no-1||(int)c!=13);

    return 0;
}
void menu_cu(char *s)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 240);
    printf(" %s ",s);
}
void menu_fara(char *s)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 5);
    printf(" %s ",s);
}
