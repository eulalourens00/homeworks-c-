#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime> 
using namespace std;

//1. структура и описание крысы
struct Rat {
    int speed;
    double position_x;
    string species;
    string name;
    int age;
};

//2. сделать новую крысу
Rat createRat(int speed, double position_x, string species, string name, int age) {
    Rat newMini_rat;
    newMini_rat.speed = speed;
    newMini_rat.position_x = position_x;
    newMini_rat.species = species;
    newMini_rat.name = name;
    newMini_rat.age = age;

    return newMini_rat;
}

//3.изменение положения крысы. x += rand()
  //изменение положение на случайную величину, с учетом ее скорости.
void updatePosition(Rat& mini_rat) {

    double random_move = static_cast<double>(rand()) / RAND_MAX * mini_rat.speed;
    mini_rat.position_x += abs(random_move);
}

//4. функция для изменения имени и скорости крысы
void new_name(Rat& mini_rat, string new_name) {
    mini_rat.name = new_name;
}
void new_speed(Rat& mini_rat, int new_speed) {
    mini_rat.speed = new_speed;
}

//5. новая крыса (параметры берем из первых двух крыс, рандомно)
//Rat create_Absolutly_new_Rat(int speed, double position_x, string species, string name, int age) {
//    for (int i = 0; i <= 5; i++) {
//        srand(static_cast<unsigned int>(time(0)));
//        int random_sign = rand() % 5 + 1;
//
//        if (random_sign == 1) {
//
//        }
//    }
//
//}

    int main()
{

    //1. rat
    Rat mini_rat1 = {
         4,
         3.2,
         "Long hair rat",
         "Leeky",
         2
    };

    Rat mini_rat2 = {
        3,
        2.2,
        "Black rat",
        "Suya",
        1
    };

    //2. new rat
    Rat new_mini_rat1 = createRat(3, 4.0, "King of rat", "Goldboy", 10);

    //3. изменение позиции

    cout << "Initial position of " << mini_rat1.name << ": " << mini_rat1.position_x << endl;
    updatePosition(mini_rat1);
    cout << "New position of " << mini_rat1.name << ": " << mini_rat1.position_x << endl;

    //4. изменение имени и скорости
    cout << "Rat speed: " << mini_rat1.speed << " " << "; name is " << mini_rat1.name << endl;
    new_name(mini_rat1, "Loopy");
    new_speed(mini_rat1, 10);
    cout << "New Rat speed: " << mini_rat1.speed << " " << "; New name is " << mini_rat1.name << endl;


    return 0;
}
