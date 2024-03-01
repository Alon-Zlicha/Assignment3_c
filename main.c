#include "StrList.h"


int main(){
    StrList* list=StrList_alloc();
    if(list==NULL)
    {
        printf("faild to allocate for list");
        return 1;
    }
    while(1){
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 0:
            break;

            case 1:
            int numOfSTR;
            scanf("%d",&numOfSTR);
            if(numOfSTR==0){
                printf("No string to read");
            }
            else{
                for(int i=0;i<numOfSTR;i++){
                    char* str=(char*)malloc(sizeof(char)*STR_MAX_SIZE);
                    if(str==NULL){
                        printf("faild to allocate for string");
                        return 1;
                    }
                    scanf("%s ",str);
                    StrList_insertLast(list,str);
                }
            }
            break;

            case 2:
            int indexToAdd;
            char* str= (char*)malloc(sizeof(char)*STR_MAX_SIZE);
            if(str==NULL){
                printf("faild to allocate for string");
                return 1;
            }
            scanf("%d %s",&indexToAdd,str);
            StrList_insertAt(list,str,indexToAdd);
            break;

            case 3:
            StrList_print(list);
            break;

            case 4:
            size_t size=StrList_size(list);
            printf("%lu",size);
            break;

            case 5:
            int indexToPrint;
            scanf("%d",&indexToPrint);
            StrList_printAt(list,indexToPrint);
            break;

            case 6:
            int count=StrList_printLen(list);
            printf("%d",count);
            break;

            case 7:
            char* strToCount=(char*)malloc(sizeof(char)*STR_MAX_SIZE);
            if(strToCount==NULL){
                printf("failed to allocate for string");
                return 1;
            }
            scanf("%s",strToCount);
            int strCounter=StrList_count(list,strToCount);
            printf("%d ",strCounter);
            free(strToCount);
            break;

            case 8:
            char* strToRemove=(char*)malloc(sizeof(char)*STR_MAX_SIZE);
            if(strToRemove==NULL){
                printf("failed to allocate for string");
                return 1;
            }
            scanf("%s",strToRemove);
            StrList_remove(list,strToRemove);
            free(strToRemove);
            break;
            
            case 9:
            int indexToRemove;
            scanf("%d",&indexToRemove);
            StrList_removeAt(list,indexToRemove);
            break;
        }
        if (choice == 0) {
            break;
        }
    }
    if(list!=NULL){
         StrList_free(list);
    }
    return 0;
}