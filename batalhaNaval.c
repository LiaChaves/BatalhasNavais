#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LINHA 10
#define COLUNA 10
#define BOMBA 1
#define BARCO 3
#define ACERTOU 5
#define AGUA 0

void Navio(int matriz[LINHA][COLUNA], int i, int j, int navio){
if (navio == 1) { // if dentro de cada barco delimita a posição que irá surgir
    for (int a = i -1 ; a <= i + 1; a++) {
        if (a >= 0 && a < LINHA) {
        matriz[a][j] = BARCO;}}
} else if (navio == 2) {
    for (int a = j -1; a <= j + 1; a++) {
        if (a >= 0 && a < COLUNA) {
        matriz[i][a] = BARCO;}}
} else if (navio == 3) {
    for (int a = 0; a < 2; a++) {
        if (i + a < LINHA && j - a >= 0) {
        matriz[i + a][j - a] = BARCO;}
        if (i - a >= 0 && j + a < COLUNA) {
        matriz[i - a][j + a] = BARCO;}}
} else if (navio == 4) {
    for (int a = 0; a < 2; a++) {
        if (i + a < LINHA && j + a < COLUNA) {
        matriz[i + a][j + a] = BARCO;}
        if (i - a >= 0 && j - a >= 0) { 
        matriz[i - a][j - a] = BARCO;}}}}

void BombaCone(int matriz[LINHA][COLUNA], int i, int j){
  for (int c = 2; c > 0; c--) {
    for(int a = j - c; a <= j + c; a++){
        if (i + c < LINHA && a >= 0 && a < COLUNA) {
        matriz[i + c][a] = BOMBA;}
        for(int b = i + c; b >= i; b--){
            if (b >= 0 && b < LINHA) {
            matriz[b][j] = BOMBA;}
        }}}
}
void BombaOctaedro(int matriz[LINHA][COLUNA], int i, int j){
   for (int c = 0; c <= 1; c++){
    for (int a = i - 2 + c; a <= i + 2 - c; a++) {
        if (a >= 0 && a < LINHA) {
            if (j - c >= 0 && j - c < COLUNA) {
        matriz[a][j - c] = BOMBA;}
           if (j + c >= 0 && j + c < COLUNA) {
        matriz[a][j + c] = BOMBA;}}
        for (int b = j - 2; b <= j + 2; b++) {
            if (b >= 0 && b < COLUNA) {
            matriz[i][b] = BOMBA;}
           
        }}}
 }
void BombaCruz(int matriz[LINHA][COLUNA], int i, int j){
  
    for (int a = i - 1; a <= i + 1; a++) {
        if (a >= 0 && a < LINHA) {
        matriz[a][j] = BOMBA;}}
        for (int a = j - 2; a <= j + 2; a++) {
            if (a >= 0 && a < COLUNA) {
            matriz[i][a] = BOMBA;}}
 }
 void contapontos(int JGD1[LINHA][COLUNA], int JGD2[LINHA][COLUNA], int B1[LINHA][COLUNA], int B2[LINHA][COLUNA], int *countexjgd1, int *countexjgd2){
     for (int i = 0; i < LINHA; i++) {
         for (int j = 0; j < COLUNA; j++) {
             if (JGD1[i][j] == BARCO && B2[i][j] == BOMBA) {
                 JGD1[i][j] = ACERTOU; B2[i][j] = ACERTOU;
                 (*countexjgd2)++;}}
     }
     for (int i = 0; i < LINHA; i++) {
         for (int j = 0; j < COLUNA; j++) {
             if (JGD2[i][j] == BARCO && B1[i][j] == BOMBA) {
                 JGD2[i][j] = ACERTOU;B1[i][j] = ACERTOU;
                 (*countexjgd1)++;}}
     }
 }
 void zerarmatriz(int a[LINHA][COLUNA], int b[LINHA][COLUNA], int c[LINHA][COLUNA], int d[LINHA][COLUNA]){
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            a[i][j] = AGUA; b[i][j] = AGUA; c[i][j] = AGUA; d[i][j] = AGUA; }
        }
 }

void imprimirMatriz(int matriz[LINHA][COLUNA]) {
    printf("  ");
    for (int i = 0; i < COLUNA; i++) {
        printf("%d ", i + 1);}
    for (int i = 0; i < LINHA; i++) {
        char l = 'A' + i;
        printf("\n");
        printf("%c ", l);
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", matriz[i][j]);}}
    printf("\n");}

int main() {
    srand(time(0)); //aleatorio conforme a hora
    int JGD1[LINHA][COLUNA], JGD2[LINHA][COLUNA], B1[LINHA][COLUNA], B2[LINHA][COLUNA];
    char linhaindex; 
    int colunaindex, countexjgd1 = 0, countexjgd2 = 0, bomba, menu, tipjogo, navio;
    // chamada aleatorio para jogador vs pc
int PClinha, PCcoluna, PCbomba, PCnavio;
// coloca agua no tabuleiro sem transbordar
    zerarmatriz(JGD1, JGD2, B1, B2);
        do{
    printf("Bem-vinde ao jogo de batalha naval\n");
    printf("[1] Jogar!\n[2] Regras!\n[3] Sair!\n");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        do{printf("Como deseja jogar?\n[1] Jogador Vs Jogador!\n[2] Jogador Vs PC!\n[3] Voltar!\n");
        scanf("%d", &tipjogo);
        
switch (tipjogo)
{
case 1:
zerarmatriz(JGD1, JGD2, B1, B2);
    printf("Vamos começar!\nJogador 1, coloque o seu navio\n");
    imprimirMatriz(JGD1);
    for(int countnavio = 0; countnavio < 3; countnavio++){
    printf("Digite a linha e a coluna do navio %d\n", countnavio + 1);
    scanf(" %c %d", &linhaindex, &colunaindex);
    printf("Como deseja por o seu navio?\n[1] Vertical!\n[2] Horizontal!\n[3] Diagonal Esquerda!\n[4] Diagonal Direita!\n");
scanf("%d", &navio);
    int lIndex = (linhaindex >= 'A' && linhaindex <= 'Z') ? linhaindex - 'A' : linhaindex - 'a';
    int cIndex = colunaindex - 1; // Linha 127 e 128 são para conversão de letra para numero e vice-versa
    Navio(JGD1, lIndex, cIndex, navio);
    imprimirMatriz(JGD1);}
    printf("\n\n");//FINAL COLOCAR NAVIO jgd1
    printf("Jogador 2, coloque o seu navio\n");
    imprimirMatriz(JGD2);
    for(int countnavio = 0; countnavio < 3; countnavio++){
        printf("Digite a linha e a coluna do navio %d\n", countnavio + 1);
        scanf(" %c %d", &linhaindex, &colunaindex);
        printf("Como deseja por o seu navio?\n[1] Vertical!\n[2] Horizontal!\n[3] Diagonal Esquerda!\n[4] Diagonal Direita!\n");
scanf("%d", &navio);
        int lIndex = (linhaindex >= 'A' && linhaindex <= 'Z') ? linhaindex - 'A' : linhaindex - 'a';
        int cIndex = colunaindex - 1; // Linha 137 e 138 são para conversão de letra para numero e vice-versa
        Navio(JGD2, lIndex, cIndex, navio);
        imprimirMatriz(JGD2);}
        printf("\n\n\n\n\n\n\n\n\n\n\n\n"); //FINAL COLOCAR NAVIO jgd2
        for(int countbomb = 0; countbomb < 3; countbomb++){
printf("Jogador 1, onde deseja jogar a %d bomba?\n", countbomb + 1);
scanf(" %c %d", &linhaindex, &colunaindex);
int lIndex = (linhaindex >= 'A' && linhaindex <= 'Z') ? linhaindex - 'A' : linhaindex - 'a';
int cIndex = colunaindex - 1; // mesma chamada igual as outras mil
printf("Qual bomba deseja jogar?\n");
printf("[1] Cruz\n[2] Octaedro\n[3] Cone\n");
scanf("%d", &bomba);   
if (bomba == 1) {
    BombaCruz(B1, lIndex, cIndex);  }
        else if (bomba == 2) {
            BombaOctaedro(B1, lIndex, cIndex);}
        else if (bomba == 3) {
            BombaCone(B1, lIndex, cIndex);}
            imprimirMatriz(B1);
        printf("\n\n");}
        //final jogada das bombas do jogador 1 e inicio do jogador 2
        for(int countbomb = 0; countbomb < 3; countbomb++){
        printf("Jogador 2, onde deseja jogar a %d bomba?\n", countbomb + 1);
scanf(" %c %d", &linhaindex, &colunaindex);
int lIndex = (linhaindex >= 'A' && linhaindex <= 'Z') ? linhaindex - 'A' : linhaindex - 'a';
int cIndex = colunaindex - 1; // mesma chamada iguais a de cima
printf("Qual bomba deseja jogar?\n");
printf("[1] Cruz\n[2] Octaedro\n[3] Cone\n");
scanf("%d", &bomba);   
if (bomba == 1) {
    BombaCruz(B2, lIndex, cIndex);  }
        else if (bomba == 2) {
            BombaOctaedro(B2, lIndex, cIndex);}
        else if (bomba == 3) {
            BombaCone(B2, lIndex, cIndex);} 
            imprimirMatriz(B2);
        printf("\n\n");}// final jogada das bombas 

    contapontos(JGD1, JGD2, B1, B2, &countexjgd1, &countexjgd2);
        
        printf("Jogador 1 acertou %d vezes\n", countexjgd1);
        printf("Jogador 2 acertou %d vezes\n", countexjgd2);
        if (countexjgd1 > countexjgd2){
            printf("Jogador 1 venceu!\nParabéns\n");}
        else if (countexjgd1 < countexjgd2){
            printf("Jogador 2 venceu!\nParabéns!\n");}
        else{
            printf("Empate!\n");
        }
        printf("Campo Jogador 1!\n");  imprimirMatriz(JGD1);
        printf("Campo Jogador 2!\n");  imprimirMatriz(JGD2);
   printf("Deseja jogar novamente?\n[1] SIM!\n[2] NÃO!\n");
   scanf("%d", &tipjogo);
   if (tipjogo == 1){break;} else if (tipjogo == 2){printf("Obrigada por jogar!\nSaindo...\n"); return 0;}
    break;
    case 2:
    zerarmatriz(JGD1, JGD2, B1, B2);
    printf("Vamos começar!\nJogador, coloque o seu navio\n");
    imprimirMatriz(JGD1);
    for(int countnavio = 0; countnavio < 3; countnavio++){
    printf("Digite a linha e a coluna do navio %d\n", countnavio + 1);
    scanf(" %c %d", &linhaindex, &colunaindex);
    printf("Como deseja por o seu navio?\n[1] Vertical!\n[2] Horizontal!\n[3] Diagonal Esquerda!\n[4] Diagonal Direita!\n");
scanf("%d", &navio);
    int lIndex = (linhaindex >= 'A' && linhaindex <= 'Z') ? linhaindex - 'A' : linhaindex - 'a';
    int cIndex = colunaindex - 1; // Linha 197 e 198 são para conversão de letra para numero e vice-versa
    Navio(JGD1, lIndex, cIndex, navio);
    imprimirMatriz(JGD1);}
    for(int countbomb = 0; countbomb < 3; countbomb++){
        printf("Jogador, onde deseja jogar a %d bomba?\n", countbomb + 1);
        scanf(" %c %d", &linhaindex, &colunaindex);
        int lIndex = (linhaindex >= 'A' && linhaindex <= 'Z') ? linhaindex - 'A' : linhaindex - 'a';
        int cIndex = colunaindex - 1; // msm chamada de sempre ara correção de valores
        printf("Qual bomba deseja jogar?\n");
        printf("[1] Cruz\n[2] Octaedro\n[3] Cone\n");
        scanf("%d", &bomba);   
        if (bomba == 1) {
            BombaCruz(B1, lIndex, cIndex);  }
                else if (bomba == 2) {
                    BombaOctaedro(B1, lIndex, cIndex);}
                else if (bomba == 3) {
                    BombaCone(B1, lIndex, cIndex);}
                    imprimirMatriz(B1);
                printf("\n\n");} // final jogador joga bombas
                // começo chamada pc aleatorio
                int i = 0;
                while( i < 3){
                     PClinha = rand() % 10; 
                     PCcoluna = rand() % 10; //chamada sempre aleatoria
                     PCnavio = rand() % 4 + 1;
                    Navio(JGD2, PClinha, PCcoluna, PCnavio);
                    i++;
                }
                i = 0;
                while ( i < 3){
                        PClinha = rand() % 10; 
                        PCcoluna = rand() % 10; //chamada sempre aleatoria
                        PCbomba = rand() % 3 + 1; 
                    if (PCbomba == 1){ BombaCone(B2, PClinha, PCcoluna);}
                    else if (PCbomba == 2){BombaCruz(B2, PClinha, PCcoluna);}
                    else if (PCbomba == 3) {BombaOctaedro(B2, PClinha, PCcoluna);}
                    i++;
                }
                contapontos(JGD1, JGD2, B1, B2, &countexjgd1, &countexjgd2);
        
        printf("Jogador acertou %d vezes\n", countexjgd1);
        printf("O PC acertou %d vezes\n", countexjgd2);
        if (countexjgd1 > countexjgd2){
            printf("Jogador venceu!\nParabéns\n");}
        else if (countexjgd1 < countexjgd2){
            printf("O PC venceu!\nParabéns!\n");}
        else{
            printf("Empate!\n");
        }
        printf("Deseja ver a posição do PC?\n[1] SIM!\n[2] NÂO!\n");
        scanf("%d", &tipjogo);
        if (tipjogo == 1){printf("Campo de Navios!\n");  imprimirMatriz(JGD2); printf("Campo de Bombas!\n");  imprimirMatriz(B2);}
        else{;}
        printf("Deseja jogar novamente?\n[1] SIM!\n[2] NÃO!\n");
   scanf("%d", &tipjogo);
   if (tipjogo == 1){break;} else if (tipjogo == 2){printf("Obrigada por jogar!\nSaindo...\n"); return 0;}
    break;

}}while(tipjogo != 3);
        break;
        case 2:
        printf("BEM VINDO A BATALHA NAVAL EM C.!\nEste é um tabuleiro\n");
        imprimirMatriz(JGD1);
        printf("Escolha uma letra de A até J para escolher a LINHA!\nE escolha um número de 1 até 10 para escolher uma COLUNA!\nOs Navios são representados por 3!\nAs Bombas são representadas por 1!\nE quando uma bomba acerta um navio ambos viram 5!\nPosicione seus navios e jogue bombas no mar do adversario!\nBom Jogo!\n");
        break;
        
    }}while(menu != 3);
    printf("Obrigada por jogar!\nSaindo...\n");
    return 0;}
