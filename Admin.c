#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Admin.h"
#include"Slots.h"

#define Password "1234"
#define maxtrails  3

Node *Head=NULL;

int CheckPassword(){
	char password[10];
	int trails=0;

	while(maxtrails>trails){

		printf("Enter your password ");
		scanf("%s",password);

		if (strcmp(password, Password) == 0) {
            return 1;
        }
		else {
			trails++;
			printf("Incorect Password. Attempts left: %d\n",maxtrails-trails);
		}
	}
	return 0 ;
}

int CheckID(int ID){
   Node * temp = Head ;
   while(temp!=NULL){
   	if(ID==temp->P.ID){
   		return 1;
   	}
   	temp=temp->next ;
   }
   return 0 ;
}

Node * AddNewPatient(){
	 Node * NewNode = (Node*)malloc(sizeof(Node));

     printf("Enter The Patient ID \n");
     scanf("%d",&NewNode->P.ID);
     fflush(stdin);

     if(CheckID(NewNode->P.ID)==1){
     	printf("This User is already exist,Rejected");
        free(NewNode); 
        return NULL;
     }

     printf("Enter Patient Name \n");
     scanf(" %[^\n]",NewNode->P.Name);
     fflush(stdin);

     printf("Enter Patient Age \n");
     scanf("%d",&NewNode->P.Age);
     fflush(stdin);

     printf("Enter Patient Gender (M/F) \n");
     scanf("%c", &NewNode->P.Gender);
     fflush(stdin);
     
     NewNode->next=NULL;

     if(Head==NULL){
     	Head=NewNode ;
     }

     else {
     	 Node *temp = Head ;

     	 while(temp->next!=NULL){
              temp=temp->next;
     	 }

     	 temp->next=NewNode;

     }
     

     return NewNode ;
 }

void EditPatientInfo() {
    int id;
    int edit;

    printf("Enter the Patient ID: \n");
    scanf("%d", &id);

    Node *temp = Head;

    while (temp != NULL) {
        if (id == temp->P.ID) {
            printf("Patient Name  : %s\n", temp->P.Name);
            printf("Patient Age   : %d\n", temp->P.Age);
            printf("Patient Gender: %c\n", temp->P.Gender);
            printf("\nTo edit Name   press 1\nTo edit Age    press 2\nTo edit Gender press 3\n");
            scanf("%d", &edit);

            switch (edit) {
                case 1:
                    printf("Enter the new Name: \n");
                    scanf(" %[^\n]", temp->P.Name);
                    break;
                case 2:
                    printf("Enter the new Age: \n");
                    scanf("%d", &temp->P.Age);
                    break;
                case 3:
                    printf("Enter the new Gender: \n");
                    scanf(" %c", &temp->P.Gender);
                    break;
                default:
                    printf("Invalid option\n");
                    break;
            }
            return;  
        }
        temp = temp->next;
    }
    printf("Patient not found.\n");
}

void Reserve_A_Slot_With_Dr() {  
    int id;
    int chosenSlot;
    Node *temp = Head;

    printf("Enter Patient ID: \n");
    scanf("%d", &id);

    while (temp != NULL) {
        if (id == temp->P.ID) {
            DisplayAvailableSlots();

            printf("Enter the Slot Number you want to reserve: ");
            scanf("%d", &chosenSlot);

            if (chosenSlot < 1 || chosenSlot > TOTAL_SLOTS) {
                printf("Invalid Slot Number\n");
                return;
            }

            if (!slots[chosenSlot - 1].isAvailable) {
                printf("Slot %d is already reserved.\n", chosenSlot);
                return;
            }

            // Reserve the slot
            slots[chosenSlot - 1].isAvailable = 0;
            slots[chosenSlot - 1].patientID = id;

            printf("Slot %d reserved successfully for Patient ID %d.\n", chosenSlot, id);
            return;
        }
        temp = temp->next;
    }

    printf("Patient ID not found.\n");
}

void Cancel_Reservation(){
     int id ;
     int i ;
     int found = 0 ;

     printf("Enter patient ID : \n");
     scanf("%d",&id);

     for(i = 0 ; i<5 ; i++){
     	if(slots[i].patientID==id){
     		slots[i].isAvailable=1;
     		slots[i].patientID=-1;
     		found =1 ;
            break;
     	}
     }

      if (found) {
        printf("Slot has been cancelled successfully.\n");
    } else {
        printf("No reservation found for the given patient ID.\n");
    }
  
}
