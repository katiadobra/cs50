/* CS50:          https://cs50.harvard.edu/x/2020/
*  Caesar:        https://cs50.harvard.edu/x/2020/psets/2/caesar/
*
* The code asks user to provide text and key.
* Returns Caesar ciphered text (https://en.wikipedia.org/wiki/Caesar_cipher)
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // checking that user provides exactly one command-line argument
    if (argc != 2)
    {
        printf("Please enter the key: ./caesar key\n");
        return 1;
    }

    // validating the key
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // atoi => convert a string into a number
    int k = atoi(argv[1]);

    // getting plaintext from user
    printf("plaintext: ");
    string p = get_string("");
    string ciphertext = p;

    // Formula for converting text
    // ciphertext[i] = (p[i] + k) % 26

    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // checking if it's an alphabetic
        if (isalpha(p[i]))
        {
            // if upper 'A' - 'Z' (65 - 90)
            if (isupper(p[i]))
            {
                ciphertext[i] = (p[i] - 65 + k) % 26 + 65;
            }
            // if lower 'a' - 'z' (97 - 122)
            else if (tolower(p[i]))
            {
                ciphertext[i] = (p[i] - 97 + k) % 26 + 97;
            }
        }
    }

    // output
    printf("ciphertext: %s", ciphertext);
    printf("\n");
}
