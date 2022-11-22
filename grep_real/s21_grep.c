
#include "s21_grep.h"

/*
 * TODO: debug count files
 * */


void parse_flags(int argc, char **argv, struct options *MANAGER) {
    int c;
    char *optstring = "eivclnhsfo";
    while ((c = getopt(argc, argv, optstring)) != -1) {
        switch (c) {
            case 'e':
                MANAGER->e = 1;
                break;
            case 'i':
                MANAGER->i = 1;
                break;
            case 'v':
                MANAGER->v = 1;
                break;
            case 'c':
                MANAGER->c = 1;
                break;
            case 'l':
                MANAGER->l = 1;
                break;
            case 'n':
                MANAGER->n = 1;
                break;
            case 'h':
                MANAGER->h = 1;
                break;
            case 's':
                MANAGER->s = 1;
                break;
            case 'f':
                MANAGER->f = 1;
                break;
            case 'o':
                MANAGER->o = 1;
                break;
            default:
                abort();
        }
    }
}

int file_indicator(char *arg) {
    int r_comp;
    int return_value = -1;
    regex_t regex;
    r_comp = regcomp(&regex, ".txt", 0);
    return_value = regexec(&regex, arg, 0, NULL, 0);
    return return_value; // returns 0 if .txt was found
}

int countfiles(int argc, char **argv) {
    int total = 0;
    for (int i = 0; i < argc; ++i) {
        char *current = argv[i];
        if (file_indicator(current) == 0)
    }
}

char **parse_files(int argc, char **argv, struct options *MANAGER) { // PARSE THESE WITH REGEX
    parse_flags(argc, argv, MANAGER);

    char **filenames;
    int file_i = 0;
    int count_files;

    int count_options = 0;
    int regex_index = 0;

    for (int i = 1; i < argc - 1; ++i) {
        if (argv[i][0] == '-') {
            count_options++;
            continue;
        }
        if (argv[i][0] == 39) {
            int len = strlen(argv[i]);
            if (argv[i][len - 1] == 39) {
                regex_index = i;
                continue;
            }
        }

        if (file_indicator(argv[i]) == 0) {
            char *to_put_in_array = argv[i];
            filenames[file_i] = argv[i];
            file_i++;
        }
    }


    return 0;
}


int main(int argc, char **argv) {

//
//    for (int i = 0; i < argc; ++i) {
//        printf("%d %s\n", i, argv[i]);
//    }

//    regex_t regex;
//    int return_value,
//    return_value1, return_value2;
//    return_value = regcomp(&regex,"ice",0);
//    return_value1 = regexec(&regex,"icecream",0,NULL,0);
//    return_value2 = regexec(&regex,"anotherstring",0,NULL,0);
//
//    printf("%d\n%d",return_value1, return_value2);
//
//    int t = 7;




    char inp[1000] = "a.out -e -i -v -c -l -n -h -s -f -o 'reg_ex' test1.txt test2.txt test3.txt";
    const char d[2] = " ";
    char **my_argv = malloc(sizeof(char *) * 20);
    int my_argc = 0;

    char *token;
    token = strtok(inp, d);
    int i = 0;
    while (token != NULL) {
        my_argv[i] = malloc(sizeof(char) * 100);
        my_argv[i] = token;
        printf("%d  %s\n", i, my_argv[i]); // THIS LINE PRINTS THE CONTENTS OF ARGV
        token = strtok(NULL, d);
        i++;
        my_argc = i;
    }


    struct options MANAGER;  // структура, которая отвечает за опции
    char **files;
    files = parse_files(my_argc, my_argv, &MANAGER); // функция, которая парсит командную строку и
    // возвращает массив с названиями файлов
    int t = 4;





//    char *pattern= argv[optind]; // записать шаблон, по которому будем искать записи
//    while (optind < argc) {  // пока не дойдём до конца команды
//        reader(&MANAGER, &pattern, argv[optind]);  // будем выводить символы, отвечающие критериям КАКИМ?
//        optind++;  // плюс индекс optind
//    }
}