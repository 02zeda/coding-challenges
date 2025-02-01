#ifndef JSON_PARSER_H
#define JSON_PARSER_H
#include <stdio.h>
int lex(FILE *input,char* tokens);
int syntax(char*input);
#endif