#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char decimal_ip[16], binary_ip[34] = "";
    int length[4], i, j;

    // read decimal dotted IP address from user
    printf("Enter the decimal dotted IP address: ");
    scanf("%s", decimal_ip);


    // convert each length to binary and concatenate them
    for (i = 0; i < 4; i++) {
        int bit_pos = 7;
        for (j = 0; j < 8; j++) {
            if (length[i] & (1 << bit_pos)) {
                strcat(binary_ip, "1");
            } else {
                strcat(binary_ip, "0");
            }
            bit_pos--;
        }
        if (i < 3) {
            strcat(binary_ip, ".");
        }
    }

    // print the binary dotted IP address
    printf("The binary dotted IP address is: %s\n", binary_ip);

    return 0;
}
