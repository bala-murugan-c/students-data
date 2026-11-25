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

## Functions

### stud_main.c

| Function | Description |
|---|---|
| `main()` | Loads `student.dat`, shows the menu in a loop, calls the function for the chosen option, and frees all nodes before exiting. |
| `show_menu()` | Prints the main menu. |

### stud_add.c

| Function | Description |
|---|---|
| `stud_add()` | Reads the name and percentage, validates them, creates a node with `malloc()`, and links it at the end of the list. |
| `next_rollno()` | Returns the smallest positive roll number not already in use. |
| `roll_exists()` | Checks whether a roll number is already in the list. |

### stud_del.c

| Function | Description |
|---|---|
| `stud_del()` | Deletes a record by roll number or by name. For a name, it lists all matches and deletes the roll number the user chooses. |
| `delete_by_roll()` | Unlinks the node with the given roll number and frees its memory. |
| `find_roll()` | Returns the node with the given roll number, or `NULL`. |
| `read_roll()` | Reads a roll number and rejects input that is not a number. |

### stud_show.c

| Function | Description |
|---|---|
| `stud_show()` | Prints all records in a table, or a message if the list is empty. |

### stud_mod.c

| Function | Description |
|---|---|
| `stud_mod()` | Finds a record by roll number, name or percentage. If several match, it lists them and asks for the roll number. |
| `edit_node()` | Shows the current details and updates the name and percentage. The roll number never changes. |
| `matches()` | Checks whether a node fits the name or percentage searched. |
| `find_roll()` | Returns the node with the given roll number, or `NULL`. |
| `read_roll()` | Reads a roll number and rejects input that is not a number. |

### stud_save.c

| Function | Description |
|---|---|
| `stud_save()` | Writes all records to `student.dat`, one line per record. |
| `stud_load()` | Reads `student.dat` at startup and builds the linked list. Returns an empty list if the file does not exist. |

### stud_sort.c

| Function | Description |
|---|---|
| `stud_sort()` | Sorts the list by name (A to Z) or by percentage (highest first) by relinking the nodes. |
| `comes_before()` | Decides which of two nodes should come first for the chosen sort. |

### stud_delall.c

| Function | Description |
|---|---|
| `stud_delall()` | Frees every node and returns `NULL` so the head pointer is reset. Does not touch `student.dat`. |

### stud_rev.c

| Function | Description |
|---|---|
| `stud_rev()` | Reverses the list by changing the `next` pointers, without creating new nodes. |

## Note

Records are saved in `student.dat`, one per line as `rollno,percentage,name`. If `student.dat` does not exist, the program starts with an empty list.
