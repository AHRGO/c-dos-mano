#include<stdio.h>
#include<stdlib.h>
#include "dev_d_favela.h"

//criar um algorítimo para contar uma lista encadeada recursivamente
typedef struct Parsa {
    int numero_da_sorte;
    struct Parsa* o_proximo_mano;
} Parsa;

Parsa* ArranjaUmParsa(int numero_da_sorte) {
    Parsa* o_novo_integrante = (Parsa*) malloc(sizeof(Parsa));
    
    if (o_novo_integrante == NULL) {
        gritaAe("Não tem espaço pro menó no bonde");
        exit(1);
    }

    o_novo_integrante->numero_da_sorte = numero_da_sorte;
    o_novo_integrante->o_proximo_mano = NULL;

    return o_novo_integrante;
}

void adicionaONovimNoBonde(Parsa** quem_eh_o_novato_agora, int numero_da_sorte) {
    Parsa* o_mais_novo_mais_novo_dos_rapazes = ArranjaUmParsa(numero_da_sorte);
    o_mais_novo_mais_novo_dos_rapazes->o_proximo_mano = *quem_eh_o_novato_agora;
    *quem_eh_o_novato_agora = o_mais_novo_mais_novo_dos_rapazes; 
}

void vamoContaOBonde(Parsa* o_novato) {
    Parsa* o_da_vez = o_novato;
    while (o_da_vez != NULL) {
        printf("%d -> ", o_da_vez->numero_da_sorte);
        o_da_vez = o_da_vez->o_proximo_mano;
    }
    gritaAe("Acabou. Foram todos\n");
}

void dispersaOBonde(Parsa* o_da_vez) {
    Parsa* mlk_do_corre;
    while (o_da_vez != NULL) {
        mlk_do_corre = o_da_vez;
        o_da_vez = o_da_vez->o_proximo_mano;
        esqueceSahDroga(mlk_do_corre);
    }
}

int main() {
    Parsa* o_novato = NULL;

    adicionaONovimNoBonde(&o_novato, 10);
    adicionaONovimNoBonde(&o_novato, 20);
    adicionaONovimNoBonde(&o_novato, 30);

    gritaAe("Ó os muleque passando ");

    vamoContaOBonde(o_novato);

    dispersaOBonde(o_novato);

    return 0;
}