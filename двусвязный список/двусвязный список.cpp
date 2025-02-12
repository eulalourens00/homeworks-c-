
#include <iostream>

using namespace std;

template <typename T>
class List {
    class Node {
        T value;
        Node* next;
        Node* prev;

        Node(T val) : value(val), next(nullptr), prev(nullptr) {}
    };

    int size;
    Node* head;
    Node* tail;

public:
    //1. без параметров
    
};
int main()
{
    std::cout << "Hello World!\n";
}
