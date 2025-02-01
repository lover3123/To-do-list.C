#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Task structure
typedef struct {
    char *task;
    int completed;
} Task;

// Global variables
Task *tasks = NULL;
int length = 0;

// Function prototypes
void addTask(const char *task);
void listTasks();
void markCompleted(int index);
void deleteTask(int index);
void editTask(int index, const char *editedTask);

int main() {
    int running = 1;
    while (running) {
        printf("\nOptions:\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Edit Task\n");
        printf("5. Delete Task\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1: {
                char taskInput[100];
                printf("Enter task: ");
                fgets(taskInput, sizeof(taskInput), stdin);
                taskInput[strcspn(taskInput, "\n")] = '\0'; // Remove trailing newline
                addTask(taskInput);
                break;
            }
            case 2:
                listTasks();
                break;
            case 3: {
                int indexInput;
                printf("Enter index: ");
                scanf("%d", &indexInput);
                getchar(); // Consume the newline character
                markCompleted(indexInput);
                break;
            }
            case 4: {
                int indexInput;
                char taskInput[100];
                printf("Enter index: ");
                scanf("%d", &indexInput);
                getchar(); // Consume the newline character
                printf("Enter edited task: ");
                fgets(taskInput, sizeof(taskInput), stdin);
                taskInput[strcspn(taskInput, "\n")] = '\0'; // Remove trailing newline
                editTask(indexInput, taskInput);
                break;
            }
            case 5: {
                int indexInput;
                printf("Enter index: ");
                scanf("%d", &indexInput);
                getchar(); // Consume the newline character
                deleteTask(indexInput);
                break;
            }
            case 6:
                running = 0;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    // Free allocated memory
    for (int i = 0; i < length; i++) {
        free(tasks[i].task);
    }
    free(tasks);

    return 0;
}

// Function to add a task
void addTask(const char *task) {
    tasks = realloc(tasks, (length + 1) * sizeof(Task));
    tasks[length].task = malloc(strlen(task) + 1);
    strcpy(tasks[length].task, task);
    tasks[length].completed = 0;
    length++;
    printf("Task added successfully!\n");
}

// Function to list all tasks
void listTasks() {
    if (length == 0) {
        printf("No tasks available.\n");
        return;
    }
    for (int i = 0; i < length; i++) {
        char status = tasks[i].completed ? 'D' : 'N';
        printf("%d. %s [%c]\n", i + 1, tasks[i].task, status);
    }
}

// Function to mark a task as completed
void markCompleted(int index) {
    if (index > 0 && index <= length) {
        tasks[index - 1].completed = 1;
        printf("Task marked as completed!\n");
    } else {
        printf("Invalid index!\n");
    }
}

// Function to delete a task
void deleteTask(int index) {
    if (index > 0 && index <= length) {
        free(tasks[index - 1].task);
        for (int i = index - 1; i < length - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        length--;
        tasks = realloc(tasks, length * sizeof(Task));
        printf("Task deleted successfully!\n");
    } else {
        printf("Invalid index!\n");
    }
}

// Function to edit a task
void editTask(int index, const char *editedTask) {
    if (index > 0 && index <= length) {
        tasks[index - 1].task = realloc(tasks[index - 1].task, strlen(editedTask) + 1);
        strcpy(tasks[index - 1].task, editedTask);
        printf("Task updated successfully!\n");
    } else {
        printf("Invalid index!\n");
    }
}