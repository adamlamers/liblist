/* File: list.h
 * Creation Date: March 9th, 2010
 * Last Modified Date: March 12th, 2010
 * Version: 0.0.1
 * Contact: Adam Lamers <adam@millenniumsoftworks.com>
*/

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

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
extern list* new_list(void *data);

/**
 * Appends an element to a list
 * @param l Pointer to the list to add the item to, or NULL to begin a new list.
 * @param data Pointer to the data to store in the new element.
 * @return pointer to the new list, with the recently added item first.
 */
extern list *list_append(list *l, void *data);

/**
 * Prepends an element to a list
 * @param l Pointer to the list to add the item to, or NULL to begin a new list.
 * @param data Pointer to the data to store in the new element.
 * @return pointer to the beginning of the new list.
 */
extern list* list_prepend(list *l, void *data);

/**
 * Rewinds to the beginning of the list.
 * @param l The list to rewind.
 */
extern list* list_rewind(list *l);

/**
 * Fast-fowards to the end of the list.
 * @param l The list to fast-forward
 */
extern list* list_end(list *l);

/**
 * Deletes an existing list.
 */
extern void delete_list(list *l);
list *delete_first(list *l);

#ifdef __cplusplus
}
#endif //extern "C"

#endif // LIST_H_INCLUDED
