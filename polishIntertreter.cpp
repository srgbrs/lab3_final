#include <iostream>
#include <string>
#include "StackHeader.h"
#include <cmath>
#include <math.h>

#define is_letter(c) (c >= 'a' && c <= 'z')
#define is_function(c) (c == 'sin' || c == 'cos' || c == 'tan' || c == 'ctan')

using namespace std;

double functCalc (string &funct, double &value)
{
    double result;
    
    if (funct == "")
        result = value;
    else
        if (funct == "sin")
            result = sin(value);
        else
            if (funct == "cos")
                result = cos(value);
            else
                if (funct == "tan")
                    result = tan(value);
                else
                {
                    result = 0.0;
                    cout << "Unknown function" << endl;
                    exit(1);
                }
    
    return result;
}


double Interpreter(string &line) {
    Stack <double> CalcString;
    double num1, num2;
    double result;
    
    int i=0;
    string num, funct = "";
    
    while (i < line.length())
    {
        if(is_letter(line[i])) // Если функция
        {
            funct = funct + line[i];
           // cout << "funct: " << funct << endl;
            i++;
        }
        
        else if (isdigit(line[i]) || line[i] == '.')
        {
            num = num + line[i];
            
            if ((!isdigit(line[i+1])) && !(line[i+1] == '.') ) // если след знак - не число
            {
    
                double value = stod(num);
                CalcString.push(functCalc(funct, value));
//            cout << "pushing " << functCalc(funct, value) << " with funct [" << funct << "], value: " << value << endl;
             //   cout << "stack top: " << CalcString.top() << endl;
         
                num = ""; funct = "";
            }
            i++;
        }
        else if (line[i] == ' ')
        {
            i++;
        }
        
        else { // Если оператор
           // cout << endl;
            
                num2 = CalcString.top();
                CalcString.pop();
                num1 = CalcString.top();
                CalcString.top();
                switch(line[i])
                {
                    case'+':result = num1 + num2;
                        break;
                    case '-':result = num1 - num2;
                        break;
                    case '*':result = num1 * num2;
                        break;
                    case '/':result = num1 / num2;
                        break;
                    case '^':result = pow(num1, num2);
                        break;
                    default: cout << "Result could not be found.\n";
                        break;
                }
                CalcString.push(result);
                i++;
           // cout << endl;
            }
        }
    
        return CalcString.top();
    }

