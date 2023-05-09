#include "testMessage.h"

void testMes1() {
    struct message mes;
    initMessage(&mes, 4);
    freeMessage(&mes);
    END;
}

void testMes2() {
    struct message mes;
    initMessage(&mes, 4);
    setMessage(&mes, "123");
    //'1' = 49 = 00110001
    if (getBite(&mes, 0) != 1)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 1) != 0)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 2) != 0)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 3) != 0)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 4) != 1)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 5) != 1)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 6) != 0)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 7) != 0)
        ERROR("Неправильный возврат из getBite");
    freeMessage(&mes);
    END;
}
void testMes3() {
    struct message mes;
    initMessage(&mes, 4);
    //'1' = 49 = 00011001
    setBite(&mes, 0, 1);
    if (getBite(&mes, 0) != 1)
        ERROR("Ошибка при исполнении setBite");
    setBite(&mes, 1, 0);
    if (getBite(&mes, 1) != 0)
        ERROR("Ошибка при исполнении setBite");
    setBite(&mes, 2, 0);
    if (getBite(&mes, 2) != 0)
        ERROR("Ошибка при исполнении setBite");
    setBite(&mes, 3, 1);
    if (getBite(&mes, 3) != 1)
        ERROR("Ошибка при исполнении setBite");
    setBite(&mes, 4, 1);
    if (getBite(&mes, 4) != 1)
        ERROR("Ошибка при исполнении setBite");
    setBite(&mes, 5, 0);
    if (getBite(&mes, 5) != 0)
        ERROR("Ошибка при исполнении setBite");
    setBite(&mes, 6, 0);
    if (getBite(&mes, 6) != 0)
        ERROR("Ошибка при исполнении setBite");
    setBite(&mes, 7, 0);
    if (getBite(&mes, 7) != 0)
        ERROR("Ошибка при исполнении setBite");
    freeMessage(&mes);
    END;
}

void testMes4() {
    struct message mes;
    initMessage(&mes, 4);
    setMessage(&mes, "123");
    //'2' = 50 = 00110010
    if (getBite(&mes, 8) != 0)
        ERROR("Неправильный возврат из getBite");
    setBite(&mes, 9, 0);
    if (getBite(&mes, 9) != 0)
        ERROR("Неправильный возврат из getBite");
    setBite(&mes, 10, 1);
    if (getBite(&mes, 10) != 1)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 11) != 0)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 12) != 1)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 13) != 1)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 14) != 0)
        ERROR("Неправильный возврат из getBite");
    if (getBite(&mes, 15) != 0)
        ERROR("Неправильный возврат из getBite");
    freeMessage(&mes);
    END;
}

void testMes5() {
    struct message mes;
    initMessage(&mes, 4);
    setMessage(&mes, "123");
    writeBites(&mes, mes.n*8);
    printf("= 10001100 01001100 11001100\n");
    freeMessage(&mes);
    END;
}

void allMesTest() {
    testMes1();
    testMes2();
    testMes3();
    testMes4();
    testMes5();
}