#include "StrList.h"

Node* Node_alloc(const char* _str,Node* _next){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode!=NULL){
        newNode->str=(char*)_str;
        newNode->next=_next;
    }
    return newNode;
}
StrList* StrList_alloc(){
    StrList* newStrList=(StrList*)malloc(sizeof(StrList));
    if(newStrList!=NULL){
        newStrList->head=NULL;
        newStrList->size=0;
    }
    return newStrList;
}
void StrList_free(StrList* StrList){
    if (StrList!=NULL){
        Node* current=StrList->head;
        Node* next;
        while(current!=NULL){
            next=current->next;
            free(current->str);
            free(current);
            current=next;
        }
        free(StrList);
    }
}
size_t StrList_size(const StrList* StrList){
    if(StrList!=NULL){
        return StrList->size;
    }
    return 0;
}
void StrList_insertLast(StrList* StrList, const char* data){
    Node* newNode= Node_alloc(data,NULL);
    if(newNode!=NULL){
        if(StrList->head==NULL){
            StrList->head=newNode;
        }
        else{
            Node* current=StrList->head;
            while(current->next!=NULL){
                current=current->next;
            }
            current->next=newNode;
        }
    StrList->size++;
    }
}
void StrList_insertAt(StrList* StrList,const char* data,int index){
    size_t size=StrList_size(StrList);
    if(index>size){
        printf("index too big");
        return;
    }
    Node* newNode=(Node*)Node_alloc(data,NULL);
    if(newNode!=NULL){
        if(index==0){
            newNode->next=StrList->head;
            StrList->head=newNode;
        }
        else{
            Node* current=StrList->head;
            for(int i=0;i<index-1;i++){
                current=current->next;
            }
            Node* next=current->next;
            current->next=newNode;
            newNode->next=next;
        }
        StrList->size++;
    }
}
char* StrList_firstData(const StrList* StrList){
    if(StrList==NULL){
        return NULL;
    }
    return StrList->head->str;
}
void StrList_print(const StrList* StrList){
    printf("\n");
    if((StrList==NULL) || (StrList->head==NULL )){
        return;
    }
    Node* current=StrList->head;
    while(current!=NULL){
        printf("%s",current->str);
        current=current->next;
        if (current != NULL) {
            printf(" ");
        }
    }
}
void StrList_printAt(const StrList* Strlist,int index){
    if(index>StrList_size(Strlist)-1){
        printf("index to big");
        return;
    }
    if(index==0){
        printf("\n%s",Strlist->head->str);
        return;
    }
    Node* current=Strlist->head;
    for(int i=0;i<index;i++){
        current=current->next;
    }
    printf("\n%s",current->str);
}
int StrList_printLen(const StrList* Strlist){
    if((Strlist==NULL) || (Strlist->head==NULL )){
        return 0;
    }
    int count=0;
    Node* current=Strlist->head;
    while(current!=NULL){
        count+=strlen(current->str);
        current=current->next;
    }
    return count;
}
int StrList_count(StrList* StrList, const char* data){
    if((StrList==NULL) || (StrList->head==NULL )){
        return 0;
    }
    int count=0;
    Node* current=StrList->head;
    while(current!=NULL){
        if(strcmp(data,current->str)==0){
            count++;
        }
        current=current->next;
    }
    return count;
}
void StrList_remove(StrList* StrList, const char* data){
    int count=0;
    while((StrList->head!=NULL) && strcmp(StrList->head->str,data)==0){
        Node* temp=StrList->head;
        StrList->head=StrList->head->next;
        free(temp->str);
        free(temp);
        count++;
    }
    if((StrList==NULL) || (StrList->head==NULL)){
        return;
    }
    Node* current=StrList->head;
    while((current->next!=NULL) && (current!=NULL)){
        if(strcmp(data,current->next->str)==0){
            Node* temp=current->next;
            current->next=current->next->next;
            free (temp->str);
            free(temp);
            count++;
        }
        else{
            current=current->next;
        }
    }
    StrList->size-=count;
}
void StrList_removeAt(StrList* StrList, int index){
    if(index>StrList_size(StrList)-1){
        printf("index to big");
        return;
    }
    if(index==0){
        Node* temp=StrList->head;
        StrList->head=StrList->head->next;
        free(temp->str);
        free(temp);
        StrList->size--;
        return;
    }
    Node* current=StrList->head;
    for(int i=0;i<index-1;i++){
        current=current->next;
    }
    Node* temp=current->next;
    current->next=current->next->next;
    free(temp->str);
    free(temp);
    StrList->size--;
}
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if(StrList1->size!=StrList2->size){
        return 0;
    }
    if(StrList1->size==0){
        return 1;
    }
    Node* current1=StrList1->head;
    Node* current2=StrList2->head;
    while(current1!=NULL){
        if(strcmp(current1->str,current2->str)!=0){
            return 0;
        }
        current1=current1->next;
        current2=current2->next;
    }
    return 1;
}
StrList* StrList_clone(const StrList* StrList){
    if(StrList==NULL){
        return NULL;
    }
    struct _StrList* clonedList=StrList_alloc();
    if(clonedList==NULL){
        printf("failed to allocate");
        return NULL;
    }
    Node* originalCurrent=StrList->head;
    Node* clonePrev=NULL;
    while(originalCurrent!=NULL){
        char* clonedStr=(char*)malloc(strlen(originalCurrent->str)+1);
        if(clonedStr==NULL){
            printf("failed to allocate");
            StrList_free(clonedList);
            return NULL;
        }
        strcpy(clonedStr,originalCurrent->str);
        Node* clonedNode=Node_alloc(clonedStr,NULL);
        if(clonedNode==NULL){
            printf("failed to alllocate");
            StrList_free(clonedList);
            return NULL;
        }
        if(clonePrev==NULL){
            clonedList->head=clonedNode;
        }
        else{
            clonePrev->next=clonedNode;
        }
        clonePrev=clonedNode;
        originalCurrent=originalCurrent->next;
    }
    clonedList->size=StrList->size;
    return clonedList;
}
void StrList_reverse( StrList* StrList){
    if(StrList->size<=1){
        return;
    }
    Node* prev=NULL;
    Node* current=StrList->head;
    while(current!=NULL){
        Node* next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    StrList->head=prev;
}
int compareStrings(const void* a, const void* b) {
    const char** str1 = (const char**)a;
    const char** str2 = (const char**)b;
    return strcmp(*str1, *str2);
}
void StrList_sort( StrList* StrList){
    size_t size=StrList->size;
    if(size<=1){
        return;
    }
    Node* current=StrList->head;
    char** arr=(char**)malloc(sizeof(char*)*size);
    if(arr==NULL){
        printf("failed to allocate");
        return;
    }
    current=StrList->head;
    int i=0;
    while(current!=NULL){
        arr[i]=current->str;
        current=current->next;
        i++;
    }
    qsort(arr,size,sizeof(char*),compareStrings);
    current=StrList->head;
    int j=0;
    while(current!=NULL){
        current->str=arr[j];
        current=current->next;
        j++;
    }
    free(arr);;
}
int StrList_isSorted(StrList* StrList){
    if(StrList->size<=1){
        return 1;
    }
    Node* current=StrList->head;
    while(current->next!=NULL){
        if(strcmp(current->str,current->next->str)>0){
            return 0;
        }
        current=current->next;
    }
    return 1;
}
