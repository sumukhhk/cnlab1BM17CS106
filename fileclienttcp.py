from socket import*
serverPort=12000
serverName='10.124.7.95'
clientSocket=socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
sentence=input("Enter file name")
clientSocket.send(sentence.encode())
modifiedfile=clientSocket.recv(1024).decode()
print("From server",modifiedfile)
clientSocket.close()
