#include <stdio.h>
#include <conio.h>
#include <math.h>

#define MAX_PRODUCTS 100

//Using Struct,To Define Elements Of a Product(i.e, Name,Quantity,Price.)
struct Product {
    char name[50];
    int quantity;
    float price;
};

//Initializing The Functions 
void add_product(struct Product inventory[], int *numProducts);
void update_quantity(struct Product inventory[], int numProducts);
void display_productDetails(struct Product inventory[], int numProducts);
void display_all_products(struct Product inventory[], int numProducts);
void calculate_totalValue(struct Product inventory[], int numProducts);

int main() {
    struct Product inventory[MAX_PRODUCTS];
    int numProducts = 0;
    int choice;
//Using do-while loop Giving choicw to the user to what he wnat to access
    do {
        // Display menu
        printf("\n-:Inventory Management System:-\n");
        printf("1. Add a new product to the inventory\n");
        printf("2. Update the quantity of an existing product\n");
        printf("3. Display the details of a specific product\n");
        printf("4. Display the details of all products in the inventory\n");
        printf("5. Calculate and display the total value of the inventory(sum of the products*quantity multiplied by their respective prices).\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Using switch-case condition for each of the conditions like to add a product,updating details ,acessing productsetc...
        switch (choice) {
            case 1:
                //calling the Functions
                add_product(inventory, &numProducts);
                break;
            case 2:
                update_quantity(inventory, numProducts);
                break;
            case 3:
                display_productDetails(inventory, numProducts);
                break;
            case 4:
                display_all_products(inventory, numProducts);
                break;
            case 5:
                calculate_totalValue(inventory, numProducts);
                break;
            case 6:
                printf("Exit...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid number.\n");
        }
    } while (choice != 6);

    return 0;
}
//Defining the Functions
void add_product(struct Product inventory[], int *numProducts) {
    if (*numProducts < MAX_PRODUCTS) {
        printf("Enter product name: ");
        scanf("%s", inventory[*numProducts].name);
        printf("Enter quantity: ");
        scanf("%d", &inventory[*numProducts].quantity);
        printf("Enter price for one unit: ");
        scanf("%f", &inventory[*numProducts].price);

        (*numProducts)++;
        printf("Product added successfully.\n");
    } else {
        printf("Inventory is full. Cannot add more products.\n");
    }
}

void update_quantity(struct Product inventory[], int numProducts) {
    char searchName[50];
    printf("Enter the name of the product to update quantity: ");
    scanf("%s", searchName);

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(searchName, inventory[i].name) == 0) {
            printf("Enter new quantity for %s: ", searchName);
            scanf("%d", &inventory[i].quantity);
            printf("Quantity updated successfully.\n");
            return;
        }
    }

    printf("Product not found in inventory.\n");
}

void display_productDetails(struct Product inventory[], int numProducts) {
    char searchName[50];
    printf("Enter the name of the product to display details: ");
    scanf("%s", searchName);

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(searchName, inventory[i].name) == 0) {
            printf("Product Details:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price per unit: $%.2f\n", inventory[i].price);
            return;
        }
    }

    printf("Product not found in inventory.\n");
}

void display_all_products(struct Product inventory[], int numProducts) {
    printf("Inventory Details:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d. %s - Quantity: %d, Price per unit: $%.2f\n", i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void calculate_totalValue(struct Product inventory[], int numProducts) {
    float totalValue = 0;
    for (int i = 0; i < numProducts; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }
    printf("Total value of the inventory: $%.2f\n", totalValue);
}
