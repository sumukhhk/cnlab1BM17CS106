from socket import*
serverPort=15000
serverName='DESKTOP-OC56HS8'
serverSocket=socket(AF_INET,SOCK_DGRAM)
serverSocket.bind((serverName,serverPort))
print("The server is ready to receive")
while(1):
    message,clientaddr=serverSocket.recvfrom(1024).decode()
    file=open(message,"r")
    f=file.read(2048)
    serverSocket.sendto(f.encode(),clientaddr)
    file.close()
