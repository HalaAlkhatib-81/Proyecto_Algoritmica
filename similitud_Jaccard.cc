#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// Función para calcular la similitud de Jaccard entre dos conjuntos
double jaccardSimilarity(const set<int> &setA, const set<int> &setB)
{
    // Conjuntos para almacenar la intersección y la unión
    set<int> intersectionSet, unionSet;

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

int main()
{
    // Ejemplo de conjuntos
    set<int> doc1 = {1, 2, 3, 4, 5};
    set<int> doc2 = {4, 5, 6, 7, 8};

    double similarity = jaccardSimilarity(doc1, doc2);
    cout << "La similitud de Jaccard es: " << similarity << endl;
}
