/***********************************************************************
 * File: Email.h
 * Author: B11215002
 * Create Date: 2024/4/30
 * Editor: B11215002
 * Update Date: 2024/5/4
 * Description: This program inherits Document class, stores sender, recipient, title, context within.
***********************************************************************/

#pragma once
#include "Document.h"
#include <iostream>
#include <string>

class Email : public Document {
private:
	std::string sender;
	std::string recipient;
	std::string title;
public:
	//constructor
	Email() {
		this->text = "";
		this->sender = "";
		this->recipient = "";
		this->title = "";	
	}

	//input constructor
	Email(std::string context, std::string from, std::string to, std::string topic) {
		this->text = context;
		this->sender = from;
		this->recipient = to;
		this->title = topic;
	}

	//sets the sender
	void setSender(std::string input) { this->sender = input; }

	//returns the sender
	std::string getSender() { return this->sender; }

	//sets the recipient
	void setRecipient(std::string input) { this->recipient = input; }

	//returns the recipient
	std::string getRecipient() { return this->recipient; }

	//sets the title
	void setTitle(std::string input) { this->title = input; }

	//returns the title
	std::string getTitle() { return this-> title; }

	//overloads the = sign for other classes
	void operator=(Email input) {
		this->text = input.getText();
		this->sender = input.getSender();
		this->recipient = input.getRecipient();
		this->title = input.getTitle();
	}
};