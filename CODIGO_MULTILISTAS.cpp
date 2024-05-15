#include "CODIGO_MULTILISTAS.h"

Receta::Receta(int id, string nombre, Ingrediente* ingredientes, int num_ingredientes, int tiempo_preparacion, int tiempo_coccion, int porciones, string nivel_dificultad, string categoria, string origen, ValorNutricional valor_nutricional)
    : id(id), nombre(nombre), ingredientes(ingredientes), num_ingredientes(num_ingredientes), tiempo_preparacion(tiempo_preparacion), tiempo_coccion(tiempo_coccion), porciones(porciones), nivel_dificultad(nivel_dificultad), categoria(categoria), origen(origen), valor_nutricional(valor_nutricional), siguiente(nullptr) {}

MultilistaRecetas::MultilistaRecetas() : cabeza_recetas(nullptr) {}

void MultilistaRecetas::agregarReceta(Receta* nueva_receta) {
    if (!cabeza_recetas) {
        cabeza_recetas = nueva_receta;
    }
    else {
        Receta* temp = cabeza_recetas;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nueva_receta;
    }
}

void MultilistaRecetas::imprimirRecetas() {
    Receta* temp = cabeza_recetas;
    while (temp) {
        cout << "|*|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|*|" << endl;
        cout << "ID ==>  " << temp->id << endl;
        cout << "Nombre ==>  " << temp->nombre << endl;
        cout << "Ingrediente : " << endl;
        for (int i = 0; i < temp->num_ingredientes; ++i) {
            cout << "  - " << temp->ingredientes[i].nombre << ": " << temp->ingredientes[i].cantidad << endl;
        }
        cout << "Tiempo de preparacion ==> " << temp->tiempo_preparacion << " minutos" << endl;
        cout << "Tiempo de coccion ==> " << temp->tiempo_coccion << " minutos" << endl;
        cout << "Porciones ==> " << temp->porciones << endl;
        cout << "Nivel de dificultad ==> " << temp->nivel_dificultad << endl;
        cout << "Categoria ==> " << temp->categoria << endl;
        cout << "Origen ==> " << temp->origen << endl;
        cout << endl;
        cout << "----Valor nutricional----" << endl;
        cout << "*  Calorias: " << temp->valor_nutricional.calorias << endl;
        cout << "*  Grasas: " << temp->valor_nutricional.grasas << "g" << endl;
        cout << "*  Proteinas: " << temp->valor_nutricional.proteinas << "g" << endl;
        cout << "*  Carbohidratos: " << temp->valor_nutricional.carbohidratos << "g" << endl;
        cout << "*  Otros: " << temp->valor_nutricional.otros << "g" << endl;
        cout << "|*|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|*|" << endl;
        temp = temp->siguiente;
    }
}

int main() {
    MultilistaRecetas multilistaRecetas;

    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        // Pedir al usuario los detalles de la receta
        int id, num_ingredientes, tiempo_preparacion, tiempo_coccion, porciones;
        string nombre, nivel_dificultad, categoria, origen;
        Ingrediente* ingredientes;
        ValorNutricional valor_nutricional;

        cout << "Ingrese el ID de la receta: ";
        cin >> id;
        cout << "Ingrese el nombre de la receta: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese el numero de ingredientes: ";
        cin >> num_ingredientes;

        // Crear arreglo de ingredientes dinámicamente
        ingredientes = new Ingrediente[num_ingredientes];
        for (int i = 0; i < num_ingredientes; ++i) {
            cout << "Ingrese el nombre del ingrediente " << i + 1 << ": ";
            cin >> ingredientes[i].nombre;
            cout << "Ingrese la cantidad de " << ingredientes[i].nombre << ": ";
            cin >> ingredientes[i].cantidad;
        }

        cout << "Ingrese el tiempo de preparacion en minutos: ";
        cin >> tiempo_preparacion;
        cout << "Ingrese el tiempo de coccion en minutos: ";
        cin >> tiempo_coccion;
        cout << "Ingrese el numero de porciones: ";
        cin >> porciones;
        cout << "Ingrese el nivel de dificultad: ";
        cin >> nivel_dificultad;
        cout << "Ingrese la categoria: ";
        cin >> categoria;
        cout << "Ingrese el origen: ";
        cin.ignore();
        getline(cin, origen);

        cout << "Ingrese el valor nutricional:" << endl;
        cout << "Calorias: ";
        cin >> valor_nutricional.calorias;
        cout << "Grasas: ";
        cin >> valor_nutricional.grasas;
        cout << "Proteinas: ";
        cin >> valor_nutricional.proteinas;
        cout << "Carbohidratos: ";
        cin >> valor_nutricional.carbohidratos;
        cout << "Otros: ";
        cin >> valor_nutricional.otros;

        // Crear la receta y agregarla a la multilista
        Receta nueva_receta(id, nombre, ingredientes, num_ingredientes, tiempo_preparacion, tiempo_coccion, porciones, nivel_dificultad, categoria, origen, valor_nutricional);
        multilistaRecetas.agregarReceta(&nueva_receta);

        // Liberar la memoria del arreglo de ingredientes
        delete[] ingredientes;

        cout << "¿Desea ingresar otra receta? (s/n): ";
        cin >> continuar;
    }

    // Imprimir todas las recetas almacenadas en la multilista
    multilistaRecetas.imprimirRecetas();

    return 0;
}