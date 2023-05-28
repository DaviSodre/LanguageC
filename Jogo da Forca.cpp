#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

// Função para exibir o desenho da forca de acordo com o número de tentativas restantes
void exibirForca(int tentativasRestantes) {
    if (tentativasRestantes == 6) {
        std::cout <<
            " _______     \n"
            "|       |     \n"
            "|             \n"
            "|             \n"
            "|             \n"
            "|             \n";
    } else if (tentativasRestantes == 5) {
         std::cout <<
             " _______     \n"
             "|       |     \n"
             "|       O     \n"
             "|             \n"
             "|             \n"
             "|             \n";
     } else if (tentativasRestantes == 4) {
         std::cout <<
             " _______     \n"
             "|       |     \n"
             "|       O     \n"
             "|       |     \n"
             "|             \n"
             "|             \n";
     } else if (tentativasRestantes == 3) {
         std::cout <<
             " _______     \n"
             "|       |     \n"
             "|       O     \n"
             "|      /|     \n"
             "|             \n"
             "|             \n";
     } else if (tentativasRestantes == 2) {
         std::cout <<
             " _______     \n"
             "|       |     \n"
             "|       O     \n"
             "|      /|\\   \n"
             "|             \n"
             "|             \n";
     } else if (tentativasRestantes == 1) {
         std::cout <<
             " _______     \n"
             "|       |     \n"
             "|       O     \n"
             "|      /|\\   \n"
             "|      /      \n"
             "|             \n";
    }
}

int main() {
    srand(time(NULL));


    const int NUM_PALAVRAS = 7;
    const int MAX_TAMANHO = 100;
    char palavras[NUM_PALAVRAS][MAX_TAMANHO] = {"SALA", "AULA", "FACULDADE", "BANANA", "CHOCOLATE", "MESA", "COMPUTADOR"};
    int indicePalavraSecreta = rand() % NUM_PALAVRAS;
    char palavraSecreta[MAX_TAMANHO];
strcpy(palavraSecreta, palavras[indicePalavraSecreta]);

    int tamanhoPalavra = strlen(palavraSecreta);
    char letrasAcertadas[MAX_TAMANHO];
    for (int i = 0; i < tamanhoPalavra; i++) {
        letrasAcertadas[i] = '_';
    }
    int tentativasRestantes = 6;
    bool enforcou = false;
    bool ganhou = false;

    while (!enforcou && !ganhou) {
        std::cout << "Tentativas restantes: " << tentativasRestantes << std::endl;
      exibirForca(tentativasRestantes);

        for (int i = 0; i < tamanhoPalavra; i++) {
            std::cout << letrasAcertadas[i] << ' ';
        }
        std::cout << std::endl;

        char chute;
        std::cout << "Digite uma letra: ";
        std::cin >> chute;

        bool acertou = false;
        for (int i = 0; i < tamanhoPalavra; i++) {
            if (palavraSecreta[i] == chute) {
                letrasAcertadas[i] = chute;
                acertou = true;
            }
        }

        if (!acertou) {
            tentativasRestantes--;
        }

        enforcou = (tentativasRestantes == 0);
        ganhou = true;
        for (int i = 0; i < tamanhoPalavra; i++) {
            if (letrasAcertadas[i] == '_') {
                ganhou = false;
                break;
            }
        }
    }

    if (ganhou) {
        std::cout << "Parabéns! Você acertou a palavra secreta." << std::endl;
    } else {
        std::cout << "Você perdeu. A palavra secreta era: " << palavraSecreta << std::endl;
    }

    return 0;
}

