#include <stdio.h>
#ifdef __WIN32 /* Windows dectetado. */
#include <conio.h>
#elif __linux__
#include <unistd.h> /* Linux detectado. */
#include <sys/ioctl.h>
#include <termios.h>
#endif //__WIN32

#ifdef __linux__
static struct termios old, current;

/* Initialize new terminal i/o settings */
static void initTermios(int echo)
{
	tcgetattr(0, &old);			/* grab old terminal i/o settings */
	current = old;				/* make new settings same as old settings */
	current.c_lflag &= ~ICANON; /* disable buffered i/o */
	if (echo)
		current.c_lflag |= ECHO; /* set echo mode */

	else
		current.c_lflag &= ~ECHO; /* set no echo mode */

	tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
static void resetTermios(void)
{
	tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
static char getch_(int echo)
{
	char ch;
	initTermios(echo);
	ch = getchar();
	resetTermios();
	return ch;
}

/* Read 1 character without echo */
char getch(void)
{
	return getch_(0);
}
#endif // __linux__
