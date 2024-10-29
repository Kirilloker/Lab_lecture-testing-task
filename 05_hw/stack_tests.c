#include "stack.h"
#include <assert.h>
#include <stdio.h>

void test_pop() {
    // Создаем стек: 30 - 20 - 10
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Верхний элемент должен быть равен 30
    assert(getTop(&stack)->data == 30);

    // Удаляем верхний элемент, теперь стек выглядит так: 20 - 10
    pop(&stack);

    // Повторяем до тех пор пока стек не станет пустым
    assert(getTop(&stack)->data == 20);

    pop(&stack);
    assert(getTop(&stack)->data == 10);

    pop(&stack);

    // Проверяем, что стек пустой
    assert(isEmpty(&stack) == true);

    printf("test_pop passed.\n");

    destroyStack(&stack);
}

int main() {
    test_pop();
    printf("All tests passed.\n");
    return 0;
}
