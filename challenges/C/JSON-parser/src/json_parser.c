
#include "json_parser.h"
#define LB 0
#define RB 1
#define START 0

struct token {
    char* token;
    int type;
};
struct syntax_tree {
    struct token* tokens;
    struct syntax_tree* children;
    int type;
};
static int token_count = 0;
int lex(FILE *input,struct token *tokens) {
    int token_index = 0;
    int index =0;
    char buff[10000] = {0};
    while(fgets(buff,10000,input) != NULL) {
        printf("lexing for input: %s\n",buff);
        char c;
        while((c = buff[index]) != NULL){
            if(buff[index]== '{' || buff[index] == '}') {
                tokens[token_index].token = c;
                if(c == '{') {
                    tokens[token_index].type = LB;
                } else {
                    tokens[token_index].type = RB;
                }
                token_index++;
            }
            index++;
        }
    }
    token_count = token_index;
    return 0;
}
int syntax(struct token *tokens) {
    struct syntax_tree* root = (struct syntax_tree*)malloc(sizeof(struct syntax_tree));
    for(int i=0; i<token_count; i++){
        if(tokens[i].type == LB) {
            root->tokens = &tokens[i];
            root->type = START;
        }
    }
    return 0;
}
