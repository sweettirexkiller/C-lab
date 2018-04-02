#include <stdio.h>
#include <stdlib.h>

struct Element{
       void *data;
       struct Element *next;
       struct Element *previous;
};

struct LinkedList{
       struct Element *first;
       struct Element *last;
};

void Initialize(struct LinkedList *list);
void AddElement(struct LinkedList* list,void *data);
void FreeList(struct LinkedList* list);
void RemoveElement(struct LinkedList* list,int index);
void Swap(struct Element* el_1,struct Element* el_2);
struct Element* GetElement(struct LinkedList* list,int index);
int GetLenght(struct LinkedList* list);
void Sort(struct LinkedList * list,int (*fun)(const void*,const void* ));
