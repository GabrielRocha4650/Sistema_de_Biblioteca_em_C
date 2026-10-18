#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

int main() {
    int n;
    
    printf("Quantos livros deseja cadastrar no sistema? ");
    scanf("%d", &n);
    getchar(); // Limpa buffer

    Biblioteca livros[n];
    
    // Cadastro inicial obrigatório dos N livros
    Entrada(livros, n);

    int opcao;
    do {
        printf("\n====================================");
        printf("\n          MENU BIBLIOTECA           ");
        printf("\n====================================");
        printf("\n1 - Listar todos os livros");
        printf("\n2 - Quantidade de livros acima de R$ 80,00");
        printf("\n3 - Buscar livro por Codigo");
        printf("\n4 - Buscar livros por Autor");
        printf("\n5 - Ver livro mais Caro e mais Barato");
        printf("\n6 - Ver Clientes Cadastrados");
        printf("\n0 - Sair do sistema");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa buffer

        switch(opcao) {
            case 1:
                Saida(livros, n);
                break;
            case 2: {
                int quant = contar_livros_acima_de_80_reais(livros, n);
                printf("\nQuantidade de livros acima de R$ 80,00: %d\n", quant);
                break;
            }
            case 3: {
                int cod;
                printf("\nDigite o codigo que deseja buscar: ");
                scanf("%d", &cod);
                getchar();
                buscar_por_codigo(livros, n, cod);
                break;
            }
            case 4: {
                char autor[500];
                printf("\nDigite o nome do autor completo para busca: ");
                fgets(autor, 500, stdin);
                autor[strcspn(autor, "\n")] = '\0';
                buscar_por_autor(livros, n, autor);
                break;
            }
            case 5:
                encontrar_livro_mais_caro_e_barato(livros, n);
                break;

            case 6:
              printf("\n=== TODOS OS CLIENTES CADASTRADOS ===");
               for(int i = 0; i < n; i++) {
                 printf("\n%d - Nome: %s | Telefone: %s  | CPF: %s | Endereco: %s\n", i + 1, livros[i].nome_usuario, livros[i].tel_usuario
                 ,livros[i].cpf_usuario,livros[i].endereco_usuario);
               }
                break;

            case 0:
                printf("\nFechando o sistema. Ate logo!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}

