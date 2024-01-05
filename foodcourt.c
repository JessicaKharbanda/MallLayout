#include <stdio.h>

struct order{
    char name[50];
    int number_of_fooditems;
    int cost;
}p[100];
int order_count = 0;
void showElevator();

void items();
void order ()
{
    int n, in, q;
    printf ("please enter your name: ");
    gets (p[order_count].name);
    items();
    p[order_count].number_of_fooditems = n;
    p[order_count].cost = 0;
    p[order_count].number_of_fooditems = 0;
    
    level:
    printf ("How many items do you wish to order? ");
    scanf ("%d", &n);

    getchar ();
    while (n--){
        printf ("\nEnter chosen item code\n");
        scanf ("%d", &in);
        getchar();
        switch(in){
    case 1 : {
        printf ("Please enter the quantity: ");
        scanf ("%d", &q);
        getchar();

        p[order_count].number_of_fooditems +=q;

        p[order_count].cost += (180*q);
        break;
    }
    case 2 :{
        printf ("Enter the size of Chicken Pizza: 1. regular  2. medium  3. large\n");
        int i;
        scanf ("%d", &i);
        getchar();

        printf ("Please enter the quantity: ");
        scanf ("%d", &q);
        getchar();

        p[order_count].number_of_fooditems +=q;

        if (i==1) p[order_count].cost += (750*q);

        else if (i==2) p[order_count].cost += (975*q);

        else  p[order_count].cost += (1250*q);

        break;
    }
    case 3 :{
        printf ("Enter the amount of chicken: 1. 1 pcs  2. 4 pcs  3. 10 pcs\n");
        int i;
        scanf ("%d", &i);
        getchar();

        printf ("Please enter the quantity: ");
        scanf ("%d", &q);
        getchar();

        p[order_count].number_of_fooditems +=q;

        if (i==1) p[order_count].cost += (85*q);

        else if (i==2) p[order_count].cost += (320*q);

        else  p[order_count].cost += (790*q);

        break;
    }
    case 4 :{
        printf ("Enter the size of grilled chicken: 1. quarter  2. half  3. full\n");
        int i;
        scanf ("%d", &i);
        getchar();

        printf ("Please enter the quantity: ");
        scanf ("%d", &q);
        getchar();

        p[order_count].number_of_fooditems +=q;

        if (i==1) p[order_count].cost += (70*q);

        else if (i==2) p[order_count].cost += (140*q);

        else  p[order_count].cost += (250*q);

        break;
    }
    case 5 :{
        printf ("Enter the size of Noodles: 1. half  2. full\n");
        int i;
        scanf ("%d", &i);
        getchar();

        printf ("Please enter the quantity: ");
        scanf ("%d", &q);
        getchar();

        p[order_count].number_of_fooditems +=q;

        if (i==1) p[order_count].cost += (130*q);

        else p[order_count].cost += (250*q);

        break;
    }
    case 6 :{
        printf ("Please enter the quantity: ");
        scanf ("%d", &q);
        getchar();

        p[order_count].number_of_fooditems +=q;

        p[order_count].cost += (240*q);

        break;
    }
    case 7 : {
        printf ("Please enter the quantity: ");
        scanf ("%d", &q);
        getchar();

        p[order_count].number_of_fooditems +=q;
        p[order_count].cost += (180*q);
        break;
    }
    case 8 : {
        printf ("Please enter the quantity: ");
        scanf ("%d", &q);
        getchar();

        p[order_count].number_of_fooditems +=q;
        p[order_count].cost += (65*q);
        break;
    }
    case 9 : {
        printf ("Please enter the quantity: ");
        scanf ("%d", &q);
        getchar();

        p[order_count].number_of_fooditems +=q;
        p[order_count].cost += (70*q);
        break;
    }
    case 10 :{
        printf ("Please enter the quantity: ");
        scanf ("%d", &q);
        getchar();

        p[order_count].number_of_fooditems +=q;

        p[order_count].cost += (30*q);
        break;
    }
    default : {
        printf ("Invalid selection try again\n");
        n++;
    }
        }
    }
    char temp;
    printf ("Do you want to order anything else?(y/n)\n ");
    scanf("%c", &temp);
    if (temp == 'y' || temp == 'Y')
        goto level;
    printf ("\nThank you %s for your order. Your bill is %d.\nPlease wait while we prepare the food.\n\n", p[order_count].name, p[order_count].cost);
    order_count++;
}

void items ()
{
    printf("..................................MENU....................................\n");

    printf("Item Code    Description-------------------Size--------------------Price\n");

    printf("(1)----------Cheeseburger---------------standard-------------------180\n");
    printf("(2)----------Chicken Pizza--------------reg/med/large--------------750/975/1250\n");
    printf("(3)----------Fried Chicken--------------1/4/10 pcs-----------------85/320/790\n");
    printf("(4)----------Grilled Chicken------------quarter/half/full----------70/140/250\n");
    printf("(5)----------Noodles--------------------Half/Full------------------130/250\n");
    printf("(6)----------Pasta----------------------standard-------------------240\n");
    printf("(7)----------Oreo Shake-----------------standard-------------------180\n");
    printf("(8)----------Cold Coffee----------------standard-------------------65\n");
    printf("(9)----------Cappuccino-----------------standard-------------------70\n");
    printf("(10)---------Coke-----------------------standard-------------------30\n\n");

}
int startFoodCourt ()
{
    printf ("\t\t     Welcome To food corner\n");
    while (1){
        printf ("1. Order\n2. Exit the program\n");

        int in;
        scanf ("%d", &in);
        getchar ();
        switch (in){
            case 1 : {
                order ();
                break;
            }
            case 2 : {
                printf("\tThankyou!\n\tCome by again!");
                showElevator();
                return 0;
            }
        }
    }
}    



