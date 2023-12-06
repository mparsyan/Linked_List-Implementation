#include "linked_list.hpp"
#include <iostream>

int main() 
{
    // Create an instance of LinkedList
    LinkedList<int> list;

    // Test push_back and push_front
    list.push_back(10);
    list.push_front(5);

    // Test insert
    list.insert(1, 7);  // List is now [5, 7, 10]
    std::cout << "List after insertions: ";
    list.print_list();

    // Test erase
    list.erase(1);  // List is now [5, 10]
    std::cout << "List after erase: ";
    list.print_list();

    // Test front and back
    std::cout << "Front element: " << list.front() << "\n";
    std::cout << "Back element: " << list.back() << "\n";

    // Test size and empty
    std::cout << "List size: " << list.size() << "\n";
    std::cout << "Is list empty? " << (list.empty() ? "Yes" : "No") << "\n";

    // Test pop_back and pop_front
    list.pop_back();
    list.pop_front();  // List should be empty now
    std::cout << "List after pop operations: ";
    list.print_list();

    // Test clear
    list.clear();

    // Repopulate list for further tests
    list.push_back(3);
    list.push_back(1);
    list.push_back(4);

    // Test resize
    list.resize(5);  // Resize to 5 elements, additional elements initialized to 0
    std::cout << "List after resize: ";
    list.print_list();

    // Test reverse
    list.reverse();
    std::cout << "List after reverse: ";
    list.print_list();

    // Test sort
    list.sort();
    std::cout << "List after sort: ";
    list.print_list();

    // Copy constructor
    LinkedList<int> list2 = list;
    std::cout << "List2 (copy of list): ";
    list2.print_list();

    // Move constructor
    LinkedList<int> list3 = std::move(list);
    std::cout << "List3 (moved from list): ";
    list3.print_list();
    std::cout << "Original list (after move): ";
    list.print_list();

    // Assignment operators
    list = list2;
    std::cout << "List (after assignment from list2): ";
    list.print_list();
    LinkedList<int> list4;
    list4 = std::move(list3);
    std::cout << "List4 (moved from list3): ";
    list4.print_list();

    //Test comparison operators
    if (list == list4) 
    {
        std::cout << "List and List4 are equal\n";
    } 
    else 
    {
        std::cout << "List and List4 are not equal\n";
    }

    return 0;
}
