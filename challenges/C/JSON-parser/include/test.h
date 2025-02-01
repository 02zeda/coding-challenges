#ifndef TEST_H
#define TEST_H
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int main(int argc, char *argv[]);
void get_lex(FILE* file,char* tokens,const char *expected_tokens);
void get_syntax(char* tokens,const char* json);
void step_one();
void step_two();
void step_three();
void step_four();
#endif