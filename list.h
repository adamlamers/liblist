/* File: list.h
 * Creation Date: March 9th, 2010
 * Last Modified Date: March 29th, 2010
 * Version: 0.0.2
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
 * @return Pointer to a new list.
 */
extern list* new_list(void *data);

/**
 * \brief Appends an element to a list
 * If a NULL pointer is passed for the "l" argument of this function, a new list is created, the item appened, and
 * the created list is returned.
 * @param l Pointer to a list to append an item to.
 * @param data Pointer to the data to store in the new element.
 * @return pointer to the new list, with the recently added item first.
 */
extern list *list_append(list *l, void *data);

/**
 * \brief Prepends an element to a list
 * If a NULL pointer is passed for the "l" argument of this function, a new list is created, the item is prepended, and
 * the created list is returned.
 * @param l Pointer to a list to append an item to.
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
 * \brief Fast-fowards to the end of the list.
 * This function is NULL-Safe, nothing will happen if a null pointer is passed as an argument.
 * @param l The list to fast-forward.
 */
extern list* list_end(list *l);

/**
 * Deletes the container elements for the list only.
 * @param l The list to delete.
 */
extern void delete_list(list *l);

/**
 * \brief Deletes the first element in a list.
 * If there are no more elements in the list to delete, this function will return NULL.
 * @param l The list to delete the first element from.
 */
extern list *delete_first(list *l);

/**
 * \brief Frees and deletes the first element in a list.
 * NOTE: The l->data member of the first member in the list MUST be allocated by malloc, or the behavior is undefined.
 * @param l The list to delete and free the first element from.
 */
extern list *free_first(list *l);

/**
 * \brief Frees and deletes all elements in a list.
 * NOTE: The l->data member of all members of the list MUST be allocated by malloc, or the behavior is undefined.
 * @param l The list to delete and free all elements of.
 */
extern void list_free_all(list *l);

#ifdef __cplusplus
}
#endif //extern "C"

#endif // LIST_H_INCLUDED
