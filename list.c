/* C Library for simple linked lists
 * File: list.c
 * Creation Date: March 9th, 2010
 * Last Modified Date: March 29th, 2010
 * Version: 0.0.2
 * Contact: Adam Lamers <adam@millenniumsoftworks.com>
*/

#include <stdlib.h>
#include <stdint.h>
#include "list.h"

#ifdef DEBUG
#include <windows.h>
#include <psapi.h>
#endif

list* new_list(void *data)
{
    list *l = malloc(sizeof(list));
    l->data = data;
    l->prev = NULL;
    l->next = NULL;
    return l;
}

list *list_append(list *l, void *data)
{
    if(!l)
    {
        return new_list(data);
    }
    else
    {
        list *lastElement = list_end(l);
        list *newList = malloc(sizeof(list));
        if(!newList) return NULL;
        newList->next = NULL;
        newList->prev = lastElement;
        newList->data = data;
        lastElement->next = newList;
        return l;
    }
}

list *list_prepend(list *l, void *data)
{
    if(!l)
    {
        return new_list(data);
    }
    else
    {
        list *newList = malloc(sizeof(list));
        if(!newList) return NULL;
        l->prev = newList;
        newList->next = l;
        newList->prev = NULL;
        newList->data = data;
        return newList;
    }
}

list *list_reverse(list *l)
{
    list *last = NULL;
    while(l)
    {
        last = l;
        l = last->next;
        last->next = last->prev;
        last->prev = l;
    }
    return last;
}

int list_length(list *l)
{
    int count = 0;
    for(;l != NULL; l = l->next)
    {
        count++;
    }
    return count;
}

void delete_list(list *l)
{
    while(l) l = delete_first(l);
}

list *delete_first(list *l)
{
    if(l)
    {
        if(l->next)
        {
            list *newList = l->next;
            newList->prev = NULL;
            free(l);
            return newList;
        }
        else
        {
            free(l);
            return NULL;
        }
    }
    return NULL;
}

list *free_first(list *l)
{
    if(l)
    {
        if(l->next)
        {
            list *newList = l->next;
            newList->prev = NULL;
            free(l->data);
            free(l);
            return newList;
        }
        else
        {
            free(l->data);
            free(l);
            return NULL;
        }
    }
    return NULL;
}

list* list_rewind(list *l)
{
    for(;l->prev != NULL; l = l ->prev);
    return l;
}

list* list_end(list *l)
{
    for(;l->next != NULL; l = l->next);
    return l;
}

void list_free_all(list *l)
{
    while(l) l = free_first(l);
}

#ifdef DEBUG
int main(int a, char **b)
{
    list *z = NULL;
    char *data;
    int i = 0;
    printf("adding elements...\n");
    for(i = 0; i < 128000; i++)
    {
        data = malloc(1024);
        data[0] = i;
        z = list_append(z, data);
    }
    system("pause");
    list_free_all(z);
    printf("freeing...\n");
    system("pause");
    return 0;
}
#endif
