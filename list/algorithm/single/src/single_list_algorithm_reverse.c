#include "single_list_algorithm_reverse.h"

list_head *init_list(int num)
{
    list_head *head = init_head();

    for(int i = 0; i < num; i++){
        single_list *list = add_list(i);
        push_list_tail(head, list);
    }
    return head;
}

void iteration_reverse(list_head *head)
{
    if(!head || !head->list){
        LOG("head or list is NULL\n");
        return;
    }

    single_list *pre = NULL;
    single_list *cur = head->list;
    single_list *next = cur->next;

    while(next){
        cur->next = pre;
        pre = cur;
        cur = next;
        next = next->next;
    }

    cur->next = pre;
    head->list = cur;

}

single_list *recursive_reverse(list_head *head, single_list *list)
{
    if(!list || !list->next) {
        head->list = list;
        return list;
    }
    single_list *next = recursive_reverse(head, list->next);
    list->next->next = list;
    list->next = NULL;
    return next;
}

int single_list_algorithm_reverse(int argc, char argv[])
{
    list_head *head = init_list(9);
    LOG("source list:\n");
    print_list(head);
    iteration_reverse(head);
    LOG("iteration_reverse list:\n");
    print_list(head);
    recursive_reverse(head, head->list);
    LOG("recursive_reverse list:\n");
    print_list(head);
    exit(0);
}
