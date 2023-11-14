#include <iostream>
#include <fstream>
#include <vector>
#include "CTweets.h"
#include "tweetFunctions.h"
#include <string>


// declare constants
const string kBannedWordsFile = "banned", kPositiveWordsFile = "positive", kNegativeWordsFile = "negative";
const string kFileType = ".txt";
const string allTweetFiles[4] = { "tweets1", "tweets2", "tweets3",  "tweets4" };
const int kTweets = 5;
const string allFilteredFiles[5] = { "tweets1Filtered", "tweets2Filtered",  "tweets3Filtered",  "tweets4Filtered" };
vector<wordAppearance> structsPerFile1, structsPerFile2, structsPerFile3, structsPerFile4;
vector <vector<wordAppearance>> allStructsPerFile = { structsPerFile1, structsPerFile2, structsPerFile3, structsPerFile4 };
vector<wordAppearance> top10;

int main()
{
    // create vectors to store file content

    vector <string> positiveWords, negativeWords, bannedWords;
    vector <CTweets> tweetsVector1, tweetsVector2, tweetsVector3, tweetsVector4;
    vector <vector<CTweets>> allTweets = { tweetsVector1, tweetsVector2, tweetsVector3, tweetsVector4 };

    ReadWordsFromFile(bannedWords, kBannedWordsFile); // pass vector and banned words file through
    ReadWordsFromFile(positiveWords, kPositiveWordsFile); // pass vector and positive words file through
    ReadWordsFromFile(negativeWords, kNegativeWordsFile); // pass vector and negative words file through


    for (int i = 0; i < allTweets.size(); i++)
    {
        ReadTweetsFromFile(allTweets[i], allTweetFiles[i]); // read through all tweet vectors
    }

    for (int i = 0; i < allTweets.size(); i++) // loop through all tweet vectors
    {
        for (int j = 0; j < kTweets; j++) // loop through each tweet
        {
            DrawLine();
            cout << endl;
            cout << "File " << i + 1 << endl;
            allTweets[i][j].TweetAnalysis(positiveWords, negativeWords, bannedWords, allStructsPerFile[i]);  // call function to display censored words, sentiments and word occurences
            cout << allTweets[i][j].mNewTweets << endl;  // display new tweets (censored words)
            DrawLine();
            cout << endl;
            system("pause");
        }

        for (int x = 0; x < allStructsPerFile[i].size(); x++)
        {
            if (allStructsPerFile[i][x].timesAppeared > 1)
            {
                cout << allStructsPerFile[i][x].word << " appears " << allStructsPerFile[i][x].timesAppeared << " times." << endl; // display word occurences
            }

            else
            {
                cout << allStructsPerFile[i][x].word << " appears once." << endl;
            }
        }


        system("pause");
        system("cls");

    }




}
