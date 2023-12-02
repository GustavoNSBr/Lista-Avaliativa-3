#include <stdio.h>

// Função para converter número romano para decimal
int romanoPraDecimal(char c) {
    switch(c) {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default: return 0;
    }
}

// Função para converter decimal para binário
void decimalParaBinario(int decimal) {
    int binario[32];
    int i = 0;

    while (decimal > 0) {
        binario[i++] = decimal % 2;
        decimal = decimal / 2;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

int main() {
    char numeroRomano[13];
    scanf("%s", numeroRomano);

    int decimal = 0;
    for (int i = 0; numeroRomano[i] != '\0'; i++) {
        if (romanoPraDecimal(numeroRomano[i]) < romanoPraDecimal(numeroRomano[i + 1])) {
            decimal += romanoPraDecimal(numeroRomano[i + 1]) - romanoPraDecimal(numeroRomano[i]);
            i++;
        } else {
            decimal += romanoPraDecimal(numeroRomano[i]);
        }
    }

    printf("%s na base 2: ", numeroRomano);
    decimalParaBinario(decimal);
    printf("%s na base 10: %d\n", numeroRomano, decimal);
    printf("%s na base 16: %x\n", numeroRomano, decimal);

    return 0;
}
