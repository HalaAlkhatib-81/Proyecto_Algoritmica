

#ifndef LSH_HH
#define LSH_HH

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <unordered_map>
#include "xxhash.h"
using namespace std;

/** @class MinHash
    @brief Clase para calcular la similitud entre dos documentos mediante Locality Sensitive Hashing.
*/

class LSH{
    public:
        /** @brief calcula los minHash de cada shingle existente en el documente
         * @param shingles conjunto de shingles del documento
         * @return vector con los minHash de los shingles
         * @pre shingles no vacio
         * @post se devuelven los minHash de los shingles en un vector de enteros
         */
        vector<uint32_t> computarMinHash(set<string> shingles);

        /** @brief calcula las bandas de los minHash
         * @param minhashes vector con los minHash del documento
         * @param b numero de bandas
         * @return vector con las bandas de los minHash
         * @pre minhashes no vacio
         * @post se devuelven las bandas de los minHash en un vector de vectores de enteros
         */
        vector<vector<int>> bandes(vector<uint32_t> minhashes, int b);

        /** @brief calcula la similaridad de Jaccard aproximada entre dos documentos usando los minHash creados
         * @param firmaA vector con los minHash del documento A
         * @param firmaB vector con los minHash del documento B
         * @return similaridad de Jaccard aproximada entre los documentos
         * @pre firmaA y firmaB no vacios
         * @post se devuelve la similaridad de Jaccard aproximada entre los documentos
         */
        double similitudJaccard(const vector<uint32_t> &firmaA, const vector<uint32_t> &firmaB);



        /** @brief guarda en una tabla hash los documentos que coinciden en una banda
         * @param bandes vector con las bandas de los minHash
         * @param docId id del documento
         * @param lshTable tabla hash donde se guardaran los documentos que coinciden en una banda
         * @pre bandes no vacio
         */
        void localitySensitiveHashing(const vector<vector<int>> &bandes, int docId, unordered_map<size_t, vector<int>> &lshTable);
        
    private:
            /** @brief lee las lineas de un archivo y las guarda en un conjunto
         * @param filename nombre del archivo
         * @param doc conjunto donde se guardaran las lineas
         * @pre filename existe
         * @post se guardan las lineas del archivo en el conjunto
         */
        static void readElementsFromFile(const string &filename, set<string> &doc, int opcion, int k);
    };




#endif