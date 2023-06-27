#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Function to convert binary string to decimal number
int binaryToDecimal(char *binary)
{
    int decimal = 0;
    int power = 0;
    int len = strlen(binary);
    // Iterate through the string from right to left
    for (int i = len - 1; i >= 0; i--)
    {
        // If the current character is '1', add 2^power to decimal
        if (binary[i] == '1')
        {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}
// Function to convert binary dotted IP address to decimal IP address
void binaryToDecimalIP(char *binaryIP, int *decimalIP)
{
    char *token;
    char *rest = binaryIP;
    int i = 0;

    // Split the binary IP address by '.' and convert each part to decimal
    while ((token = strtok_r(rest, ".", &rest)))
    {
        decimalIP[i++] = binaryToDecimal(token);
    }
}

int main()
{
    char binaryIP[33];
    int decimalIP[4];
    printf("Enter a binary dotted IP address: ");
    scanf("%s", binaryIP);

    binaryToDecimalIP(binaryIP, decimalIP);

    printf("Decimal IP address: %d.%d.%d.%d\n", decimalIP[0], decimalIP[1], decimalIP[2], decimalIP[3]);

    return 0;
}

