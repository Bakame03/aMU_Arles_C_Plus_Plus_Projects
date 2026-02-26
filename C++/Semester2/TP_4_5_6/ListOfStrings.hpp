#ifndef LISTOFSTRINGS_HPP

#include <iostream>
#include <string>

class ListOfStrings
{
    class StringNode
    {
        public:
            std::string value;
            StringNode* next;
            StringNode(std::string v, StringNode* = nullptr);
            StringNode(const StringNode&);
            ~StringNode();
    };
};

#endif //LISTOFSTRINGS_HPP
