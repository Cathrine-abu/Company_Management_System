# Company Management System

A **Company Management System** developed in **C**, simulating real-world company operations with dynamic memory handling, struct-based modeling, and interactive user interaction.

---

## Features

- Add new workers to the company
- Open new projects and assign workers
- Join workers to existing projects
- Add/remove project features
- View all active projects
- View workers' project assignments
- Remove workers and update all related data
- Menu-driven interface for smooth user experience

---

## Technologies Used

- C (Programming Language)
- Dynamic Memory Allocation
- Structs and Linked Lists
- Modular Code Design with `.h` and `.c` files

---

## Skills Demonstrated

- Proper use of `malloc`, `realloc`, and `free`
- Avoidance of memory leaks
- Use of arrays of pointers to manage relationships between entities
- Clear separation of logic into modular components
- Validation of user input and edge case handling

---

## Setup and Usage

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Cathrine-abu/Company_Management_System.git
Navigate to the project directory:

bash
Copy
Edit
cd Company-Management-System
Compile and run using make:

bash
Copy
Edit
make run
If make is not installed, you can compile manually:

bash
Copy
Edit
gcc -o company_management_system src/company_management_system.c
./company_management_system
To clean the executable:

bash
Copy
Edit
make clean
Project Structure
src/: Contains the C source code and header files.

src/company_management_system.c: The main file containing all program logic.

src/company_management_system.h: Declarations and definitions shared across the project.

Makefile: Automates the build and run process using Make.

