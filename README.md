# 🏢 **Company Management System – C Project**

## 🚀 **Overview**
The **Company Management System** is a fully interactive console application written in **C**, designed to simulate real-world company operations.  
It demonstrates advanced **memory management**, **data structure design**, and **modular architecture** using headers and source files.  
Users can dynamically manage employees, projects, and assignments in a clean and intuitive menu-driven environment.

---

## ✨ **Key Features**

- 👤 **Add and Remove Workers** – Dynamically allocate memory and manage worker records.  
- 🧩 **Project Management** – Create new projects, assign workers, and modify project attributes.  
- 🔗 **Linked Data Relationships** – Automatically update project lists when workers are added or removed.  
- 📊 **Display Functions** – View all active projects and current worker assignments.  
- 🧮 **Interactive Menu** – User-friendly interface with input validation and error handling.

---

## 🧠 **Technologies & Concepts**

| **Category** | **Details** |
|---------------|-------------|
| **Language** | C |
| **Core Concepts** | Structs, Dynamic Memory, Linked Lists, Pointers |
| **Memory Management** | `malloc`, `calloc`, `realloc`, `free` |
| **Architecture** | Modular code with `.h` and `.c` separation |
| **Design Principles** | Clean code, validation, low-level optimization |

---

## 🧩 **Skills Demonstrated**

- 🧠 Proficient use of **dynamic memory allocation** and deallocation  
- ✅ Prevention of **memory leaks** through careful pointer handling  
- 🧱 Design of efficient **data structures** (arrays, linked lists, structs)  
- 🧩 Implementation of **modular programming** for scalable code organization  
- 🖥️ Development of an **interactive console interface** with real-time user input validation  

---

## ⚙️ **Setup & Usage**

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/Cathrine-abu/Company_Management_System.git
2️⃣ Navigate to the Project Directory
bash
Copy code
cd Company_Management_System
3️⃣ Compile and Run with make
bash
Copy code
make run
4️⃣ If make is not installed, compile manually
bash
Copy code
gcc -o company_management_system src/company_management_system.c
./company_management_system
5️⃣ Clean the Build Files
bash
Copy code
make clean
🗂️ Project Structure
bash
Copy code
Company_Management_System/
│
├── src/
│   ├── company_management_system.c   # Main program logic
│   ├── company_management_system.h   # Struct definitions & function declarations
│
├── Makefile                         # Automates build and clean processes
└── README.md                        # Project documentation
🏁 Highlights
🔧 Written in pure C, emphasizing manual memory control and system-level thinking

🧩 Demonstrates clean architecture through modular design

🧠 Excellent showcase of problem-solving and structured programming skills

🧰 Easily extendable for features like data persistence or file-based storage
