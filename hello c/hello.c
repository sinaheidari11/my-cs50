// this program will asj your name and says hello to you.
#include <stdio.h>
#include <cs50.h>

int main(void)
{
//by using get_string function this program will ask for the user name    
    string name = get_string("dear user tell me what is your name please :\n");
//after the user gives the program their name it will say hello to them.
    printf("hello dear %s and welcome to my program hope you enjoy it.\n", name );
}
