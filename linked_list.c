#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"


LinkedList* linked_list_initialize() {
    Node *dummy = malloc(sizeof(Node));
    if (!dummy) return NULL;

    dummy->data = 0;
    dummy->next = NULL;

    LinkedList *linked_list = malloc(sizeof(LinkedList));
    if (!linked_list) {free(dummy); return NULL;}

    linked_list->head = dummy;
    linked_list->tail = dummy;
    linked_list->size = 0;

    return linked_list;
}

int linked_list_insert_to_head(LinkedList *linked_list, const int value) {
    if (!linked_list) return 1;

    Node *new_node = malloc(sizeof(Node));
    if (!new_node) return 1;

    new_node->data = value;
    new_node->next = linked_list->head->next;
    linked_list->head->next = new_node;

    if (linked_list->size == 0) linked_list->tail = new_node;

    linked_list->size++;
    return 0;
}

int linked_list_insert_to_tail(LinkedList *linked_list, const int value) {
    if (!linked_list) return 1;

    Node *new_node = malloc(sizeof(Node));
    if (!new_node) return 1;

    new_node->data = value;
    new_node->next = NULL;

    linked_list->tail->next = new_node;

    linked_list->tail = new_node;

    linked_list->size++;
    return 0;
}

int linked_list_search_by_value(LinkedList *linked_list, const int value) {
    if (!linked_list) return 1;

    Node *cur = linked_list->head->next;
    unsigned int idx = 0;
    while (cur != NULL) {
        if (cur->data == value) printf("Node(%d), idx: %hu\n", cur->data, idx);
        idx += 1;
        cur = cur->next;
    }
    return 0;
}

int linked_list_delete_by_value(LinkedList *linked_list, const int value) {
    if (!linked_list) return 1;
    if (linked_list->size == 0) return 2;

    Node *prev = linked_list->head;      
    Node *current = linked_list->head->next; 
    Node *temp;

    while (current != NULL) {
        if (current->data == value) {
            prev->next = current->next;

            if (current == linked_list->tail) linked_list->tail = prev;

            linked_list->size--;
            temp = current->next;
            free(current);
            current = temp;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return 2;
}

int linked_list_special_function(LinkedList *linked_list, const int value) {
    if (!linked_list) return 1;

    Node *prev = linked_list->head;
    Node *cur = linked_list->head->next;
    Node *temp;

    while (cur != NULL) {
        if (cur->data > value) {
            prev->next = cur->next;

            if (cur == linked_list->tail) linked_list->tail = prev;

            linked_list->size--;
            temp = cur->next;
            free(cur);
            cur = temp;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return 0;
}

int linked_list_sort(LinkedList *linked_list, SortOrder order) {
    if (!linked_list) return 0;
    if (linked_list->size < 2) return 0;
 
    bool swapped;
    Node *current;
    Node *prev;
    Node *next_node;
 
    do {
        swapped = false;
        prev = linked_list->head;
        current = linked_list->head->next;
 
        while (current && current->next) {
            next_node = current->next;
            bool should_swap = false;
 
            if (order == SORT_ASC) {
                if (current->data > next_node->data) should_swap = true;
            } else {
                if (current->data < next_node->data) should_swap = true;
            }
 
            if (should_swap) {
                current->next = next_node->next;
                next_node->next = current;
                prev->next = next_node;
 
                if (current->next == NULL) {
                    linked_list->tail = current;
                }
 
                prev = next_node;
                swapped = true;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
 
    return 0;
}

int linked_list_show(const LinkedList *linked_list) {
    if (!linked_list) return 1;

    Node *cur = linked_list->head->next;
    while (cur != NULL) {
        printf("Node(%d) -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");

    return 0;
}

void linked_list_free(LinkedList *linked_list) {
    if (!linked_list) return;

    Node *cur = linked_list->head;
    Node *cur_next;

    while (cur != NULL) {
        cur_next = cur->next;
        free(cur);
        cur = cur_next;
    }

    free(linked_list);
}