#ifndef __STRING__
#define __STRING__
#include <iostream> 

struct String{
    size_t allocated_size;
    char * buffer;
};

void CreateString(String & str, const size_t size=256);
void DisplayString(const String & str);

#endif