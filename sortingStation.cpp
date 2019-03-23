#include <stdio.h>
#include <iostream>
#include <string>
#include "Header.h"

#include "StackHeader.h"
#include "QueueHeader.h"

//#include <stack> // Стандартные библиотеки - ЗАМЕНИТЬ
//#include <queue>

using namespace std;

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '%' || c == '^')
#define is_function(c) (c == 'sin' || c == 'cos' || c == 'tan' || c == 'ctan')
#define is_letter(c) (c >= 'a' && c <= 'z')

string toPostfix( string &line) {
    
    Stack<char> stack;
    Queue<string> outQueue;
    
    string result, num, top="", funct;
    
    int i = 0; // counter
    
    while (i < line.length())
    {
        
        if (isdigit(line[i]) || line[i] == '.')
        {
            num = num + line[i];
            
            if (!isdigit(line[i+1]) && !(line[i+1] == '.')) // если след знак - не число
            {
                //cout << "pushing " << num << endl;
                outQueue.push(num);
                num = "";
            }
            i++;
        }
        
        else if (is_letter(line[i])) // Если функция
        {
            funct = funct + line[i];
            if (!is_letter(line[i+1]))
            {
                outQueue.push(funct);
                funct = "";
            }
            i++;
        }
        
        else if (is_operator(line[i])) // Если оператор
        {
            while (!stack.empty())
            {
                if (is_operator(stack.top())
                    && (op_priority(line[i]) <= op_priority(stack.top())))
                {
                    top = stack.top();
                    outQueue.push(top);
                    stack.pop();
                }
                else break;
            }
            
            stack.push(line[i]);
            i++;
        }
        
        else if (line[i] == '(')
        {
            stack.push(line[i]);
            i++;
        }
        
        else if (line[i] == ')')
        {
            bool logic = false;
            // До появления на вершине стека левой скобки перекладывать операторы из стека в очередь вывода
            while (!stack.empty())
            {
                if (stack.top() == '(')
                {
                    logic = true;
                    break;
                }
                else
                {
                    top = stack.top();
                    outQueue.push(top);
                    stack.pop();
                }
            }
            // Если стек кончится до нахождения левой скобки, то была пропущена скобка
            if(!logic)
            {
                cout << "Error: bracket mismatched\n";
                exit(1);
            }
            // выкидываем левую скобку из стека (не добавляем в очередь вывода)
            stack.pop();
            i++;
        }
        else
            i++;
        
    }
    
    while (!stack.empty())
    {
        if((stack.top() == '(') || (stack.top() == ')'))
        {
            cout << "Error: parentheses mismatched\n" ;
            return 0;
        }
        
        top = stack.top();
        outQueue.push(top);
        stack.pop();
    }
    
    while (!outQueue.empty())
    {
        result += outQueue.front();
        result += " ";
        outQueue.pop();
    }
    return result;
}

int op_priority(const char c) // Приоритет булевой операции
{
    switch(c)
    {
        case '*':
        case '^':
        case '%':
        case '/':
            return 2;
            
        case '+':
        case '-':
            return 1;
    }
    return 0;
}
