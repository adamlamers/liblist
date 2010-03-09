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
    void *first;    /**< First element in the list */
    void *last;     /**< Last element in the list */
    int64_t length; /**< Number of elements in the list */
} list;

typedef struct node_tag
{
    void *next; /**< Succeding element in the list */
    void *prev; /**< Preceding element in the list */
    void *data; /**< Data for this node in the list */
} node;

#endif // LIST_H_INCLUDED
