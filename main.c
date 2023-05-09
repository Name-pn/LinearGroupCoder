#include <stdio.h>
#include "libs/linGroupCode/linGroupCode.h"
#include "windows.h"
#include "libs/menu/menu.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
//    struct message msg;
//    char str[255];
//    gets(str);
//    initMessage(&msg, strlen(str) + 1);
//    strcpy(msg.bufPtr, str);
//    struct linGroup* lg;
//    lg = initGroup(&msg);
//    writeMatr(&lg->g);
//    printf("Min w = %d, min d = %d\n", minWeight(lg), minDistance((lg)));
//    writeCodes(lg);
//    writeMsg(lg);
//    putc('\n', stdout);
//    char buf[255];
//    toText(lg, buf);
//    puts(buf);
//    makeError(lg);
//    fixError(lg);
//    toText(lg, buf);
//    puts(buf);
//    freeMessage(&msg);

    runMenu();
    return 0;
}
