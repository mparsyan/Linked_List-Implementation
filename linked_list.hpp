#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<T>& other);
    LinkedList(LinkedList<T>&& other) noexcept;
    ~LinkedList();

public:
    LinkedList<T>& operator=(const LinkedList<T>& other);
    LinkedList<T>& operator=(LinkedList<T>&& other) noexcept;
    bool operator==(const LinkedList<T>& other);
    bool operator!=(const LinkedList<T>& other);
    bool operator<(const LinkedList<T>& other);
    bool operator<=(const LinkedList<T>& other);
    bool operator>(const LinkedList<T>& other);
    bool operator>=(const LinkedList<T>& other);

public:
    void assign(size_t count, const T& value);
    T& front();
    T& back();
    bool empty() const;
    size_t size() const;
    size_t max_size() const;
    void clear();
    void insert(size_t index, const T& value);
    void erase(size_t index);
    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    void resize(size_t new_size);
    void swap(LinkedList<T>& other);
    void reverse();
    void sort();

    void print_list();

private:
    struct Node
    {
        Node(const T& value);
        T m_value;
        Node* m_next;
    };
    
    Node* m_head;
    size_t m_size;
};

#include "linked_list_impl.hpp"

#endif  // LINKED_LIST_HPP