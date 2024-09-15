#include <stdio.h>
#include <stdlib.h>

#include "Admin_Mode.h"
#include "Admin.h"

#include "Slots.h"

void printMenu() {
    printf("\nAdmin Mode Menu:\n");
    printf("1. Add New Patient\n");
    printf("2. Edit Patient Info\n");
    printf("3. Reserve Slot\n");
    printf("4. Cancel Reservation\n");
    printf("5. Exit Admin Mode\n");
    printf("6. Exit the entire system\n");
    printf("Choose an option: ");
}

void initializeSystem() {
    slots[0] = (Slot){1, "2:00 AM - 2:30 AM", 1, -1};
    slots[1] = (Slot){2, "2:30 AM - 3:00 PM", 1, -1};
    slots[2] = (Slot){3, "3:00 PM - 3:30 PM", 1, -1};
    slots[3] = (Slot){4, "4:00 PM - 4:30 PM", 1, -1};
    slots[4] = (Slot){5, "4:30 PM - 5:00 PM", 1, -1};
    
    Head = NULL;
}
/*
void AdminMode() {
    int choice;

    initializeSystem();
    if (CheckPassword()) {
        printf("Password correct. Access granted.\n");
        while (1) {
            printMenu();
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    AddNewPatient();
                    break;
                case 2:
                    EditPatientInfo();
                    break;
                case 3:
                    Reserve_A_Slot_With_Dr();
                    break;
                case 4:
                    Cancel_Reservation();
                    break;
                case 5:
                    printf("Exiting Admin Mode.\n");
                    return;
                default:
                    printf("Invalid option. Please try again.\n");
            }
        }
    } else {
        printf("Access denied. Exiting...\n");
    }
}
*/
extern int exitProgram;

void AdminMode() {
    int choice;
    int exitAdminMode = 0;

    if (CheckPassword()) {
        printf("Password correct. Access granted.\n");
        while (!exitAdminMode && !exitProgram) {
            printMenu();
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    AddNewPatient();
                    break;
                case 2:
                    EditPatientInfo();
                    break;
                case 3:
                    Reserve_A_Slot_With_Dr();
                    break;
                case 4:
                    Cancel_Reservation();
                    break;
                case 5:
                    printf("Exiting Admin Mode.\n");
                    exitAdminMode = 1;
                    break;
                case 6:
                    printf("Exiting the system.\n");
                    exitProgram = 1;
                    exitAdminMode = 1;
                    break;
                default:
                    printf("Invalid option. Please try again.\n");
            }
        }
    } else {
        printf("Access denied. Exiting...\n");
    }
}
