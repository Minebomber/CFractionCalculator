#include "../shared/file_reading.h"
#include <stdlib.h>
#include <stdio.h>
#include "fraction.h"
#include "mixed_number.h"
#include "fraction_math.h"

int main() {

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error reading file (1)");
        exit(1);
    }
    char *lines;
    int lines_size = fr_read_lines_from_file(file, &lines);
    int num_lines = fr_num_lines(lines, lines_size);
    for (int n = 0; n < num_lines; n++) {
        char *line;
        int line_size = fr_line_from_array(n, lines, lines_size, &line);
        int w1, n1, d1, w2, n2, d2;
        char *operator;
        int matches = sscanf(line, "%d %d/%d %s %d %d/%d", &w1, &n1, &d1, operator, &w2, &n2, &d2);
        if (matches != 7) {
            printf("Error matching line:\n %s\n", line);
        }

        struct MixedNumber m1 = {.whole = w1, .numerator = n1, .denominator = d1};
        struct MixedNumber m2 = {.whole = w2, .numerator = n2, .denominator = d2};

        struct MixedNumber result;

        if (operator[0] == '+') {
            result = add_mixed_numbers(m1, m2);
        } else if (operator[0] == '-') {
            result = subtract_mixed_numbers(m1, m2);
        } else if (operator[0] == '*') {
            result = multiply_mixed_numbers(m1, m2);
        } else if (operator[0] == '/') {
            result = divide_mixed_numbers(m1, m2);
        }

        printf("%s = %d %d/%d\n", line, result.whole, result.numerator, result.denominator);

        free(line);
    }

    free(lines);
    fclose(file);
    return 0;
}
