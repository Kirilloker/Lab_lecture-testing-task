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

void test_isEmpty() {
    Stack stack;
    initStack(&stack);

    // Новый стек пуст
    assert(isEmpty(&stack) == true);

    // После добавление элемента, стек больше не пустой
    push(&stack, 10);
    assert(isEmpty(&stack) == false);

    // Удаление единственного элемента, и проверка что стек пуст
    pop(&stack);
    assert(isEmpty(&stack) == true);

    printf("test_isEmpty passed.\n");

    destroyStack(&stack);
}

void test_searchByValue() {
    // Создаем стек: 30 - 20 - 10
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Находим 20 в стеке (есть в стеке)
    Node* result = searchByValue(&stack, 20);
    assert(result != NULL && result->data == 20);

    // Находим 10 в стеке (есть в стеке)
    result = searchByValue(&stack, 10);
    assert(result != NULL && result->data == 10);

    // Находим 10 в стеке (его нет в стеке)
    result = searchByValue(&stack, 40);
    assert(result == NULL);

    printf("test_searchByValue passed.\n");

    destroyStack(&stack);
}

int main() {
    test_isEmpty();
    test_pop();
    test_searchByValue();

    printf("All tests passed.\n");
    
    return 0;
}
