#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Define the structure for Passenger
typedef struct Passenger {
    char pnr[20];
    char name[50];
    int age;
    char berth[10];
    int coach;
    char source[50];
    char destination[50];
} Passenger;

// Declare an array of Passenger structures and a counter for the number of passengers
Passenger p[MAX];
int count = 0;

// Function prototypes
void add_passenger(void);
void search_pnr(void);
void print_senior_citizens(void);
void print_lower_berth_passengers(void);

int main() {
    int choice;
    // Main menu loop
    while (1) {
        // Display menu options
        printf("\n\n **** INDIAN RAILWAY RESERVATION SYSTEM **** \n");
        printf("1. Add Passenger\n");
        printf("2. Search PNR\n");
        printf("3. Print Senior Citizens Details\n");
        printf("4. Print Lower Berth Passengers\n");
        printf("5. Exit\n");

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch based on user choice
        switch (choice) {
            case 1:
                add_passenger();
                break;
            case 2:
                search_pnr();
                break;
            case 3:
                print_senior_citizens();
                break;
            case 4:
                print_lower_berth_passengers();
                break;
            case 5:
                // Exit the program
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}

// Function to add a new passenger
void add_passenger() {
    if (count >= MAX) {
        // Display a message if the train is full
        printf("Train is full. No more bookings are allowed.\n");
        return;
    }

    // Get details from the user
    printf("Enter PNR: ");
    scanf("%s", p[count].pnr);

    printf("Enter Name: ");
    scanf("%s", p[count].name);

    // Validate age input
    while (1) {
        printf("Enter Age: ");
        scanf("%d", &p[count].age);
        if (p[count].age >= 0 && p[count].age <= 100) {
            break;  // Exit the loop if valid input
        } else {
            printf("Invalid age. Please enter an age between 0 and 100.\n");
        }
    }

    // Validate berth input
    while (1) {
        printf("Enter Berth (upper/lower): ");
        scanf("%s", p[count].berth);
        if (strcmp(p[count].berth, "upper") == 0 || strcmp(p[count].berth, "lower") == 0) {
            break;  // Exit the loop if valid input
        } else {
            printf("Invalid input. Please enter 'upper' or 'lower'.\n");
        }
    }

    printf("Enter Coach Number: ");
    scanf("%d", &p[count].coach);

    printf("Enter Source Station: ");
    scanf("%s", p[count].source);

    printf("Enter Destination Station: ");
    scanf("%s", p[count].destination);

    // Increment the passenger count
    count++;
    printf("Passenger added successfully.\n");
}

// Function to search for a passenger by PNR
void search_pnr() {
    char pnr[20];
    int i, found = 0;

    // Get the PNR to search for
    printf("Enter PNR to search: ");
    scanf("%s", pnr);

    // Search for the passenger with the given PNR
    for (i = 0; i < count; i++) {
        if (strcmp(p[i].pnr, pnr) == 0) {
            // Display details if found
            printf("\n--- Passenger Found ---\n");
            printf("PNR: %s\n", p[i].pnr);
            printf("Name: %s\n", p[i].name);
            printf("Age: %d\n", p[i].age);
            printf("Berth: %s\n", p[i].berth);
            printf("Coach Number: %d\n", p[i].coach);
            printf("Source Station: %s\n", p[i].source);
            printf("Destination Station: %s\n", p[i].destination);
            found = 1;
            break;
        }
    }

    // Display a message if not found
    if (!found) {
        printf("No passenger found with PNR %s.\n", pnr);
    }
}

// Function to print details of senior citizens
void print_senior_citizens() {
    int i, found = 0;

    // Display header
    printf("\n--- Senior Citizens (Age 60+) ---\n");
    printf("PNR\tName\tAge\tBerth\tCoach\tSource\tDestination\n");

    // Print details of senior citizens
    for (i = 0; i < count; i++) {
        if (p[i].age >= 60) {
            printf("%s\t%s\t%d\t%s\t%d\t%s\t%s\n", p[i].pnr, p[i].name, p[i].age, p[i].berth,
                   p[i].coach, p[i].source, p[i].destination);
            found = 1;
        }
    }

    if (!found) {
        printf("No senior citizen records found.\n");
    }
}

// Function to print details of passengers booked in lower berths
void print_lower_berth_passengers() {
    int i, found = 0;

    // Display header
    printf("\n--- Passengers with Lower Berth ---\n");
    printf("PNR\tName\tAge\tBerth\tCoach\tSource\tDestination\n");

    // Print details of passengers booked in lower berths
    for (i = 0; i < count; i++) {
        if (strcmp(p[i].berth, "lower") == 0) {
            printf("%s\t%s\t%d\t%s\t%d\t%s\t%s\n", p[i].pnr, p[i].name, p[i].age, p[i].berth,
                   p[i].coach, p[i].source, p[i].destination);
            found = 1;
        }
    }

    if (!found) {
        printf("No passengers with lower berth found.\n");
    }
}
