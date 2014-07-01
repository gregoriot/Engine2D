#ifndef STRINGSPLIT_HPP
#define	STRINGSPLIT_HPP

#include <iostream>
#include <vector>
#include "sstream"

class StringSplit {
public:
    StringSplit();
    virtual ~StringSplit();
    
    static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
    static std::vector<std::string> split(const std::string &s, char delim);
private:
    
};

#endif	/* STRINGSPLIT_HPP */

