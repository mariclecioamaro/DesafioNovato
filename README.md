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

- A estrutura usada é uma `struct Item` com os campos:  

```c
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;
```

- Os itens são armazenados em um vetor sequencial de até 10 posições.

## 🛠️ Tecnologias utilizadas

Linguagem: C

Bibliotecas:

- **<stdio.h> → Entrada e saída de dados

-  **<stdlib.h> → Utilidades gerais

- **<string.h> → Manipulação de strings

## 📖 Como executar

- **Clone o repositório ou copie o código para um arquivo chamado inventario.c.

- **Compile o programa em um terminal:

```gcc inventario.c -o inventario```

- **Execute o programa:

  ```./inventario```

##📋 Exemplo de uso
- Menu principal:

- ==== Sistema de Inventario ====
- **1. Cadastrar item
- **2. Remover item
- **3. Listar itens
- **4. Buscar item
- **0. Sair
- Escolha uma opcao:


- Cadastro de itens:

Digite o nome do item: Rifle
Digite o tipo do item (arma, municao, cura...): arma
Digite a quantidade: 1
Item adicionado com sucesso!

--- Itens na mochila ---
Nome: Rifle | Tipo: arma | Quantidade: 1


- Remoção:

Digite o nome do item a ser removido: Rifle
Item removido com sucesso!
Mochila vazia.


- Busca:

Digite o nome do item a buscar: KitMedico
Item encontrado!
Nome: KitMedico | Tipo: cura | Quantidade: 2


##📌 Regras de funcionamento

- **O inventário comporta no máximo 10 itens.

- **Não é possível remover ou buscar em uma mochila vazia.

- **Os nomes dos itens são usados como chave de busca (não pode haver dois itens com o mesmo nome).

##🧩 Organização do código

- O programa está dividido em funções para facilitar a manutenção:

- **inserirItem() → adiciona itens na mochila.

- **removerItem() → remove itens pelo nome.

- **listarItens() → lista todos os itens atuais.

- **buscarItem() → busca sequencialmente um item pelo nome.

##🎯 Objetivo educacional

- Este projeto foi desenvolvido como prática de:

- **Structs para agrupar dados.

- **Vetores sequenciais para organizar múltiplos registros.

- **Modularização com funções.

- **Busca sequencial em um vetor de structs.

##📌 Próximos passos poderiam incluir:

- **Implementar mochila dinâmica com ponteiros e alocação dinâmica (malloc).

- **Adicionar sistema de categorias para organizar melhor os itens.

- **Salvar e carregar o inventário em um arquivo.
