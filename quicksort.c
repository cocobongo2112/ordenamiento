#include <stdio.h>

void clasi_rap(int datos[], int inf, int sup)
{
    int i, j, tmp, elem_de_divi;

    if (sup > inf) {
        elem_de_divi = datos[sup];
        i = inf - 1;
        j = sup;

        while (1) {
            while (datos[++i] < elem_de_divi);
            while (datos[--j] > elem_de_divi && j > inf);

            if (i >= j)
                break;

            tmp = datos[i];
            datos[i] = datos[j];
            datos[j] = tmp;
        }

        tmp = datos[i];
        datos[i] = datos[sup];
        datos[sup] = tmp;

        clasi_rap(datos, inf, i - 1);
        clasi_rap(datos, i + 1, sup);
    }
}

int main() {
    int datos[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(datos) / sizeof(datos[0]);

    clasi_rap(datos, 0, n - 1);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    return 0;
}
