#ifndef WC_H
#define WC_H
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>
int main(int argc, char *argv[]);
int wc(char *filename,int option,int *result);
int count_lines(FILE *file);
int count_words(FILE *file);
int count_chars(FILE *file);
int count_multibyte_chars(FILE *file);
int count_default(FILE *file,int *results);
#endif // WC_H
