#include <cstdlib> // para usar a função rand()
#include <ctime>   // para usar a função time()
#include <iostream>

int main() {
  srand(time(NULL)); // inicializa a semente do gerador de números aleatórios e
                     // garante que o número gerado pela função rand() seja
                     // diferente cada vez que o programa é executado.

  int numeroSecreto =
      rand() % 100 + 1; // gera um número aleatório entre 1 e 100
  int tentativa;

  std::cout << "Adivinhe o número entre 1 e 100: ";
  std::cin >> tentativa;

  while (tentativa != numeroSecreto) {
    if (tentativa < numeroSecreto) {
      std::cout << "O número secreto é maior. Tente novamente: ";
    } else {
      std::cout << "O número secreto é menor. Tente novamente: ";
    }
    std::cin >> tentativa;
  }

  std::cout << "Parabéns! Você acertou o número." << std::endl;

  return 0;
}
