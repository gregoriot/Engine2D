#include <iostream>
#include <vector>

#ifndef STRINGSPLIT_HPP
#define	STRINGSPLIT_HPP

class StringSplit {
public:
    StringSplit();
    virtual ~StringSplit();
    
    static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
    static std::vector<std::string> split(const std::string &s, char delim);
private:
    
};

#endif	/* STRINGSPLIT_HPP */

