#include<iostream>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
#define bucketsize 512
void bktinput(int a, int b);
int main()
{
	int op,pktsize;
	cout<<"Enter output rate:";
	cin>>op;
	for(int i=1;i<=5;i++)
	{
		usleep(rand()%1000);
		pktsize=rand()%1000;
		cout<<"\nPacket no"<<i<<"\tPacket size="<<pktsize;
		bktinput(pktsize,op);
	}
return 0;
}
void bktinput(int a,int b)
{
	if(a>bucketsize)
		cout<<"\n\t\tBucket overflow";
	else
	{
		usleep(500);
		while(a>b)
		{
			cout<<"\n\t\t"<<b<<"bytes outputted";
			a-=b;
			usleep(500);
		}
	if(a>0)
		cout<<"\n\t\tlast"<<a<<"bytes sent\t";
	cout<<"\n\t\t Bucket output successful";
	}
}

/*
OUTPUT
bmsce@bmsce-Precision-T1700:~$ g++ leaky.cpp -o leak.o
bmsce@bmsce-Precision-T1700:~$ ./leak.o
Enter output rate:300

Packet no1	Packet size=886
		Bucket overflow
Packet no2	Packet size=915
		Bucket overflow
Packet no3	Packet size=335
		300bytes outputted
		last35bytes sent	
		 Bucket output successful
Packet no4	Packet size=492
		300bytes outputted
		last192bytes sent	
		 Bucket output successful
Packet no5	Packet size=421
		300bytes outputted
		last121bytes sent	
		 Bucket output successfulbmsce@bmsce-Precision-T1700:~$ ^C
bmsce@bmsce-Precision-T1700:~$ 

*/
