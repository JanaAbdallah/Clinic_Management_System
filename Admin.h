#ifndef AdminMode_1
#define AdminMode_1


typedef struct {
	char Name[100];
    int Age ;
    char Gender;
    int ID;
} Patient ;

typedef struct Node {
    Patient P ;
    struct Node *next ;
}Node; 

extern Node *Head ;

int CheckPassword();
int CheckID(int id);
Node * AddNewPatient();
void EditPatientInfo();
void Reserve_A_Slot_With_Dr();
void Cancel_Reservation();

#endif