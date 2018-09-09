//
//  Parser.h
//  Parser
//
//  Created by Tony David on 04/09/18.
//  Copyright © 2018 Tony David. All rights reserved.
// A00819569 Antonio David

#ifndef Parser_h
#define Parser_h
#include <iostream>
#include <string>
using namespace std;

int failure = 0;

//id = 1 -> numeros
//id = 2 -> variables
//id = 3 -> op
//id = 4 -> ()
//id = 5 -> ;
void match(string &phrase, int key){
    char token = phrase[0];
    //Si viene un numero
    if(key == 1){
        if (token >= 48 && token <= 57){
            phrase.erase(0,1);
            return;
        }
        else{
            cout<<"Error, expected: number"<<endl;
            failure = 1;
            return;
        }
    }
    //si viene una variable
    if(key == 2){
        if((phrase[0] >= 48 && phrase[0] <= 57) || (phrase[0] >= 65 && phrase[0] <= 90) || (phrase[0] >= 97 && phrase[0] <= 122) ){
            phrase.erase(0,1);
            return;
        }
        else{
            cout<<"Error, expected: leter or number as variable"<<endl;
            failure = 1;
            return;
        }
    }
    
    //si viene un operador
    if(key == 3){
        if(token == '+' | token == '-' | token == '*' | token == '/' ){
            phrase.erase(0,1);
            return;
        }
        else{
            cout<<"Error, expected: operator (+ or - or * or /)"<<endl;
            failure = 1;
            return;
        }
    }
    
    //si viene un ()
    if(key == 4){
        if(token == '(' | token == ')'){
            phrase.erase(0,1);
            return;
        }
        else{
            cout<<"Error, expected: ( or )"<<endl;
            failure = 1;
            return;
        }
    }
    
    //Si viene un ;
    if(key == 5){
        if(token == ';'){
            phrase.erase(0,1);
            return;
        }
        else{
            cout<<"Error, expected: ;"<<endl;
            failure = 1;
            return;
        }
    }
}

void parseExp1(string &phrase);

void parseExp(string &phrase){
    
    cout<<"pila ="<<phrase<<endl;
    //Si son numeros de 0 a 9
    if (phrase[0] >= 48 && phrase[0] <= 57){
        match(phrase, 1);
        parseExp(phrase);
        return;
    }
    
    //Si es un variable
    if((phrase[0] >= 48 && phrase[0] <= 57) || (phrase[0] >= 65 && phrase[0] <= 90) || (phrase[0] >= 97 && phrase[0] <= 122) ){
        match(phrase, 2);
        parseExp(phrase);
        return;
    }
    
    //Si es un op
    if(phrase[0] == '+' | phrase[0] == '-' | phrase[0] == '*' | phrase[0] == '/'){
        parseExp1(phrase);
        return;
    }
    
    //Si son ()
    if(phrase[0]=='(' || phrase[0]==')'){
        match(phrase, 4);
        parseExp(phrase);
    }
    
    //Si es un ;
    if(phrase[0] == ';'){
        match(phrase, 5);
        parseExp1(phrase);
        return;
    }
    
    return;
}

void parseExp1(string &phrase){
    
    //Si es un op
    if(phrase[0] == '+' | phrase[0] == '-' | phrase[0] == '*' | phrase[0] == '/'){
        match(phrase, 3);
        parseExp(phrase);
        parseExp1(phrase);
        return;
    }
    
    if(phrase == ""){
        return;
    }
    return;
}

void parser(string tokens){
    parseExp(tokens);
     if(failure == 1){
         return;
     }
     else{
         cout<<"Frase Correcta"<<endl;
     }
}

#endif /* Parser_h */
