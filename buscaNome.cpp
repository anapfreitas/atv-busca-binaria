#include<stdio.h>
#include<string.h>
#include<ctype.h>

void converterParaMinusculas(char tmp[]) {
    for (int i = 0; i < strlen(tmp); i++) {
        tmp[i] = tolower(tmp[i]);
    }
}

bool comecaCom(char s1[], char s2[]) {
    if (strlen(s1) < strlen(s2)) return false;
    for (int i = 0; i < strlen(s2); i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

void buscaBinaria(char nomes[][100], int n, char tmp[]) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (comecaCom(nomes[meio], tmp)) {
            printf("%s\n", nomes[meio]);
            int indice = meio - 1;
            while (comecaCom(nomes[indice], tmp) && indice >= 0) {
                printf("%s\n", nomes[indice]);
                indice--;
            }
            indice = meio + 1;
            while (comecaCom(nomes[indice], tmp) && indice < n) {
                printf("%s\n", nomes[indice]);
                indice++;
            }
            return;
        } else if (strcmp(nomes[meio], tmp) > 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
}

int main() {

    FILE *f;
    f = fopen("nomes.txt", "r+");

    int i = 0;
    int n = 517;
    char nomes[n][100];
    char tmp[100];

    while (fscanf(f, "%[^\n]%*c", tmp) != EOF) {
        converterParaMinusculas(tmp);
        strcpy(nomes[i], tmp);
        i++;
    }

    scanf("%[^\n]%*c", tmp);

    converterParaMinusculas(tmp);

    buscaBinaria(nomes, n, tmp);

    return 0;
}


