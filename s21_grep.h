//
// Created by Daniil Kolesnik on 19/11/2022.
//

#ifndef GREP_S21_GREP_H
#define GREP_S21_GREP_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct options {
    int e; // поиск записи по шаблону
    int i; // perform case insensetive matching
    int v; // выбрать записи, которые не совпадают с шаблоном
    int c; // вывести количество записей, которые подходят под описание
    int l; // вывести только имена файлов, в которых было совпадение с шаблоном
    int n; // вывести только номер записи, в которой было совпадение

    int h; // не выводить имя файла
    int s; // if error, keep working silently
    int f; // брать шаблоны из файла
    int o; // выводит только сами совпадения


};

char **create_array_of_arrays();
char **parse(int argc, char **argv, struct options *MANAGER);
int reader(struct options *MANAGER, char** pattern, char *filename);

#endif //GREP_S21_GREP_H
