//
//  Scanner.h
//  Parser
//
//  Created by Tony David on 04/09/18.
//  Copyright © 2018 Tony David. All rights reserved.
//

#ifndef Scanner_h
#define Scanner_h
#include <iostream>
#include <string>
using namespace std;
//El scanner debe generar e imprimir la lista de tokens derivados del análisis.
//Si el scanner encuentra un error, debe detenerse y mostrar el mensaje correcto en la pantalla

//Matriz de transiciones.
//[estado no final, transicion]
//estados > 6 = no finales
//estados == 6 = final
//10 == caracter no permitido



int MatrizLaws[3][8]={
    //{1-9}, 0, {a-z}, (), op, ;, otro
    /* Estado 0 */{1, 999, 2, 103, 999, 105,999},
    /* Estado 1 */{1, 1, 999, 106, 106, 106, 999},   //numero
    /* Estado 2 */{2, 2, 2, 106, 106, 106, 999}     //letras y numeros
};

int error = 999;

//Metodo que controlará la matriz de estados y transiciones;
//Retornará la columna del valor ingresado
int matrixController(char token){
    
    //Si son numeros de 1 a 9
    if (token >= 49 && token <= 57){
        return 0;
    }
    
    //si es 0
    if(token == 48){
        return 1;
    }
    
    //si son letras A-Z o a-z
    if((token >= 65 && token <= 90) || (token >= 97 && token <= 122) ){
        return 2;
    }
    
    //si son parentesis
    if(token == '(' | token == ')'){
        return 3;
    }
    
    //si es un operador
    if(token == '+' | token == '-' | token == '*' | token == '/'){
        return 4;
    }
    
    //si es ;
    if (token == ';'){
        return 5;
    }
    //si es cualqueir otro caracter no permitido
    else{
        return 6;
    }
}

void encontrarError(string sVariable){
    
    if(sVariable[sVariable.length()-1] != ';'){
        cout<<"Cada que termines de escrbir una linea debes de poner un ; "<<endl;
        return;}
    
    if((sVariable[0] >= 65 && sVariable[0] <= 90) || (sVariable[0] >= 97 && sVariable[0] <= 122) ){
        cout<<"Variables solo empiezan con una letra seguidos unicamente de numeros o más letras"<<endl;
        return ;
        
    }
    
    if(sVariable[0] == '('|| sVariable[0] == ')'){
        cout<<"Parentesis solo van seguidos de más parentesis"<<endl;
        return;}
    
    if(sVariable[0] == '+' | sVariable[0] == '-' | sVariable[0] == '*' | sVariable[0] == '/'){
        cout<<"No puedes usar operadores si no hay dos numeros o variables que usar"<<endl;
        return;
    }
    
    if ((sVariable[1] >= 48 && sVariable[1] <= 57) || sVariable[0] == '0' ){
        cout<<"Numeros no pueden comenzar con 0 y solo van seguidos de más numeros"<<endl;
        return;}
}

bool Scanner(string sVariable){
    bool flag = true;
    int state = 0, token = 0, transition = 0;
    while (token < sVariable.length()) {
        string value;
        transition = matrixController(sVariable[token]);
        state = MatrizLaws[state][transition];
        token++;
        if (state == error){
            encontrarError(sVariable);
            flag = false;
            return flag;}
        if (state > 100) {
            token--;
            return flag;}
        else{
            value.push_back(sVariable[token]);
        }
    }
    return flag;
}

#endif /* Scanner_h */
