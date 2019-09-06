from socket import*
serverPort=25000
serverName='10.124.7.93'
clientSocket=socket(AF_INET,SOCK_DGRAM)
message=input("enter filename")
clientSocket.sendto(message.encode(),(serverName,serverPort))
nfile,serveraddr=clientSocket.recvfrom(1024)
print(nfile.decode())
