from socket import*
serverPort=12000
serverName='DESKTOP-OC56HS8'
clientSocket=socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
sentence=input("enter sentence")
clientSocket.send(sentence.encode())
modifiedSentence=clientSocket.recv(1024)
print("From server:",modifiedSentence.decode())
clientSocket.close()
