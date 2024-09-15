#include <stdio.h>

#include "User.h"
#include "User_Mode.h"

#include "Admin.h"
#include "Slots.h"

/*void UserMode() {
    int choice;

    while (1) {
        printf("\nUser Mode Menu:\n");
        printf("1. View Patient Record\n");
        printf("2. View Today's Reservations\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ViewPatientRecord();
                break;
            case 2:
                ViewTodayReservations();
                break;
            case 3:
                printf("Exiting User Mode.\n");
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
*/

extern int exitProgram;
void UserMode() {
    int choice;
    int exitUserMode = 0;

    while (!exitUserMode && !exitProgram) {
        printf("\nUser Mode Menu:\n");
        printf("1. View Patient Record\n");
        printf("2. View Today's Reservations\n");
        printf("3. Exit User Mode\n");
        printf("4. Exit the system\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ViewPatientRecord();
                break;
            case 2:
                ViewTodayReservations();
                break;
            case 3:
                printf("Exiting User Mode.\n");
                exitUserMode = 1;
                break;
            case 4:
                printf("Exiting the system.\n");
                exitProgram = 1;
                exitUserMode = 1;
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
