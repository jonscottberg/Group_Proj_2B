#include <iostream>

#include <iomanip>

#include <fstream>

using namespace std;



string cakeTypes[] = {"Chocolate", "Carrot", "Yellow", "Oreo", "Strawberry"};

string frostingTypes[] = {"Chocolate", "Vanilla", "Cream Cheese"};

string fillingTypes[] = {"Fudge", "Pudding", "Custard", "Mousse"};



const double prices[5][3][4] = {

    {

        {10.12, 12.34, 13.34, 14.80},

        {13.10, 13.12, 10.20, 14.99},

        {10.20, 10.22, 15.23, 39.99},

    },

    {

        {12.22, 12.39, 13.45, 15.32},

        {11.11, 14.23, 11.21, 24.99},

        {11.20, 22.22, 23.33, 89.99},

    },

    {

        {10.12, 12.34, 13.34, 14.80},

        {13.10, 13.12, 10.20, 14.99},

        {10.20, 10.22, 15.23, 59.99},

    },

    {

        {10.12, 12.34, 13.34, 14.80},

        {13.10, 13.12, 10.20, 14.99},

        {10.20, 10.22, 15.23, 69.99},

    },

    {

        {10.14, 12.34, 17.38, 49.80},

        {13.34, 15.12, 10.02, 13.07},

        {10.20, 12.34, 14.20, 29.99},

    },

};



double determineBaseCakePrice(string *, string *, string *);

int getItemIndexFromArray(string, string[]);

void displayAndPrintReceipt(string *, string *, string *, string*, double *);



int main() {

    bool repeatOrderProcess = true;

    string customerName;



    cout << "Welcome to the Conjoined Triangles of Success Bakery!" << endl;

    cout << "Please enter your full name: ";

    cin >> customerName;



    while (repeatOrderProcess) {

        string cakeType;

        int cakeTypeLength = sizeof(cakeTypes)/sizeof(cakeTypes[0]);

        cout << "Please choose a cake type. Here are our available ones." << endl;



        for (int i = 0; i < cakeTypeLength; i++) {

            cout << i + 1 << ") " << cakeTypes[i] << endl;

        }



        cout << "Please enter a cake type: ";

        cin >> cakeType;



        string frostingType;

        int frostingTypeLength = sizeof(frostingTypes)/sizeof(frostingTypes[0]);

        cout << "Please choose a frosting type. Here are our available ones." << endl;



        for (int i = 0; i < frostingTypeLength; i++) {

            cout << i + 1 << ") " << frostingTypes[i] << endl;

        }



        cout << "Please enter a frosting type: ";

        cin >> frostingType;



        string fillingType;

        int fillingTypeLength = sizeof(fillingTypes)/sizeof(fillingTypes[0]);

        cout << "Please choose a filling type. Here are our available ones." << endl;



        for (int i = 0; i < fillingTypeLength; i++) {

            cout << i + 1 << ") " << fillingTypes[i] << endl;

        }



        cout << "Please enter a filling type: ";

        cin >> fillingType;



        double price = determineBaseCakePrice(&cakeType, &frostingType, &fillingType);

        cout << price << endl;



        char repeatOrder;

        cout << "Would you like to make another order? (Yes (Y) / No (N)): " << endl;

        cin >> repeatOrder;



        displayAndPrintReceipt(&customerName, &cakeType, &frostingType, &fillingType, &price);

        

        switch (repeatOrder) {

            case 'N':

                repeatOrder = false;

                cout << "Bye " << customerName << ", your order will be completed shortly." << endl;

                cout << "Have a great day!" << endl;

                break;

            default:

                repeatOrderProcess = true;

                break;

        }

    }



    return 0;

}



// generates a price for the cake based off of the cake type, frosting type, and filling type

double determineBaseCakePrice(string *cakeType, string *frostingType, string *fillingType) {

    int cakeTypeIndex = getItemIndexFromArray(*cakeType, cakeTypes);

    int frostingTypeIndex = getItemIndexFromArray(*frostingType, frostingTypes);

    int fillingTypeIndex = getItemIndexFromArray(*fillingType, fillingTypes);



    // loop through the prices array, if all indexes match then return a price

    for (int cake = 0; cake < sizeof(cakeTypes)/sizeof(cakeTypes[0]); cake++) {

        for (int frosting = 0; frosting < sizeof(frostingTypes)/sizeof(frostingTypes[0]); frosting++) {

            for (int filling = 0; filling < sizeof(fillingTypes)/sizeof(fillingTypes[0]); filling++) {

                if (cake == cakeTypeIndex && frosting == frostingTypeIndex && filling == fillingTypeIndex) {

                    return prices[cake][frosting][filling];

                }

            }

        }

    }



    return 0.00;

}



// returns the index of a value of it exists, otherwise returns -1

int getItemIndexFromArray(string itemName, string items[]) {

    int itemLength = sizeof(items)/sizeof(items[0]);

    for (int i = 0; i < itemLength; i++) {

        cout << items[i] << endl;

    }

    return -1;

}



// saves a receipt to a text file based on customer information

void displayAndPrintReceipt(string *customerName, string *cakeType, string *frostingType, string *fillingType, double * price) {



    ofstream writeReceiptFile;

    ifstream readRecieptFile;

    string outputFromReceiptFile;



    writeReceiptFile.open("receipt.txt");

    readRecieptFile.open("receipt.txt");



    readRecieptFile >> outputFromReceiptFile;



    writeReceiptFile << outputFromReceiptFile;

    writeReceiptFile << "Order #" << rand();

    writeReceiptFile << "________________________________" << endl;

    writeReceiptFile << "Customer Name: " << *customerName << endl;

    writeReceiptFile << "Cake Type: " << *cakeType << endl;

    writeReceiptFile << "Cake Frosting: " << *frostingType << endl;

    writeReceiptFile << "Cake Filling: " << *fillingType << endl;

    writeReceiptFile << "Total: " << *price << endl;



    writeReceiptFile.close();

    readRecieptFile.close();

}