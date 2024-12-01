#include <iostream>
#include <vector>
#include <string>

struct Account {
    std::string full_name;
    int account_number;
    double money;
    std::string phone_number;
};

void add_money(Account &acc, double money) {
    acc.money  += money;
}

void no_money(Account &acc, double money) {
    int summa;
    std::cout << "Summa which you need to get: ";
    std::cin >> summa;

    if(acc.money >= summa){
        acc.money -= summa;
        std::cout << "now " << acc.money;
    } else{
        std::cout << "Cant do it.";
    }
}

// Account create_account(std::string full_name, int account_number, double money, std::string phone_number);
int main() {
    Account acc1 = {"Leeky sya",
                    60,
                    4.12};
                    
    add_money(acc1, 10);
    std::cout << acc1.full_name << " " << acc1.money;

    //Account  acc2 = create_account("Leeky", 124321, 12.321, "+845674");
    //Account* pacc2 = &acc2;
    //std::cout << pacc2->full_name << " " << pacc2->money;

    return 0;
}