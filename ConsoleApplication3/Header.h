
#pragma once
#include <iostream>
#include <random>
#include <cmath>
#include <typeinfo>

template <class T>
class ObjectMass;

template <class T>
std::ostream& operator<<(std::ostream& os, const ObjectMass<T>& obj);

template <class T>
std::istream& operator>>(std::istream& is, ObjectMass<T>& obj);

template <class T>
class ObjectMass
{
private:
    T* massiv;
    int len;

   

public:
    ObjectMass() : massiv(nullptr), len(0) {}
    ObjectMass(T* input_massiv, int input_len) : massiv(input_massiv), len(input_len) {}
    T randomInRange(T min, T max) {
        std::random_device rd;
        std::mt19937 gen(rd());

        if constexpr (std::is_same_v<T, char>) {
            std::uniform_int_distribution<int> distribution(static_cast<int>(min), static_cast<int>(max));
            return static_cast<char>(distribution(gen));
        }
        else if constexpr (std::is_same_v<T, float>) {
            std::uniform_real_distribution<T> distribution(min, max);
            return distribution(gen);
        }
        else {
            std::uniform_int_distribution<T> distribution(min, max);
            return distribution(gen);
        }
    }

    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    int partition(T* arr, int low, int high) {
        T pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(T* arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    int getLen() const {
        return len;
    }

    T* getArray() const {
        return massiv;
    }

    void createMassiv(int size) {
        massiv = new T[size];
        if constexpr (std::is_same_v<T, char>) {
            for (int i = 0; i < size; i++) {
                massiv[i] = randomInRange('A', 'Z');
            }
        }
        else if constexpr (std::is_same_v<T, float>) {
            for (int i = 0; i < size; i++) {
                massiv[i] = randomInRange(0.0f, 100.0f);
            }
        }
        else {
            for (int i = 0; i < size; i++) {
                massiv[i] = randomInRange(static_cast<T>(1), static_cast<T>(100));
            }
        }
        len = size;
    }

    void updateMassiv(const T& object) {
        int newLen = getLen();
        T* newMass = new T[newLen + 1];
        for (int i = 0; i < newLen; i++) {
            newMass[i] = massiv[i];
        }
        newMass[newLen] = object;
        len = newLen + 1;
        delete[] massiv;
        massiv = newMass;
    }

    void deleteByNum(int number) {
        if (number >= 0 && number < len) {
            for (int i = number; i < len - 1; i++) {
                massiv[i] = massiv[i + 1];
            }
            len--;
        }
    }

    void deleteByEl(const T& element) {
        for (int i = 0; i < len; i++) {
            if (massiv[i] == element) {
                deleteByNum(i);
                return;
            }
        }
    }

    void sortedMass() {
        quickSort(massiv, 0, len - 1);
    }

    T& operator[](int index) {
        if (index >= 0 && index < len) {
            return massiv[index];
        }
        else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    const T& operator[](int index) const {
        if (index >= 0 && index < len) {
            return massiv[index];
        }
        else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    ObjectMass<T>& operator=(const ObjectMass<T>& other) {
        if (this == &other) {
            return *this;
        }
        delete[] massiv;
        len = other.len;
        massiv = new T[len];
        std::copy(other.massiv, other.massiv + len, massiv);
        return *this;
    }

    bool operator==(const ObjectMass<T>& other) const {
        if (len != other.len) {
            return false;
        }
        for (int i = 0; i < len; ++i) {
            if (massiv[i] != other.massiv[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const ObjectMass<T>& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<< <>(std::ostream& os, const ObjectMass<T>& obj);
    friend std::istream& operator>> <>(std::istream& is, ObjectMass<T>& obj);

    ~ObjectMass() {
        delete[] massiv;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const ObjectMass<T>& obj) {
    os << "[";
    for (int i = 0; i < obj.len; ++i) {
        os << obj.massiv[i];
        if (i < obj.len - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, ObjectMass<T>& obj) {
    std::cout << "ввидите длинну: ";
    int length;
    is >> length;
    obj.createMassiv(length);
    std::cout << "ввидите " << length << " элементы: ";
    for (int i = 0; i < length; ++i) {
        is >> obj.massiv[i];
    }
    return is;
}
