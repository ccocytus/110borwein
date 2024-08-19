#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my.h"

#define EPSILON 1e-6

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(errors_few_args, exit_code, .init=redirect_all_stdout)
{
    int ac = 1;
    char *av[1] = {"./110borwein"};

    int result = run_program(ac, av);
    cr_assert_eq(84, result);
}

Test(errors_too_many_args, exit_code, .init=redirect_all_stdout)
{
    int ac = 3;
    char *av[] = {"./110borwein", "2", "extra"};

    int result = run_program(ac, av);
    cr_assert_eq(84, result);
}

Test(errors_wrong_args, exit_code, .init=redirect_all_stdout)
{
    int ac = 2;
    char *av[] = {"./110borwein", "aaaa"};

    int result = run_program(ac, av);
    cr_assert_eq(84, result);
}

Test(errors_negative_number, exit_code, .init=redirect_all_stdout)
{
    int ac = 2;
    char *av[] = {"./110borwein", "-1"};

    int result = run_program(ac, av);
    cr_assert_eq(84, result);
}

Test(errors_large_number, exit_code, .init=redirect_all_stdout)
{
    int ac = 2;
    char *av[] = {"./110borwein", "5001"};

    int result = run_program(ac, av);
    cr_assert_eq(84, result);
}

Test(midpoint_rule_test, result_for_n0, .init = redirect_all_stdout)
{
    int n = 0;
    double result = midpoint_rule(n);

    cr_assert_float_eq(result, 1.5707651076, EPSILON, "Le résultat de Midpoint avec n = 0 n'est pas correct");
}

Test(trapezoidal_rule_test, result_for_n0, .init = redirect_all_stdout)
{
    int n = 0;
    double result = trapezoidal_rule(n);

    cr_assert_float_eq(result, 1.5707660806, EPSILON, "Le résultat de Trapezoidal avec n = 0 n'est pas correct");
}

Test(simpson_rule_test, result_for_n0, .init = redirect_all_stdout)
{
    int n = 0;
    double result = simpson_rule(n);

    cr_assert_float_eq(result, 1.5707654320, EPSILON, "Le résultat de Simpson avec n = 0 n'est pas correct");
}
