/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** display
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <math.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <ctype.h>

int run_program(int ac, char **av);
double borwein_product(double x, int n);
double midpoint_rule(int n);
double trapezoidal_rule(int n);
double simpson_rule(int n);
int display(void);

    #define INTERVAL_END 5000
    #define NUM_SUBINTERVALS 10000
    #define M_PI 3.14159265358979323846
#endif
