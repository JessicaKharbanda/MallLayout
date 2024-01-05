#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function 
int getFloorFromParking();
void startParking();
void startArcadeGame();

// Functions By Jessica
int startFoodCourt();

//Functions By Aaradhys
int startCinema();

//function by Samarth
void startGrocery();
void showElevator();
void showFloorShops();


//Global Variables
int cf=0;
char name[]="Inf1n1ty";
char *floors[]={"Parking 2","Parking 1","Ground Floor","First Floor","Second Floor","Third Floor"};
char vc;
void main()
{
    vc='N';//Default vehicle choice is N (No)
    printf("Welcome to %s Mall\nAre you on a vehicle(Y/N) : ",name);
    scanf(" %c",&vc);  
    printf("\n");
    if(vc != 'N' && vc != 'n') {
        startParking();
        cf=getFloorFromParking();    
    }
    showElevator();
}
void showFloorShops(){
    switch(cf){
        case -2:
        startParking();
        break;
        case -1:
        startParking();
        break;
        case 0:{
            startGrocery();
            break;
        }           
        case 1:
            printf("Shops in this area are under maintenance\n");
            showElevator();
            break;
        case 2: {
            int choice=0;
            printf("Where do you want to go \n1.Arcade \n2.Food Court\n");
            scanf("%d",&choice);
            switch (choice)
            {
                case 1:
                    startArcadeGame();
                break;
                case 2:
                    startFoodCourt();
                break;
                default:
                printf("Wrong Choice\n");
                break;
            }
            break;
        }
        case 3:
            startCinema();
            break;          
    }
}

void showElevator(){
    int input=0;
    printf("What floor do you want to go?\n");
    printf("Available options: \n");
    for(int x=(vc=='Y' || vc == 'y')?0:2;x<6;x++){
        printf("%s -> %d\n",floors[x],(x-2));            
    }
    if(vc=='Y' || vc == 'y'){
        printf("Enter Your Choice: ");
    }
    else{
        printf("Enter Your Choice(-1 means terminate): ");
    }
    scanf("\n%d",&input);
    if(input == -1 && !(vc=='Y' || vc == 'y')){
        printf("Visit Us Again!");
        return;
    }
    printf("\n");
    cf=input;
    showFloorShops();
}

