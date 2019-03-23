#ifndef Header_h
#define Header_h

#include <string>
using namespace std;

string toPostfix(string &str);
int op_priority(const char c);

double Interpreter(string &line);
double functCalc (string &funct, double &value);

#endif /* Header_h */
