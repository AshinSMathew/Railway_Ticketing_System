#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Reservation{
    char name[25];
    int rnum;
    struct Reservation* link;
};
struct WaitingList{
    char name[25];
    int wnum;
    struct WaitingList* link;
};

struct Reservation* headR=NULL;
struct WaitingList* headW=NULL;
int wn=1;

struct Reservation* create_Reservation(char name[]){
    struct Reservation *newnode=(struct Reservation*)malloc(sizeof(struct Reservation));
    strcpy(newnode->name, name);
    newnode->rnum=0;
    newnode->link=NULL;
    return newnode;
}
struct WaitingList* create_Waiting(char name[]){
    struct WaitingList *newnode=(struct WaitingList*)malloc(sizeof(struct WaitingList));
    strcpy(newnode->name, name);
    newnode->wnum=wn++;
    newnode->link=NULL;
    return newnode;
}

void Insert_Waiting(char name[]){
    struct WaitingList* temp=create_Waiting(name);
    if(headW==NULL){
        temp->link=headW;
	    headW=temp;
        printf("Waiting List Confirmed\n");
    }
    else{
        struct WaitingList* ptr=headW;
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=temp;
        printf("Waiting List Confirmed\n");
    }
}

int ResIsFull(){
    int count=1;
    struct Reservation* ptr=headR;
    while(ptr->link!=NULL){
        ptr=ptr->link;
        count++;
    }
    if(count>=5){
        return 0;
    }
    else{
        return 1;
    }
}

void Insert_Reservation(char name[]){
    struct Reservation* temp=create_Reservation(name);
    if(headR==NULL){
        temp->link=headR;
	    headR=temp;
        printf("Ticket Confirmed for %s\n",name);
    }
    else{
        struct Reservation* ptr=headR;
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        if(ResIsFull()){
            ptr->link=temp;
            printf("Ticket Confirmed for %s\n",name);
        }
        else{
            printf("Reservation Full\n");
            Insert_Waiting(name);
        }
    }
}

void Delete(char key[],int n){
    if(n==1){
        struct Reservation* ptr=headR;
        struct WaitingList* ptr1=headW;
        struct Reservation* temp=NULL;
        if(headR==NULL){
            printf("Reservation List is Empty");
            return;
        }
        else{
            while(ptr!=NULL && strcmp(ptr->name,key)!=0){
                temp=ptr;
                ptr=ptr->link;
            }
            if(ptr==NULL){
                printf("%s not found in Reservation List",key);
                return;
            }
            if(temp==NULL){
                headR=ptr->link;
            }
            else{
                temp->link=ptr->link;
            }
	        free(ptr);
            printf("%s deleted from Reservation List\n",key);
            if(headW!=NULL){
                Insert_Reservation(ptr1->name);
                Delete(ptr1->name,0);
            }
        }
    }
    else{
        struct WaitingList* ptr=headW;
        struct WaitingList* temp=NULL;
        if(headW==NULL){
            printf("Waiting List is Empty");
            return;
        }
        else{
            while(ptr!=NULL && strcmp(ptr->name,key)!=0){
                temp=ptr;
                ptr=ptr->link;
            }
            if(ptr==NULL){
                printf("%s not found in Waiting List",key);
                return;
            }
            if(temp==NULL){
                headW=ptr->link;
            }
            else{
                temp->link=ptr->link;
            }
            printf("%s deleted from Waiting List\n",key);
            free(ptr);
            int c=0;
            while(ptr!=NULL){
                ptr->wnum=c++;
                ptr=ptr->link;
            }
        }
    }
}

void display(int n){
    if(n==1){
        struct Reservation* ptr=headR;
        printf("\nReservation List\n");
        for(int i=100;i<105;i++){
            ptr->rnum=i;
            printf("%d %s\n",ptr->rnum,ptr->name);
		    ptr=ptr->link;
        }
    }
    else{
        struct WaitingList* ptr=headW;
        printf("\nWaiting List\n");
	    while(ptr!=NULL){
            if(headW==NULL){
                printf("Empty\n");
            }
		    printf("WL%d %s\n",ptr->wnum,ptr->name);
		    ptr=ptr->link;	
	    }
    }
}

int main(){
    int choice;
    char name1[25],name2[25],name3[25]; 
    printf("RAILWAY TICKETING SYSTEM\n");
    printf("\n\t1.BOOK A TICKET\n\t2.CANCEL RESERVATION TICKET\n\t3.DISPLAY RESERVATION LIST\n\t4.DISPLAY WAITING LIST\n\t5.CANCEL WAITING LIST TICKET\n\t6.EXIT\n");
    do{
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter name: ");
                scanf("%s",name1);
                Insert_Reservation(name1);
                break;
            case 2:
                printf("\nEnter name: ");
                scanf("%s",name2);
                Delete(name2,1);
                break;
            case 3:
                display(1);
                break;
            case 4:
                display(0);
                break;
            case 5:
                printf("\nEnter name: ");
                scanf("%s",name3);
                Delete(name3,0);
                break;
            case 6:
                printf("Exiting......");
                exit(0);
            default:
                printf("Invalid Input");
                break;
        }
    }while(choice!=6);
}