//this program will ask for your change then it will calculate homany coin you need
//importing libraries.   
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
// creating variables     
    float changes;

    int changecent;

    int coins = 0;
// using do and while loop to make sure the user will enter a positive number.
    do 
    {
        changes = get_float("enter your change :");
    }
    while (changes < 0);
// using math library 
    changecent = round(changes * 100);
// counting quarters 
    while (changecent >= 25)
    {
        changecent = changecent - 25;
        coins++;
    }
// counting dimes    
    while (changecent >= 10)
    {
        changecent = changecent - 10;
        coins++;

    }
//counting nickels   
    while (changecent >= 5)
    {
        changecent = changecent - 5;
        coins++;
    }
// counting pennis    
    while (changecent >= 1)
    {
        changecent = changecent - 1;
        coins++;
    }
//adding all of coins and printing the results.    
    printf("coins needed :%d \n", coins);
}
