#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aes.h"

int aes_ecb_encrypt(uint8* ptrinput, uint8 *ptroutput, uint32 len)
{
    uint32 i = 0;
    uint32 count = len / 16;
    aes_context ctx;
    uint8 *ptrplain = NULL;
    uint8 *ptrencrypt = NULL;
    uint8 key[16]={0x01, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

    if (ptrinput == NULL || ptroutput == NULL)
    {
        return -1;
    }
    
    /* 长度必须是16的倍数 */
    if (len < 16 || len % 16 != 0)
    {
        return -1;
    }

    aes_set_key(&ctx, key, 128); 

    ptrplain = ptrinput;
    ptrencrypt = ptroutput;

    for (i = 0; i < count; i++)
    {
        aes_encrypt(&ctx, ptrplain, ptrencrypt);
        ptrplain += 16;
        ptrencrypt += 16;
    }

    return 0;
}

int aes_ecb_decrypt(uint8* ptrinput, uint8 *ptroutput, uint32 len)
{
    uint32 i = 0;
    uint32 count = len / 16;
    aes_context ctx;
    uint8 *ptrplain = NULL;
    uint8 *ptrdecrypt = NULL;
    uint8 key[16]={0x01, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

    if (ptrinput == NULL || ptroutput == NULL)
    {
        return -1;
    }

    /* 长度必须是16的倍数 */
    if (len < 16 || len % 16 != 0)
    {
        return -1;
    }

    aes_set_key(&ctx, key, 128); 

    ptrplain = ptrinput;
    ptrdecrypt = ptroutput;

    for (i = 0; i < count; i++)
    {
        aes_decrypt(&ctx, ptrplain, ptrdecrypt);
        ptrplain += 16;
        ptrdecrypt += 16;
    }

    return 0;
}


int main()
{
    char plain_text[32]="This is a test string.";
    //char plain_text[32]="0123456789abcdef";
    char encrypt_text[128]={0};
    char decrypt_text[128]={0};

    /* 长度必须是16的倍数 */
    aes_ecb_encrypt(plain_text, encrypt_text, 32);
    aes_ecb_decrypt(encrypt_text, decrypt_text, 32);

    printf("plain_text: %s\n\n", plain_text);
    printf("decrypt_text: %s\n", decrypt_text);

#if 0
    int i = 0;

    printf("plain_text: ");
    for (i = 0; i < strlen(plain_text); i++)
    {
        printf("0x%x ", plain_text[i]);
    }
    printf("\n\n");

    printf("enctypt_text: ");
    for (i = 0; i < strlen(plain_text); i++)
    {
        printf("0x%x ", encrypt_text[i]);
    }
    printf("\n\n");

    printf("dectypt_text: ");
    for (i = 0; i < strlen(plain_text); i++)
    {
        printf("0x%x ", decrypt_text[i]);
    }
    printf("\n\n");
#endif

    return 0;
}
