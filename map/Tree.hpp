#pragma once
#ifndef TREE_HPP
#define TREE_HPP
namespace ft
{
    template <typename pair>
    class node
    {
        public:
        node<pair> *left;
        node<pair> *right;
        node<pair> *right;
        pair *data;
        int height; int threshold;
    } ;
    template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
    > 
    class Tree
    {
        public :
        typedef Key key_type;
        typedef T   mapped_type;
        typedef typename ft::pair<const Key, T> value_type;
        typedef std::less<key_type> key_compare;
        typedef allocator<value_type> allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef node<value_type> *root;    
        typedef std::ptrdiff_t difference_type;
        typedef std::size_t size_type;
        private:
            key_compare comp;
            size_type _size;
            allocator_type alloc;
            node_alloc  

        
    }
}
#endif