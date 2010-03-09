/* C Library for simple linked lists
 * File: list.c
 * Creation Date: March 9th, 2010
 * Last Modified Date: March 9th, 2010
 * Version: 0.0.1
 * Contact: Adam Lamers <adam@millenniumsoftworks.com>
*/

#include <stdlib.h>
#include "list.h"

list* new_list()
{
    list *l = malloc(sizeof(list));
    l->first = NULL;
    l->last = NULL;
    l->length = 0;
    return l;
}
