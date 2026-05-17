
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


// Struct


struct Product
{
    string name;
    int quantity;
};


const int MAX_PRODUCTS = 100;

Product products[MAX_PRODUCTS];

int productsCount = 0;


// Recursive Function


int calculateTotalRecursive(int index)
{

    if (index == productsCount)
    {
        return 0;
    }


    return products[index].quantity +
           calculateTotalRecursive(index + 1);
}


// Add Product


void addProduct()
{
    if (productsCount >= MAX_PRODUCTS)
    {
        cout << "\n Inventory is full\n";
        return;
    }

    cin.ignore();

    cout << "\n Enter product name : ";
    getline(cin, products[productsCount].name);

    do
    {
        cout << " Enter quantity : ";
        cin >> products[productsCount].quantity;

        if (products[productsCount].quantity < 0)
        {
            cout << " Negative values are not allowed\n";
        }

    } while (products[productsCount].quantity < 0);

    productsCount++;

    cout << "\n Product added successfully\n";
}


// Display Products


void displayProducts()
{
    if (productsCount == 0)
    {
        cout << "\n No products available\n";
        return;
    }

    cout << "\n========================================================\n";

    cout << left
         << setw(10) << "Number"
         << setw(25) << "Product Name"
         << setw(15) << "Quantity"
         << setw(10) << "Index";

    cout << "\n========================================================\n";

    for (int i = 0; i < productsCount; i++)
    {
        cout << left
             << setw(10) << i + 1
             << setw(25) << products[i].name
             << setw(15) << products[i].quantity
             << setw(10) << i;

        cout << endl;
    }

    cout << "========================================================\n";
}


// Search Product


int searchProduct()
{
    if (productsCount == 0)
    {
        cout << "\n No products found\n";
        return -1;
    }

    cin.ignore();

    string searchName;

    cout << "\n Enter product name to search : ";
    getline(cin, searchName);

    for (int i = 0; i < productsCount; i++)
    {
        if (products[i].name == searchName)
        {
            return i;
        }
    }

    return -1;
}


// Update Quantity


void updateQuantity(int index)
{
    int oldQuantity = products[index].quantity;

    cout << "\n Old Quantity : "
         << oldQuantity << endl;

    do
    {
        cout << " Enter new quantity : ";
        cin >> products[index].quantity;

        if (products[index].quantity < 0)
        {
            cout << " Negative values are not allowed\n";
        }

    } while (products[index].quantity < 0);

    cout << "\n Quantity updated successfully\n";

    cout << " Previous Quantity : "
         << oldQuantity << endl;

    cout << " New Quantity : "
         << products[index].quantity << endl;
}


// Search Then Update


void searchThenUpdate()
{
    int index = searchProduct();

    if (index == -1)
    {
        cout << "\n Product not found\n";
    }
    else
    {
        cout << "\n Product found\n";

        updateQuantity(index);
    }
}


// Show Total Quantity


void showTotalQuantity()
{
    int total = calculateTotalRecursive(0);

    cout << "\n Total Quantity = "
         << total << endl;
}


// Menu


int showMenu()
{
    int choice;

    do
    {
        cout << "\n=========== Inventory Management System ===========\n";

        cout << "1- Add Product\n";
        cout << "2- Modify Quantity\n";
        cout << "3- Display Products\n";
        cout << "4- Search Product\n";
        cout << "5- Total Quantity\n";
        cout << "6- Exit\n";

        cout << "\n Enter your choice : ";
        cin >> choice;

        if (choice < 1 || choice > 6)
        {
            cout << "\n Invalid choice\n";
        }

    } while (choice < 1 || choice > 6);

    return choice;
}


int main()
{
    int choice;

    do
    {
        choice = showMenu();

        switch (choice)
        {
        case 1:
            addProduct();
            break;

        case 2:
            searchThenUpdate();
            break;

        case 3:
            displayProducts();
            break;

        case 4:
        {
            int index = searchProduct();

            if (index == -1)
            {
                cout << "\n Product not found\n";
            }
            else
            {
                cout << "\n Product found\n";

                cout << " Product Name : "
                     << products[index].name << endl;

                cout << " Quantity : "
                     << products[index].quantity << endl;

                cout << " Index : "
                     << index << endl;
            }

            break;
        }

        case 5:
            showTotalQuantity();
            break;

        case 6:
            cout << "\n Program terminated successfully\n";
            break;
        }

    } while (choice != 6);

    return 0;
}
