
#include "json_parser.h"
char* valid_tokens[2] = {"{","}"};
int lex(FILE *input,char *tokens) {
    char buff[10000] = {0};
    while(fgets(buff,10000,input) != NULL) {
        printf("lexing for input: %s\n",buff);
        for(int i =0; valid_tokens[i] !=NULL; i++){
            if (valid_tokens[i][0] == buff[i]) {
                tokens[i] = buff[i];
            }
        }
    }

    return 0;
}
int syntax(char*input) {
    printf("syntax\n");
    return 0;
}
