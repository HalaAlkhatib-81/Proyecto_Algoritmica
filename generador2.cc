#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void generar_k_shingles(const string& archivo_entrada, const string& archivo_salida, int k) {
    ifstream entrada(archivo_entrada);
    ofstream salida(archivo_salida);

    if (!entrada) {
        cerr << "Error al abrir el archivo de entrada." << endl;
    }

    if(!salida) {
        cerr << "Error al abrir el archivo de salida." << endl;
    }

    vector<string> palabras;
    string palabra;
    while (entrada >> palabra) {
        palabras.push_back(palabra);
    }
    entrada.close();

    for (int i = 0; i < palabras.size() - k; ++i) {
        int cont = 0;
        int j = i;
        while (cont < k) {
            salida << palabras[j] << " ";
            ++cont;
            ++j;
        }
        salida << endl;
    }

}
int main() {
    int k;
    cout << "Dame un valor de k: " << endl;
    cin >> k;

    generar_k_shingles("documento_salida.txt", "k-shingles.txt", k);
}