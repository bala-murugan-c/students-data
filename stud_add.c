#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/* returns 1 if the roll number is already used */
static int roll_exists(struct student *head, int roll)
{
    struct student *p;

    for (p = head; p != NULL; p = p->next)
    {
        if (p->rollno == roll)
            return 1;
    }
    return 0;
}

/* smallest positive roll number not in use */
static int next_rollno(struct student *head)
{
    int roll = 1;

    while (roll_exists(head, roll))
        roll++;

    return roll;
}

struct student *stud_add(struct student *head)
{
    struct student *new_node, *p;
    char name[50];
    float percentage;
    int r;

    printf("Enter student name: ");
    scanf(" %49[^\n]", name);

    /* repeat until percentage is a number from 0 to 100 */
    while (1)
    {
        printf("Enter percentage (0.00 - 100.00): ");
        r = scanf("%f", &percentage);

        if (r == 1 && percentage >= 0.0f && percentage <= 100.0f)
            break;

        printf("Invalid percentage. Try again.\n");
        scanf("%*[^\n]");   /* discard the bad input */
    }

    /* allocate the node only after the input is valid */
    new_node = (struct student *)malloc(sizeof(struct student));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    new_node->rollno = next_rollno(head);
    strcpy(new_node->name, name);
    new_node->percentage = percentage;
    new_node->next = NULL;

    /* link the node at the end of the list */
    if (head == NULL)
        head = new_node;
    else
    {
        for (p = head; p->next != NULL; p = p->next)
            ;
        p->next = new_node;
    }

    printf("Record added. Roll number assigned: %d\n", new_node->rollno);
    return head;
}
