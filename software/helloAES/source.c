/*
 * source.c
 *
 *  Created on: Jun 15, 2025
 *      Author: ASUS
 */




/*
 * source.c
 *
 *  Created on: Jun 15, 2025
 *      Author: ASUS
 */




#include "system.h"
#include "io.h"
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {
    /* key */
    uint32_t key[4]   = { 0x0f1571c9, 0x47d9e859, 0x0cb7add6, 0xaf7f6798 };


    /*  plaintext */
    uint32_t data[4]  = { 0x3ab78499, 0xf1451a07, 0x6c2dfed2, 0x9ec0335b};

    uint32_t ct[4];
    int i;

    /* -------- 1-------- */
    while (!(IORD(IP_SLAVE_0_BASE, 15) & 0x1)) { }
    for (i = 0; i < 4; i++)
        IOWR(IP_SLAVE_0_BASE, i, key[i]);// Load_Key
    IOWR(IP_SLAVE_0_BASE, 5, 1);

    while (!(IORD(IP_SLAVE_0_BASE, 15) & 0x1)) { }
    for (i = 0; i < 4; i++)
        IOWR(IP_SLAVE_0_BASE, i, data[i]); // Load_Data
    IOWR(IP_SLAVE_0_BASE, 4, 1);

    while (!(IORD(IP_SLAVE_0_BASE, 10) & 0x1)) { }
    for (i = 0; i < 4; i++)
        ct[i] = IORD(IP_SLAVE_0_BASE, 6 + i);

    printf("Write Key\n");
    printf("Key      =");
    for (i = 0; i < 4; i++)
        printf(" 0x%08" PRIx32, key[i]); // Display_Key
    printf("\nPlain    =");
    for (i = 0; i < 4; i++)
        printf(" 0x%08" PRIx32, data[i]);// Display_Plain
    printf("\nCipher   =");
    for (i = 0; i < 4; i++)
        printf(" 0x%08" PRIx32, ct[i]);// Display_Cipher
    printf("\n\n");



    return 0;
}
