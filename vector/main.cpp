#include "./Vector.hpp"
#include <vector>

#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
using namespace std;


    int main()
    {
         std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::Vector<std::string>::size_type s, ft_s;
        ft::Vector<std::string>::size_type c, ft_c;
            std::vector<std::string> v(200, "hello");
            ft::Vector<std::string> ft_v(200, "hello");
            
            ft_s = ft_v.capacity();
            v.clear();
            s = v.capacity();
            
            ft_v.clear();

   
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
                         std::cout <<"soio "<< s<< std::endl;
            std::cout <<"s "<< ft_s<< std::endl;

           
    }
