#include <iostream>
#include <string>

using namespace std;
void parser(string str, double* output){
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
    *output = res;
}


int main()
{
    string op;
    cout << "Entre une opération : ";
    getline (cin, op);

    cout << parser(op) << endl;
}