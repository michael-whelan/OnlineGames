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
	cout<< n->portNum << " "<< n->getSenderIP();

	n->sendData(ip,28001,"Player A Message");
	//n->receiveData(message);
}

void playerB(Net* n){
	char* ip = "127.0.0.1";
	n->setupUDP(28001, ip);
	//int m = n->receiveData("Player B");
	cout<< n->portNum<< " "<< n->getSenderIP();
	//n->sendData(ip,28000,"Player B Message");
	while(true){
		 n->receiveData(message);
		if(message[0] != '\0')
		{
			
			 cout << message;
		}
	}
	
}