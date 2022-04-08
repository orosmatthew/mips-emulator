#include <iostream>

#include "circuits.hpp"

int main()
{

    bin_val val = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    bin_val val_ext;
    sign_ext(&val_ext, &val[16]);

    std::cout << (int)mux_2to1(1, 1, 1) << std::endl;
    return 0;
}
