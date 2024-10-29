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

    destroyStack(&stack);

    printf("test_pop passed.\n");
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

    destroyStack(&stack);

    printf("test_isEmpty passed.\n");
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

    destroyStack(&stack);

    printf("test_searchByValue passed.\n");
}

void test_createNode() {
    // Создаем узел: 30
    Node* node = createNode(30);

    // Проверяем, что он не null, в нем лежит значение 30 и следующего элемента нет
    assert(node != NULL);
    assert(node->data == 30);
    assert(node->next == NULL);

    free(node);

    printf("test_createNode passed.\n");
}

void test_initStack() {
    // Создаем стек и проверяем что он пустой 
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack) == true);

    printf("test_initStack passed.\n");
}

void test_destroyStack() {
    // Создаем стек: 30 - 20 - 10
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    // Уничтожаем его
    destroyStack(&stack);
    
    // Проверяем что стек пустой
    assert(isEmpty(&stack) == true); 
    
    printf("test_destroyStack passed.\n");
}

void test_push() {
    // Создаем стек
    Stack stack;
    initStack(&stack);

    // Добавляем в него 10, и проверяем что этот элемент находится сверху
    push(&stack, 10);
    assert(getTop(&stack)->data == 10);
    
    // Добавляем в него 20, и проверяем что этот элемент находится сверху
    push(&stack, 20);
    assert(getTop(&stack)->data == 20);

    destroyStack(&stack);
    
    printf("test_push passed.\n");
}

void test_searchByIndex() {
    // Создаем стек: 30 - 20 - 10
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Проверяем, что на индексе 0 находится элемент 30 (вершина стека)
    Node* result = searchByIndex(&stack, 0);
    assert(result != NULL && result->data == 30);

    // Проверяем, что на индексе 2 находится элемент 10
    result = searchByIndex(&stack, 2);
    assert(result != NULL && result->data == 10);

    // Проверяем, что индекс, выходящий за пределы, возвращает NULL
    result = searchByIndex(&stack, 3);
    assert(result == NULL);

    destroyStack(&stack);

    printf("test_searchByIndex passed.\n");
}

void test_getTop() {
    // Создаем стек
    Stack stack;
    initStack(&stack);

    // Добавляем 10 и проверяем что оно сверху
    push(&stack, 10);
    assert(getTop(&stack)->data == 10);

    // Добавляем 20 и проверяем что оно сверху
    push(&stack, 20);
    assert(getTop(&stack)->data == 20);

    // Удаляем 20, и проверяем что 10 снова сверху
    pop(&stack);
    assert(getTop(&stack)->data == 10);

    destroyStack(&stack);

    printf("test_getTop passed.\n");
}

void test_traverseStack() {
    // Создаем стек: 30 - 20 - 10
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Ожидаем, что будет выведено: 30 20 10
    printf("Expected output: 30 20 10\n");
    printf("Actual output: ");

    traverseStack(&stack);

    destroyStack(&stack);

    printf("test_traverseStack passed.\n");
}



int main() {
    test_isEmpty();
    test_pop();
    test_searchByValue();
    test_createNode();
    test_initStack();
    test_push();
    test_searchByIndex();
    test_getTop();
    test_traverseStack();

    test_destroyStack();
    
    printf("All tests passed.\n");

    return 0;
}
