
#include "s21_grep.h"

/*
 * Function parse_flags misbehaves when encounters -eeeeeee
 *
 * */


char **get2dAR(int entries) {
    char **result = malloc(sizeof(char *) * entries);
    for (int i = 0; i < entries; ++i) {
        result[i] = malloc(sizeof(char) * 50);
    }
    return result;
}

int file_indicator(char *arg) {
    int r_comp;
    int return_value = -1;
    regex_t regex;
    r_comp = regcomp(&regex, ".txt", 0);
    return_value = regexec(&regex, arg, 0, NULL, 0);
    return return_value; // returns 0 if .txt was found in arg
}


int countfiles(int argc, char **argv) {
    int total = 0;
    for (int i = 0; i < argc; ++i) {
        char *current = argv[i];
        if (file_indicator(current) == 0) {
            total++;
        }
    }
    return total;
}

int e_indicator(char *arg) {
    int r_comp1;
    int r_comp2;
    int return_value = -1;
    regex_t regex;
    r_comp1 = regcomp(&regex, "-e", 0);

    return_value = regexec(&regex, arg, 0, NULL, 0);
    return return_value; // returns 0 if '/" was found in arg
}

int count_e(int argc, char **argv) {  //
    int total = 0;
    for (int i = 0; i < argc; ++i) {
        char *current = argv[i];
        if (e_indicator(argv[i]) == 0) {
            total++;
        }
    }
    return total;
}


void parse_flags(int argc, char **argv, struct options *MANAGER) {
    int c;
    int e_count = 0;
    char *optstring = "eivclnhsfo";
    while ((c = getopt(argc, argv, optstring)) != -1) {
        switch (c) {
            case 'e':
                e_count++;
                MANAGER->e = e_count;
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


char **parse_regex(int argc, char **argv) {

    char *pattern;

    char *current;
    for (int i = 0; i < argc; ++i) {
        current = argv[i];
        int len_cur = strlen(current);
        if ((current[0] == current[len_cur - 1]) && (current[0] == 39)) {
            pattern = current;
            return pattern;
        }
    }
    exit(1); // pattern not found
}

char **parse_files(int argc, char **argv) { // PARSE THESE WITH REGEX


    int n_files = 0;
    n_files = countfiles(argc, argv);

    char **filenames = get2dAR(n_files);
    int file_i = 0;


    int count_options = 0;
    int regex_number = 0;

    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            count_options++;
            continue;
        }
        if (argv[i][0] == 39) {
            int len = strlen(argv[i]);
            if (argv[i][len - 1] == 39) {
                regex_number = i;
                continue;
            }
        }
        char *current = argv[i];
        if (file_indicator(current) == 0) {
            char *to_put_in_array = argv[i];
            filenames[file_i] = argv[i];
            file_i++;
        }
    }


    return filenames;
}




char **tokenize(int argc, char **argv, struct options MANAGER) {
    if (MANAGER.e == 0) {
        return 0;
    }
    int n_regex = count_e(argc, argv);  // посчитали сколько будет блоков
    struct block grouped[n_regex];  // создали вместилище для блоков

    int i = 0;
    int block_write = 0;
    while (1) {
        if (i >= argc)
            break;
        char* buf;
        if ((argv[i] == "-e")&&(block_write == 0)) {
            block_write = 1;

        }
    }

}

int main(int argc, char **argv) {
    char inp[1000] = "a.out -e -i -v -c -l -n -h -s -f -o 'regex1' test1.txt -e 'regex2' test2.txt -e 'regex3' test3.txt";
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
    //    char **file_names = create_array_of_arrays();

    parse_flags(my_argc, my_argv,
          &MANAGER); // функция, которая парсит командную строку и возвращает массив с названиями файлов
    tokenize(my_argc,my_argv,MANAGER);
          //    char *pattern= argv[optind]; // записать шаблон, по которому будем искать записи
          //    while (optind < argc) {  // пока не дойдём до конца команды
          //        reader(&MANAGER, &pattern, argv[optind]);  // будем выводить символы, отвечающие критериям КАКИМ?
          //        optind++;  // плюс индекс optind
          //    }


    return 0;
}
