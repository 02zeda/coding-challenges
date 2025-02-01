#include "json_parser.h"
#include "main.h"


int main(int argc, char *argv[]) {
    int return_code = 0;
    if (argc < 2) {
        printf("Usage: %s file.json\n", argv[0]);
        return_code = 1;
        return return_code;
    }

    FILE* file;
    char* tokens[10000] = {0};
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("%s not found\n",argv[1]);
        return 1;
    }
    return_code = lex(file,tokens);
    if (return_code != 0) {
        return return_code;
    }
    return_code = syntax(tokens);
    if (return_code != 0) {
        return return_code;
    }
    return 0;
}