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
    ft::Vector<int>::iterator l = B.end();
    
    //ft::Vector<int>::reverse_iterator it = B.rend();
    //it--;
    std::cout << "kolijsdjkk"<< std::endl;
 
    //std::cout << *it << "  kk"<< std::endl;
    //while(it != B.rbegin())
    //{
    B.insert(l, 15);
    //std::cout << *it <<"dd"<< std::endl;
    //it--;
    
    //}
    ////std::cout << B.capacity()<< std::endl;
    //B.returnvect();

    std::cout << B  << std::endl;
 
    //B.pop_back();
    //B.returnvect();
    
     
    
    //B.push_back(5);
    //B.push_back(4);
   

 return(12);
   
}