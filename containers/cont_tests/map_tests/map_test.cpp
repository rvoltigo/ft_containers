#include "map_utils.hpp"

void map_constr()
{
    try
    {
		std::cout<< std::endl << "===================================Default constructor===================================" << std::endl;;
        std::map<int, std::string> stl_default_map;
        ft::map<int, std::string> ft_default_map;
        std::cout << ((showInfoMap(stl_default_map, ft_default_map) == true) ? "[✅]" : "[❌]");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
		std::cout<< std::endl << "===================================Range constrcutor ===================================" << std::endl;;
        const int range_int[] = {-652, -4, 98, 54, -210};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		showInfoMap(stl_map, ft_map);

		std::map<int, std::string> stl_map_copy(stl_map.begin(), stl_map.end());
		ft::map<int, std::string> ft_map_copy(ft_map.begin(), ft_map.end());

		std::cout << ((showInfoMap(stl_map_copy, ft_map_copy) == true) ? "[✅]" : "[❌]");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}

void map_assign()
{
    try
    {
		std::cout<< std::endl << "===================================map assign ===================================" << std::endl;;
        const int range_int[] = {478, 952, 12, -96, -9};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

        showInfoMap(stl_map, ft_map);

		std::map<int, std::string> stl_map_copy = stl_map;
		ft::map<int, std::string> ft_map_copy = ft_map;

		std::cout << ((showInfoMap(stl_map_copy, ft_map_copy) == true) ? "[✅]" : "[❌]");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_begins()
{
    try
    {
		std::cout<< std::endl << "===================================begin ite===================================" << std::endl;;
        const int range_int[] = {1485, 5, 89, 652, -94};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}
        showInfoMap(stl_map, ft_map);
		std::cout << "[";
		std::cout << ((showInfo((*stl_map.begin()).first, (*ft_map.begin()).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_map.begin()).second, (*ft_map.begin()).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
		std::cout<< std::endl << "===================================const begin ite===================================" << std::endl;;
        const int range_int[] = {48, 9, 12, 63, 99};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}
        showInfoMap(stl_map, ft_map);
		std::cout << "[";
		std::cout << ((showInfo((*stl_map.begin()).first, (*ft_map.begin()).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_map.begin()).second, (*ft_map.begin()).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_ends()
{
    try
    {
		std::cout<< std::endl << "===================================end ite===================================" << std::endl;;
        
        const int range_int[] = {-99, 584, 965, 366, 77};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

        std::map<int, std::string>::iterator stl_it = stl_map.end();
		ft::map<int, std::string>::iterator ft_it = ft_map.end();

		showInfoMap(stl_map, ft_map);

		--stl_it;
		--ft_it;

		std::cout << "[";
		std::cout << ((showInfo((*stl_it).first, (*ft_it).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_it).second, (*ft_it).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
		std::cout<< std::endl << "===================================const begin ite===================================" << std::endl;;
        
        const int range_int[] = {154, 966, 3, -84, 75};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		std::map<int, std::string>::const_iterator stl_it = stl_map.end();
		ft::map<int, std::string>::const_iterator ft_it = ft_map.end();

		showInfoMap(stl_map, ft_map);

        --stl_it;
		--ft_it;

		std::cout << "[";
		std::cout << ((showInfo((*stl_it).first, (*ft_it).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_it).second, (*ft_it).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_reverses()
{
    try
    {
		std::cout<< std::endl << "===================================reverse begin ite===================================" << std::endl;;
        
        const int range_int[] = {1458, -985, 58, 632, 65};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		std::map<int, std::string>::reverse_iterator stl_it = stl_map.rbegin();
		ft::map<int, std::string>::reverse_iterator ft_it = ft_map.rbegin();

		showInfoMap(stl_map, ft_map);

		++stl_it;
		++ft_it;

		std::cout << "[";
		std::cout << ((showInfo((*stl_it).first, (*ft_it).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_it).second, (*ft_it).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
		std::cout<< std::endl << "===================================const reverse begin ite===================================" << std::endl;;
        
        const int range_int[] = {859, 99, -325, -65, -98};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		std::map<int, std::string>::const_reverse_iterator stl_it = stl_map.rbegin();
		ft::map<int, std::string>::const_reverse_iterator ft_it = ft_map.rbegin();

		showInfoMap(stl_map, ft_map);

		std::cout << "[";
		std::cout << ((showInfo((*stl_it).first, (*ft_it).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_it).second, (*ft_it).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_reverses_end()
{
    try
    {
		std::cout<< std::endl << "===================================reverse end ite===================================" << std::endl;;
        
        const int range_int[] = {325, -657, -942, -8, 66};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		std::map<int, std::string>::reverse_iterator stl_it = stl_map.rend();
		ft::map<int, std::string>::reverse_iterator ft_it = ft_map.rend();

		showInfoMap(stl_map, ft_map);

		--stl_it;
		--ft_it;

		std::cout << "[";
		std::cout << ((showInfo((*stl_it).first, (*ft_it).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_it).second, (*ft_it).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //const_end
    try
    {
		std::cout<< std::endl << "===================================const reverse end ite===================================" << std::endl;;

        const int range_int[] = {-99, 584, 965, 366, 77};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		std::map<int, std::string>::const_reverse_iterator stl_it = stl_map.rend();
		ft::map<int, std::string>::const_reverse_iterator ft_it = ft_map.rend();

		showInfoMap(stl_map, ft_map);

		--(--stl_it);
		--(--ft_it);

		std::cout << "[";
		std::cout << ((showInfo((*stl_it).first, (*ft_it).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_it).second, (*ft_it).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}

void map_empty()
{
    try
    {
        std::cout<< std::endl << "===================================empty true===================================" << std::endl;;
		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		showInfoMap(stl_default_map, ft_default_map);
		std::cout << ((printBoolResult(stl_default_map.empty(), ft_default_map.empty()) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //False
    try
    {
		std::cout<< std::endl << "===================================empty false===================================" << std::endl;;
        const int range_int[] = {1452, 3651, -98, 84, 899};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		showInfoMap(stl_map, ft_map);
		std::cout << ((printBoolResult(stl_map.empty(), ft_map.empty()) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}

void map_size()
{
    try
    {
		std::cout<< std::endl << "===================================size()===================================" << std::endl;;
        const int range_int[] = {9, -84, -45, -67, -9};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		showInfoMap(stl_map, ft_map);
		std::cout << "[";
		std::cout << ((showInfo(stl_map.size(), ft_map.size()) == true) ? "[✅]" : "[❌]");

		stl_map.insert(std::make_pair(42, "Represent"));
		ft_map.insert(ft::make_pair(42, "Represent"));

		std::cout << ((showInfo(stl_map.size(), ft_map.size()) == true) ? "[✅]" : "[❌]");

		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    //max_size()
    try
    {
		std::cout<< std::endl << "===================================max_size()===================================" << std::endl;;
        std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		showInfoMap(stl_default_map, ft_default_map);
		std::cout << ((showInfo(stl_default_map.max_size(), ft_default_map.max_size()) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_operators()
{
    //[]
    try
    {
		std::cout<< std::endl << "===================================operator[]===================================" << std::endl;;
        const int range_int[] = {1489, -98, -9, -46, 256};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		showInfoMap(stl_map, ft_map);

		std::cout << "[";
		std::cout << ((showInfo(stl_map[-9], ft_map[-9]) == true) ? "[✅]" : "[❌]");

		stl_map[-9] = "Changed";
		ft_map[-9] = "Changed";

		std::cout << ((showInfo(stl_map[-9], ft_map[-9]) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_inserts()
{
    try
    {
		std::cout<< std::endl << "===================================Insert single===================================" << std::endl;;
        std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		stl_map.insert(std::make_pair(42, "La famille"));
		ft_map.insert(ft::make_pair(42, "La famille"));

		std::cout << ((showInfoMap(stl_map, ft_map) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
		std::cout<< std::endl << "===================================Insert hint===================================" << std::endl;;
        const int range_int[] = {584, 96, 21, -54, 36};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

        showInfoMap(stl_map, ft_map);
		
		stl_map.insert(++(stl_map.begin()), std::make_pair(42, "Nice"));
		ft_map.insert(++(ft_map.begin()), ft::make_pair(42, "Nice"));

		std::cout << ((showInfoMap(stl_map, ft_map) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
		std::cout<< std::endl << "===================================Insert range===================================" << std::endl;;
        const int range_int[] = {754, -985, 58, 999, 5};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map_one;
		ft::map<int, std::string> ft_map_one;
		std::map<int, std::string> stl_map_two;
		ft::map<int, std::string> ft_map_two;

		for (int i = 0; i < 5; i++)
		{
			stl_map_one.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map_one.insert(ft::make_pair(range_int[i], range_str[i]));
			stl_map_two.insert(std::make_pair(range_int[i] + 266, range_str[i] + "_two"));
			ft_map_two.insert(ft::make_pair(range_int[i] + 266, range_str[i] + "_two"));
		}

		showInfoMap(stl_map_one, ft_map_one);
		showInfoMap(stl_map_two, ft_map_two);
		
		stl_map_one.insert(stl_map_two.begin(), stl_map_two.end());
		ft_map_one.insert(ft_map_two.begin(), ft_map_two.end());

		std::cout << ((showInfoMap(stl_map_one, ft_map_one) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_erase()
{
    //Erase single
    try
    {
		std::cout<< std::endl << "===================================Erase single===================================" << std::endl;;
        const int range_int[] = {-9, -84, -77, 24, 56};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		showInfoMap(stl_map, ft_map);
		
		stl_map.erase(stl_map.begin());
		ft_map.erase(ft_map.begin());

		std::cout << ((showInfoMap(stl_map, ft_map) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    //erase_key
    try
    {
		std::cout<< std::endl << "===================================erase_key===================================" << std::endl;;
        const int range_int[] = {1452, 3651, -98, 84, 899};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}
        showInfoMap(stl_map, ft_map);
		
		stl_map.erase(-98);
		ft_map.erase(-98);

		std::cout << ((showInfoMap(stl_map, ft_map) == true) ? "[✅]" : "[❌]");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    //erase_range
    try
    {
		std::cout<< std::endl << "===================================erase_range===================================" << std::endl;;
        const int range_int[] = {-854, 1, 965, -9, 755};
        const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

        for (int i = 0; i < 5; i++)
        {
            stl_map.insert(std::make_pair(range_int[i], range_str[i]));
            ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
        }

        showInfoMap(stl_map, ft_map);
	    
		std::map<int, std::string>::iterator stl_it_beg = stl_map.begin();
		ft::map<int, std::string>::iterator ft_it_beg = ft_map.begin();
		std::map<int, std::string>::iterator stl_it_end = stl_map.end();
		ft::map<int, std::string>::iterator ft_it_end = ft_map.end();

		for (int i = 0; i < 2; i++)
		{
			stl_it_beg++;
			ft_it_beg++;
		}
		stl_it_end--;
		ft_it_end--;

        stl_map.erase(stl_it_beg, stl_it_end);
        ft_map.erase(ft_it_beg, ft_it_end);

        std::cout << ((showInfoMap(stl_map, ft_map) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_swap()
{
    try
    {
		std::cout<< std::endl << "===================================map_swap===================================" << std::endl;;
        const int range_int[] = {489, 851, 32, -98, 8};
        const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

        std::map<int, std::string> stl_map_one;
        ft::map<int, std::string> ft_map_one;
        std::map<int, std::string> stl_map_two;
        ft::map<int, std::string> ft_map_two;

        for (int i = 0; i < 5; i++)
        {
            stl_map_one.insert(std::make_pair(range_int[i], range_str[i]));
            ft_map_one.insert(ft::make_pair(range_int[i], range_str[i]));
            stl_map_two.insert(std::make_pair(range_int[i] + 120, range_str[i]));
            ft_map_two.insert(ft::make_pair(range_int[i] + 120, range_str[i]));
        }

        showInfoMap(stl_map_one, ft_map_one);
        showInfoMap(stl_map_two, ft_map_two);
        
        stl_map_one.swap(stl_map_two);
        ft_map_one.swap(ft_map_two);

        std::cout << ((showInfoMap(stl_map_one, ft_map_one) == true) ? "[✅]" : "[❌]");
        std::cout << ((showInfoMap(stl_map_two, ft_map_two) == true) ? "[✅]" : "[❌]");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_clear()
{
    try
    {
		std::cout<< std::endl << "===================================map_clear===================================" << std::endl;;
        const int range_int[] = {148, 9874, -987, 52, 96};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		showInfoMap(stl_map, ft_map);
		
		stl_map.clear();
		ft_map.clear();

		std::cout << ((showInfoMap(stl_map, ft_map) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_key_comp()
{
    try
    {
		std::cout<< std::endl << "===================================map_key_comp===================================" << std::endl;;
        std::map<int, std::string>::key_compare stl_key = std::map<int, std::string>().key_comp();
		ft::map<int, std::string>::key_compare ft_key = ft::map<int, std::string>().key_comp();

		bool stl_res = stl_key(42, 99);
		bool ft_res = ft_key(42, 99);

		std::cout << ((printBoolResult(stl_res, ft_res) == true) ? "[✅]" : "[❌]");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_value_comp()
{
    try
    {
		std::cout<< std::endl << "===================================map_value_comp===================================" << std::endl;;
        std::map<int, std::string>::value_compare stl_key = std::map<int, std::string>().value_comp();
		ft::map<int, std::string>::value_compare ft_key = ft::map<int, std::string>().value_comp();

		bool stl_res = stl_key(std::make_pair(99, "End"), std::make_pair(42, "Noice"));
		bool ft_res = ft_key(ft::make_pair(99, "End"), ft::make_pair(42, "Noice"));

		std::cout << ((printBoolResult(stl_res, ft_res) == true) ? "[✅]" : "[❌]");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
}

void map_find_exist()
{
    try
    {
		std::cout<< std::endl << "===================================map_find_exist===================================" << std::endl;;
        const int range_int[] = {954, 12, -965, 42, 1000};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		std::map<int, std::string>::iterator stl_it = stl_map.find(42);		
		ft::map<int, std::string>::iterator ft_it = ft_map.find(42);
		
		showInfoMap(stl_map, ft_map);
		
		std::cout << "[";
		std::cout << ((showInfo((*stl_it).first, (*ft_it).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_it).second, (*ft_it).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_not_exist()
{
    try
    {
		std::cout<< std::endl << "===================================map_not_exist===================================" << std::endl;;
        const int range_int[] = {14, 985, 578, -23, 47};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}
		std::map<int, std::string>::iterator stl_it = stl_map.find(42);		
		ft::map<int, std::string>::iterator ft_it = ft_map.find(42);
		
		showInfoMap(stl_map, ft_map);
		
		std::cout << ((printBoolResult((stl_it == stl_map.end()), (ft_it == ft_map.end())) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void map_const_if_Find()
{
    try
    {
        const int range_int[] = {842, -965, 99, 52, 65};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		std::map<int, std::string>::const_iterator stl_it = stl_map.find(99);		
		ft::map<int, std::string>::const_iterator ft_it = ft_map.find(99);
		
		showInfoMap(stl_map, ft_map);
		
		std::cout << "[";
		std::cout << ((showInfo((*stl_it).first, (*ft_it).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_it).second, (*ft_it).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_count()
{
    try
    {
        const int range_int[] = {842, 654, 95, -98, -8};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		showInfoMap(stl_map, ft_map);

		std::cout << "[";
		std::cout << ((printBoolResult((stl_map.count(-98) > 0), (ft_map.count(-98) > 0)) == true) ? "[✅]" : "[❌]");
		std::cout << ((printBoolResult((stl_map.count(42) > 0), (ft_map.count(42) > 0)) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_lower_bound()
{
    try
    {
        const int range_int[] = {351, -999, 5, 76, 61};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		showInfoMap(stl_map, ft_map);

		std::map<int, std::string>::iterator stl_it = stl_map.lower_bound(80);
		ft::map<int, std::string>::iterator ft_it = ft_map.lower_bound(80);

		std::cout << "[";
		std::cout << ((showInfo((*stl_it).first, (*ft_it).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_it).second, (*ft_it).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_upper_bound()
{
    try
    {
        const int range_int[] = {45, -84, 957, 966, 3};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		showInfoMap(stl_map, ft_map);

		std::map<int, std::string>::iterator stl_it = stl_map.upper_bound(950);
		ft::map<int, std::string>::iterator ft_it = ft_map.upper_bound(950);

		std::cout << "[";
		std::cout << ((showInfo((*stl_it).first, (*ft_it).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stl_it).second, (*ft_it).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_equal_range()
{
    try
    {
        const int range_int[] = {-741, 520, 65, -84, -1};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}
		showInfoMap(stl_map, ft_map);

		std::cout << "[";
		std::cout << ((showInfo((*(stl_map.equal_range(65).first)).first, (*(ft_map.equal_range(65).first)).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*(stl_map.equal_range(65).second)).first, (*(ft_map.equal_range(65).second)).first) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}