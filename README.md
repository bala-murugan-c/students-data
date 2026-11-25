# Student Record Management System

Mini Project - II (C Programming)

A menu-driven program to manage student records using a singly linked list, dynamic memory allocation and file handling.

## Compile

```
make
```

Or without make:

```
gcc -o student stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c stud_sort.c stud_delall.c stud_rev.c
```

## Run

```
./student
```

On Windows, run `student.exe`.

## Menu

```
a/A : Add new record
d/D : Delete a record
s/S : Show the list
m/M : Modify a record
v/V : Save records to student.dat
e/E : Exit (save and exit, or exit without saving)
t/T : Sort the list (by name or percentage)
l/L : Delete all the records
r/R : Reverse the list
```

## Note

Records are saved in `student.dat`, one per line as `rollno,percentage,name`. If `student.dat` does not exist, the program starts with an empty list.
