# Network Programming Projects

This repository contains a collection of projects and labs focused on network programming and protocol implementation. The projects were developed as part of coursework for the **COEN 146: Computer Networks** class, showcasing foundational and advanced networking concepts. 

Each project demonstrates practical implementations of networking protocols, socket programming, and algorithmic techniques used in computer networking.

---

## Projects Overview

### **1. UDP File Transfer**
- Implements a simple file transfer application using UDP sockets.
- Features client (`udpc.c`) and server (`udps.c`) programs for transferring files over a connectionless network.
- Highlights:
  - File reading/writing in C.
  - UDP socket communication (`sendto`/`recvfrom`).
  - Local and remote execution support.

### **2. Reliable File Transfer with Stop-and-Wait Protocol**
- Builds on UDP to implement a reliable transport service using the Stop-and-Wait protocol (rdt3.0).
- Features client (`c3.c`) and server (`s3.c`) programs for file transfer with packet loss and acknowledgment (ACK) loss handling.
- Highlights:
  - Packet retransmissions on timeout.
  - Checksum-based error detection.
  - Simulated network failures.

### **3. Link State Routing**
- Implements the Link State (LS) routing algorithm with Dijkstra's algorithm for computing shortest paths.
- Features a single program (`ls.c`) simulating the behavior of a router in a network topology.
- Highlights:
  - Threaded architecture with synchronization using mutexes.
  - Dynamic cost updates and UDP-based message exchanges.
  - Calculation of least-cost paths from a source node.

---

## Key Features of the Repository

- **Socket Programming:** Hands-on experience with UDP and TCP sockets in C.
- **Protocol Implementation:** Covers reliable and unreliable transport layer protocols, as well as routing algorithms.
- **Dynamic Network Simulation:** Simulates real-world network conditions, including packet loss and cost changes.
- **Multithreading and Synchronization:** Utilizes threads and mutexes for concurrency and shared resource management.
- **Dijkstra’s Algorithm:** Computes least-cost paths in a network.
