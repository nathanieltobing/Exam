#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"

Node *createNode(Data biodata) {
  Node *temp = (Node*)malloc(sizeof(Node));
  strcpy(temp->biodata.name, biodata.name);
  strcpy(temp->biodata.month, biodata.month);
  temp->biodata.day = biodata.day;
  temp->biodata.year = biodata.year;
  temp->next = temp->prev = NULL;
  return temp;
}

void insertNode(Data biodata,int *count) {
    Node *temp = createNode(biodata);
    *count = *count + 1;
  if(!head) { 
    head = tail = temp;
  } else if(biodata.year < head->biodata.year) { 
      
    temp->next = head;
    head->prev = temp;
    head = temp;
  } else if(biodata.year > head->biodata.year) { 
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
  } else { 
    curr = head;

    while(curr->biodata.year < biodata.year) {
      curr = curr->next;
    }
   
    temp->prev = curr->prev; 
    temp->next = curr; 
   

    curr->prev->next = temp; 
    curr->prev = temp;
  }
}

void popDataAsCure(int *value,int *count){
    
    if(head == tail){
        free(head);
        
    }
    else{

        while(head){
            Node *newHead = head->next;
            head->next = newHead->prev = NULL;
            free(head);
            head = newHead;
            *value = *value - 1;
            *count = *count - 1;
        }
  
    }
    

}

void popAllData(){
    while(head){
        Node *newHead = head->next;
        head->next = newHead->prev = NULL;
        free(head);
        head = newHead;
    }
}

void printAll(){
    curr = head;
    while(curr){
        printf("%d %s %d - %s\n",curr->biodata.day,curr->biodata.month,curr->biodata.year,curr->biodata.name);
        curr= curr->next;
    }
}


