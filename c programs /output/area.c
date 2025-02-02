#include <stdio.h>

int main() {
    // Print a greeting message
    printf("Hello, welcome to the C program projection!\n");

    // Projecting a simple task message
    printf("This program will calculate the area of a rectangle.\n");

    // Declare variables
    float length, width, area;

    // Get user input for length and width
    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%f", &width);

    // Calculate the area of the rectangle
    area = length * width;

    // Display the result
    printf("The area of the rectangle is: %.2f\n", area);

    return 0;
    
}
