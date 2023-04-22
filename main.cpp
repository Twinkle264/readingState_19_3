#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    string lastName;
    string name;
    unsigned int payment = 0;
    unsigned int totalPayment = 0;
    unsigned int maxPayment = 0;
    string date;
    string maxPaymentName;

    fin.open("statement.txt");
    if (!fin.is_open()) {
        cerr << "File is not open!";
    } else {
        while (!fin.eof()) {
            fin >> name >> lastName >> payment >> date;

            name += " " + lastName;
            totalPayment += payment;

            if (payment > maxPayment) {
                maxPayment = payment;
                maxPaymentName = name;
            }
        }
    }
    fin.close();

    cout << "Total payment is: " << totalPayment << endl;
    cout << maxPaymentName << " has the maximum payouts with the amount of " << maxPayment;
    return 0;
}
