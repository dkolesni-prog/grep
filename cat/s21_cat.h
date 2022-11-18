//
// Created by Daniil Kolesnik on 15/11/2022.
//

#ifndef CAT_S21_CAT_H
#define CAT_S21_CAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>



struct options {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
    int E;
    int T;

};

int empty(struct options MAN);

struct options constructor(int argc, char **argv);


void print_ch(FILE *fp, struct options MANAGER);

#endif //CAT_S21_CAT_H
