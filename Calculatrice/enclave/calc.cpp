#include "calc.h"
#include <openenclave/enclave.h>
#include <iostream>

int find(char s[256], char ch){
	int i = 0;
	int len = 256;

	for(i = 0; i < len; i++) if(s[i] == ch) return i;

	return -1;
}

double ecall_dispatcher::parser(char str[256])
{
    double res = 2;
    int a;
    int b;
    double anum;
    double bnum;

    if (find(str, '+') != -1) {
        a = atoi(str);
        b = atoi(str+find(str,'+')+1);
        anum = (double) a;
        bnum = (double) b;
        res = anum+bnum;
    }
    if (find(str, '-') != -1) {
        a = atoi(str);
        b = atoi(str+find(str,'-')+1);
        anum = (double) a;
        bnum = (double) b;
        res = anum-bnum;
    }
    if (find(str, '*') != -1) {
        a = atoi(str);
        b = atoi(str+find(str,'*')+1);
        anum = (double) a;
        bnum = (double) b;
        res = anum*bnum;
    }
    if (find(str, '/') != -1) {
        a = atoi(str);
        b = atoi(str+find(str,'/')+1);
        anum = (double) a;
        bnum = (double) b;
        res = anum/bnum;
    }

    float f;
    f = (float) res;

    return f;
}