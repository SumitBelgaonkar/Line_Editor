# Line_Editor
Simple Line Editor in C

Team Members

Sumit Belgaonkar - R25EJ155

Sankalp Todkari - R25EJ134

Saksham Agarwal - R25EJ130

Project Overview

The Simple Line Editor is a command-line text editor written in C.
It allows users to create, view, modify, save, and load a small text
document directly from the terminal.

The document is stored in memory using an array of character pointers.
Each line is dynamically allocated, allowing lines to be inserted and
deleted while managing memory efficiently.

Implemented Features

The following features have been implemented:

Core Features

Insert a Line

Adds a new line at a specified line number.

Existing lines are shifted down to make space.

Delete a Line

Removes a selected line.

The lines below it are shifted upward.

Memory allocated for the deleted line is released.

Display the Document

Displays all current lines.

Each line is shown with its corresponding line number.

Additional Feature

Save / Load a File

Saves the current document to a text file.

Loads an existing text file into the editor.

The document is stored in memory while the editor is running.

Data Structure

The editor uses:

char *lines[MAX_LINES];

Each element of the array is a pointer to a dynamically allocated
string containing one line of the document.

Why this data structure?

A dynamic array of character pointers is simple to implement and
understand. It also makes insertion and deletion straightforward by
shifting pointers. For a small line editor, this approach provides
good performance while keeping the implementation manageable.

Requirements

C compiler such as GCC

Windows, Linux, or another operating system with a terminal

Compilation

Open a terminal in the project directory and run:

gcc proj.c -o proj.exe

On Linux/macOS, you can use:

gcc proj.c -o proj

Running the Editor

Windows PowerShell

.\proj.exe

Linux/macOS

./proj

Main Menu

When the program starts, the following menu is displayed:

1. Insert line
2. Delete line
3. Display document
4. Save file
5. Load file
6. Exit

Select the required option by entering its number.

Example

Enter your choice: 1
Enter line number to insert at (1-1): 1
Enter text: Hello World
Line inserted successfully.

Enter your choice: 3

----- Document -----
1: Hello World
--------------------

Enter your choice: 4
Enter filename: document.txt
Document saved successfully.

Project Files

proj.c - Main C source code for the line editor.

help.txt - Help file explaining the supported commands and usage.

README.md - Project documentation, team information, features,
and compilation/run instructions.

Notes

The editor supports up to 100 lines.

Each line can contain up to 500 characters.

Dynamically allocated memory is freed when lines are deleted or
when the editor exits.