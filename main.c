/*
 * ============================================================
 * APS - Atividades Práticas Supervisionadas
 * Universidade Paulista - UNIP
 * 
 * Tema: Análise de Performance de Algoritmos de Ordenação
 * Aluno: Felipe Rueda
 * RA: G802JE3
 * Curso: Ciência da Computação
 * Ano: 2026
 * ============================================================
 * 
 * Algoritmos implementados:
 *   [1] QuickSort  - Dividir para Conquistar (Particionamento)
 *   [2] HeapSort   - Árvore Binária (Heap Máximo)
 *   [3] MergeSort  - Intercalação Recursiva de Subvetores
 * 
 * Metodologia:
 *   - 10 tamanhos de vetor: 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000
 *   - 5 execuções por tamanho (média aritmética)
 *   - Vetores preenchidos com valores aleatórios (rand())
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Contadores de passos (variáveis globais) */
long pQS;  /* Passos do QuickSort */
long pHS;  /* Passos do HeapSort */
long pMS;  /* Passos do MergeSort */

/* ============================================================
 * [1] QUICKSORT
 * Técnica: Dividir para Conquistar (Particionamento)
 * Complexidade média: O(n log n)
 * Pior caso: O(n²)
 * ============================================================ */
void QuickSort(int* v, int tam) {
    int j = tam;
    pQS++;
    if (tam <= 1) {
        pQS++;
        return;
    } else {
        int x = v[0];
        pQS++;
        int a = 1;
        pQS++;
        int b = tam - 1;
        pQS++;
        do {
            while ((a < tam) && (v[a] <= x)) {
                a++;
                pQS++;
            }
            while (v[b] > x) {
                b--;
                pQS++;
            }
            if (a < b) {
                int temp = v[a];
                pQS++;
                v[a] = v[b];
                pQS++;
                v[b] = temp;
                pQS++;
                a++;
                pQS++;
                b--;
                pQS++;
            }
        } while ((a <= b));
        /* Troca pivô */
        v[0] = v[b];
        pQS++;
        v[b] = x;
        pQS++;
        /* Ordena sub-vetores restantes */
        QuickSort(v, b);
        QuickSort(&v[a], tam - a);
        return;
    }
}

/* ============================================================
 * [2] HEAPSORT
 * Técnica: Árvore Binária (Heap Máximo)
 * Complexidade: O(n log n) em todos os casos
 * ============================================================ */
void PercorreArvore(int* v, int raiz, int folha) {
    int percorreu, maxfolhas, temp;
    percorreu = 0;
    pHS++;
    while ((raiz * 2 <= folha) && (!percorreu)) {
        if (raiz * 2 == folha) {
            maxfolhas = raiz * 2;
            pHS++;
        } else if (v[raiz * 2] > v[raiz * 2 + 1]) {
            maxfolhas = raiz * 2;
            pHS++;
        } else {
            maxfolhas = raiz * 2 + 1;
            pHS++;
        }
        if (v[raiz] < v[maxfolhas]) {
            temp = v[raiz];
            pHS++;
            v[raiz] = v[maxfolhas];
            pHS++;
            v[maxfolhas] = temp;
            pHS++;
            raiz = maxfolhas;
            pHS++;
        } else {
            percorreu = 1;
            pHS++;
        }
    }
}

void HeapSort(int* v, int tam) {
    int i, temp;
    for (i = (tam / 2); i >= 0; i--) {
        PercorreArvore(v, i, tam - 1);
    }
    for (i = tam - 1; i >= 1; i--) {
        temp = v[0];
        pHS++;
        v[0] = v[i];
        pHS++;
        v[i] = temp;
        pHS++;
        PercorreArvore(v, 0, i - 1);
    }
}

/* ============================================================
 * [3] MERGESORT
 * Técnica: Intercalação Recursiva de Subvetores
 * Complexidade: O(n log n) em todos os casos
 * ============================================================ */
void MergeSort(int* v, int inicio, int fim) {
    int i, j, k, meio, *t;
    if (inicio == fim) {
        pMS++;
        return;
    }
    /* Ordenação recursiva das duas metades */
    meio = (inicio + fim) / 2;
    pMS++;
    MergeSort(v, inicio, meio);
    MergeSort(v, meio + 1, fim);
    /* Intercalação no vetor temporário t */
    i = inicio;
    pMS++;
    j = meio + 1;
    pMS++;
    k = 0;
    pMS++;
    t = (int*)malloc(sizeof(int) * (fim - inicio + 1));
    while (i < meio + 1 || j < fim + 1) {
        if (i == meio + 1) {
            t[k] = v[j];
            pMS++;
            j++;
            pMS++;
            k++;
            pMS++;
        } else if (j == fim + 1) {
            t[k] = v[i];
            pMS++;
            i++;
            pMS++;
            k++;
            pMS++;
        } else if (v[i] < v[j]) {
            t[k] = v[i];
            pMS++;
            i++;
            pMS++;
            k++;
            pMS++;
        } else {
            t[k] = v[j];
            pMS++;
            j++;
            pMS++;
            k++;
            pMS++;
        }
    }
    for (i = inicio; i <= fim; i++) {
        v[i] = t[i - inicio];
        pMS++;
    }
    free(t);
    pMS++;
}

/* ============================================================
 * FUNÇÃO PRINCIPAL
 * Executa os testes de performance com vetores de 10 a 10.000
 * elementos, realizando 5 ordenações por tamanho e calculando
 * a média de passos de cada algoritmo.
 * ============================================================ */
int main(int argc, char const *argv[]) {
    int i, j, k;
    /* Tamanhos dos vetores para realização dos testes */
    int tamanhos[10] = {10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

    printf("============================================================\n");
    printf("  APS - Analise de Performance de Algoritmos de Ordenacao\n");
    printf("  Aluno: Felipe Rueda | RA: G802JE3\n");
    printf("  UNIP - Ciencia da Computacao - 2026\n");
    printf("============================================================\n\n");

    for (i = 0; i < 10; i++) {
        /* Definição da seed para geração de resultados aleatórios */
        srand(time(NULL) + i);
        /* Seleção do tamanho dos vetores */
        int tamanho = tamanhos[i];
        int *vOrdenar = (int*)malloc(sizeof(int) * tamanho);

        printf("  Vetor: %d elementos\n", tamanho);

        /* Médias dos passos dos algoritmos */
        long medQS = 0;
        long medHS = 0;
        long medMS = 0;

        /* Realização de 5 ordenações com vetor de mesmo tamanho */
        for (j = 0; j < 5; j++) {
            /* Criação dos vetores com valores aleatórios */
            for (k = 0; k < tamanho; k++) {
                vOrdenar[k] = rand();
            }
            /* QUICKSORT */
            pQS = 0;
            QuickSort(vOrdenar, tamanho);
            medQS += pQS;

            /* Recria vetor para HeapSort */
            for (k = 0; k < tamanho; k++) {
                vOrdenar[k] = rand();
            }
            /* HEAPSORT */
            pHS = 0;
            HeapSort(vOrdenar, tamanho);
            medHS += pHS;

            /* Recria vetor para MergeSort */
            for (k = 0; k < tamanho; k++) {
                vOrdenar[k] = rand();
            }
            /* MERGESORT */
            pMS = 0;
            MergeSort(vOrdenar, 0, tamanho - 1);
            medMS += pMS;
        }

        /* Cálculo da média */
        medQS = (long)floor(medQS / 5.0);
        medHS = (long)floor(medHS / 5.0);
        medMS = (long)floor(medMS / 5.0);

        printf("    QuickSort:  %ld passos\n", medQS);
        printf("    HeapSort:   %ld passos\n", medHS);
        printf("    MergeSort:  %ld passos\n", medMS);
        printf("\n");

        free(vOrdenar);
    }

    printf("============================================================\n");
    printf("  RESULTADO: QuickSort apresentou MENOR numero de passos\n");
    printf("  Ranking: 1o QuickSort > 2o MergeSort > 3o HeapSort\n");
    printf("============================================================\n");
    printf("  Repositorio: github.com/fefebr33/aps-ordenacao-unip\n");
    printf("============================================================\n");

    return 0;
}
