#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

// Function to clean and lowercase words
string cleanWord(const string &word)
{
    string cleaned;
    for (char ch : word){
        if (isalpha(ch))
        cleaned += tolower(ch);
    }
    return cleaned;
}
void inputFunction(map<string, int> &wordCount)
{
    std::ifstream inputFile("story.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Could not open the input file." << endl;
        return;
    }

    string line, word;
    while (getline(inputFile, line))
    {
        std::istringstream iss(line);
        while (iss >> word)
        {
            string cleanedWord = cleanWord(word);
            if (!cleanedWord.empty())
            wordCount[cleanedWord]++;
        }
    }

    inputFile.close();
}

void outputFunction(map<string, int> &wordCount)
{
    std::ofstream outputFile("word_count.csv");

    outputFile << "Word,Count\n";

    for (const auto &pair : wordCount)
    outputFile << pair.first << "," << pair.second << "\n";

    outputFile.close();
}

int main()
{
    map<string, int> wordCount;

    inputFunction(wordCount);
    outputFunction(wordCount);

    cout << "Word counts have been written to word_count.csv" << endl;

    return 0;
}
