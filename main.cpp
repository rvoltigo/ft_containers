#include "containers/vector.hpp"
#include "containers/stack.hpp"
#include "containers/map.hpp"
#include <map>

int main()
{
    map <std::string, int> myFirstMap = {{ "Mother", 37 },
                                 { "Father", 40 },///map явно инициализирована
                                 { "Brother", 15 },
                                 { "Sister", 20 }};
                                 
    return (0);
}