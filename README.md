# 🎒 Sistema de Inventário em C  

Este projeto implementa um **sistema básico de inventário (mochila)** para um jogo de sobrevivência.  
O jogador pode cadastrar, remover, listar e buscar itens coletados (como armas, munições e kits médicos).  

O objetivo é praticar o uso de **structs, vetores e funções** em C, simulando a organização inicial de loot em um jogo.  

---

## 🚀 Funcionalidades  

- **Cadastro de itens**: até 10 itens podem ser adicionados, cada um com `nome`, `tipo` e `quantidade`.  
- **Remoção de itens**: permite remover um item pelo nome.  
- **Listagem**: exibe todos os itens da mochila após cada operação.  
- **Busca sequencial**: procura um item pelo nome e exibe seus dados.  

---

## 📂 Estrutura de Dados  

A estrutura usada é uma `struct Item` com os campos:  

```c
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;
