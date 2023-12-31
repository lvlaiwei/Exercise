#include "single_list_data.h"

void check_pointer(void *pointer)
{
    if(!pointer)
        exit(-1);
}

list_head *init_head()
{
    list_head *head = (list_head *)malloc(sizeof(list_head));
    check_pointer(head);
    head->list = NULL;
    head->total_num = 0;

    return head;
}

single_list *add_list(int num)
{
    single_list *list = (single_list *)malloc(sizeof(single_list));
    check_pointer(list);
    list->next = NULL;
    list->num = num;
    return list;
}

void push_list_tail(list_head *head, single_list *list)
{
    if(!head->list){
        head->list = list;
        return;
    }

    single_list *temp_list = head->list;
    while(temp_list->next) temp_list = temp_list->next;

    temp_list->next = list;
}

void push_list_head(list_head *head, single_list *list)
{
    if(!head->list){
        head->list = list;
        return;
    }

    list->next = head->list;
    head->list = list;

}

void pop_list(list_head *head, int num)
{
    if(!head->list){
        printf("Head is NULL\n");
        return;
    }
    
    single_list *temp_list = head->list;
    single_list *pre_list = NULL;
    while(temp_list->num != num){
        pre_list = temp_list;
        temp_list = temp_list->next;
    }

    pre_list->next = temp_list->next;
    
    free(temp_list);
}

void print_list(list_head *head)
{
    if(!head->list){
        printf("Head is NULL\n");
        return;
    }

    single_list *temp_list = head->list;
    while(temp_list){
        // printf("num is %p\n", temp_list);
        printf("num is %d\n", temp_list->num);
        temp_list = temp_list->next;
    }
}

void free_all_list(list_head *head)
{
    if(!head->list){
        printf("Head is NULL\n");
        return;
    }
    
    single_list *temp_list = head->list;
    single_list *pre_list = NULL;
    while(temp_list){
        pre_list = temp_list;
        temp_list = temp_list->next;
        free(pre_list);
    }
    free(head);

}

int single_list_data(int argc, char *argv[])
{
    list_head *head = init_head();
    
    for(int i = 0; i < 9; i++){
        single_list *list = add_list(i);
        push_list_tail(head, list);
    }
    for(int i = 9; i < 18; i++){
        single_list *list = add_list(i);
        push_list_head(head, list);
    }

    pop_list(head, 6);

    print_list(head);

    free_all_list(head);
    exit(0);
}
