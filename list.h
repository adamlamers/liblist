/* File: list.h
 * Creation Date: March 9th, 2010
 * Last Modified Date: March 9th, 2010
 * Version: 0.0.1
 * Contact: Adam Lamers <adam@millenniumsoftworks.com>
*/

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdint.h>

typedef struct list_tag
{
    void *data;                /**< Current element data */
    struct list_tag *next;     /**< Next element pointer */
    struct list_tag *prev;     /**< Previous element pointer */
} list;

/**
 * Creates a new list.
 * @return pointer to the new list
 */
extern list* new_list();

/**
 * Appends an element to a list
 * @param l Pointer to the list to add the item to, or NULL to begin a new list.
 * @param data Pointer to the data to store in the new element.
 * @return pointer to the new list, with the recently added item first.
 */
extern list *list_append(list *l, void *data);

/**
 * Rewinds to the beginning of the list.
 * @param l The list to rewind.
 */
list* list_rewind(list *l);
inline list* list_rewind(list *l)
{
    for(;l->prev != NULL; l = l ->prev);
    return l;
}
//#define list_rewind(l) for(;l->prev != NULL; l = l->prev)

/**
 * Fast-fowards to the end of the list.
 * @param l The list to fast-forward
 */
list* list_end(list *l);
inline list* list_end(list *l)
{
    for(;l->next != NULL; l = l->next);
    return l;
}

/**
 * Deletes an existing list.
 */
extern void delete_list();

#endif // LIST_H_INCLUDED
