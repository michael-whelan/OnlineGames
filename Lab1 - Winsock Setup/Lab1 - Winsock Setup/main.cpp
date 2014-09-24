#include <WinSock2.h>
#include "Net.h"
#include <iostream>

using namespace std;
void playerA(Net*);
void playerB(Net*);

char message[200] = "";
int main() {

	Net* n = new Net();
	n->initialise();

	
	string input = "";
	cin>>input;

	if(input == "a"){
		playerA(n);
	}
	else if(input == "b"){
		playerB(n);
	}
};

void  playerA(Net* n){
	char* ip = "127.0.0.1";
	n->setupUDP(28000, ip);
	//int m = n->receiveData("Player A");
	cout<< n->portNum << " "<< n->getSenderIP()<<endl;

	n->sendData(ip,28001,"Player A Message");
	//n->receiveData(message);
	while(true){
		 n->receiveData(message);
		if(message[0] != '\0')
		{
			 cout << message<<endl;
			 break;
		}
	}
}

void playerB(Net* n){
	char* ip = "149.153.102.45";
	n->setupUDP(28001, ip);
	//int m = n->receiveData("Player B");
	cout<< n->portNum<< " "<< n->getSenderIP()<<endl;
	n->sendData("149.153.102.32",28000,"Wow Message");
	while(true){
		 n->receiveData(message);
		if(message[0] != '\0')
		{
			 cout << message<<endl;
			 break;
		}
	}
}