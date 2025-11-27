### LoginGaurd (Cpp Terminal)

A beginner-friendly C++ console application for user authentication with **Login**, **Signup**, and **Forgot Password** functionality. Data is stored in a simple text file inside the `data/` folder.

---

#### Features
1. **Login** – Authenticate with username and password.
2. **Signup** – Register a new account with username, email, and password.  
   - Email format is validated (`example@domain.com`).  
   - Password must be at least 8 characters long, include uppercase, lowercase, digit, and special character.
3. **Forgot Password** – Retrieve or reset your password securely.

---

#### Getting Started

##### Prerequisites:
- C++ compiler (e.g., `g++`)
- Linux/Mac terminal or Windows CMD/PowerShell

##### Installation:

###### 1. Clone The Repository
```
git clone https://github.com/ishfaqbuilds/CppArena.git
cd CppArena/LoginGaurd
```

###### 2. Compile The Program:
```
g++ main.cpp -o authApp
```

###### 3. Run The Game
```
./authApp
```

---

#### Project Structure

```
LoginGaurd/
├── src/
│   └── main.cpp          # Source code
├── data/
│   ├── Login.txt         # Stores user credentials
│   └── temp.txt          # Temporary file for password reset
├── README.md             # Documentation
```

---

#### Learning Highlights

- File handling with fstream
- String parsing with delimiters
- Regex-based email validation
- Password strength validation
- Console-based menu-driven program

---

#### Contributing

##### Contributions are welcome! Please follow these steps:
1. Fork the repository
2. Create a feature branch
3. Follow Python coding style (PEP 8)
4. Commit with clear messages
5. Submit a pull request

##### For bugs or feature requests, please open an issue.

---

#### License

Licensed under the **MIT License**. See the `LICENSE` file for details.

