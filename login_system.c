#include <stdio.h>
#include <string.h>

void registerUser()
{
    char fullName[100], email[100], phone[20], username[50], password[50];
    FILE *file = fopen("credentials.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Register\n");
    printf("Enter Full Name: ");
    scanf(" %[^\n]s", fullName);
    printf("Enter Email: ");
    scanf("%s", email);
    printf("Enter Phone Number: ");
    scanf("%s", phone);
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    fprintf(file, "%s\n%s\n%s\n%s\n%s", fullName, email, phone, username, password);
    fclose(file);

    printf("Registration successful!\n\n");
}

void loginUser()
{
    char username[50], password[50];
    char storedUsername[50], storedPassword[50];
    char storedFullName[100], storedEmail[100], storedPhone[20];
    FILE *file = fopen("credentials.txt", "r");

    if (file == NULL)
    {
        printf("No registered user found. Please register first.\n");
        return;
    }

    fscanf(file, "%[^\n]\n%s\n%s\n%s\n%s", storedFullName, storedEmail, storedPhone, storedUsername, storedPassword);
    fclose(file);

    printf("Login\n");
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0)
    {
        printf("\n-------------------------\n");
        printf("Login successful!\n");
        printf("-------------------------\n");
        printf("Your full name: %s\n", storedFullName);
        printf("Your email: %s\n", storedEmail);
        printf("Your phone: %s\n", storedPhone);
    }
    else
    {
        printf("Incorrect username or password. Please try again.\n");
    }
}

int main()
{
    int choice;
    printf("1. Register\n2. Login\nChoose an option: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        registerUser();
        break;
    case 2:
        loginUser();
        break;
    default:
        printf("Invalid choice.\n");
    }
    return 0;
}
