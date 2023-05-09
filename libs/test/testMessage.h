#ifndef NETKURSOV_TESTMESSAGE_H
#define NETKURSOV_TESTMESSAGE_H

#include "../message/message.h"
#include <stdio.h>

#define ERROR(s) printf("Ошибка в функции %s\n%s\n", __FUNCTION__, s)
#define END printf("Завершение %s\n", __FUNCTION__)

void testMes1();
void testMes2();
void testMes3();
void testMes4();
void testMes5();

void allMesTest();


#endif //NETKURSOV_TESTMESSAGE_H
