#include <iostream>
#include <string>
#include "Header.h"
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string line;
    
    if (argc == 1)
    {
        cout << endl;
        getline(cin, line);
    }
    else
    {
        for (int i=1; i<argc; i++)
            line = line + argv[i];
    }

    
    cout << "Postfix form: " << toPostfix(line) << endl;
    line = toPostfix(line);
  cout << "Result = " << setprecision(4)<< Interpreter(line) << endl;

//    system("pause");
    
    return 0;
}
