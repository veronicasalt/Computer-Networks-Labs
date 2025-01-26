# UDP File Transfer Application

This repository contains a UDP-based client-server application written in C. The project demonstrates the use of UDP sockets for file transfer as part of a networking lab exercise. The client (`c.c`) sends a file to the server (`s.c`), which receives and stores it. This application highlights the connectionless nature of UDP and provides hands-on experience with socket programming.

---

## Overview

UDP (User Datagram Protocol) is a lightweight, connectionless communication protocol. While it does not guarantee reliable delivery, it is widely used for applications where speed is more critical than reliability. This project uses UDP sockets to transfer a file from a client to a server.

The implementation covers the core components of UDP communication:
- Socket creation
- Address binding
- Sending and receiving data
- Basic error handling

---

## Features

- **UDP Communication:** Implements client-server communication using `sendto()` and `recvfrom()` system calls.
- **File Transfer:** Allows the client to transmit a file to the server, which saves it locally.
- **Local and Remote Support:** Can run locally using the loopback address (`127.0.0.1`) or across a network by specifying the server's IP address and port.
- **Error Handling:** Ensures graceful failure in case of errors such as socket creation failure or file I/O issues.

---

## Files in the Repository

- `c.c`: Client program that reads a file and sends its content to the server.
- `s.c`: Server program that receives the file content from the client and writes it to a local file.
- `README.md`: This file, providing an overview of the project, setup instructions, and details about the implementation.

---

## How to Run
Using a C compiler and a file to test file transfer: 
gcc -o server s.c
gcc -o client c.c
