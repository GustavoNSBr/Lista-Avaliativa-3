#include <stdio.h>

// Função para converter número romano para decimal
int romanToDecimal(char c) {
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
void decimalToBinary(int decimal) {
    int binary[32];
    int i = 0;

    while (decimal > 0) {
        binary[i++] = decimal % 2;
        decimal = decimal / 2;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    char romanNumber[13];
    scanf("%s", romanNumber);

    int decimal = 0;
    for (int i = 0; romanNumber[i] != '\0'; i++) {
        if (romanToDecimal(romanNumber[i]) < romanToDecimal(romanNumber[i + 1])) {
            decimal += romanToDecimal(romanNumber[i + 1]) - romanToDecimal(romanNumber[i]);
            i++;
        } else {
            decimal += romanToDecimal(romanNumber[i]);
        }
    }

    printf("%s na base 2: ", romanNumber);
    decimalToBinary(decimal);
    printf("%s na base 10: %d\n", romanNumber, decimal);
    printf("%s na base 16: %x\n", romanNumber, decimal);

    return 0;
}
