#include "helper.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

bool isSplitterWord(const char& ch) {
	return !isalpha(ch) && !isdigit(ch);
}

bool isVowel(const char& _ch) {
	char ch = tolower(_ch);
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

std::string task(const string& s) {
	std::string ans = "";
	bool isWord = false;
	int startWord = -1;
	int number = 1;
	for (int i = 0; i < s.size(); i++) {
		if (isSplitterWord(s[i])) {
			if (isWord && isVowel(s[startWord]))
				ans.append(s.substr(startWord, i - startWord)).append(" ");
			isWord = false;
		}
		else {
			if (!isWord) {
				isWord = true;
				startWord = i;
			}
		}
	}
	return !ans.empty() ? ans : "В файле нет предложений заданной длины\n";
}

string readFile(ifstream& input) {
	string s = "";
	string tmpS;
	while (getline(input, tmpS))
		s.append(tmpS).append("\n");
	return s;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filename;
	processInputNameOfInputFile(filename);
	ifstream input(filename);
	cout << "Результат работы:\n" << task(readFile(input));
	input.close();
}