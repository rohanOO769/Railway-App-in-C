# Railway Ticketing App
This is a simple command-line application that allows users to book and cancel tickets, check seat availability, and access their reservation number (PRN) for trains.

# Installation
Clone this repository to your local machine.
Compile the app.c file using a C compiler. For example, using gcc: gcc app.c -o app.
Run the app executable to start the application.

# Usage
The application will display a menu with the following options:

Book Ticket
Cancel Ticket
Check Seat Availability
Access PRN
Exit
Use the arrow keys to select an option and press Enter to confirm your selection.

## Booking a Ticket
To book a ticket, select the "Book Ticket" option from the main menu. You will be prompted to enter the source and destination stations, as well as the number of tickets you want to book. If seats are available on the selected train, the application will display the fare and ask you to confirm the booking. After confirmation, the application will generate a unique PRN for your reservation.

## Cancelling a Ticket
To cancel a ticket, select the "Cancel Ticket" option from the main menu. You will be prompted to enter your PRN. If the PRN is valid and the ticket has not already been cancelled, the application will cancel the ticket and update the seat availability for the corresponding train.

## Checking Seat Availability
To check seat availability, select the "Check Seat Availability" option from the main menu. You will be prompted to enter the source and destination stations and the date of travel. The application will display a list of available trains and their current seat availability.

## Accessing PRN
To access your PRN, select the "Access PRN" option from the main menu. The application will display a list of your booked tickets along with their corresponding PRNs. You will be prompted to select a ticket and enter the seat number. The application will then display the PRN for that ticket.

# Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
