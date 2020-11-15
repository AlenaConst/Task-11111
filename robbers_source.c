#include "robbers_head.h"
int number=7;
int i;
int w[7]= {0,0,0,0,0,0,0};
void create()
{
    FILE *fp,*fp1;
    fp=fopen("names.txt","r");
    fp1=fopen("alive.txt","r");
    for(i=0; i<number; i++)
    {
        fscanf(fp,"%s",R[i].name);
        fscanf(fp1,"%s",R[i].alive);
    }
    fclose(fp);
    fclose(fp1);
    for(i=0; i<number; i++)
    {
        R[i].horses=rand()%3;
        R[i].sabers=rand()%6;
        R[i].rubies=rand()%21;
        R[i].necklaces=rand()%11;
        R[i].wifes=rand()%3;
        R[i].coins=rand()%2501;
    }
    for(i=0; i<number; i++)
    {
        R[i].wealth=500*R[i].horses+ 100*R[i].sabers+ 50*R[i].rubies+10*R[i].necklaces+200*R[i].wifes+ R[i].coins;
    }
}
void f4()
{
    int max=R[0].wealth;
    for(i=0; i<number; i++)
    {
        if(R[i].alive[0]=='y'&&R[i].wealth>max)
        {
            max=R[i].wealth;
        }
    }
    for(i=0; i<number; i++)
    {
        if(R[i].wealth==max&&R[i].alive[0]=='y')printf("%10s %3s %1d %1d %2d %2d %1d %4d %4d\n ", R[i].name,R[i].alive, R[i].horses, R[i].sabers, R[i].rubies, R[i].necklaces, R[i].wifes, R[i].coins, R[i].wealth );
    }

}
void f2()
{
    for(i=0; i<number; i++)
    {
        printf("%10s %3s %1d %1d %2d %2d %1d %4d %4d\n ", R[i].name,R[i].alive, R[i].horses, R[i].sabers, R[i].rubies, R[i].necklaces, R[i].wifes, R[i].coins, R[i].wealth );
    }

}
void f1()
{
    int b[8];
    for(i=0; i<8; i++)b[i]=0;
    for(i=0; i<number; i++)
    {
        if(R[i].alive[0]=='y')b[0]++;
        b[1]+=R[i].horses;
        b[2]+=R[i].sabers;
        b[3]+=R[i].rubies;
        b[4]+=R[i].necklaces;
        b[5]+=R[i].wifes;
        b[6]+=R[i].coins;
        b[7]+=R[i].wealth;

    }

    printf("Итого %2d %1d %1d %2d %2d %1d %4d %4d\n ", b[0], b[1]+w[0],  b[2]+w[1],  b[3]+w[2],  b[4]+w[3],  b[5]+w[4],  b[6]+w[5],  b[7]+w[6]);

}
void f3()
{
    for(i=0; i<number; i++)
    {
        if(R[i].alive[0]=='y')printf("%10s %3s %1d %1d %2d %2d %1d %4d %4d\n ", R[i].name,R[i].alive, R[i].horses, R[i].sabers, R[i].rubies, R[i].necklaces, R[i].wifes, R[i].coins, R[i].wealth );
    }

}
void f5()
{
    char n[15];
    char n1[3]="no";
    gets(n);
    for(i=0; i<number; i++)
    {
        if(strcmp(R[i].name,n)==0&&R[i].alive[0]=='y')
        {
            w[0]=-R[i].horses;
            w[1]=-R[i].sabers;
            w[2]=-R[i].rubies;
            w[3]=-R[i].necklaces;
            w[4]=-R[i].wifes;
            w[5]=-R[i].coins;
            w[6]=-R[i].wealth;
            strcpy(R[i].alive,n1);
            break;
        }

    }

}
void f6()
{
    number=number+1;
    scanf("%s",&R[number-1].name);
    scanf("%s",&R[number-1].alive);
    scanf("%d %d %d %d %d %d", &R[number-1].horses, &R[number-1].sabers, &R[number-1].rubies, &R[number-1].necklaces, &R[number-1].wifes, &R[number-1].coins);
    R[number-1].wealth=500*R[number-1].horses+ 100*R[number-1].sabers+ 50*R[number-1].rubies+10*R[number-1].necklaces+200*R[number-1].wifes+ R[number-1].coins;

}
void f7()
{
    char n[15];
    scanf("%s",&n);
    for(i=0; i<number; i++)
    {
        if(strcmp(n,R[i].name)==0)printf("%10s %3s %1d %1d %2d %2d %1d %4d %4d\n ", R[i].name,R[i].alive, R[i].horses, R[i].sabers, R[i].rubies, R[i].necklaces, R[i].wifes, R[i].coins, R[i].wealth );
    }
}
void f8()
{
    int k=0;
    int gd=CUSTOM;
    int gm=CUSTOM_MODE(1500,1500);
    initgraph(&gd,&gm,"");
    for(i=0; i<number; i++)
    {
        if(R[i].alive[0]=='y')
        {
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            outtextxy(100+k*150,900,R[i].name);
            bar(100+k*150,800-R[i].wealth/8,200+k*150,870);
            k++;
        }
    }
    readkey();
    closegraph();
}
