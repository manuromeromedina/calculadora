#include "calcu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits> //para el clear();
using namespace std;


double Calculator::suma(double num1, double num2) {
    return num1 + num2;
}

double Calculator::resta(double num1, double num2) {
    return num1 - num2;
}

double Calculator::multi(double num1, double num2) {
    return num1 * num2;
}

double Calculator::division(double num1, double num2) {
    if(num2 != 0)
        return num1 / num2;
    else
        return 0;
}

int main(){
    double num1, num2, resultado;
    int operacion;
    string simb_operacion;
    Calculator calculator;
    ofstream  file;
    file.open("resultados.txt");

    if (!file) {
    cerr << "No se pudo abrir el archivo resultados.txt" << endl;
    return 1;
        }


    cout<<"Ingrese el primer numero: ";

    while(!(cin>>num1)){
        cout<<"No ingresaste un numero. Vuelva a ingresar un numero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout<<"Ingrese el segundo numero: ";

    while(!(cin>>num2)){
        cout<<"No ingresaste un numero. Vuelva a ingresar un numero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    cout<<"1- SUMA "<<endl;
    cout<<"2- RESTA "<<endl;
    cout<<"3- DIVISION "<<endl;
    cout<<"4- MULTIPLICACION "<<endl;
    cout<<"Ingrese el valor correspondiente a la operacion: ";
    cin>>operacion;

    switch (operacion){
    case 1:
        resultado=calculator.suma(num1,num2);
        simb_operacion="+";
        break;
    case 2:
        resultado=calculator.resta(num1,num2);
        simb_operacion="-";
        break;
    case 3:
        resultado=calculator.division(num1,num2);
        simb_operacion="/";
        break;
    case 4:
        resultado=calculator.multi(num1,num2);
        simb_operacion="*";
        break;
    }

    file<< num1 << " "<< simb_operacion << " " << num2 << " = " << resultado<<endl;

    file.close();
    if (!file) {
    cerr << "Hubo un error al cerrar el archivo resultados.txt" << endl;
    return 1;
}

    return 0;


}


