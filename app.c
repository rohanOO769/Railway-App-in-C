#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store information about each train
typedef struct {
    int train_number;
    char source[50];
    char destination[50];
    int num_seats;
    int available_seats;
} train;

// Define a function to book tickets
void book_tickets(train* trains, int num_trains) {
    int train_number, num_tickets;

    // Print the list of available trains
    printf("Available trains:\n");
    for (int i = 0; i < num_trains; i++) {
        printf("%d. %s to %s (%d seats available)\n", trains[i].train_number, trains[i].source, trains[i].destination, trains[i].available_seats);
    }

    // Ask the user to select a train
    printf("Enter the number of the train you want to book: ");
    scanf("%d", &train_number);

    // Find the selected train in the array
    int index = -1;
    for (int i = 0; i < num_trains; i++) {
        if (trains[i].train_number == train_number) {
            index = i;
            break;
        }
    }

    // If the selected train is not found, print an error message and return
    if (index == -1) {
        printf("Invalid train number.\n");
        return;
    }

    // Ask the user to enter the number of tickets they want to book
    printf("Enter the number of tickets you want to book: ");
    scanf("%d", &num_tickets);

    // Check if there are enough available seats on the selected train
    if (num_tickets > trains[index].available_seats) {
        printf("Not enough seats available.\n");
        return;
    }

    // Update the available seats on the selected train
    trains[index].available_seats -= num_tickets;

    // Generate a reservation number (PRN)
    int prn = rand() % 10000 + 1;

    // Print a confirmation message with the reservation number
    printf("%d tickets booked successfully. Your PRN is %d.\n", num_tickets, prn);
}

// Define a function to cancel tickets
void cancel_tickets(train* trains, int num_trains) {
    int train_number, prn, num_tickets;

    // Print the list of booked tickets with PRNs
    printf("Your booked tickets:\n");
    for (int i = 0; i < num_trains; i++) {
        if (trains[i].num_seats - trains[i].available_seats > 0) {
            printf("%d. %s to %s (%d tickets booked) PRN: %d\n", trains[i].train_number, trains[i].source, trains[i].destination, trains[i].num_seats - trains[i].available_seats, rand() % 10000 + 1);
        }
    }

    // Ask the user to select a train
printf("Enter the number of the train you want to cancel tickets for: ");
scanf("%d", &train_number);

// Find the selected train in the array
int index = -1;
for (int i = 0; i < num_trains; i++) {
    if (trains[i].train_number == train_number) {
        index = i;
        break;
    }
}

// If the selected train is not found, print an error message and return
if (index == -1) {
    printf("Invalid train number.\n");
    return;
}

// Ask the user to enter the reservation number (PRN) of the tickets they want to cancel
printf("Enter the PRN of the tickets you want to cancel: ");
scanf("%d", &prn);

// Calculate the number of tickets booked with the given PRN
num_tickets = 0;
for (int i = 0; i < trains[index].num_seats; i++) {
    if (trains[index].available_seats == trains[index].num_seats && trains[index].available_seats > 0) {
        num_tickets++;
    }
}

// If the PRN is not found or there are no tickets booked with the given PRN, print an error message and return
if (num_tickets == 0) {
    printf("Invalid PRN.\n");
    return;
}

// Update the available seats on the selected train
trains[index].available_seats += num_tickets;

// Print a confirmation message with the number of tickets canceled
printf("%d tickets canceled successfully.\n", num_tickets);
}

// Define a function to check seat availability
void check_seat_availability(train* trains, int num_trains) {
int train_number;
// Print the list of available trains
printf("Available trains:\n");
for (int i = 0; i < num_trains; i++) {
    printf("%d. %s to %s (%d seats available)\n", trains[i].train_number, trains[i].source, trains[i].destination, trains[i].available_seats);
}

// Ask the user to select a train
printf("Enter the number of the train you want to check seat availability for: ");
scanf("%d", &train_number);

// Find the selected train in the array
int index = -1;
for (int i = 0; i < num_trains; i++) {
    if (trains[i].train_number == train_number) {
        index = i;
        break;
    }
}

// If the selected train is not found, print an error message and return
if (index == -1) {
    printf("Invalid train number.\n");
    return;
}

// Print the number of available seats on the selected train
printf("There are %d seats available on train number %d.\n", trains[index].available_seats, train_number);
}

// Define a function to access the reservation number (PRN)
void access_prn(train* trains, int num_trains) {
    int train_number, seat_number;
    // Print the list of booked tickets with PRNs
    printf("Your booked tickets:\n");
    for (int i = 0; i < num_trains; i++) {
        for (int j = 0; j < trains[i].num_seats; j++) {
            if (trains[i].seats[j].is_booked) {
                printf("Train number %d, Seat number %d, PRN: %d\n", trains[i].train_number, j+1, trains[i].seats[j].prn);
            }
        }
    }
    // Ask the user to select a train
    printf("Enter the number of the train you want to access the PRN for: ");
    scanf("%d", &train_number);

    // Find the selected train in the array
    int index = -1;
    for (int i = 0; i < num_trains; i++) {
        if (trains[i].train_number == train_number) {
            index = i;
            break;
        }
    }

    // If the selected train is not found, print an error message and return
    if (index == -1) {
        printf("Invalid train number.\n");
        return;
    }

    // Ask the user to enter the seat number of the ticket they want to access the PRN for
    printf("Enter the seat number of the ticket you want to access the PRN for: ");
    scanf("%d", &seat_number);

    // If the selected seat is not booked, print an error message and return
    if (!trains[index].seats[seat_number - 1].is_booked) {
        printf("Seat number %d is not booked.\n", seat_number);
        return;
    }

    // Print the PRN of the selected ticket
    printf("The PRN of the ticket with seat number %d on train number %d is %d.\n", seat_number, train_number, trains[index].seats[seat_number - 1].prn);
}


// Define the main function
int main() {
train trains[MAX_TRAINS];
int num_trains = 0;
int choice;
// Display the menu and ask the user for their choice
while (1) {
    printf("\n");
    printf("1. Book ticket\n");
    printf("2. Cancel ticket\n");
    printf("3. Check seat availability\n");
    printf("4. Access reservation number (PRN)\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            book_ticket(trains, num_trains);
            break;
        case 2:
            cancel_ticket(trains, num_trains);
            break;
        case 3:
            check_seat_availability(trains, num_trains);
            break;
        case 4:
            access_prn(trains, num_trains);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
    }
}

return 0;
}

