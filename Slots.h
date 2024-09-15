
#ifndef SLOT_H
#define SLOT_H 

#include"Admin.h"

#define TOTAL_SLOTS 5

typedef struct {
    int slotNumber;
    char time[20];
    int isAvailable;
    int patientID;
} Slot;

extern Slot slots[TOTAL_SLOTS];
extern Node *Head;

void DisplayAvailableSlots();

#endif
