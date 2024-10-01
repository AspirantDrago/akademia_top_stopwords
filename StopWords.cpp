#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"
#define STOP_FILE "stopwords.txt"

set<string> stopwords;

void loadStopWords();

string lowerEngish(string text);

int main() {
	loadStopWords();
	ifstream fIn(FILE_IN);
	ofstream fOut(FILE_OUT);
	string word;
	while (!fIn.eof()) {
		fIn >> word;
		if (stopwords.find(lowerEngish(word)) == stopwords.end()) {
			fOut << word << ' ';
		}
	}
	fIn.close();
	fOut.close();
}

void loadStopWords() {
	ifstream fStopWords(STOP_FILE);
	string word;
	while (!fStopWords.eof()) {
		fStopWords >> word;
		stopwords.insert(word);
	}
	fStopWords.close();
}

string lowerEngish(string text) {
	string result(text);
	size_t n = text.length();
	for (int i = 0; i < n; ++i) {
		if ('A' <= result[i] && result[i] <= 'Z') {
			result[i] += 'a' - 'A';
		}
	}
	return result;
}
