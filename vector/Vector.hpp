#pragma once
#include <iostream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "../iterator_traits.hpp"
namespace ft
{
    template < class T, class Alloc = std::allocator<T> > 
    class Vector {
        public :
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference &reference;
            typedef const typename  allocator_type::const_reference &const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef ft::iterator<value_type> iterator;
            typedef ft::iterator<const value_type> const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef std::size_t size_type;
        private :
            size_type _size;
            size_type _cap;
            pointer      ptr;
            allocator_type       alloc;
        public :
        //MEMBER functions
        ~Vector()
        {
            if(_size > 0)
                alloc.deallocate(ptr, _size);
        }

        explicit Vector(const allocator_type &allocc = Alloc()) : _size(0), _cap(0), ptr(NULL), alloc(allocc){};
        explicit Vector(size_t n,const value_type &val = value_type(),const allocator_type &allocc = Alloc() ):/*Vector()*/ _size(0), _cap(0), ptr(NULL), alloc(allocc)
        { 
            if (n > 0)
                ptr = alloc.allocate(n);
            for(size_type i = 0; i < n ; i++)
                alloc.construct(&ptr[i], val);
            _size = n;    
            _cap = n;
        }

        template <class InputIterator>
        Vector(InputIterator fst, InputIterator lst, const allocator_type &allocc = Alloc()): _cap(0), _size(0), ptr(NULL), alloc(allocc)
        {
            reserve(lst - fst);
            for(;fst != lst; fst++)
                alloc.construct(&ptr[_size++], *fst);
        }
        Vector(const Vector &x) : ptr(NULL) ,alloc(x.alloc)
        {
            *this = x;
        }

        Vector& operator=(const Vector& x)
        {
            if(_size != 0)
                alloc.deallocate(ptr,_size);
            _size = x._size;
            _cap = x._cap;
            ptr = alloc.allocate(_cap);
            for(size_t i = 0; i < x._size;i++)
                alloc.construct(&ptr[i],x.ptr[i]);
            return(*this);
        }

        void assign(size_type n, const value_type &x)
        {
            if(n > _cap)
            {
                alloc.deallocate(ptr, _cap);
                ptr = alloc.allocate(n);
                _cap = n;
            }
            for (size_type i= 0; i < n ; i++)
                    alloc.construct(&ptr[i], x);
            _size = n;
        }

        template <class InputIterator>
        void assign(InputIterator fst, InputIterator lst)
        {
            size_type n = lst - fst;
            if ( n > _cap)
            {
                alloc.deallocate(ptr , _cap);
                ptr = alloc.allocate(n);
                _cap = n;
            }
            for(size_type i = 0; i < n; i++)
                alloc.construct(&ptr[i], *fst++);
            _size = n;
        }

        allocator_type get_allocator() const
        {
            return (alloc);
        }

        //accessing elements

        reference at(size_type i)
        {
            if ( i >= _size)
                throw std::out_of_range("Vector");
            return(ptr[i]);
        }
        const_reference at(size_type i) const
        {
            if ( i >= _size)
                throw std::out_of_range("Vector");
            return(ptr[i]);
        }
        reference operator[](size_type n) {return(ptr[n]);}
        const_reference operator[](size_type n) const {return (ptr[n]);}
        reference front() { return (ptr[0]);}
        const_reference front() const { return (ptr[0]);}
        reference back() { return (ptr[_size - 1]);}
        const_reference back() const { return (ptr[_size - 1]);}
        
        //iteration

        iterator begin() { return iterator(ptr); }
        iterator end() { return iterator(ptr + _size); }
        const_iterator begin() const { return const_iterator(ptr); }
        const_iterator end() const { return const_iterator(ptr + _size); }
        reverse_iterator rbegin() { return (reverse_iterator(this->end())); }
        reverse_iterator rend() { return (reverse_iterator(this->begin())); }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
        const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }
        
        //capacity
        bool empty() const { return(_size == 0); }
        size_type size() const { return(_size); }
        size_type max_size() const { return(alloc.max_size()); }
        size_type capacity() const { return(_cap); }
        
        void  reserve(size_type n)
        {
            if(n > _cap)
            {
                pointer tmp = ptr;
                ptr = alloc.allocate(n);
                if(tmp != NULL)
                {
                    for(size_type i = 0; i < _size; i++)
                    {
                        alloc.construct(ptr + i,tmp[i]);
                    }
                    alloc.deallocate(tmp, _cap);
                }
                _cap = n;
            }
        }



        /*****************************/
        //modifiers
        void clear()
        {
            for(size_type i= 0; i < _size; i++)
            {
                alloc.destroy(&ptr[i]);
            }
            _size = 0;
        }

        void resize(size_type n, value_type val = value_type())
        {
            size_type i;
            if(n < _size)
            {
                for(i = n; i < _size;i++)
                    alloc.destroy(&ptr[i]);
                _size = n; 
            }
            else if(n > _cap)
            {
                reserve((n > _cap * 2) * n + !(n > _cap * 2) * (_cap * 2));
                for(i = _size; i < n ; i++)
                    push_back(val);
            }
            else if(n > _size)
                for(i = _size;  i < n; i++)
                    push_back(val);       
        }

        void swap(Vector &x)
        {
            pointer tmp;
            size_type tsize;
            size_type tcap;

            tmp = this->ptr;
            tsize = this->_size;
            tcap = this->_cap;

            this->ptr = x.ptr;
            this->_size = x._size;
            this->_cap = x._cap;

            x.ptr = tmp;
            x._size = tsize;
            x._cap = tcap; 
        }

        void push_back(const value_type &val)
        {
            if(_size == 0)
                reserve(1);
            else if( _size == _cap)
                reserve(_cap * 2);
            alloc.construct(ptr + _size , val);
            _size++;
        }

        void pop_back()
        {
            alloc.destroy(&ptr[_size - 1]);
            _size--;
        }

        iterator insert( iterator pos, const T& value )
        {
            difference_type posx = distance(this->begin(),pos);
            difference_type l = 0;
            pointer tmp = ptr;
            if(_size + 1 > _cap)
            {
                _cap *= 2;
            }
            ptr = alloc.allocate(_cap);
            for(difference_type i = 0; i < _size + 1 ; i++)
            {
                if(i != posx)
                {
                    alloc.construct(ptr + i,tmp[l]);
                    l++;
                }
                else
                {
                    alloc.construct(ptr + i,value);
                }
            }
            alloc.deallocate(tmp, _cap);
            _size++;
            return iterator(ptr);
        }
    };
    template <typename T>
    std::ostream &operator<<(std::ostream &o,const Vector<T> &p)
    {
        for(size_t i = 0;i < p.size();i++)
            o << p[i] << " ";
            return(o);
    }
    template< class T, class Alloc >
    void swap( Vector<T,Alloc>& lhs,Vector<T,Alloc>& rhs)
    {
        lhs.swap(rhs);
    }

template< class T, class Alloc >
bool operator==( const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs )
{
    if(lhs.size() != rhs.size())
        return false;
    size_t i = 0;
    for(;i < rhs.size();i++)
    {
        if(lhs[i] != rhs[i])
            break;
    }
    if(i != rhs.size())
        return false;
    return true;
}



template< class T, class Alloc >
bool operator!=( const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs )
{
    return(!(lhs == rhs));
}

template< class T, class Alloc >
bool operator>( const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs )
{
    if(lhs.size() > rhs.size())
        return true;
    else if (lhs.size() < rhs.size())
        return false;
    for(size_t i = 0 ; i < rhs.size(); i++)
    {
            if(lhs[i] > rhs[i])
                return true;
            else if(lhs[i] < rhs[i])
                return false;
    }
    return false;
}

template< class T, class Alloc >
bool operator<=( const Vector<T,Alloc>& lhs,  const Vector<T,Alloc>& rhs )
{   return(!(lhs > rhs));}

template< class T, class Alloc >
bool operator<( const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs )
{
    return(rhs > lhs);
}

template< class T, class Alloc >
bool operator>=( const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs )
{
    return((lhs > rhs) || (rhs == lhs));
}



}