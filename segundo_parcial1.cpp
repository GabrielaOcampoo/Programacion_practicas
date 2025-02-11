/*Escribe un programa en C++ que permita al usuario ingresar dos
vectores de tipo entero de n elementos. El segundo vector solo
debe permitir la entrada de números pares. Si el usuario intenta
ingresar un número impar, se debe solicitar que ingrese un
nuevo número. Luego, genera un tercer vector que contenga
la división de los elementos de los dos vectores (primer vector
dividido por el segundo vector). */ 

#include <iostream> //Libreria de entrada y salida.
using namespace std;



// Función para dividir dos vectores elemento por elemento
int* dividirVectores(const int* v1, const int* v2, int n, int& error) {
    // "error" se usará para comunicar errores a la función main
    error = 0; // Inicialmente no hay error

    // Crear un nuevo array para almacenar el resultado de la división
    int* resultado = new int[n];

    // Iterar sobre los elementos de los vectores y realizar la división
    for (int i = 0; i < n; ++i) {
        // Verificar si el divisor es cero
        if (v2[i] == 0) {
            error = 1; // Código de error para división por cero
            delete[] resultado; // Liberar memoria antes de salir
            return nullptr; // Devolver nullptr para indicar error
        }
        // Realizar la división y guardar el resultado en el array resultado
        resultado[i] = v1[i] / v2[i];
    }
    // Devolver el array con el resultado de la división
    return resultado;
}

int main() {
    int n;
    // Pedir al usuario la longitud de los vectores y validar que sea un número positivo
    do {
        cout << "Por favor, ingrese la longitud de los vectores (debe ser un numero positivo): ";
        cin >> n;
        if (n <= 0) {
            cout << "Error. La longitud debe ser positiva. Intente de nuevo \n";
        }
    } while (n <= 0);

    // Crear los arrays v1 y v2 con la longitud especificada
    int* v1 = new int[n];
    int* v2 = new int[n];

    // Pedir al usuario los elementos del primer vector
    cout << "Por favor, ingrese los elementos del primer vector:\n";
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }

    // Pedir al usuario los elementos del segundo vector (solo números pares)
    cout << "Por favor, ingrese los elementos del segundo vector (solo numeros pares):\n";
    for (int i = 0; i < n; ++i) {
        // Validar que el número ingresado sea par
        do {
            cin >> v2[i];
            if (v2[i] % 2 != 0) {
                cout << "Error. Estimado usuario usted debe ingresar un numero par. Intente de nuevo: ";
            }
        } while (v2[i] % 2 != 0);
    }

    // Dividir los vectores y manejar posibles errores
    int error;
    int* resultado = dividirVectores(v1, v2, n, error);

    if (error == 0) {
        // Mostrar el vector resultado si no hubo errores
        cout << "El Vector Resultante es:\n";
        for (int i = 0; i < n; ++i) {
            cout << resultado[i] << " ";
        }
        cout << endl;
        delete[] resultado; // Importante: liberar la memoria reservada
    } else {
        // Mostrar mensaje de error si hubo algún problema
        cerr << "Error en la Division";
    }
        return 0;

    }
