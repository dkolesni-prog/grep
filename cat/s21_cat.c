//
// Created by Zienya Sharilyn on 10/27/22.
//
#include "s21_cat.h"

int empty(struct options MAN) {
    if (MAN.b + MAN.e + MAN.n + MAN.s + MAN.t == 0) {
        return 1;
    }
    return 0;
}

struct options constructor(int argc, char **argv) {
    struct options Ret;
    Ret.b = 0;
    Ret.e = 0;
    Ret.n = 0;
    Ret.s = 0;
    Ret.t = 0;
    Ret.v = 0;
    Ret.E = 0;
    Ret.T = 0;
    int opt = 0;
    int opt_ind = 0;
    const struct option for_long[] = {{"number",          0, NULL, 'n'},
                                      {"number-nonblank", 0, NULL, 'b'},
                                      {"squeeze-blank",   0, NULL, 's'},
                                      {NULL,              0, NULL, 0}};


    while ((opt = getopt_long(argc, argv, "+vbenstET", for_long, &opt_ind)) !=
           -1) {
        switch (opt) { //vbenstET?

            case 'v':
                Ret.v = 1;
                break;

            case 'b':
                Ret.b = 1;
                break;

            case 'e':
                Ret.e = 1;
                Ret.v = 1;
                break;

            case 'n':
                Ret.n = 1;
                break;

            case 's':
                Ret.s = 1;
                break;

            case 't':
                Ret.t = 1;
                Ret.v = 1;
                break;

            case 'E':
                Ret.E = 1;
                Ret.v = 0;
                break;

            case 'T':
                Ret.T = 1;
                Ret.v = 0;
                break;

            default:
                printf("Usage s21_cat [-b -e -n -s -t] <filename>");
                exit(1);


        }
    }

    return Ret;
}


void print_ch(FILE *fp, struct options MANAGER) {


    char break_line = '\n';
    char current;
    int strCount = 0;
    int counter = 1;


    while ((current = fgetc(fp)) != EOF) {
        if (MANAGER.s && break_line == '\n' && current == '\n') {
            strCount++;
            if (strCount > 1) {
                continue;
            }
        }

        if ((MANAGER.n && break_line == '\n' && !MANAGER.b) ||
            ((MANAGER.b) && break_line == '\n' && current != '\n')) {
            printf("%6d\t", counter++);
        }

        if (MANAGER.e == 1 && current == '\n') {
            printf("$");
        }

        if (MANAGER.t && current == '\t') {
            printf("^");
            current = 'I';
        }

        if (MANAGER.v && !(current >= 32 && current < 127) && current != '\n' &&
            current != '\t') {
            if (current == 127) {
                printf("^");
                current -= 64;
            } else if (current < 32 && current >= 0) {
                printf("^");
                current += 64;
            }
        }

        if (break_line == '\n' && current != '\n') {
            strCount = 0;
        }
        break_line = current;
        printf("%c", current);
    }


}


int main(int argc, char **argv) {

    char inp[1000] = "a.out -s /Users/daniilkolesnik/Desktop/origin/School21/cat/requirements.txt";
    const char d[2] = " ";

    char **my_argv = malloc(sizeof(char *) * 20);
    int my_argc = 0;

    char *token;
    token = strtok(inp, d);

    int i = 0;
    while (token != NULL) {
        my_argv[i] = malloc(sizeof(char) * 100);
        my_argv[i] = token;
        //        printf("%d  %s\n", i, my_argv[i]); // THIS LINE PRINTS THE CONTENTS OF ARGV

        token = strtok(NULL, d);
        i++;
        my_argc = i;
    }

    FILE *fp = fopen(my_argv[my_argc - 1], "rb");
    if (fp != NULL) {
        struct options MAN;
        MAN = constructor(my_argc, my_argv);


        print_ch(fp, MAN);
        fclose(fp);
    }


//    FILE *fp = fopen(argv[argc - 1], "rb");
//    if (fp != NULL) {
//        struct options MAN;
//        MAN = constructor(argc, argv);
//        print_ch(fp, MAN);
//        fclose(fp);
//    } else {
//        printf("No such file or directory");
//        exit(1);
//    }

    return 0;
}
