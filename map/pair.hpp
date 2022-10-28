#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft{
    template<class T1, class T2> 
    class pair
    {
        private :
            typedef T1 first_type;  
            typedef T2 second_type;
        public :
            first_type first;
            second_type second;
        //MEMBER FUNCTIONS
        pair():first(), second() {}
        pair( const T1& x, const T2& y ) : first(x), second(y) {}
        template<class U, class V> 
        pair (const pair<U,V>& x) : first{x.first}, second(x.second) {}
        pair& operator= (const pair& pr)
        {
            first = pr.first;
            second = pr.second;
            return *this;
        }
    };
    //NON MEMBER
    //relational operators
    template <class T1, class T2>  
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return((lhs.first == rhs.first)&&(lhs.second = rhs.second));
    }

    template <class T1, class T2>  
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
        return(!(lhs == rhs));
    }
    template <class T1, class T2>  
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
    }

    template <class T1, class T2>  
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return((lhs < rhs) || (lhs == rhs));
    }
    template <class T1, class T2>  
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return(!(lhs <= rhs));
    }

    template <class T1, class T2>  
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return(!(lhs < rhs));
    }
    template <class T1, class T2>  
    pair<T1,T2> make_pair (T1 x, T2 y) {return pair<T1,T2>(x,y);}
}
#endif