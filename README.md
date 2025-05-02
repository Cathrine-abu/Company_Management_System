# Company Management System

A **Company Management System** developed in **C**, simulating real-world company operations with dynamic memory handling, struct-based modeling, and interactive user interaction.

---

## Features

- Add new workers to the company  
- Open new projects and assign workers  
- Join workers to existing projects  
- Add/remove project features  
- View all active projects  
- View workers’ project assignments  
- Remove workers and auto-update project references  
- Interactive menu with safe input handling

---

## Technologies Used

- C (Programming Language)  
- Dynamic Memory Allocation  
- Structs and Linked Lists  
- Modular Code Design using `.h` and `.c` files

---

## Skills Demonstrated

- Proper use of `malloc`, `realloc`, and `free`  
- Avoidance of memory leaks  
- Data structure design using arrays, linked lists and pointers 
- Modular architecture  
- User interaction with validation

---

## Setup and Usage

1. **Clone the repository:**

    ```bash
    https://github.com/Cathrine-abu/Company_Management_System.git
    ```

2. **Navigate to the project directory:**

    ```bash
    cd Company-Management-System
    ```

3. **Compile and run using `make`:**

    ```bash
    make run
    ```

4. **If `make` is not installed, you can compile manually:**

    ```bash
    gcc -o company_management_system src/company_management_system.c
    ./company_management_system
    ```

5. **To clean the executable:**

    ```bash
    make clean
    ```

---

## Project Structure

- `src/` – Contains the C source code and header files  
- `src/company_management_system.c` – Main program logic  
- `src/company_management_system.h` – Struct definitions and function declarations  
- `Makefile` – Automates the build and clean processes

---

## Author

**Cathrine Abu-Elazam**  
Bar-Ilan University  
Project Duration: Jan 2024 – Mar 2024
