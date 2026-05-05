#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

#define CLEAR 1


int main(void) {
    int res; // to catch error in the functions

    int choice;
    unsigned short step = 0;

    int value_to_insert;
    int input_value;

    LinkedList *linked_list = linked_list_initialize();
    if (!linked_list) {
        printf("Something went wrong during initialization of linked list. Try again latter.\n");
        // exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Value to insert: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода! Введите целое число.\n");
            while(getchar() != '\n');
            continue;
        }

        if (linked_list_insert_to_tail(linked_list, choice) != 0) {
            printf("Ошибка: не удалось выделить память под узел.\n");
            break;
        }

        if (choice == 666) break;
    }

    while (1) {
        switch (step) {
            case 0:
                if (CLEAR) system("clear"); else printf("---------------------------------------------------------\n");

                printf("Menu:\n");
                printf("1. View.\n");
                printf("2. Insert.\n");
                printf("3. Delete.\n");
                printf("4. Sort.\n");
                printf("5. Special Function.\n");
                printf("6. Exit.\n");
                printf("7. Search by value.\n");

                if (scanf("%d", &choice) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                if (choice == 1) step = 10; else
                if (choice == 2) step = 20; else
                if (choice == 3) step = 30; else
                if (choice == 4) step = 40; else
                if (choice == 5) step = 50; else
                if (choice == 6) exit(EXIT_SUCCESS); else
                if (choice == 7) step = 70;
                else printf("Incorrect input. Try again.\n");

                break;
                
            case 10:
                if (CLEAR) system("clear"); else printf("---------------------------------------------------------\n");

                if (!linked_list) {
                    printf("Linked List doesn't exist.\n");
                    // exit(EXIT_FAILURE);
                }

                linked_list_show(linked_list);

                printf("Menu:\n");
                printf("Go back to start menu:\n");
                printf("1. YES\n");
                printf("2. NO\n");

                if (scanf("%d", &choice) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                if (choice == 1) step = 0; else
                if (choice == 0) continue; else
                printf("Incorrect input. Try again.\n");

                break;

            case 20:
                if (CLEAR) system("clear"); else printf("---------------------------------------------------------\n");

                printf("Menu:\n");
                printf("Select the option:\n");
                printf("1. Insert to the head of linked list.\n");
                printf("2. Insert to the tail of linked list.\n");
                printf("3. Go back to start menu.\n");

                if (scanf("%d", &choice) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                if (choice == 1) step = 21; else
                if (choice == 2) step = 22; else
                if (choice == 3) step = 0; else
                printf("Incorrect input. Try again.\n");

                break;

            case 21:
                if (CLEAR) system("clear"); else printf("---------------------------------------------------------\n");
                
                printf("Insert to the HEAD of linked list.\n");
                printf("Value to insert: ");

                if (scanf("%d", &value_to_insert) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                printf("\n");

                res = linked_list_insert_to_head(linked_list, value_to_insert);
                if (res == 1) {
                    printf("Something went wrong during data insertion.\n");
                    // exit(EXIT_FAILURE);
                } else printf("Data was successfully inserted.\n");

                printf("Menu:\n");
                printf("1. Insert one more element.\n");
                printf("2. Insert element to the TAIl of linked list.\n");
                printf("3. View linked list.\n");
                printf("4. GO to start menu.\n");

                if (scanf("%d", &choice) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                if (choice == 1) step = 21; else
                if (choice == 2) step = 22; else
                if (choice == 3) step = 10; else
                if (choice == 4) step = 0; else
                printf("Incorrect input. Try again.\n");
                
                break;
            
            case 22:
                if (CLEAR) system("clear"); else printf("---------------------------------------------------------\n");
                
                printf("Insert to the TAIL of linked list.\n");
                printf("Value to insert: ");

                if (scanf("%d", &value_to_insert) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                printf("\n");

                res = linked_list_insert_to_tail(linked_list, value_to_insert);
                if (res == 1) {
                    printf("Something went wrong during data insertion.\n");
                    // exit(EXIT_FAILURE);
                } else printf("Data was successfully inserted.\n");

                printf("Menu:\n");
                printf("1. Insert one more element.\n");
                printf("2. Insert element to the HEAD of linked list.\n");
                printf("3. View linked list.\n");
                printf("4. GO to start menu.\n");

                if (scanf("%d", &choice) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                if (choice == 1) step = 22; else
                if (choice == 2) step = 21; else
                if (choice == 3) step = 10; else
                if (choice == 4) step = 0; else
                printf("Incorrect input. Try again.\n");
                
                break;

            case 30:
                if (CLEAR) system("clear"); else printf("---------------------------------------------------------\n");

                if (!linked_list) {
                    printf("Linked List doesn't exist.\n");
                    exit(EXIT_FAILURE);
                }

                printf("\nCurrent list: ");
                linked_list_show(linked_list);

                printf("\nEnter value to delete: ");
                if (scanf("%d", &input_value) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    continue;
                }

                res = linked_list_delete_by_value(linked_list, input_value);
                if (res == 0) {
                    printf("Value %d deleted successfully.\n", input_value);
                }
                // if (res == 2) {
                //     printf("Value %d not found in the list.\n", input_value);
                // } else {
                //     printf("Something went wrong during delete element from linked list.\n");
                //     exit(EXIT_FAILURE);
                // }

                printf("\nMenu:\n");
                printf("1. Delete another element\n");
                printf("2. View linked list.\n");
                printf("3. Go back to start menu\n");
                printf("Your choice: ");

                if (scanf("%d", &choice) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                if (choice == 1) continue; else
                if (choice == 2) step = 10; else
                if (choice == 3) step = 0; else
                printf("Incorrect input. Try again.\n");
                break;

            case 40:
                if (CLEAR) system("clear"); else printf("---------------------------------------------------------\n");

                if (!linked_list) {
                    printf("Linked List doesn't exist.\n");
                    exit(EXIT_FAILURE);
                }

                printf("Choose the order to sort:\n");
                printf("1. ASC\n");
                printf("2. DESC\n");
                printf("3. GO to start menu\n");

                if (scanf("%d", &choice) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                if (choice == 1) step = 41; else
                if (choice == 2) step = 42; else
                if (choice == 3) step = 0; else
                printf("Incorrect input. Try again.\n");

                break;

            case 41:
                if (CLEAR) system("clear"); else printf("---------------------------------------------------------\n");
                
                res = linked_list_sort(linked_list, SORT_ASC);
                if (res == 1) {
                    printf("Something went wrong during sorting linked list. Try again latter.\n");
                    // exit(EXIT_FAILURE);
                }

                printf("Linked list was successfully sorted.\n");
                linked_list_show(linked_list);
                
                printf("Menu:\n");
                printf("Go back to start menu:\n");
                printf("1. YES\n");
                printf("2. NO\n");

                if (scanf("%d", &choice) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                if (choice == 1) step = 0; else
                if (choice == 2) continue; else
                printf("Incorrect input. Try again.\n");

                break;

            case 42:
                if (CLEAR) system("clear"); else printf("---------------------------------------------------------\n");
                
                res = linked_list_sort(linked_list, SORT_DESC);
                if (res == 1) {
                    printf("Something went wrong during sorting linked list. Try again latter.\n");
                    // exit(EXIT_FAILURE);
                }

                printf("Linked list was successfully sorted.\n");
                linked_list_show(linked_list);
                
                printf("Menu:\n");
                printf("Go back to start menu:\n");
                printf("1. YES\n");
                printf("2. NO\n");

                if (scanf("%d", &choice) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                if (choice == 1) step = 0; else
                if (choice == 2) continue; else
                printf("Incorrect input. Try again.\n");

                break;
            
            case 50:
                if (CLEAR) system("clear"); else printf("---------------------------------------------------------\n");

                printf("\nEnter pivot to delete: ");
                if (scanf("%d", &input_value) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    continue;
                }

                res = linked_list_special_function(linked_list, input_value);
                if (res == 1) {
                    printf("Something went wrong during deleting values. Try again latter.\n");
                    // exit(EXIT_FAILURE);
                }

                printf("Menu:\n");
                printf("1. View linked list.\n");
                printf("2. Go back to main menu.\n");

                if (scanf("%d", &choice) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                if (choice == 1) step = 10; else
                if (choice == 2) step = 0; else
                printf("Incorrect input. Try again.\n");

                break;

            case 70:
                if (CLEAR) system("clear"); else printf("---------------------------------------------------------\n");
                
                printf("\nEnter value to search: ");
                if (scanf("%d", &input_value) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    continue;
                }

                res = linked_list_search_by_value(linked_list, input_value);
                if (res == 1) {
                    printf("Something went wrong during searching the element with value.\n");
                    // exit(EXIT_FAILURE);
                }

                printf("Menu:\n");
                printf("1. Search by value.\n");
                printf("2. Go back to main menu.\n");

                if (scanf("%d", &choice) != 1) {
                    while (getchar() != '\n'); 
                    continue;
                }

                if (choice == 1) step = 70; else
                if (choice == 2) step = 0; else
                printf("Incorrect input. Try again.\n");

                break;
        }
    }

    linked_list_free(linked_list);

    return 0;
}