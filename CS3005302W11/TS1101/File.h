/***********************************************************************
 * File: File.h
 * Author: B11215002
 * Create Date: 2024/4/30
 * Editor: B11215002
 * Update Date: 2024/5/4
 * Description: This program inherits Document class, stores the pathname
***********************************************************************/

#pragma once
#include "Document.h"
#include "Email.h"
#include <iostream>
#include <string>

class File : public Document {
private:
	std::string pathname;
public:
	//constructor
	File() {
		this->text = "";
		this->pathname = "";
	}

	//constructor
	File(std::string context, std::string route) {
		this->text = context;
		this->pathname = route;
	}

	//sets the pathname
	void setPathname(std::string input) { this->pathname = input; }

	//returns the pathname
	std::string getPathname() { return this->pathname; }

	//operator overloading = for different classes
	void operator=(File input) {
		this->text = input.getText();
		this->pathname = input.getPathname();
	}
};