/*
** EPITECH PROJECT, 2024
** main
** File description:
** display
*/

#include "../my.h"

static int printf_error(void)
{
    printf("Invalid argument -h for help\n");
    return 84;
}

static void print_result(int n, double result)
{
    double diff = fabs(result - M_PI / 2);

    printf("I%d = %.10f\n", n, result);
    printf("diff = %.10f\n", diff);
}

static int check_error(int ac, char **av)
{
    int is_digit = 1;

    if (ac != 2)
        return printf_error();
    for (int i = 0; av[1][i] != '\0'; i++)
        if (!isdigit(av[1][i])) {
            is_digit = 0;
            break;
        }
    if (!is_digit)
        return printf_error();
    if (atoi(av[1]) > 5000)
        return printf_error();
    return atoi(av[1]);
}

int run_program(int ac, char **av)
{
    int n = 0;
    double result = 0.0;
    double diff = 0.0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return display();
    n = check_error(ac, av);
    if (n == 84)
        return 84;
    result = midpoint_rule(n);
    diff = fabs(result - M_PI / 2);
    printf("Midpoint:\n");
    print_result(n, result);
    result = trapezoidal_rule(n);
    printf("\nTrapezoidal:\n");
    print_result(n, result);
    result = simpson_rule(n);
    printf("\nSimpson:\n");
    print_result(n, result);
    return 0;
}

double borwein_product(double x, int n)
{
    double product = 1.0;
    double res;

    if (x == 0)
        return 1.0;
    for (int k = 0; k <= n; k++) {
        res = x / (2 * k + 1);
        product *= sin(res) / res;
    }
    return product;
}

double midpoint_rule(int n)
{
    double delta_x = (double)INTERVAL_END / NUM_SUBINTERVALS;
    double sum = 0.0;
    double mid;

    for (int i = 0; i < NUM_SUBINTERVALS; i++) {
        mid = (i + 0.5) * delta_x;
        sum += borwein_product(mid, n);
    }
    return sum * delta_x;
}

double trapezoidal_rule(int n)
{
    double delta_x = (double)INTERVAL_END / NUM_SUBINTERVALS;
    double sum = borwein_product(0, n) + borwein_product(INTERVAL_END, n);
    double x;

    for (int i = 1; i < NUM_SUBINTERVALS; i++) {
        x = i * delta_x;
        sum += 2 * borwein_product(x, n);
    }
    return sum * delta_x / 2;
}

double simpson_rule(int n)
{
    double delta_x = (double)INTERVAL_END / (NUM_SUBINTERVALS * 2);
    double sum = borwein_product(0, n) + borwein_product(INTERVAL_END, n);
    double x;

    for (int i = 1; i < (NUM_SUBINTERVALS * 2); i += 2) {
        x = i * delta_x;
        sum += 4 * borwein_product(x, n);
    }
    for (int i = 2; i < (NUM_SUBINTERVALS * 2) - 1; i += 2) {
        x = i * delta_x;
        sum += 2 * borwein_product(x, n);
    }
    return sum * delta_x / 3.0;
}
