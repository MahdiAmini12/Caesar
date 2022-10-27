#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[1])
{
    if (argc == 2)
    {
        int num_of_ints = 0;
        int n = strlen(argv[1]);

        //check if all characters in string are digit.
        for (int i = 0; i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                ++num_of_ints;
            }
        }
        //happy path if key is validated as integer
        if (num_of_ints == n)
        {
            //convert key to useable integer
            int key = atoi(argv[1]);
            //get plaintext from user
            string text = get_string("Plain text: ");

            for (int i = 0, t = strlen(text); i < t; i++)
            {
                //check whether char i in user given string is alphabetical
                if (isalpha(text[i]))
                {
                    //perform cypher operation key number of times
                    for (int j = 0; j < key; j++)
                    {
                        if (text[i] >= 65 && text[i] <= 90)
                        {
                            text[i] += 1;
                            if (text[i] > 90)
                            {
                                text[i] = 'A';
                            }
                        }

                        else if (text[i] >= 97 && text[i] <= 122)
                        {
                            text[i] += 1;
                            if (text[i] > 122)
                            {
                                text[i] = 'a';
                            }
                        }
                    }
                }
            }
            printf("Ciphertext: %s\n", text);
        }

        else
        {
            printf("Usage: %s key\n", argv[0]);
        }

    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
    }

}