#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <locale>
#include <codecvt>
#include <cwctype>
#include <unordered_set>

using namespace std;

unordered_set<string> obtener_palabras_diferentes(const unordered_set<string>& stopwords) {
    //abrimos el documento
    ifstream archivo("documento_original.txt");

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
    }
    
    unordered_set<string> palabras_diferentes;
    string palabra;

    while (archivo >> palabra) {
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

        //agrego palabra al set si no es un stopword
        if (!stopwords.count(palabra_final)) {
            palabras_diferentes.insert(palabra_final);
        }
    }

    archivo.close();

    return palabras_diferentes;
}

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

/*usamos un unordered set para ver cuantas palabras diferentes hay porque
nos da igual el orden, solo nos interesa que no sean palabras repetidas*/
int main() {
    //manejaemos los stopwords
    unordered_set<string> stopwords = obtener_stopwords();

    //manejamos las palabras diferentes del documento
    unordered_set<string> palabras_doc_original = obtener_palabras_diferentes(stopwords);

    if (palabras_doc_original.size() <= 50) {
        cout << "El texto no tiene 50 palabras diferentes." << endl;
    }
    else {
        ofstream archivo("palabras_diferentes.txt");
        if (!archivo) {
            cerr << "Error al abrir el archivo para escribir." << endl;
        }

        for (const string& palabra : palabras_doc_original) {  // Recorrer el set
            archivo << palabra << endl;  // Escribir cada palabra en una nueva línea
        }

        archivo.close();
    }
}
