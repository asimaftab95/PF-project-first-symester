#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string toyotaModels[3] = {"Toyota Revo", "Toyota Fortuner", "Toyota Grande"};
int toyotaPrices[3] = {155, 200, 75};
int toyotaUnitsSold[3] = {0};

string hondaModels[3] = {"Honda Civic", "Honda City", "Honda Vezel"};
int hondaPrices[3] = {99, 55, 132};
int hondaUnitsSold[3] = {0};

string audiModels[3] = {"Audi e-tron gt", "Audi A5", "Audi e-tron"};
int audiPrices[3] = {500, 180, 300};
int audiUnitsSold[3] = {0};

void displayCars(string models[], int prices[], int size, string companyName);
void modifyPrice(string models[], int prices[], int size);
void enterMonthlySales();
void viewProfitForMonth();
void viewTaxForMonth();
void viewExpenses();
void viewNetProfitForMonth();
void menu();


void displayCars(string models[], int prices[], int size, string companyName) {
    cout << "\nCars available from " << companyName << ":\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << models[i] << " - Price: " << prices[i] << " lacs\n";
    }
    cout << endl;
}

void modifyPrice(string models[], int prices[], int size) {
    int carChoice;
    cout << "\nChoose a car to modify its price:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << models[i] << ": Current Price: " << prices[i] << " lacs\n";
    }
    cout << "Enter your choice: ";
    cin >> carChoice;

    if (carChoice >= 1 && carChoice <= size) {
        int newPrice;
        cout << "Enter the new price for " << models[carChoice - 1] << ": ";
        cin >> newPrice;
        prices[carChoice - 1] = newPrice;
        cout << "Price updated successfully.\n";
    } else {
        cout << "Invalid choice.\n";
    }
}

bool monthRecorded[12] = {false};
int salesData[3][3][12] = {0}; // salesData[company][car][month]


void enterMonthlySales() {
    int month;
    cout << "\nEnter the month number (1-12): ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month! Try again.\n";
        return;
    }

    month -= 1; // Convert to 0-based index

    if (monthRecorded[month]) {
        cout << "Sales for this month have already been entered. Choose a different month.\n";
        return;
    }

    string companies[3] = {"Toyota", "Honda", "Audi"};
    string* models[3] = {toyotaModels, hondaModels, audiModels};

    for (int company = 0; company < 3; company++) {
        cout << "\nEnter sales for " << companies[company] << ":\n";
        for (int car = 0; car < 3; car++) {
            cout << "Enter units sold for " << models[company][car] << ": ";
            cin >> salesData[company][car][month];
        }
    }

    monthRecorded[month] = true;
    cout << "\nSales data for month " << (month + 1) << " recorded successfully.\n";
}


void viewProfitForMonth() {
    int month;
    cout << "\nEnter the month number (1-12) to view profit: ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month! Try again.\n";
        return;
    }

    month -= 1;

    if (!monthRecorded[month]) {
        cout << "Sales for this month have not been recorded yet. Enter sales first.\n";
        return;
    }

    cout << "\n--- Profit Report for Month " << (month + 1) << " ---\n";

    string companies[3] = {"Toyota", "Honda", "Audi"};
    string* models[3] = {toyotaModels, hondaModels, audiModels};
    int* prices[3] = {toyotaPrices, hondaPrices, audiPrices};

    float totalProfit = 0;

    for (int company = 0; company < 3; company++) {
        cout << "\nProfit for " << companies[company] << ":\n";
        for (int car = 0; car < 3; car++) {
            int unitsSold = salesData[company][car][month];

            float profitRate = 0.0;
            int price = prices[company][car];
            if (price < 80)
                profitRate = 3.0;
            else if (price <= 100)
                profitRate = 5.5;
            else if (price <= 200)
                profitRate = 7.0;
            else if (price <= 350)
                profitRate = 11.0;
            else if (price <= 500)
                profitRate = 15.0;

            float profit = unitsSold * profitRate;
            totalProfit += profit;

            cout << "Car: " << models[company][car] << "\n";
            cout << "Units sold: " << unitsSold << "\n";
            cout << "Profit: " << profit << " lacs\n\n";
        }
    }

    cout << "Total Profit for Month " << (month + 1) << ": " << totalProfit << " lacs\n";
}


void viewTaxForMonth() {
    int month;
    cout << "\nEnter the month number (1-12) to view tax: ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month! Try again.\n";
        return;
    }

    month -= 1;

    if (!monthRecorded[month]) {
        cout << "Sales for this month have not been recorded yet. Enter sales first.\n";
        return;
    }

    cout << "\n--- Tax Report for Month " << (month + 1) << " ---\n";

    string companies[3] = {"Toyota", "Honda", "Audi"};
    string* models[3] = {toyotaModels, hondaModels, audiModels};
    int* prices[3] = {toyotaPrices, hondaPrices, audiPrices};

    float totalTax = 0;

    for (int company = 0; company < 3; company++) {
        cout << "\nTax for " << companies[company] << ":\n";
        for (int car = 0; car < 3; car++) {
            int unitsSold = salesData[company][car][month];
            int price = prices[company][car];

            float taxRate;
            if (price <= 100)
                taxRate = 0.10;
            else if (price <= 200)
                taxRate = 0.15;
            else if (price <= 300)
                taxRate = 0.20;
            else if (price <= 500)
                taxRate = 0.25;
            else
                taxRate = 0.30;

            float tax = unitsSold * price * taxRate;
            totalTax += tax;

            cout << "Car: " << models[company][car] << "\n";
            cout << "Units sold: " << unitsSold << "\n";
            cout << "Tax: " << tax << " lacs\n\n";
        }
    }

    cout << "Total Tax for Month " << (month + 1) << ": " << totalTax << " lacs\n";
}


int rent[12] = {0}, electricity[12] = {0}, salaries[12] = {0};
bool expensesEntered[12] = {false};

void viewExpenses() {
    int month;
    cout << "\nEnter the month number (1-12) to enter expenses: ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month! Try again.\n";
        return;
    }

    month -= 1;

    if (expensesEntered[month]) {
        cout << "Expenses for this month have already been entered.\n";
        return;
    }

    cout << "Entering expenses for month " << (month + 1) << ":\n";

    cout << "Enter the monthly rent of the showroom: ";
    cin >> rent[month];

    cout << "Enter the electricity bills of the showroom: ";
    cin >> electricity[month];

    cout << "Enter the salaries of employees of the showroom: ";
    cin >> salaries[month];

    expensesEntered[month] = true;
    cout << "Expenses entered successfully for month " << (month + 1) << ".\n";
}


void viewNetProfitForMonth() {
    int month;
    cout << "\nEnter the month number (1-12) to view net profit: ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month! Try again.\n";
        return;
    }

    month -= 1;

    if (!monthRecorded[month]) {
        cout << "Sales for this month have not been recorded yet. Enter sales first.\n";
        return;
    }

    if (!expensesEntered[month]) {
        cout << "Expenses for this month have not been entered yet. Enter expenses first.\n";
        return;
    }


    string companies[3] = {"Toyota", "Honda", "Audi"};
    string* models[3] = {toyotaModels, hondaModels, audiModels};
    int* prices[3] = {toyotaPrices, hondaPrices, audiPrices};

    float totalProfit = 0;

    for (int company = 0; company < 3; company++) {
        for (int car = 0; car < 3; car++) {
            int unitsSold = salesData[company][car][month];

            float profitRate = 0.0;
            int price = prices[company][car];
            if (price < 80)
                profitRate = 3.0;
            else if (price <= 100)
                profitRate = 5.5;
            else if (price <= 200)
                profitRate = 7.0;
            else if (price <= 350)
                profitRate = 11.0;
            else if (price <= 500)
                profitRate = 15.0;

            totalProfit += unitsSold * profitRate;
        }
    }

    
    int totalExpense = rent[month] + electricity[month] + salaries[month];
    cout << "Total Profit for Month " << (month + 1) << ": " << totalProfit << " lacs\n";
    cout << "Total Expenses for Month " << (month + 1) << ": " << totalExpense << " lacs\n";


    float netProfit = totalProfit - totalExpense;
    cout << "Net Profit for Month " << (month + 1) << ": " << netProfit << " lacs\n";
}

void saveDataToFile() {
    ofstream outFile("Sales_data.txt");

    if (!outFile) {
        cout << "Error: Could not open file for saving data.\n";
        return;
    }

    
    string companies[3] = {"Toyota", "Honda", "Audi"};
    string* models[3] = {toyotaModels, hondaModels, audiModels};
    int* prices[3] = {toyotaPrices, hondaPrices, audiPrices};

    // Save sales data to the file
    outFile << "Sales Data:\n";
    for (int month = 0; month < 12; month++) {
        if (monthRecorded[month]) {
            outFile << "Month " << (month + 1) << ":\n";
            for (int company = 0; company < 3; company++) {
                outFile << companies[company] << ":\n";
                for (int car = 0; car < 3; car++) {
                    outFile << "  " << models[company][car] 
                            << ": Units Sold: " << salesData[company][car][month] 
                            << ", Price: " << prices[company][car] << " lacs\n";
                }
            }
        }
    }

    // Save expenses data to the file
    outFile << "\nExpenses:\n";
    for (int month = 0; month < 12; month++) {
        if (expensesEntered[month]) {
            outFile << "Month " << (month + 1) << ": Rent: " << rent[month] 
                    << " lacs, Electricity: " << electricity[month] 
                    << " lacs, Salaries: " << salaries[month] << " lacs\n";
        }
    }

    outFile.close();
    cout << "Data saved successfully.\n";
}

void readFileAndDisplay() {
    ifstream inFile("Sales_data.txt");
    if (!inFile) {
        cout << "Error: File not found!" << endl;
        return;
    }

    string line;
    cout << "Reading file contents:" << endl;
    while (getline(inFile, line)) {
        cout << line << endl; 
    }

    inFile.close();
}


void menu() {
    int choice;
    do {
        cout << "\n--- Car Showroom Management System ---\n";
        cout << "1. View available cars and their prices\n";
        cout << "2. Modify car price\n";
        cout << "3. Check tax list according to a car price\n";
        cout << "4. Enter monthly sales\n";
        cout << "5. Enter the monthly expenses\n";
        cout << "6. View profit from sales\n";
        cout << "7. View tax from sales\n";
        cout << "8. View net profit\n ";
        cout << "9. Save data to a file\n ";
        cout << "10. Load data to a file \n ";
        cout << "11. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int companyChoice;
                cout << "1. Toyota\n";
                cout << "2. Honda\n";
                cout << "3. Audi\n";
                cout << "Enter your choice: ";
                cin >> companyChoice;

                if (companyChoice == 1) {
                    displayCars(toyotaModels, toyotaPrices, 3, "Toyota");
                } else if (companyChoice == 2) {
                    displayCars(hondaModels, hondaPrices, 3, "Honda");
                } else if (companyChoice == 3) {
                    displayCars(audiModels, audiPrices, 3, "Audi");
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
            case 2: {
                int companyChoice;
                cout << "1. Toyota\n";
                cout << "2. Honda\n";
                cout << "3. Audi\n";
                cout << "Enter your choice: ";
                cin >> companyChoice;

                if (companyChoice == 1) {
                    modifyPrice(toyotaModels, toyotaPrices, 3);
                } else if (companyChoice == 2) {
                    modifyPrice(hondaModels, hondaPrices, 3);
                } else if (companyChoice == 3) {
                    modifyPrice(audiModels, audiPrices, 3);
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
            case 3: {
                cout << "If car price is less than 100 lacs, tax is 10% of car price.\n";
                cout << "If car price is greater than 100 lacs and less than or equal to 200 lacs, tax is 15%.\n";
                cout << "If car price is greater than 200 lacs and less than or equal to 300 lacs, tax is 20%.\n";
                cout << "If car price is greater than 300 lacs and less than or equal to 500 lacs, tax is 25%.\n";
                break;
            }
            case 4:
                enterMonthlySales();
                break;
            case 5:
                viewExpenses();
                break;
            case 6:
                viewProfitForMonth();
                break;
            case 7:
                viewTaxForMonth();
                break;
            case 8:
                viewNetProfitForMonth();
                break;
            case 9:
                 saveDataToFile();
                break;
			case 10:
                readFileAndDisplay();
                break;    
            case 11:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please select again.\n";
        }
    } while (choice != 11);
}

int main() {
    menu();
    return 0;
} 
