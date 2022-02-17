                                        Data Packets

A packet is the smallest form of data, once it has been broken down into bits to be transmitted across the network. It contains, the data, 
and the information needed to send it (destination etc)

--------------------------------------------------------------------------------------------------------------------------------------------

                                       Data Encapsulation

The IP (Internet Protocol) regulates how data packets are sent across the internet. (ex: in the postal service, a letter must have an address on it)
IP gets the packet to the right computer, then the other packets get it to the right app, window, etc.

A data packet is usually sent with a max size of 1500 bytes, as 1500 is the most optimal size to send data (it has a low error rate, is quick to send a lot of packets and if one fails you only have to send 1500 bytes again).

1. a packet is created.
  
   data = 1234

2. the whole thing (packet + header) is wrapped again by another protocol (UDP or TCP)

                UDP

    | UDP header: 8 bytes      | data: 50 - 1500 bytes|
    |--------------------------|--------------------- |
    | - port #                 | 1234                 |
    | - checksum = 10          |                      |
    ---------------------------------------------------

                TCP
       

    | TCP Header : 16 bytes | Data: 50 - 1500 bytes|
    |-----------------------|----------------------|
    | - ports #             | 1234                 |
    | - checksum = 10       |                      |
    | - sequence #          |                      |
    | - acknowledgment #    |                      |
    ------------------------------------------------

    The port # gives the source and destination port of the application so that the computer receives the packet and knows where to send it.
    ex: Skype is on port 3478.
    
    The checksum is the sum of the data (as an int). The computer that receives the data adds it all up, and if the sum id == checksum then all the
    data was successfully received. If not, some of the data went missing.
    
    UDP:
        would know but can do nothing about it, can only tell the receiving program that it is incomplete,
        then the receiving program usually discards the incomplete packet.
    TCP:
        sequence number: the order of the packets sent. The first packet has sequence #1, etc... The receiving computer can then reorder packets if
        they arrive in the wrong order.

        acknowledgment number: the number of bytes received, the computer sends that back to the sender to say that the packet has been received.
        If the sending computer does not receive an acknowledgment within a certain time, it resends the same packet until it is sure that it has arrived.

3. it is then wrapped by the next layer (IP)

    | IP headerP: 16 bytes     | TCP header: 16 bytes  | data: 50-1500 bytes  |
    |--------------------------|-----------------------|----------------------|
    | - destination IP address | - port #              | 1234                 |
    | - source IP address      | - checksum = 10       |                      |
    |                          | - sequence #          |                      |
    |                          | - acknowledgment #    |                      |
    ---------------------------------------------------------------------------

4. and the final one (physical layer, ex: Ethernet)

    
    | Ethernet header: 22-26 bytes | IP header: 16 bytes       | TCP header: 16 bytes   | data: 50-1500 bytes | Ethernet footer: 16 bytes | 
    |------------------------------|---------------------------|------------------------|---------------------|---------------------------|
    | - destination MAC address    | - destination IP address  | - port #               | 1234                | - Interpacket gap         |  
    | - source MAC address         | - source IP address       | - checksum = 10        |                     | - Frame check sequence    |
    |                              |                           | - sequence #           |                     |                           |
    |                              |                           | - acknowledgment #     |                     |                           |
    ---------------------------------------------------------------------------------------------------------------------------------------

    MAC address: physical address of a computer on a LAN.
    
    Interpacket gap: time to wait until a new packet can be received.
    
    Frame check sequence: works like the checksum, checks that the data is complete.

Once the destination computer receives the packet, it:
1. the hardware level strips the Ethernet header
2. the kernel strips the IP layer
3. the correct protocol strips the UDP/TCP header
4. the data is finally accessible
