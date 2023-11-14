#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "CTweets.h"
#include <algorithm>

bool CTweets::CheckIfInStruct(vector<wordAppearance> structsVector, string wordToFind)
{
    bool found = false;
    for (int i = 0; i < structsVector.size(); i++) // loop through vector
    {
        if (structsVector[i].word == wordToFind) // set bool to true if words match
        {
            found = true;
        }
    }
    return found;
}

int CTweets::GetIndexValue(vector<wordAppearance> structsVector, string wordToFind)
{
    for (int i = 0; i < structsVector.size(); i++)
    {
        if (structsVector[i].word == wordToFind)
        {
            return i;
        }
    }
}

void CTweets::FindBannedWords(vector<string> bannedWords, vector<wordAppearance>& structsVector)
{
    const char replace = '*';
    int stringPos = 0;
    mNewTweets = mTweets;

    for (int j = 0; j < bannedWords.size(); j++)
    {
        stringPos = mNewTweets.find(bannedWords[j]); // find the banned words

        // carry on finding them till it reaches the end
        while (stringPos != -1)
        {
            stringPos = mNewTweets.find(bannedWords[j]);
            if (stringPos != -1)
            {
                wordAppearance temp;
                if (bannedWords[j].length() == 3)
                {
                    mNewTweets.replace(stringPos + 1, 1, 1, replace); // replace with an asterisk
                }

                else if (bannedWords[j].length() > 3 && bannedWords[j].length() < 7)
                {
                    mNewTweets.replace(stringPos + 2, 1, 1, replace); // replace with an asterisk
                }

                else if (bannedWords[j].length() >= 7)
                {
                    mNewTweets.replace(stringPos + 3, 1, 1, replace); // replace with an asterisk
                }


                if (!CheckIfInStruct(structsVector, bannedWords[j])) // check if word has already been found
                {
                    structsVector.push_back({ bannedWords[j], 1 });  // add the words found to the vector if they're not already in
                }
                else
                {
                    structsVector[GetIndexValue(structsVector, bannedWords[j])].timesAppeared++; // find index and increment occurence count
                }
            }
        }
    }
}

void CTweets::FindSentiment(vector<string> positiveWords, vector<string> negativeWords)
{
    int pos = 0;

    transform(mTweets.begin(), mTweets.end(), mTweets.begin(), tolower); // ref : https://www.youtube.com/watch?v

    for (int j = 0; j < positiveWords.size(); j++)
    {
        pos = mTweets.find(positiveWords[j]); // find the positive words

        if (pos != -1) // if the word has been found then increment the sentiment
        {
            mSentiment++;
        }
    }
    pos = 0;
    for (int x = 0; x < negativeWords.size(); x++)
    {
        pos = mTweets.find(negativeWords[x]); // find the negative words

        if (pos != -1)
        {
            mSentiment--; // if the word has been found then decrement the sentiment
        }
    }

    if (mSentiment < 0)
    {
        mTweets.append(" :  Negative"); // mark as negative if sentiment count is negative
    }

    if (mSentiment > 0)
    {
        mTweets.append(" :  Positive"); // mark as positive if sentiment count is positive
    }

    if (mSentiment == 0)
    {
        mTweets.append(" :  Neutral"); // mark as neutral if sentiment count is zero
    }

}

void CTweets::TweetAnalysis(vector<string> positiveWords, vector<string> negativeWords, vector<string> bannedWords, vector <wordAppearance>& structsVector)
{
    // go to start and end of input array and start of output array to make it lower case
    transform(mTweets.begin(), mTweets.end(), mTweets.begin(), tolower); // ref : https://www.youtube.com/watch?v

    FindBannedWords(bannedWords, structsVector); // call find banned words function
    FindSentiment(positiveWords, negativeWords); // call sentiment function

    cout << mTweets << endl;

}

