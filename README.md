# APS - Análise de Performance de Algoritmos de Ordenação

Este repositório contém a implementação e os testes de performance dos algoritmos de ordenação **QuickSort**, **HeapSort** e **MergeSort**, desenvolvidos como parte das Atividades Práticas Supervisionadas (APS) do curso de Ciência da Computação da Universidade Paulista (UNIP).

## Objetivo

O objetivo deste projeto é analisar a eficiência de diferentes algoritmos de ordenação no contexto de geoprocessamento de imagens da Floresta Amazônica, visando otimizar a fiscalização de crimes ambientais através da organização eficiente de grandes volumes de dados.

## Algoritmos Implementados

- **QuickSort**: Algoritmo baseado na técnica de "dividir para conquistar" com particionamento.
- **HeapSort**: Algoritmo baseado em estrutura de dados de árvore binária (heap).
- **MergeSort**: Algoritmo recursivo que utiliza a intercalação de subvetores.

## Estrutura do Repositório

- `main.c` - Código-fonte principal contendo as implementações e a rotina de testes.
- `video_demo_aps.svg` - Vídeo demonstrativo da execução do programa (animação SVG interativa).
- `README.md` - Documentação do projeto.

## Vídeo Explicativo

O vídeo demonstrando o funcionamento da aplicação está disponível neste repositório no arquivo `video_execucao_aps.mp4`. Para visualizá-lo, basta abrir o arquivo diretamente no navegador.

O vídeo mostra:
1. Compilação do código-fonte com GCC.
2. Execução completa do programa com vetores de 10 a 10.000 elementos.
3. Resultados comparativos de performance entre QuickSort, HeapSort e MergeSort.

## Como Executar

Para compilar e executar o código, você precisará de um compilador C (como o GCC):

```bash
gcc main.c -o aps_ordenacao -lm
./aps_ordenacao
```

## Autor

- **Felipe Rueda** - RA: G802JE3
- Curso: Ciência da Computação - UNIP
- Ano: 2026
