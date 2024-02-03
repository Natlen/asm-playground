#ifndef CDummy_H
#define CDummy_H


#pragma pack(1) // set padding for 1 byte - mandatory for asm - since retrieving via base address+#of byte
class CDummy {
    public:
    CDummy(int x, bool(*cmp_fptr)(const CDummy&, const CDummy&), double y, const char* t, unsigned long long u, void* z) :
        x{ x }, cmp_fptr{ cmp_fptr }, y{ y }, t{ t }, u{ u }, z{ z } {};
    friend bool cmp(const CDummy&, const CDummy&);
    private:

    /* rsp */       int x;
    /* rsp+4 */     bool (*cmp_fptr)(const CDummy&, const CDummy&);
    /* rsp+12 */    double y;
    /* rsp+20 */    const char* t;
    /* rsp+28 */    unsigned long long u;
    /* rsp+36 */    void* z;
};
#pragma pack()

#endif