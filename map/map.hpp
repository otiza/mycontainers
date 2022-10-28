#ifndef MAP_HPP
#define MAP_HPP
namespace ft{
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class map{
    public :
        typedef Key key_type;
        typedef T   mapped_type;
        typedef typename ft::pair<const Key, T> value_type;
        typedef std::less<key_type> key_compare;
        typedef  allocator<value_type> allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        /*iteratorq*/
        typedef std::ptrdiff_t difference_type;
        typedef std::size_t size_type;

};
}
#endif