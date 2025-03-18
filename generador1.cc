#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void generar_permutaciones(vector<string>& palabras, int tamano) {
    random_device rd;
    mt19937 g(rd());

    for (int i = 1; i <= 20; ++i) {
        vector<string> palabras_permutadas = palabras;
        shuffle(palabras_permutadas.begin(), palabras_permutadas.end(), g);

        string nombre_archivo = "permutacion1_" + to_string(i) + ".txt";
        ofstream archivo(nombre_archivo);

        if (!archivo) {
            cerr << "Error al abrir el archivo: " << nombre_archivo << endl;
        }

        int contador = 0;
        string texto_formateado;

        for (const string& palabra : palabras_permutadas) {
            texto_formateado += palabra + " ";
            contador++;

            if (contador >= tamano) {
                texto_formateado += "\n";
                contador = 0;
            }
        }

        archivo << texto_formateado;

        archivo.close();
    }
}

int main() {
    ifstream archivo("documento_salida.txt");

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
    }

    vector<string> palabras_diferentes;
    string palabra;
    while (archivo >> palabra) {
        palabras_diferentes.push_back(palabra);
    }

    archivo.close();

    generar_permutaciones(palabras_diferentes, 10);

}