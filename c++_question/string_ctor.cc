#include <iostream>
#include <cassert>
#include <iterator>
#include <string>
#include <cctype>

int main()
{
    {
        // string::string()
        std::string s;
        assert(s.empty() && ( s.length() == 0) && (s.size() == 0));
    }

    {
        //string::string(size_type count, charT ch)
        std::string s(4, '=');
        std::cout << s << '\n'; // "===="
    }

    {
        std::string const other("Examplary");
        //std::string (string const &other, size_type pos, size_type count)
        std::string s(other, 0, other.length() - 1);
        std::cout << s << '\n';//"Exemplar"
    }
    {
        //string::string (charT const* s, size_type count)
        std::string s("C-style string", 7);
        std::cout << s << '\n'; // "C-style"
    }

    {
        //string::string(charT const*s)
        std::string s("C-style\0string");
        std::cout << s << '\n'; // "C-style"
    }

    {
        char mutable_c_str[] = "another C-style string";
        //string::string(inputlt first, inputlt last)
        std::string s(std::begin(mutable_c_str) + 8, std::end(mutable_c_str) - 1);
        std::cout << s << '\n';// 'C-style string'
    }

    {
        std::string const other("Exemplar");
        std::string s(other);
        std::cout << s << '\n';// "Exemplar"
    }

    {
        //string::string(stirng&& str)
        std::string s(std::string("C++by ") + std::string("example"));
        std::cout << s << '\n';// C++ by example
    }
    {
        //string (std::initializer_list<charT> ilist)
        std::string s({'C', '-', 's', 't', 'y', 'l','e'});
        std::cout << s << '\n';// C-style
    }
    {
        // overload resolution select string(Input first, Input last) [with input = int]
        // which behaves as if string(size_type count, charT ch) is called
        std::string s(3, std::toupper('a'));
        std::cout << s << '\n';// AAA
    }
    return 0;
}

