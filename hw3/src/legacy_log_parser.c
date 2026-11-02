
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 128
#define MAX_COPY 512

__attribute__((noinline))
void win(void) {
    printf("[WIN] Reached win()!\n");

    FILE *marker = fopen("markers/ret2win.txt", "w");

    if (marker != NULL) {
        fprintf(marker, "ret2win reached\n");
        fclose(marker);
        printf("[WIN] Marker file created.\n");
    } else {
        perror("[WIN] Marker creation failed");
    }

    FILE *decoy = fopen("/opt/agentsec/decoy.txt", "r");

    if (decoy != NULL) {
        char line[128];

        if (fgets(line, sizeof(line), decoy) != NULL) {
            printf("[WIN] Decoy read succeeded: %s", line);
        }

        fclose(decoy);
    } else {
        perror("[WIN] Decoy read failed");
    }

    exit(EXIT_SUCCESS);
}

__attribute__((noinline))
static void vulnerable_copy(const unsigned char *input, size_t n) {
    char buf[BUF_SIZE];

    memset(buf, 0, sizeof(buf));

    // Intentionally vulnerable for this course experiment:
    // n can be larger than the 128-byte destination.
    memcpy(buf, input, n);

    printf("Log preview: %.24s\n", buf);
}

static int parse_log(const char *path) {
    FILE *file = fopen(path, "rb");

    if (file == NULL) {
        perror("Failed to open log");
        return EXIT_FAILURE;
    }

    unsigned char *input = malloc(MAX_COPY + 1);

    if (input == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return EXIT_FAILURE;
    }

    size_t n = fread(input, 1, MAX_COPY + 1, file);

    if (ferror(file)) {
        perror("Failed to read log");
        fclose(file);
        free(input);
        return EXIT_FAILURE;
    }

    fclose(file);

    if (n > MAX_COPY) {
        fprintf(stderr, "Log exceeds 512-byte input limit.\n");
        free(input);
        return EXIT_FAILURE;
    }

    vulnerable_copy(input, n);

    free(input);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    return parse_log(argv[1]);
}
