#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <unordered_map>
#include "xxhash.h"
using namespace std;

const int T = 100;
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


void readLinesFromFile(const string &filename, set<string> &doc)
{
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        doc.insert(line);
    }
}

vector<vector<int>> bandes(vector<uint32_t> minhashes, int b){
    vector<vector<int>> bandes;
    int r = T/b;
    for(int i = 0; i < b; i++){
        vector<int> band;
        for(int j = 0; j < r; j++){
            band.push_back(minhashes[i*r + j]);
        }
        bandes.push_back(band);
    }
    return bandes;
}

void localitySensitiveHashing(const vector<vector<int>> &bandes, int docId, unordered_map<size_t, vector<int>> &lshTable) {
    for (int i = 0; i < bandes.size(); i++) {
        size_t hash = 0;
        for (int j = 0; j < bandes[i].size(); j++) {
            hash = hash * 31 + bandes[i][j];
        }
        lshTable[hash].push_back(docId);
    }
}

double similitudJaccard(const vector<uint32_t> &firmaA, const vector<uint32_t> &firmaB) {
    int coincidencies = 0;
    for (int i = 0; i < T; i++) {
        if (firmaA[i] == firmaB[i]) coincidencies++;
    }
    return (double)coincidencies / T;
}

int main(){

    set<string> shinglesA;
    set<string> shinglesB;
    readLinesFromFile("docA.txt", shinglesA);
    readLinesFromFile("docB.txt", shinglesB);

    vector<uint32_t> firmaA = computarMinHash(shinglesA);
    vector<uint32_t> firmaB = computarMinHash(shinglesB);
    vector<vector<int>> bandesA = bandes(firmaA, 10);
    vector<vector<int>> bandesB = bandes(firmaB, 10);

    unordered_map<size_t, vector<int>> lshTable;
    localitySensitiveHashing(bandesA, 1, lshTable);
    localitySensitiveHashing(bandesB, 2, lshTable);

    // Comprovem si els documents han caigut en la mateixa banda
    bool sonCandidats = false;
    for (const auto &entry : lshTable) {
        if (entry.second.size() > 1) {
            cout << "Possible parella similar trobada en banda hash: " << entry.first << endl;
            sonCandidats = true;
        }
    }

    if (sonCandidats) {
        double sim = similitudJaccard(firmaA, firmaB);
        cout << "Similitud de Jaccard real: " << sim << endl;
    } else {
        cout << "No s'han trobat candidats similars." << endl;
    }

    return 0;
}