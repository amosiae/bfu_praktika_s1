#include <iostream>
 
class Byte {
    int length = 2, bits = 3;
    unsigned char byte = 0;
 
public:
 
    void set_number(int pos, int n) {
        if ((n < 0) || (n > pow(2, bits))) return;
        if ((pos < 0) || (pos > length)) return;
 
        unsigned char update = n << (pos * bits);
        unsigned char clear = 7 << (pos * bits);
        byte = byte & (~clear);
        byte = byte | update; 
    }
 
    unsigned int get_number(int pos) {
        unsigned char clear = 7 << (pos * bits);
        unsigned char number = byte & clear;
        if (pos > 0)
        number = byte >> (pos * bits);
        return number;
    }
};
 
int main()
{
    Byte byte;
    byte.set_number(0, 4);
    byte.set_number(1, 1);
    std::cout << byte.get_number(0) << std::endl;
    std::cout << byte.get_number(1) << std::endl;
}