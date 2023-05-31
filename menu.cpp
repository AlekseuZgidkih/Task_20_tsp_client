#include "menu.h"
#include <vector>
#include <memory>
#include <unordered_map> 
#include <string>

using namespace std;

int Menu::findMessage(const string& login) {

	int i = 0;
	for (auto it = messages.begin(); it != messages.end(); ++it)
	{
		if (it->first == _curentName) {
			i++;
		}
	}
	return i;
}

void Menu::readMessage(const std::string& login) {
	cout << "read messages" << endl;
	if (findMessage(login) == 0) cout << "you haven't messeges." << endl;
	for (auto it = messages.begin(); it != messages.end(); ++it)
	{
		if (it->first == _curentName)
			cout << it->second << endl;
	}
}

bool Menu::changeLogin(const string& login) {

	auto itFindLogin = mapUsers.find(login);

	if (itFindLogin != mapUsers.end()) {
		return true;
	}
	return false;
}

void Menu::saveLogPass(string& login, string& password) {														// çàïèñü ëîãèíà
	mapUsers.emplace(login, password);
}

bool Menu::main_menu() {	//char operation	

	char operation;
	if (mapUsers.empty()) cout << "1 - Registration, 0 - Out" << endl;
	else cout << " 1 - Enter, d - delete user, 0 - Out" << endl;	

	cin >> operation;

	switch (operation)
	{
		// enter into profile
	case '1': {				
		if (!mapUsers.empty()) { 
			string login, password;

			cout << " Enter login: ";
			cin >> login;

			cout << " Enter password: ";
			cin >> password;

			auto itBegin = mapUsers.find(login);
			if (changeLogin(login) && (itBegin->second == password)) {					// ïðîâåðêà ëîãèíà è ïàðîëÿ ïðîéäåíû
				_curentName = login;	
				_chatRun = true;
			}			
			else {
				auto itBegin = mapUsers.begin();
				cout << "Correct login: " << itBegin->first << ", password: " 
				<< itBegin->second << endl << endl;
			}
			break;
		}
		else {
			string login, password;

			cout << " Enter login: ";
			cin >> login;

			cout << " Enter password: ";
			cin >> password;

			if (!changeLogin(login)) {
				cout << endl << "User: " << login << ". Registration completed. " << endl;
				saveLogPass(login, password);

				_chatRun = true;
				_curentName = login;
			}
			else {
				cout << " Login is busy." << endl;				
			}
			break;
		}
	}	
	case 'd': {
		mapUsers.clear();
		cout<< "User was deleting. " << endl << endl;
		return true;
	}
			// Покинуть чат
	case '0': {
		_chatRun = false;
		_curentName = " ";		
		return false;
	}
	default: {
		cout << "wrong command." << endl;
	}
	}
	return true;
}

bool Menu::chat() {
	char operation='0';
	cout << "1 - Start tolking, 0 - exit profile." << endl; 	
	cin>> operation;

switch (operation) {
	case '1':{
		if (!TCPNet.tcpInit()){
			cout<<"CLIENT IS ESTABLISHING A CONNECTION WITH SERVER THROUGH PORT: " << PORT << endl;
			TCPNet.tcpSentMess(); 
		}		
		TCPNet.tcpCloseSocket(); 		
		return true;
	};
	case '0':{
		cout<<endl;
		_chatRun=false;
		return false;
	};
	default: {
		cout << "try again." << endl;
		return false;
	}
}
	return true;
}
