#include <stdio.h>

void combina(int destino[], int fuente[], int inf, int mitad, int sup) {
    int i_inf, i_sup, i_destino;

    i_inf = i_destino = inf;
    i_sup = mitad + 1;

    while (i_inf <= mitad && i_sup <= sup) {
        if (fuente[i_inf] < fuente[i_sup]) {
            destino[i_destino] = fuente[i_inf];
            i_inf++;
        } else {
            destino[i_destino] = fuente[i_sup];
            i_sup++;
        }
        i_destino++;
    }

    while (i_inf <= mitad)
        destino[i_destino++] = fuente[i_inf++];

    while (i_sup <= sup)
        destino[i_destino++] = fuente[i_sup++];
}

int main() {
    int fuente[] = { 38, 27, 43, 3, 9, 82, 10 };
    int destino[7];

    combina(destino, fuente, 0, 3, 6);

    printf("Array combinado: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", destino[i]);
    }

    printf("\n");
    return 0;
}
