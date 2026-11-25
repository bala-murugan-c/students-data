#ifndef STUDENT_H
#define STUDENT_H

struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

/* stud_add.c */
struct student *stud_add(struct student *head);

/* stud_del.c */
struct student *stud_del(struct student *head);

/* stud_show.c */
void stud_show(struct student *head);

/* stud_mod.c */
void stud_mod(struct student *head);

/* stud_save.c */
void stud_save(struct student *head);
struct student *stud_load(void);

/* stud_sort.c, stud_delall.c, stud_rev.c */
struct student *stud_sort(struct student *head);
struct student *stud_delall(struct student *head);
struct student *stud_rev(struct student *head);

#endif
