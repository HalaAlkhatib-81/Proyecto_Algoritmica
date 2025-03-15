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

    /*for (char c : palabra) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            c = tolower(c);
            palabra_final += c;
        }
    }*/

    return palabra_final;
}

//esta función cuenta cuántas palabras diferentes que no son stopwords tiene un texto
int contador_palabras(const string& archivo_entrada, const unordered_set<string>& stopwords) {
    ifstream archivo(archivo_entrada);

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
    }
    
    unordered_set<string> palabras_diferentes;
    string palabra;

    while (archivo >> palabra) {
        //nos quedamos con la palabra sola, en minúsculas y sin signos de puntuación y agregamos en el set solo si no es stopword
        string palabra_final = limpiar_palabra(palabra);
        //agrego palabra al set si no es un stopword
        if (!stopwords.count(palabra_final)) {
            palabras_diferentes.insert(palabra_final);
        }
    }

    archivo.close();

    return palabras_diferentes.size();
}

/*usamos un unordered set para ver cuantas palabras diferentes hay porque
nos da igual el orden, solo nos interesa que no sean palabras repetidas*/
int main() {
    //manejaemos los stopwords
    unordered_set<string> stopwords = obtener_stopwords();

    int cont = contador_palabras("documento_original.txt", stopwords);

    cout << "Tu documento tiene " << cont << " palabras diferentes que no son stopwords." << endl;
}
