#include <iostream>
#include <stdio.h>

#include "dummy/CDummy.h"

#ifdef __cplusplus
extern "C" {
extern int printf(const char*, ...);
double dummyfunc(int x, bool(*func_ptr)(const CDummy&, const CDummy&), double y,
    const char* t, unsigned long long u, void* z, const CDummy& d)
{
    *((int*)z) = -9;
    return func_ptr(d, d) ? 16.16 : -16.16;
}
void a(CDummy& d)
{
    int t = 0;
    t++;
}
extern double __cdecl func(CDummy&);

#endif
#ifdef __cplusplus 
}
#endif

inline bool cmp(const CDummy& d1, const CDummy& d2) { return d1.x == d2.x && d1.y == d2.y; };


int main()
{
    int a = -4;
    CDummy d1{ 1, cmp, 1.1, "aaaaaaaaaa", 123456789ULL, &a};
    double dd = func(d1);
    std::cout << "a = " << a << std::endl;
    std::cout << "dd = " << dd << std::endl;
    return 0;
}