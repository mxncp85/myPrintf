/*
** EPITECH PROJECT, 2022
** B-CPE-101-NAN-1-1-myprintf-maxence.perronie
** File description:
** Test my printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void my_printf(char const *format, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Random tests
Test(my_printf, spacing_field_width_and_prec, .init = redirect_all_std)
{
    my_printf("Hello %' '3.3f", 5.33);
    cr_assert_stdout_eq_str("Hello  5.330");
}

Test(my_printf, zero_and_prec, .init = redirect_all_std)
{
    my_printf("Hello %05.3d", 5);
    cr_assert_stdout_eq_str("Hello   005");
}

Test(my_printf, possible_failure1, .init = redirect_all_std)
{
    my_printf("Hello %' '10d", 5);
    cr_assert_stdout_eq_str("Hello          5");
}

Test(my_printf, possible_failure2, .init = redirect_all_std)
{
    my_printf("Hello %#+010d", 5);
    cr_assert_stdout_eq_str("Hello +000000005");
}

Test(my_printf, possible_failure3, .init = redirect_all_std)
{
    my_printf("Hello %#+010.4d", 5);
    cr_assert_stdout_eq_str("Hello      +0005");
}

Test(my_printf, possible_failure4, .init = redirect_all_std)
{
    my_printf("Hello %#-+010d", 5);
    cr_assert_stdout_eq_str("Hello +5        ");
}

Test(my_printf, possible_failure5, .init = redirect_all_std)
{
    my_printf("Hello %#011.2e", 5.3);
    cr_assert_stdout_eq_str("Hello 0005.30e+00");
}

Test(my_printf, possible_failure6, .init = redirect_all_std)
{
    my_printf("Hello %#011.2d", 5);
    cr_assert_stdout_eq_str("Hello          05");
}

// e flag tests
// ------------------------------------

Test(my_printf, e_flag_basic1, .init = redirect_all_std)
{
    my_printf("%e", 5.3);
    cr_assert_stdout_eq_str("5.300000e+00");
}

Test(my_printf, e_flag_basic2, .init = redirect_all_std)
{
    my_printf("%e", 5.344);
    cr_assert_stdout_eq_str("5.344000e+00");
}

Test(my_printf, e_flag_basic3, .init = redirect_all_std)
{
    my_printf("%.2e", 5.344);
    cr_assert_stdout_eq_str("5.34e+00");
}

Test(my_printf, e_flag_basic4, .init = redirect_all_std)
{
    my_printf("%.2e", 5.345);
    cr_assert_stdout_eq_str("5.34e+00");
}

Test(my_printf, e_flag_basic5, .init = redirect_all_std)
{
    my_printf("%.2e", 5.346);
    cr_assert_stdout_eq_str("5.35e+00");
}

Test(my_printf, e_flag_basic6, .init = redirect_all_std)
{
    my_printf("%.0e", 5.5);
    cr_assert_stdout_eq_str("6e+00");
}

Test(my_printf, e_flag_basic7, .init = redirect_all_std)
{
    my_printf("%.0e", 5.5);
    cr_assert_stdout_eq_str("6e+00");
}

Test(my_printf, e_flag_basic8, .init = redirect_all_std)
{
    my_printf("%.0e", 5.4);
    cr_assert_stdout_eq_str("5e+00");
}

Test(my_printf, e_flag_basic9, .init = redirect_all_std)
{
    my_printf("%.0e", 5.45);
    cr_assert_stdout_eq_str("5e+00");
}

Test(my_printf, e_flag_basic10, .init = redirect_all_std)
{
    my_printf("%.1e", 5.455);
    cr_assert_stdout_eq_str("5.5e+00");
}

Test(my_printf, e_flag_basic11, .init = redirect_all_std)
{
    my_printf("%.3e", 533.455);
    cr_assert_stdout_eq_str("5.335e+02");
}

Test(my_printf, e_flag_basic12, .init = redirect_all_std)
{
    my_printf("%.6e", 5.4555554);
    cr_assert_stdout_eq_str("5.455555e+00");
}


Test(my_printf, e_flag_basic13, .init = redirect_all_std)
{
    my_printf("%10.3e", 0);
    cr_assert_stdout_eq_str(" 0.000e+00");
}


Test(my_printf, space_flag, .init = redirect_all_std)
{
    my_printf("%' '7.4d", 4);
    cr_assert_stdout_eq_str("   0004");
}

Test(my_printf, field_width_test1, .init = redirect_all_std)
{
    my_printf("%10.2c", 'c');
    cr_assert_stdout_eq_str("         c");
}

Test(my_printf, field_width_test2, .init = redirect_all_std)
{
    my_printf("%-10.2c", 'c');
    cr_assert_stdout_eq_str("c         ");
}

Test(my_printf, field_width_test3, .init = redirect_all_std)
{
    my_printf("%10.2d", 34);
    cr_assert_stdout_eq_str("        34");
}

Test(my_printf, field_width_test4, .init = redirect_all_std)
{
    my_printf("%-10.2d", 34);
    cr_assert_stdout_eq_str("34        ");
}

Test(my_printf, field_width_test5, .init = redirect_all_std)
{
    my_printf("%-10.4d", 34);
    cr_assert_stdout_eq_str("0034      ");
}

Test(my_printf, field_width_test52, .init = redirect_all_std)
{
    my_printf("%10.4d", 34);
    cr_assert_stdout_eq_str("      0034");
}

Test(my_printf, field_width_test6, .init = redirect_all_std)
{
    my_printf("%10.4o", 34);
    cr_assert_stdout_eq_str("      0042");
}

Test(my_printf, field_width_test7, .init = redirect_all_std)
{
    my_printf("%-10.4o", 34);
    cr_assert_stdout_eq_str("0042      ");
}

Test(my_printf, field_width_test8, .init = redirect_all_std)
{
    my_printf("%10.4X", 10);
    cr_assert_stdout_eq_str("      000A");
}

Test(my_printf, field_width_test9, .init = redirect_all_std)
{
    my_printf("%10.4x", 10);
    cr_assert_stdout_eq_str("      000a");
}

Test(my_printf, field_width_test10, .init = redirect_all_std)
{
    my_printf("%10.4x", 10);
    cr_assert_stdout_eq_str("      000a");
}

Test(my_printf, field_width_test11, .init = redirect_all_std)
{
    my_printf("%10.4x", 10);
    cr_assert_stdout_eq_str("      000a");
}

Test(my_printf, field_width_test12, .init = redirect_all_std)
{
    my_printf("%20.0e", 2.3);
    cr_assert_stdout_eq_str("               2e+00");
}

Test(my_printf, field_width_test13, .init = redirect_all_std)
{
    my_printf("%#20.0e", 2.3);
    cr_assert_stdout_eq_str("              2.e+00");
}

Test(my_printf, field_width_test14, .init = redirect_all_std)
{
    my_printf("%#20.4e", 2.3);
    cr_assert_stdout_eq_str("          2.3000e+00");
}

Test(my_printf, field_width_test15, .init = redirect_all_std)
{
    my_printf("%-010.4d", 2);
    cr_assert_stdout_eq_str("0002      ");
}

Test(my_printf, zero_test1, .init = redirect_all_std)
{
    my_printf("%010.4x", 10);
    cr_assert_stdout_eq_str("      000a");
}

Test(my_printf, zero_test2, .init = redirect_all_std)
{
    my_printf("%010x", 10);
    cr_assert_stdout_eq_str("000000000a");
}


Test(my_printf, zero_test3, .init = redirect_all_std)
{
    my_printf("%-010x", 10);
    cr_assert_stdout_eq_str("a         ");
}

Test(my_printf, blank_test1, .init = redirect_all_std)
{
    my_printf("%' '#.3x", 4);
    cr_assert_stdout_eq_str("0x004");
}


Test(my_printf, blank_test2, .init = redirect_all_std)
{
    my_printf("%' '#.3d", 4);
    cr_assert_stdout_eq_str(" 004");
}

Test(my_printf, blank_test3, .init = redirect_all_std)
{
    my_printf("%-' '23d", 10);
    cr_assert_stdout_eq_str(" 10                    ");
}


Test(my_printf, diez_test1, .init = redirect_all_std)
{
    my_printf("%-#10.3x", 4);
    cr_assert_stdout_eq_str("0x004     ");
}

Test(my_printf, diez_test3, .init = redirect_all_std)
{
    my_printf("%#10x", 4);
    cr_assert_stdout_eq_str("       0x4");
}

Test(my_printf, diez_test4, .init = redirect_all_std)
{
    my_printf("%#2x", 4);
    cr_assert_stdout_eq_str("0x4");
}

Test(my_printf, plus_test1, .init = redirect_all_std)
{
    my_printf("Hello %#-+010d", 5);
    cr_assert_stdout_eq_str("Hello +5        ");
}

Test(my_printf, plus_test2, .init = redirect_all_std)
{
    my_printf("Hello %+010d", 5);
    cr_assert_stdout_eq_str("Hello +000000005");
}

Test(my_printf, plus_test3, .init = redirect_all_std)
{
    my_printf("Hello %+10d", 5);
    cr_assert_stdout_eq_str("Hello         +5");
}

Test(my_printf, plus_test4, .init = redirect_all_std)
{
    my_printf("Hello %+010.3d", 5);
    cr_assert_stdout_eq_str("Hello       +005");
}

Test(my_printf, plus_test5, .init = redirect_all_std)
{
    my_printf("Hello %+-010.3d", 5);
    cr_assert_stdout_eq_str("Hello +005      ");
}

Test(my_printf, percentage_flg1, .init = redirect_all_std)
{
    my_printf("Hello %+-010%", 5);
    cr_assert_stdout_eq_str("Hello %");
}

Test(my_printf, percentage_flg2, .init = redirect_all_std)
{
    my_printf("Hello %%", 5);
    cr_assert_stdout_eq_str("Hello %");
}