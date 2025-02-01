#ifndef TEST_H
#define TEST_H
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
int main(int argc, char *argv[]);
void get_lex(FILE* file,char* tokens,const char *expected_tokens);
void get_syntax(char* tokens,const char* json);
int step_one();
int step_two();
int step_three();
int step_four();
#endif