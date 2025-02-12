#include <iostream>
#include <initializer_list>
#include <stdexcept>

using namespace std;

template <typename T>
class VectorType {
private:
    int cap;
    int size;
    T* data;

    class iterator {
    public:
        iterator(T* m_ptr = nullptr) : ptr(m_ptr) {}

        T& operator *() {
            return *ptr;
        }

        iterator& operator ++() {
            ++ptr;
            return *this;
        }

        iterator operator ++(int) {
            iterator tmp(*this);
            ++ptr;
            return tmp;
        }

        iterator& operator --() {
            --ptr;
            return *this;
        }

        iterator operator --(int) {
            iterator tmp(*this);
            --ptr;
            return tmp;
        }

        bool operator != (const iterator& other) const {
            return ptr != other.ptr;
        }

        bool operator == (const iterator& other) const {
            return ptr == other.ptr;
        }

    private:
        T* ptr;
    };

public:
    VectorType() : cap(1), size(0), data(new T[cap]) {}

    VectorType(int size) : cap(size * 2), size(size), data(new T[cap]) {
        for (int i = 0; i < size; i++) {
            data[i] = T();
        }
    }

    VectorType(initializer_list<T> init) : cap(init.size() * 2), size(init.size()), data(new T[cap]) {
        int i = 0;
        for (const auto& elem : init) {
            data[i++] = elem;
        }
    }

    VectorType(const VectorType& other) : cap(other.cap), size(other.size), data(new T[cap]) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~VectorType() {
        delete[] data;
    }

    VectorType& operator =(const VectorType& other) {
        if (this != &other) {
            delete[] data;
            cap = other.cap;
            size = other.size;
            data = new T[cap];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    T& operator [](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator [](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    void Append(T elem) {
        if (size == cap) {
            cap *= 2;
            T* temp = data;
            data = new T[cap];
            for (int i = 0; i < size; ++i) {
                data[i] = temp[i];
            }
            delete[] temp;
        }
        data[size++] = elem;
    }

    void Pop(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }
    //1.
    int Size() const {
        return size;
    }
    //2.
    void Clear() {
        size = 0;
    }
    //3.
    int Capacity() const {
        return cap;
    }

    iterator begin() {
        return iterator(data);
    }

    iterator end() {
        return iterator(data + size);
    }
};

int main() {
    VectorType<int> vec = { 1, 2, 3, 4, 5 };
    VectorType<int> vec2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    VectorType<int> vec3 = { 1, 2, 3 };

    int value;
    cout << "Add element: ";
    cin >> value;
    vec3.Append(value);

    cout << "Elements in vec3: ";
    for (auto it = vec3.begin(); it != vec3.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Element at index 3: " << vec3[3] << endl; 
    cout << "Size: " << vec3.Size() << endl;
    cout << "Capacity: " << vec3.Capacity() << endl;

    int pop_value;
    cout << "Erase element (index): ";
    cin >> pop_value;
    vec3.Pop(pop_value);

    cout << "Elements in vec3: ";
    for (auto it = vec3.begin(); it != vec3.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    vec3.Clear();
    cout << "After clear: ";
    for (auto it = vec3.begin(); it != vec3.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}