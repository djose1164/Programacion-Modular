#ifndef GETCH_H
#define GETCH_H
static void initTermios(int echo);
static void resetTermios(void);
static char getch_(int echo);
char getch(void);
#endif //GETCH_H
