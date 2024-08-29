#include <iostream>
#include <algorithm> // for reverse function
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    string word = "";

    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            // If we encounter a space and the current word is not empty, reverse and print the word
            if (!word.empty()) {
                reverse(word.begin(), word.end());
                cout << word << " ";
                word = ""; // Resetting the word for the new word
            }
        } else {
            word.push_back(line[i]);
        }
    }

    // For the last word
    if (!word.empty()) {
        reverse(word.begin(), word.end());
        cout << word;
    }

    return 0;
}

/*
SECOND WAY
==============================
    
    
    string word;
    while(cin>> word){
        reverse(word.begin(), word.end());
        cout << word <<" ";
    }
    return 0;

*/