#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

#define NUM_ITERATIONS 10000000

void benchmark_push(Stack* stack, int num_operations, bool print) {
    clock_t start = clock();

    for (int i = 0; i < num_operations; i++) {
        push(stack, i);
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    if (print){
      printf("Time taken for %d push operations: %f seconds\n", num_operations, time_spent);
    }
}

void benchmark_pop(Stack* stack, int num_operations) {
    clock_t start = clock();

    for (int i = 0; i < num_operations; i++) {
        pop(stack);
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken for %d pop operations: %f seconds\n", num_operations, time_spent);
}

int main() {
    Stack stack;
    initStack(&stack);

    printf("Benchmarking push operation:\n");

    for (int i = 1000; i <= NUM_ITERATIONS; i *= 10) {
        benchmark_push(&stack, i, true);

        // Освобождаем стек после каждого теста
        while (!isEmpty(&stack)) {
            pop(&stack);
        }
    }

    // Заполняем стек для тестирования pop
    benchmark_push(&stack, NUM_ITERATIONS, false);

    printf("\nBenchmarking pop operation:\n");

    for (int i = 1000; i <= NUM_ITERATIONS; i *= 10) {
        benchmark_pop(&stack, i);

        // Восстанавливаем стек после каждого теста
        benchmark_push(&stack, i, false);
    }

    destroyStack(&stack);

    return 0;
}