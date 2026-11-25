#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/* returns the node with this roll number, or NULL */
static struct student *find_roll(struct student *head, int roll)
{
    struct student *p;

    for (p = head; p != NULL; p = p->next)
    {
        if (p->rollno == roll)
            return p;
    }
    return NULL;
}

/* unlink the node with this roll number and free it */
static struct student *delete_by_roll(struct student *head, int roll)
{
    struct student *curr = head, *prev = NULL;

    while (curr != NULL && curr->rollno != roll)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        printf("Record with roll number %d not found.\n", roll);
        return head;
    }

    if (prev == NULL)
        head = curr->next;       /* deleting the first node */
    else
        prev->next = curr->next; /* skip over the node */

    free(curr);
    printf("Record with roll number %d deleted successfully.\n", roll);
    return head;
}

/* reads a roll number, returns 0 if the input is not a number */
static int read_roll(int *roll)
{
    if (scanf("%d", roll) != 1)
    {
        scanf("%*[^\n]");
        printf("Invalid roll number.\n");
        return 0;
    }
    return 1;
}

struct student *stud_del(struct student *head)
{
    struct student *p, *node;
    char choice, name[50];
    int roll, count;

    if (head == NULL)
    {
        printf("No student records available.\n");
        return head;
    }

    printf("R/r : Enter roll number to delete\n");
    printf("N/n : Enter name to delete\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice == 'r' || choice == 'R')
    {
        printf("Enter roll number: ");
        if (read_roll(&roll))
            head = delete_by_roll(head, roll);
    }
    else if (choice == 'n' || choice == 'N')
    {
        printf("Enter name: ");
        scanf(" %49[^\n]", name);

        /* show every record with this name */
        count = 0;
        for (p = head; p != NULL; p = p->next)
        {
            if (strcmp(p->name, name) == 0)
            {
                if (count == 0)
                {
                    printf("------------------------------------------------------------\n");
                    printf("Roll No.    Name                          Percentage\n");
                    printf("------------------------------------------------------------\n");
                }
                printf("%-11d %-29s %.2f\n", p->rollno, p->name, p->percentage);
                count++;
            }
        }

        if (count == 0)
        {
            printf("No record found with name %s.\n", name);
            return head;
        }

        printf("------------------------------------------------------------\n");
        printf("Enter roll number to delete: ");
        if (read_roll(&roll))
        {
            /* the roll number must belong to a listed record */
            node = find_roll(head, roll);
            if (node == NULL || strcmp(node->name, name) != 0)
                printf("Roll number does not match any listed record.\n");
            else
                head = delete_by_roll(head, roll);
        }
    }
    else
        printf("Invalid choice.\n");

    return head;
}
