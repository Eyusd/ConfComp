#include "calc.h"
#include <stdio.h>
#include <openenclave/enclave.h>
#include <iostream>
#include <string>

double parser(string str, double* output){
    double res = 0;
    string a,b;
    double anum,bnum;

    if (str.find('+') != -1) {
        a = str.substr(0, str.find('+'));
        b = str.substr(str.find('+')+1, str.length());
        anum = stof(a);
        bnum = stof(b);
        res = anum+bnum;
    }
    if (str.find('-') != -1) {
        a = str.substr(0, str.find('-'));
        b = str.substr(str.find('-')+1, str.length());
        anum = stof(a);
        bnum = stof(b);
        res = anum-bnum;
    }
    if (str.find('*') != -1) {
        a = str.substr(0, str.find('*'));
        b = str.substr(str.find('*')+1, str.length());
        res = anum*bnum;
    }
    if (str.find('/') != -1) {
        a = str.substr(0, str.find('/'));
        b = str.substr(str.find('/')+1, str.length());
        anum = stof(a);
        bnum = stof(b);
        res = anum/bnum;
    }
    return res;
}


double ecall_dispatcher::parser(string str)
{
    return parser(str);
}