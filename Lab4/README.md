# Lab 4: UDP/IP Socket Programming

## **Overview**
This repository contains implementations of a client-server application using UDP sockets in C as part of Lab 4 for COEN 146: Computer Networks course. The lab demonstrates the transfer of files between a client and a server over a connectionless UDP/IP network.

## **Objectives**
The primary goals of this lab are:
- To understand and develop client-server (peer-to-peer) communication using UDP sockets.
- To implement a file transfer application using the UDP protocol, showcasing its connectionless and unreliable nature.
- To gain hands-on experience with socket programming and system calls in C.

---

## **Project Structure**
The repository includes the following files:
- "udpc.c": The client-side implementation of the UDP application. This program sends a file to the server.
- "udps.c": The server-side implementation of the UDP application. This program receives a file from the client.

Each program is designed with modularity and scalability, making them suitable for local testing or extension to more complex scenarios.

---

## **Key Features**
1. **Socket Creation:** 
   - Both the client and server use the `socket()` system call to create UDP sockets for communication.
   - "AF_INET" is used as the domain for IPv4 addressing.
   - "SOCK_DGRAM" is used as the type for connectionless UDP communication.

2. **Address Binding:**
   - On the server side, the `bind()` function is used to bind the socket to a specific port and IP address.
   - The client uses the server's IP and port to direct its file transfer.

3. **File Transfer:**
   - The client reads the contents of a file and sends it to the server using the `sendto()` system call.
   - The server receives the file using the `recvfrom()` system call and writes the contents to a new file.

4. **Local and Remote Execution:**
   - The application can run locally (using "127.0.0.1") for testing.
   - It can also be configured for remote execution by specifying the IP address of a remote server.

---

## **How to Run the Programs**
This lab is to be run with a C compiler. A text file to use as input will also be necessary to test the file transfer
   ```bash
   gcc -o udps udps.c
   gcc -o udpc udpc.c
