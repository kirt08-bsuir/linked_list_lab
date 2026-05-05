#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    struct Node *head;
    struct Node *tail;
    unsigned short size;
} LinkedList;

typedef enum {
    SORT_ASC,
    SORT_DESC
} SortOrder;

LinkedList* linked_list_initialize();

int linked_list_insert_to_head(LinkedList *linked_list, const int value);
int linked_list_insert_to_tail(LinkedList *linked_list, const int value);

int linked_list_search_by_value(LinkedList *linked_list, const int value);

int linked_list_delete_by_value(LinkedList *linked_list, const int value);

int linked_list_special_function(LinkedList *linked_list, const int value);

int linked_list_sort(LinkedList *linked_list, SortOrder order);

int linked_list_show(const LinkedList *linked_list);

void linked_list_free(LinkedList *linked_list);

#endif