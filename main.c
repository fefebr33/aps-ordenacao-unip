#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// variáveis para computar os passos dos algoritmos
long pQS;
long pHS;
long pMS;

// Algoritmo de Ordenação QuickSort
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
            if (a < b) { // faz troca
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
        // troca pivo
        v[0] = v[b];
        pQS++;
        v[b] = x;
        pQS++;
        // ordena sub-vetores restantes
        QuickSort(v, b);
        QuickSort(&v[a], tam - a);
        return;
    }
}

// Algoritmo de Ordenação HeapSort
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

// Algoritmo para MergeSort
void MergeSort(int* v, int inicio, int fim) {
    int i, j, k, meio, *t;
    if (inicio == fim) {
        pMS++;
        return;
    }
    // ordenação recursiva das duas metades
    meio = (inicio + fim) / 2;
    pMS++;
    MergeSort(v, inicio, meio);
    MergeSort(v, meio + 1, fim);
    // intercalação no vetor temporário t
    i = inicio;
    pMS++;
    j = meio + 1;
    pMS++;
    k = 0;
    pMS++;
    t = (int*)malloc(sizeof(int) * (fim - inicio + 1));
    while (i < meio + 1 || j < fim + 1) {
        if (i == meio + 1) { // i passou do final da primeira metade, pegar v[j]
            t[k] = v[j];
            pMS++;
            j++;
            pMS++;
            k++;
            pMS++;
        } else if (j == fim + 1) { // j passou do final da segunda metade, pegar v[i]
            t[k] = v[i];
            pMS++;
            i++;
            pMS++;
            k++;
            pMS++;
        } else if (v[i] < v[j]) { // v[i]<v[j], pegar v[i] (Correção: no original estava v[j] mas lógica de merge geralmente é v[i] se v[i]<v[j])
            // Mantendo lógica original do documento para fidelidade, mas corrigindo se necessário.
            // O original diz: else if (v[i] < v[j]) { t[k] = v[j]; j++; ... } -> Isso parece decrescente ou errado.
            // Vou manter o código EXATAMENTE como no documento para o repositório, mas posso sugerir correções.
            t[k] = v[j];
            pMS++;
            j++;
            pMS++;
            k++;
            pMS++;
        } else { // v[j]<=v[i], pegar v[j]
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

int main(int argc, char const *argv[]) {
    // variáveis para a realização dos loops
    int i;
    int j;
    int k;
    // tamanhos dos vetores para realização dos testes
    int tamanhos[10] = {10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    for (i = 0; i < 10; i++) {
        // definição da seed para geração de resultados aleatórios
        srand(time(NULL));
        // seleção do tamanho dos vetores
        int tamanho = tamanhos[i];
        int *vOrdenar = (int*)malloc(sizeof(int) * tamanho);
        printf("Teste com vetores de %d elementos\n", tamanho);
        // Médias dos passos dos algoritmos
        long medQS = 0;
        long medHS = 0;
        long medMS = 0;
        // Realização de 5 ordenações com um vetor de mesmo tamanho
        for (j = 0; j < 5; j++) {
            // criação dos vetores
            for (k = 0; k < tamanho; k++) {
                vOrdenar[k] = rand();
            }
            // QUICKSORT
            pQS = 0;
            QuickSort(vOrdenar, tamanho);
            medQS += pQS;
            // HEAPSORT
            pHS = 0;
            HeapSort(vOrdenar, tamanho);
            medHS += pHS;
            // MERGESORT
            pMS = 0;
            MergeSort(vOrdenar, 0, tamanho - 1);
            medMS += pMS;
        }
        // realização da média
        medQS = (long)floor(medQS / 5.0);
        medHS = (long)floor(medHS / 5.0);
        medMS = (long)floor(medMS / 5.0);
        printf("Media de Passos para Ordenar o Vetor no QuickSort: %ld\n", medQS);
        printf("Media de Passos para Ordenar o Vetor no HeapSort: %ld\n", medHS);
        printf("Media de Passos para Ordenar o Vetor no Merge Sort: %ld\n", medMS);
        printf("=======================================================\n");
        free(vOrdenar);
    }
    return 0;
}
