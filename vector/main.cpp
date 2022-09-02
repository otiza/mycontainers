#include "./Vector.hpp"

int main()
{
    Nector<int> A(5,4);
    Nector<int> B(9,3);
    Nector<int> C;
    C = B;
    C.returnvect();
    C.swap(A);
    C.returnvect();
}