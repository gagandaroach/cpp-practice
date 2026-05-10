#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double loanAmount, annualRate, years;
    int totalPayments;
    double monthlyRate, monthlyPayment;
    double totalInterest = 0.0;

    // Input
    cout << "Enter loan amount: ";
    cin >> loanAmount;
    cout << "Enter annual interest rate (%): ";
    cin >> annualRate;
    cout << "Enter loan term (years): ";
    cin >> years;

    // Validate inputs
    if (loanAmount <= 0 || annualRate < 0 || years <= 0) {
        cout << "Error: All values must be positive (interest rate can be zero)." << endl;
        return 1;
    }

    // Convert annual rate to monthly and decimal
    monthlyRate = annualRate / 12.0 / 100.0;
    totalPayments = static_cast<int>(years * 12);

    // Handle zero interest rate
    if (monthlyRate == 0) {
        monthlyPayment = loanAmount / totalPayments;
    } else {
        // Calculate monthly payment using formula
        monthlyPayment = loanAmount * (monthlyRate * pow(1 + monthlyRate, totalPayments)) /
                         (pow(1 + monthlyRate, totalPayments) - 1);
    }

    // Display header
    cout << fixed << setprecision(2);
    cout << "\nLoan Amortization Schedule\n";
    cout << "------------------------------------------------------------\n";
    cout << "Payment #  Beg Balance   Payment   Principal   Interest   End Balance\n";
    cout << "------------------------------------------------------------\n";

    double balance = loanAmount;
    for (int month = 1; month <= totalPayments; month++) {
        double interest = balance * monthlyRate;
        double principal;
        double payment;

        if (month == totalPayments) {
            // Last payment: pay off the remaining balance
            principal = balance;
            payment = principal + interest;
        } else {
            payment = monthlyPayment;
            principal = payment - interest;
        }

        double endBalance = balance - principal;

        // Display the row
        cout << setw(9) << month
             << setw(12) << balance
             << setw(10) << payment
             << setw(10) << principal
             << setw(10) << interest
             << setw(12) << endBalance
             << endl;

        totalInterest += interest;
        balance = endBalance;
    }

    cout << "------------------------------------------------------------\n";
    cout << "Total Interest Paid: $" << totalInterest << endl;

    return 0;
}