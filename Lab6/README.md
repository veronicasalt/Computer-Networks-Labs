# Reliable UDP File Transfer with Stop-and-Wait Protocol (TFv3)

This repository contains the implementation of a reliable file transfer system using the Stop-and-Wait protocol on top of UDP. The project introduces reliability by handling packet loss, acknowledgment loss, and corruption, simulating the behavior of the rdt3.0 protocol as described in networking textbooks.

The implementation includes:
- `c3.c`: The client program that sends data to the server using the Stop-and-Wait protocol.
- `s3.c`: The server program that receives data, acknowledges it, and writes it to a file.

---

## Objective

The primary objective of this project is to build a reliable transport service over UDP, which is inherently connectionless and unreliable. The Stop-and-Wait protocol ensures:
1. Packets are delivered in order.
2. Lost packets and acknowledgments are retransmitted.
3. Corruption is detected using a checksum.

This project simulates packet and acknowledgment loss, enabling robust testing of the protocol.

---

## Features

- **Stop-and-Wait Protocol:** Implements rdt3.0, ensuring reliability through retransmission.
- **Checksum Validation:** Detects corruption in packets and acknowledgments.
- **Loss Simulation:** Randomly drops packets and acknowledgments to test the robustness of the protocol.
- **Timeout Mechanism:** Uses `select()` for managing retransmissions upon timeout.
- **Error Handling:** Prevents infinite retransmissions after the final data packet by implementing a resend limit.

---

## Program Details

### Client (`c3.c`)

The client performs the following tasks:
- Reads data from a specified file and sends it to the server in chunks.
- Calculates a checksum for each packet and includes it in the header.
- Waits for an acknowledgment (`ACK`) from the server.
- Retransmits the packet if:
  - No acknowledgment is received within the timeout period.
  - The acknowledgment is corrupted.
- Stops retransmissions after a predefined limit for the final packet.

### Server (`s3.c`)

The server performs the following tasks:
- Waits for packets from the client.
- Validates each packet's checksum and sequence number.
- Sends an acknowledgment (`ACK`) for valid packets.
- Ignores corrupted or unexpected packets and resends the last acknowledgment.
- Writes valid data to a file.

The server stops receiving data and terminates after processing an empty packet (indicating the end of the file).

---

## Getting Started

### Prerequisites
1. A C compiler (e.g., `gcc`) installed on your system.
2. A test file to transfer from the client to the server.

gcc -o server s3.c
gcc -o client c3.c
