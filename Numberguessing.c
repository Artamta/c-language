#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int My_guess, Number_of_guesses = 0;
    srand(time(0));
    int random_number = (rand() % 100) + 1;

    printf("Guess the number between 1 and 100\n");

    do
    {
        char input[10];
        int valid_input = 0;

        while (!valid_input)
        {
            printf("Enter your guess: ");
            scanf("%s", input);

            valid_input = 1;
            for (int i = 0; i < strlen(input); i++)
            {
                if (!isdigit(input[i]))
                {
                    valid_input = 0;
                    printf("Invalid input. Please enter a number.\n");
                    break;
                }
            }

            if (valid_input)
            {
                My_guess = atoi(input);
            }
        }

        if (My_guess > random_number)
        {
            printf("Lower number please\n");
        }
        else if (My_guess < random_number)
        {
            printf("Higher number please\n");
        }
        else if (My_guess == random_number)
        {
            printf("Congratulations you guessed the number right\n");
        }

        Number_of_guesses++;
    } while (My_guess != random_number);

    printf("You guessed the number in %d attempts\n", Number_of_guesses);

    char play_again;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &play_again);

    if (play_again == 'y' || play_again == 'Y')
    {
        main();
    }
    else
    {
        printf("Thank you for playing!\n");
    }

    return 0;
}