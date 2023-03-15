#include<iostream>
#include<winsock2.h>
using namespace std;

int main()
{
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;
	char message[30];
	int strlen;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "WSAStartup() error!" << endl;
	}
	hSocket = socket(PF_INET,SOCK_STREAM,0);
	if(hSocket==INVALID_SOCKET)
	{
		cout << "socket() error!" << endl;
	}
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.9.9.1");
	char*c = "9190";
	servAddr.sin_port = htons(atoi(c));
	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		cout << "socket() error!" << endl;
	}
	strlen = recv(hSocket, message, sizeof(message) - 1, 0);
	if (strlen == -1)
	{
		cout << "read() error!" << endl;
	}
	cout << "message from service " << message << endl;
	closesocket(hSocket);
	WSACleanup();
	system("pause");
	return 0;
}