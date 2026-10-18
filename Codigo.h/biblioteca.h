#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

typedef struct Biblioteca {
    char nome[500];
    char autor[500];
    char nome_usuario[500];
    char endereco_usuario[500];
    char cpf_usuario[500];
    char tel_usuario[500];
    int codigo;
    float preco;
} Biblioteca;

void Entrada(Biblioteca livros[], int n);
int contar_livros_acima_de_80_reais(Biblioteca livros[], int n);
void Saida(Biblioteca livros[], int n);
void buscar_por_codigo(Biblioteca livros[], int n, int codigo_busca);
void buscar_por_autor(Biblioteca livros[], int n, char autor_busca[]);
void encontrar_livro_mais_caro_e_barato(Biblioteca livros[], int n);

#endif

