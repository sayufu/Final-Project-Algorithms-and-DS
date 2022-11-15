#pragma once

#include"Lib.h"

template<class var>
class Admin {
private:
	var username, password;
public:
	Admin(var username, var password) {
		this->username = username;
		this->password = password;
	}
	~Admin() {}

	var getUsername() { return this->username; }
	var getPassword() { return this->password; }

	void setPassword(var password) { this->password = password; }
};
