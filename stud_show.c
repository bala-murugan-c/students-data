#include <stdio.h>
#include "student.h"

void stud_show(struct student *head)
{
    struct student *p;

    if (head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("------------------------------------------------------------\n");
    printf("Roll No.    Name                          Percentage\n");
    printf("------------------------------------------------------------\n");

    /* print one row per node */
    for (p = head; p != NULL; p = p->next)
        printf("%-11d %-29s %.2f\n", p->rollno, p->name, p->percentage);

    printf("------------------------------------------------------------\n");
}
