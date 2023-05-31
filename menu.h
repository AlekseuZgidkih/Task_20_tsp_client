#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include "TCP_client.h"

class Menu {
private:
	std::unordered_map <std::string /* login */, std::string /* password */> mapUsers;
	std::multimap <std::string/* login */, std::string /*text*/> messages;
	std::string _curentName;
	bool _chatRun = false;

public:
	Menu() = default;							// конструктор
	~Menu() = default;							// деструктор
	TCPNetClient TCPNet;

	void setCurentName(std::string& curentName) { _curentName = curentName; }
	std::string const getCurentName() { return _curentName; }

	void setChatRun(bool chatRun) { _chatRun = chatRun; }
	bool const getChatRun() { return _chatRun; }
				

	int findMessage(const std::string& login);
	void readMessage(const std::string& login);
	bool changeLogin(const std::string& login);
	void saveLogPass(std::string& login, std::string& password);
	bool main_menu();
	bool chat();
};