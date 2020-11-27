#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"

int main(){

    int patient,cure,count = 0;
    scanf("%d%d",&patient,&cure);
    for(int i =0 ;i<patient; i++){
        Data biodata;
        scanf("%d %s %d - %[^\n]",&biodata.day,biodata.month,&biodata.year,biodata.name);
        insertNode(biodata,&count);

    }
    popDataAsCure(&cure,&count);
    if(head = NULL ){
        printf("All patients get the cure,%d cure left\n",cure);
    }
    else{
        printf("Need %d more cure\n",count);
    }
    printAll();
    popAllData();


    return 0;
}