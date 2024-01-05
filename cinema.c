#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    char name[20];
    char type[10];
    char class[20];
    char lang[20];
    int age;
    char rno;
    int sno;
    int audi;
    int tot;
}tick;
void showElevator();

void input(tick*,int);
void calc(tick*,int);
void disp(tick*,int);
int startCinema() {
    printf("********************--------------*******************\n");
    printf("     *****___WELCOME TO DHINCHAK CINEMAS___*****\n     This is Aaradhya,how may i help you??\n");
    printf("))))))))Movies listed on the big banner are((((((((((\n");
    printf("Notimetodie\nSpectre\nSkyfall\nCasinoRoyale\n");
    printf("             How many tickets do you want\n");
    int n,g;
    scanf("%d", &n);
    tick cin[n];
    while(1) {
        input(cin, n);
        calc(cin, n);
        disp(cin, n);
        printf("eneter 1 TO EXIT\n");
        scanf("%d",&g);
        if(g==1)
            break;
    }
    printf("@@@@@@@@@@@@@@@@__Hope you had a great experience__@@@@@@@@@@@@@@@@\nsssssssh don't lose this ticket,you can save 20 percent on your next booking\nuse code-%d\n",rand());
    showElevator();
    return 0;
}
void input(tick* cin,int n){
    int i;
    for(i=0;i<n;i++)
    {
       printf("Dear customer,please enter movie name,class(platinum/gold/silver),movie languageenglish/hindi),movie type(2d/3d/4d)(da-4d,db-3D,dc-2D) and your age\n");
       scanf("%s%s%s%s%d",cin[i].name,cin[i].class,cin[i].lang,cin[i].type,&cin[i].age);
    }
}
void calc(tick* cin,int n) {
    int bs, i, p = 1, g = 1, s = 1;
    char s1[] = "platinum";
    char s2[] = "gold";
    char s3[] = "silver";
    char m1[] = "notimetodie";
    char m2[] = "spectre";
    char m3[] = "skyfall";
    char m4[] = "casinoroyale";
    char t1[] = "da";
    char t2[] = "db";
    char t3[] = "dc";
    char l1[]="english";
    for (i = 0; i < n; i++) {
        bs = 250;
        if (cin[i].age > 5)
        {
                if ((strcmp(cin[i].name, m1)) <= 0) {
                    bs += 100;
                    cin[i].audi = 1;
                } else if ((strcmp(cin[i].name, m2)) <= 0) {
                    bs += 80;
                    cin[i].audi = 2;
                } else if ((strcmp(cin[i].name, m3)) <= 0) {
                    cin[i].audi = 3;
                    bs += 60;
                } else {
                    cin[i].audi = 4;
                    bs += 40;
                 }
                if ((strcmp(cin[i].lang,l1)<= 0))
                {
                    bs += 50;
                } else {
                    bs += 20;
                }

                if ((strcmp(cin[i].class, s1)) <= 0) {
                    bs += 100;
                    cin[i].rno = 'P';
                    cin[i].sno = p;
                    p++;
                } else if ((strcmp(cin[i].class, s2)) <= 0) {
                    bs += 50;
                    cin[i].rno = 'G';
                    cin[i].sno = g;
                    g++;
                } else {
                    bs += 10;
                    cin[i].rno = 'S';
                    cin[i].sno = s;
                    s++;

            }
        if (((strcmp(cin[i].type, t1))<=0))
        { bs += 80; }
        else if ((strcmp(cin[i].type, t2))<=0)
        { bs += 50;
            }
        else
        { bs += 20;
            }
        cin[i].tot = bs;
        }

        else
            cin[i].tot=bs;
    }
}
void disp(tick* cin,int n)
{
    int i;
    FILE* fp1;
    fp1=fopen("logbook.txt","w");
        for(i=0;i<n;i++) {
            if (cin[i].age > 5)
                printf("\n|MOVIE NAME---%s          |\n|LANGUAGE---%s          |\n|CLASS---%s       |\n|AUDI---%d    |\n|SEAT NUMBER---%c%d    |\n|GRAND TOTAL---%d    |\t    |",cin[i].name, cin[i].lang, cin[i].class, cin[i].audi, cin[i].rno, cin[i].sno, cin[i].tot);
            else
                printf("\n|MOVIE NAME---%s    |\t|LANGUAGE---%s    |\t|CLASS---%s    |\t|AUDI---%d    |\t|GRAND TOTAL---%d    |\t    |", cin[i].name,cin[i].lang, cin[i].class, cin[i].audi, cin[i].tot);
        }
        for(i=0;i<n;i++)
        {
            fprintf(fp1, "%s\n%s\n%s\n%s\n%d\n%d\n\n", cin[i].name, cin[i].lang, cin[i].class, cin[i].type, cin[i].age,cin[i].tot);
        }
    fclose(fp1);
}