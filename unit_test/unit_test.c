#include <stdio.h>
#include "../color_print/color_print.h"

int testCount = 1;

void unit_test_describe_section(char *sectionName)
{
    printf("\nTesting: %s\n", sectionName);
    testCount = 1;
}

void unit_test_assert_int(char *testName, int a, int b)
{
    printf("    %d. %s: ", testCount, testName);
    if (a == b)
    {
        color_print_green("[pass]\n");
    }
    else
    {
        color_print_red("[fail]\n");
    }

    testCount++;
}