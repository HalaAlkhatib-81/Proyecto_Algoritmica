#include <iostream>
#include <fstream>
#include <cctype>
#include <unordered_set>

using namespace std;

unordered_set<string> obtener_stopwords() {
    unordered_set<string> stopwords;
    ifstream archivo("stopwords-es.txt");

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
    }

    // leemos cada stopword y la insertamos en el unordered set 
    string palabra;
    while (archivo >> palabra) { 
        stopwords.insert(palabra);
    }

    archivo.close();

    return stopwords;
}

string limpiar_palabra(const string& palabra) {
    //nos quedamos con la palabra sola, en minúsculas y sin signos de puntuación y agregamos en el set solo si no es stopword
    string palabra_final;
    for (char c : palabra) {
        if (!ispunct(c)) {
            if (isupper(c)) c = tolower(c);
            palabra_final += c;
        };
    }
    return palabra_final;
}

//pre: el documento tiene mínimo 50 palabras diferentes
void procesar_texto(const string& archivo_entrada, const string& archivo_salida, const unordered_set<string>& stopwords, string num) {
    ifstream entrada(archivo_entrada);
    ofstream salida(archivo_salida);

    if (!entrada) {
        cerr << "Error al abrir el archivo de entrada." << endl;
    }

    if(!salida) {
        cerr << "Error al abrir el archivo de salida." << endl;
    }

    string palabra;

    if (num == "1") {
         while(entrada >> palabra) {
            string palabra_final = limpiar_palabra(palabra);
            //agrego palabra a la salida si no es un stopword
            if (!stopwords.count(palabra_final)) {
                salida << palabra_final << endl;
            }
        } 
    }

    else {
        while(entrada >> palabra) {
            string palabra_final = limpiar_palabra(palabra);
            //agrego palabra a la salida si no es un stopword
            if (!stopwords.count(palabra_final)) {
                salida << palabra_final << " ";
            }
        }
        salida << endl;
    }
    entrada.close();
    salida.close();
}

int main() {
    //manejamos los stopwords
    unordered_set<string> stopwords = obtener_stopwords();
    
    cout << "Pulsa 1 si quieres generar el documento base para el 1er experimento." << endl;
    cout << "Pulsa 2 si quieres generar el documento base para el 2o experimento." << endl;
    string num;
    cin >> num;
    while (num != "1" && num != "2") {
        cout << "La opción no es válida." << endl;
        cin >> num;
    }

    procesar_texto("documento_original.txt", "documento_salida.txt", stopwords, num);
}
