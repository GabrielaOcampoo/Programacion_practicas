/* Definir un struct Carnet para guardar la información de N
estudiantes, se debe incluir nombre, apellido, edad, cédula,
genero, semestre que cursa y promedio general. El nombre,
apellido, semestre y cédula deben ser cadenas de caracteres,
la edad es entero, promedio double y el género es char (M/F).
Además de ingresar y mostrar los datos, se debe realizar lo
siguiente: si el género es F, contar al estudiante en un grupo
denominado MUJERES, caso contrario contar al mismo en el
grupo VARONES, al final se debe mostrar el número de
estudiantes que integra cada grupo, además, sumar los dígitos
de la edad y mostrar el resultado (para poder sumar y asegurar
que se tiene los dos dígitos se debe controlar que se ingresen
números mayores o iguales a 10 hasta el 99, si ingresa de forma
incorrecta volver a pedir hasta que se ingrese bien) */


#include <iostream> //Libreria de estrada y salida.
#include <vector> //Libreria para vectores.
#include <string> //Libreria para cadena de caracteres.
using namespace std;

// Definición de la estructura Carnet
struct Carnet {
    string nombre;
    string apellido;
    int edad;
    string cedula;
    char genero; // 'M' para masculino, 'F' para femenino
    string semestre;
    double promedio;
};

// Función para validar la edad (entre 10 y 99)
int validarEdad() {
    int edad;
    do {
        cout << "Ingrese la edad (entre 10 y 99): ";
        cin >> edad;
        if (edad < 10 || edad > 99) {
            cout << "Error: La edad debe estar entre 10 y 99. Intente de nuevo.\n";
        }
    } while (edad < 10 || edad > 99);
    return edad;
}

// Función para ingresar los datos de los estudiantes
void ingresarDatos(vector<Carnet> &estudiantes, int &mujeres, int &varones) {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Carnet estudiante;
        cout << "\nIngresando datos del estudiante " << i + 1 << ":\n";
        cout << "Nombre: ";
        cin >> estudiante.nombre;
        cout << "Apellido: ";
        cin >> estudiante.apellido;
        estudiante.edad = validarEdad();
        cout << "Cédula: ";
        cin >> estudiante.cedula;
        
        // Validación del género
        do {
            cout << "Género (M/F): ";
            cin >> estudiante.genero;
            estudiante.genero = toupper(estudiante.genero); // Convertir a mayúscula
            if (estudiante.genero != 'M' && estudiante.genero != 'F') {
                cout << "Error: Género inválido. Intente de nuevo.\n";
            }
        } while (estudiante.genero != 'M' && estudiante.genero != 'F');

        cout << "Semestre: ";
        cin >> estudiante.semestre;
        cout << "Promedio general: ";
        cin >> estudiante.promedio;

        // Contar en el grupo correspondiente
        if (estudiante.genero == 'F') {
            mujeres++;
        } else {
            varones++;
        }

        estudiantes.push_back(estudiante);
    }
}

// Función para mostrar los datos de los estudiantes
void mostrarDatos(const vector<Carnet> &estudiantes) {
    cout << "\nLista de estudiantes:\n";
    for (const auto &estudiante : estudiantes) {
        cout << "--------------------------------------\n";
        cout << "Nombre: " << estudiante.nombre << " " << estudiante.apellido << endl;
        cout << "Edad: " << estudiante.edad << endl;
        cout << "Cédula: " << estudiante.cedula << endl;
        cout << "Género: " << estudiante.genero << endl;
        cout << "Semestre: " << estudiante.semestre << endl;
        cout << "Promedio: " << estudiante.promedio << endl;
        
        // Sumar los dígitos de la edad
        int suma_digitos = (estudiante.edad / 10) + (estudiante.edad % 10);
        cout << "Suma de los dígitos de la edad: " << suma_digitos << endl;
    }
    cout << "--------------------------------------\n";
}

int main() {
    vector<Carnet> estudiantes;
    int mujeres = 0, varones = 0;

    // Ingresar datos
    ingresarDatos(estudiantes, mujeres, varones);
    
    // Mostrar datos
    mostrarDatos(estudiantes);
    
    // Mostrar cantidad de estudiantes en cada grupo
    cout << "\nTotal de mujeres: " << mujeres << endl;
    cout << "Total de varones: " << varones << endl;

    return 0;
}
