#include <iostream>
 
 
class Array {
public:
    int* numbers;
    int numbers_len;
 
    Array() {
        numbers = new int;
        numbers_len = 0;
    }
 
    ~Array() {
        delete[] numbers;
    }
 
    void append(int n) {
        numbers_len++;
        int* new_numbers = new int[numbers_len];
 
        for (int i = 0; i < numbers_len - 1; i++) {
            new_numbers[i] = numbers[i];
        }
        new_numbers[numbers_len - 1] = n;
        delete[] numbers;
        numbers = new_numbers;
 
    }
 
    int len() {
        return numbers_len;
    }
 
    int by_index(int ind) {
        return numbers[ind];
    }
 
    void update(int pos, int n) {
        numbers[pos] = n;
    }
 
    void delete_element(int ind) {
        for (int i = ind; i < numbers_len - 1; i++) {
            numbers[i] = numbers[i + 1];
        }
 
        numbers_len--;
        int* new_numbers = new int[numbers_len];
 
        for (int i = 0; i < numbers_len - 1; i++) {
            new_numbers[i] = numbers[i];
        }
        delete[] numbers;
        numbers = new_numbers;
    }
 
    void insert(int pos, int n) {
        append(numbers[numbers_len - 1]);
        for (int i=numbers_len - 2; i >= pos; i--) {
            numbers[i + 1] = numbers[i];
        }
        numbers[pos] = n;
    }
 
    void print() {
        for (int el = 0; el < numbers_len; el++) {
            std::cout << numbers[el] << ' ';
        }
    }
};
 
 
int main()
{
    Array arr;
    arr.append(1);
    for (int i = 2; i <= 10; i++) {
        arr.append(i);
        arr.print();
        std::cout << std::endl;
    }
}
 
 