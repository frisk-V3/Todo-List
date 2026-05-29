#include <stdio.h>
#ifndef VERSION
#define VERSION "local-dev"
#endif

int main() {
    printf("===============================\n");
    printf(" Application Launching...\n");
    printf(" Version (Commit): %s\n", VERSION);
    printf("===============================\n");
    return 0;
}
