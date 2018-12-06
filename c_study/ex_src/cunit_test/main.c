#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/Console.h"

#include "score.h"

#include <stdio.h>

int main(void)
{
	CU_pSuite pSuite = NULL;
	CU_initialize_registry();

	pSuite = CU_add_suite("score_test_suit", init_suite, clean_suite);

	CU_add_test(pSuite, "score_test_1", score_test_1);
	CU_add_test(pSuite, "score_test_2", score_test_2);


	CU_console_run_tests();

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	printf("\n");
	CU_basic_show_failures(CU_get_failure_list());
	printf("\n\n");

	return 0;
}
