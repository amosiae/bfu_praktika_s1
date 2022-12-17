#include <iostream>
 
const int n_len = 100;
 
void print_n(int n[n_len]) {
    int c = 0;
    while (n[c] == 0) {
        c++;
    }
    for (int i = c; i < n_len; i++) {
        std::cout << n[i];
    }
}
 
void clear(int n[n_len]) {
    for (int i = n_len - 1; i >= 1; i--) {
        n[i - 1] += n[i] / 10;
        n[i] = n[i] % 10;
    }
}
 
int* sum(int n1[n_len], int n2[n_len]) {
    int *res = new int[n_len];
 
    for (int i = n_len - 1; i >= 0; i--) {
        res[i] = n1[i] + n2[i];
    }
    clear(res);
    return res;
}
 
int* product(int n1[n_len], int n2[n_len]) {
    int* res = new int[n_len];
    for (int i = 0; i < n_len; i++) {
        res[i] = 0;
    }
 
    int n1_delta = 0, n2_delta = 0;
    while (n1[n1_delta] == 0) {
        n1_delta++;
    }
    while (n2[n2_delta] == 0) {
        n2_delta++;
    }
 
    for (int i = n1_delta; i < n_len; i++) {
        for (int j = n2_delta; j < n_len; j++) {
            res[n_len - (n_len - j) - (n_len - i) + 1] += n1[i] * n2[j];
        }
    }
    clear(res);
 
    return res;
}
 
int main()
{
    int numbers[2][n_len];
    for (int i = 0; i < 2; i++) {
        char n[n_len];
        std::cin >> n;
        int temp_n_len = strlen(n);
        int delta_len = n_len - temp_n_len;
        for (int j = temp_n_len - 1; j >= 0; j--) {
            numbers[i][j + delta_len] = n[j] - 48;
        }
        for (int j = 0; j < delta_len; j++) {
            numbers[i][j] = 0;
        }
    }
 
    int* res1 = sum(numbers[0], numbers[1]);
    print_n(res1);
    std::cout << std::endl;
    int* res2 = product(numbers[0], numbers[1]);
    print_n(res2);
    delete[] res1, res2;
}