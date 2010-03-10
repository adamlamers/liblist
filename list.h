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
 * Deletes an existing list.
 */
extern void delete_list();

#endif // LIST_H_INCLUDED
