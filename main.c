#include <stdio.h>
#include <stdlib.h>
#include "robbers_head.h"
#include <windows.h>
#include <string.h>
#include <graphics.h>
#include <math.h>
void menu(int c)
{

    switch(c)
    {
    case 1:
        f1();
        break;
    case 2:
        f2();
        break;
    case 3:
        f3();
        break;
    case 4:
        f4();
        break;
    case 5:
        f5();
        break;
    case 6:
        f6();
        break;
    case 7:
        f7();
        break;
    case 8:
        f8();
        break;
    }
    scanf("%d",&c);
    if(c==9)return;
    else menu(c);
}
void print_menu() {
    printf("What do you want to do?\n");
    printf("1. All to list\n");
    printf("2. Show actually list\n");
    printf("3. Live guys\n");
    printf("4. Show the richest robber\n");
    printf("5. Mark to murdered\n");
    printf("6. Add new robber\n");
    printf("7. Infa by name\n");
    printf("8. Grafica\n");
}
void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    create();
    print_menu();
    int a;
    scanf("%d",&a);
    menu(a);

}
