#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int getRandomNumber(int lower, int upper);
void confirmTicket();
void showElevator();

int istw=0; //is to wheeler boolean kind of variable to save memory as it was save only 0 or 1
int ticketId=0;
short s=0;
void startParking(){    
    if(!ticketId){
        float tp;//Ticket price
        printf("Hey There! Welcome to Parking Lot\n Enter your vehicle details\n");
        printf("1.Two-Wheeler\n");
        printf("2. Four-Wheeler\n");
        scanf("%d",&istw);
        if(istw == 1){
            tp=30;
        }
        else{
            tp=50;
        }        
        srand(time(NULL)); //seeding time
        ticketId=getRandomNumber(10000,999999);
        printf("Your Ticket id is %d\n Total : Rs.%f\n",ticketId,tp);
        printf("Save this ticket id to get back your %s\n",istw==1?"two-wheeler":"four wheeler");
    }
    else{
        //user has parked his/her vehicle
        confirmTicket();
    }
   
}
void confirmTicket(){
    int input=0;
    while(1){        
        printf("Enter your ticked id : ");
        scanf("%d",&input);
        if(input == ticketId){
            printf("Verification Successful\nYou can have your car now\nVisit us again!\n");
            break;
        }
        else if(input == -1){
            showElevator();
            break;
        }
        else if(input == -2){
            break;
        }
        else{
            printf("Verification Failed\nTry Again or input -1 to go to elevator or -2 to terminate\n");
        }
    }
    
}
int getFloorFromParking(){
    return istw?-1:-2;
}

void startArcadeGame(){
    int l=1, u=100;
    srand(time(NULL));          
    int number=getRandomNumber(l,u);
    int input=1;
    int max_chances=10;
    int chances=max_chances-1;
    printf("Welcome To GUESS THE NUMBER\n");
    printf("Game Commencing\n");
    printf("Enter a number in range %d-%d\n",l,u);
    while(input!=number || input != -1){
        printf("Number : ");
        scanf("%d",&input);
        printf("\n");
        if(input<number){
            printf("Secret Number is greater than your input\n");
            printf("Moves:(%d/%d)\n",chances,max_chances);
        }
        else if(number<input){
            printf("Secret Number is smaller than your input\n");
            printf(" Moves:(%d/%d)\n",chances,max_chances);        
        }
        else{
            printf("You Win!\n");
            break;
        }
        if(--chances == 0){
            printf("Game Over\n");
            break;
        }
    }
    showElevator();
}
int getRandomNumber(int lower, int upper)
{
    int num = (rand() %
           (upper - lower + 1)) + lower;
    return num;
}