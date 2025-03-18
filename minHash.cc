#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <unordered_map>
#include "xxhash.h"
using namespace std;

const int T = 10;
vector<uint32_t> computarMinHash(set<string> shingles){
    vector<uint32_t> minhashes(T, UINT32_MAX);
    for(string shin: shingles){
        for(int i = 0; i < T; i++){
            uint32_t hash = XXH32(shin.c_str(), shin.size(), i);
            minhashes[i] = min(minhashes[i], hash);
        }
    }
    return minhashes;
}

double similaridades(vector<uint32_t> minhashesA, vector<uint32_t> minhashesB){
    double count = 0;
    for(size_t i = 0; i < minhashesA.size(); i++){
        if(minhashesA[i] == minhashesB[i]){
            count++;
        }
    }
    cerr << count << endl;
    return count/T;
}

void readLinesFromFile(const string &filename, set<string> &doc)
{
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        doc.insert(line);
        cout << line << endl;
    }
}



int main(){

    set<std::string> shinglesA = {"algoritmo hashing útil", "hashing útil comparar", "útil comparar documentos"};
    set<std::string> shinglesB = {"algoritmo hashing útil", "hashing útil comparar", "permite comparar textos"}; 

    vector<uint32_t> signatureA = computarMinHash(shinglesA);
    vector<uint32_t> signatureB = computarMinHash(shinglesB);

    double numeros = similaridades(signatureA, signatureB);    
    cout << numeros << endl;
    return 0;
}