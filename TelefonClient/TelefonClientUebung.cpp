#include <iostream>
#include "TelefonClient.h"
using namespace std;

int main()
{
	string SERVERIP = "127.0.0.1";
	int SERVERPORT = 54321;
	// Mehr sollte in der main() nicht stehen!

	TelefonClient tc;
	cout << "------------CLIENT--------------" << endl;
	if (tc.verbinden(SERVERIP, SERVERPORT) == false)
		cout << "Server nicht gefunden!" << endl;

	if (tc.abmelden() == false)
		cout << "Nicht abgemeldet!" << endl;

	return 0;
}

