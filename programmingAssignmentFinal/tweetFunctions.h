#pragma once
#include "CTweets.h"
#include <algorithm>
using namespace std;

constexpr int kLineWidth = 120;

void DrawLine() // function to draw lines for menu and title
{
    for (int i = 0; i < kLineWidth; i++)
    {
        cout << "*";
    }
}

// function to convert files to vectors
void ReadWordsFromFile(vector <string>& fileVector, string fileName)
{
    ifstream iFile;
    string line;
    iFile.open(fileName + ".txt"); // pass file through


    if (iFile.fail()) // input validation
    {
        cout << "Error" << endl;

    }

    if (iFile.is_open()) // check if file is open
    {
        while (getline(iFile, line))
        {
            fileVector.push_back(line); // add strings to a vector
        }
    }

}

void ReadTweetsFromFile(vector <CTweets>& fileVector, string fileName)
{
    ifstream iFile;
    string line;
    CTweets temp;
    iFile.open(fileName + ".txt"); // pass file through


    if (iFile.fail()) // input validation
    {
        cout << "Error" << endl;

    }

    if (iFile.is_open()) // check if file is open
    {
        while (!iFile.eof())
        {
            temp.mTweets = line;
            getline(iFile, temp.mTweets);

            fileVector.push_back(temp); // add strings to a vector
        }
    }

    iFile.close();

}
