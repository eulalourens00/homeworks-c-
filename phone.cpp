#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime> 
using namespace std;

//1. структура и описание телефона
struct Phone {
    int price;
    string color;
    string model;
};

//2. функция для изменения одного параметра
void newPhonecolor(Phone& one_phone, string new_color) {
    one_phone.color = new_color;
}
void newPhoneprice(Phone& one_phone, int new_price) {
    one_phone.price = new_price;
}

//3. сделать новый телефон
Phone createPhone(int price, string color, string model) {
    Phone newPhone;
    newPhone.price = price;
    newPhone.color = color;
    newPhone.model = model;

    return newPhone;
}

int main()
{
    //1.
    Phone lifephone = {
         15000,
         "White",
         "LifePhone from Barboskin" 
    };

    Phone moonphone = {
        30000,
        "Black",
        "Suya"
    };

    //2.
    cout << "LifePhone from Barboskin. Was color: " << lifephone.color << " " << "; Was price is " << lifephone.price << endl;
    newPhonecolor(lifephone, "Blue");
    newPhoneprice(lifephone, 10000);

    cout << "LifePhone from Barboskin. New color: " << lifephone.color << " " << "; price is " << lifephone.price << endl;
    //3.
    Phone newPhone = createPhone(17000, "Gold", "Goldboy");


    return 0;
}