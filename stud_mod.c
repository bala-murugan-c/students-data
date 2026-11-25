#include <stdio.h>
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

/* returns 1 if the node fits the name or percentage searched */
static int matches(struct student *p, char choice, const char *name, float pct)
{
    if (choice == 'n' || choice == 'N')
        return strcmp(p->name, name) == 0;

    /* floats are compared within 0.005 instead of == */
    return (p->percentage - pct < 0.005f && pct - p->percentage < 0.005f);
}

/* show the record and read the new name and percentage */
static void edit_node(struct student *node)
{
    char name[50];
    float percentage;
    int r;

    printf("Current details:\n");
    printf("Roll No: %d\n", node->rollno);
    printf("Name: %s\n", node->name);
    printf("Percentage: %.2f\n", node->percentage);

    printf("Enter new name: ");
    scanf(" %49[^\n]", name);

    while (1)
    {
        printf("Enter new percentage (0.00 - 100.00): ");
        r = scanf("%f", &percentage);

        if (r == 1 && percentage >= 0.0f && percentage <= 100.0f)
            break;

        printf("Invalid percentage. Try again.\n");
        scanf("%*[^\n]");
    }

    /* roll number is left unchanged */
    strcpy(node->name, name);
    node->percentage = percentage;
    printf("Record with roll number %d modified successfully.\n", node->rollno);
}

void stud_mod(struct student *head)
{
    struct student *p, *first = NULL, *node;
    char choice, name[50] = "";
    float pct = 0.0f;
    int roll, count;

    if (head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("Enter which record to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice == 'r' || choice == 'R')
    {
        printf("Enter roll number: ");
        if (read_roll(&roll))
        {
            node = find_roll(head, roll);
            if (node == NULL)
                printf("Record with roll number %d not found.\n", roll);
            else
                edit_node(node);
        }
    }
    else if (choice == 'n' || choice == 'N' || choice == 'p' || choice == 'P')
    {
        if (choice == 'n' || choice == 'N')
        {
            printf("Enter name: ");
            scanf(" %49[^\n]", name);
        }
        else
        {
            printf("Enter percentage: ");
            if (scanf("%f", &pct) != 1 || pct < 0.0f || pct > 100.0f)
            {
                scanf("%*[^\n]");
                printf("Invalid percentage.\n");
                return;
            }
        }

        /* count the matching records */
        count = 0;
        for (p = head; p != NULL; p = p->next)
        {
            if (matches(p, choice, name, pct))
            {
                if (count == 0)
                    first = p;
                count++;
            }
        }

        if (count == 0)
        {
            printf("No matching record found.\n");
            return;
        }

        /* only one match: modify it directly */
        if (count == 1)
        {
            edit_node(first);
            return;
        }

        /* several matches: list them and ask for the roll number */
        printf("------------------------------------------------------------\n");
        printf("Roll No.    Name                          Percentage\n");
        printf("------------------------------------------------------------\n");
        for (p = head; p != NULL; p = p->next)
        {
            if (matches(p, choice, name, pct))
                printf("%-11d %-29s %.2f\n", p->rollno, p->name, p->percentage);
        }
        printf("------------------------------------------------------------\n");

        printf("Enter roll number to modify: ");
        if (read_roll(&roll))
        {
            /* the roll number must belong to a listed record */
            node = find_roll(head, roll);
            if (node == NULL || !matches(node, choice, name, pct))
                printf("Roll number does not match any listed record.\n");
            else
                edit_node(node);
        }
    }
    else
        printf("Invalid choice.\n");
}
