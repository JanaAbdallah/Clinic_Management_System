#include <stdio.h>
#include "Slots.h"
#include "Admin_Mode.h"
#include "User_Mode.h"
#include "printModeMenu.h"
    
// Global flag to exit the entire program    
int exitProgram=0;


int main() {
    int choice;

    while (!exitProgram) {
        
        printModeMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AdminMode();
                break;
            case 2:
                UserMode();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}


