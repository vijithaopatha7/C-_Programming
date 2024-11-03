#include <stdio.h>
#include <string.h>

int main()
{
    int score = 0;
    int answer;

    printf("Welcome to the Quiz Game!\n");
    printf("Each question has four options. Choose the correct answer by entering the number.\n\n");

    // Question 1
    printf("1. What is the capital of France?\n");
    printf("1) Berlin\n");
    printf("2) Madrid\n");
    printf("3) Paris\n");
    printf("4) Rome\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 3)
    {
        printf("Correct!\n\n");
        score++;
    }
    else
    {
        printf("Wrong! The correct answer is Paris.\n\n");
    }

    // Question 2
    printf("2. What is the largest planet in our solar system?\n");
    printf("1) Earth\n");
    printf("2) Mars\n");
    printf("3) Jupiter\n");
    printf("4) Venus\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 3)
    {
        printf("Correct!\n\n");
        score++;
    }
    else
    {
        printf("Wrong! The correct answer is Jupiter.\n\n");
    }

    // Question 3
    printf("3. Who wrote 'To Kill a Mockingbird'?\n");
    printf("1) Harper Lee\n");
    printf("2) Mark Twain\n");
    printf("3) J.K. Rowling\n");
    printf("4) Charles Dickens\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == 1)
    {
        printf("Correct!\n\n");
        score++;
    }
    else
    {
        printf("Wrong! The correct answer is Harper Lee.\n\n");
    }

    // Final score
    printf("Quiz Over! Your score is: %d out of 3\n", score);
    if (score == 3)
    {
        printf("Excellent! You got all the answers right!\n");
    }
    else if (score == 2)
    {
        printf("Good job! Almost perfect!\n");
    }
    else
    {
        printf("Keep trying! You can do better.\n");
    }
    return 0;
}
