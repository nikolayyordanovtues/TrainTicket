#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int freeSeats[49];
    char destination[30];

    printf("Hello! Welcome to the train station!\n\n");

    printf("Please enter the destination the train is going to: ");
    scanf("%s", destination);
    printf("\n");

    for(int i = 0; i < 50; i++) {
        //variables
        int age;
        char name[30];
        char isStudentOrRetired[1];
        char coupe[10];
        int desiredNumOfTickets;
        int finalPrice = 0;
        int ticketPrice = 20;
        int totalDiscount = 0;
        //input how many tickets does the passenger want
        printf("How many tickets does the passenger want: ");
        scanf("%d", &desiredNumOfTickets);
        finalPrice = finalPrice + ticketPrice*desiredNumOfTickets;
        //input: name
        printf("Please enter the name of the passenger (firstName-lastName): ");
        scanf("%s", name);
        //input: age
        printf("How old is the passenger: ");
        scanf("%d", &age);
        //input: is the passenger a student or retired
        printf("Is the passenger a student or retired (y/n): ");
        scanf("%s", isStudentOrRetired);
        //input: the type of coupe
        printf("What kind of coupe does the passenger want (sleep/regular): ");
        scanf("%s", coupe);
        //input: seat indexes && validation
        printOccupiedSeats(freeSeats);
        for(int j = 0; j < desiredNumOfTickets; j++) {
            printf("Enter the desired seat for ticket %d: ", j + 1);
            int seat;
            scanf("%d", &seat);
            if(freeSeats[seat - 1] == 1) {
                j--;
                printf("Please choose an unoccupied seat: ");
                scanf("%d", &seat);\
                if(freeSeats[seat - 1] != 1) {
                    j++;
                }
            }
            else if(seat < 1 || seat > 50)
            {
                j--;
                printf("Please choose a valid seat (1-50): ");
                scanf("%d", &seat);
                if(seat >= 1 && seat <= 50)
                {
                    j++;
                }
            }
            else
            {
                freeSeats[seat - 1] = 1;
            }
        }
        //print receipt
        printReceipt();
        //check if there are more customers after the current one
        char moreCustomers[1];
        printf("Are there any more customers (y/n): ");
        scanf("%s", moreCustomers);
        if(strcmp(moreCustomers, "n") == 0)
        {
            break;
        }
    }
    return 0;
}

void printOccupiedSeats(int freeSeats[49]) {
    printf("Occupied seats: ");
    for(int i = 0; i < 50; i++) {
        if(freeSeats[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

void printReceipt() {
}

