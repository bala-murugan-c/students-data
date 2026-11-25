#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void stud_save(struct student *head)
{
    FILE *fp;
    struct student *p;
    int count = 0;

    fp = fopen("student.dat", "w");
    if (fp == NULL)
    {
        printf("Unable to open student.dat for writing.\n");
        return;
    }

    /* one line per record: rollno,percentage,name */
    for (p = head; p != NULL; p = p->next)
    {
        fprintf(fp, "%d,%.2f,%s\n", p->rollno, p->percentage, p->name);
        count++;
    }

    fclose(fp);
    printf("%d record(s) saved to student.dat.\n", count);
}

struct student *stud_load(void)
{
    FILE *fp;
    struct student *head = NULL, *tail = NULL, *node;
    char line[128], name[50];
    int roll;
    float percentage;

    fp = fopen("student.dat", "r");
    if (fp == NULL)
        return NULL;   /* no file: start with an empty list */

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        /* skip damaged lines */
        if (sscanf(line, "%d,%f,%49[^\n]", &roll, &percentage, name) != 3)
            continue;

        if (roll <= 0 || percentage < 0.0f || percentage > 100.0f)
            continue;

        node = (struct student *)malloc(sizeof(struct student));
        if (node == NULL)
        {
            printf("Memory allocation failed while loading.\n");
            break;
        }

        node->rollno = roll;
        strcpy(node->name, name);
        node->percentage = percentage;
        node->next = NULL;

        /* add at the end of the list */
        if (head == NULL)
            head = node;
        else
            tail->next = node;
        tail = node;
    }

    fclose(fp);
    return head;
}
