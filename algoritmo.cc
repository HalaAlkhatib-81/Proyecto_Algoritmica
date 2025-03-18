#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "xxhash.h"
using namespace std;


int main(){
    string x = "Hola me llamo Pedro";
    long long int hash = XXH32(x.c_str(), x.size(), 0);
    cout << hash << endl;
    return 0;
}