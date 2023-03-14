#include<iostream>
#include<winsock2.h>
using namespace std;
int  main()
{
	WSADATA wsaData;
	SOCKET hServerSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;
	int szClntAddr;
	char message[] = "chook always beautiful";
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "WSAStartup() error!" << endl;
	}
	hServerSock = socket(PF_INET,SOCK_STREAM,0);
	if(hServerSock==INVALID_SOCKET)
	{
		cout << "socket() error!" << endl;
	}
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	char*c = "9190";
	servAddr.sin_port = htons(atoi(c));
	if (bind(hServerSock, (SOCKADDR*)&servAddr, sizeof(servAddr) == SOCKET_ERROR))
	{
		cout << "bind() error" << endl;
	}
	if (listen(hServerSock, 5) == SOCKET_ERROR)
	{
		cout << "listen() error" << endl;
	}
	szClntAddr = sizeof(clntAddr);
	hClntSock = accept(hServerSock, (SOCKADDR*)&clntAddr, &szClntAddr);
	if (hClntSock == INVALID_SOCKET)
	{
		cout << "accept() error" << endl;
	}
	send(hClntSock, message, sizeof(message), 0);
	closesocket(hClntSock);
	closesocket(hServerSock);
	WSACleanup();
	system("pause");
	return 0;
}