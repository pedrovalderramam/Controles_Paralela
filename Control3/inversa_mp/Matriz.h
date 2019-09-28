#ifndef MATRIZ_H
#define MATRIZ_H

#define LARGO 3

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Matriz {
public:
    Matriz();
    Matriz(const std::string& orig);
    Matriz(const Matriz& orig);
    virtual ~Matriz();

    void llenar(const std::string& orig);
    void matrizInversa(double[3][3]);
    std::string toString(double[3][3]);
private:
    int matriz[LARGO][LARGO];
};

#endif /* MATRIZ_H */

