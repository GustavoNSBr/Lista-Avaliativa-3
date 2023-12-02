#include <stdio.h>
#include <math.h>

int main() {
    int meses, i;
    double aporte, taxa, valor_total, montante;

    // Entrada de dados
    scanf("%d %lf %lf", &meses, &aporte, &taxa);

    // Cálculo e saída
    valor_total = 0;
    for (i = 1; i <= meses; i++) {
        montante = aporte * pow((1 + taxa), i);
        valor_total += montante;
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, valor_total);
    }

    return 0;
}