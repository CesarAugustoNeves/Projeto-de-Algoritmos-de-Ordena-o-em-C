#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Roda_de_troca(int *x, int *y) {
    int temporario = *x; 
    *x = *y;
    *y = temporario;
}

void Galhos(int vet[], int num_total, int inicio_raiz) {
    int maior = inicio_raiz; 
    int esquerda = 2 * inicio_raiz + 1; // filho esquerdo
    int direita = 2 * inicio_raiz + 2; // filho direito

    if (esquerda < num_total && vet[esquerda] > vet[maior]) //esquerdo maior
        maior = esquerda;

    if (direita < num_total && vet[direita] > vet[maior]) //direito maior
        maior = direita;

    if (maior != inicio_raiz) {
        Roda_de_troca(&vet[inicio_raiz], &vet[maior]); //troca de valores
        Galhos(vet, num_total, maior);
    }
}

void heapSort(int vet[], int num_total) {
    for (int indice = num_total / 2 - 1; indice >= 0; indice--)
        Galhos(vet, num_total, indice);

    for (int final = num_total - 1; final >= 0; final--) {
        Roda_de_troca(&vet[0], &vet[final]); // Move a raiz atual para o final
        Galhos(vet, final, 0); // Chama Galhos na árvore reduzida
    }
}
void printLista(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int n = 10; // Tamanho da lista (Ajustável)
    int lista[n];

    srand(time(NULL)); // Inicializa a geração de números aleatórios

    // Preenche a lista com números aleatórios
    for (int i = 0; i < n; i++) {
        lista[i] = rand() % 10000; // Limita o tamanho dos números aleatórios
    }

    printf("Lista original:\n\n");
    printLista(lista, n); // Imprime a lista original

    clock_t inicio, fim;
    double tempo_cpu;

    inicio = clock(); // Marca o tempo de início
    QuickSort(lista, 0, n - 1); // Chama a função de ordenação
    fim = clock(); // Marca o tempo de fim

    tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução

    printf("Tempo de execução: %f segundos\n\n", tempo_cpu);

    // Imprime a lista ordenada
    printf("Lista ordenada:\n\n");
    printLista(lista, n);

    return 0;
}
