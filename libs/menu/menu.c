//
// Created by Alexandr on 09.05.2023.
//

#include "menu.h"

void writeInvatation() {
    printf("Для прекращения работы введите %d\n", END_OF_WORK);
    printf("Для кодирования сообщения в линейно-групповой код введите %d\n", CODING);
    printf("Для внесения ошибки в линейно-групповой код введите %d\n", NOICE);
    printf("Для вывода сообщения в битовом виде введите %d\n", WRITE_MSG);
    printf("Для вывода сообщения в виде текста введите %d\n", WRITE_TEXT);
    printf("Для исправления ошибок в сообщении введите %d\n", FIX);
    printf("->");
}

void runMenu() {
    int flag = SCAN;
    int init = 0;
    struct linGroup *lg;
    while (flag != END_OF_WORK) {
        writeInvatation();
        scanf("%d", &flag);
        switch (flag) {
            case SCAN: {
                break;
            }
            case CODING: {
                init = 1;
                printf("Введите кодируемую строку, не более %d байт\n", MAX_MSG_SIZE);
                char str[MAX_MSG_SIZE];
                gets(str);
                gets(str);
                struct message msg;
                initMessage(&msg, strlen(str) + 1);
                strcpy(msg.bufPtr, str);
                lg = initGroup(&msg);
                printf("Таблица кодирования:\n");
                writeCodes(lg);
                break;
            }
            case NOICE: {
                if (init) {
                    makeError(lg);
                } else
                    ERROR;
                break;
            }
            case WRITE_MSG: {
                if (init) {
                    writeMsg(lg);
                    printf("\n");
                }
                else
                    ERROR;
                break;
            }
            case WRITE_TEXT: {
                if (init) {
                    char str[MAX_MSG_SIZE];
                    toText(lg, str);
                    puts(str);
                } else
                    ERROR;
                break;
            }
            case FIX: {
                fixError(lg);
            }

        }
        if (flag != END_OF_WORK)
            flag = SCAN;
    }
}