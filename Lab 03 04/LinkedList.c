#include "LinkedList.h"

void Initialize(struct LinkedList *list){
     list->first = NULL;
     list->last = NULL;
}

void AddElement(struct LinkedList* list,void *data){
    struct Element *element;
    element = malloc(sizeof(struct Element));
    element->data = (void*)data;
    if(list->first == NULL){
        list->first = element;
        list->last = element;
        element->next = NULL;
        element->previous = NULL;
    }else{
        list->last->next = element;
        element->previous = list->last;
        list->last = element;
        element->next = NULL;
    }
}

void FreeList(struct LinkedList* list){
    struct Element* el = list->first;
    while(el != NULL){
        struct Element* next = el->next;
        free(el);
        el = next;
    }
    free(list);
}

void RemoveElement(struct LinkedList* list,int index){
    struct Element* el = list->first;
    int actual = 0;
    while(el != NULL){
        if(actual == index){
            if(el->previous != NULL){
                if(el->next != NULL){
                    el->previous->next = el->next;
                    el->next->previous = el->previous;
                }else{
                    el->previous->next = NULL;
                    list->last = el->previous;
                }
            }else{
                if(el->next != NULL){
                    el->next->previous = NULL;
                    list->first = el->next;
                }else{
                    list->first = NULL;
                    list->last = NULL;
                }
            }
            free(el);
        }
        el = el->next;
        actual++;
    }

}

void Swap(struct Element* el_1,struct Element* el_2){
    void *help = el_1->data;
    el_1->data = el_2->data;
    el_2->data = help;
}

struct Element* GetElement(struct LinkedList* list,int index){
    int actual = 0;
    struct Element* el = list->first;
    while(el != NULL){
        if(actual == index){
            return el;
        }
        actual++;
        el = el->next;
    }
    return NULL;
}

int GetLenght(struct LinkedList* list){
    int counter = 0;
    struct Element* el = list->first;
    while(el != NULL){
        counter++;
        el = el->next;
    }
    return counter;
}

void Sort(struct LinkedList* list,int (*fun)(const void*,const void* )){
  int i,j;
  for(i=0;i<GetLenght(list);i++){
      for(j=1;j<GetLenght(list)-i;j++){
        void* a = GetElement(list,j-1);
        void* b = GetElement(list,j);
        if(fun(a,b) > 0){
            Swap(a,b);
        }
      }
    }
}
