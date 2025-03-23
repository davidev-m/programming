#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <stdexcept>
using namespace std;

// Función que devuelve la precedencia de un operador.
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Aplica el operador 'op' a los operandos 'a' y 'b'.
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("División por cero");
            return a / b;
    }
    return 0;
}

// Evalúa la expresión matemática pasada como cadena.
double evaluate(const string &expr) {
    stack<double> values;  // Pila de valores (operandos)
    stack<char> ops;       // Pila de operadores

    for (size_t i = 0; i < expr.length(); i++) {
        // Ignorar espacios en blanco.
        if (expr[i] == ' ') continue;

        // Si encontramos un dígito o un punto decimal, extraemos el número completo.
        if (isdigit(expr[i]) || expr[i] == '.') {
            string val;
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                val.push_back(expr[i]);
                i++;
            }
            values.push(stod(val));
            i--; // Ajustamos el índice ya que el for incrementará.
        }
        // Si encontramos un paréntesis de apertura, lo apilamos.
        else if (expr[i] == '(') {
            ops.push(expr[i]);
        }
        // Si encontramos un paréntesis de cierre, resolvemos hasta el paréntesis de apertura.
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty())
                ops.pop(); // Quitar el '('
        }
        // Si encontramos un operador.
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            // Resolver los operadores de mayor o igual precedencia.
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(expr[i]);
        }
    }

    // Resolvemos cualquier operador que quede.
    while (!ops.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main(){
    string expr;
    cout << "Introduce la expresión: ";
    getline(cin, expr);
    try {
        double result = evaluate(expr);
        cout << "Resultado: " << result << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
