#include "StrList.h"

#define BUFFER_SIZE 1024

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
            
            char buffer[BUFFER_SIZE];
            if (fgets(buffer, sizeof(buffer), stdin)==NULL){
                printf("failed to read input\n");
                    return 1;
            }
            char *newLine=strchr(buffer,'\n');
            if (newLine!=NULL) {
                *newLine='\0';
            }
            char*word=strtok(buffer, " ");
            int i=0;
            while ((word!=NULL) && (i<numOfSTR)){
            char* str=(char*)malloc(strlen(word)+1);
            if(str==NULL){
                printf("failed to allocate");
                StrList_free(list);
                return 1;
            }
            strcpy(str,word);
            StrList_insertLast(list,str);
            i++;
            word=strtok(NULL, " "); 
        }
            /*for(int i=0;i<numOfSTR;i++){
                char* str=(char*)malloc(sizeof(char)*STR_MAX_SIZE);
                if(str==NULL){
                    printf("faild to allocate for string");
                    StrList_free(list);
                    return 1;
                }
                scanf(" %s", str);
                StrList_insertLast(list,str);
            }*/
            break;

            case 2:
            int indexToAdd;
            char* str= (char*)malloc(sizeof(char)*STR_MAX_SIZE);
            if(str==NULL){
                printf("faild to allocate for string");
                StrList_free(list);
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
            printf("%lu\n",size);
            break;

            case 5:
            int indexToPrint;
            scanf("%d",&indexToPrint);
            StrList_printAt(list,indexToPrint);
            break;

            case 6:
            int count=StrList_printLen(list);
            printf("%d\n",count);
            break;

            case 7:
            char* strToCount=(char*)malloc(sizeof(char)*STR_MAX_SIZE);
            if(strToCount==NULL){
                printf("failed to allocate for string");
                StrList_free(list);
                return 1;
            }
            scanf("%s",strToCount);
            int strCounter=StrList_count(list,strToCount);
            printf("%d\n",strCounter);
            free(strToCount);
            break;

            case 8:
            char* strToRemove=(char*)malloc(sizeof(char)*STR_MAX_SIZE);
            if(strToRemove==NULL){
                printf("failed to allocate for string");
                StrList_free(list);
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

            case 10:
            StrList_reverse(list);
            break;

            case 11:
            while(list->head!=NULL){
                Node* temp=list->head;
                list->head=list->head->next;
                free(temp->str);
                free(temp);
            }
            list->size=0;
            break;

            case 12:
            StrList_sort(list);
            break;

            case 13:
            int ans=StrList_isSorted(list);
            if(ans==1){
                printf("true\n");
            }
            else{
                printf("false\n");
            }
            break;
        }   
        if (choice==0) {
            break;
        }
    }
    if(list!=NULL){
         StrList_free(list);
    }
    return 0;
}