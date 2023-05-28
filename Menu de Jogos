#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

// =============================== FUNÇÃO VOID DO JOGO DA FORCA
// ================================

void exibirForca(int tentativasRestantes) { // Incializa os desenhos da forca
  if (tentativasRestantes == 6) {
    std::cout << " _______     \n"
                 "|       |     \n"
                 "|             \n"
                 "|             \n"
                 "|             \n"
                 "|             \n";
  } else if (tentativasRestantes == 5) {
    std::cout << " _______     \n"
                 "|       |     \n"
                 "|       O     \n"
                 "|             \n"
                 "|             \n"
                 "|             \n";
  } else if (tentativasRestantes == 4) {
    std::cout << " _______     \n"
                 "|       |     \n"
                 "|       O     \n"
                 "|       |     \n"
                 "|             \n"
                 "|             \n";
  } else if (tentativasRestantes == 3) {
    std::cout << " _______     \n"
                 "|       |     \n"
                 "|       O     \n"
                 "|      /|     \n"
                 "|             \n"
                 "|             \n";
  } else if (tentativasRestantes == 2) {
    std::cout << " _______     \n"
                 "|       |     \n"
                 "|       O     \n"
                 "|      /|\\   \n"
                 "|             \n"
                 "|             \n";
  } else if (tentativasRestantes == 1) {
    std::cout << " _______     \n"
                 "|       |     \n"
                 "|       O     \n"
                 "|      /|\\   \n"
                 "|      /      \n"
                 "|             \n";
  } 
}

void jogoDaForca() {
  srand(time(NULL));

  const int NUM_PALAVRAS = 7;
  const int MAX_TAMANHO = 100;
  char palavras[NUM_PALAVRAS][MAX_TAMANHO] = {
      "SALA", "AULA", "FACULDADE", "BANANA", "CHOCOLATE", "MESA", "COMPUTADOR"};
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
    std::cout << "Digite uma letra (EM MAIUSCULO): ";
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
    std::cout << "\n _______     \n"
                 "|       |     \n"
                 "|       O     \n"
                 "|      /|\\   \n"
                 "|      / \\    \n"
                 "|             \n" << std::endl;
    
    std::cout << "\nVocê perdeu. A palavra secreta era: " << palavraSecreta
              << std::endl;
    
    
    
  }
}

// ====================================== VOIDS DO JOGO DA VELHA
// ===================================

const int TAMANHO = 3;
char tabuleiro[TAMANHO][TAMANHO];
char jogadorAtual = 'X';

void inicializarTabuleiro() {
  for (int i = 0; i < TAMANHO; i++) {
    for (int j = 0; j < TAMANHO; j++) {
      tabuleiro[i][j] = ' ';
    }
  }
}

void exibirTabuleiro() {
  std::cout << "  1 2 3\n";
  for (int i = 0; i < TAMANHO; i++) {
    std::cout << i + 1 << ' ';
    for (int j = 0; j < TAMANHO; j++) {
      std::cout << tabuleiro[i][j];
      if (j != TAMANHO - 1) {
        std::cout << '|';
      }
    }
    std::cout << '\n';
    if (i != TAMANHO - 1) {
      std::cout << "  ─│─│─\n";
    }
  }
}

bool fazerJogada(int linha, int coluna) {
  if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
    return false;
  }
  if (tabuleiro[linha][coluna] != ' ') {
    return false;
  }
  tabuleiro[linha][coluna] = jogadorAtual;
  return true;
}

bool verificarVitoria(char jogador) {
  // verifica linhas
  for (int i = 0; i < TAMANHO; i++) {
    bool vitoria = true;
    for (int j = 0; j < TAMANHO; j++) {
      if (tabuleiro[i][j] != jogador) {
        vitoria = false;
        break;
      }
    }
    if (vitoria) {
      return true;
    }
  }

  // verifica colunas
  for (int j = 0; j < TAMANHO; j++) {
    bool vitoria = true;
    for (int i = 0; i < TAMANHO; i++) {
      if (tabuleiro[i][j] != jogador) {
        vitoria = false;
        break;
      }
    }
    if (vitoria) {
      return true;
    }
  }

  // verifica diagonal principal
  bool vitoria = true;
  for (int i = 0; i < TAMANHO; i++) {
    if (tabuleiro[i][i] != jogador) {
      vitoria = false;
      break;
    }
  }
  if (vitoria) {
    return true;
  }

  // verifica diagonal secundária
  vitoria = true;
  for (int i = 0; i < TAMANHO; i++) {
    if (tabuleiro[i][TAMANHO - i - 1] != jogador) {
      vitoria = false;
      break;
    }
  }
  if (vitoria) {
    return true;
  }

  return false;
}

bool verificarEmpate() {
  for (int i = 0; i < TAMANHO; i++) {
    for (int j = 0; j < TAMANHO; j++) {
      if (tabuleiro[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

void trocarJogador() {
  if (jogadorAtual == 'X') {
    jogadorAtual = 'O';
  } else {
    jogadorAtual = 'X';
  }
}

void jogoDaVelha() {
  inicializarTabuleiro();

  while (true) {
    exibirTabuleiro();

    int linha, coluna;

    std::cout << "Jogador " << jogadorAtual << ", escolha uma linha: ";

    std::cin >> linha;

    std::cout << "Jogador " << jogadorAtual << ", escolha uma coluna: ";

    std::cin >> coluna;

    while (!fazerJogada(linha - 1, coluna - 1)) {
      std::cout << "Jogada inválida. Tente novamente.\n";

      std::cout << "Jogador " << jogadorAtual << ", escolha uma linha: ";

      std::cin >> linha;

      std::cout << "Jogador " << jogadorAtual << ", escolha uma coluna: ";

      std::cin >> coluna;
    }

    if (verificarVitoria(jogadorAtual)) {
      exibirTabuleiro();

      std::cout << "Jogador " << jogadorAtual << " venceu!\n";

      break;

    } else if (verificarEmpate()) {
      exibirTabuleiro();

      std::cout << "Empate!\n";

      break;

    } else {
      trocarJogador();
    }
  }
}

void jogoDeAdivinhacao() {
  srand(time(NULL)); // inicializa a semente do gerador de números aleatórios e
                     // garante que o número gerado pela função rand() seja
                     // diferente cada vez que o programa é executado.

  int numeroSecreto =
      rand() % 100 + 1; // gera um número aleatório entre 1 e 100
  int tentativa;
  std::cout << "\nAdivinhe o número entre 1 e 100: ";
  std::cin >> tentativa;
  

  while (tentativa != numeroSecreto) {
    if (tentativa < numeroSecreto) {
      std::cout << "O número secreto eh maior. Tente novamente: ";
    } else {
      std::cout << "O número secreto eh menor. Tente novamente: ";
    }
    std::cin >> tentativa;
  }

  std::cout << "Parabéns! Você acertou o número." << std::endl;
}

int main() {
  bool sair = false;
  while (!sair) {
    
    std::cout << "\nTT                  TT" << std::endl;
    std::cout << "|| ESCOLHA OS JOGOS ||" << std::endl;
    std::cout << "||==================||" << std::endl;
    std::cout << "|| 1. Jogo da Forca ||" << std::endl;
    std::cout << "|| 2. Jogo da Velha ||" << std::endl;
    std::cout << "|| 3. Adivinhacao   ||" << std::endl;
    std::cout << "|| 4. Sair          ||" << std::endl;
    std::cout << "||__________________||\n" << std::endl;

    int escolha;
    std::cin >> escolha;

    switch (escolha) {
    case 1:
      std::cout << "\n-=-=- Inicializando o Jogo da Forca! -=-=-\n" << std::endl;
      jogoDaForca();
      break;
    case 2:
      std::cout << "\n-=-=- Inicializando o Jogo da Velha! -=-=-\n" << std::endl;
      jogoDaVelha();
      break;
    case 3:
      std::cout << "\n-=-=- Inicializando o Jogo de Adivinhação! -=-=-\n" << std::endl;
      jogoDeAdivinhacao();
      break;
    case 4:
      sair = true;
      break;
    default:
      std::cout << "\nOpção inválida. Tente novamente." << std::endl;
      break;
    }
  }

  return 0;
}
