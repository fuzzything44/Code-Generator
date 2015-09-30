#include "stdafx.h"
#include <iostream>
#include "genName.h"
#include "logger.h"
#include "globalNamespace.h"
#include <typeinfo>

using std::cout;
using std::string; 
using std::cin;
using std::endl;

#define TEST_NAME_GEN


int main() {
    
    logger::init("Name generator");
    genName::init();
    int i = 5;
#ifdef TEST_NAME_GEN
    while (true) {
        cout << "Enter name type: ";
        string s;
        cin >> s;
        cout << genName::get(s) << endl;
    }
#else
    globalNamespace g;
    g.generate(5);
#endif
    
    logger::close();
}

