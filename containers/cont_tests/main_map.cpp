#include <iostream>
#include "head.hpp"
int main()
{
    map_constr();
    std::cin.ignore();

    map_assign();
    std::cin.ignore();

    map_begins();
    std::cin.ignore();

    map_ends();
    std::cin.ignore();

    map_reverses();
    std::cin.ignore();

    map_reverses_end();
    std::cin.ignore();

    map_empty();
    std::cin.ignore();

    map_size();
    std::cin.ignore();

    map_operators();
    std::cin.ignore();
    
    map_inserts();
    std::cin.ignore();

    map_erase();
    std::cin.ignore();
    
    map_swap();
    std::cin.ignore();

    map_clear();
    std::cin.ignore();

    map_key_comp();
    std::cin.ignore();

    map_value_comp();
    std::cin.ignore();
    
    map_find_exist();
    std::cin.ignore();

    map_not_exist();
    std::cin.ignore();

    map_const_if_Find();
    std::cin.ignore();

    map_count();
    std::cin.ignore();

    map_lower_bound();
    std::cin.ignore();

    map_upper_bound();
    std::cin.ignore();

    map_equal_range();
    std::cout << "End!!!";
    return (0);
}