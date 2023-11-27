#include <iostream>

class Account {
protected:
    std::string accountHolder;
    std::string accountNumber;
    double balance;
public:
    Account(const std::string& accNum, const std::string& accHolder, double bal)
        : accountNumber(accNum), accountHolder(accHolder), balance(bal)
    {
    }

    void displayDetails() {
        std::cout << "Account Holder: " << accountHolder << std::endl << "Account Balance: " << balance << std::endl;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if(balance > amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient Balance";
        }
    }
};


class SavingsAccount : public Account {
private:
    double interestRate;
public:
     SavingsAccount(const std::string& accNum, const std::string& accHolder, double bal, double rate)
	     : Account(accNum,accHolder,bal), interestRate(rate)
    {
    }

    void withdraw(double amount) {
        if ((balance - 1000) > 0) {
            balance -= amount;
        } else {
            std::cout << "Could Not Withdraw. Balance must remain above $1000";
        }
    }
};

class CurrentAccount : public Account {
private:
    double overdraft;
public:
    CurrentAccount(const std::string& accNum, const std::string& accHolder, double bal, double odlimit)
        : Account(accNum,accHolder,bal), overdraft(odlimit)
    {
    }
    void withdraw(double amount) {
        if ((balance - amount) > -(overdraft)) {
            balance -= amount;
        } else {
	    std::cout << "Could not withdraw. Amount exceeds overdraft limit";	
	}
    }
};

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);
    
    savings.displayDetails();
    current.displayDetails();

    return 0;
}


