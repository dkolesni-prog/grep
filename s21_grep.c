
#include "s21_grep.h"

char **create_array_of_arrays() {

}

char **parse(int argc, char **argv, struct options *MANAGER) {

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


    return 0;
}

// -e,
//-i,
//-v,
//-c,
//-l,
//-n

int main(int argc, char **argv) {

    char inp[1000] = "a.out -e -i -v -c -l -n -h -s -f -o 'reg_ex' test1.txt";
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
    parse(my_argc, my_argv,
          &MANAGER); // функция, которая парсит командную строку и возвращает массив с названиями файлов


//    char *pattern= argv[optind]; // записать шаблон, по которому будем искать записи
//    while (optind < argc) {  // пока не дойдём до конца команды
//        reader(&MANAGER, &pattern, argv[optind]);  // будем выводить символы, отвечающие критериям КАКИМ?
//        optind++;  // плюс индекс optind
//    }
}