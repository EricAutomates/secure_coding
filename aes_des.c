#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

// Generic encryption function (works for both AES and DES)
int encrypt(unsigned char *plaintext, int plaintext_len,
            unsigned char *key, unsigned char *iv,
            unsigned char *ciphertext, const EVP_CIPHER *cipher) {

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int len, ciphertext_len;

    // Initialize encryption with chosen algorithm (AES or DES)
    EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv);

    // Perform encryption
    EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len);
    ciphertext_len = len;

    // Finalize encryption
    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

// Generic decryption function (works for both AES and DES)
int decrypt(unsigned char *ciphertext, int ciphertext_len,
            unsigned char *key, unsigned char *iv,
            unsigned char *plaintext, const EVP_CIPHER *cipher) {

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int len, plaintext_len;

    // Initialize decryption with chosen algorithm (AES or DES)
    EVP_DecryptInit_ex(ctx, cipher, NULL, key, iv);

    // Perform decryption
    EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len);
    plaintext_len = len;

    // Finalize decryption
    EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return plaintext_len;
}

int main() {
    unsigned char text[] = "Hello Crypto!";

    unsigned char ciphertext[128];
    unsigned char decrypted[128];

    // ================= AES SECTION =================
    // AES uses 16-byte (128-bit) key and IV
    unsigned char aes_key[16] = "1234567890123456";
    unsigned char aes_iv[16]  = "1234567890123456";

    // Encrypt using AES (EVP_aes_128_cbc specifies AES algorithm)
    int enc_len = encrypt(text, strlen((char*)text),
                          aes_key, aes_iv,
                          ciphertext,
                          EVP_aes_128_cbc());   // <-- AES USED HERE

    // Decrypt using AES
    int dec_len = decrypt(ciphertext, enc_len,
                          aes_key, aes_iv,
                          decrypted,
                          EVP_aes_128_cbc());   // <-- AES USED HERE

    decrypted[dec_len] = '\0';
    printf("AES Decrypted Text: %s\n", decrypted);


    // ================= DES SECTION =================
    // DES uses 8-byte (64-bit) key and IV
    unsigned char des_key[8] = "12345678";
    unsigned char des_iv[8]  = "12345678";

    // Encrypt using DES (EVP_des_cbc specifies DES algorithm)
    enc_len = encrypt(text, strlen((char*)text),
                      des_key, des_iv,
                      ciphertext,
                      EVP_des_cbc());          // <-- DES USED HERE

    // Decrypt using DES
    dec_len = decrypt(ciphertext, enc_len,
                      des_key, des_iv,
                      decrypted,
                      EVP_des_cbc());          // <-- DES USED HERE

    decrypted[dec_len] = '\0';
    printf("DES Decrypted Text: %s\n", decrypted);

    return 0;
}
