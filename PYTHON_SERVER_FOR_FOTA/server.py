import socket
import sys
import time

codeSize = 4

#Read Binary File
with open ("raw_text", 'rb') as f:
    byte = f.read()

print('Length: ', len(byte))
blockLength = int(len(byte) / 4)+1
print('Block Length: ', blockLength)
i = 0

#udp -> https://linuxhint.com/send_receive_udp_python/

ip = "192.168.1.4"
port = 5555

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = (ip, port)
s.bind(server_address)

while True:
    start = time.time();
    print("####### Server is listening #######")
    data, address = s.recvfrom(4096)
    print("Server received: ", data.hex(), "\n")
    
    print('len: ', len(byte))
    if data.hex() == "01":
        print('Transfer is being processing!', "\n")
        i = 0
    
        while i != (blockLength):
            print(i+1, '. block by', blockLength);
            newPacket = byte[(codeSize*i):(codeSize*(i+1))];
            if len(newPacket) < codeSize:
                for j in range(len(newPacket), codeSize):
                    newPacket = newPacket + bytes.fromhex("1A")
            print('Packet Size: ', len(newPacket))
            
            s.sendto(newPacket, address)
            print("Server sent : ", newPacket.hex(), newPacket)
            i = i + 1
            ack, address = s.recvfrom(4096)
            print("ACK received: ", ack.hex())
            if ack.hex() == "02":
                print("Success!", "\n")
            else:
                print('Fail!', "\n")
                break
            
            time.sleep(0.1)
    else:
        print('Transfer can not start!', "\n")
    end = time.time()
    print('Data Transmission Time: ', end - start, ' seconds')
        
    
    