#pragma once
#include "../iterator_traits.hpp" 
#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
namespace ft{
template< class Iter >
class reverse_iterator{
    public:
        typedef Iter iterator_type;
        typedef typename iterator_traits<Iter>::iterator_category iterator_category;
        typedef typename iterator_traits<Iter>::value_type value_type;
        typedef typename iterator_traits<Iter>::difference_type difference_type;
        typedef typename iterator_traits<Iter>::pointer pointer;
        typedef typename iterator_traits<Iter>::reference reference;
    protected:
        iterator_type current;
    public:
    reverse_iterator(): current(NULL){}
    explicit reverse_iterator(iterator_type It): current(It){}
    template< class U >
    reverse_iterator& operator=( const reverse_iterator<U>& other)
    {
        this->current = other.base();
        return (*this);
    }
    iterator_type base() const  {return(current);}
    //accessing
    reference operator*() const
    {
        Iter tmp = current;
        return *(--tmp);
    }
    pointer operator->() const
    {
        return &(this->operator*());
    }
    reference operator[]( difference_type n ) const
    {
        return *(current - n - 1);
    }
    reverse_iterator& operator++()
    {
        current--;
        return *this;
    }
    reverse_iterator operator++( int )
    {
        reverse_iterator tmp = *this;
        current--;
        return tmp;
    }
    reverse_iterator& operator--()
    {
        current++;
        return *this;
    }
    reverse_iterator operator--( int )
    {
        reverse_iterator tmp = *this;
        current++;
        return tmp;
    }
    reverse_iterator operator+( difference_type n ) const
    {
        return(reverse_iterator(current - n));
    }
    reverse_iterator operator-( difference_type n ) const
    {
        return(reverse_iterator(current + n));
    }
    reverse_iterator& operator+=( difference_type n )
    {
        current -= n;
        return *this;
    }
    reverse_iterator& operator-=( difference_type n )
    {
        current += n;
        return *this;
    }
    
    //template< class U >
    //reverse_iterator( const reverse_iterator<U>& other ) current(other.base())
    //base here


    };
    template< class Iterator1, class Iterator2 >
    bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() == rhs.base();
    }
    template< class Iterator1, class Iterator2 >
    bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return ( !(lhs.base() == rhs.base()) );
    }
    template< class Iterator1, class Iterator2 >
    bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (lhs.base() > rhs.base());
    } 
    template< class Iterator1, class Iterator2 > 
    bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (lhs.base() >= rhs.base());
    }
    template< class Iterator1, class Iterator2 >
    bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (lhs.base() < rhs.base());
    }
    template< class Iterator1, class Iterator2 >
    bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs )
    {
        return (lhs.base() <= rhs.base());
    }  
    template< class Iter >
    reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n,const reverse_iterator<Iter>& it ) {return(it + n);}
    template< class Iterator >
    typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs ){return (rhs.base() - lhs.base());}
    template< class Iter >
    typename iterator_traits<Iter>::difference_type distance( Iter fst, Iter lst )
    {
        typename iterator_traits<Iter>::difference_type ret = 0;
        while(fst != lst)
        {
            fst++;
            ret++;
        }
        return ret;
    }
}


#endif