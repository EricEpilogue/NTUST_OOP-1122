/***********************************************************************
 * File: Document.h
 * Author: B11215002
 * Create Date: 2024/4/30
 * Editor: B11215002
 * Update Date: 2024/5/4
 * Description: This program is the base class, stores the text.
***********************************************************************/

#pragma once
#include <iostream>
#include <string>

class Document{
public:
	std::string text;

	//constructor
	Document() {
		this->text = "";
	}

	//input constructor
	Document(std::string context) {
		this->text = context;
	}

	//gets text 
	std::string getText() const { return text; }

	//sets text
	std::string setText(std::string input) { this->text = input; }

	//operator overloading = for different classes
	void operator=(Document input) {
		this->text = input.getText();
	}
};