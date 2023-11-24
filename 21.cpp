#* key) {
    // Implement ECB encryption logic here
    printf("ECB mode encryption\n");
}

// CBC mode encryption
void cbc_encrypt(char* plaintext, char* key, char* iv) {
    // Implement CBC encryption logic here
    printf("CBC mode encryption\n");
}

// CFB mode encryption
void cfb_encrypt(char* plaintext, char* key, char* iv) {
    // Implement CFB encryption logic here
    printf("CFB mode encryption\n");
}

int main() {
    char plaintext[256];
    char key[256];
    char iv[256];

    // Get plaintext, key, and IV from user input
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    printf("Enter IV: ");
    fgets(iv, sizeof(iv), stdin);

    // Remove newline characters from user input
    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';
    iv[strcspn(iv, "\n")] = '\0';

    // Perform encryption in different modes
    ecb_encrypt(plaintext, key);
    cbc_encrypt(plaintext, key, iv);
    cfb_encrypt(plaintext, key, iv);

    return 0;
}


