#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 500

char *lines[MAX_LINES];
int lineCount = 0;

// Remove newline from input
void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Display all lines
void display() {
    if (lineCount == 0) {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n----- Document -----\n");

    for (int i = 0; i < lineCount; i++) {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

// Insert a line
void insertLine() {
    if (lineCount >= MAX_LINES) {
        printf("Document is full!\n");
        return;
    }

    int position;
    char text[MAX_LENGTH];

    printf("Enter line number to insert at (1-%d): ", lineCount + 1);
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount + 1) {
        printf("Invalid line number!\n");
        return;
    }

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);
    removeNewline(text);

    // Shift lines down
    for (int i = lineCount; i >= position; i--) {
        lines[i] = lines[i - 1];
    }

    // Allocate memory for new line
    lines[position - 1] = malloc(strlen(text) + 1);

    if (lines[position - 1] == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(lines[position - 1], text);

    lineCount++;

    printf("Line inserted successfully.\n");
}

// Delete a line
void deleteLine() {
    if (lineCount == 0) {
        printf("Document is empty!\n");
        return;
    }

    int position;

    printf("Enter line number to delete (1-%d): ", lineCount);
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount) {
        printf("Invalid line number!\n");
        return;
    }

    // Free memory of deleted line
    free(lines[position - 1]);

    // Shift remaining lines up
    for (int i = position - 1; i < lineCount - 1; i++) {
        lines[i] = lines[i + 1];
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

// Save document to file
void saveFile() {
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);
    getchar();

    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Could not open file!\n");
        return;
    }

    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("Document saved successfully.\n");
}

// Load document from file
void loadFile() {
    char filename[100];
    char buffer[MAX_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);
    getchar();

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file!\n");
        return;
    }

    // Clear current document
    for (int i = 0; i < lineCount; i++) {
        free(lines[i]);
    }

    lineCount = 0;

    // Read lines from file
    while (fgets(buffer, MAX_LENGTH, file) != NULL) {

        if (lineCount >= MAX_LINES) {
            printf("Maximum line limit reached.\n");
            break;
        }

        removeNewline(buffer);

        lines[lineCount] = malloc(strlen(buffer) + 1);

        if (lines[lineCount] == NULL) {
            printf("Memory allocation failed!\n");
            break;
        }

        strcpy(lines[lineCount], buffer);

        lineCount++;
    }

    fclose(file);

    printf("Document loaded successfully.\n");
}

// Free all memory
void cleanup() {
    for (int i = 0; i < lineCount; i++) {
        free(lines[i]);
    }
}

int main() {

    int choice;

    printf("================================\n");
    printf("       SIMPLE LINE EDITOR       \n");
    printf("================================\n");

    while (1) {

        printf("\n");
        printf("1. Insert line\n");
        printf("2. Delete line\n");
        printf("3. Display document\n");
        printf("4. Save file\n");
        printf("5. Load file\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
                insertLine();
                break;

            case 2:
                deleteLine();
                break;

            case 3:
                display();
                break;

            case 4:
                saveFile();
                break;

            case 5:
                loadFile();
                break;

            case 6:
                cleanup();
                printf("Exiting editor...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}