// stringstream header
// 🔹 Why Use stringstream Instead of Loops?

// Much less manual code for splitting on spaces.

// Handles multiple spaces automatically.

// Handles type conversion easily (like reading an int from a string).
// Operation	Meaning
// ss << value;	Write a value into the stringstream (like cout)
// ss >> value;	Read a value from the stringstream (like cin)
// ss.str()	Get the underlying string from the stringstream
// ss.str(str)	Replace the contents of the stringstream with str
// ss.clear()	Reset state flags (important after reading to EOF)
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string text="hi vishnu keese ho";
    string word;
    vector<string>words;
    stringstream ss (text);
    while(ss>>word){
        words.push_back(word);
    }
}
