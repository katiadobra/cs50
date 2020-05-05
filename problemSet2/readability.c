/* CS50:          https://cs50.harvard.edu/x/2020/
*  Readability:   https://cs50.harvard.edu/x/2020/psets/2/readability/
*
* The code computes the approximate grade level needed to comprehend some text
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
float computing_grade(int letters, int words, int sentences);


int main(void)
{
// getting user input
    string str = get_string("Text: ");

// counting the number of letters
    int letters = count_letters(str);

// counting the number of words
    int words = count_words(str);

// counting the number of sentences
    int sentences = count_sentences(str);

// computing Coleman-Liau index
    float grade = computing_grade(letters, words, sentences);

    (grade < 1) ? printf("Before Grade 1\n") : (grade > 16) ? printf("Grade 16+\n") : printf("Grade %.0f\n", grade);
}

int count_letters(string s)
{
    // counting letters
    int count = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // checking for an alphabetic character;
        if (isalpha(s[i]) != 0)
        {
            count++;
        }
    }

    return count;
}


int count_words(string s)
{
    // counting words
    int count = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }

// plus 1 because of the last word without space.
    return count + 1;
}


int count_sentences(string s)
{
    int count = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            count++;
        }
    }
    return count;
}


float computing_grade(int letters, int words, int sentences)
{
// computing Coleman-Liau index using the formula:
// index = 0.0588 * L - 0.296 * S - 15.8
// L = the average number of letters per 100 words
// S = the average number of sentences per 100 words

// You might want to cast your one or more values to float
// before performing division when calculating L and S!
    float L = (float) letters * 100 / (float) words;
    float S = (float) sentences * 100 / (float) words;

    float index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}
