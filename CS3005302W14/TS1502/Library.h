/***********************************************************************
 * File: Library.h
 * Author: B11215002
 * Create Date: 2024/05/28
 * Editor: B11215002
 * Update Date: 2024/05/28
 * Description: This program is to manage a library database system
***********************************************************************/

#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

class Library{
private:
	std::string title;
	std::string author;
	std::set<int> edition;
	std::vector<Library> books; //sort the book like title, author, {edition, edition, edition}
public:
	//constructor
	Library(void) {

	}

	//constructor
	Library(std::string T, std::string A, int E) {
		this->title = T;
		this->author = A;
		this->edition.insert(E);
	}

	// Intent: Insert book informations into the vector of book collections
	// Pre: empty
	// Post: loaded with books without duplicates
	void insert(std::string T, std::string A, int E) {
		for (auto& it : books) {
			//it.edition.find(E) != it.edition.end() means there's something matching
			if (it.title == T && it.author == A && it.edition.find(E) != it.edition.end()) {
				std::cout << "Datum already exist.\n";
				return;
			}
			//it.edition.find(E) == it.edition.end() means there's nothing thats the same
			if (it.title == T && it.author == A && it.edition.find(E) == it.edition.end()) {
				it.edition.insert(E);
				std::cout << "Insert " << A << "'s " << T << ", Edition: " << E << ".\n";
				return;
			}
			
		}

		//insert if every condition is met
		books.push_back(Library(T, A, E));
		std::cout << "Insert " << A << "'s " << T << ", Edition: " << E << ".\n";
	}

	// Intent: Delete a book and its specific edition
	// Pre: vector of library books
	// Post: remove existing matching book
	void deleteEdition(std::string T, std::string A, int E) {
		for (auto& it : books) {
			if (it.title == T && it.author == A) {
				//if nothing found
				if (it.edition.find(E) == it.edition.end()) {
					std::cout << "Datum doesn't exist.\n";
					return;
				}
				else {
					//erase the edition found
					it.edition.erase(it.edition.find(E));
					std::cout << "Delete " << A << "'s " << T << ", Edition: " << E << ".\n";
					return;
				}
			}
		}
	}

	// Intent: Delete the book along every edition
	// Pre: vector of library books
	// Post: Removal of all matching books and its every edition
	void deleteBook(std::string T, std::string A) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].title == T && books[i].author == A) {
				books.erase(books.begin() + i);
				std::cout << "Delete " << A << "'s " << T << ".\n";
				return;
			}
		}

		//if nothing found
		std::cout << "Book doesn't exist.\n";
	}

	// Intent: find a book with the corresponding title and author
	// Pre: vector of library books
	// Post: prints a specific book and it's editions
	void findBook(std::string T, std::string A) {
		std::vector<int> editionList;
		editionList.clear();

		//all the matching books and their editions
		for (auto& it : books) {
			if (it.title == T && it.author == A) {
				for (auto& E : it.edition) {
					editionList.push_back(E);
				}
			}
		}

		if (editionList.size() == 0) {
			std::cout << "Book doesn't exist.\n";
			return;
		}
		//print with given format
		else {
			//sort by ascending order of edition
			std::sort(editionList.begin(), editionList.end());

			std::cout << "Title: " << T << "\tAuthor: " << A << "\tEdition: " << editionList[0];

			for (int i = 1; i < editionList.size(); i++) {
				std::cout << ", " << editionList[i];
			}

			std::cout << "\n";
		}
	}

	// Intent: find every book with the specified author
	// Pre: nothing
	// Post: prints every book with the specified author
	void findAuthor(std::string A) {
		std::vector<std::string> titleList;
		titleList.clear();
		for (auto& it : books) {
			if (it.author == A) {
				titleList.push_back(it.title);
			}
		}

		if (titleList.size() == 0) {
			std::cout << "No book found.\n";
		}
		else {
			//sort title alphabetically
			std::sort(titleList.begin(), titleList.end());

			std::cout << A << "'s Books: " << titleList[0];

			for (int i = 1; i < titleList.size(); i++) {
				std::cout << ", " << titleList[i];
			}

			std::cout << "\n";
		}
	}

	// Intent: To serve as a condition for sort()
	// Pre: nothing
	// Post: returns how I want the title and author to be sorted alphabetically
	static bool compareByTitle(Library first, Library second) {
		if (first.title != second.title) {
			return first.title < second.title;
		}
		else {
			return first.author < second.author;
		}
	}

	// Intent: To sort every book in the Library vector by title then by author
	// Pre: A vector<Library> named book
	// Post: prints every book accordingly
	void sortByTitle() {
		//condition, now should be sorted and be like : title, author, edition {1, 2, 3}
		std::sort(books.begin(), books.end(), compareByTitle);

		for (auto& it : books) {
			std::vector<int> editionList;
			for (auto& E : it.edition) {
				editionList.push_back(E);
			}

			std::sort(editionList.begin(), editionList.end());

			std::cout << "Title: " << it.title << "\tAuthor: " << it.author << "\tEdition: " << editionList[0];

			for (int i = 1; i < editionList.size(); i++) {
				std::cout << ", " << editionList[i];
			}

			std::cout << "\n";
		}
	}

	// Intent: To serve as a condition for sort()
	// Pre: nothing
	// Post: returns how I want the title and author to be sorted alphabetically
	static bool compareByAuthor(Library first, Library second) {
		if (first.author != second.author) {
			return first.author < second.author;
		}
		else {
			return first.title < second.title;
		}
	}

	// Intent: To sort every book in the Library vector by author then by title
	// Pre: A vector<Library> named book
	// Post: prints every book accordingly
	void sortByAuthor() {
		//condition
		std::sort(books.begin(), books.end(), compareByAuthor);

		for (auto& it : books) {
			std::vector<int> editionList;
			for (auto& E : it.edition) {
				editionList.push_back(E);
			}

			std::sort(editionList.begin(), editionList.end());

			std::cout << "Title: " << it.title << "\tAuthor: " << it.author << "\tEdition: " << editionList[0];

			for (int i = 1; i < editionList.size(); i++) {
				std::cout << ", " << editionList[i];
			}

			std::cout << "\n";
		}
	}
};
