#ifndef TESTER_HPP
# define TESTER_HPP

# include <iostream>
# include <string>

# define NORMAL "\033[0;37m"
# define UNDERLINE "\033[4m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"

bool printBoolResult(bool stl_bool, bool ft_bool);

template <class T>
std::string equal(const T& t1, const T& t2)
{
    return (t1 == t2 ? "✔" : "✘");
}

template <class T>
bool equalbool(const T& t1, const T& t2)
{
    return (t1 == t2 ? true : false);
}

template<class T>
static bool printSingleValue(const T& t1, const T& t2)
{
    std::cout << "\n══════════════════════════════════════════════════════════════\n";
    std::cout << "Value from :\n";
    std::cout << "STL    : " << t1 << "\n";
    std::cout << "FT  [" << equal(t1, t2) << "]: " << t2 << "\n";
    std::cout << "══════════════════════════════════════════════════════════════\n";
    return (t1 == t2 ? true : false);
}

#endif
