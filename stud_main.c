#include <stdio.h>
#include "student.h"

static void show_menu(void)
{
    printf("\n******** STUDENT RECORD MENU ********\n");
    printf("a/A : Add new record\n");
    printf("d/D : Delete a record\n");
    printf("s/S : Show the list\n");
    printf("m/M : Modify a record\n");
    printf("v/V : Save records\n");
    printf("e/E : Exit\n");
    printf("t/T : Sort the list\n");
    printf("l/L : Delete all the records\n");
    printf("r/R : Reverse the list\n");
    printf("Enter your choice: ");
}

int main(void)
{
    struct student *head = NULL;   /* start of the list */
    char choice, ex;
    int done = 0;

    head = stud_load();            /* load student.dat if it exists */

    while (!done)
    {
        show_menu();
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'a': case 'A':
                head = stud_add(head);
                break;

            case 'd': case 'D':
                head = stud_del(head);
                break;

            case 's': case 'S':
                stud_show(head);
                break;

            case 'm': case 'M':
                stud_mod(head);
                break;

            case 'v': case 'V':
                stud_save(head);
                break;

            case 't': case 'T':
                head = stud_sort(head);
                break;

            case 'l': case 'L':
                head = stud_delall(head);
                printf("All records deleted from memory.\n");
                break;

            case 'r': case 'R':
                head = stud_rev(head);
                break;

            case 'e': case 'E':
                printf("S/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter your choice: ");
                scanf(" %c", &ex);

                if (ex == 's' || ex == 'S')
                {
                    stud_save(head);
                    head = stud_delall(head);   /* free all nodes */
                    done = 1;
                }
                else if (ex == 'e' || ex == 'E')
                {
                    head = stud_delall(head);   /* free all nodes, no save */
                    done = 1;
                }
                else
                    printf("Invalid choice. Returning to menu.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
