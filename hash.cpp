#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int g_k = 1;
int hash_function(string text) {
        // Implement your own hash function here

    unsigned long long hash=0;
    unsigned long long base=683;
    unsigned long long mod=1000000007ULL ;
    unsigned long long power=1;

    for (int i=0;i<(int)text.size();i++) {
        unsigned char c=(unsigned char)text[i];
        hash=(hash+(unsigned long long)(c+1)*power)%mod;
        power=(power*base)%mod;
    }

    return (int)(hash%(unsigned long long)g_k);
}
