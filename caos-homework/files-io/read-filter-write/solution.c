#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file_digits> <output_file_others>\n", argv[0]);
        return 1;
    }

    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        return 1;
    }

    int output_digits_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_digits_fd == -1) {
        close(input_fd);
        return 2;
    }

    int output_others_fd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_others_fd == -1) {
        close(input_fd);
        close(output_digits_fd);
        return 2;
    }

    char buffer[1024];
    ssize_t bytes_read;

    while ((bytes_read = read(input_fd, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (isdigit(buffer[i])) {
                if (write(output_digits_fd, &buffer[i], 1) == -1) {
                    close(input_fd);
                    close(output_digits_fd);
                    close(output_others_fd);
                    return 3;
                }
            } else {
                if (write(output_others_fd, &buffer[i], 1) == -1) {
                    close(input_fd);
                    close(output_digits_fd);
                    close(output_others_fd);
                    return 3;
                }
            }
        }
    }

    if (bytes_read == -1) {
        close(input_fd);
        close(output_digits_fd);
        close(output_others_fd);
        return 3;
    }

    close(input_fd);
    close(output_digits_fd);
    close(output_others_fd);

    return 0;
}

