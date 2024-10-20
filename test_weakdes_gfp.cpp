#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include "weakdes_gfp.h"

int debug_level = 4;

int main()
{
    size_t m = 30;
    size_t t = 5;

    class weakdes *wd;
    wd = new weakdes_gfp;
    wd->set_params(t, m);

    long double r = wd->get_r();
    size_t m_wd = wd->get_m();
    size_t t_wd = wd->get_t();
    std::cout << "r = " << r << std::endl;
    std::cout << "m = " << m_wd << std::endl;
    std::cout << "t = " << t_wd << "\n" << std::endl;

    std::vector<uint64_t> indices;
    indices.resize(t);

    for (std::size_t i=0; i<m; ++i) {
        wd->compute_Si(i, indices);

        std::cout << "i = " << i << std::endl;
        std::cout << "[ ";
        for (std::size_t j=0; j<t; ++j) {
            std::cout << indices[j] << " ";
        }
        std::cout << "]" << "\n" << std::endl;
    }

    delete wd;
    return 0;
}
