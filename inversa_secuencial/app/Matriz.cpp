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

Matriz::Matriz(const Matriz& orig) {
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            this->matriz[i][j] = orig.matriz[i][j];
        }
    }
}

Matriz::~Matriz() {
}



/*bool Matriz::esMagico() {
    bool ok = false;
    try {
        int fila1 = (this->matriz[0][0] + this->matriz[0][1] + this->matriz[0][2]);
        int fila2 = (this->matriz[1][0] + this->matriz[1][1] + this->matriz[1][2]);
        int fila3 = (this->matriz[2][0] + this->matriz[2][1] + this->matriz[2][2]);

        int columna1 = (this->matriz[0][0] + this->matriz[1][0] + this->matriz[2][0]);
        int columna2 = (this->matriz[0][1] + this->matriz[1][1] + this->matriz[2][1]);
        int columna3 = (this->matriz[0][2] + this->matriz[1][2] + this->matriz[2][2]);

        int diagonal1 = (this->matriz[0][0] + this->matriz[1][1] + this->matriz[2][2]);
        int diagonal2 = (this->matriz[0][2] + this->matriz[1][1] + this->matriz[2][0]);

        if ((fila1 == fila2) && (fila1 == fila3)) {
            if ((columna1 == columna2) && (columna1 == columna3)) {
                if (diagonal1 == diagonal2) {
                    ok = true;
                }
            }
        }
    } catch (...) {
        ok = false;
    }
    return ok;
}*/



void Matriz::inversa_matriz()
{
   float Determinante_Matriz = 0;
   int Indice_1 = 0,Indice_2 = 0;
   Determinante_Matriz = (this->matriz[0][0]*this->matriz[1][1]*this->matriz[2][2]) + (this->matriz[0][1]*this->matriz[1][2]*this->matriz[2][0]) + (this->matriz[1][0]*this->matriz[2][1]*this->matriz[0][2]) - (this->matriz[2][0]*this->matriz[1][1]*this->matriz[0][2]) - (this->matriz[1][0]*this->matriz[0][1]*this->matriz[2][2]) - (this->matriz[2][1]*this->matriz[1][2]*this->matriz[0][0]);
   float Adjunta[3][3];
   Adjunta[0][0] = this->matriz[1][1]*this->matriz[2][2] - this->matriz[2][1]*this->matriz[1][2];
   Adjunta[0][1] = (this->matriz[1][0]*this->matriz[2][1] - this->matriz[2][0]*this->matriz[1][2])*-1;
   Adjunta[0][2] = this->matriz[1][0]*this->matriz[2][1] - this->matriz[2][0]*this->matriz[1][1];
   Adjunta[1][0] = (this->matriz[0][1]*this->matriz[2][2] - this->matriz[2][1]*this->matriz[0][2])*-1;
   Adjunta[1][1] = this->matriz[0][0]*this->matriz[2][2] - this->matriz[2][0]*this->matriz[0][2];
   Adjunta[1][2] = (this->matriz[0][0]*this->matriz[2][1] - this->matriz[2][0]*this->matriz[0][1])*-1;
   Adjunta[2][0] = this->matriz[0][1]*this->matriz[1][2] - this->matriz[1][1]*this->matriz[0][2];
   Adjunta[2][1] = (this->matriz[0][0]*this->matriz[1][2] - this->matriz[1][0]*this->matriz[0][2])*-1;
   Adjunta[2][2] = this->matriz[0][0]*this->matriz[1][1] - this->matriz[1][0]*this->matriz[0][1];
   for(Indice_1 = 0;Indice_1 < 3;Indice_1++)
   {
       for(Indice_2 = 0;Indice_2 < 3;Indice_2++)
       {
           matriz_inversa[Indice_1][Indice_2] = (1/Determinante_Matriz)*(Adjunta[Indice_1][Indice_2]);
       }
   }
}
std::string Matriz::toString() {
   std::stringstream ss;
   ss << '[' << this->matriz_inversa[0][0] << ',' << this->matriz_inversa[0][1] << ',' << this->matriz_inversa[0][2] << ';' << this->matriz_inversa[1][0] << ',' << this->matriz[1][1] << ',' << this->matriz_inversa[1][2] << ';' << this->matriz_inversa[2][0] << ',' << this->matriz_inversa[2][1] << ',' << this->matriz_inversa[2][2] << ']' << std::endl;
   return ss.str();
}
