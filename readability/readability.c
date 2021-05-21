// this programm will take a text from user and analyzes the text then returns the grade of the text given 
// importing libraries 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("enter your text :");
    int letters = 0;
    int words = 1;
    int sentence = 0;

//using for loop the program will count words letters and sentences till the whole text is readed by program
    for (int i = 0; i < strlen(text); i++)
//counting letters 
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;   
        }
//counting words    
        else if (text[i] == ' ')
        {
            words++;
        }
//counting sentences    
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }     
// using the math formula given the program can calculate the grade of text a number between 0 and 16     
    float grade =  0.0588 * (100 * (float) letters / (float) words) - 0.296 * (100 * (float) sentence / (float) words) - 15.8;
// using if and else statement and the result of the math formula above,the program will tell the user the grad of their text.    
    if (grade >= 0 && grade < 16)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Before Grade 1\n");
    }

}