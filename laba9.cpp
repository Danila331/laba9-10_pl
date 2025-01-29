#include <iostream>

template <typename T>
T sumArray(const T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum = sum + arr[i];
    }
    return sum;
}

class Number {
    public:
        int value;
        Number() : value(0) {}

        Number(int v) : value(v) {}
        // Ну а тут я перегрузил оператор + для сложения двух объектов класса Number
        Number operator+(const Number& other) {
            return Number(value + other.value);
        }

    // Вот тут я перезагрузил оператор << для вывода на экран, потому что без него не работает ))
    friend std::ostream& operator<<(std::ostream& os, const Number& number) {
        os << number.value;
        return os;
    }
};

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    Number arr[] = {1, 2, 3, 4, 5};
    std::cout << "Sum of number array: " << sumArray(arr, 5) << '\n';
    std::cout << "Sum of int array: " << sumArray(intArr, 5) << '\n';
    std::cout << "Sum of double array: " << sumArray(doubleArr, 5) << '\n';

    return 0;
}
