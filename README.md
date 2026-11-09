# 📒 Address Book Management System in C

A menu-driven **Address Book Management System** developed using the C programming language. This application allows users to create, search, edit, delete, and display contact information with input validation and file handling.

This project demonstrates practical implementation of C programming concepts such as structures, arrays, functions, pointers, string handling, and file operations.

## ✨ Features

- ➕ **Create Contact:** Add a new contact with name, phone number, and email address.
- 🔍 **Search Contact:** Search contacts using name, phone number, or email ID.
- ✏️ **Edit Contact:** Modify individual fields or update all contact details.
- 🗑️ **Delete Contact:** Remove a selected contact.
- 📋 **List Contacts:** Display all saved contacts in a structured table.
- ✅ **Input Validation:** Validate names, phone numbers, and email addresses.
- 🚫 **Duplicate Checking:** Prevent duplicate contact information.
- 💾 **File Handling:** Load and save contact records permanently.
- 🔠 **Case-Insensitive Search:** Search contacts without worrying about uppercase or lowercase letters.

## 🛠️ Technologies Used

- 💻 **Programming Language:** C
- ⚙️ **Compiler:** GCC
- 🧠 **Concepts:** Structures, Arrays, Pointers, Functions, Strings, File Handling
- 🖥️ **Development Environment:** VS Code / Linux

## 📂 Project Structure

```text
Address_Book/
│
├── main.c
├── contact.c
├── contact.h
├── contacts.txt
├── document.txt
└── README.md
```

| File | Description |
|---|---|
| `main.c` | Main function and menu-driven interface |
| `contact.c` | Contact management operations and validation |
| `contact.h` | Structure definitions and function declarations |
| `contacts.txt` | Stores contact information |
| `document.txt` | Project documentation |

## 🚀 Getting Started

### 📌 Prerequisites

Make sure GCC is installed on your system.

Check GCC installation:

```bash
gcc --version
```

### 📥 Installation

**1️⃣ Clone the repository**

```bash
git clone https://github.com/aviraje01/Address_Book.git
```

**2️⃣ Navigate to the project directory**

```bash
cd Address_Book
```

**3️⃣ Compile the project**

```bash
gcc main.c contact.c -o address_book
```

**4️⃣ Run the application**

```bash
./address_book
```

For Windows:

```bash
address_book.exe
```

## 📱 Application Menu

After executing the program, the following menu is displayed:

```text
📒 Address Book Menu

1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit

Enter your choice:
```

## 🔐 Input Validation

The application implements validation rules for contact information:

- 👤 **Name:** Accepts alphabets and spaces.
- 📞 **Phone Number:** Accepts digits only, with a maximum length of 10 digits.
- 📧 **Email ID:** Validates lowercase Gmail addresses according to implemented rules.
- 🚫 **Duplicate Prevention:** Checks whether a name, phone number, or email address already exists.
- 🔄 **Retry Mechanism:** Provides up to three attempts for entering valid contact information.

## 💾 File Handling

The application uses file handling to maintain contact records.

- 📂 Existing contacts are loaded from `contacts.txt` when the application starts.
- ✏️ New and modified contacts are maintained in memory during execution.
- 💾 Contact information is written back to `contacts.txt` when the user selects Exit.

This allows contact information to remain available even after the application is closed.

## 🎯 Learning Outcomes

Through this project, I gained practical experience in:

- 📌 Implementing structures and arrays in C.
- 🧩 Developing modular programs using functions.
- 🔗 Working with pointers and string manipulation.
- 📁 Performing file operations using standard C functions.
- 🛡️ Implementing input validation and duplicate checking.
- 💡 Developing menu-driven applications.


---

⭐ If you find this project useful, consider giving the repository a star!
