#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <setjmp.h>

#define HANDLE_SIGNAL  /* register the signal handler */
//#define DO_SEGFAULT    /* generate segment fault */
//#define JUMP_SEGFAULT  /* jump segment fault */
#define HANDLE_CTRL_C /* CTRL+C */

#ifdef JUMP_SEGFAULT
jmp_buf env;
#endif

static int gs_signals[] = 
{
    SIGSEGV, /* This is the most common crash */
    SIGINT,
    -1
};

static void crash_handler(int sig)
{
    printf("Child: received signal %d: ", sig);
    if(sig == SIGSEGV)
    {
       printf("SEGMENT FAULT\n");
#ifdef JUMP_SEGFAULT
       longjmp(env, 1);
#endif
    }
    else if(sig == SIGINT)
       printf("INTERRUPTED, by CTRL +C?\n");
    else
       printf("Not translated signal\n");
}
void register_sig_handler()
{
    int i = 0;
    while(gs_signals[i] != -1)
    {
        signal(gs_signals[i], crash_handler);
        i ++;
    }
}
int main(int argc, char * argv[])
{
    printf("Process started\n");

#ifdef HANDLE_CTRL_C
    sigset_t newmask, oldmask;
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    sigaddset(&newmask, SIGINT);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);
    printf("SIGINT is blocked for 10 seconds, CTRL+C takes no effect now\n");
    sleep(10);

    sigprocmask(SIG_UNBLOCK, &newmask, &oldmask);
    printf("SIGINT is unblocked, CTRL+C works now\n");
    printf("Sleep for 10 seconds, or use kill or CTRL+C to exit\n");
    sleep(10);
#endif

#ifdef HANDLE_SIGNAL /* register signal handlers */
    register_sig_handler();
#endif
    
#ifdef DO_SEGFAULT
#ifdef JUMP_SEGFAULT
    int rp = setjmp(env);
    if(rp == 0)
    {
#endif //#ifdef JUMP_SEGFAULT
        printf("Bang! going to segment fault!\n");
        char* p = 0;
        *p = 'a';
#ifdef JUMP_SEGFAULT
    }
    else
    {
        printf("Recovered from segment fault!!\n");
    }
#endif //#ifdef JUMP_SEGFAULT
#endif //#ifdef DO_SEGFAULT

    printf("Process ended\n");
    return 0;//getchar();
}
