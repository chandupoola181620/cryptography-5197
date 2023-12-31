#include <stdio.h>

// Function to calculate the greatest common divisor (GCD)
unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate the modulo inverse
unsigned long long int modInverse(unsigned long long int a, unsigned long long int m) {
    unsigned long long int m0 = m, t, q;
    unsigned long long int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now
        m = a % m;
        a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

int main() {
    unsigned long long int p, q, e, n, phi_n, d, plaintext, ciphertext, decrypted;

    // Assume values of p, q, and e are known
    p = 7;
    q = 11;
    e = 17;

    n = p * q;
    phi_n = (p - 1) * (q - 1);

    // Find a potential factor of n using the information given
    unsigned long long int potential_factor;
    printf("Enter a potential factor of n: ");
    scanf("%llu", &potential_factor);

    if (gcd(n, potential_factor) > 1) {
        // If the potential factor is indeed a factor of n
        // Calculate the private key (d) using the public key (e) and phi(n)
        d = modInverse(e, phi_n);

        // Decrypt the ciphertext block corresponding to the known plaintext block
        printf("Enter the ciphertext block corresponding to the known plaintext: ");
        scanf("%llu", &ciphertext);

        // Decrypt the known ciphertext block
        decrypted = 1;
        for (unsigned long long int i = 0; i < d; i++) {
            decrypted = (decrypted * ciphertext) % n;
        }

        printf("Decrypted plaintext: %llu\n", decrypted);
    } else {
        printf("The provided potential factor is not a factor of n.\n");
    }

    return 0;
}
