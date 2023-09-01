#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Define a struct for a product
typedef struct
{
    char name[MAX_NAME_LENGTH];
    int price;
} Product;

// Array to store the products
Product products[MAX_PRODUCTS];

// Variables to track the number of products, the total cost of the cart, and the discount
int productCount = 0;
double totalCost = 0;
double discount = 0;

// Function to add a new product to the array
void addProduct(char *name, int price)
{
    // Check if the maximum product limit has been reached
    if (productCount >= MAX_PRODUCTS)
    {
        printf("Maximum product limit reached. Cannot add more products.\n");
        return;
    }

    // Copy the product name and set its price in the array
    strcpy(products[productCount].name, name);
    products[productCount].price = price;
    productCount++;
}

// Function to print the main menu options
void printMenu()
{
    printf("\n-- Shopping Mall Menu --\n");
    printf("1. Clothing Section\n");
    printf("2. Accessories Section\n");
    printf("3. Cosmetics Section\n");
    printf("4. Footwear Section\n");
    printf("5. View Cart\n");
    printf("6. Checkout\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Function to print the available products in each section
void printProductMenu()
{
    printf("\n-- Available Products --\n");
    for (int i = 0; i < productCount; i++)
    {
        printf("%d. %s - Rs.%d\n", i + 1, products[i].name, products[i].price);
    }
    printf("Enter your choice: ");
}

// Function to add a product to the cart based on the user's choice
void addToCart(int choice)
{
    if (choice < 1 || choice > productCount)
    {
        printf("Invalid choice! Please try again.\n");
        return;
    }

    int quantity;
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    totalCost += (products[choice - 1].price * quantity);

    printf("%d %s added to cart.\n", quantity, products[choice - 1].name);
}

// Function to handle the checkout process
void checkout()
{
    // Check if the cart is empty
    if (totalCost == 0)
    {
        printf("Your cart is empty. Nothing to checkout.\n");
        return;
    }

    printf("\n-- Checkout --\n");
    printf("Total Cost: Rs.%.2lf\n", totalCost);

    // Apply discount based on the total cost
    if (totalCost >= 2000 && totalCost < 5000)
    {
        discount = totalCost * 0.1;
        totalCost -= discount;
        printf("Discount Applied: Rs.%.2lf (10%%)\n", discount);
    }
    else if (totalCost >= 5000 && totalCost < 10000)
    {
        discount = totalCost * 0.2;
        totalCost -= discount;
        printf("Discount Applied: Rs.%.2lf (20%%)\n", discount);
    }
    else if (totalCost >= 10000)
    {
        discount = totalCost * 0.3;
        totalCost -= discount;
        printf("Discount Applied: Rs.%.2lf (30%%)\n", discount);
    }

    printf("Final Cost: Rs.%.2lf\n", totalCost);

    // Clear the cart for the next shopping session
    totalCost = 0;
    discount = 0;
}

int main()
{
    char name[100];
    printf("Enter the customer name: ");
    fgets(name, 100, stdin);

    printf("***** WELCOME TO THE STYLE CAPITAL *****");

    // Add products to the different sections of the shopping mall

    // Clothing Section
    addProduct("Shirt", 500);
    addProduct("Trousers", 1000);
    addProduct("Jacket", 1500);
    addProduct("Dress", 1200);
    addProduct("Skirt", 800);

    // Accessories Section
    addProduct("Belt", 250);
    addProduct("Bracelet", 300);
    addProduct("Chain with Pendant", 400);
    addProduct("Bangles", 350);

    // Cosmetics Section
    addProduct("Lipstick", 150);
    addProduct("Foundation", 300);
    addProduct("Eyeshadow Palette", 500);
    addProduct("Mascara", 200);
    addProduct("Perfume", 1000);

    // Footwear Section
    addProduct("Shoes", 1000);
    addProduct("Sneakers", 800);
    addProduct("Sandals", 500);
    addProduct("Boots", 1200);

    int choice;
    bool shoppingComplete = false;

    while (!shoppingComplete)
    {
        printMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n-- Clothing Section --\n");
            printf("1. Shirt - Rs.500\n");
            printf("2. Trousers - Rs.1000\n");
            printf("3. Jacket - Rs.1500\n");
            printf("4. Dress - Rs.1200\n");
            printf("5. Skirt - Rs.800\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            // Validate the choice
            if (choice < 1 || choice > 5)
            {
                printf("Invalid Input... Please try again\n");
                break;
            }

            addToCart(choice);
            break;

        case 2:
            printf("\n-- Accessories Section --\n");
            printf("1. Belt - Rs.250\n");
            printf("2. Bracelet - Rs.300\n");
            printf("3. Chain with Pendant - Rs.400\n");
            printf("4. Bangles - Rs.350\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            // Validate the choice
            if (choice < 1 || choice > 4)
            {
                printf("Invalid Input... Please try again\n");
                break;
            }

            addToCart(choice + 5);
            break;

        case 3:
            printf("\n-- Cosmetics Section --\n");
            printf("1. Lipstick - Rs.150\n");
            printf("2. Foundation - Rs.300\n");
            printf("3. Eyeshadow Palette - Rs.500\n");
            printf("4. Mascara - Rs.200\n");
            printf("5. Perfume - Rs.1000\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            // Validate the choice
            if (choice < 1 || choice > 5)
            {
                printf("Invalid Input... Please try again\n");
                break;
            }

            addToCart(choice + 9);
            break;

        case 4:
            printf("\n-- Footwear Section --\n");
            printf("1. Shoes - Rs.1000\n");
            printf("2. Sneakers - Rs.800\n");
            printf("3. Sandals - Rs.500\n");
            printf("4. Boots - Rs.1200\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            // Validate the choice
            if (choice < 1 || choice > 4)
            {
                printf("Invalid Input... Please try again\n");
                break;
            }

            addToCart(choice + 14);
            break;

        case 5:
            printf("\n-- View Cart --\n");
            printf("Total Cost: Rs.%.2lf\n", totalCost);
            break;

        case 6:
            checkout();
            shoppingComplete = true;
            printf("Thank you for shopping with us!\nPlease visit again, %s\n", name);
            break;

        case 7:
            printf("\n-- Exiting --\n");
            shoppingComplete = true;
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}