//this program will ask the user for a number between 0 and 8 to print blocks (#) just like mario game.
#include <stdio.h>
#include <cs50.h>

int main(void)
{
// by using do and while loop we make the user understand to put a number greater than 0 whenwe ask them for height of blocks     
    int n;
    do{
        n = get_int("How much high do you want your blocks ? \n ");
// untill user types a negative number or a number greater than 8 the program will ask them again to enter a number between 0 and 8   
    }while (n<0 || n>8);
// by using for loop, the program prints # blocks in rows and columns 
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n ; j++)
        {
// this if and else statement will limit the number of blocks so it will print the amount of blocks that user typed            
            if (i+j < (n-1))
            printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
