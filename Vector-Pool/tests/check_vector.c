#include <check.h>

#ifndef STDLIB_H
    #define STDLIB_H
    #include <stdlib.h>
#endif

#ifndef TYPES_H
    #define TYPES_H
    #include "../src/types.h"
#endif

#ifndef VECFUNC_H
    #define VECFUNC_H
    #include "../src/vecfunc.h"
#endif

/*
    Equality comparisions for double types are not exact, and hence we say that to be equal 
    they need to be close to each other in value within some tolerance limit, this value varies according
    to the task at hand. As I want the values to match until the 6th decimal exactly, I have set the 
    tolerance to 5e-7.
    E.g.:
    ------
    If the decimal part of a certain value is:
    .abcdefx
     '----'^---> This decimal digit is allowed to vary within (x + 5) to (x - 5)
        |
        v
    The digits at these decimal places must match exactly
*/
#define TOLERANCE 5e-7F


/*
    Run the program for the first example test case:
	Input:
        7   ---> Size of the vector
        6   ---> Window Size
        1.0 --
        2.0  |
        3.0  |
        4.0  | -----> These are the vector elements
        5.0  |
        6.0  |
        7.0 --

    Output: 3.50 7.00 
*/
START_TEST(test_case_one) {
    extern Vector createVector(int arg_count);

    const int VECTOR_SIZE = 7;
    const int WINDOW_SIZE = 6;

    double vecElements[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    double pooledVecElements[] = {3.50, 7.0};  // Expected answer after pooling operation

    Vector vec = createVector(VECTOR_SIZE);

    // Addition of elements to the vector must return true
    for(int i = 0; i < VECTOR_SIZE; ++i)
        ck_assert(appendElement(&vec, vecElements[i]));
    
    Vector pooledVec = poolVector(vec, WINDOW_SIZE);

    // Check if the pooledVec contains the correct elements
    int numberOfPooledElements = (int)ceil((double)VECTOR_SIZE / WINDOW_SIZE);
    for(int  i = 0; i < numberOfPooledElements; ++i) {
        ck_assert_double_eq_tol(pooledVec.head[i].data, pooledVecElements[i], TOLERANCE);
    }

    // Destroying the vector must return true
    ck_assert(destoryVector(&pooledVec));
    ck_assert(destoryVector(&vec));

    ck_assert_ptr_eq(pooledVec.head, NULL);
    ck_assert_int_eq(pooledVec.length, 0);
    ck_assert_int_eq(pooledVec.lengthOccupied, 0);

    ck_assert_ptr_eq(vec.head, NULL);
    ck_assert_int_eq(vec.length, 0);
    ck_assert_int_eq(vec.lengthOccupied, 0);
} END_TEST


/*
    Run the program for the second example test case:
	Input:         
        5  ---> Size of the vector
        2  ---> Window Size
        1.0  --
        2.0   |
        3.0   | -----> These are the vector elements
        4.0   |
        5.0  --

    Output: 1.50 3.50 5.00 
*/
START_TEST(test_case_two) {
    extern Vector createVector(int arg_count);

    const int VECTOR_SIZE = 5;
    const int WINDOW_SIZE = 2;

    double vecElements[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double pooledVecElements[] = {1.50, 3.50, 5.0};  // Expected answer after pooling operation

    Vector vec = createVector(VECTOR_SIZE);

    // Addition of elements to the vector must return true
    for(int i = 0; i < VECTOR_SIZE; ++i)
        ck_assert(appendElement(&vec, vecElements[i]));
    
    Vector pooledVec = poolVector(vec, WINDOW_SIZE);

    // Check if the pooledVec contains the correct elements
    int numberOfPooledElements = (int)ceil((double)VECTOR_SIZE / WINDOW_SIZE);
    for(int  i = 0; i < numberOfPooledElements; ++i) {
        ck_assert_double_eq_tol(pooledVec.head[i].data, pooledVecElements[i], TOLERANCE);
    }

    // Destroying the vector must return true
    ck_assert(destoryVector(&pooledVec));
    ck_assert(destoryVector(&vec));

    ck_assert_ptr_eq(pooledVec.head, NULL);
    ck_assert_int_eq(pooledVec.length, 0);
    ck_assert_int_eq(pooledVec.lengthOccupied, 0);

    ck_assert_ptr_eq(vec.head, NULL);
    ck_assert_int_eq(vec.length, 0);
    ck_assert_int_eq(vec.lengthOccupied, 0);
} END_TEST


/*
    Run the program for the third example test case:
	Input:         
        4  ---> Size of the vector
        2  ---> Window Size
        1.0  --
        2.0   |
        3.0   | -----> These are the vector elements
        4.0  --

    Output: 1.50 3.50
*/
START_TEST(test_case_three) {
    extern Vector createVector(int arg_count);

    const int VECTOR_SIZE = 4;
    const int WINDOW_SIZE = 2;

    double vecElements[] = {1.0, 2.0, 3.0, 4.0};
    double pooledVecElements[] = {1.50, 3.50};  // Expected answer after pooling operation

    Vector vec = createVector(VECTOR_SIZE);

    // Addition of elements to the vector must return true
    for(int i = 0; i < VECTOR_SIZE; ++i)
        ck_assert(appendElement(&vec, vecElements[i]));
    
    Vector pooledVec = poolVector(vec, WINDOW_SIZE);

    // Check if the pooledVec contains the correct elements
    int numberOfPooledElements = (int)ceil((double)VECTOR_SIZE / WINDOW_SIZE);
    for(int  i = 0; i < numberOfPooledElements; ++i) {
        ck_assert_double_eq_tol(pooledVec.head[i].data, pooledVecElements[i], TOLERANCE);
    }

    // Destroying the vector must return true
    ck_assert(destoryVector(&pooledVec));
    ck_assert(destoryVector(&vec));

    ck_assert_ptr_eq(pooledVec.head, NULL);
    ck_assert_int_eq(pooledVec.length, 0);
    ck_assert_int_eq(pooledVec.lengthOccupied, 0);

    ck_assert_ptr_eq(vec.head, NULL);
    ck_assert_int_eq(vec.length, 0);
    ck_assert_int_eq(vec.lengthOccupied, 0);
} END_TEST


/*
    Run the program for the fourth example test case:
	Input:         
        10  ---> Size of the vector
        7   ---> Window Size
        4   --
        5    |
        6    |
        3    |
        7    |
        8    |  -----> These are the vector elements
        10   |
        20   |
        3.4  |
        5   --

    Output: 6.142857 9.466667
*/
START_TEST(test_case_four) {
    extern Vector createVector(int arg_count);

    const int VECTOR_SIZE = 10;
    const int WINDOW_SIZE = 7;

    double vecElements[] = {4.0, 5.0, 6.0, 3.0, 7.0, 8.0, 10.0, 20.0, 3.4, 5.0};
    double pooledVecElements[] = {6.142857, 9.466667};  // Expected answer after pooling operation

    Vector vec = createVector(VECTOR_SIZE);

    // Addition of elements to the vector must return true
    for(int i = 0; i < VECTOR_SIZE; ++i)
        ck_assert(appendElement(&vec, vecElements[i]));
    
    Vector pooledVec = poolVector(vec, WINDOW_SIZE);

    // Check if the pooledVec contains the correct elements
    int numberOfPooledElements = (int)ceil((double)VECTOR_SIZE / WINDOW_SIZE);
    for(int  i = 0; i < numberOfPooledElements; ++i) {
        ck_assert_double_eq_tol(pooledVec.head[i].data, pooledVecElements[i], TOLERANCE);
    }

    // Destroying the vector must return true
    ck_assert(destoryVector(&pooledVec));
    ck_assert(destoryVector(&vec));

    ck_assert_ptr_eq(pooledVec.head, NULL);
    ck_assert_int_eq(pooledVec.length, 0);
    ck_assert_int_eq(pooledVec.lengthOccupied, 0);

    ck_assert_ptr_eq(vec.head, NULL);
    ck_assert_int_eq(vec.length, 0);
    ck_assert_int_eq(vec.lengthOccupied, 0);
} END_TEST


/*
    Run the program for the fifth example test case:
	Input:         
        20  ---> Size of the vector
        5   ---> Window Size
        3.5        --
        3.45        |
        7.8         |
        3.456       |
        5.67        |
        10.89       |
        4.567       |
        11.98       |
        101.43      |
        55.678      |   -----> These are the vector elements
        550.432     |
        0.234       |
        108.3498    |
        9.998       |
        6.7842      |
        4.567       |
        29.894      |
        99.9989     |
        56.567      |
        13.3333    --

    Output: 4.775200 36.909000 135.159600 40.872040
*/
START_TEST(test_case_five) {
    extern Vector createVector(int arg_count);

    const int VECTOR_SIZE = 20;
    const int WINDOW_SIZE = 5;

    double vecElements[] = {3.5, 3.45, 7.8, 3.456, 5.67, 10.89, 4.567, 11.98,
                            101.43, 55.678, 550.432, 0.234, 108.3498, 9.998, 6.7842,
                            4.567, 29.894, 99.9989, 56.567, 13.3333};
    double pooledVecElements[] = {4.775200, 36.909000, 135.159600, 40.872040};  // Expected answer after pooling operation

    Vector vec = createVector(VECTOR_SIZE);

    // Addition of elements to the vector must return true
    for(int i = 0; i < VECTOR_SIZE; ++i)
        ck_assert(appendElement(&vec, vecElements[i]));
    
    Vector pooledVec = poolVector(vec, WINDOW_SIZE);

    // Check if the pooledVec contains the correct elements
    int numberOfPooledElements = (int)ceil((double)VECTOR_SIZE / WINDOW_SIZE);
    for(int  i = 0; i < numberOfPooledElements; ++i) {
        ck_assert_double_eq_tol(pooledVec.head[i].data, pooledVecElements[i], TOLERANCE);
    }

    // Destroying the vector must return true
    ck_assert(destoryVector(&pooledVec));
    ck_assert(destoryVector(&vec));

    ck_assert_ptr_eq(pooledVec.head, NULL);
    ck_assert_int_eq(pooledVec.length, 0);
    ck_assert_int_eq(pooledVec.lengthOccupied, 0);

    ck_assert_ptr_eq(vec.head, NULL);
    ck_assert_int_eq(vec.length, 0);
    ck_assert_int_eq(vec.lengthOccupied, 0);
} END_TEST


/*
    Creating a test suite for compiling all the above test functions together for running the tests.
*/
Suite *vector_suite(void) {
    Suite *s = suite_create("vector_lifecycle_test");  // Create a suite for testing
    TCase *tc_fit = tcase_create("Window size fits the vector size");  // Creating a test case to add to the suite
    TCase *tc_no_fit = tcase_create("Window size does not fit the vector size");  // Creating a test case to add to the suite

    tcase_add_test(tc_fit, test_case_three);
    tcase_add_test(tc_fit, test_case_five);

    tcase_add_test(tc_no_fit, test_case_one);
    tcase_add_test(tc_no_fit, test_case_two);
    tcase_add_test(tc_no_fit, test_case_four);

    suite_add_tcase(s, tc_fit);
    suite_add_tcase(s, tc_no_fit);

    return s;
}


int main() {
    int no_failed = 0;                   
    Suite *s;                            
    SRunner *runner;                     

    s = vector_suite();                   
    runner = srunner_create(s);          

    srunner_run_all(runner, CK_NORMAL);  
    no_failed = srunner_ntests_failed(runner); 
    srunner_free(runner);                      
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;  
}