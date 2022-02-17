--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    
                                                    SOCKETS

Sockets are the low level endpoints used to send and receive information across a network. They are used by protocols like HTTP (hyper text transfer protocol) or FTP (file transfer protocol).
Sockets are two way endpoints. You can send or receive information from any socket.

A socket is created with the C socket() call, returns an integer that is used to refer to it (like a fd).

Client socket:
Once the socket is created, we use the connect() call with an ip address and a port so that the socket knows what to connect to.
This returns a value that says it is successfull, and you can start sending / receiving information.


Server socket:
Once the socket is created, we use the bind() call to tell the socket where to listen for connections. We then use listen() to listen for connections, then use accept()
in order to get another socket to perform tasks on the client side. Finally we can use the send() or recv() functions to exchange data.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    
                                                    OSI Model

7 layers of communications between computers and machines. The 7 layers follow transmission protocols and each have a role in the transmission of data.

Layer 1: Physical Layer
    The lowest level of data transmission, converts bits received into radio waves, optical signals, etc... to send to another machine. Deals mainly with hardware
    and its limitations, such as maximum distance for a transmission, voltage changes, cable specifications, wave frequency, etc.
    Heavily used for Bluetooth, Ethernet and USB standards.

Layer 2: Data Link Layer
    - Provides basic node-to-node data transfer, defines the protocol to establish a connection between two physical devices. Basically manages the physical level.
    - Provides the means to detect and correct errors that occur in the physical layer.
    - This layer only applies to same-level nodes (two nodes connected on the same network will see their connection handled by this level, for network-network transmission, see higher layers.)
    - The data link layer receives requests from the network layer and fulfills them by issuing service requests to the physical layer.
    - Encapsulates the data received from the network layer into frames.
        * Frame: a data transmission unit, in the shape of a container for a network packet. Consists of a header followed by a packet. Is delimited by frame synchronization (a bit sequence that indicates the beginning and end of the data.)
    - Contains 2 sub-layers:
        * Medium access control (MAC) layer - controls how devices in a network gain access to the media. Also handles frame synchronization (determines the 
            start and end of each frame in the transmission bitstream.)
        * Logical Link control (LLC) layer - provides flow control, acknowledgment and error notification, along with contril and addressing of the data. Specifies 
            what to do in which situation.

Layer 3: Network Layer
    - Responsible for sending network packets from a source to a destination host via one or more networks. Responds to requests from the transport layer and issues requests to the data link layer.
    - Describes multiple network architectures (the Internet is an example of one.)
    - The communication at this layer is connectionless (the recipient of a packet does not send an acknowledgment to the sender like in higher layer communication. ex: UDP)
    - Assigns a unique address to all hosts in a network (ex: IP addresses on the Internet)
    - Sends the data between network through special hosts called gateways or routers.
    
Layer 4: Transport Layer
    - Delivers data to the appropriate application process on the host computer.
    - Provides protocols for connection-oriented communication (a communication is established before any data is sent, by having a "test" message sent. ex: TCP)
    - Error checking, to account for possible errors during the network layer protocols, error detection codes are created, and a sendre can be notified if something went wrong.
    - Controls the flow of data from the sender to the receiver (to prevent the sender from sending more than the receiver can handle)
    - Handles the contol of bandwith consumption (using congestion avoidance)
    - Multiplexing, or the idea that a node in a network can have multiple endpoints (ports) to access multiple network services at once.
    - Forms data segments that will be sent to the network layer, adds source and destination port numbers in the data header.
    - UDP and TCP are examples of transport layer protocols.
    - Does not know or try to know of the inside of the data packets, only determines where and how to forward them.

Layer 5: Session Layer
    - Controls the connections between computers. Establishes, maintains and closes the connection as needed.
    - An example of a session layer protocol is a connection recovery protocol, which reconnects two devices that have been disconnected.
    - Receives requests from the Presentation layer and relays them to the transport layer.
    - An example of this layer in action is in live tv programs or video conferencing, where the video stream and the audio stream must match perfectly.

Layer 6: Presentation Layer
    - Receives requests from the application layer and transmits them to the session layer through a unique presentation service access point (PSAP)
    - Makes sure that the information sent out by one system is readable by the receiver system. On the sender system, it will convert the data to the standard transmittable format.
        On the receiver it will translate, format, and deliver the information to be processed or displayed.
    - Some applications/protocols (like HTTP) do not differenciate between presentation and application layer, the tasks of the two are done at the same point in the transmission.
    - Up until here, the data retains its structure and presentation, but the protocols in this layer will make it understandable by other layers further down.
    - This is also usually where encryption and decryption are done.

Layer 7: Application Layer
    - Interface responsible for communicating with user-facing applications, what the user actually sees.
    - Sends the requests of the user to the underlying layers and protocols.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                
                                                TCP / IP Model

Developped to have an efficient way to transmit data from one system to another on the Internet, this protocol has found that it is much safer to deconstruct a message into packets
rather than trying to send all of it at once. Although that might be a faster way to send data, all it takes is one issue for the whole transmission to be lost.
The packets are then reassembled once they have reached their destination, into the full message that they were to begin with. This allows different packets to take the
best path from one machine to another based on traffic congestion, error feedback etc. The different steps of communication are split into layers, and each layer serves
a specific purpose in the overall transmission process. This system is a way of standardizing the transmission of data so that each provider does not have to implement
their own transmission standard. The 4 layers are:

Layer 1: Application Layer
    - The application with which the user interacts, used to develop network-based applications.
    - provides services like naming network devices, formatting text, emails, file transfer, etc.
    - handles errors and message recovery if needed
    - uses protocols like: HTTP (formatting and transmission of hypertext and hypermedia), FTP (file transfer), DNS (naming system for devices in a network, translation of domain names to IP addresses.)

Layer 2: Transport Layer
    - Provides a reliable connection between two computers. Deconstructs the data into data packets, acknowledges data received from the other device and ensures that the other device
        acknowledges data received.
    - uses protocols like: TCP (reliable connection-oriented protocol, establishes a connection, divides byte streams into segments and assigns a sequence number to each segment so
        they can be reassembled into the correct order once delivered to the recipient. The recipient then sends an acknowledgment back to the sender.), UDP (a message-oriented protocol
            that provides a simple though unreliable and connectionless service. Used to transmit small amounts of data where speed of transmission is more important than accuracy.).

Layer 3: Internet/Network Layer
    - Controls the movement of packets across a network. Routes each data packet to the best way to reach the destination, independently of each other, to use the optimal route.
    - Reassembles the out-of-order packets once they have reached their destination, and handles error checking and remedial.
    - uses protocols like: IP (connectionless and unreliable protocol, transports datagrams across multiple nodes (routes)).

Layer 4: Host-to-Network Layer/Datalink
    - Manages the physical parts of sending the data, along with the pysical aspects of its reception (ethernet cable, router, etc)
    - Defines how bits are to be encoded into optical or electrical pulses.
    - Accepts IP packets and turns them into frames, handle frame synchronization.
    - States the transmission mode (simplex, half duplex, full duplex) and the topology of the network.
    - uses protocols like: Ethernet, Frame Relay, Token ring, ATM


                                                Transmission modes
                                            
Simplex mode:
    - the communication is unidirectional. Only one of the devices can transmit, the other can only receive. That way the entirety of the channel capacity can be used in one direction.
        ex: a keyboard sends information to a computer, without the need for information going the other way.

Half-duplex mode:
    - both devices can send and receive, but not at the same time. if one is sending, the other can only receive. like in simplex mode, the entirety of the channel capacity can be in use.
        ex: walkie-talkies
    
Full-duplex mode:
    - both devices can send and receive at any time. There are two ways to do this: either the link has two separate transmission paths, one for sending and one for receiving, or 
        the channel capacity is shared between the two.
        ex: telephone line

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                                                Ports and IP Addresses

On a TCP/IP network, each device must have a unique IP address to communicate with others. However each device must be able to run multiple
applications/processes at once, and for that a device has multiple ports. As an IP address identifies the computer on the network, a port identifies
the application running on that computer. Just like an apartment block has one street address for all the apartments (IP address), each of them has a number (port).

Ports
    - Ports use 16-bit numbers, and can therefore range from 0 to 65535.
    - Ports 0-1023 are allocated to server services by default. Web servers normally use port 80 and SMTP servers use 25.
    - Ports 1024-49151 are registered ports. They can be registered for services by the IANA and are semi-reserved.
    - Ports 49152-65535 are client program ports. Any user is free to use them in their program. These ports are ephemeral ports.
    - Ports are handled at the transport layer of the TCP/IP model, as part of the header that precedes the data packet.
    - FTP (File Transfer Protocol) uses: port tcp/20 to send data, port tcp/21 is used for the control channel.
    - Mail servers (usually use SMTP) on port tcp/25.
    - DNS (Domain Name Servers) usually use udp/53 for queries to change domain names into IP addresses but sometimes use port tcp/53 for zone transfers.
    - HTTP (Hyper Text Transfer Protocol) uses tcp/80.
    - HTTPS (Hyper Text Transfer Protocol Secure) uses tcp/443 to encrypt a HTTP pages.

TCP Sockets
    - A combination of an IP address and a port, each end of a connection between two devices will have a socket.
    - A computer connected to Google.com would be: IP(computer) + port 60200 <-------------> IP(Google) + port 80 (standard port)
    - Another tab on the same computer to Yahoo.com would be: IP(computer) + port 60401 <----------> IP(Yahoo) + port 80.
    - Your: computer IP + port number = your client computer socket. The Google IP + port 80 = the destination socket on the Google server.

IP Addresses
    - IP addresses are handled at the networking layer of the TCP/IP model, as part of the tail info of the data packet.
    - TCP/IP supports TCP ports and UDP ports.
    - TCP has its own 65535 ports and UDP has its own 65535 ports. They are not shared between them.

IPv4
    - The old version, addresses were made up of four bytes (four "octets") usually written in dots and numbers form:
        ex: 192.0.2.111
    - Most sites on the Internet currently use IPv4
    - IPv4 has the risk of running out, so IPv6 was born to deal with this issue.
    - the first part of the address can be the network address, and the last part can be the host.
        ex: in address 192.0.2.12, we can be talking about host 12 on network 192.0.2.0

IPv6
    - New version, with trillions of different addresses.
    - Hexadecimal notation, each 2-byte chunk is separated by a colon (:)
        ex: 2001:0db8:c9d2:aee5:73e3:934a:a5ae:9551
        * any chunk that is full of 0s can be compressed between 2 colons:
            ex: 2001:0db8:c9d2:0012:0000:0000:0000:0051 is the same as 2001:db8:c9d2:12::51
        * Leading 0s can be left out in the notation
            ex: 2001:0db8:ab00:0000:0000:0000:0000:0000 is the same as 2001:db8:ab00::

Localhost: The loopback address (the machine I'm running on now) is 127.0.0.1 in IPv4, and 0000:0000:0000:0000:0000:0000:0000:0001 or ::1 in IPv6.

An IPv4 address can be represented as an IPv6 address like this:
    IPv4: 192.0.2.33
    IPv6: ::ffff:192.0.2.33
