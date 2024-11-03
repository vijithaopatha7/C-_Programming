#include <stdio.h>
#include <string.h>

void remove_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

int main()
{
    char input[100];

    printf("Hello! I am a simple chatbot.\n");
    printf("You can ask me things like 'hello', 'how are you', 'what is your name', or 'bye'.\n\n");

    while (1)
    {
        printf("You: ");
        fgets(input, sizeof(input), stdin);
        remove_newline(input);

        if (strcmp(input, "hello") == 0)
        {
            printf("Bot: Hello! How can I help you today?\n");
        }
        else if (strcmp(input, "how are you") == 0)
        {
            printf("Bot: I'm just a bot, but thanks for asking!\n");
        }
        else if (strcmp(input, "what is your name") == 0)
        {
            printf("Bot: I am a simple chatbot created in C.\n");
        }
        else if (strcmp(input, "bye") == 0)
        {
            printf("Bot: Goodbye! Have a great day.\n");
            break;
        }
        else
        {
            printf("Bot: Sorry, I don't understand that.\n");
        }
    }
    return 0;
}
