#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// Función para calcular la similitud de Jaccard entre dos conjuntos
double jaccardSimilarity(const set<string> &setA, const set<string> &setB)
{
    // Conjuntos para almacenar la intersección y la unión
    set<string> intersectionSet, unionSet;

    // Calcular la intersección de setA y setB
    set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), inserter(intersectionSet, intersectionSet.begin()));

    // Calcular la unión de setA y setB
    set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), inserter(unionSet, unionSet.begin()));

    // Si la unión está vacía, se retorna similitud 0
    if (unionSet.empty())
        return 0.0;

    // La similitud de Jaccard es el tamaño de la intersección dividido por el tamaño de la unión
    return static_cast<double>(intersectionSet.size()) / unionSet.size();
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

int main()
{
    // Leer los documentos de los archivos
    set<string> doc1, doc2;
    readLinesFromFile("permutacion1_1.txt", doc1);
    readLinesFromFile("permutacion1_2.txt", doc2);

    //set<string> doc1 = {"apple and pineapple", "apple and orange"};
    //set<string> doc2 = {"apple and pineapple"};

    cout << "////////////////// Documento 1:" << endl;
    for (const auto &line : doc1)
    {
        cout << line << endl;
    }
    cout << "////////////////// Documento 2:" << endl;
    for (const auto &line : doc2)
    {
        cout << line << endl;
    }

    double similarity = jaccardSimilarity(doc1, doc2);
    cout << "La similitud de Jaccard es: " << similarity << endl;
}
