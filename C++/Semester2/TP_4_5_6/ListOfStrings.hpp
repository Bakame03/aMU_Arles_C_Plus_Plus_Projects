#ifndef __LISTOFSTRINGS_HPP__
#define __LISTOFSTRINGS_HPP__

#include <iostream>
#include <string>

class ListOfStrings
{
    class StringNode
    {
        public:
            std::string value;
            StringNode* next;
            StringNode(std::string, StringNode* = nullptr);
            StringNode(const StringNode&);
            ~StringNode();
    };

    private:
        size_t count;
        StringNode* first;
        StringNode* last;

    public:
        ListOfStrings();
        ListOfStrings(const ListOfStrings&);
        ~ListOfStrings();
        inline size_t size() const { return count; };
};

#endif //__LISTOFSTRINGS_HPP__
