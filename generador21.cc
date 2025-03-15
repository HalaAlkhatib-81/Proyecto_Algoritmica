#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>
#include <unordered_set>

using namespace std;

void generar_permutaciones(vector<vector<string> >& k_shingles, int tamano, int n) {
    for (int i = 1; i <= 20; ++i) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, k_shingles.size() - 1);

        unordered_set<int> indices_elegidos; //queremos evitar repeticiones

        while (indices_elegidos.size() < n) {
            int indice = distrib(gen);
            indices_elegidos.insert(indice);
        }
        
        string nombre_archivo = "permutacion1_" + to_string(i) + ".txt";
        ofstream archivo(nombre_archivo);

        if (!archivo) {
            cerr << "Error al abrir el archivo: " << nombre_archivo << endl;
        }

        int contador = 0;
        string texto_formateado;

        for (int j : indices_elegidos) {
            for (int k = 0; k < k_shingles[j].size(); ++k) {
                texto_formateado += k_shingles[j][k] + " ";
                contador ++;

                if (contador >= tamano) {
                    texto_formateado += "\n";
                    contador = 0;
                }
            }
        }
        archivo << texto_formateado;
        archivo.close();
    }
}

int main() {
    ifstream archivo("k-shingles.txt");

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
    }

    vector<vector<string> > k_shingles;
    string linea;
    while (getline(archivo, linea)) {
        vector<string> aux;
        stringstream ss(linea);
        string palabra;
        while (ss >> palabra) {
            aux.push_back(palabra);
        }
        if (!aux.empty()) {
            k_shingles.push_back(aux);
        }
    }

    archivo.close();

    int n;
    cout << "Dame un numero de 0 a " << k_shingles.size() - 1 << endl;
    cin >> n;
    while (n >= k_shingles.size()) {
        cout << "El número no es válido." << endl;
        cin >> n;
    }

    generar_permutaciones(k_shingles, 10, n);

}