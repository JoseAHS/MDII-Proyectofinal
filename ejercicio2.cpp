#include <iostream>
#include <cstdlib>  // Para la generación de números aleatorios
#include <ctime>    // Para inicializar la semilla del generador de números aleatorios

using namespace std;

int main() {
    // Semilla para el generador de números aleatorios
    srand(time(0));

    // Inicialización de la urna (3 bolas negras y 2 blancas)
    int bolasNegras = 3;
    int bolasBlancas = 2;

    // Número de experimentos
    int numExperimentos = 1000000;  // Puedes ajustar este valor según sea necesario

    // Contadores para contar el número de veces que la segunda y tercera bola son blancas
    int conteoSegundaBlanca = 0;
    int conteoTerceraBlanca = 0;

    // Realizar múltiples experimentos
    for (int i = 0; i < numExperimentos; ++i) {
        // Copiar el estado inicial de la urna
        int bolasNegrasRestantes = bolasNegras;
        int bolasBlancasRestantes = bolasBlancas;

        // Primera extracción (no afecta las probabilidades en este caso)

        // Segunda extracción
        int indiceSegunda = rand() % (bolasNegrasRestantes + bolasBlancasRestantes);
        if (indiceSegunda < bolasBlancasRestantes) {
            // La segunda bola es blanca
            conteoSegundaBlanca++;

            // Actualizar la urna
            bolasBlancasRestantes--;
        } else {
            // La segunda bola es negra
            bolasNegrasRestantes--;
        }

        // Tercera extracción
        int indiceTercera = rand() % (bolasNegrasRestantes + bolasBlancasRestantes);
        if (indiceTercera < bolasBlancasRestantes) {
            // La tercera bola es blanca
            conteoTerceraBlanca++;
        }
    }

    // Calcular probabilidades empíricas
    double probSegundaBlanca = static_cast<double>(conteoSegundaBlanca) / numExperimentos;
    double probTerceraBlanca = static_cast<double>(conteoTerceraBlanca) / numExperimentos;

    // Mostrar resultados
    cout << "Probabilidad empírica de que la segunda bola sea blanca: " << probSegundaBlanca << endl;
    cout << "Probabilidad empírica de que la tercera bola sea blanca: " << probTerceraBlanca << endl;

    return 0;
}
