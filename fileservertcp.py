from socket import *
serverPort=12000
serverName='10.124.7.94'
serverSocket=socket(AF_INET,SOCK_STREAM)
serverSocket.bind((serverName,serverPort))
serverSocket.listen(1)
print("The server is ready to receive")
while(1):
    connectionSocket,addr=serverSocket.accept()
    name=connectionSocket.recv(1024).decode()
    file=open(name,"r")
    f=file.read(1024)
    connectionSocket.send(f.encode())
    file.close()
    connectionSocket.close()
