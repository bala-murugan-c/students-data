#include <stdlib.h>
#include "student.h"

struct student *stud_delall(struct student *head)
{
    struct student *next;

    /* free the nodes one by one */
    while (head != NULL)
    {
        next = head->next;   /* save the next node before freeing */
        free(head);
        head = next;
    }

    return NULL;   /* the list is now empty */
}
