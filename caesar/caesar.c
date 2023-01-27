#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for( int i = 0; i < strlen(argv[1]); i++)
    {
        
        int k;
        k = atoi(argv[1]);

        string plaintext = get_string("Plaintext: ");
        printf("Cyphertext: ");

        for( int j = 0; j < strlen(plaintext); j++ )
        {
            if(islower(plaintext[j]))
            {
                printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
            }
            else if(isupper(plaintext[j]))
            {
                printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
            }
            else
            {
                printf("%c",plaintext[j]);
            }
        }
    }
    printf("\n");


}

int only_digits(string s)
{
    for( int i = 0; i < strlen(s); i++)
    {
        if(!isdigit(s) && (s >= 0 && s <= 9))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            return 0;
        }
}
}