#include "stdio.h"

// __has_include("") , __has_include(<>) 는 해당 파일이 include가 가능한지에 대한 여부 ( include 했냐 안했냐가 아님 )
#if __has_include("mockIncludeFile.hpp")    //mockIncludeFile.hpp이 include 가능한가?
    #define MOCK
    #include "mockIncludeFile.hpp"          //mockIncludeFile.hpp include 가능하니깐 true
#else
    
#endif


int main(int argc, char** argv)
{
#ifdef MOCK
    mockIncludeFile::print_mock();
#endif
    return 0;
}