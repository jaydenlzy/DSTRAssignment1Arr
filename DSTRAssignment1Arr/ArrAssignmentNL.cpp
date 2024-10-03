/*Lai Yin Xiang TP068461*/

#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

void loadWords(const string& filename, string*& wordArray, int& wordCount, int maxSize) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    wordArray = new string[maxSize]; 
    wordCount = 0;
    string word;

    while (file >> word && wordCount < maxSize) {
        wordArray[wordCount++] = word;
    }

    file.close();

    for (int i = 0; i < wordCount; i++) {
        cout << wordArray[i] << endl;
    }
    cout << "Loaded " << wordCount << " words from " << filename << endl;
}

int main() {
    string* positiveWords = nullptr;
    string* negativeWords = nullptr;
    int posCount = 0, negCount = 0;


    loadWords("C:/Users/LaiYinXiang/OneDrive/Documents/YEAR 2 DEGREE/SEM 2/DATA STRUCTURES/ass_words/positive-words.txt", positiveWords, posCount, 2500); 

    loadWords("C:/Users/LaiYinXiang/OneDrive/Documents/YEAR 2 DEGREE/SEM 2/DATA STRUCTURES/ass_words/negative-words.txt", negativeWords, negCount, 5000);

    cout << "Positive Words Count: " << posCount << endl;
    cout << "Negative Words Count: " << negCount << endl;

    delete[] positiveWords;
    delete[] negativeWords;

    return 0;
}
