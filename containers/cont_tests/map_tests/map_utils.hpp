#ifndef MAP_UTILS_HPP
#define MAP_UTILS_HPP

#include "../test.hpp"
#include "../../map.hpp"
#include <map>




template <class Ta, class Tb>
std::string equalContent(
	const std::map<Ta, Tb> & stl_map,
	const ft::map<Ta, Tb> & ft_map
)
{
	typename ft::map<Ta, Tb>::const_iterator ft_it;
	typename std::map<Ta, Tb>::const_iterator stl_it;
	if (ft_map.size() != stl_map.size())
		return ("✘");
	stl_it = stl_map.begin();
	for(ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++)
	{
		if ((*ft_it).first != (*stl_it).first || (*ft_it).second != (*stl_it).second)
			return ("✘");
		stl_it++;
	}
	return ("✔");
}

template <class Ta, class Tb>
bool printMapAttributes(
	std::map<Ta, Tb>& stl_map,
	ft::map<Ta, Tb>& ft_map
)
{
	std::string stl_empty = ((stl_map.empty() == 1) ? "true" : "false");
	size_t stl_size = stl_map.size();
	size_t stl_max_size = stl_map.max_size();

	std::string ft_empty = ((ft_map.empty() == 1) ? "true" : "false");
	size_t ft_size = ft_map.size();
	size_t ft_max_size = ft_map.max_size();

	bool empty = equalbool(ft_empty, stl_empty);
	bool size = equalbool(ft_size, stl_size);
	bool max_size = equalbool(ft_max_size, stl_max_size);
	std::string content = equalContent(stl_map, ft_map);
	
	std::cout << "\n══════════════════════════════════════════════════════════════\n";
	std::cout << "maps attributes : \n";
	std::cout << "STL : \n";
	std::cout << "Empty       : " << stl_empty  << std::endl;
	std::cout << "Size        : " << stl_size  << std::endl;
	std::cout << "Max size    : " << stl_max_size  << std::endl;
	std::cout << "Content     : [";
	
	typename std::map<Ta, Tb>::const_iterator stl_it;
	for (stl_it = stl_map.begin();  stl_it != stl_map.end(); stl_it++)
	{
		std::cout << "[";
		std::cout << (*stl_it).first;
		std::cout << ", ";
		std::cout << (*stl_it).second;
		std::cout << "]";
		std::cout << ", ";
	}
	std::cout << "]\n";

	std::cout << std::endl;

	std::cout << "FT : \n";
	std::cout << "Empty    [" << equal(ft_empty, stl_empty) << "]: " << ft_empty  << std::endl;
	std::cout << "Size     [" << equal(ft_size, stl_size) << "]: " << ft_size  << std::endl;
	std::cout << "Max size [" << equal(ft_max_size, stl_max_size) << "]: " << ft_max_size  << std::endl;

	std::cout << "Content  [" << content << "]: [";

	typename ft::map<Ta, Tb>::const_iterator ft_it;
	for(ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++)
	{
		std::cout << "[";
		std::cout << (*ft_it).first;
		std::cout << ", ";
		std::cout << (*ft_it).second;
		std::cout << "]";
		std::cout << ", ";
	}
	std::cout << "]\n";

	std::cout << "══════════════════════════════════════════════════════════════\n";

	if (empty == false)
		return (false);
	else if (size == false)
		return (false);
	else if (max_size == false)
		return (false);
	else if (content == "✘")
		return (false);
	return (true);
};


void map_constr();
void map_assign();
void map_begins();
void map_ends();
void map_reverses();
void map_reverses_end();
void map_empty();
void map_size();
void map_operators();
void map_inserts();
void map_erase();
void map_swap();
void map_clear();
void map_key_comp();
void map_value_comp();
void map_find_exist();
void map_not_exist();
void map_const_if_Find();
void map_count();
void map_lower_bound();
void map_upper_bound();
void map_equal_range();

#endif