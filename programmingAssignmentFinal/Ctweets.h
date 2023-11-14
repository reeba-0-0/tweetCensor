#pragma once
#include <string>
using namespace std;

struct wordAppearance
{
	string word;
	int timesAppeared = 0;
};

class CTweets
{
public:

	string mTweets; // reads per tweet
	string mNewTweets; // reads per tweet for censored words
	int mWordsFound = 0; // counter for found words
	int mSentiment = 0; //  counter for sentiment

	bool CheckIfInStruct(vector <wordAppearance> structsVector, string wordToFind); // usesd to check if a word has been push backed into a vector
	int GetIndexValue(vector<wordAppearance> structsVector, string wordToFind); // function to return the index of a word
	void FindBannedWords(vector<string> bannedWords, vector<wordAppearance>& structsVector);  // check for banned words and censor them
	void FindSentiment(vector<string> positiveWords, vector <string> negativeWords); // find the emotion of each tweet
	void TweetAnalysis(vector<string> positiveWords, vector<string> negativeWords, vector<string> bannedWords, vector <wordAppearance>& structsVector); // display everything
};