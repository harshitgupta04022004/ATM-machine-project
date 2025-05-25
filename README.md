# 💳 ATM Transaction Management System in C

This is a C-based console application that simulates an ATM system. It supports creating user accounts, balance inquiry, deposits, withdrawals, and viewing the transaction history using linked list data structures.

## 🛠️ Features

- 🔐 **Secure PIN Verification** for each transaction.
- 🧑 **Multiple Users Support** with dynamic account creation via ATM number and PIN.
- 💰 **Balance Management** through deposit and withdrawal functions.
- 📜 **Transaction History** using a stack-like singly linked list for each user.
- 🔁 **Persistent Session** for interacting with multiple users without restarting.
- 🗂️ **User Selection by ATM Number** to access details and perform operations.

## 📌 Data Structures

- **Doubly Linked List** – To manage users (`struct node`)
- **Singly Linked List (Stack Behavior)** – To manage individual transaction logs (`struct single_node`)

## 📋 Functional Overview

| Function               | Description                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| `Balance()`            | Returns the current balance for a user after verifying the PIN.             |
| `Deposit()`            | Adds a deposit amount and updates the transaction log.                      |
| `Withdraw()`           | Deducts the withdrawal amount and updates the transaction log.              |
| `Last_Transactions()`  | Displays all past deposits/withdrawals (stack-based view).                  |
| `newuser_details()`    | Adds a new user with ATM number and PIN using a doubly linked list.         |
| `isalreadyexit()`      | Checks if a user with the given ATM number already exists.                  |

## 🧪 Sample Run

```

START

Enter your ATM\_number\[12 digit] : 123456789012
You need to add your card first to continue.
Enter your pin : 1234
Your account added successfully.

WELCOME SCREEN

# 1.Balance(Enter-1).

# 2.Deposit(Enter-2).

# 3.Withdraw(Enter-3).

# 4.Last Transactions(Enter-4).

# 0.Exit(Enter-0).

Enter the option : 2
Enter the pin(4-digit).
1234
Enter the amount to deposit.
1000
Your Deposit of rupees 1000.000000 is successful.
Your Balance is now : 1000.000000.

````

## 💾 How to Compile and Run

1. Clone or download this repository.

2. Compile the code:

```bash
gcc atm_system.c -o atm
````

3. Run the application:

```bash
./atm
```

## 🧠 Future Enhancements

* Add file handling to save and load users and transaction logs across sessions.
* Add OTP-based verification or biometric authentication.
* Use a database (like SQLite) for scalable persistent storage.

## 📝 Author

* Developed by Harshit Gupta
