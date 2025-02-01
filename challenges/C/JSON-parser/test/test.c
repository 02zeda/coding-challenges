#include "test.h"
#include "json_parser.h"
int step_one() {
    char* tokens[10000] = {0};
    FILE* file;
    file = fopen("step1/invalid.json", "r");
    if (file == NULL) {
        printf("invalid.json not found\n");
        return 1;
    }
    get_lex(file,tokens,"");
    file = fopen("step1/valid.json", "r");
    get_lex(file,tokens,"{}");
    return 0;
}
int step_two() {
    return 0;
}
int step_three() {
    return 0;
}
int step_four() {
    return 0;
}
void get_lex(FILE* file,char* tokens,const char *expected_tokens) {
    int return_code = lex(file,tokens);
    CU_ASSERT_EQUAL(return_code,0);
    CU_ASSERT_STRING_EQUAL(tokens[0],expected_tokens);
}
void get_syntax(char* tokens,const char* json) {
    int return_code = syntax(tokens);
    CU_ASSERT_EQUAL(return_code,0);
    CU_ASSERT_STRING_EQUAL(tokens[0],json);
}

int main(int argc, char *argv[]) {
    CU_pSuite pSuite = NULL;
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }
    pSuite = CU_add_suite("Suite_1",NULL,NULL);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (CU_add_test(pSuite,"step_one",step_one) == NULL ||
        CU_add_test(pSuite,"step_two",step_two) == NULL ||
        CU_add_test(pSuite,"step_three",step_three) == NULL ||
        CU_add_test(pSuite,"step_four",step_four) == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}