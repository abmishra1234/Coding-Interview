#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>

#define FORREF
#ifndef FORREF
/*
    how copy and move is performing inside assignment operator?
    Task:  Why this is crashing?
    // output
    Account& operator = (const Account& other): 0.0000239000 seconds
    Account& operator=(Account&& other):0.0000021000 seconds
*/

class Account {
public:

    Account() = default;
    Account(int numb) : numberOf(numb), deposits(new double[numb]) {}

    Account(const Account& other) : numberOf(other.numberOf), deposits(new double[other.numberOf]) {
        std::copy(other.deposits, other.deposits + other.numberOf, deposits);
    }

    Account& operator = (const Account& other) {
        if (this != &other) {
            delete[] deposits;
            numberOf = other.numberOf;
            deposits = new double[other.numberOf];
            std::copy(other.deposits, other.deposits + other.numberOf, deposits);
        }
        return *this;
    }

    Account(Account&& other) :numberOf(other.numberOf), deposits(other.deposits) {
        other.deposits = nullptr;
        other.numberOf = 0;
    }

    // this is for move sementics
    Account& operator =(Account&& other) {
        numberOf = other.numberOf;
        deposits = other.deposits;
        other.deposits = nullptr;
        other.numberOf = 0;
        return *this;
    }
    ~Account() noexcept {
        delete[] deposits;
        deposits = nullptr;
    }

private:
    int numberOf;
    double* deposits;
};

int main() {

    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(10);

    //    Account account(200000000);
    //    Account account2(100000000);

        // above two line making system memory allocation failed case and program was crashing so just changed for small
        // memory to showcash the concept in problem
    Account account(2000);
    Account account2(1000);

    auto start = std::chrono::system_clock::now();
    account = account2; // example of standard copy
    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
    std::cout << "Account& operator = (const Account& other): " << dur.count() << " seconds" << std::endl;

    start = std::chrono::system_clock::now();
    account = std::move(account2); // Example of standard move
    dur = std::chrono::system_clock::now() - start;
    std::cout << "Account& operator=(Account&& other):" << dur.count() << " seconds" << std::endl;

    std::cout << std::endl;
}
#endif // FORREF

