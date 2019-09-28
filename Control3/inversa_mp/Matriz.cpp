#include "Matriz.h"

Matriz::Matriz() {
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            // Inicializamos con valores que no sean cuadrados mágicos
            this->matriz[i][j] = (i * j);
        }
    }
}

Matriz::Matriz(const std::string& orig) {
    llenar(orig);
}

Matriz::Matriz(const Matriz& orig) {
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            this->matriz[i][j] = orig.matriz[i][j];
        }
    }
}

Matriz::~Matriz() {
}

void Matriz::llenar(const std::string& orig) {
    try {
        Matriz();
        std::string linea(orig.c_str());
        if (!linea.empty()) {
            // Quitamos caracters innecesarios
            linea.erase(std::remove(linea.begin(), linea.end(), '['), linea.end());
            linea.erase(std::remove(linea.begin(), linea.end(), ']'), linea.end());

            // Obtenemos un token
            std::replace(linea.begin(), linea.end(), ';', ' ');


            std::vector<std::string> arreglo;
            std::stringstream ss(linea);
            std::string temp;
            while (ss >> temp) {
                arreglo.push_back(temp);
            }

            for (int i = 0; i < LARGO; i++) {
                std::string fila = arreglo[i];
                std::replace(fila.begin(), fila.end(), ',', ' ');

                std::vector<std::string> columnas;
                std::stringstream sf(fila);
                std::string tmp;
                while (sf >> tmp) {
                    columnas.push_back(tmp);
                }

                for (int j = 0; j < LARGO; j++) {
                    std::string valor = columnas[j];
                    int numero = atoi(valor.c_str());
                    this->matriz[i][j] = numero;
                }
            }
        }
    } catch (...) {
        Matriz();
    }
}

void Matriz::matrizInversa(double inversa [][3]) {
    double determinante=0;
    determinante+=(matriz[0][0]*matriz[1][1]*matriz[2][2]);
    determinante+=(matriz[0][1]*matriz[1][2]*matriz[2][0]);
    determinante+=(matriz[0][2]*matriz[1][0]*matriz[2][1]);
    determinante+=-1*(matriz[0][2]*matriz[1][1]*matriz[2][0]);
    determinante+=-1*(matriz[0][0]*matriz[1][2]*matriz[2][1]);
    determinante+=-1*(matriz[0][1]*matriz[1][0]*matriz[2][2]);
    if(determinante!=0)
    {
        inversa[0][0]=((matriz[1][1]*matriz[2][2])-(matriz[1][2]*matriz[2][1]))/determinante;
        inversa[1][0]=(-1*((matriz[1][0]*matriz[2][2])-(matriz[1][2]*matriz[2][0])))/determinante;
        inversa[2][0]=((matriz[1][0]*matriz[2][1])-(matriz[1][1]*matriz[2][0]))/determinante;
        inversa[0][1]=(-1*((matriz[0][1]*matriz[2][2])-(matriz[0][2]*matriz[2][1])))/determinante;
        inversa[1][1]=((matriz[0][0]*matriz[2][2])-(matriz[0][2]*matriz[2][0]))/determinante;
        inversa[2][1]=(-1*((matriz[0][0]*matriz[2][1])-(matriz[0][1]*matriz[2][0])))/determinante;
        inversa[0][2]=((matriz[0][1]*matriz[1][2])-(matriz[0][2]*matriz[1][1]))/determinante;
        inversa[1][2]=(-1*((matriz[0][0]*matriz[1][2])-(matriz[0][2]*matriz[1][0])))/determinante;
        inversa[2][2]=((matriz[0][0]*matriz[1][1])-(matriz[0][1]*matriz[1][0]))/determinante;
    }
}

std::string Matriz::toString(double inversa[][3]) {
    std::stringstream ss;
    ss << '[' << inversa[0][0] << ',' << inversa[0][1] << ',' << inversa[0][2] << ';' << inversa[1][0] << ',' << inversa[1][1] << ',' << inversa[1][2] << ';' << inversa[2][0] << ',' << inversa[2][1] << ',' << inversa[2][2] << ']' << std::endl;
    return ss.str();
}
