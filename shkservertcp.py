from socket import*
serverPort=12000
serverName='DESKTOP-OC56HS8'
serverSocket=socket(AF_INET,SOCK_STREAM)
serverSocket.bind((serverName,serverPort))
serverSocket.listen(1)
print("The server is ready to receive")
while(1):
    connectionSocket,addr=serverSocket.accept()
    sentence=connectionSocket.recv(1024)
    capitalizedSentence=sentence.upper()
    connectionSocket.send(capitalizedSentence)
    connectionSocket.close()
