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
        const int int_array[] = {-652, -4, 98, 54, -210};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		showInfoMap(stlMapCont, ftMapCont);

		std::map<int, std::string> stlMapCont_copy(stlMapCont.begin(), stlMapCont.end());
		ft::map<int, std::string> ftMapCont_copy(ftMapCont.begin(), ftMapCont.end());

		std::cout << ((showInfoMap(stlMapCont_copy, ftMapCont_copy) == true) ? "[✅]" : "[❌]");
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
        const int int_array[] = {478, 952, 12, -96, -9};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

        showInfoMap(stlMapCont, ftMapCont);

		std::map<int, std::string> stlMapCont_copy = stlMapCont;
		ft::map<int, std::string> ftMapCont_copy = ftMapCont;

		std::cout << ((showInfoMap(stlMapCont_copy, ftMapCont_copy) == true) ? "[✅]" : "[❌]");
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
        const int int_array[] = {1485, 5, 89, 652, -94};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}
        showInfoMap(stlMapCont, ftMapCont);
		std::cout << "[";
		std::cout << ((showInfo((*stlMapCont.begin()).first, (*ftMapCont.begin()).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stlMapCont.begin()).second, (*ftMapCont.begin()).second) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
		std::cout<< std::endl << "===================================const begin ite===================================" << std::endl;;
        const int int_array[] = {48, 9, 12, 63, 99};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}
        showInfoMap(stlMapCont, ftMapCont);
		std::cout << "[";
		std::cout << ((showInfo((*stlMapCont.begin()).first, (*ftMapCont.begin()).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*stlMapCont.begin()).second, (*ftMapCont.begin()).second) == true) ? "[✅]" : "[❌]");
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
        
        const int int_array[] = {-99, 584, 965, 366, 77};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

        std::map<int, std::string>::iterator stl_it = stlMapCont.end();
		ft::map<int, std::string>::iterator ft_it = ftMapCont.end();

		showInfoMap(stlMapCont, ftMapCont);

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
        
        const int int_array[] = {154, 966, 3, -84, 75};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		std::map<int, std::string>::const_iterator stl_it = stlMapCont.end();
		ft::map<int, std::string>::const_iterator ft_it = ftMapCont.end();

		showInfoMap(stlMapCont, ftMapCont);

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
        
        const int int_array[] = {1458, -985, 58, 632, 65};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		std::map<int, std::string>::reverse_iterator stl_it = stlMapCont.rbegin();
		ft::map<int, std::string>::reverse_iterator ft_it = ftMapCont.rbegin();

		showInfoMap(stlMapCont, ftMapCont);

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
        
        const int int_array[] = {859, 99, -325, -65, -98};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		std::map<int, std::string>::const_reverse_iterator stl_it = stlMapCont.rbegin();
		ft::map<int, std::string>::const_reverse_iterator ft_it = ftMapCont.rbegin();

		showInfoMap(stlMapCont, ftMapCont);

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
        
        const int int_array[] = {325, -657, -942, -8, 66};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		std::map<int, std::string>::reverse_iterator stl_it = stlMapCont.rend();
		ft::map<int, std::string>::reverse_iterator ft_it = ftMapCont.rend();

		showInfoMap(stlMapCont, ftMapCont);

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
		std::cout<< std::endl << "===================================const reverse end ite===================================" << std::endl;;

        const int int_array[] = {-99, 584, 965, 366, 77};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		std::map<int, std::string>::const_reverse_iterator stl_it = stlMapCont.rend();
		ft::map<int, std::string>::const_reverse_iterator ft_it = ftMapCont.rend();

		showInfoMap(stlMapCont, ftMapCont);

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
		std::cout << ((showResult(stl_default_map.empty(), ft_default_map.empty()) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //False
    try
    {
		std::cout<< std::endl << "===================================empty false===================================" << std::endl;;
        const int int_array[] = {1452, 3651, -98, 84, 899};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		showInfoMap(stlMapCont, ftMapCont);
		std::cout << ((showResult(stlMapCont.empty(), ftMapCont.empty()) == true) ? "[✅]" : "[❌]");

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
        const int int_array[] = {9, -84, -45, -67, -9};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		showInfoMap(stlMapCont, ftMapCont);
		std::cout << "[";
		std::cout << ((showInfo(stlMapCont.size(), ftMapCont.size()) == true) ? "[✅]" : "[❌]");

		stlMapCont.insert(std::make_pair(42, "Represent"));
		ftMapCont.insert(ft::make_pair(42, "Represent"));

		std::cout << ((showInfo(stlMapCont.size(), ftMapCont.size()) == true) ? "[✅]" : "[❌]");

		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

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
    try
    {
		std::cout<< std::endl << "===================================operator[]===================================" << std::endl;;
        const int int_array[] = {1489, -98, -9, -46, 256};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		showInfoMap(stlMapCont, ftMapCont);

		std::cout << "[";
		std::cout << ((showInfo(stlMapCont[-9], ftMapCont[-9]) == true) ? "[✅]" : "[❌]");

		stlMapCont[-9] = "Changed";
		ftMapCont[-9] = "Changed";

		std::cout << ((showInfo(stlMapCont[-9], ftMapCont[-9]) == true) ? "[✅]" : "[❌]");
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
        std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		stlMapCont.insert(std::make_pair(42, "La famille"));
		ftMapCont.insert(ft::make_pair(42, "La famille"));

		std::cout << ((showInfoMap(stlMapCont, ftMapCont) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
		std::cout<< std::endl << "===================================Insert hint===================================" << std::endl;;
        const int int_array[] = {584, 96, 21, -54, 36};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

        showInfoMap(stlMapCont, ftMapCont);
		
		stlMapCont.insert(++(stlMapCont.begin()), std::make_pair(42, "Nice"));
		ftMapCont.insert(++(ftMapCont.begin()), ft::make_pair(42, "Nice"));

		std::cout << ((showInfoMap(stlMapCont, ftMapCont) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
		std::cout<< std::endl << "===================================Insert range===================================" << std::endl;;
        const int int_array[] = {754, -985, 58, 999, 5};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> strMapFirst;
		ft::map<int, std::string> ftMapFirst;
		std::map<int, std::string> strMapSecond;
		ft::map<int, std::string> ftMapSecond;

		for (int i = 0; i < 5; i++)
		{
			strMapFirst.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapFirst.insert(ft::make_pair(int_array[i], str_array[i]));
			strMapSecond.insert(std::make_pair(int_array[i] + 266, str_array[i] + "_two"));
			ftMapSecond.insert(ft::make_pair(int_array[i] + 266, str_array[i] + "_two"));
		}

		showInfoMap(strMapFirst, ftMapFirst);
		showInfoMap(strMapSecond, ftMapSecond);
		
		strMapFirst.insert(strMapSecond.begin(), strMapSecond.end());
		ftMapFirst.insert(ftMapSecond.begin(), ftMapSecond.end());

		std::cout << ((showInfoMap(strMapFirst, ftMapFirst) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void map_erase()
{
    try
    {
		std::cout<< std::endl << "===================================Erase single===================================" << std::endl;;
        const int int_array[] = {-9, -84, -77, 24, 56};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		showInfoMap(stlMapCont, ftMapCont);
		
		stlMapCont.erase(stlMapCont.begin());
		ftMapCont.erase(ftMapCont.begin());

		std::cout << ((showInfoMap(stlMapCont, ftMapCont) == true) ? "[✅]" : "[❌]");

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
		std::cout<< std::endl << "===================================erase_key===================================" << std::endl;;
        const int int_array[] = {1452, 3651, -98, 84, 899};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}
        showInfoMap(stlMapCont, ftMapCont);
		
		stlMapCont.erase(-98);
		ftMapCont.erase(-98);

		std::cout << ((showInfoMap(stlMapCont, ftMapCont) == true) ? "[✅]" : "[❌]");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
		std::cout<< std::endl << "===================================erase_range===================================" << std::endl;;
        const int int_array[] = {-854, 1, 965, -9, 755};
        const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

        for (int i = 0; i < 5; i++)
        {
            stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
            ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
        }

        showInfoMap(stlMapCont, ftMapCont);
	    
		std::map<int, std::string>::iterator stl_it_beg = stlMapCont.begin();
		ft::map<int, std::string>::iterator ft_it_beg = ftMapCont.begin();
		std::map<int, std::string>::iterator stl_it_end = stlMapCont.end();
		ft::map<int, std::string>::iterator ft_it_end = ftMapCont.end();

		for (int i = 0; i < 2; i++)
		{
			stl_it_beg++;
			ft_it_beg++;
		}
		stl_it_end--;
		ft_it_end--;

        stlMapCont.erase(stl_it_beg, stl_it_end);
        ftMapCont.erase(ft_it_beg, ft_it_end);

        std::cout << ((showInfoMap(stlMapCont, ftMapCont) == true) ? "[✅]" : "[❌]");

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
        const int int_array[] = {489, 851, 32, -98, 8};
        const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

        std::map<int, std::string> strMapFirst;
        ft::map<int, std::string> ftMapFirst;
        std::map<int, std::string> strMapSecond;
        ft::map<int, std::string> ftMapSecond;

        for (int i = 0; i < 5; i++)
        {
            strMapFirst.insert(std::make_pair(int_array[i], str_array[i]));
            ftMapFirst.insert(ft::make_pair(int_array[i], str_array[i]));
            strMapSecond.insert(std::make_pair(int_array[i] + 120, str_array[i]));
            ftMapSecond.insert(ft::make_pair(int_array[i] + 120, str_array[i]));
        }

        showInfoMap(strMapFirst, ftMapFirst);
        showInfoMap(strMapSecond, ftMapSecond);
        
        strMapFirst.swap(strMapSecond);
        ftMapFirst.swap(ftMapSecond);

        std::cout << ((showInfoMap(strMapFirst, ftMapFirst) == true) ? "[✅]" : "[❌]");
        std::cout << ((showInfoMap(strMapSecond, ftMapSecond) == true) ? "[✅]" : "[❌]");
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
        const int int_array[] = {148, 9874, -987, 52, 96};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		showInfoMap(stlMapCont, ftMapCont);
		
		stlMapCont.clear();
		ftMapCont.clear();

		std::cout << ((showInfoMap(stlMapCont, ftMapCont) == true) ? "[✅]" : "[❌]");

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

		std::cout << ((showResult(stl_res, ft_res) == true) ? "[✅]" : "[❌]");
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

		std::cout << ((showResult(stl_res, ft_res) == true) ? "[✅]" : "[❌]");
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
        const int int_array[] = {954, 12, -965, 42, 1000};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		std::map<int, std::string>::iterator stl_it = stlMapCont.find(42);		
		ft::map<int, std::string>::iterator ft_it = ftMapCont.find(42);
		
		showInfoMap(stlMapCont, ftMapCont);
		
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
        const int int_array[] = {14, 985, 578, -23, 47};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}
		std::map<int, std::string>::iterator stl_it = stlMapCont.find(42);		
		ft::map<int, std::string>::iterator ft_it = ftMapCont.find(42);
		
		showInfoMap(stlMapCont, ftMapCont);
		
		std::cout << ((showResult((stl_it == stlMapCont.end()), (ft_it == ftMapCont.end())) == true) ? "[✅]" : "[❌]");

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
        const int int_array[] = {842, -965, 99, 52, 65};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		std::map<int, std::string>::const_iterator stl_it = stlMapCont.find(99);		
		ft::map<int, std::string>::const_iterator ft_it = ftMapCont.find(99);
		
		showInfoMap(stlMapCont, ftMapCont);
		
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
        const int int_array[] = {842, 654, 95, -98, -8};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		showInfoMap(stlMapCont, ftMapCont);

		std::cout << "[";
		std::cout << ((showResult((stlMapCont.count(-98) > 0), (ftMapCont.count(-98) > 0)) == true) ? "[✅]" : "[❌]");
		std::cout << ((showResult((stlMapCont.count(42) > 0), (ftMapCont.count(42) > 0)) == true) ? "[✅]" : "[❌]");
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
        const int int_array[] = {351, -999, 5, 76, 61};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		showInfoMap(stlMapCont, ftMapCont);

		std::map<int, std::string>::iterator stl_it = stlMapCont.lower_bound(80);
		ft::map<int, std::string>::iterator ft_it = ftMapCont.lower_bound(80);

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
        const int int_array[] = {45, -84, 957, 966, 3};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}

		showInfoMap(stlMapCont, ftMapCont);

		std::map<int, std::string>::iterator stl_it = stlMapCont.upper_bound(950);
		ft::map<int, std::string>::iterator ft_it = ftMapCont.upper_bound(950);

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
        const int int_array[] = {-741, 520, 65, -84, -1};
		const std::string str_array[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stlMapCont;
		ft::map<int, std::string> ftMapCont;

		for (int i = 0; i < 5; i++)
		{
			stlMapCont.insert(std::make_pair(int_array[i], str_array[i]));
			ftMapCont.insert(ft::make_pair(int_array[i], str_array[i]));
		}
		showInfoMap(stlMapCont, ftMapCont);

		std::cout << "[";
		std::cout << ((showInfo((*(stlMapCont.equal_range(65).first)).first, (*(ftMapCont.equal_range(65).first)).first) == true) ? "[✅]" : "[❌]");
		std::cout << ((showInfo((*(stlMapCont.equal_range(65).second)).first, (*(ftMapCont.equal_range(65).second)).first) == true) ? "[✅]" : "[❌]");
		std::cout << "]";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}