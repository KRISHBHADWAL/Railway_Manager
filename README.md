Sure, here is the updated description with the changes:

---

# Railway_Manager in C++

## Overview

This project is a fully functional Railway Management System implemented in C++. It allows users to book and manage train tickets, view train schedules, and track train routes. The system is designed with an emphasis on modularity and object-oriented principles, making it easy to extend and maintain.

## Features

### User Functions:
- **Book Tickets**: Users can book train tickets by specifying the train ID and their name.
- **Manage Tickets**: View all bookings made by the user.
- **View Train Schedules**: Check the schedules of specific trains including departure and arrival times.

### Admin Functions:
- **Add New Trains**: Admin can add new trains to the system with details like train ID, name, source, destination, departure time, arrival time, and total seats.
- **Modify Train Schedules**: Admin can update the schedules and other details of existing trains.
- **View All Bookings**: Admin can view all the bookings made in the system.

## Installation

1. **Clone the Repository**
   ```sh
   git clone https://github.com/KRISHBHADWAL/Railway_Manager.git
   cd Railway_Manager
   ```

2. **Compile the Code**
   ```sh
   g++ main.cpp -o railway_management_system
   ```

3. **Run the Program**
   ```sh
   ./railway_management_system
   ```

## Usage

Upon running the program, you will be presented with options to view train schedules, book tickets, and manage your bookings. Admin functionalities are integrated within the same system, allowing for seamless management of trains and bookings.

## Project Structure

- **main.cpp**: The main entry point of the application.
- **Train.h/Train.cpp**: Contains the definition and implementation of the Train class.
- **Booking.h/Booking.cpp**: Contains the definition and implementation of the Booking class.
- **RailwayManagementSystem.h/RailwayManagementSystem.cpp**: Contains the definition and implementation of the Railway Management System class.

## Contributing

Contributions are welcome! Please fork this repository and submit a pull request for any enhancements, bug fixes, or new features.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

---
