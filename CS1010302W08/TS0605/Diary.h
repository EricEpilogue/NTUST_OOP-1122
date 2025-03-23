#pragma once
#include<iostream>
#include<vector>
#include<string>

class Diary {
private:
	static std::string day;
public:
	static void NewDay(std::string dayStr) {
		Diary::day = dayStr;
	}
};

std::string Diary::day;