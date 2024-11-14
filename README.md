# Railway Ticketing System

A simple C program for managing railway ticket reservations and waiting lists. The program allows users to book tickets, cancel reservations, view the reservation and waiting lists, and manage waiting list cancellations.

## Features

- **Book a Ticket**: Reserves a ticket if seats are available; otherwise, adds the user to the waiting list.
- **Cancel Reservation**: Removes a reservation and, if there are waiting list entries, moves the first waiting list entry to the reservation list.
- **Display Lists**: Displays both reservation and waiting lists.
- **Cancel Waiting List Ticket**: Removes a person from the waiting list.

## How It Works

The system has two lists:
- **Reservation List** (limited to 5 reservations)
- **Waiting List** (unlimited capacity)

### Structs Used

- **Reservation**: Stores reservation details with fields for name, reservation number, and a link to the next reservation.
- **WaitingList**: Stores waiting list details with fields for name, waiting number, and a link to the next waiting list entry.

### Reservation Process

- If the reservation list is full, the user is added to the waiting list.
- Canceling a reservation moves the first person from the waiting list to the reservation list.

## Code Structure

### Functions

1. **`create_Reservation`**: Creates a reservation node.
2. **`create_Waiting`**: Creates a waiting list node.
3. **`Insert_Waiting`**: Adds a person to the waiting list.
4. **`ResIsFull`**: Checks if the reservation list has reached its limit.
5. **`Insert_Reservation`**: Adds a person to the reservation list if there is space, otherwise adds them to the waiting list.
6. **`Delete`**: Removes a person from either the reservation or waiting list.
7. **`display`**: Displays the reservation or waiting list.

## Usage

To use the Railway Ticketing System:

1. Compile the program using a C compiler:
   ```bash
   gcc -o ticket ticket.c
2. Run the compiled program:
   ```bash
   ./ticket
