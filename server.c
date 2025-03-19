#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

pid_t sender_pid = 0;

void    signal_handler(int signum)
{
    static char     c = 0;
    static int      bit = 7;
    // pid_t sender = info->si_pid;

	// if (bit == 0)
	// {
	// 	c = 0;
	// 	bit = 7;
	// }
	// sender_pid = sender;
    if (signum == SIGUSR2)
        c |= (1 << bit);
    // printf("hello");
    if (bit == 0)
    {
        write(1, &c, 1);
        // if (c == '\0')
        // kill(sender_pid, SIGUSR2);
        c = 0;
        bit = 8;
    }
    bit--;
	// kill(sender_pid, SIGUSR1);
}       

int     main(void)
{
	// struct sigaction info = {0};
	// info.sa_sigaction = signal_handler;
	// info.sa_flags = SA_SIGINFO;
    printf("Server PID: %d\n", getpid());
        // sigaction(SIGUSR1, &info, NULL);
        // sigaction(SIGUSR2, &info, NULL);
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1)
		pause();
	return (0);
}