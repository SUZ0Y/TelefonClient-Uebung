#include <string>
#include <iostream>
#include "Socket.hpp"
#include "TelefonClient.h"
using namespace std;

bool TelefonClient::menu(){

	return 0;
}

bool TelefonClient::verbinden(string server, int port){

	// 2) Socket() - erzeugt einen Clientsocket
	// ToDo
	client_sock = new Socket(server, port);
	string text="", antwort="";
	cout<<"Warte auf Serververbindung"<<endl;

	// 4) connect() - liefert true, wenn er einen Verbindung zu Server gefunden hat
	// ToDo
	while (client_sock->connect() == 0)
	{
		cout << ".";
		Sleep(400);
	}

	cout<<"\nVerbunden mit dem Server"<<endl;

	do{
		cout << "Name eingeben: - um die Telefonnummer abzurufen" << endl;
		cin >> text;

		// 5a) Kommunikation mit read() write()
		// ToDo
		client_sock->write(text);
		antwort = client_sock->readLine();

		cout << "Telefonnummer von " << text << " lautet: " <<  antwort << endl;
		cout << endl;
		
	}while(text != "EXIT");
	return true;
}

bool TelefonClient::abmelden()
{
	// 6) Client abmelden
	// ToDo
	client_sock->close();
	delete client_sock;
	client_sock = nullptr;
	return true;
}

TelefonClient::TelefonClient(void)
{
	// ToDo
}


TelefonClient::~TelefonClient(void)
{
	delete client_sock;
	// ToDo
}
