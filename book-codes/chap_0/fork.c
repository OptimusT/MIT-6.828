#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main() {
    int pid = fork();
    if (pid > 0) {
        printf("%u: parent: child=%d\n", getpid(), pid);
        pid = wait();
        printf("%u: child %d is done\n", getpid(), pid);
    } else if (pid == 0) {
        printf("%u: I am child\n", getpid());
        sleep(10);
        printf("%u: child: exiting\n", getpid());
        exit(0);
    } else {
        printf("%u: fork error\n", getpid());
    }
}