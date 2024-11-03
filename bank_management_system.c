#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account
{
    int accountNumber;
    char name[100];
    float balance;
};

void createAccount();
void depositMoney();
void withdrawMoney();
void balanceInquiry();
void closeAccount();
void displayMenu();

FILE *file;

int main()
{
    int choice;
    file = fopen("accounts.dat", "rb+");

    if (file == NULL)
    {
        file = fopen("accounts.dat", "wb+");
        if (file == NULL)
        {
            printf("Failed to open file\n");
            return 1;
        }
    }

    while (1)
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            balanceInquiry();
            break;
        case 5:
            closeAccount();
            break;
        case 0:
            fclose(file);
            printf("Thank you for using the system.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayMenu()
{
    printf("\n--- Bank Management System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Balance Inquiry\n");
    printf("5. Close Account\n");
    printf("0. Exit\n");
}

void createAccount()
{
    struct Account acc;
    printf("Enter account number: ");
    scanf("%d", &acc.accountNumber);
    printf("Enter name: ");
    scanf("%s", acc.name);
    printf("Enter initial deposit: ");
    scanf("%f", &acc.balance);

    fseek(file, 0, SEEK_END);
    fwrite(&acc, sizeof(struct Account), 1, file);
    printf("Account created successfully.\n");
}

void depositMoney()
{
    int accNumber;
    float amount;
    struct Account acc;

    printf("Enter account number: ");
    scanf("%d", &accNumber);
    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    rewind(file);
    while (fread(&acc, sizeof(struct Account), 1, file))
    {
        if (acc.accountNumber == accNumber)
        {
            acc.balance += amount;
            fseek(file, -sizeof(struct Account), SEEK_CUR);
            fwrite(&acc, sizeof(struct Account), 1, file);
            printf("Amount deposited successfully.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void withdrawMoney()
{
    int accNumber;
    float amount;
    struct Account acc;

    printf("Enter account number: ");
    scanf("%d", &accNumber);
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    rewind(file);
    while (fread(&acc, sizeof(struct Account), 1, file))
    {
        if (acc.accountNumber == accNumber)
        {
            if (acc.balance >= amount)
            {
                acc.balance -= amount;
                fseek(file, -sizeof(struct Account), SEEK_CUR);
                fwrite(&acc, sizeof(struct Account), 1, file);
                printf("Amount withdrawn successfully.\n");
            }
            else
            {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void balanceInquiry()
{
    int accNumber;
    struct Account acc;

    printf("Enter account number: ");
    scanf("%d", &accNumber);

    rewind(file);
    while (fread(&acc, sizeof(struct Account), 1, file))
    {
        if (acc.accountNumber == accNumber)
        {
            printf("Account Number: %d\n", acc.accountNumber);
            printf("Name: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void closeAccount()
{
    int accNumber;
    struct Account acc;
    FILE *tempFile = fopen("temp.dat", "wb");

    printf("Enter account number to close: ");
    scanf("%d", &accNumber);

    rewind(file);
    while (fread(&acc, sizeof(struct Account), 1, file))
    {
        if (acc.accountNumber != accNumber)
        {
            fwrite(&acc, sizeof(struct Account), 1, tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);

    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");
    file = fopen("accounts.dat", "rb+");

    printf("Account closed successfully.\n");
}
