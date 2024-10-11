#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>  // Include this for pid_t

int main(void) {
    pid_t pid;
    int x, y;

    for (x = 1; x <= 3; x++) {
        pid = fork();
        if (pid) {
            printf("----------p--Soy el proceso %d\n", getpid());
            sleep(2);
        } else {
            printf("Soy el hijo %d, mi padre es %d\n", getpid(), getppid());
            sleep(2);
            for (y = 1; y <= 2; y++) {
                pid = fork();
                if (pid) {
                    printf("----------ph---Soy el proceso %d\n", getpid());
                    sleep(2);
                } else {
                    printf("Soy el hijo %d, mi padre es %d\n", getpid(), getppid());
                    sleep(2);
                    exit(0);
                }
            }
            exit(0);
        }
    }
    return 0;
}
