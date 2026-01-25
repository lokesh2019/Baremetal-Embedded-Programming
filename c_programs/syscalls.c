#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _ebss;

static uint32_t *heap_end;

extern int __io_putchar(int);

int _write(int fd, char *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        // Replace with your UART TX
        __io_putchar(ptr[i]);
    }
    return len;
}

int _sbrk(int incr)
{
    if (heap_end == 0)
        heap_end = &_ebss;

    uint32_t *prev = heap_end;
    if (heap_end + incr > &_estack)
    {
        errno = ENOMEM;
        return -1;
    }

    heap_end += incr;
    return (int)prev;
}

int _close(int fd)            { return -1; }
int _read(int fd, char *p, int len) { return 0; }
int _lseek(int fd, int ptr, int dir) { return 0; }
int _isatty(int fd)           { return 1; }
int _fstat(int fd, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

void _exit(int status)
{
    while (1) {}
}

int _kill(int pid, int sig)   { return -1; }
int _getpid(void)             { return 1; }
