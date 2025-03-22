/** @file minHash.hh
 * @brief Implementacion de un algoritmo de MinHash para calcular la similitud entre dos documentos.
 */
#ifndef MINHASH_HH
#define MINHASH_HH


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <unordered_map>
#include "xxhash.h"

using namespace std;


/** @class MinHash
    @brief Clase para calcular la similitud entre dos documentos mediante funciones de MinHash.
*/

class minHash{
    public:
        /** @brief calcula los minHash de cada shingle existente en el documente
         * @param shingles conjunto de shingles del documento
         * @return vector con los minHash de los shingles
         * @pre shingles no vacio
         * @post se devuelven los minHash de los shingles en un vector de enteros
         */
        vector<uint32_t> computarMinHash(set<string> shingles);

        /** @brief calcula la similaridad de Jaccard aproximada entre dos documentos usando los minHash creados
         * @param minHashesA vector con los minHash del documento A
         * @param minHashesB vector con los minHash del documento B
         * @return similaridad de Jaccard aproximada entre los documentos
         * @pre firmaA y firmaB no vacios
         * @post se devuelve la similaridad de Jaccard aproximada entre los documentos
         */
        double similaridades(vector<uint32_t> minhashesA, vector<uint32_t> minhashesB);
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