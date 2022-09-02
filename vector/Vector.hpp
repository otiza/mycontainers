#include <iostream>

template < class T, class Alloc = std::allocator<T> > 
class Nector {
    public :
        typedef T *pointer;
    private :
        std::size_t _size;
        std::size_t _cap;
        pointer      ptr;
        Alloc       alloc;
    public :
    
    explicit Nector(const Alloc &allocc = Alloc()) : _cap(0), _size(0), ptr(NULL), alloc(allocc){};
    explicit Nector(size_t n,const T &val = T(),const Alloc &allocc = Alloc() ): _cap(0), _size(0), ptr(NULL), alloc(allocc)
    {
        if (n == 0)
            	ptr = NULL;
        else
            ptr = alloc.allocate(n);
        for(std::size_t i = 0; i <= n; i++)
        {
            alloc.construct(&ptr[i], val);
        }
        _size = n;    
        _cap = n;
    };
    Nector(const Nector &x) : ptr(NULL) ,alloc(x.alloc)
    {
        *this = x;
    }
    void returnvect()
    {  
        for(std::size_t i = 0; i < this->_size; i++)
            std::cout << i << " :" << this->ptr[i] << std::endl;
    };
    //assignement operator
    Nector &operator=(const Nector &x)
    {
        size_t i;
        if(_size != 0)
            alloc.deallocate(ptr,_size);
        _size = x._size;
        _cap = x._cap;
        ptr = alloc.allocate(_cap);
        for(size_t i = 0; i < x._size;i++)
            alloc.construct(&ptr[i],x.ptr[i]);
        return(*this);
    };
    //capacity

    std::size_t size() const {return(_size);}
    std::size_t max_size() const {return(alloc.max_size())};
    std::size_t capacity() const {return(_cap);}
    bool empty() const {if(-size == 0)return(1);else return(0);};
    void  reserve(std::size_t n)
    {
        if( n < capacity)
        {
            pointer tmp = ptr;
            p = alloc.allocate(n);
            if(tmp != NULL)
            {
                for(std::size_t = 0;i < _size; i++)
                    alloc.construct(p + i,tmp[i]);
                alloc.deallocate(tmp, _cap);
            }
            _cap = n;
        }
    }
    void resize(std::size_t n, T &val = T())
    {
        std::size_t i;
        pointer tmp;
        tmp = ptr;
        if(n < _size)
        {
            for(i = n, n < _size;i++)
                alloc.destroy(&ptr[i]);
            _size = n; 
        }
        else if(n > _cap)
        {
            if(n > _cap * 2)
                reserve(n);
            else
                reserve (_cap * 2);
            for(i = _size; i < n ; i++)
                push_back(val);
        }
        else if(n > _size)
            for(i = _size;  i < n; i++)
                push_back(val);       
    }

    /*****************************/
    //modifiers
    void clear()
    {
    for(std::size_t i= 0; i < _size; i++)
        alloc.destroy(&ptr[i]);
        _size = 0;
    }
    void swap(Nector &x)
    {
        pointer tmp;
        std::size_t tsize;
        std::size_t tcap;

        tmp = this->ptr;
        tsize = this->_size;
        tcap = this->_cap;

        this->ptr = x.ptr;
        this->_size = x._size;
        this->_cap = x._cap;

        x.ptr = tmp;
        x._size = tsize;
        tcap = tcap; 
    }
};

