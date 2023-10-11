// Determine o numero de ancestrais de um 
// determinado nó se ele existe
// na arvore

void main(){
    Arvore *arvore = NULL;
    int quantidadeAncestrais = 0;
    arvore = criarArvore();

    quantidadeAncestrais = ancestrais(arvore);
}