/***********************************************************************
 * File: Source.cpp
 * Author: B11215002
 * Create Date: 2024/05/28
 * Editor: B11215002
 * Update Date: 2024/05/28
 * Description: This program is to manage a library database system
***********************************************************************/

#include "Library.h"

Library bookData;

int main(){
	std::string title;
	std::string author;
	int edition;
	std::string command;

	//separate the input into many segments to detect incomplete commands
	while (std::cin >> command) {
		char quoteSign;

		//do insert
		if (command == "Insert") {
			//-->"<--title"
			std::cin >> quoteSign;
			if (quoteSign != '"') {
				std::cout << "Incomplete Command.\n";
				continue;
			}
			//delimiter, "title-->"<--
			std::getline(std::cin, title, '"');

			//-->"<--author"
			std::cin >> quoteSign;
			if (quoteSign != '"') {
				std::cout << "Incomplete Command.\n";
				continue;
			}

			//delimiter, "author-->"<--
			std::getline(std::cin, author, '"');
			std::cin >> edition;

			//do the insert
			bookData.insert(title, author, edition);
		}
		//first by find
		else if (command == "Find") {
			std::string info;
			std::cin >> info;

			//this calls "find book"
			if (info == "Book") {
				//e.g. Find Book "Harry" "JK"
				//catch the first quote
				std::cin >> quoteSign;
				if (quoteSign != '"') {
					std::cout << "Incomplete Command.\n";
					continue;
				}

				std::getline(std::cin, title, '"');

				std::cin >> quoteSign;
				if (quoteSign != '"') {
					std::cout << "Incomplete Command.\n";
					continue;
				}

				std::getline(std::cin, author, '"');
				bookData.findBook(title, author);
			}
			//this calls find author
			else if (info == "Author") {
				//e.g. Find Author "Unknown"
				std::cin >> quoteSign;
				if (quoteSign != '"') {
					std::cout << "Incomplete Command.\n";
					continue;
				}

				std::getline(std::cin, author, '"');
				bookData.findAuthor(author);
			}
			else {
				std::cout << "Imcomplete Command." << std::endl;
			}
		}
		//now filter by delete
		else if (command == "Delete") {
			std::string info;
			std::cin >> info;
			//delete book
			if (info == "Book") {
				//e.g. Delete Book "Mamamia" "ABBA"
				std::cin >> quoteSign;
				if (quoteSign != '"') {
					std::cout << "Incomplete Command.\n";
					continue;
				}

				std::getline(std::cin, title, '"');

				std::cin >> quoteSign;
				if (quoteSign != '"') {
					std::cout << "Incomplete Command.\n";
					continue;
				}

				std::getline(std::cin, author, '"');
				bookData.deleteBook(title, author);
			}
			//delete by edition
			else if (info == "Edition") {
				//Delete Edition "Harry" "JK" 3
				std::cin >> quoteSign;
				if (quoteSign != '"') {
					std::cout << "Incomplete Command.\n";
					continue;
				}

				std::getline(std::cin, title, '"');

				std::cin >> quoteSign;
				if (quoteSign != '"') {
					std::cout << "Incomplete Command.\n";
					continue;
				}

				std::getline(std::cin, author, '"');
				std::cin >> edition;
				bookData.deleteEdition(title, author, edition);
			}
			else {
				std::cout << "Imcomplete Command." << std::endl;
			}
		}
		//filter by sort
		else if (command == "Sort") {
		std::string by;
		std::cin >> by;
		//the connecting word "by", if failed to catch by then return incomplete command
		if (by != "by") {
			std::cout << "Incomplete Command.\n";
			continue;
		}

		std::string info;
		std::cin >> info;

		//sort by title
		if (info == "Title") {
			bookData.sortByTitle();
		}
		//sort by author
		else if (info == "Author") {
			bookData.sortByAuthor();
		}
		else {
			std::cout << "Imcomplete Command." << std::endl;
		}
		}
		//all other cases are unknown command.
		else {
		std::cout << "Unknown Command." << std::endl;
		}
	}
}
