TEST = DEV

test: test_unit_test test_math_utils test_statement

test_unit_test: test_unit_test.c unit_test.c unit_test.h
	gcc -D$(TEST) test_unit_test.c unit_test.c -o test_unit_test.bin.test
	./test_unit_test.bin.test

test_math_utils: test_math_utils.c ../math_utils.c ../math_utils.h unit_test.c unit_test.h
	gcc -D$(TEST) test_math_utils.c ../math_utils.c unit_test.c -o test_math_utils.bin.test
	./test_math_utils.bin.test

test_statement: test_statement.c ../statement.c ../statement.h ../math_utils.c ../math_utils.h unit_test.c unit_test.h
	gcc -D$(TEST) test_statement.c ../statement.c ../math_utils.c unit_test.c -o test_statement.bin.test
	./test_statement.bin.test

.PHONY: clean

clean:
	rm -f *.bin.test a.out
