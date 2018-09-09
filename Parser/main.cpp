//
//  main.cpp
//  Parser
//
//  Created by Tony David on 04/09/18.
//  Copyright © 2018 Tony David. All rights reserved.
//

#include <iostream>
#include "Parser.h"
#include "Scanner.h"


int main(int argc, const char * argv[]) {
    string phrase;
    cin>>phrase;
    bool scanner = false;
    scanner = Scanner(phrase);
    if (scanner == true){
        parser(phrase);
    }
    return 0;
}
