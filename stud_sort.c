#include <stdio.h>
#include <string.h>
#include "student.h"

/* returns 1 if node a should come before node b */
static int comes_before(struct student *a, struct student *b, char choice)
{
    if (choice == 'n' || choice == 'N')
        return strcmp(a->name, b->name) < 0;   /* A to Z */

    return a->percentage > b->percentage;      /* highest first */
}

struct student *stud_sort(struct student *head)
{
    struct student *sorted = NULL, *curr, *next, *p;
    char choice;

    if (head == NULL)
    {
        printf("No student records available.\n");
        return head;
    }

    printf("N/n : Sort with name\n");
    printf("P/p : Sort with percentage\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice != 'n' && choice != 'N' && choice != 'p' && choice != 'P')
    {
        printf("Invalid choice.\n");
        return head;
    }

    /* take each node from the old list and link it into sorted */
    for (curr = head; curr != NULL; curr = next)
    {
        next = curr->next;   /* save the rest before changing curr->next */

        if (sorted == NULL || comes_before(curr, sorted, choice))
        {
            /* insert at the front of sorted */
            curr->next = sorted;
            sorted = curr;
        }
        else
        {
            /* find the node after which curr belongs */
            p = sorted;
            while (p->next != NULL && !comes_before(curr, p->next, choice))
                p = p->next;

            curr->next = p->next;
            p->next = curr;
        }
    }

    if (choice == 'n' || choice == 'N')
        printf("List sorted by name.\n");
    else
        printf("List sorted by percentage (highest first).\n");

    return sorted;   /* the first node may have changed */
}
