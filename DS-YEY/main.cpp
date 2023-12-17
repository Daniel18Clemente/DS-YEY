#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include<cstdlib>
#include<stdlib.h>
#include <chrono>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "lodepng.h"
#include "qrcodegen.hpp"

using namespace std;
using namespace chrono;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

struct AccountNode
{
    string UsernameAdmin;
    string PasswordAdmin;
    string birthDate;
    string UsernameUser;
    string PasswordUser;
    string userFullname;
    string userContactnumber;
    AccountNode* next;
};

struct ProductNode
{
    string productClassification;
    string productCode;
    string date;
    string productName;
    double price;
    int quantity;
    ProductNode* next;
};

struct TransactionNode
{
    string transactionUsername;
    string product_name;
    int purchased_quantity;
    string modeOfPayment;
    TransactionNode* next;
};

struct ShoppingCartNode
{
    string userCart;
    string productName;
    double price;
    int quantity;
    ShoppingCartNode* next;
};

ShoppingCartNode* ShoppingCartHead = NULL;
TransactionNode* Transactionhead = NULL;
ProductNode* Producthead = NULL;
AccountNode* Accounthead = NULL;
string product_name;
double price;
int quantity;
int choice;
int position;
string searchAccount;
string classification;
int i=0;
string special_key ="SIRPENGEUNO";

void clearBuffer()
{
    cin.clear();
    cin.ignore(100, '\n');
    //cout<<"\nInvalid Input\n";
}


bool isNumeric(string  str)
{
    stringstream ss(str);
    double num;
    return ss >> num >> ws  &&  ss.eof();
}


string generateProductCode()
{
    const string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int productCodeLength = 8;

    string productCode;
    for (int i = 0; i < productCodeLength; ++i)
    {
        productCode += charset[rand() % charset.length()];
    }

    return productCode;
}

string getCurrentDate()
{
    time_t now = time(0);
    tm* date = localtime(&now);

    stringstream ss;
    ss << date->tm_year + 1900 << "-"
       << setw(2) << setfill('0') << date->tm_mon + 1 << "-"
       << setw(2) << setfill('0') << date->tm_mday;

    return ss.str();
}

void openImageInViewer(const std::string& filename)
{
    string command = "start " + filename;
    system(command.c_str());
}

void setPosxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
    return;
}

void setColor (int x)
{
    SetConsoleTextAttribute(console, x);
}

void MembersName()
{
    system("CLS");
    cout << endl << endl;

//    for( i = 0; i < 110; i++)
//    {
//        setColor(17);
//        setPosxy(6,3);
//        cout << "  ";
//        setPosxy(6,4);
//        cout << "  ";
//        setPosxy(6,5);
//        cout << "  ";
//        setPosxy(6,6);
//        cout << "  ";
//        setPosxy(6,7);
//        cout << "  ";
//        setPosxy(6,8);
//        cout << "  ";
//        setPosxy(6,9);
//        cout << "  ";
//        setPosxy(6,10);
//        cout << "  ";
//        setPosxy(6,11);
//        cout << "  ";
//        setPosxy(6,12);
//        cout << "  ";
//        setPosxy(6,13);
//        cout << "  ";
//        setPosxy(6,14);
//        cout << "  ";
//        setPosxy(6,15);
//        cout << "  ";
//        setPosxy(6,16);
//        cout << "  ";
//        setPosxy(6,17);
//        cout << "  ";
//        setColor(17+i);
//        setPosxy(8+i, 3);
//        cout <<" ";
//        setPosxy(8+i,17);
//        cout <<" ";
//
//
//        setPosxy(118,3);
//        cout << "  ";
//        setPosxy(118,4);
//        cout << "  ";
//        setPosxy(118,5);
//        cout << "  ";
//        setPosxy(118,6);
//        cout << "  ";
//        setPosxy(118,7);
//        cout << "  ";
//        setPosxy(118,8);
//        cout << "  ";
//        setPosxy(118,9);
//        cout << "  ";
//        setPosxy(118,10);
//        cout << "  ";
//        setPosxy(118,11);
//        cout << "  ";
//        setPosxy(118,12);
//        cout << "  ";
//        setPosxy(118,13);
//        cout << "  ";
//        setPosxy(118,14);
//        cout << "  ";
//        setPosxy(118,15);
//        cout << "  ";
//        setPosxy(118,16);
//        cout << "  ";
//        setPosxy(118,17);
//        cout << "  ";
//        Sleep(1);
//    }
//

    for ( i = 0; i < 40; i++)
    {
        for ( int x = 0; x < 7; x++)
        {

            setColor(x);
            setPosxy(9+i,5);
            cout << " ";
            setPosxy(9+i,6);
            cout << " ";
            setPosxy(9+i,7);
            cout << " ";
            setPosxy(9+i,8);
            cout << " ";
            setPosxy(9+i,9);
            cout << " ";
            setPosxy(9+i,10);
            cout << " ";
            setPosxy(9+i,11);
            cout << " ";
            setPosxy(9+i,12);
            cout << " ";
            setPosxy(9+i,13);
            cout << " ";
            setPosxy(9+i,14);
            cout << " ";

            setPosxy(10+i,5);
            cout << "Clemente, Daniel Francis S. " ;
            setPosxy(10+i,6);
            cout << "Alcantara, Krystian Ivan B." ;
            setPosxy(10+i,7);
            cout << "Daligdig, Jancee A." ;
            setPosxy(10+i,8);
            cout << "De Jesus, Novie Anne R." ;
            setPosxy(10+i,9);
            cout << "Dela Peña, Edrian C" ;
            setPosxy(10+i,10);
            cout << "Galicio, Alexis Joy B." ;
            setPosxy(10+i,11);
            cout << "Imson, Sean Enrie M." ;
            setPosxy(10+i,12);
            cout << "Pangan, Daniel G." ;
            setPosxy(10+i,13);
            cout << "Ramos, John Niel C." ;
            setPosxy(10+i,14);
            cout << "Vinta, Juana Marie E." ;
            setPosxy(10+i,17);
            setColor(120);
            cout << " LOADING" ;
            setColor(x);

            cout << endl << endl<<endl;
            Sleep(1);
        }
    }
}

void frontPage(string menuType)
{
    system("CLS");
    cout << endl << endl;

    for( i = 0; i < 110; i++)
    {
        setColor(17);
        setPosxy(6,3);
        cout << "  ";
        setPosxy(6,4);
        cout << "  ";
        setPosxy(6,5);
        cout << "  ";
        setPosxy(6,6);
        cout << "  ";
        setPosxy(6,7);
        cout << "  ";
        setPosxy(6,8);
        cout << "  ";
        setPosxy(6,9);
        cout << "  ";
        setPosxy(6,10);
        cout << "  ";
        setPosxy(6,11);
        cout << "  ";
        setPosxy(6,12);
        cout << "  ";
        setPosxy(6,13);
        cout << "  ";
        setPosxy(6,14);
        cout << "  ";
        setPosxy(6,15);
        cout << "  ";
        setPosxy(6,16);
        cout << "  ";
        setPosxy(6,17);
        cout << "  ";
        setColor(17+i);
        setPosxy(8+i, 3);
        cout <<" ";
        setPosxy(8+i,17);
        cout <<" ";


        setPosxy(118,3);
        cout << "  ";
        setPosxy(118,4);
        cout << "  ";
        setPosxy(118,5);
        cout << "  ";
        setPosxy(118,6);
        cout << "  ";
        setPosxy(118,7);
        cout << "  ";
        setPosxy(118,8);
        cout << "  ";
        setPosxy(118,9);
        cout << "  ";
        setPosxy(118,10);
        cout << "  ";
        setPosxy(118,11);
        cout << "  ";
        setPosxy(118,12);
        cout << "  ";
        setPosxy(118,13);
        cout << "  ";
        setPosxy(118,14);
        cout << "  ";
        setPosxy(118,15);
        cout << "  ";
        setPosxy(118,16);
        cout << "  ";
        setPosxy(118,17);
        cout << "  ";
        Sleep(1);
    }


    for ( i = 0; i < 7; i++)
    {
        for ( int x = 0; x < 7; x++)
        {

            setColor(x);
            setPosxy(9+i,5);
            cout << " ";
            setPosxy(9+i,6);
            cout << " ";
            setPosxy(9+i,7);
            cout << " ";
            setPosxy(9+i,8);
            cout << " ";
            setPosxy(9+i,9);
            cout << " ";
            setPosxy(9+i,10);
            cout << " ";
            setPosxy(9+i,11);
            cout << " ";

            setPosxy(10+i,5);
            cout << "########  ########  ####### ###      ###   ####         #####  ########   ####   #####  ###### " ;
            setPosxy(10+i,6);
            cout << "##    ##     ##         ##  ## ##  ## ## ##    ##      ##   ##    ##    ##    ## ##  ## ##     " ;
            setPosxy(10+i,7);
            cout << "##           ##        ##   ##   ##   ## ##    ##       ##        ##    ##    ## ##  ## ####   " ;
            setPosxy(10+i,8);
            cout << "##  ####     ##       ##    ##        ## ##    ##         ##      ##    ##    ## #####  ##     " ;
            setPosxy(10+i,9);
            cout << "##    ##     ##      ##     ##        ## ##    ##          ##     ##    ##    ## ##  ## ##     " ;
            setPosxy(10+i,10);
            cout << "##    ##     ##     ##      ##        ## ##    ##      ##   ##    ##    ##    ## ##  ## ##     " ;
            setPosxy(10+i,11);
            cout << "########  ######## ######## ##        ##   ####         #####     ##      ####   ##  ## ###### " ;
            cout << endl <<endl<< "\t\t    \"The Ultimate Variety Store: Elevate Your Lifestyle, Embrace Endless Possibilities!\"" << endl<<endl;
            cout<<"\t\t\t\t\t\t\t["<< menuType<<"]";

            cout << endl << endl<<endl;
            Sleep(1);
        }
    }
}
void otherPage(string menuType)
{
    system("CLS");
    cout << endl << endl;

    for( i = 0; i < 110; i++)
    {
        setColor(17);
        setPosxy(6,3);
        cout << "  ";
        setPosxy(6,4);
        cout << "  ";
        setPosxy(6,5);
        cout << "  ";
        setPosxy(6,6);
        cout << "  ";
        setPosxy(6,7);
        cout << "  ";
        setPosxy(6,8);
        cout << "  ";
        setPosxy(6,9);
        cout << "  ";
        setPosxy(6,10);
        cout << "  ";
        setPosxy(6,11);
        cout << "  ";
        setPosxy(6,12);
        cout << "  ";
        setPosxy(6,13);
        cout << "  ";
        setPosxy(6,14);
        cout << "  ";
        setPosxy(6,15);
        cout << "  ";
        setPosxy(6,16);
        cout << "  ";
        setPosxy(6,17);
        cout << "  ";
        setColor(17+i);
        setPosxy(8+i, 3);
        cout <<" ";
        setPosxy(8+i,17);
        cout <<" ";


        setPosxy(118,3);
        cout << "  ";
        setPosxy(118,4);
        cout << "  ";
        setPosxy(118,5);
        cout << "  ";
        setPosxy(118,6);
        cout << "  ";
        setPosxy(118,7);
        cout << "  ";
        setPosxy(118,8);
        cout << "  ";
        setPosxy(118,9);
        cout << "  ";
        setPosxy(118,10);
        cout << "  ";
        setPosxy(118,11);
        cout << "  ";
        setPosxy(118,12);
        cout << "  ";
        setPosxy(118,13);
        cout << "  ";
        setPosxy(118,14);
        cout << "  ";
        setPosxy(118,15);
        cout << "  ";
        setPosxy(118,16);
        cout << "  ";
        setPosxy(118,17);
        cout << "  ";
        Sleep(0.0001);
    }


    for ( i = 0; i < 7; i++)
    {
        setColor(6);
        setPosxy(9+i,5);
        cout << " ";
        setPosxy(9+i,6);
        cout << " ";
        setPosxy(9+i,7);
        cout << " ";
        setPosxy(9+i,8);
        cout << " ";
        setPosxy(9+i,9);
        cout << " ";
        setPosxy(9+i,10);
        cout << " ";
        setPosxy(9+i,11);
        cout << " ";

        setPosxy(10+i,5);
        cout << "########  ########  ####### ###      ###   ####         #####  ########   ####   #####  ###### " ;
        setPosxy(10+i,6);
        cout << "##    ##     ##         ##  ## ##  ## ## ##    ##      ##   ##    ##    ##    ## ##  ## ##     " ;
        setPosxy(10+i,7);
        cout << "##           ##        ##   ##   ##   ## ##    ##       ##        ##    ##    ## ##  ## ####   " ;
        setPosxy(10+i,8);
        cout << "##  ####     ##       ##    ##        ## ##    ##         ##      ##    ##    ## #####  ##     " ;
        setPosxy(10+i,9);
        cout << "##    ##     ##      ##     ##        ## ##    ##          ##     ##    ##    ## ##  ## ##     " ;
        setPosxy(10+i,10);
        cout << "##    ##     ##     ##      ##        ## ##    ##      ##   ##    ##    ##    ## ##  ## ##     " ;
        setPosxy(10+i,11);
        cout << "########  ######## ######## ##        ##   ####         #####     ##      ####   ##  ## ###### " ;
        cout << endl <<endl<< "\t\t    \"The Ultimate Variety Store: Elevate Your Lifestyle, Embrace Endless Possibilities!\"" << endl<<endl;
        cout<<"\t\t\t\t\t\t\t["<< menuType<<"]";

        cout << endl << endl<<endl<<endl;
        Sleep(0.001);
    }
}


void addAccountAdmin(string username, string password)
{
    AccountNode* ptr = Accounthead;
    while (ptr != nullptr)
    {
        if (ptr->UsernameAdmin == username)
        {
            cout << "\n\t\t\t\t\t\tUsername already exists. Please choose a different username\n\n";
            cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
            _getch();
            return;
        }
        ptr = ptr->next;
    }
    AccountNode* tempAccountNode = new AccountNode;
    tempAccountNode->UsernameAdmin = username;
    tempAccountNode->PasswordAdmin = password;
    tempAccountNode->next = Accounthead;
    Accounthead = tempAccountNode;
    cout << "\n\t\t\t\t\t\tAccount created successfully\n";
    cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
    _getch();
}

void addAccountUser(string userFullname, string userContactnumber,string birthDate,string username, string password)
{
    AccountNode* ptr = Accounthead;
    while (ptr != nullptr)
    {
        if (ptr->UsernameUser == username)
        {
            cout << "\n\t\t\t\t\t\tUsername already exists. Please choose a different username\n\n";
            cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
            _getch();
            return;
        }
        ptr = ptr->next;
    }
    AccountNode* tempAccountNode = new AccountNode;
    tempAccountNode->userFullname = userFullname;
    tempAccountNode->userContactnumber = userContactnumber;
    tempAccountNode->UsernameUser = username;
    tempAccountNode->PasswordUser = password;
    tempAccountNode->birthDate = birthDate;
    tempAccountNode->next = Accounthead;
    Accounthead = tempAccountNode;
    cout << "\n\t\t\t\t\t\tAccount created successfully\n";
    cout<< "\n\n\n\n\t\t\t\t\t\t\tPress any key....";
    _getch();
}


void removeAccountUser(string username)
{
    AccountNode* ptr = Accounthead;
    AccountNode* previous = nullptr;

    while (ptr != nullptr)
    {
        if (ptr->UsernameUser == username)
        {
            if (previous == nullptr)
            {
                Accounthead = ptr->next;
            }
            else
            {
                previous->next = ptr->next;
            }
            cout << "\n\t\t\t\t\tAccount removed successfully\n";
            cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
            _getch();
            return;
        }

        previous = ptr;
        ptr = ptr->next;
    }
    cout << "\n\t\t\t\t\tAccount not found\n";
    cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
    _getch();
}

void removeAccountAdmin(string username)
{
    AccountNode* ptr = Accounthead;
    AccountNode* previous = nullptr;

    while (ptr != nullptr)
    {
        if (ptr->UsernameAdmin == username)
        {
            if (previous == nullptr)
            {
                Accounthead = ptr->next;
            }
            else
            {
                previous->next = ptr->next;
            }
            cout << "\t\t\t\t\t\tAccount removed successfully\n";
            cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
            _getch();
            return;
        }

        previous = ptr;
        ptr = ptr->next;
    }
    cout << "\t\t\t\t\tAccount not found\n";
    cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
    _getch();
}
void changeFullName(string username)
{
    AccountNode* userPtr = Accounthead;

    while (userPtr != nullptr)
    {
        if (userPtr->UsernameUser == username)
        {
            cout << "\n\t\t\t\t\tEnter new full name: ";
            cin.ignore();
            getline(cin, userPtr->userFullname);
            cout << "\n\t\t\t\t\tFull name changed successfully\n";
            cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
            _getch();
            return;
        }
        userPtr = userPtr->next;
    }

//    cout << "\t\t\t\t\tUser not found.\n";
//    cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
//    _getch();
    return;
}

void editAccount(string username)
{
    AccountNode* userPtr = Accounthead;

    while (userPtr != nullptr)
    {
        if (userPtr->UsernameUser == username)
        {
            do
            {
                cout << "\n\t\t\t\t\tEdit Account for: " << username << "\n";
                cout << "\t\t\t\t\t\t\t[1] Change Password\n"
                     << "\t\t\t\t\t\t\t[2] Change Contact Number\n"
                     << "\t\t\t\t\t\t\t[3] Change Full Name\n"
                     << "\t\t\t\t\t\t\t[4] Back to Menu\n"
                     << "\t\t\t\t    Enter Your Choice : ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "\n\t\t\t\t\tEnter new password: ";
                    cin >> userPtr->PasswordUser;
                    cout << "\n\t\t\t\t\tPassword changed successfully\n";
                    cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
                    _getch();
                    break;
                case 2:
                    cout << "\n\t\t\t\t\tEnter new contact number: ";
                    cin >> userPtr->userContactnumber;
                    cout << "\n\t\t\t\t\tContact number changed successfully\n";
                    cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
                    _getch();
                    break;
                case 3:
                    changeFullName(username);
                    break;
                case 4:
                    return;
                default:
                    clearBuffer();
                    break;
                }
                do
                {
                    char editAgain;
                    cout << "\n\t\t\t\t\t\t\tInvalid input.";
                    cout << "\n\t\t\t\t\tDo you want to edit again? (y/n): ";
                    cin >> editAgain;

                    if (tolower(editAgain) == 'n')
                    {
                        return;
                    }
                    else if (tolower(editAgain) == 'y')
                    {
                        break;
                    }
                    else
                    {
                        cout << "\t\t\t\t\t\t\tInvalid input.";
                        clearBuffer();
                    }


                }
                while(true);


            }
            while (true);

            return;
        }
        else
        {
            userPtr = userPtr->next;
        }
    }
    cout << "\t\t\t\t\t\t\tUser not found.\n";
            cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
            _getch();
}


//void addProduct(string product_name, double product_price, int product_quantity, string classification)
//{
//    ProductNode* tempProductNode = new ProductNode;
//    tempProductNode->productName = product_name;
//    tempProductNode->price = product_price;
//    tempProductNode->quantity = product_quantity;
//    tempProductNode->productClassification = classification;
//
//    tempProductNode->productCode = generateProductCode();
//
//    tempProductNode->date = getCurrentDate();
//    tempProductNode->next = nullptr;
//
//    if (Producthead == nullptr)
//    {
//        Producthead = tempProductNode;
//    }
//    else
//    {
//        ProductNode* current = Producthead;
//        while (current->next != nullptr)
//        {
//            current = current->next;
//        }
//        current->next = tempProductNode;
//    }
//}
void addProduct(string product_name, double product_price, int product_quantity, string classification)
{
    ProductNode* tempProductNode = new ProductNode;
    tempProductNode->productName = product_name;
    tempProductNode->price = product_price;
    tempProductNode->quantity = product_quantity;
    tempProductNode->productClassification = classification;

    tempProductNode->productCode = generateProductCode();

    tempProductNode->date = getCurrentDate();
    tempProductNode->next = nullptr;

    if (Producthead == nullptr)
    {
        Producthead = tempProductNode;
    }
    else
    {
        ProductNode* current = Producthead;
        while (current != nullptr)
        {
            if (current->productName == product_name && current->productClassification == classification && current->price == product_price)
            {
                current->quantity += product_quantity;
                delete tempProductNode;
                return;
            }
            if (current->next == nullptr)
            {
                current->next = tempProductNode;
                return;
            }
            current = current->next;
        }
    }
}

void displayProducts()
{
    ProductNode* ptr = Producthead;
    int position = 0;

    if (ptr == nullptr)
    {
        cout << "\n\n\n\n\t\t\t\t\t\t\tNo products available.\n";
        cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
        _getch();
        return;
    }

    //cout << "\nProducts : \n";
    setPosxy(10,15);
    cout << right << "No." << setw(1) << "Product Name" << setw(20) << "Price" << setw(15) << "Quantity" << setw(15) << "Date" << setw(15) << "Code" << setw(20) << "Classification" << endl;
    setPosxy(10,16);
    cout << setw(11) << right << setfill('-') << setw(100) << "" << setfill(' ') << endl;

    while (ptr != nullptr)
    {
        setPosxy(10,17+position);
        cout << right << "["<<position<<"]" << setw(25) << left << ptr->productName << setw(15) << fixed << setprecision(2) << ptr->price << setw(10) << ptr->quantity
             << setw(15) << ptr->date << setw(15) << ptr->productCode << setw(20) << ptr->productClassification << endl;
        ptr = ptr->next;
        ++position;
    }
    cout << endl<<endl<<endl<<endl;
}


int prodIndex()
{
    ProductNode* ptr = Producthead;
    int position = 0;

    if (ptr == nullptr)
    {
        return -1;
    }

    while (ptr != nullptr)
    {
        ptr = ptr->next;
        ++position;
    }
    return position+5;

}
int prodex()
{
    ProductNode* ptr = Producthead;
    int position = 0;

    if (ptr == nullptr)
    {
        return -1;
    }

    while (ptr != nullptr)
    {
        ptr = ptr->next;
        ++position;
    }
    return position;

}
void editProduct()
{
    int prodIndex = prodex();
    if (prodIndex == -1)
    {
        cout << "\n\t\t\t\tNo products available for editing.\n";
        return;
    }

    ProductNode* productPtr = Producthead;
    int currentIndex = 0;

    int choice;
    cout << "\n\t\t\t\tEnter the index of the product you want to edit: ";
    cin >> choice;

    if (choice < 0 || choice >= prodIndex)
    {
        cout << "\n\t\t\t\tInvalid index. Please enter a valid index.\n";
        return;
    }

    while (productPtr != nullptr)
    {
        if (currentIndex == choice)
        {
            cout << "\n\t\t\t\tEnter new details for the product:\n";
            do
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\n\t\t\t\t Enter the product name (up to 25 characters): ";
                getline(cin, productPtr->productName);

                if (productPtr->productName.length() > 25)
                {
                    clearBuffer();
                    cout << "\n\t\t\t\tPlease enter a product name with at most 25 characters!";
                }
            }
            while (productPtr->productName.length() > 25);

            double price;
            do
            {
                cout << "\n\t\t\t\tEnter new product price: ";
                string price_str;
                cin >> price_str;

                if (isNumeric(price_str))
                {
                    double price = stod(price_str);
                    if (price >= 1.0 && price <= 1000000.0)
                    {
                        productPtr->price = price;
                        break;
                    }
                    else
                    {
                        cout << "\n\t\t\t\tInvalid input. Please enter a valid numeric value between 1 and 1 million.\n";
                        clearBuffer();
                    }
                }
                else
                {
                    cout << "\n\t\t\t\tInvalid input. Please enter a valid numeric value.\n";
                    clearBuffer();
                }
            }
            while (true);

            do
            {
                cout << "\n\t\t\t\tEnter new quantity: ";
                cin >> productPtr->quantity;

                if (productPtr->quantity > 0)
                {
                    break;
                }
                else
                {
                    cout << "\n\t\t\t\tInvalid input. Please enter a valid numeric value greater than 0.\n";
                    clearBuffer();
                }
            }
            while (true);

            cout << "\n\n\t\t\t\tChoose the new classification of the product:\n"
                 << "\t\t\t\t\t\t\t[1] Dairy\n"
                 << "\t\t\t\t\t\t\t[2] Canned Goods\n"
                 << "\t\t\t\t\t\t\t[3] Health & Beauty Care\n"
                 << "\t\t\t\t\t\t\t[4] Electronics\n"
                 << "\t\t\t\t\t\t\t[5] Other\n"
                 <<"\t\t\t\t    Enter Your Choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                productPtr->productClassification = "Dairy";
                break;
            case 2:
                productPtr->productClassification = "Canned Goods";
                break;
            case 3:
                productPtr->productClassification = "Health & Beauty Care";
                break;
            case 4:
                productPtr->productClassification = "Electronics";
                break;
            case 5:
                productPtr->productClassification = "Other";
                break;
            default:
                clearBuffer();
                break;
            }

            cout << "\n\t\t\t\tProduct updated successfully\n";
            cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
            _getch();
            return;
        }
        currentIndex++;
        productPtr = productPtr->next;
    }

    cout << "Product not found.\n";
    cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
    _getch();
}

void itemDesign(string menuType)
{
    prodIndex();
    cout << endl << endl;

    for( i = 0; i < 110; i++)
    {
        setColor(17);
        setPosxy(6,3);
        cout << "  ";
        setPosxy(6,4);
        cout << "  ";
        setPosxy(6,5);
        cout << "  ";
        setPosxy(6,6);
        cout << "  ";
        setPosxy(6,7);
        cout << "  ";
        setPosxy(6,8);
        cout << "  ";
        setPosxy(6,9);
        cout << "  ";
        setPosxy(6,10);
        cout << "  ";
        setPosxy(6,11);
        cout << "  ";
        setPosxy(6,12);
        cout << "  ";
        setPosxy(6,13);
        cout << "  ";
        setPosxy(6,14);
        cout << "  ";
        setPosxy(6,15);
        cout << "  ";
        setPosxy(6,16);
        cout << "  ";
        setPosxy(6,17);
        cout << "  ";
        setPosxy(6,18);
        cout << "  ";

        setColor(17+i);

        setPosxy(8+i, 3);
        cout <<" ";
        setPosxy(8+i,18+prodIndex());
        cout <<" ";

        setPosxy(118,3);
        cout << "  ";
        setPosxy(118,4);
        cout << "  ";
        setPosxy(118,5);
        cout << "  ";
        setPosxy(118,6);
        cout << "  ";
        setPosxy(118,7);
        cout << "  ";
        setPosxy(118,8);
        cout << "  ";
        setPosxy(118,9);
        cout << "  ";
        setPosxy(118,10);
        cout << "  ";
        setPosxy(118,11);
        cout << "  ";
        setPosxy(118,12);
        cout << "  ";
        setPosxy(118,13);
        cout << "  ";
        setPosxy(118,14);
        cout << "  ";
        setPosxy(118,15);
        cout << "  ";
        setPosxy(118,16);
        cout << "  ";
        setPosxy(118,17);
        cout << "  ";
        setPosxy(118,18);
        cout << "  ";
        Sleep(0.0001);
    }

    for(int x=0; x<=prodIndex(); x++)
    {
        setColor(17);
        setPosxy(6,18+x);
        cout << "  ";
    }


    for(int x=0; x<=prodIndex(); x++)
    {
        setColor(127);
        setPosxy(118,18+x);
        cout << "  ";
        \
    }



    for ( i = 0; i < 15; i++)
    {
        setColor(6);
        setPosxy(9+i,5);
        cout << " ";
        setPosxy(9+i,6);
        cout << " ";
        setPosxy(9+i,7);
        cout << " ";
        setPosxy(9+i,8);
        cout << " ";
        setPosxy(9+i,9);
        cout << " ";
        setPosxy(9+i,10);
        cout << " ";
        setPosxy(9+i,11);
        cout << " ";

        setPosxy(10+i,5);
        cout << " ######  ######   #####  ######  ##    ##  ######  ########   #####        " ;
        setPosxy(10+i,6);
        cout << " ##   ## ##   ## ##   ## ##   ## ##    ## ##          ##     ##   ##       " ;
        setPosxy(10+i,7);
        cout << " ##   ## ##   ## ##   ## ##   ## ##    ## ##          ##      ##           " ;
        setPosxy(10+i,8);
        cout << " ######  ######  ##   ## ##   ## ##    ## ##          ##        ##         " ;
        setPosxy(10+i,9);
        cout << " ##      ##   ## ##   ## ##   ## ##    ## ##          ##         ##        " ;
        setPosxy(10+i,10);
        cout << " ##      ##   ## ##   ## ##   ## ##    ## ##          ##     ##   ##       " ;
        setPosxy(10+i,11);
        cout << " ##      ##   ##  #####  ######   ######   ######     ##      #####        " ;

        cout << endl<<endl;
        cout<<"\t\t\t\t\t\t["<< menuType<<"]";
        cout << endl<<endl<<endl<<endl;
        Sleep(0.001);
    }
    displayProducts();
    cout << endl<<endl<<endl<<endl;
}


void addPurchase(string username, string product_name, int quantity, string modeOfPayment)
{
    TransactionNode* tempNode = new TransactionNode;
    tempNode->transactionUsername = username;
    tempNode->product_name = product_name;
    tempNode->purchased_quantity = quantity;
    tempNode->modeOfPayment = modeOfPayment;
    tempNode->next = Transactionhead;
    Transactionhead = tempNode;
}


void removeProductByIndex()
{
    int index;
    int quantity;

    cout << "\t\t\t\t    Enter the Position of Product to Reduce Stock: ";
    cin >> index;
    if (index < 0 || index >= prodex())
    {
        cout << "\t\t\t\t\t\t\tInvalid index. Please enter a valid index.\n";
        clearBuffer();
        return;
    }

    do
    {
        cout << "\t\t\t\t    Enter the Quantity to Reduce Stock: ";
        cin >> quantity;

        if (quantity > 0)
        {
            break;
        }
        else
        {
            cout << "\t\t\t\t\t\t\tInvalid input. Please enter a valid numeric value greater than 0.\n";
            clearBuffer();
        }
    }
    while (true);

    ProductNode* productPtr = Producthead;
    ProductNode* prevProductPtr = nullptr;
    int currentIndex = 0;

    while (productPtr != nullptr)
    {
        if (currentIndex == index)
        {
            if (productPtr->quantity >= quantity)
            {
                productPtr->quantity -= quantity;

                double totalPrice = quantity * productPtr->price;
                system("CLS");
                itemDesign("Remove Item");

                cout << "\n\t\t\t\t\t\tRemove successful\n"
                     << "\t\t\t\t\t------------------------\n"
                     << "\t\t\t\t\tProduct name: " << (productPtr->productName) << endl
                     << "\t\t\t\t\tQuantity purchased: " << quantity << endl
                     << "\t\t\t\t\tTotal Price of removed items: PHP" << totalPrice << endl
                     << "\t\t\t\t\t------------------------\n";
                cout << "\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
                _getch();

                if (productPtr->quantity == 0)
                {
                    if (prevProductPtr == nullptr)
                    {
                        Producthead = productPtr->next;
                    }
                    else
                    {
                        prevProductPtr->next = productPtr->next;
                    }

                    delete productPtr;
                    system("CLS");
                    itemDesign("Remove Item");
                    cout << "\t\t\t\t\The item's stock has become zero; it will automatically be removed.\n";
                }
            }
            else
            {
                cout << "\t\t\t\t\Not enough stock.\n";
            }
            return;
        }

        prevProductPtr = productPtr;
        productPtr = productPtr->next;
        currentIndex++;
    }

    cout << "\t\t\t\t\Invalid index or product not found.\n";
}
//void removeProductByIndex(int index, int quantity)
//{
//    ProductNode* productPtr = Producthead;
//    ProductNode* prevProductPtr = nullptr;
//    int currentIndex = 0;
//
//    while (productPtr != nullptr)
//    {
//        if (currentIndex == index)
//        {
//            if (productPtr->quantity >= quantity)
//            {
//                productPtr->quantity -= quantity;
//
//
//
//                double totalPrice = quantity * productPtr->price;
//                system("CLS");
//                itemDesign("Remove Item");
//
//                cout << "\n\t\t\t\t\t\tRemove successful\n"
//                     << "\t\t\t\t\t------------------------\n"
//                     << "\t\t\t\t\tProduct name: " << (productPtr->productName) << endl
//                     << "\t\t\t\t\tQuantity purchased: " << quantity << endl
//                     << "\t\t\t\t\tTotal Price of removed items: PHP" << totalPrice << endl
//                     << "\t\t\t\t\t------------------------\n";
//                     if (productPtr->quantity == 0)
//                {
//                    if (prevProductPtr == nullptr)
//                    {
//                        Producthead = productPtr->next;
//                    }
//                    else
//                    {
//                        prevProductPtr->next = productPtr->next;
//                    }
//
//                    delete productPtr;
//                system("CLS");
//                itemDesign("Remove Item");
//                cout << "\t\t\t\t\The item's stock has become zero; it will automatically be removed.\n";
//                }
//            }
//            else
//            {
//                cout << "\t\t\t\t\Not enough stock.\n";
//            }
//            return;
//        }
//
//        prevProductPtr = productPtr;
//        productPtr = productPtr->next;
//        currentIndex++;
//    }
//
//    cout << "\t\t\t\t\Invalid index or product not found.\n";
//}

//
//void addToCart(string username)
//{
//    int productPos;
//
//    do
//    {
//        cout << "\t\t\t\t    Enter the product position: ";
//        string input;
//        cin >> input;
//
//        if (isNumeric(input))
//        {
//            productPos = stoi(input);
//
//            if (productPos >= 0 && productPos < prodex())
//            {
//                break;
//            }
//            else
//            {
//                cout << "Invalid index. Please enter a valid index.\n";
//                clearBuffer();
//            }
//        }
//        else
//        {
//            cout << "\t\t\t\t\t\tInvalid input. Please enter a valid numeric value.\n";
//            clearBuffer();
//        }
//    }
//    while (true);
//
//    int quantity;
//    do
//    {
//        cout << "\t\t\t\t    Enter the quantity to purchase: ";
//        string input;
//        cin >> input;
//
//        if (isNumeric(input))
//        {
//            quantity = stoi(input);
//
//            if (quantity > 0)
//            {
//                break;
//            }
//            else
//            {
//                cout << "\t\t\t\t\t\tInvalid input. Please enter a valid numeric value greater than 0.\n";
//                clearBuffer();
//            }
//        }
//        else
//        {
//            cout << "\t\t\t\t\t\tInvalid input. Please enter a valid numeric value.\n";
//            clearBuffer();
//        }
//    }
//    while (true);
//
//    ProductNode* productPtr = Producthead;
//    int currentIndex = 0;
//
//    while (productPtr != nullptr)
//    {
//        if (currentIndex == productPos)
//        {
//            if (productPtr->quantity >= quantity)
//            {
//                ShoppingCartNode* newNode = new ShoppingCartNode;
//                newNode->userCart = username;
//                newNode->productName = productPtr->productName;
//                newNode->price = productPtr->price;
//                newNode->quantity = quantity;
//                newNode->next = ShoppingCartHead;
//                ShoppingCartHead = newNode;
//
//                cout << "\t\t\t\t    Item added to the cart.\n";
//            }
//            else
//            {
//                cout << "\t\t\t\t    Not enough stock available. Item not added to the cart.\n";
//            }
//            return;
//        }
//
//        productPtr = productPtr->next;
//        ++currentIndex;
//    }
//
//    cout << "\t\t\t\t    Invalid product index. Item not added to the cart.\n";
//}
void addToCart(string username)
{
    int productPos;

    do
    {
        cout << "\t\t\t\t    Enter the product position: ";
        string input;
        cin >> input;

        if (isNumeric(input))
        {
            productPos = stoi(input);

            if (productPos >= 0 && productPos < prodex())
            {
                break;
            }
            else
            {
                cout << "Invalid index. Please enter a valid index.\n";
                clearBuffer();
            }
        }
        else
        {
            cout << "\t\t\t\t\t\tInvalid input. Please enter a valid numeric value.\n";
            clearBuffer();
        }
    } while (true);

    int quantity;
    do
    {
        cout << "\t\t\t\t    Enter the quantity to purchase: ";
        string input;
        cin >> input;

        if (isNumeric(input))
        {
            quantity = stoi(input);

            if (quantity > 0)
            {
                break;
            }
            else
            {
                cout << "\t\t\t\t\t\tInvalid input. Please enter a valid numeric value greater than 0.\n";
                clearBuffer();
            }
        }
        else
        {
            cout << "\t\t\t\t\t\tInvalid input. Please enter a valid numeric value.\n";
            clearBuffer();
        }
    } while (true);

    ProductNode* productPtr = Producthead;
    int currentIndex = 0;

    while (productPtr != nullptr)
    {
        if (currentIndex == productPos)
        {
            ShoppingCartNode* cartPtr = ShoppingCartHead;
            while (cartPtr != nullptr)
            {
                if (cartPtr->userCart == username && cartPtr->productName == productPtr->productName)
                {
                    cartPtr->quantity += quantity;

                    cout << "\t\t\t\t    Item quantity updated in the cart.\n";
                    return;
                }
                cartPtr = cartPtr->next;
            }


            if (productPtr->quantity >= quantity)
            {
                ShoppingCartNode* newNode = new ShoppingCartNode;
                newNode->userCart = username;
                newNode->productName = productPtr->productName;
                newNode->price = productPtr->price;
                newNode->quantity = quantity;
                newNode->next = ShoppingCartHead;
                ShoppingCartHead = newNode;

                cout << "\t\t\t\t    Item added to the cart.\n";
            }
            else
            {
                cout << "\t\t\t\t    Not enough stock available. Item not added to the cart.\n";
            }
            return;
        }

        productPtr = productPtr->next;
        ++currentIndex;
    }

    cout << "\t\t\t\t    Invalid product index. Item not added to the cart.\n";
}

void displayCart(string username)
{
    ShoppingCartNode* cartPtr = ShoppingCartHead;

    if (cartPtr == nullptr)
    {
        cout << "\n\n\n\n\t\t\t\t\t\t\tYour cart is empty.\n";
        return;
    }

    cout << "\n\t\t\t\tShopping Cart for " << username << ":\n";

    cout <<"\t\t\t\t"<< setw(5) << left << "Index" << setw(20) << "Product Name" << setw(20) << "Price" << setw(10) << "Quantity" << setw(20) << "Total Price" << endl;

    cout <<"\t\t\t\t"<< setfill('-') << setw(70) << "" << setfill(' ') << endl;

    double totalCartPrice = 0.0;
    int currentIndex = 0;

    while (cartPtr != nullptr)
    {
        if (cartPtr->userCart == username)
        {
            double totalPrice = cartPtr->quantity * cartPtr->price;

            cout <<"\t\t\t\t"<< setw(5) << currentIndex << setw(20) << left << cartPtr->productName << setw(20) << fixed << setprecision(2) << cartPtr->price
                 << setw(10) << cartPtr->quantity << setw(20) << totalPrice << endl;

            totalCartPrice += totalPrice;
            currentIndex++;
        }

        cartPtr = cartPtr->next;
    }

    cout <<"\t\t\t\t"<< setfill('-') << setw(70) << "" << setfill(' ') << endl;
    cout <<"\t\t\t\t"<< setw(50) << left << "Total Cart Price:" << setw(20) << totalCartPrice << endl;
}

int displayCartIndex(string username)
{
    ShoppingCartNode* cartPtr = ShoppingCartHead;

    if (cartPtr == nullptr)
    {
        return -1;
    }

    double totalCartPrice = 0.0;
    int currentIndex = 0;

    while (cartPtr != nullptr)
    {
        if (cartPtr->userCart == username)
        {
            double totalPrice = cartPtr->quantity * cartPtr->price;

            totalCartPrice += totalPrice;
            return currentIndex++;
        }

        cartPtr = cartPtr->next;
    }

}

void itemCart(string username)
{
    system("CLS");
    cout << endl << endl;

    for( i = 0; i < 110; i++)
    {
        setColor(17);
        setPosxy(6,3);
        cout << "  ";
        setPosxy(6,4);
        cout << "  ";
        setPosxy(6,5);
        cout << "  ";
        setPosxy(6,6);
        cout << "  ";
        setPosxy(6,7);
        cout << "  ";
        setPosxy(6,8);
        cout << "  ";
        setPosxy(6,9);
        cout << "  ";
        setPosxy(6,10);
        cout << "  ";
        setPosxy(6,11);
        cout << "  ";
        setPosxy(6,12);
        cout << "  ";
        setPosxy(6,13);
        cout << "  ";
        setPosxy(6,14);
        cout << "  ";
        setPosxy(6,15);
        cout << "  ";


        setColor(17+i);

        setPosxy(8+i, 3);
        cout <<" ";
        setPosxy(8+i,15);
        cout <<" ";

        setPosxy(118,3);
        cout << "  ";
        setPosxy(118,4);
        cout << "  ";
        setPosxy(118,5);
        cout << "  ";
        setPosxy(118,6);
        cout << "  ";
        setPosxy(118,7);
        cout << "  ";
        setPosxy(118,8);
        cout << "  ";
        setPosxy(118,9);
        cout << "  ";
        setPosxy(118,10);
        cout << "  ";
        setPosxy(118,11);
        cout << "  ";
        setPosxy(118,12);
        cout << "  ";
        setPosxy(118,13);
        cout << "  ";
        setPosxy(118,14);
        cout << "  ";
        setPosxy(118,15);
        cout << "  ";

        Sleep(0.0001);
    }

    for ( i = 0; i < 35; i++)
    {
        setColor(6);
        setPosxy(9+i,5);
        cout << " ";
        setPosxy(9+i,6);
        cout << " ";
        setPosxy(9+i,7);
        cout << " ";
        setPosxy(9+i,8);
        cout << " ";
        setPosxy(9+i,9);
        cout << " ";
        setPosxy(9+i,10);
        cout << " ";
        setPosxy(9+i,11);
        cout << " ";

        setPosxy(10+i,5);
        cout << "  ######  #####  #####   ########             " ;
        setPosxy(10+i,6);
        cout << " ##      ##   ## ##   ##    ##                " ;
        setPosxy(10+i,7);
        cout << " ##      ##   ## ##   ##    ##                " ;
        setPosxy(10+i,8);
        cout << " ##      ####### #####      ##                " ;
        setPosxy(10+i,9);
        cout << " ##      ##   ## ##   ##    ##                " ;
        setPosxy(10+i,10);
        cout << " ##      ##   ## ##   ##    ##                " ;
        setPosxy(10+i,11);
        cout << "  ###### ##   ## ##   ##    ##                " ;

        cout << endl<<endl;
        cout<<"\t\t\t\t\t\t\t["<< username<<"]";
        Sleep(0.001);
        cout << endl<<endl<<endl<<endl;
    }
    displayCart(username);
    cout << endl<<endl<<endl;
}


void clearCart()
{
    ShoppingCartNode* tempPtr;

    while (ShoppingCartHead != nullptr)
    {
        tempPtr = ShoppingCartHead;
        ShoppingCartHead = ShoppingCartHead->next;
        delete tempPtr;
    }
}

void removeFromCartByIndex(string username)
{
    if (ShoppingCartHead == nullptr)
    {
        cout << "\t\t\t\tThe shopping cart is empty. Nothing to remove.\n";
        return;
    }

    ShoppingCartNode* cartPtr = ShoppingCartHead;

    itemCart(username);

    int index;
    do
    {
        cout << "\n\t\t\t\tEnter the index of the item to remove (or -1 to cancel): ";
        string input;
        cin >> input;

        if (isNumeric(input))
        {
            index = stoi(input);

            if (index == -1)
            {
                cout << "\t\t\t\tRemoval canceled.\n";
                return;
            }

            if (index >= 0)
            {
                break;
            }
            else
            {
                cout << "\t\t\t\tInvalid index. Please enter a non-negative index.\n";
                clearBuffer();
            }
        }
        else
        {
            cout << "\t\t\t\tInvalid input. Please enter a valid numeric value.\n";
            clearBuffer();
        }
    }
    while (true);

    ShoppingCartNode* previous = nullptr;
    int currentIndex = 0;

    while (cartPtr != nullptr)
    {
        if (cartPtr->userCart == username)
        {
            if (currentIndex == index)
            {
                if (previous == nullptr)
                {
                    ShoppingCartHead = cartPtr->next;
                }
                else
                {
                    previous->next = cartPtr->next;
                }

                delete cartPtr;
                cout << "\t\t\t\tItem removed from the cart.\n";
                return;
            }

            previous = cartPtr;
            cartPtr = cartPtr->next;
            currentIndex++;
        }
        else
        {
            cartPtr = cartPtr->next;
        }
    }

    cout << "\t\t\t\tItem not found in the cart.\n";
}

void displayPurchases(string username)
{
    AccountNode* userAccountPtr = Accounthead;
    while (userAccountPtr != nullptr)
    {
        if (userAccountPtr->UsernameUser == username)
        {
            break;
        }
        userAccountPtr = userAccountPtr->next;
    }

    if (userAccountPtr == nullptr)
    {
        cout << "\n\n\n\n\t\t\t\t\t\t\tUser not found.\n";
        return;
    }

    TransactionNode* userProductPtr = Transactionhead;
    double totalPurchase = 0.0;

    cout << "\n\tUser Purchases for: " << userAccountPtr->userFullname << " (" << username << ")\n";
    cout << "\tContact Number: " << userAccountPtr->userContactnumber << "\n";
    cout <<"\t"<< setw(30) << left << "Product Name" << setw(15) << "Quantity" << setw(15) << "Total Price"
         << setw(20) << "Date" << setw(20) << "Product Code" << setw(20) << "Mode of Payment" << endl;
    cout << "\t"<<setfill('-') << setw(120) << "" << setfill(' ') << endl;

    bool userFound = false;

    while (userProductPtr != nullptr)
    {
        if (userProductPtr->transactionUsername == username)
        {
            ProductNode* productPtr = Producthead;
            while (productPtr != nullptr)
            {
                if (productPtr->productName == userProductPtr->product_name)
                {
                    double productPrice = productPtr->price;
                    double purchasePrice = userProductPtr->purchased_quantity * productPrice;

                    if (userProductPtr->modeOfPayment == "Bank Transfer 5% Discount.")
                    {
                        purchasePrice = purchasePrice - (purchasePrice * 0.05);
                    }
                    else if (userProductPtr->modeOfPayment == "Cash Birthday Discount 10%.")
                    {
                        purchasePrice = purchasePrice - (purchasePrice * 0.1);
                    }

                    cout <<"\t"<< setw(30) << left << userProductPtr->product_name
                         << setw(15) << userProductPtr->purchased_quantity
                         << setw(15) << fixed << setprecision(2) << purchasePrice
                         << setw(20) << productPtr->date
                         << setw(20) << productPtr->productCode
                         << setw(20) << userProductPtr->modeOfPayment << endl;

                    totalPurchase += purchasePrice;
                    userFound = true;
                    break;
                }
                productPtr = productPtr->next;
            }
        }
        userProductPtr = userProductPtr->next;
    }

    if (!userFound)
    {
        cout << "\tNo transactions.\n";
    }

    cout <<"\t"<< setfill('-') << setw(120) << "" << setfill(' ') << endl;

    if (userFound)
    {
        cout <<"\t"<< setw(95) << left << "Total Purchase Amount:"
             << setw(25) << fixed << setprecision(2) << totalPurchase << endl;
    }

    cout << endl;
}

void displayUserPurchases(string username)
{
    AccountNode* userAccountPtr = Accounthead;
    while (userAccountPtr != nullptr)
    {
        if (userAccountPtr->UsernameUser == username)
        {
            break;
        }
        userAccountPtr = userAccountPtr->next;
    }

    if (userAccountPtr == nullptr)
    {
        setPosxy(12,19);
        cout << "\t\t\t\t\t\t\tUser not found.\n";
        cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
        _getch();
        return;
    }

    TransactionNode* userProductPtr = Transactionhead;
    double totalPurchase = 0.0;
    int counter=0;
    setPosxy(12,15);
    cout << "User Purchases for: " << userAccountPtr->userFullname << " (" << username << ")\n";
    setPosxy(12,16);
    cout << "Contact Number: " << userAccountPtr->userContactnumber << "\n";
    setPosxy(12,17);
    cout << setw(20) << left << "Product Name" << setw(15) << "Quantity" << setw(15) << "Total Price"
         << setw(15) << "Date" << setw(15) << "Product Code" << setw(15) << "Mode of Payment" << endl;
    setPosxy(12,18);
    cout << setfill('-') << setw(100) << "" << setfill(' ') << endl;

    bool userFound = false;

    while (userProductPtr != nullptr)
    {
        if (userProductPtr->transactionUsername == username)
        {
            ProductNode* productPtr = Producthead;
            while (productPtr != nullptr)
            {
                if (productPtr->productName == userProductPtr->product_name)
                {
                    double productPrice = productPtr->price;
                    double purchasePrice = userProductPtr->purchased_quantity * productPrice;

                    if (userProductPtr->modeOfPayment == "Bank Transfer 5% Discount.")
                    {
                        purchasePrice = purchasePrice - (purchasePrice * 0.05);
                    }
                    else if (userProductPtr->modeOfPayment == "Cash Birthday Discount 10%.")
                    {
                        purchasePrice = purchasePrice - (purchasePrice * 0.1);
                    }
                    setPosxy(12,19+counter);
                    cout << setw(20) << left << userProductPtr->product_name
                         << setw(15) << userProductPtr->purchased_quantity
                         << setw(15) << fixed << setprecision(2) << purchasePrice
                         << setw(15) << productPtr->date
                         << setw(15) << productPtr->productCode
                         << setw(15) << userProductPtr->modeOfPayment << endl;
                    ++counter;
                    totalPurchase += purchasePrice;
                    userFound = true;
                    break;
                }
                productPtr = productPtr->next;
            }
        }
        userProductPtr = userProductPtr->next;
    }

    if (!userFound)
    {
        setPosxy(12,19);
        cout << "No transactions.";
        cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
        _getch();
    }
    setPosxy(12,20+counter);
    cout << setfill('-') << setw(100) << "" << setfill(' ') << endl;

    if (userFound)
    {
        setPosxy(12,21+counter);
        cout << setw(50) << left << "Total Purchase Amount:"
             << setw(25) << fixed << setprecision(2) << totalPurchase << endl;
        cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
        _getch();
    }

    cout << endl;
}

void buyProductBirthdayDiscount(string username, string product_name, int quantity, double& totalPurchase)
{
    ProductNode* productPtr = Producthead;

    while (productPtr != nullptr)
    {
        if (productPtr->productName == product_name)
        {
            if (productPtr->quantity >= quantity)
            {
                productPtr->quantity -= quantity;
                string productCode = productPtr->productCode;

                addPurchase(username, product_name, quantity, "Cash Birthday Discount 10%.");

                double totalPrice = quantity * productPtr->price;
                totalPurchase += totalPrice;
                cout << setw(30) << left << productPtr->productName
                     << setw(15) << quantity
                     << setw(15) << fixed << setprecision(2) << (totalPrice = totalPrice - (totalPrice * 0.1))
                     << setw(20) << getCurrentDate()
                     << setw(20) << productCode << endl;
            }
            else
            {
                cout << "Not enough stock available.\n";
            }
            return;
        }
        productPtr = productPtr->next;
    }

    cout << "Product not found.\n";
}


int displayUserPurchasesIndex(string username)
{
    TransactionNode* userProductPtr = Transactionhead;
    int counter = 0;

    while (userProductPtr != nullptr)
    {
        if (userProductPtr->transactionUsername == username)
        {
            ProductNode* productPtr = Producthead;
            while (productPtr != nullptr)
            {
                if (productPtr->productName == userProductPtr->product_name)
                {
                    ++counter;
                }
                productPtr = productPtr->next;
            }
        }
        userProductPtr = userProductPtr->next;
    }

    return counter+10;
}

void designUserPurchase(string username)
{
    system("CLS");
    displayUserPurchasesIndex(username);
    cout << endl << endl;

    for( i = 0; i < 110; i++)
    {
        setColor(17);
        setPosxy(6,3);
        cout << "  ";
        setPosxy(6,4);
        cout << "  ";
        setPosxy(6,5);
        cout << "  ";
        setPosxy(6,6);
        cout << "  ";
        setPosxy(6,7);
        cout << "  ";
        setPosxy(6,8);
        cout << "  ";
        setPosxy(6,9);
        cout << "  ";
        setPosxy(6,10);
        cout << "  ";
        setPosxy(6,11);
        cout << "  ";
        setPosxy(6,12);
        cout << "  ";
        setPosxy(6,13);
        cout << "  ";
        setPosxy(6,14);
        cout << "  ";
        setPosxy(6,15);
        cout << "  ";
        setPosxy(6,16);
        cout << "  ";
        setPosxy(6,17);
        cout << "  ";
        setPosxy(6,18);
        cout << "  ";

        setColor(17+i);

        setPosxy(8+i, 3);
        cout <<" ";
        setPosxy(8+i,18+displayUserPurchasesIndex(username));
        cout <<" ";

        setPosxy(118,3);
        cout << "  ";
        setPosxy(118,4);
        cout << "  ";
        setPosxy(118,5);
        cout << "  ";
        setPosxy(118,6);
        cout << "  ";
        setPosxy(118,7);
        cout << "  ";
        setPosxy(118,8);
        cout << "  ";
        setPosxy(118,9);
        cout << "  ";
        setPosxy(118,10);
        cout << "  ";
        setPosxy(118,11);
        cout << "  ";
        setPosxy(118,12);
        cout << "  ";
        setPosxy(118,13);
        cout << "  ";
        setPosxy(118,14);
        cout << "  ";
        setPosxy(118,15);
        cout << "  ";
        setPosxy(118,16);
        cout << "  ";
        setPosxy(118,17);
        cout << "  ";
        setPosxy(118,18);
        cout << "  ";
        Sleep(0.0001);
    }

    for(int x=0; x<=displayUserPurchasesIndex(username); x++)
    {
        setColor(17);
        setPosxy(6,18+x);
        cout << "  ";
    }


    for(int x=0; x<=displayUserPurchasesIndex(username); x++)
    {
        setColor(127);
        setPosxy(118,18+x);
        cout << "  ";
    }



    for ( i = 0; i < 2; i++)
    {
        setColor(6);
        setPosxy(9+i,5);
        cout << " ";
        setPosxy(9+i,6);
        cout << " ";
        setPosxy(9+i,7);
        cout << " ";
        setPosxy(9+i,8);
        cout << " ";
        setPosxy(9+i,9);
        cout << " ";
        setPosxy(9+i,10);
        cout << " ";
        setPosxy(9+i,11);
        cout << " ";

        setPosxy(10+i,5);
        cout << " ######## #####    ###   ###     ##   ####    ##     ##### ########  ########   ####    ###     ##     " ;
        setPosxy(10+i,6);
        cout << "    ##    ##  ##  ## ##  ####    ##  ##  ##  ## ##  ##        ##        ##    ##    ##  ####    ##     " ;
        setPosxy(10+i,7);
        cout << "    ##    ##  ## ##   ## ## ##   ##   ##    ##   ## ##        ##        ##    ##    ##  ## ##   ##     " ;
        setPosxy(10+i,8);
        cout << "    ##    #####  ####### ##  ##  ##    ##   ####### ##        ##        ##    ##    ##  ##  ##  ##     " ;
        setPosxy(10+i,9);
        cout << "    ##    ##  ## ##   ## ##   ## ##     ##  ##   ## ##        ##        ##    ##    ##  ##   ## ##     " ;
        setPosxy(10+i,10);
        cout << "    ##    ##  ## ##   ## ##    ####  ##  ## ##   ## ##        ##        ##    ##    ##  ##    ####     " ;
        setPosxy(10+i,11);
        cout << "    ##    ##  ## ##   ## ##     ###   ####  ##   ##  #####    ##     ########   ####    ##     ###     " ;

        cout << endl<<endl;
        cout << endl<<endl<<endl<<endl;
        Sleep(0.001);
    }
    displayUserPurchases(username);
    cout << endl<<endl<<endl<<endl;
}


void saveQrCodeImage(const qrcodegen::QrCode& qr, const string& filename, int scale)
{
    int enlargedSize = qr.getSize() * scale;

    vector<unsigned char> image;
    image.reserve(enlargedSize * enlargedSize * 4); // RGBA channels

    // Convert QR code to enlarged image data
    for (int y = 0; y < qr.getSize(); ++y)
    {
        for (int yi = 0; yi < scale; ++yi)
        {
            for (int x = 0; x < qr.getSize(); ++x)
            {
                unsigned char color = qr.getModule(x, y) ? 0 : 255;
                for (int xi = 0; xi < scale; ++xi)
                {
                    image.push_back(color); // R
                    image.push_back(color); // G
                    image.push_back(color); // B
                    image.push_back(255);   // A (alpha channel)
                }
            }
        }
    }

    // Save enlarged image as PNG
    if (lodepng::encode(filename, image, enlargedSize, enlargedSize) == 0)
    {
        cout << "QR code containing purchase details saved to " << filename << endl;
    }
    else
    {
        cerr << "\nError saving QR code image." << endl;
    }
}



void buyAllFromCartBirthdayDiscount(string username)
{
    double totalPurchase = 0.0;
    int position = 0;

    ShoppingCartNode* cartPtr = ShoppingCartHead;
    setPosxy(13,14);
    cout << "Store: GIZMO STORE";
    setPosxy(13,15);
    cout << "Address: Malolos, Bulacan";
    string referenceId = generateProductCode();
    setPosxy(13,16);
    cout << "Transaction Date : "<<getCurrentDate();
    setPosxy(13,17);
    cout << "Reference ID: " << referenceId;
    setPosxy(13,18);
    cout << "Sold to : "<<username;
    setPosxy(13,19);
    cout << setfill('=') << setw(100) << "" << setfill(' ') << endl;
    setPosxy(13,20);
    cout << setw(30) << left << "Product Name" << setw(15) << "Quantity" << setw(15) << "Total Price" << setw(20) << "Date" << setw(20) << "Product Code" << endl;
    setPosxy(13,21);
    cout << setfill('=') << setw(100) << "" << setfill(' ') << endl;

    stringstream purchaseDetails;

    while (cartPtr != nullptr)
    {
        setPosxy(13,22+position);
        buyProductBirthdayDiscount(username, cartPtr->productName, cartPtr->quantity, totalPurchase);
        double totalPrice = cartPtr->quantity * cartPtr->price;

        purchaseDetails << getCurrentDate() << " | "
                        << "Reference ID: " << referenceId << " | "
                        << "Mode of Payment : Cash Birthday Discount 10%."<<" | "
                        << "Customer : " <<username <<" | "
                        << "Product Name: " << cartPtr->productName << " | "
                        << "Quantity: " << cartPtr->quantity << " | "
                        << "Total Price: PHP" << fixed << setprecision(2) << (totalPrice-(totalPrice*0.1))<< "\n";

        ShoppingCartNode* tempPtr = cartPtr;
        cartPtr = cartPtr->next;
        ++position;
        delete tempPtr;
    }

    ShoppingCartHead = nullptr;
    setPosxy(13,24+position);
    cout << setfill('-') << setw(100) << "" << setfill(' ') << endl;
    setPosxy(13,25+position);
    cout << "Total Purchase Amount: PHP\t\t\t" << fixed << setprecision(2) << (totalPurchase-(totalPurchase*0.1))<< endl;
    setPosxy(13,26+position);
    cout << "Mode of Payment : Cash Birthday Discount 10%.        Save Ammount :" << (totalPurchase*0.1);
    purchaseDetails << "\nTotal Amount: " << (totalPurchase-(totalPurchase*0.1)) << "\n";
    string purchaseDetailsStr = purchaseDetails.str();
    const char* text = purchaseDetailsStr.c_str();
    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text, qrcodegen::QrCode::Ecc::LOW);
    setPosxy(13,27+position);
    string file = "qrcode" + username +".png";
    saveQrCodeImage(qr, file, 5);
    openImageInViewer(file);
    setPosxy(13,28+position);
    cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
    _getch();

}



int buyAllFromCartIndexBirthdayDiscount()
{
    ShoppingCartNode* cartPtr = ShoppingCartHead;
    int position = 0;

    while (cartPtr != nullptr)
    {
        cartPtr = cartPtr->next;
        ++position;
    }

    return position+10;
}

void ReceiptBirthdayDiscount(string username)
{
    system("CLS");
    buyAllFromCartIndexBirthdayDiscount();
    cout << endl << endl;

    for( i = 0; i < 110; i++)
    {
        setColor(17);
        setPosxy(6,3);
        cout << "  ";
        setPosxy(6,4);
        cout << "  ";
        setPosxy(6,5);
        cout << "  ";
        setPosxy(6,6);
        cout << "  ";
        setPosxy(6,7);
        cout << "  ";
        setPosxy(6,8);
        cout << "  ";
        setPosxy(6,9);
        cout << "  ";
        setPosxy(6,10);
        cout << "  ";
        setPosxy(6,11);
        cout << "  ";
        setPosxy(6,12);
        cout << "  ";
        setPosxy(6,13);
        cout << "  ";
        setPosxy(6,14);
        cout << "  ";
        setPosxy(6,15);
        cout << "  ";
        setPosxy(6,16);
        cout << "  ";
        setPosxy(6,17);
        cout << "  ";
        setPosxy(6,18);
        cout << "  ";
        setPosxy(6,19);
        cout << "  ";
        setPosxy(6,20);
        cout << "  ";

        setColor(17+i);

        setPosxy(8+i, 3);
        cout <<" ";
        setPosxy(8+i,20+buyAllFromCartIndexBirthdayDiscount());
        cout <<" ";

        setPosxy(118,3);
        cout << "  ";
        setPosxy(118,4);
        cout << "  ";
        setPosxy(118,5);
        cout << "  ";
        setPosxy(118,6);
        cout << "  ";
        setPosxy(118,7);
        cout << "  ";
        setPosxy(118,8);
        cout << "  ";
        setPosxy(118,9);
        cout << "  ";
        setPosxy(118,10);
        cout << "  ";
        setPosxy(118,11);
        cout << "  ";
        setPosxy(118,12);
        cout << "  ";
        setPosxy(118,13);
        cout << "  ";
        setPosxy(118,14);
        cout << "  ";
        setPosxy(118,15);
        cout << "  ";
        setPosxy(118,16);
        cout << "  ";
        setPosxy(118,17);
        cout << "  ";
        setPosxy(118,18);
        cout << "  ";
        setPosxy(118,19);
        cout << "  ";
        setPosxy(118,20);
        cout << "  ";
        Sleep(0.0001);
    }

    for(int x=0; x<=buyAllFromCartIndexBirthdayDiscount(); x++)
    {
        setColor(17);
        setPosxy(6,20+x);
        cout << "  ";
        setPosxy(6,20+x);
        cout << "  ";
    }


    for(int x=0; x<=buyAllFromCartIndexBirthdayDiscount(); x++)
    {
        setColor(127);
        setPosxy(118,20+x);
        cout << "  ";
        setPosxy(118,20+x);
        cout << "  ";
    }



    for ( i = 0; i < 30; i++)
    {
        setColor(6);
        setPosxy(9+i,5);
        cout << " ";
        setPosxy(9+i,6);
        cout << " ";
        setPosxy(9+i,7);
        cout << " ";
        setPosxy(9+i,8);
        cout << " ";
        setPosxy(9+i,9);
        cout << " ";
        setPosxy(9+i,10);
        cout << " ";
        setPosxy(9+i,11);
        cout << " ";

        setPosxy(10+i,5);
        cout << "   ######  ######  #####  ######  ###### #####   ########            " ;
        setPosxy(10+i,6);
        cout << "   ##   ## ##     ##      ##        ##   ##   ##    ##               " ;
        setPosxy(10+i,7);
        cout << "   ##   ## ##     ##      #####     ##   ##   ##    ##               " ;
        setPosxy(10+i,8);
        cout << "   ######  #####  ##      ##        ##   #####      ##               " ;
        setPosxy(10+i,9);
        cout << "   ##   ## ##     ##      ##        ##   ##         ##               " ;
        setPosxy(10+i,10);
        cout << "   ##   ## ##     ##      ##        ##   ##         ##               " ;
        setPosxy(10+i,11);
        cout << "   ##   ## ######  #####  ######  ###### ##         ##               " ;

        cout << endl<<endl;
        Sleep(0.001);
    }
    buyAllFromCartBirthdayDiscount(username);
}


void buyProductDiscounted(string username, string product_name, int quantity, double& totalPurchase)
{
    ProductNode* productPtr = Producthead;

    while (productPtr != nullptr)
    {
        if (productPtr->productName == product_name)
        {
            if (productPtr->quantity >= quantity)
            {
                productPtr->quantity -= quantity;
                string productCode = productPtr->productCode;

                addPurchase(username, product_name, quantity, "Bank Transfer 5% Discount.");

                double totalPrice = quantity * productPtr->price;
                totalPurchase += totalPrice;
                cout << setw(30) << left << productPtr->productName
                     << setw(15) << quantity
                     << setw(15) << fixed << setprecision(2) << (totalPrice = totalPrice - (totalPrice * 0.05))
                     << setw(20) << getCurrentDate()
                     << setw(20) << productCode << endl;
            }
            else
            {
                cout << "Not enough stock available.\n";
            }
            return;
        }
        productPtr = productPtr->next;
    }

    cout << "Product not found.\n";
}

void buyAllFromCartDiscounted(string username)
{
    double totalPurchase = 0.0;
    int position = 0;

    ShoppingCartNode* cartPtr = ShoppingCartHead;
    setPosxy(13,14);
    cout << "Store: GIZMO STORE";
    setPosxy(13,15);
    cout << "Address: Malolos, Bulacan";
    string referenceId = generateProductCode();
    setPosxy(13,16);
    cout << "Transaction Date : "<<getCurrentDate();
    setPosxy(13,17);
    cout << "Reference ID: " << referenceId;
    setPosxy(13,18);
    cout << "Sold to : "<<username;
    setPosxy(13,19);
    cout << setfill('=') << setw(100) << "" << setfill(' ') << endl;
    setPosxy(13,20);
    cout << setw(30) << left << "Product Name" << setw(15) << "Quantity" << setw(15) << "Total Price" << setw(20) << "Date" << setw(20) << "Product Code" << endl;
    setPosxy(13,21);
    cout << setfill('=') << setw(100) << "" << setfill(' ') << endl;

    stringstream purchaseDetails;

    while (cartPtr != nullptr)
    {
        setPosxy(13,22+position);
        buyProductDiscounted(username, cartPtr->productName, cartPtr->quantity, totalPurchase);
        double totalPrice = cartPtr->quantity * cartPtr->price;

        purchaseDetails << getCurrentDate() << " | "
                        << "Reference ID: " << referenceId << " | "
                        << "Mode of Payment : Bank Transfer 5% Discount."<<" | "
                        << "Customer : " <<username <<" | "
                        << "Product Name: " << cartPtr->productName << " | "
                        << "Quantity: " << cartPtr->quantity << " | "
                        << "Total Price: PHP" << fixed << setprecision(2) << (totalPrice-(totalPrice*0.05))<< "\n";

        ShoppingCartNode* tempPtr = cartPtr;
        cartPtr = cartPtr->next;
        ++position;
        delete tempPtr;
    }

    ShoppingCartHead = nullptr;
    setPosxy(13,24+position);
    cout << setfill('-') << setw(100) << "" << setfill(' ') << endl;
    setPosxy(13,25+position);
    cout << "Total Purchase Amount: PHP\t\t\t" << fixed << setprecision(2) << (totalPurchase-(totalPurchase*0.05))<< endl;
    setPosxy(13,26+position);
    cout << "Mode of Payment : Bank Transfer 5% Discount.        Save Ammount :" <<(totalPurchase*0.05) ;
    purchaseDetails << "\nTotal Amount: " << (totalPurchase-(totalPurchase*0.05)) << "\n";
    string purchaseDetailsStr = purchaseDetails.str();
    const char* text = purchaseDetailsStr.c_str();
    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text, qrcodegen::QrCode::Ecc::LOW);
    setPosxy(13,27+position);
    string file = "qrcode" + username +".png";
    saveQrCodeImage(qr, file, 5);
    openImageInViewer(file);
    setPosxy(13,28+position);
    cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
    _getch();

}




bool isUserBirthday(string username)
{
    AccountNode* userPtr = Accounthead;
    while (userPtr != nullptr)
    {
        if (userPtr->UsernameUser == username)
        {
            time_t now = time(0);
            tm* currentDate = localtime(&now);
            stringstream ss(userPtr->birthDate.substr(4));
            tm birthDate = {};
            ss >> birthDate.tm_year >> birthDate.tm_mon >> birthDate.tm_mday;

            stringstream birthDateSS;
            birthDateSS << userPtr->birthDate.substr(4);

            stringstream currentDateStringSS;
            currentDateStringSS << "-" << setfill('0') << currentDate->tm_mon + 1 << "-" << setw(2) << setfill('0') << currentDate->tm_mday;

            if (birthDateSS.str() == currentDateStringSS.str())
            {
                cout << "\t\t\t\t\t\tHappy Birthday, " << username << "!\n";
                return true;
            }
            else
            {
                return false;
            }
        }
        userPtr = userPtr->next;
    }

    cout << "\t\t\t\t\t\t\tUser not found.\n";


    return false;
}



int buyAllFromCartIndexDiscounted()
{
    ShoppingCartNode* cartPtr = ShoppingCartHead;
    int position = 0;

    while (cartPtr != nullptr)
    {
        cartPtr = cartPtr->next;
        ++position;
    }

    return position+10;
}

void ReceiptDiscounted(string username)
{
    system("CLS");
    buyAllFromCartIndexDiscounted();
    cout << endl << endl;

    for( i = 0; i < 110; i++)
    {
        setColor(17);
        setPosxy(6,3);
        cout << "  ";
        setPosxy(6,4);
        cout << "  ";
        setPosxy(6,5);
        cout << "  ";
        setPosxy(6,6);
        cout << "  ";
        setPosxy(6,7);
        cout << "  ";
        setPosxy(6,8);
        cout << "  ";
        setPosxy(6,9);
        cout << "  ";
        setPosxy(6,10);
        cout << "  ";
        setPosxy(6,11);
        cout << "  ";
        setPosxy(6,12);
        cout << "  ";
        setPosxy(6,13);
        cout << "  ";
        setPosxy(6,14);
        cout << "  ";
        setPosxy(6,15);
        cout << "  ";
        setPosxy(6,16);
        cout << "  ";
        setPosxy(6,17);
        cout << "  ";
        setPosxy(6,18);
        cout << "  ";
        setPosxy(6,19);
        cout << "  ";
        setPosxy(6,20);
        cout << "  ";

        setColor(17+i);

        setPosxy(8+i, 3);
        cout <<" ";
        setPosxy(8+i,20+buyAllFromCartIndexDiscounted());
        cout <<" ";

        setPosxy(118,3);
        cout << "  ";
        setPosxy(118,4);
        cout << "  ";
        setPosxy(118,5);
        cout << "  ";
        setPosxy(118,6);
        cout << "  ";
        setPosxy(118,7);
        cout << "  ";
        setPosxy(118,8);
        cout << "  ";
        setPosxy(118,9);
        cout << "  ";
        setPosxy(118,10);
        cout << "  ";
        setPosxy(118,11);
        cout << "  ";
        setPosxy(118,12);
        cout << "  ";
        setPosxy(118,13);
        cout << "  ";
        setPosxy(118,14);
        cout << "  ";
        setPosxy(118,15);
        cout << "  ";
        setPosxy(118,16);
        cout << "  ";
        setPosxy(118,17);
        cout << "  ";
        setPosxy(118,18);
        cout << "  ";
        setPosxy(118,19);
        cout << "  ";
        setPosxy(118,20);
        cout << "  ";
        Sleep(0.0001);
    }

    for(int x=0; x<=buyAllFromCartIndexDiscounted(); x++)
    {
        setColor(17);
        setPosxy(6,20+x);
        cout << "  ";
        setPosxy(6,20+x);
        cout << "  ";
    }


    for(int x=0; x<=buyAllFromCartIndexDiscounted(); x++)
    {
        setColor(127);
        setPosxy(118,20+x);
        cout << "  ";
        setPosxy(118,20+x);
        cout << "  ";
    }



    for ( i = 0; i < 30; i++)
    {
        setColor(6);
        setPosxy(9+i,5);
        cout << " ";
        setPosxy(9+i,6);
        cout << " ";
        setPosxy(9+i,7);
        cout << " ";
        setPosxy(9+i,8);
        cout << " ";
        setPosxy(9+i,9);
        cout << " ";
        setPosxy(9+i,10);
        cout << " ";
        setPosxy(9+i,11);
        cout << " ";

        setPosxy(10+i,5);
        cout << "   ######  ######  #####  ######  ###### #####   ########            " ;
        setPosxy(10+i,6);
        cout << "   ##   ## ##     ##      ##        ##   ##   ##    ##               " ;
        setPosxy(10+i,7);
        cout << "   ##   ## ##     ##      #####     ##   ##   ##    ##               " ;
        setPosxy(10+i,8);
        cout << "   ######  #####  ##      ##        ##   #####      ##               " ;
        setPosxy(10+i,9);
        cout << "   ##   ## ##     ##      ##        ##   ##         ##               " ;
        setPosxy(10+i,10);
        cout << "   ##   ## ##     ##      ##        ##   ##         ##               " ;
        setPosxy(10+i,11);
        cout << "   ##   ## ######  #####  ######  ###### ##         ##               " ;

        cout << endl<<endl;
        Sleep(0.001);
    }
    buyAllFromCartDiscounted(username);
}

void buyProduct(string username, string product_name, int quantity, double& totalPurchase)
{
    ProductNode* productPtr = Producthead;

    while (productPtr != nullptr)
    {
        if (productPtr->productName == product_name)
        {
            if (productPtr->quantity >= quantity)
            {
                productPtr->quantity -= quantity;
                string productCode = productPtr->productCode;

                addPurchase(username, product_name, quantity, "Cash");
                double totalPrice = quantity * productPtr->price;
                totalPurchase += totalPrice;

                cout << setw(30) << left << productPtr->productName
                     << setw(15) << quantity
                     << setw(15) << fixed << setprecision(2) << totalPrice
                     << setw(20) << getCurrentDate()
                     << setw(20) << productCode << endl;


            }
            else
            {
                cout << "\n\t\t\t\t\t\tNot enough stock available.\n";
                cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
                _getch();
            }
            return;
        }
        productPtr = productPtr->next;
    }

    cout << "\n\t\t\t\t\t\tProduct not found.\n";
    cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
    _getch();
}


void buyAllFromCart(string username)
{
    double totalPurchase = 0.0;
    int position = 0;

    ShoppingCartNode* cartPtr = ShoppingCartHead;
    setPosxy(13,14);
    cout << "Store: GIZMO STORE";
    setPosxy(13,15);
    cout << "Address: Malolos, Bulacan";
    string referenceId = generateProductCode();
    setPosxy(13,16);
    cout << "Transaction Date : "<<getCurrentDate();
    setPosxy(13,17);
    cout << "Reference ID: " << referenceId;
    setPosxy(13,18);
    cout << "Sold to : "<<username;
    setPosxy(13,19);
    cout << setfill('=') << setw(100) << "" << setfill(' ') << endl;
    setPosxy(13,20);
    cout << setw(30) << left << "Product Name" << setw(15) << "Quantity" << setw(15) << "Total Price" << setw(20) << "Date" << setw(20) << "Product Code" << endl;
    setPosxy(13,21);
    cout << setfill('=') << setw(100) << "" << setfill(' ') << endl;

    stringstream purchaseDetails;

    while (cartPtr != nullptr)
    {
        setPosxy(13,22+position);
        buyProduct(username, cartPtr->productName, cartPtr->quantity, totalPurchase);
        double totalPrice = cartPtr->quantity * cartPtr->price;

        purchaseDetails << getCurrentDate() << " | "
                        << "Reference ID: " << referenceId << " | "
                        << "Mode of Payment : Cash."<<" | "
                        << "Customer : " <<username <<" | "
                        << "Product Name: " << cartPtr->productName << " | "
                        << "Quantity: " << cartPtr->quantity << " | "
                        << "Total Price: PHP" << fixed << setprecision(2) << totalPrice<< "\n";

        ShoppingCartNode* tempPtr = cartPtr;
        cartPtr = cartPtr->next;
        ++position;
        delete tempPtr;
    }

    ShoppingCartHead = nullptr;
    setPosxy(13,24+position);
    cout << setfill('-') << setw(100) << "" << setfill(' ') << endl;
    setPosxy(13,25+position);
    cout << "Total Purchase Amount: PHP\t\t\t" << fixed << setprecision(2) << totalPurchase<< endl;
    setPosxy(13,26+position);
    cout << "Mode of Payment : Cash";
    purchaseDetails << "\nTotal Amount: " << totalPurchase << "\n";
    string purchaseDetailsStr = purchaseDetails.str();
    const char* text = purchaseDetailsStr.c_str();
    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text, qrcodegen::QrCode::Ecc::LOW);
    setPosxy(13,27+position);
    string file = "qrcode" + username +".png";
    saveQrCodeImage(qr, file, 5);
    openImageInViewer(file);
    setPosxy(13,28+position);
    cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
    _getch();

}


int buyAllFromCartIndex()
{
    ShoppingCartNode* cartPtr = ShoppingCartHead;
    int position = 0;

    while (cartPtr != nullptr)
    {
        cartPtr = cartPtr->next;
        ++position;
    }

    return position+10;
}

void Receipt(string username)
{
    system("CLS");
    buyAllFromCartIndex();
    cout << endl << endl;

    for( i = 0; i < 110; i++)
    {
        setColor(17);
        setPosxy(6,3);
        cout << "  ";
        setPosxy(6,4);
        cout << "  ";
        setPosxy(6,5);
        cout << "  ";
        setPosxy(6,6);
        cout << "  ";
        setPosxy(6,7);
        cout << "  ";
        setPosxy(6,8);
        cout << "  ";
        setPosxy(6,9);
        cout << "  ";
        setPosxy(6,10);
        cout << "  ";
        setPosxy(6,11);
        cout << "  ";
        setPosxy(6,12);
        cout << "  ";
        setPosxy(6,13);
        cout << "  ";
        setPosxy(6,14);
        cout << "  ";
        setPosxy(6,15);
        cout << "  ";
        setPosxy(6,16);
        cout << "  ";
        setPosxy(6,17);
        cout << "  ";
        setPosxy(6,18);
        cout << "  ";
        setPosxy(6,19);
        cout << "  ";
        setPosxy(6,20);
        cout << "  ";

        setColor(17+i);

        setPosxy(8+i, 3);
        cout <<" ";
        setPosxy(8+i,20+buyAllFromCartIndex());
        cout <<" ";

        setPosxy(118,3);
        cout << "  ";
        setPosxy(118,4);
        cout << "  ";
        setPosxy(118,5);
        cout << "  ";
        setPosxy(118,6);
        cout << "  ";
        setPosxy(118,7);
        cout << "  ";
        setPosxy(118,8);
        cout << "  ";
        setPosxy(118,9);
        cout << "  ";
        setPosxy(118,10);
        cout << "  ";
        setPosxy(118,11);
        cout << "  ";
        setPosxy(118,12);
        cout << "  ";
        setPosxy(118,13);
        cout << "  ";
        setPosxy(118,14);
        cout << "  ";
        setPosxy(118,15);
        cout << "  ";
        setPosxy(118,16);
        cout << "  ";
        setPosxy(118,17);
        cout << "  ";
        setPosxy(118,18);
        cout << "  ";
        setPosxy(118,19);
        cout << "  ";
        setPosxy(118,20);
        cout << "  ";
        Sleep(0.0001);
    }

    for(int x=0; x<=buyAllFromCartIndex(); x++)
    {
        setColor(17);
        setPosxy(6,20+x);
        cout << "  ";
        setPosxy(6,20+x);
        cout << "  ";
    }


    for(int x=0; x<=buyAllFromCartIndex(); x++)
    {
        setColor(127);
        setPosxy(118,20+x);
        cout << "  ";
        setPosxy(118,20+x);
        cout << "  ";
    }



    for ( i = 0; i < 30; i++)
    {
        setColor(6);
        setPosxy(9+i,5);
        cout << " ";
        setPosxy(9+i,6);
        cout << " ";
        setPosxy(9+i,7);
        cout << " ";
        setPosxy(9+i,8);
        cout << " ";
        setPosxy(9+i,9);
        cout << " ";
        setPosxy(9+i,10);
        cout << " ";
        setPosxy(9+i,11);
        cout << " ";

        setPosxy(10+i,5);
        cout << "   ######  ######  #####  ######  ###### #####   ########            " ;
        setPosxy(10+i,6);
        cout << "   ##   ## ##     ##      ##        ##   ##   ##    ##               " ;
        setPosxy(10+i,7);
        cout << "   ##   ## ##     ##      #####     ##   ##   ##    ##               " ;
        setPosxy(10+i,8);
        cout << "   ######  #####  ##      ##        ##   #####      ##               " ;
        setPosxy(10+i,9);
        cout << "   ##   ## ##     ##      ##        ##   ##         ##               " ;
        setPosxy(10+i,10);
        cout << "   ##   ## ##     ##      ##        ##   ##         ##               " ;
        setPosxy(10+i,11);
        cout << "   ##   ## ######  #####  ######  ###### ##         ##               " ;

        cout << endl<<endl;
        Sleep(0.001);
    }
    buyAllFromCart(username);
}







bool loginUser(string username, string password)
{
    AccountNode* ptr = Accounthead;

    while (ptr != nullptr)
    {
        if (ptr->UsernameUser == username  &&  ptr->PasswordUser == password)
        {
            cout << "\n\t\t\t\t\t\t\tLogin successful.\n";
            cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
            _getch();
            return true;
        }
        ptr = ptr->next;
    }

    cout << "\n\t\t\t\t\t\tLogin failed. Invalid username or password.\n";
    cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
    _getch();
    return false;
}

bool loginAdmin(string username, string password)
{
    AccountNode* ptr = Accounthead;

    while (ptr != nullptr)
    {
        if (ptr->UsernameAdmin == username  &&  ptr->PasswordAdmin == password)
        {
            cout << "\n\t\t\t\t\t\t\tLogin successful.\n";
            cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
            _getch();
            return true;
        }
        ptr = ptr->next;
    }

    cout << "\n\t\t\t\t\t\tLogin failed. Invalid username or password.\n";
    cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
    _getch();
    return false;
}

void createAdminAccount()
{
    system("CLS");
    otherPage("Create Admin Account");
    string specialCode;
    cout << "\n\t\t\t\t\t\t\tEnter Special Key: ";
    cin >> specialCode;

    if (specialCode != special_key)
    {
        cout << "\n\t\t\t\t\t\t\tInvalid Special Key. Access Denied.\n";
        cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
        _getch();
        return;
    }

    string username, password;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "\n\t\t\t\t\t\t\tEnter Username: ";
    getline(cin, username);
    cin.clear();
    cout << "\n\t\t\t\t\t\t\tEnter Password: ";
    getline(cin, password);

    addAccountAdmin(username, password);

    system("CLS");
}

void createCustomerAccount()
{
    system("CLS");
    otherPage("Create User Account");
    string username, password, fullname, contactNum, birthYear, birthMonth, birthDay;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "\n\t\t\t\t\tEnter Full Name: ";
    getline(cin, fullname);
    cin.clear();
    cout << "\n\t\t\t\t\tEnter Contact Number: ";
    cin >> contactNum;
    cin.ignore();

    auto now = system_clock::now();
    auto now_c = system_clock::to_time_t(now);
    tm current_date = *localtime(&now_c);

    do
    {
        cout << "\n\t\t\t\t\tEnter Birth Year: ";
        cin >> birthYear;

        if (birthYear.length() != 4 || !isNumeric(birthYear))
        {
            clearBuffer();
            cout << "\n\t\t\t\t\tEnter a valid year!\n";
        }
    }
    while (birthYear.length() != 4 || !isNumeric(birthYear));



    do
    {
        cout << "\n\t\t\t\t\tEnter Birth Month (If one digit, add 0): ";
        cin >> birthMonth;

        if (birthMonth.length() != 2 || !isdigit(birthMonth[0]) || !isdigit(birthMonth[1]) || stoi(birthMonth) < 1 || stoi(birthMonth) > 12)
        {
            clearBuffer();
            cout << "\n\t\t\t\t\tEnter a valid month (01 to 12)!\n";
        }
    }
    while (birthMonth.length() != 2 || !isdigit(birthMonth[0]) || !isdigit(birthMonth[1]) || stoi(birthMonth) < 1 || stoi(birthMonth) > 12);

    do
    {
        cout << "\n\t\t\t\t\tEnter Birth Day DD (If one digit, add 0): ";
        cin >> birthDay;

        if (birthDay.length() != 2 || !isdigit(birthDay[0]) || !isdigit(birthDay[1]) || stoi(birthDay) < 1 || stoi(birthDay) > 31)
        {
            clearBuffer();
            cout << "\n\t\t\t\t\tEnter a valid day (01 to 31)!\n";
        }
    }
    while (birthDay.length() != 2 || !isdigit(birthDay[0]) || !isdigit(birthDay[1]) || stoi(birthDay) < 1 || stoi(birthDay) > 31);

    string birthDate = birthYear + "-" + birthMonth + "-" + birthDay;

    stringstream ss(birthDate);
    tm birth_date = {};
    ss >> birth_date.tm_year >> birth_date.tm_mon >> birth_date.tm_mday;

    int age = current_date.tm_year + 1900 - birth_date.tm_year;
    if (current_date.tm_mon < birth_date.tm_mon ||
            (current_date.tm_mon == birth_date.tm_mon && current_date.tm_mday < birth_date.tm_mday) )
    {
        age--;
    }

    if (age < 18 || age > 100)
    {
        cout << "\n\t\t\t\t\tSorry, you are not eligible to create an account. 18 to 100 years old only\n";
        return;
    }

    cin.clear();
    cin.ignore(100, '\n');
    cout << "\n\t\t\t\t\tEnter Username: ";
    getline(cin, username);
    cin.clear();
    cout << "\n\t\t\t\t\tEnter Password: ";
    getline(cin, password);

    addAccountUser(fullname, contactNum, birthDate, username, password);
    system("CLS");
}

void displayAllUserTransactions()
{
    AccountNode* userPtr = Accounthead;
    bool regularUserFound = false;

    while (userPtr != nullptr)
    {
        if (userPtr->UsernameAdmin.empty())
        {
            displayPurchases(userPtr->UsernameUser);
            regularUserFound = true;
        }

        userPtr = userPtr->next;
    }

    if (!regularUserFound)
    {
        cout << "\t\t\t\t\t\t\tUser not found.\n";
    }
}

int TransactionsCount()
{
    int counter = 0;
    AccountNode* userPtr = Accounthead;
    bool regularUserFound = false;

    while (userPtr != nullptr)
    {
        if (userPtr->UsernameAdmin.empty())
        {
            displayUserPurchases(userPtr->UsernameUser);
            regularUserFound = true;
        }
        userPtr = userPtr->next;
        ++counter;
    }
    return counter+8;
}

void designAllTrans()
{
    system("CLS");
    TransactionsCount();
    cout << endl << endl;

    for( i = 0; i < 110; i++)
    {
        setColor(17);
        setPosxy(6,3);
        cout << "  ";
        setPosxy(6,4);
        cout << "  ";
        setPosxy(6,5);
        cout << "  ";
        setPosxy(6,6);
        cout << "  ";
        setPosxy(6,7);
        cout << "  ";
        setPosxy(6,8);
        cout << "  ";
        setPosxy(6,9);
        cout << "  ";
        setPosxy(6,10);
        cout << "  ";
        setPosxy(6,11);
        cout << "  ";
        setPosxy(6,12);
        cout << "  ";
        setPosxy(6,13);
        cout << "  ";
        setPosxy(6,14);
        cout << "  ";
        setPosxy(6,15);
        cout << "  ";
        setPosxy(6,16);
        cout << "  ";
        setPosxy(6,17);
        cout << "  ";
        setPosxy(6,18);
        cout << "  ";

        setColor(17+i);

        setPosxy(8+i, 3);
        cout <<" ";
        setPosxy(8+i,18+ TransactionsCount());
        cout <<" ";

        setPosxy(118,3);
        cout << "  ";
        setPosxy(118,4);
        cout << "  ";
        setPosxy(118,5);
        cout << "  ";
        setPosxy(118,6);
        cout << "  ";
        setPosxy(118,7);
        cout << "  ";
        setPosxy(118,8);
        cout << "  ";
        setPosxy(118,9);
        cout << "  ";
        setPosxy(118,10);
        cout << "  ";
        setPosxy(118,11);
        cout << "  ";
        setPosxy(118,12);
        cout << "  ";
        setPosxy(118,13);
        cout << "  ";
        setPosxy(118,14);
        cout << "  ";
        setPosxy(118,15);
        cout << "  ";
        setPosxy(118,16);
        cout << "  ";
        setPosxy(118,17);
        cout << "  ";
        setPosxy(118,18);
        cout << "  ";
        Sleep(0.0001);
    }

    for(int x=0; x<= TransactionsCount(); x++)
    {
        setColor(17);
        setPosxy(6,18+x);
        cout << "  ";
    }


    for(int x=0; x<= TransactionsCount(); x++)
    {
        setColor(127);
        setPosxy(118,18+x);
        cout << "  ";
    }



    for ( i = 0; i < 5; i++)
    {
        setColor(6);
        setPosxy(9+i,5);
        cout << " ";
        setPosxy(9+i,6);
        cout << " ";
        setPosxy(9+i,7);
        cout << " ";
        setPosxy(9+i,8);
        cout << " ";
        setPosxy(9+i,9);
        cout << " ";
        setPosxy(9+i,10);
        cout << " ";
        setPosxy(9+i,11);
        cout << " ";

        setPosxy(10+i,5);
        cout << " ######## #####    ###   ###     ##   ####    ##     ##### ########  ########   ####    ###     ##     " ;
        setPosxy(10+i,6);
        cout << "    ##    ##  ##  ## ##  ####    ##  ##  ##  ## ##  ##        ##        ##    ##    ##  ####    ##     " ;
        setPosxy(10+i,7);
        cout << "    ##    ##  ## ##   ## ## ##   ##   ##    ##   ## ##        ##        ##    ##    ##  ## ##   ##     " ;
        setPosxy(10+i,8);
        cout << "    ##    #####  ####### ##  ##  ##    ##   ####### ##        ##        ##    ##    ##  ##  ##  ##     " ;
        setPosxy(10+i,9);
        cout << "    ##    ##  ## ##   ## ##   ## ##     ##  ##   ## ##        ##        ##    ##    ##  ##   ## ##     " ;
        setPosxy(10+i,10);
        cout << "    ##    ##  ## ##   ## ##    ####  ##  ## ##   ## ##        ##        ##    ##    ##  ##    ####     " ;
        setPosxy(10+i,11);
        cout << "    ##    ##  ## ##   ## ##     ###   ####  ##   ##  #####    ##     ########   ####    ##     ###     " ;

        cout << endl<<endl;
        cout << endl<<endl<<endl<<endl;
        Sleep(0.001);
    }


    displayAllUserTransactions();

    cout << endl<<endl<<endl<<endl;

}


void adminLogin()
{
    system("CLS");
    otherPage("Login admin account");
    string username, password;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "\n\t\t\t\t\t\t\tEnter Username: ";
    getline(cin, username);
    cin.clear();
    cout << "\n\t\t\t\t\t\t\tEnter Password: ";
    getline(cin, password);


    if (loginAdmin(username, password))
    {
        do
        {
admin_menu:
            system("CLS");

            otherPage("Admin : "+username);
            cout << "\t\t\t\t\t\t\t[1] Add Item\n\n"
                 << "\t\t\t\t\t\t\t[2] Remove Item\n\n"
                 << "\t\t\t\t\t\t\t[3] Edit Product\n\n"
                 << "\t\t\t\t\t\t\t[4] Transactions\n\n"
                 << "\t\t\t\t\t\t\t[5] Remove Customer\n\n"
                 << "\t\t\t\t\t\t\t[6] Edit Customer Info\n\n"
                 << "\t\t\t\t\t\t\t[7] Delete My Account\n\n"
                 << "\t\t\t\t\t\t\t[8] Logout\n\n"
                 <<"\t\t\t\t    Enter Your Choice : ";
            cin >> choice;
            if (choice == 1)
            {
                do
                {
addingProd:
                    system("CLS");
                    otherPage("Add Item");
                    cout << "\t\t\t\t\t\t\t[1] Dairy\n"
                         << "\t\t\t\t\t\t\t[2] Canned Goods\n"
                         << "\t\t\t\t\t\t\t[3] Health & Beauty Care\n"
                         << "\t\t\t\t\t\t\t[4] Electronics\n"
                         << "\t\t\t\t\t\t\t[5] Other\n"
                         <<"\t\t\t\t    Enter Your Choice : ";

                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        classification = "Dairy";
                        break;
                    case 2:
                        classification = "Canned Goods";
                        break;
                    case 3:
                        classification = "Health & Beauty Care";
                        break;
                    case 4:
                        classification = "Electronics";
                        break;
                    case 5:
                        classification = "Other";
                        break;
                    default:
                        cout<<"\n\t\t\t\t\t\t\tInvalid Input\n";
                        clearBuffer();
                        break;
                    }
                    cin.ignore(100, '\n');
                    do
                    {
                        cout << "\n\t\t\t\tEnter the product name (up to 25 characters): ";
                        getline(cin, product_name);
                        if (product_name.length() > 25)
                        {
                            clearBuffer();
                            cout << "\t\t\t\t Please enter a product name with at most 25 characters!";
                        }
                    }
                    while (product_name.length() > 25);


                    double price;

                    do
                    {
                        cout << "\n\t\t\t\tEnter the product price: ";
                        string price_str;
                        cin >> price_str;

                        if (isNumeric(price_str))
                        {
                            price = stod(price_str);
                            if (price >= 1.0 && price <= 1000000.0)
                            {
                                break;
                            }
                            else
                            {
                                cout << "\t\t\t\t\t\t\tInvalid input. Please enter a valid numeric value between 1 and 1 million.\n";
                                clearBuffer();
                            }
                        }
                        else
                        {
                            cout << "\t\t\t\t\t\t\tInvalid input. Please enter a valid numeric value.\n";
                            clearBuffer();
                        }

                    }
                    while (true);

                    int quantity;
                    do
                    {
                        cout << "\n\t\t\t\t Enter the quantity : ";
                        cin >> quantity;

                        if (quantity > 0)
                        {
                            break;
                        }
                        else
                        {
                            cout << "\t\t\t\t\t\t\tInvalid input. Please enter a valid numeric value greater than 0.\n";
                            clearBuffer();
                        }
                    }
                    while (true);

                    addProduct(product_name, price, quantity,classification);
                    char addAnother;
                    system("CLS");
                    itemDesign("Successfully Added");
Invalid_Input:
                    cout << "\t\t\t\t\tDo you want to add another product? (y/n): ";
                    cin >> addAnother;


                    if (tolower(addAnother) == 'n')
                    {
                        goto admin_menu;
                    }
                    else if (tolower(addAnother) == 'y')
                    {
                        goto addingProd;
                    }
                    else
                    {
                        cout << "\t\t\t\t\t\t\tInvalid input.\n";
                        clearBuffer();
                        goto Invalid_Input;
                    }
                }
                while (true);
            }
            else if(choice == 2)
            {
remove_menu:
                system("CLS");
                itemDesign("Remove Item");
                cout << endl << endl << endl << endl;
                do
                {
                    removeProductByIndex();
                    char addAnother;

                    do
                    {
                        cout << "\t\t\t\t\tDo you want to remove another product? (y/n): ";
                        cin >> addAnother;

                        if (tolower(addAnother) == 'n')
                        {
                            goto admin_menu;
                        }
                        else if (tolower(addAnother) == 'y')
                        {
                            break;
                        }
                        else
                        {
                            cout << "\t\t\t\t\t\t\tInvalid input.";
                            clearBuffer();
                        }
                    }
                    while (true);

                }
                while (true);
            }
            else if (choice == 3)
            {
                do
                {
edit:
                    system("CLS");
                    itemDesign("Edit Product");
                    editProduct();
                    system("CLS");
                    itemDesign("Edited Product");
                    cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
                    _getch();

                    char addAnother;
                    do
                    {
invalid:
                        cout << "\n\t\t\t\t\tDo you want to edit another product? (y/n): ";
                        cin >> addAnother;

                        if (tolower(addAnother) == 'n')
                        {
                            goto admin_menu;
                        }
                        else if (tolower(addAnother) == 'y')
                        {
                            goto edit;
                        }
                        else
                        {
                            cout << "\t\t\t\t\t\t\tInvalid input\n.";
                            clearBuffer();
                            goto invalid;
                        }
                    }
                    while (true);

                }
                while (true);
            }
            else if  (choice == 4)
            {
                system("CLS");
                otherPage("Transactions");
                do
                {
                    cout<<"\t\t\t\t\t\t\t[1] View account order history\n\n"
                        <<"\t\t\t\t\t\t\t[2] View all account order history\n\n"
                        <<"\t\t\t\t    Enter Your Choice : ";
                    cin>>choice;
                    if (choice == 1)
                    {
                        cout << "\t\t\t\t\t\t\tSearch Account: ";
                        cin >> searchAccount;
                        designUserPurchase(searchAccount);
//                        cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
//                        _getch();
                        //displayPurchases(searchAccount);
                        goto admin_menu;
                    }
                    else if(choice == 2)
                    {
                        system("CLS");
                        otherPage("All User Transactions");
                        displayAllUserTransactions();
                        cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
                        _getch();
                        goto admin_menu;
                    }
                    else
                    {
                        clearBuffer();
                    }

                }
                while(true);
            }
            else if  (choice == 5)
            {
                system("CLS");
                otherPage("Remove Customer");
                cout<< "\n\t\t\t\t\tEnter The username of the customer you want to remove : ";
                cin>>username;
                removeAccountUser(username);
                goto admin_menu;
            }
            else if  (choice == 6)
            {
                system("CLS");
                otherPage("Edit Customer Info");
                cout<< "\n\t\t\t\t\tEnter The username of the customer you want to edit info : ";
                cin>>username;
                editAccount(username);
                goto admin_menu;
            }
            else if (choice ==7)
            {
                system("CLS");
                otherPage("Delete My Account");
                removeAccountAdmin(username);
                break;
            }
            else if  (choice == 8)
            {
                system("CLS");
                break;
            }
            else
            {
                clearBuffer();
            }

        }
        while (choice < 1 || choice > 9);
    }
}

void customerLogin()
{
    system("CLS");
    otherPage("Login User Account");
    string username, password;
    cin.clear();
    cin.ignore(100, '\n');
    cout << "\n\t\t\t\t\t\t\tEnter Username: ";
    getline(cin, username);
    cin.clear();
    cout << "\n\t\t\t\t\t\t\tEnter Password: ";
    getline(cin, password);

    if (loginUser(username, password))
    {

        do
        {
customer_menu:
            system("CLS");
            otherPage("Customer : " + username);
            cout << "\t\t\t\t\t\t\t[1] View Cart\n\n"
                 << "\t\t\t\t\t\t\t[2] Add to Cart\n\n"
                 << "\t\t\t\t\t\t\t[3] Checkout\n\n"
                 << "\t\t\t\t\t\t\t[4] Remove From Cart\n\n"
                 << "\t\t\t\t\t\t\t[5] My Transaction\n\n"
                 << "\t\t\t\t\t\t\t[6] Logout\n\n"
                 <<"\t\t\t\t    Enter Your Choice : ";
            cin >> choice;
            if(choice == 1 )
            {
                system("CLS");
                itemCart(username);
                cout<<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
                _getch();
                goto customer_menu;
            }
            else if (choice == 2)//GAGAWING BY INDEX UMAY //LALAGYAN NG GOTO MENU//walng prompt umay
            {
                do
                {
                    addcart:
                    system("CLS");
                    itemDesign(username);
                    addToCart(username);
                    char addAnother;
                    notValid:
                    cout << "\t\t\t\t    Do you want to add another product? (y/n): ";
                    cin >> addAnother;
                    do
                    {
                        if (tolower(addAnother) == 'n')
                        {
                            goto customer_menu;
                        }
                        else if (tolower(addAnother) == 'y')
                        {
                            goto addcart;
                        }
                        else
                        {
                            cout << "\t\t\t\t\t\t\tInvalid input.\n";
                            clearBuffer();
                            goto notValid;
                        }
                    }
                    while(true);

                }
                while (true);
            }
            else if (choice== 3)
            {
                int choice;

                system("CLS");

                if (displayCartIndex(username) < 0)
                {
                    itemCart(username);
                    cout << "\n\n\n\n\t\t\t\t\t\t\tYou can't checkout while the cart is empty.\n";
                    cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
                    _getch();
                    goto customer_menu;
                }
                else
                {
mop:
                    itemCart(username);
                    cout << "\t\t\t\t\t\t[1] Cash\n"
                         << "\t\t\t\t\t\t[2] Bank Transfer with 5% discount for each item\n";

                    if (isUserBirthday(username))
                    {
                        cout << "\t\t\t\t\t\t[3] Special Birthday Discount\n";
                    }

                    cout << "\t\t\t\t    Enter Your Choice : ";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        Receipt(username);
                        goto customer_menu;
                    case 2:
                        ReceiptDiscounted(username);
                        goto customer_menu;
                    case 3:
                        if (isUserBirthday(username))
                        {
                            ReceiptBirthdayDiscount(username);
                            goto customer_menu;
                        }
                        else
                        {
                            cout << "Invalid choice. Please try again.\n";
                            cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
                            _getch();
                            clearBuffer();
                            goto mop;
                        }
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                        cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
                        _getch();
                        clearBuffer();
                        goto mop;
                    }
                }

            }
            else if (choice == 4)
            {

                removeFromCartByIndex(username);
                cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
                _getch();
                goto customer_menu;
            }
            else if(choice == 5)
            {
                cout<<username;
                designUserPurchase(username);
//                    cout <<"\n\n\n\n\t\t\t\t\t\t\t Press any key....\n";
//                    _getch();

                goto customer_menu;
            }
            else if  (choice ==6)
            {
                system("CLS");
                break;
            }
            else
            {
                clearBuffer();
            }
        }
        while (choice != 1  &&  choice != 2 && choice !=3&& choice !=4&& choice !=5);
    }
}

int main()
{
    addProduct("Samsung S23 256gb", 81990.00, 50, "Electronics");
    addProduct("iPhone 15 pro max", 108990.00, 50, "Electronics");
    addProduct("Xiaomi Monitor", 15999.00, 50, "Electronics");
    addProduct("Acer Nitro Laptop", 62999.00, 100, "Electronics");
    addProduct("Samsung Galaxy Buds", 5490.00, 100, "Electronics");

    addProduct("Anchor Butter", 78.00, 100, "Dairy");
    addProduct("Arla Cheese", 116.95, 100, "Dairy");
    addProduct("Chevital Quickmelt", 196.95, 100, "Dairy");
    addProduct("Alaska Fresh Milk", 88.50,100, "Dairy");
    addProduct("Eden Cream Cheese", 138.00, 100, "Dairy");

    addProduct("CETAPHIL soap Bar", 422.00, 100, "Health & Beauty Care");
    addProduct("SAFEGUARD Soap 175g", 81.00, 100, "Health & Beauty Care");
    addProduct("Dove Shampoo 170ml", 195.00, 100, "Health & Beauty Care");
    addProduct("HEAD N SHOULDERS", 385.00, 100, "Health & Beauty Care");
    addProduct("OLAY Skin Cleanser", 160.00, 100, "Health & Beauty Care");

    addProduct("Delimondo CBeef", 163.00, 200, "Canned Goods");
    addProduct("San Marino Tuna", 23.25, 200, "Canned Goods");
    addProduct("555 Tuna Caldereta ", 25.00, 200, "Canned Goods");
    addProduct("Star Corned Beef", 30.00, 200, "Canned Goods");
    addProduct("Argentina Meat Loaf", 19.80, 200, "Canned Goods");

    addProduct("NXLED Strip Light", 1699.75, 100, "Other");
    addProduct("Refillabe Battery", 649.00, 100, "Other");
    addProduct("AquaFlask 22oz Red", 750.00, 100, "Other");
    addProduct("Aluminum Tape Small", 45.00, 200, "Other");
    addProduct("Double-Sided Tape ", 34.00, 200, "Other");




    int choice;
    MembersName();
    cout << "Press any key to Start..." << endl;
    _getch();
    system("CLS");
    do
    {
main_menu:
        frontPage("Main Menu");
        cout<<endl;
        cout <<"\t\t\t\t\t\t\t[1] Sign up\n\n"
             <<"\t\t\t\t\t\t\t[2] Login\n\n"
             <<"\t\t\t\t\t\t\t[3] Display Product\n\n"
             <<"\t\t\t\t\t\t\t[4] Exit\n\n"
             <<"\t\t\t\t    Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("CLS");
            otherPage("Sign up");
            int accountType;
            cout << "\t\t\t\t\t\t\t[1] Admin\n\n"
                 << "\t\t\t\t\t\t\t[2] Customer\n\n"
                 << "\t\t\t\t\t\t\t[3] Back\n\n"
                 <<"\t\t\t\t    Enter Your Choice : ";
            cin >> accountType;
            if (accountType == 1)
            {
                createAdminAccount();
            }
            else if (accountType == 2)
            {
                createCustomerAccount();
            }
            else if(accountType == 3)
            {
                system("CLS");
                goto main_menu;
            }
            else
            {
                clearBuffer();

            }
            break;

        case 2:
            int userType;
            system("CLS");
            otherPage("Login");
            cout << "\t\t\t\t\t\t\t[1] Admin\n\n"
                 << "\t\t\t\t\t\t\t[2] Customer\n\n"
                 << "\t\t\t\t\t\t\t[3] Back\n\n"
                 <<"\t\t\t\t    Enter Your Choice : ";
            cin >> userType;
            if (userType == 1)
            {
                adminLogin();
            }
            else if (userType == 2)
            {
                customerLogin();
            }
            else if (userType == 3)
            {
                goto main_menu;
            }
            else
            {
                clearBuffer();
                cout << "\t\t\t\t\t\t\tInvalid choice.\n";
            }
            break;

        case 3:
            system("CLS");
            itemDesign("Available");
            cout << "Press any key to Back..." << endl;
            _getch();
            system("CLS");
            break;

        case 4:
            cout << "\t\t\t\t\t\t\tExiting the program.\n";
            break;

        default:
            clearBuffer();
            cout << "\t\t\t\t\t\t\tInvalid choice.\n";
            break;
        }
    }
    while (choice != 4);

    return 0;
}



//void deleteProduct(int index)
//{
//    if (Producthead == nullptr)
//    {
//        cout << "No products available. Cannot delete.\n";
//        return;
//    }
//
//    ProductNode* current = Producthead;
//    ProductNode* previous = nullptr;
//    int currentIndex = 1;
//
//    while (current != nullptr)
//    {
//        if (currentIndex == index)
//        {
//            string deletedProductName = current->productName;
//
//            if (previous == nullptr)
//            {
//                Producthead = current->next;
//            }
//            else
//            {
//                previous->next = current->next;
//            }
//            delete current;
//
//            cout << "Product "<< " ('" << deletedProductName << "') removed successfully\n";
//            return;
//        }
//        previous = current;
//        current = current->next;
//        ++currentIndex;
//    }
//    cout << "Invalid index. Product not found.\n";
//}

//                    else if (choice == 2)
//                    {
//                        system("CLS");
//                        cout<<"\t\t\t\t    Enter the product position of product you want to delete : ";
//                        cin>>choice;
//                        deleteProduct(choice);
//                        goto admin_menu;
//                    }
