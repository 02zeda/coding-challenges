#include "../include/wc_challenge.h"
#define C_OPTION 1
#define L_OPTION 2
#define W_OPTION 3
#define M_OPTION 4
#define DEFAULT_OPTION 5
int main(int argc, char *argv[]) {

    int  results[3];
    int number_of_results;
    int option;
    int c_option =0;
    while((option=getopt(argc,argv,"clwm")) != -1){
        switch (option)
        {
        case 'c':
            c_option=C_OPTION;
            break;

        case 'l':
            c_option=L_OPTION;
            break;
        case 'w':
            c_option=W_OPTION;
            break;
        case 'm':
            c_option=M_OPTION;
            break;
        default:
            break;
        }
    }
    if (optind == 1)
        c_option = DEFAULT_OPTION;
    if (optind == argc) {
        number_of_results = wc(NULL,c_option,results);
        for (int j=0; j<number_of_results; j++){
            printf("%d\t",results[j]);
        }
        printf("\n");
    }
    for (int i=optind; i< argc; i++) {
        //printf("File: %s\n", argv[i]);
        number_of_results = wc(argv[i],c_option,results);
        for (int j=0; j<number_of_results; j++){
            printf("%d\t",results[j]);
        }
       printf("%s\n",argv[i]);
    }

    return 0;
}
int wc(char *filename,int option,int *results) {
    FILE *file;
    if (filename != NULL) {
        file = fopen(filename, "r");

    }
    else
        file = stdin;
    if (file == NULL) {
            printf("File not found\n");
            return 1;
        }
    int number_of_results = 1;
    int result = 0;
    if (option==1){
        result = count_chars(file);
        results[0] = result;
    }
    else if (option==2){
        result = count_lines(file);
        results[0] = result;
    }
    else if (option==3) {
        result = count_words(file);
        results[0] = result;
    }
    else if (option==4) {
        result = count_multibyte_chars(file);
        results[0] = result;
    }
    else if (option==5){
        count_default(file,results);
        number_of_results = 3;
    }
    return number_of_results;
}
int count_chars(FILE *file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}
int count_lines(FILE *file) {
    int result =0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            result++;
        }
    }
    fclose(file);
    return result;

}
int count_words(FILE *file){
    int result=0;
    char c;
    int in_word = 0;
    while (((c = fgetc(file)) != EOF)){
      if(isspace(c))
        in_word = 0;
      else if (!in_word){
            in_word = 1;
            result++;
        }
    }
    fclose(file);
    return result;
}
int count_multibyte_chars(FILE *file){
    setlocale(LC_ALL, "");
    int result=0;
    wchar_t c;
    while ((c = fgetwc(file) ) != WEOF)
    {
        result++;
    }
    fclose(file);
    return result;
}
int count_default(FILE *file,int *results){
    int chars,lines,words;
    chars = lines = words = 0;
    int c;
    int in_word = 0;
    while((c = fgetc(file)) != EOF){
        chars++;
        if (c == '\n')
            lines++;
        if(isspace(c))
            in_word = 0;
      else if (!in_word){
            in_word = 1;
            words++;
        }
    }
    results[0] = lines;
    results[1] = words;
    results[2] = chars;
    return 0;
}