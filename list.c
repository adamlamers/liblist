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
        list *newElement = malloc(sizeof(list));
        if(!newElement) return NULL;
        
        l->next = newElement;
        newElement->next = NULL;
        newElement->prev = l;
        newElement->data = data;

        return newElement;
    }
}

int list_prepend(list **l, void *data)
{
    if(*l != NULL)
        for(;(*l)->prev != NULL; *l = (*l)->prev);
    
}

int list_insert(list *l, void *data, int64_t pos)
{
    return 0;
}

void delete_list(list *l)
{
    //Delete the list header
    free(l);
}

int main(int a, char **b)
{
    list *files = NULL;
    files = list_append(files, "file one");
    files = list_append(files, "file two");
    files = list_append(files, "file three");
    
    //Rewind the list
    for(;files->prev != NULL; files = files->prev);
    /* Iterate through the list printing the data */
    do
    {
        printf("%s\n", files->data);
        files = files->next;
    }while(files);
    return 0;
}
