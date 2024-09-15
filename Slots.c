// Slot.c

#include <stdio.h>
#include "Slots.h"

Slot slots[TOTAL_SLOTS] = {
    {1, "2:00 PM - 2:30 PM", 1, -1},
    {2, "2:30 PM - 3:00 PM", 1, -1},
    {3, "3:00 PM - 3:30 PM", 1, -1},
    {4, "4:00 PM - 4:30 PM", 1, -1},
    {5, "4:30 PM - 5:00 PM", 1, -1}
};
//Node *Head=NULL ;

void DisplayAvailableSlots() {
    printf("Available Slots:\n");
    for (int i = 0; i < TOTAL_SLOTS; i++) {
        if (slots[i].isAvailable) {
            printf("Slot %d: %s\n", slots[i].slotNumber, slots[i].time);
        }
    }
}
