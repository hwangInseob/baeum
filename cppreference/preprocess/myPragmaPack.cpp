
/*
#pragma pack()              //정렬 기준 size를 default로 설정
#pragma pack(push, 1)       //  ''  ''  ''      1    로 설정 (1로 설정하고 설정 값을 스택으로 저장)
#pragma pack(push, 2)       //  ''  ''  ''      2    로 설정 (2로 설정하고 설정 값을 스택으로 저장)
#pragma pack(pop)
#pragma pack(pop)
*/
#include "myPragmaPack.hpp"



static struct 
{
    char a;         //1byte
    int b;          //4byte
    double c;       //8byte
    char d;         //1byte
}st_none_packed;

void myPragmaPack::print_all()
{
    printf("none packed char,int,double,char STRUCT size = %d\n", sizeof(st_none_packed) );

}