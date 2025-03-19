/** @file program.cpp
    @brief Programa principal para procesamiento de texto.
*/

/** @mainpage Ejecución de diferentes funciones sobre un texto.
    La práctica se resume en generar una serie de textos en función de unas características, y generar comparaciones entre los documentos generados para mirar la similitud.
*/

#include <iostream>
#include "Text_utils.hh"
#include "Word_counter.hh"
#include "Text_permutator.hh"
#include "Text_processor.hh"
#include "K_Shingles.hh"
#include "K_Shingles_Permutator.hh"

using namespace std;

/** @brief Muestra todos los comandos disponibles y sus parámetros
    \pre <em>cierto</em>
    \post se imprime por pantalla el comando correspondiente
*/
void mostrar_ayuda() {
    cout << "\nComandos disponibles:" << endl;
    cout << "contar_palabras <archivo> - Cuenta palabras únicas sin stopwords." << endl;
    cout << "generar_permutaciones <archivo> <tamano> <num_permutaciones> - Genera permutaciones del texto." << endl;
    cout << "procesar_texto <archivo_entrada> <archivo_salida> <opcion> - Procesa texto eliminando stopwords." << endl;
    cout << "generar_k_shingles <archivo_entrada> <archivo_salida> <k> - Genera k-shingles del texto." << endl;
    cout << "generar_permutaciones_k_shingles <archivo> <tamano> <num_permutaciones> <n> - Permuta k-shingles." << endl;
    cout << "mostrar_comandos - Muestra esta lista de comandos." << endl;
    cout << "fin - Finaliza la ejecución del programa." << endl;
    cout << endl;
}

/** @brief Programa principal 
*/
int main() {
    string comando;
    cout << "Ingrese un comando ('mostrar_comandos' para ayuda, 'fin' para salir):\n";
    cin >> comando;

    while (comando != "fin") {
        if (comando == "contar_palabras") {
            string archivo;
            cin >> archivo;
            cout << "# " << comando << " " << archivo << endl;
            int resultado = Word_counter::contpalabras(archivo);
            if (resultado != -1) cout << "El archivo tiene " << resultado << " palabras únicas sin stopwords." << endl;
            cout << endl;
        }
        else if (comando == "generar_permutaciones") {
            string archivo;
            int tamano, num_permutaciones;
            cin >> archivo >> tamano >> num_permutaciones;
            cout << "# " << comando << " " << archivo << " " << tamano << " " << num_permutaciones << endl;
            Text_permutator::generar_permutaciones(archivo, tamano, num_permutaciones);
            cout << endl;
        }
        else if (comando == "procesar_texto") {
            string archivo_entrada, archivo_salida, opcion;
            cin >> archivo_entrada >> archivo_salida >> opcion;
            cout << "# " << comando << " " << archivo_entrada << " " << archivo_salida << " " << opcion << endl;
            Text_processor::procesar_texto(archivo_entrada, archivo_salida, opcion);
            cout << endl;
        }
        else if (comando == "generar_k_shingles") {
            string archivo_entrada, archivo_salida;
            int k;
            cin >> archivo_entrada >> archivo_salida >> k;
            cout << "# " << comando << " " << archivo_entrada << " " << archivo_salida << " " << k << endl;
            K_Shingles::generar_k_shingles(archivo_entrada, archivo_salida, k);
            cout << endl;
        }
        else if (comando == "generar_permutaciones_k_shingles") {
            string archivo;
            int tamano, num_permutaciones, n;
            cin >> archivo >> tamano >> num_permutaciones >> n;
            cout << "# " << comando << " " << archivo << " " << tamano << " " << num_permutaciones << " " << n << endl;
            K_Shingles_Permutator::generar_permutaciones(archivo, tamano, num_permutaciones, n);
            cout << endl;
        }
        else if (comando == "mostrar_comandos") {
            mostrar_ayuda();
        }
        else {
            cout << "Comando no reconocido. Escriba 'mostrar_comandos' para ver la lista de comandos." << endl;
            cout << endl;
        }

        cin >> comando;
    }

    cout << "Fin del programa." << endl;
    return 0;
}