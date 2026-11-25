#include <stdio.h>
#include "student.h"

struct student *stud_rev(struct student *head)
{
    struct student *prev = NULL, *curr = head, *next;

    if (head == NULL)
    {
        printf("No student records available.\n");
        return head;
    }

    /* turn each node's next pointer to point backwards */
    while (curr != NULL)
    {
        next = curr->next;   /* save the rest of the list */
        curr->next = prev;   /* reverse the link */
        prev = curr;         /* move prev forward */
        curr = next;         /* move curr forward */
    }

    printf("List reversed.\n");
    return prev;   /* prev is the new first node */
}
