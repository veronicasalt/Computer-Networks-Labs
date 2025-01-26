//Name: Veronica Saltanov
//Date: 10/30/24
//Lab 4: udps.c step 1: UDP server (peer) that receives a file from a client (peer)
//Description: This program will use use bind the socket to address and port number.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

//Declare a Header structure that holds length of a packet
typedef struct
{
    int len;
} Header;

//Declare a packet structure that holds data and header
typedef struct
{
    Header header;
    char data[10];
} Packet;

//Declare client address to fill in address of sender
struct sockaddr_in servAddr, clienAddr;

//Printing received packet
void printPacket(Packet packet)
{
    printf("Packet{ header: { len: %d }, data: \"", packet.header.len);
    fwrite(packet.data, (size_t)packet.header.len, 1, stdout);
    printf("\" }\n");
}

//Server sending ACK to the client
void serverSend(int sockfd, const struct sockaddr *address, socklen_t addrlen)
{
    Packet packet;
    //sending acknowledgement packet
    strcpy(packet.data, "Acknowled");
    packet.header.len=sizeof(packet.data);

    //send packet
    sendto(sockfd, &packet, sizeof(packet), 0, address, addrlen);
    printf("\t Server sending %s \n", packet.data);
}

Packet serverReceive(int sockfd, struct sockaddr *address, socklen_t *addrlen)
{
    Packet packet;
    while (1)
    {
        //recv packets from the client
	    recvfrom(sockfd, &packet, sizeof(packet), 0, address, addrlen);

        // print received packet
        printPacket(packet);

        //send acknowldgement
	    serverSend(sockfd, address, *addrlen);
        break;
    }
    return packet;
}


int main(int argc, char *argv[])
{
    //Get from the command line, port and dst file
    if (argc != 3)
    {
        printf("Usage: %s <port> <dstfile>\n", argv[0]);
        exit(0);
    }
    //Declare socket file descriptor.
    int sockfd;

    //Open a UDP socket, if successful, returns a descriptor
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("cannot create socket");
        exit(0);
    }

    //Setup the server address to bind using socket addressing structure
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(atoi(argv[1]));  /* port in network byte order */
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); /* internet address */

    //bind IP address and port for server endpoint socket
    if((bind(sockfd, (struct sockaddr *) &servAddr, sizeof(struct sockaddr))) < 0)
    {
        perror("socket bind failed");
        exit(0);
    }

    //open file given by argv[2], create if it does not exist
    int fp = open(argv[2], O_CREAT | O_RDWR, 0666);
    if(fp < 0)
    {
	    perror("File failed to open\n");
	    exit(1);
    }

    // get file contents (as packets) from client
    Packet packet;
    socklen_t addr_len = sizeof(clienAddr);
    printf("Waiting for packets to come.....\n");
    do
    {
        packet = serverReceive(sockfd, (struct sockaddr *) &clienAddr, &addr_len);
	    write(fp, packet.data, packet.header.len);
    } while (packet.header.len != 0);
    //close file and socket

    return 0;
}

