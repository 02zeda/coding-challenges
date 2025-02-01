
#include "json_parser.h"
int lex(FILE *input,char *tokens) {
    char* buffer[10000] = {0};
    fgets(buffer,10000,input);
    printf("lexing for input: %s\n",buffer);
    return 0;
}
int syntax(char*input) {
    printf("syntax\n");
    return 0;
}
