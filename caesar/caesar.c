// importing libraries
// this program is a sample of caesar algorithm
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <cs50.h>
#include <ctype.h>
bool check_valid_key(string s);

int main(int argc, string argv[])
{
// using if statement to make sure user enters valid char    
    if (argc != 2 || !check_valid_key(argv[1]))
    {
        printf("usage; ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]); //"13"-> 13
    
    string plaintext = get_string("plaintext: ");
    
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext) ; i++)
    { 
        char c = plaintext[i];
        if (isalpha(c))
        {
            char m = 'A';
            if (islower(c))
            {    
                m = 'a';
            }   
// by using this formula we can make caesar algorithm               
            printf("%c", (c - m + key) % 26 + m);
        }
        else 
        {  
            printf("%c", c);
        }   
    }
    printf("\n");
}

bool check_valid_key(string s)
{
    for (int i = 0 ; i < strlen(s); i++)
        if (!isdigit(s[i]))
        { 
            return false;
        } 
    return true;   
          
}
