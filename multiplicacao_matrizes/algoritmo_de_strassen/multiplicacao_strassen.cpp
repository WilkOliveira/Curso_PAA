#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define _FILE_OFFSET_BITS 64

int leafsize;

using namespace std;

#define MAX 3 // para fazer testes

/**
* Declaração de funções para ler e mostrar as matrizes
*/
void lerMatrizes(string nomeArquivo, vector< vector<int> > &A, vector< vector<int> > &B);
void mostraMatriz(vector< vector<int> > matriz, int n);

/**
* função para fazer as adições do strassen
*/
void adicao(vector< vector<int> > &A,
            vector< vector<int> > &B,
            vector< vector<int> > &C,
            int tamanho);

/**
* função para fazer as subtrações do strassen
*/
void subtracao(vector< vector<int> > &A,
               vector< vector<int> > &B,
               vector< vector<int> > &C,
               int tamanho);

/**
* Função para tratamento para uso do algoritmo tradicional
*/
void multiplicacaoTradicional(vector< vector<int> > A,
                                   vector< vector<int> > B,
                                   vector< vector<int> > &C, int n) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/**
* Função responsavel por alocar todo o código que escolhe a entrada e processa o algoritmo de strassen
*/
void resposta(vector< vector<int> > &A,
              vector< vector<int> > &B,
              vector< vector<int> > &C,
              int tamanho){

                  if (tamanho <= leafsize) {
        multiplicacaoTradicional(A, B, C, tamanho);
        return;
    }
else{
        int novoTamanho = tamanho/2;
        vector<int> valor (novoTamanho);
        int i, j;

        /**
        * Instancia o valor (novo valor) de cada posição das matrizes
        */
        vector< vector<int> >
                a11(novoTamanho,valor), a12(novoTamanho,valor), a21(novoTamanho,valor), a22(novoTamanho,valor),
                b11(novoTamanho,valor), b12(novoTamanho,valor), b21(novoTamanho,valor), b22(novoTamanho,valor),
                c11(novoTamanho,valor), c12(novoTamanho,valor), c21(novoTamanho,valor), c22(novoTamanho,valor),
                    p1(novoTamanho,valor), p2(novoTamanho,valor), p3(novoTamanho,valor), p4(novoTamanho,valor), p5(novoTamanho,valor), p6(novoTamanho,valor), p7(novoTamanho,valor),
                        mA(novoTamanho,valor), mB(novoTamanho,valor);
        /**
        * Primeira etapa do algoritmo (de acordo com o passo a passo que achei na internet), cria 8 submatrizes
        */
        for (i = 0; i < novoTamanho; i++){
            for (j = 0; j < novoTamanho; j++){
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + novoTamanho];
                a21[i][j] = A[i + novoTamanho][j];
                a22[i][j] = A[i + novoTamanho][j + novoTamanho];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + novoTamanho];
                b21[i][j] = B[i + novoTamanho][j];
                b22[i][j] = B[i + novoTamanho][j + novoTamanho];
            }
        }

        /**
        * Segunda etapa do algoritmo (de acordo com o passo a passo que achei na internet), caucula os valores de p1 a p7 de acordo com as matrizes que foram previamente definidas
        */
        adicao(a11, a22, mA, novoTamanho); // a1,1 + a2,2
        adicao(b11, b22, mB, novoTamanho); // b1,1 + b2,2
        resposta(mA, mB, p1, novoTamanho); // p1 = (a1,1+a2,2) * (b1,1+b2,2)

        adicao(a21, a22, mA, novoTamanho); // a2,1 + a2,2
        resposta(mA, b11, p2, novoTamanho); // p2 = (a2,1+a2,2) * (b1,1)

        subtracao(b12, b22, mB, novoTamanho); // b1,2 - b2,2
        resposta(a11, mB, p3, novoTamanho); // p3 = (a1,1) * (b1,2 - b2,2)

        subtracao(b21, b11, mB, novoTamanho); // b2,1 - b1,1
        resposta(a22, mB, p4, novoTamanho); // p4 = (a2,2) * (b2,1 - b1,1)

        adicao(a11, a12, mA, novoTamanho); // a1,1 + a1,2
        resposta(mA, b22, p5, novoTamanho); // p5 = (a1,1+a1,2) * (b2,2)

        subtracao(a21, a11, mA, novoTamanho); // a2,1 - a1,1
        adicao(b11, b12, mB, novoTamanho); // b1,1 + b1,2
        resposta(mA, mB, p6, novoTamanho); // p6 = (a2,1-a1,1) * (b1,1+b1,2)

        subtracao(a12, a22, mA, novoTamanho); // a1,2 - a2,2
        adicao(b21, b22, mB, novoTamanho); // b2,1 + b2,2
        resposta(mA, mB, p7, novoTamanho); // p7 = (a1,2-a2,2) * (b2,1+b2,2)

        /**
        * Terceira etapa do algoritmo (de acordo com o passo a passo que achei na internet), caucula cada posição da matriz produto
        */
        adicao(p3, p5, c12, novoTamanho); // c12 = p3 + p5
        adicao(p2, p4, c21, novoTamanho); // c21 = p2 + p4

        adicao(p1, p4, mA, novoTamanho); // p1 + p4
        adicao(mA, p7, mB, novoTamanho); // p1 + p4 + p7
        subtracao(mB, p5, c11, novoTamanho); // c11 = p1 + p4 - p5 + p7

        adicao(p1, p3, mA, novoTamanho); // p1 + p3
        adicao(mA, p6, mB, novoTamanho); // p1 + p3 + p6
        subtracao(mB, p2, c22, novoTamanho); // c22 = p1 + p3 - p2 + p6

        /**
        * Agrupo e ordeno os resultados na matriz produto
        */
        for (i = 0; i < novoTamanho ; i++) {
            for (j = 0 ; j < novoTamanho ; j++) {
                C[i][j] = c11[i][j];
                C[i][j + novoTamanho] = c12[i][j];
                C[i + novoTamanho][j] = c21[i][j];
                C[i + novoTamanho][j + novoTamanho] = c22[i][j];
            }
        }
}
}

unsigned int nextPowerOfTwo(int n) {
    return pow(2, int(ceil(log2(n))));
}


void strassen(vector< vector<int> > &A,
              vector< vector<int> > &B,
              vector< vector<int> > &C, unsigned int n) {
    //unsigned int n = tam;
    unsigned int m = nextPowerOfTwo(n);
    vector<int> valor(m);
    vector< vector<int> > APrep(m, valor), BPrep(m, valor), CPrep(m, valor);

    for(unsigned int i=0; i<n; i++) {
        for (unsigned int j=0; j<n; j++) {
            APrep[i][j] = A[i][j];
            BPrep[i][j] = B[i][j];
        }
    }

    resposta(APrep, BPrep, CPrep, m);
    for(unsigned int i=0; i<n; i++) {
        for (unsigned int j=0; j<n; j++) {
            C[i][j] = CPrep[i][j];
        }
    }
}

/**
* Implementa a função adição
*/
void adicao(vector< vector<int> > &A,
            vector< vector<int> > &B,
            vector< vector<int> > &C, int tamanho){

        int i, j;

        for (i = 0; i < tamanho; i++) {
                for (j = 0; j < tamanho; j++) {
                    C[i][j] = A[i][j] + B[i][j];
        }
    }
}

/**
* Implementa a função subtração
*/
void subtracao(vector< vector<int> > &A,
               vector< vector<int> > &B,
               vector< vector<int> > &C, int tam) {
    int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

/**
* Função para pegar as matrizes a partir do arquivo
*/
int getTamanhoMatriz(string nomeArquivo) {
    string linha;
    ifstream infile;
    infile.open(nomeArquivo.c_str());
    getline(infile, linha);
    return count(linha.begin(), linha.end(), '\t') + 1;
}

/**
* Implementação da função que faz a leitura do arquivo
*/
void lerMatrizes(string nomeArquivo, vector< vector<int> > &A, vector< vector<int> > &B) {
    int BUF_SIZE = 40000;
    string linha;
    FILE* arquivo = freopen(nomeArquivo.c_str(), "r", stdin);

    if (arquivo == 0) {
        cerr << "Erro ao ler o arquivo " << nomeArquivo << endl;
        return;
    }

    int i = 0, j, a;
    while (getline(cin, linha) && !linha.empty()) {
        istringstream iss(linha);
        j = 0;
        while (iss >> a) {
            A[i][j] = a;
            j++;
        }
        i++;
    }

    i = 0;
    while (getline(cin, linha)) {
        istringstream iss(linha);
        j = 0;
        while (iss >> a) {
            B[i][j] = a;
            j++;
        }
        i++;
    }

    fclose (arquivo);
}

/**
* Implementação da função organiza e mostra a matriz produto
*/
void mostraMatriz(vector< vector<int> > matriz, int n) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (j != 0) {
                cout << "\t";
            }
            cout << matriz[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char* argv[])
{

string nomeArquivo;

    if (argc < 3) {
            nomeArquivo = "1000.in";
    } else {
        nomeArquivo = argv[2];
    }

    if (argc < 5) {
        leafsize = 16;
    } else {
        leafsize = atoi(argv[4]);
    }

    int n = getTamanhoMatriz(nomeArquivo);
    vector<int> valor (n);
    vector< vector<int> > A(n, valor), B(n, valor), C(n, valor);
    lerMatrizes(nomeArquivo, A, B);
    strassen(A, B, C, n);
    mostraMatriz(C, n);
    return 0;
}
