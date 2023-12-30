#ifndef _SINGLE_LIST_DATA_H_
#define _SINGLE_LIST_DATA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _SINGLE_LIST {
   struct _SINGLE_LIST *next;
   int num;
} single_list;

typedef struct _LIST_HEAD {
    int total_num;
    single_list *list;
} list_head;

void check_pointer(void *pointer);
list_head *init_head();
single_list *add_list(int num);
void push_list_tail(list_head *head, single_list *list);
void push_list_head(list_head *head, single_list *list);
void pop_list(list_head *head, int num);
void print_list(list_head *head);
void free_all_list(list_head *head);

#endif