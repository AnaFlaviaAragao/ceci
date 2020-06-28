#include "soma_1_gm.hpp"

#include <iostream>

int somador(int a, int b, int ci, int *co)
{
    *co = (a and b) or (b and ci) or (a and ci);
    return a xor b xor ci;
}

int main()
{

    int cout = 0;
    int a = 1, b = 1, cin = 1;

    int result = somador(a, b, cin, &cout);

    std::cout << result << " " << cout << std::endl;
}