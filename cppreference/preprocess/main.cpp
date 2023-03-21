#include "stdio.h"

// __has_include("") , __has_include(<>) 는 해당 파일이 include가 가능한지에 대한 여부 ( include 했냐 안했냐가 아님 )
#if __has_include("mockIncludeFile.hpp")    //mockIncludeFile.hpp이 include 가능한가?
    #define MOCK
    #include "mockIncludeFile.hpp"          //mockIncludeFile.hpp include 가능하니깐 true
#else
#endif
// __has_include("") -E-

//pragma pack() test
#include "myPragmaPack.hpp"
//pragma pack() test -E-


int main(int argc, char** argv)
{
    //__has_include("") test
#ifdef MOCK
    mockIncludeFile::print_mock();
#endif
    //__has_include("") test -E-


    //pragma pack() test
    myPragmaPack::print_all();
    //pragma pack() test -E-


    return 0;
}