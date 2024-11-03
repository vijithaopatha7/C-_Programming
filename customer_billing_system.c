#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_PRODUCTS 10

typedef struct
{
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct
{
    int id;
    char name[50];
    Product products[MAX_PRODUCTS];
    int productCount;
    float total;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void addCustomer()
{
    if (customerCount >= MAX_CUSTOMERS)
    {
        printf("Customer limit reached.\n");
        return;
    }

    Customer customer;
    customer.id = customerCount + 1;
    printf("Enter customer name: ");
    scanf("%s", customer.name);
    customer.productCount = 0;
    customer.total = 0.0;

    customers[customerCount] = customer;
    customerCount++;

    printf("Customer added successfully.\n");
}

void addProductToCustomer(int customerId)
{
    if (customerId <= 0 || customerId > customerCount)
    {
        printf("Invalid customer ID.\n");
        return;
    }

    Customer *customer = &customers[customerId - 1];
    if (customer->productCount >= MAX_PRODUCTS)
    {
        printf("Product limit reached for this customer.\n");
        return;
    }

    Product product;
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter product price: ");
    scanf("%f", &product.price);

    customer->products[customer->productCount] = product;
    customer->total += product.quantity * product.price;
    customer->productCount++;

    printf("Product added successfully.\n");
}

void displayBill(int customerId)
{
    if (customerId <= 0 || customerId > customerCount)
    {
        printf("Invalid customer ID.\n");
        return;
    }

    Customer customer = customers[customerId - 1];
    printf("\n--- Bill for %s (ID: %d) ---\n", customer.name, customer.id);
    printf("Product\tQuantity\tPrice\tTotal\n");

    for (int i = 0; i < customer.productCount; i++)
    {
        Product product = customer.products[i];
        float total = product.quantity * product.price;
        printf("%s\t%d\t\t%.2f\t%.2f\n", product.name, product.quantity, product.price, total);
    }

    printf("Total Amount: %.2f\n", customer.total);
    printf("----------------------------\n");
}

void displayAllBills()
{
    for (int i = 0; i < customerCount; i++)
    {
        displayBill(customers[i].id);
    }
}

int main()
{
    int choice, customerId;

    while (1)
    {
        printf("\nCustomer Billing System\n");
        printf("1. Add Customer\n");
        printf("2. Add Product to Customer\n");
        printf("3. Display Customer Bill\n");
        printf("4. Display All Bills\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addCustomer();
            break;
        case 2:
            printf("Enter customer ID: ");
            scanf("%d", &customerId);
            addProductToCustomer(customerId);
            break;
        case 3:
            printf("Enter customer ID: ");
            scanf("%d", &customerId);
            displayBill(customerId);
            break;
        case 4:
            displayAllBills();
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
