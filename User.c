#include <stdio.h>
#include <string.h>
#include"User.h"
#include"Admin.h"
#include"Slots.h"

void ViewPatientRecord(){
	int Patient_id ;
	int found =0 ;

	printf("Enter you ID \n");
	scanf("%d",&Patient_id);

	Node *temp=Head ;

	while(temp!=NULL){

		if(temp->P.ID==Patient_id){
            printf("Name  : %s\n", temp->P.Name);
            printf("Age   : %d\n", temp->P.Age);
            printf("Gender: %c\n", temp->P.Gender);
            found = 1 ;
            break;
		}

		temp=temp->next;
	}

	if(!found){
		printf("this ID doesn't exist!");
	}
}

void ViewTodayReservations(){ 
    int i ;
    printf("All Reservations \n");
	for(i=0 ; i<5 ; i++){
		if(!slots[i].isAvailable)
			printf("-> %s & Patient ID -> %d \n",slots[i].time,slots[i].patientID);
	}
}