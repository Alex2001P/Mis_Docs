#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    char op; // Variable para almacenar la operacion a realizar
    float num1, num2, resultado; // Variables para almacenar los numeros y el resultado

    do {
        // Preguntamos al usuario que operacion desea realizar
        cout << "Bienvenmidos a nuestra calculadora, solo tenemos las siguientes operaciones: "<< endl ;
        cout << "Las siguientes operaciones son:"<<endl;
        cout << "Suma = +"<<endl;
        cout << "Resta = -"<<endl;
        cout << "Multiplicacion = *"<<endl;
        cout << "Division = /"<<endl;
        cout << "Ingrese algun signo par realizar la operacion: "<<endl;
        
        cin >> op;

        // Preguntamos al usuario por los dos numeros a operar
        cout << "Ingrese el primer numero: ";
        cin >> num1;

        cout << "Ingrese el segundo numero: ";
        cin >> num2;

        // Realizamos la operacion correspondiente
        switch (op) {
            case '+':
                resultado = num1 + num2;
                break;
            case '-':
                resultado = num1 - num2;
                break;
            case '*':
                resultado = num1 * num2;
                break;
            case '/':
                resultado = num1 / num2;
                break;
            default:
                cout << "Oeracion Valida" << endl;
                continue; // Regresamos al inicio del ciclo
        }

        // Mostramos el resultado
        cout << "El resultado es: " << resultado << endl;

        // Preguntamos al usuario si desea realizar otra operacion
        cout << "¿Usted deseqa realizar otra operacion (s/n): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta == 'n') {
            break; // Salimos del ciclo
        }
    } while (true);

    cout << "Gracias por usar la calculadora!" << endl;

    return 0;
}