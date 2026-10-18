#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

void Entrada(Biblioteca livros[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\n--- Cadastrando o %dº Livro ---\n", i + 1);
        printf("Nome do livro: ");
        fgets(livros[i].nome, 500, stdin);
        livros[i].nome[strcspn(livros[i].nome, "\n")] = '\0';

        printf("Nome do autor: ");
        fgets(livros[i].autor, 500, stdin);
        livros[i].autor[strcspn(livros[i].autor, "\n")] = '\0';

        printf("Nome do cliente: ");
        fgets(livros[i].nome_usuario, 500, stdin);
        livros[i].nome_usuario[strcspn(livros[i].nome_usuario, "\n")] = '\0';

        printf("Endereco do cliente: ");
        fgets(livros[i].endereco_usuario, 500, stdin);
        livros[i].endereco_usuario[strcspn(livros[i].endereco_usuario, "\n")] = '\0';

        printf("Telefone do cliente: ");
        fgets(livros[i].tel_usuario, 500, stdin);
        livros[i].tel_usuario[strcspn(livros[i].tel_usuario, "\n")] = '\0';

        printf("CPF do cliente: ");
        fgets(livros[i].cpf_usuario, 500, stdin);
        livros[i].cpf_usuario[strcspn(livros[i].cpf_usuario, "\n")] = '\0';


        printf("Codigo do livro: ");
        scanf("%d", &livros[i].codigo);

        printf("Preco do livro: ");
        scanf("%f", &livros[i].preco);
        
        getchar(); // Limpa o buffer do 'enter'
    }
}

int contar_livros_acima_de_80_reais(Biblioteca livros[], int n) {
    int cont = 0;
    for(int i = 0; i < n; i++) {
        if(livros[i].preco > 80.00) {
            cont++;
        }
    }
    return cont;
}

void Saida(Biblioteca livros[], int n) {
    printf("\n=== TODOS OS LIVROS CADASTRADOS ===");
    for(int i = 0; i < n; i++) {
        printf("\n%d - Livro: %s | Autor: %s", i + 1, livros[i].nome, livros[i].autor);
        printf("\n    Codigo: %d | Preco: R$ %.2f\n", livros[i].codigo, livros[i].preco);
    }
}

// Busca linear por código inteiro
void buscar_por_codigo(Biblioteca livros[], int n, int codigo_busca) {
    int encontrado = 0;
    for(int i = 0; i < n; i++) {
        if(livros[i].codigo == codigo_busca) {
            printf("\nLivro Encontrado:\n");
            printf("Nome: %s | Autor: %s | Preco: R$ %.2f\n", livros[i].nome, livros[i].autor, livros[i].preco);
            encontrado = 1;
            break; // Código é único, pode parar a busca
        }
    }
    if(!encontrado) {
        printf("\nNenhum livro com o codigo %d foi encontrado.\n", codigo_busca);
    }
}

// Busca exata por nome de autor
void buscar_por_autor(Biblioteca livros[], int n, char autor_busca[]) {
    int encontrado = 0;
    printf("\n Livros do autor '%s':\n", autor_busca);
    for(int i = 0; i < n; i++) {
        if(strcasecmp(livros[i].autor, autor_busca) == 0) { // strcasecmp ignora maiúsculas/minúsculas
            printf("- %s (Codigo: %d) - R$ %.2f\n", livros[i].nome, livros[i].codigo, livros[i].preco);
            encontrado = 1;
        }
    }
    if(!encontrado) {
        printf("Nenhum livro desse autor foi encontrado.\n");
    }
}

// Encontra os extremos de preço
void encontrar_livro_mais_caro_e_barato(Biblioteca livros[], int n) {
    if(n <= 0) return;

    int indice_caro = 0;
    int indice_barato = 0;

    for(int i = 1; i < n; i++) {
        if(livros[i].preco > livros[indice_caro].preco) {
            indice_caro = i;
        }
        if(livros[i].preco < livros[indice_barato].preco) {
            indice_barato = i;
        }
    }

    printf("\n💰 Estatisticas de Precos:\n");
    printf("Mais CARO: %s (R$ %.2f)\n", livros[indice_caro].nome, livros[indice_caro].preco);
    printf("Mais BARATO: %s (R$ %.2f)\n", livros[indice_barato].nome, livros[indice_barato].preco);
}

