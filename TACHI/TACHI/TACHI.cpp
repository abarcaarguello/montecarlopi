#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double monteCarloPi(int totalPoints) {
    int insideCircle = 0;
    srand(time(nullptr)); // Inicializar la semilla para generar números aleatorios

    for (int i = 0; i < totalPoints; ++i) {
        double x = static_cast<double>(rand()) / RAND_MAX; // Coordenada x aleatoria entre 0 y 1
        double y = static_cast<double>(rand()) / RAND_MAX; // Coordenada y aleatoria entre 0 y 1

        // Distancia desde el origen
        double distance = sqrt(x * x + y * y);

        // Si el punto está dentro del círculo (distancia <= 1), lo contamos
        if (distance <= 1) {
            insideCircle++;
        }
    }

    // Aproximación de π utilizando el área del cuadrado y del círculo
    return 4.0 * insideCircle / totalPoints;
}

int main() {
    int totalPoints = 1000000; // Número total de puntos a generar
    double piApproximation = monteCarloPi(totalPoints);

    // Mostrar la aproximación de π
    cout << "Valor aproximado de pi es: " << piApproximation << endl;

    return 0;
}
// Alexis Adrian Abarca Arguello
