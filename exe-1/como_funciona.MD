# **Como funciona a função insere_ArvBin()???**

A função insere_ArvBin insere um valor em uma Árvore Binária de Busca (ABB). 
A seguir, irei descrever o funcionamento e comportamento esperado.

## **Descrição da Função insere_ArvBin()**

- **Verificação Inicial:**
    - A função verifica se a raiz da árvore é NULL. Se for, retorna 0 para indicar que a árvore não foi inicializada.

    ```C
    if (raiz == NULL) {
        return 0;
    }
    ```

- **Criação do Nó:**
    - Um novo nó é alocado dinamicamente com malloc. Se a alocação falhar (retornando NULL), a função retorna 0.

    ```C
    struct NO* novo;

    novo = (struct NO*) malloc(sizeof(struct NO));

    if (novo == NULL) {
        return 0;
    }
    ```

- **Atribuição de Valores ao Novo Nó:**
    - O campo info do nó recebe o valor a ser inserido.
    - Os ponteiros para os filhos (esq e dir) são inicializados como NULL.

    ```C
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    ```

- **Caso Raiz da Árvore Esteja Vazia:**
    - Se a raiz da árvore estiver vazia (*raiz == NULL), o novo nó se torna a raiz

    ```C
    if (*raiz == NULL) {
        *raiz = novo;
    }
    ```

- **Inserção na Subárvore:**
    - Se a árvore já contém elementos, começa a partir da raiz e percorre a árvore seguindo a lógica da ABB:
        - Se o valor for maior que o nó atual, segue para a subárvore direita.
        - Se for menor, segue para a subárvore esquerda.

    - Um ponteiro ant acompanha o último nó visitado.
    - Se o valor já existir na árvore, o novo nó é liberado, e a função retorna 0.

    ```C
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;

        while (atual != NULL) {
            ant = atual;

            if (valor == atual->info) {
                free(novo);
                return 0; // O elemento já existe
            }

            if (valor > atual->info) {
                atual = atual->dir;
            }

            else {
                atual = atual->esq;
            }
        }
    }
    ```

- **Conexão do Novo Nó:**
    - Após encontrar a posição correta, o novo nó é conectado como filho esquerdo ou direito do nó anterior (ant).

    ```C
    if (valor > ant->info) {
        ant->dir = novo;
    }
    
    else {
        ant->esq = novo;
    }
    ```

- **Retorno:**
    - Retorna 1 para indicar que o valor foi inserido com sucesso.

    ```C
    return 1;
    ```