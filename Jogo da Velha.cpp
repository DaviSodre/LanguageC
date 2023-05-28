#include <iostream>

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

int main() {
    inicializarTabuleiro();
    
    while(true) {        
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

        
        if(verificarVitoria(jogadorAtual)) {            
            exibirTabuleiro();
            
            std::cout << "Jogador " << jogadorAtual << " venceu!\n";
            
            break;
            
        } else if(verificarEmpate()) {            
            exibirTabuleiro();
            
            std::cout << "Empate!\n";
            
            break;
            
        } else {            
            trocarJogador();
            
        }        
    }

    
}
