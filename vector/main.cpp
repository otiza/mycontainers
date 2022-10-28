#include "./Vector.hpp"

int main()
{

    //Nector<int> A(5,4);
    ft::Vector<int> B;
    
    ///std::cout << B.capacity()<< std::endl;
    B.push_back(1);
    B.push_back(2);
    B.push_back(3);
    B.push_back(4);
    B.push_back(5);
    B.push_back(6);
    ft::Vector<int> C(B);
    
    ft::Vector<int>::reverse_iterator it = B.rend();
    it--;
    std::cout << "kolijsdjkk"<< std::endl;
    int l = 0;
    std::cout << *it << "  kk"<< std::endl;
    while(it != B.rbegin())
    {
//
    std::cout << *it <<"dd"<< std::endl;
    it--;
    
    }
    ////std::cout << B.capacity()<< std::endl;
    //B.returnvect();

    std::cout << B  << std::endl;
 
    //B.pop_back();
    //B.returnvect();
    
     
    
    //B.push_back(5);
    //B.push_back(4);
   

 return(12);
   
}