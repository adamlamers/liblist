/* C Library for simple linked lists
 * File: list.c
 * Creation Date: March 9th, 2010
 * Last Modified Date: March 9th, 2010
 * Version: 0.0.1
 * Contact: Adam Lamers <adam@millenniumsoftworks.com>
*/

#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include "list.h"

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

void delete_list(list *l)
{
    //Delete the list header
    free(l);
}

int main(int a, char **b)
{
    list *files = NULL;
    files = list_prepend(files, "file one");
    files = list_prepend(files, "file two");
    files = list_prepend(files, "file three");
    files = list_reverse(files);
    list *temp = files;
    while(temp)
    {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
    /* Iterate through the list printing the data */
    return 0;
}
