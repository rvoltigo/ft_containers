#include <iostream>
#include "head.hpp"



int main()
{
    std::cout<< std::endl << "===================================CONSTRUCTORS===================================" << std::endl;;
    map_constr();
    std::cin.ignore();

    std::cout<< std::endl << "===================================ASSIGN===================================" << std::endl;;
    map_assign();
    std::cin.ignore();

    std::cout<< std::endl << "===================================BEGINS===================================" << std::endl;;
    map_begins();
    std::cin.ignore();

    std::cout<< std::endl << "===================================ENDS===================================" << std::endl;;
    map_ends();
    std::cin.ignore();

    std::cout<< std::endl << "===================================REVERSES===================================" << std::endl;;
    map_reverses();
    std::cin.ignore();

    std::cout<< std::endl << "===================================REVERSES_END===================================" << std::endl;;
    map_reverses_end();
    std::cin.ignore();

    std::cout<< std::endl << "===================================EMPTY===================================" << std::endl;;
    map_empty();
    std::cin.ignore();

    std::cout<< std::endl << "===================================SIZE===================================" << std::endl;;
    map_size();
    std::cin.ignore();

    std::cout<< std::endl << "===================================OPERATORS===================================" << std::endl;;
    map_operators();
    std::cin.ignore();
    
    std::cout<< std::endl << "===================================INSERTS===================================" << std::endl;;
    map_inserts();
    std::cin.ignore();

    std::cout<< std::endl << "===================================ERASE===================================" << std::endl;;
    map_erase();
    std::cin.ignore();
    
    std::cout<< std::endl << "===================================SWAP===================================" << std::endl;;
    map_swap();
    std::cin.ignore();

    std::cout<< std::endl << "===================================CLEAR===================================" << std::endl;;
    map_clear();
    std::cin.ignore();

    std::cout<< std::endl << "===================================KEY_COMP===================================" << std::endl;;
    map_key_comp();
    std::cin.ignore();

    std::cout<< std::endl << "===================================VALUE_COMP===================================" << std::endl;;
    map_value_comp();
    std::cin.ignore();
    
    std::cout<< std::endl << "===================================FIND_EXIST===================================" << std::endl;;
    map_find_exist();
    std::cin.ignore();

    std::cout<< std::endl << "===================================NOT_EXIST===================================" << std::endl;;
    map_not_exist();
    std::cin.ignore();

    std::cout<< std::endl << "===================================IF_FIND===================================" << std::endl;;
    map_const_if_Find();
    std::cin.ignore();

    std::cout<< std::endl << "===================================COUNT===================================" << std::endl;;
    map_count();
    std::cin.ignore();

    std::cout<< std::endl << "===================================LOWER_BOUND===================================" << std::endl;;
    map_lower_bound();
    std::cin.ignore();

    std::cout<< std::endl << "===================================UPPER_BOUND===================================" << std::endl;;
    map_upper_bound();
    std::cin.ignore();

    std::cout<< std::endl << "===================================EQUAL_RANGE===================================" << std::endl;;
    map_equal_range();
    return (0);
}