#pragma once
#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "../iterator_traits.hpp" 
namespace ft{
    template<class T>
    class iterator{
        public :
            typedef T value_type;
            typedef std::ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef std::random_access_iterator_tag iterator_category;
        private :
            pointer ptr;

        public :
            iterator() : ptr(NULL) {}
            iterator(pointer pt) : ptr(pt) {}
            ~iterator(){}
            iterator(const iterator& cp){*this = cp;}
            iterator &operator=(const iterator &x)
            {
                this->ptr = x.ptr;
                return(*this);
            }
            iterator &operator++()
            {
                this->ptr++;
                return(*this);
            }
            iterator &operator--()
            {
                this->ptr--;
                return(*this);
            }
            iterator operator++(int)
            {
                iterator tmp(*this);
                this->ptr++;
                return(tmp);
            }
            iterator operator--(int)
            {
                iterator tmp(*this);
                this->ptr--;
                return(tmp);
            }
            iterator operator+=(difference_type i)
            {
                this->ptr += i;
                return(*this);
            }
            iterator operator-=(difference_type i)
            {
                this->ptr -= i;
                return(*this);
            }
            iterator operator+(difference_type i) const{return(this->ptr + i);}
            iterator operator-(difference_type i) const{return(this->ptr - i);}
            reference operator*() const{return(*(this->ptr));}
            pointer operator->() const{return this->ptr;}
            reference operator[](int i) const{return this->ptr[i];}
            template <class Iter>
            bool operator< (const iterator<Iter>& X){return (this->ptr < (X.ptr));}
            template <class Iter>
            bool operator== (const iterator<Iter>& X){return (this->ptr == (X.ptr));}
            template <class Iter>
            bool operator<= (const iterator<Iter>& X){return (this->ptr <= (X.ptr));}
            template <class Iter>
            bool operator>= (const iterator<Iter>& X){return (this->ptr >= (X.ptr));}
            template <class Iter>
            bool operator> (const iterator<Iter>& X){return (this->ptr > (X.ptr));}
            template <class Iter>
            bool operator!= (const iterator<Iter>& X){return (this->ptr != (X.ptr));}
    };
}
#endif