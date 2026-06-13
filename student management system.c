#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to define a student record
struct Student {
    int id;
    char name[50];
    char course[50];
    int age;
    float marks;
};

// Global variable for file pointer
FILE *fp;

// Function to add a student record
void addStudent() {
    struct Student s;
    
    printf("\n=== Add Student Record ===\n");
    
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    
    printf("Enter Student Name: ");
    scanf("%s", s.name);
    
    printf("Enter Course: ");
    scanf("%s", s.course);
    
    printf("Enter Age: ");
    scanf("%d", &s.age);
    
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    
    // Open file in append mode
    fp = fopen("student_records.dat", "ab");
    
    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }
    
    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);
    
    printf("\nStudent record added successfully!\n");
}

// Function to display all student records
void displayAllStudents() {
    struct Student s;
    
    printf("\n=== All Student Records ===\n");
    
    fp = fopen("student_records.dat", "rb");
    
    if (fp == NULL) {
        printf("\nNo records found! File doesn't exist.\n");
        return;
    }
    
    int count = 0;
    
    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        count++;
        printf("\n--- Record #%d ---\n", count);
        printf("ID: %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("Course: %s\n", s.course);
        printf("Age: %d\n", s.age);
        printf("Marks: %.2f\n", s.marks);
    }
    
    fclose(fp);
    
    if (count == 0) {
        printf("\nNo records found!\n");
    } else {
        printf("\nTotal records: %d\n", count);
    }
}

// Function to search for a student by ID
void searchStudent() {
    struct Student s;
    int id, found = 0;
    
    printf("\n=== Search Student ===\n");
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    
    fp = fopen("student_records.dat", "rb");
    
    if (fp == NULL) {
        printf("\nNo records found! File doesn't exist.\n");
        return;
    }
    
    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.id == id) {
            found = 1;
            printf("\n--- Student Found ---\n");
            printf("ID: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("Course: %s\n", s.course);
            printf("Age: %d\n", s.age);
            printf("Marks: %.2f\n", s.marks);
            break;
        }
    }
    
    fclose(fp);
    
    if (!found) {
        printf("\nStudent with ID %d not found!\n", id);
    }
}

// Function to update a student record
void updateStudent() {
    struct Student s;
    int id, found = 0, pos = 0;
    
    printf("\n=== Update Student ===\n");
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    
    fp = fopen("student_records.dat", "rb");
    
    if (fp == NULL) {
        printf("\nNo records found! File doesn't exist.\n");
        return;
    }
    
    // Find the record
    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        pos++;
        if (s.id == id) {
            found = 1;
            break;
        }
    }
    
    fclose(fp);
    
    if (!found) {
        printf("\nStudent with ID %d not found!\n", id);
        return;
    }
    
    // Display current record
    printf("\nCurrent Record:\n");
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Course: %s\n", s.course);
    printf("Age: %d\n", s.age);
    printf("Marks: %.2f\n", s.marks);
    
    // Get updated data
    printf("\nEnter New Name (or press Enter to keep current): ");
    scanf("%s", s.name);
    
    printf("Enter New Course (or press Enter to keep current): ");
    scanf("%s", s.course);
    
    printf("Enter New Age: ");
    scanf("%d", &s.age);
    
    printf("Enter New Marks: ");
    scanf("%f", &s.marks);
    
    // Open file in write mode to update
    fp = fopen("student_records.dat", "rb+");
    
    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }
    
    // Seek to the position of the record and write
    fseek(fp, (pos - 1) * sizeof(struct Student), SEEK_SET);
    fwrite(&s, sizeof(struct Student), 1, fp);
    
    fclose(fp);
    
    printf("\nStudent record updated successfully!\n");
}

// Function to delete a student record
void deleteStudent() {
    struct Student s, temp;
    int id, found = 0;
    
    printf("\n=== Delete Student ===\n");
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    
    fp = fopen("student_records.dat", "rb");
    
    if (fp == NULL) {
        printf("\nNo records found! File doesn't exist.\n");
        return;
    }
    
    // Create a temporary file
    FILE *tempFile = fopen("temp_records.dat", "wb");
    
    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.id == id) {
            found = 1;
        } else {
            fwrite(&s, sizeof(struct Student), 1, tempFile);
        }
    }
    
    fclose(fp);
    fclose(tempFile);
    
    if (!found) {
        printf("\nStudent with ID %d not found!\n", id);
        remove("temp_records.dat");
        return;
    }
    
    // Replace original file with temp file
    remove("student_records.dat");
    rename("temp_records.dat", "student_records.dat");
    
    printf("\nStudent record deleted successfully!\n");
}

// Main function with menu
int main() {
    int choice;
    
    printf("\n========================================\n");
    printf("   STUDENT RECORD MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    
    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Add Student Record\n");
        printf("2. Delete Student Record\n");
        printf("3. Update Student Record\n");
        printf("4. Search Student Record\n");
        printf("5. Display All Records\n");
        printf("6. Exit\n");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                displayAllStudents();
                break;
            case 6:
                printf("\nThank you for using Student Record Management System!\n");
                printf("Exiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 6.\n");
        }
    }
    
    return 0;
}