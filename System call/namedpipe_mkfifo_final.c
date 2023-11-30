#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    mkfifo("nitin", 0777);

    char message[] = "How are you\n";

    int pid = fork();
    if (pid == 0)
    {
        char buff[100];
        int fd = open("nitin", O_RDONLY);
        ssize_t buff_size;
        buff_size = read(fd, buff, strlen(message));
        printf("\nMessage from parent- %s", buff);
    }
    else
    {
        int fd1 = open("nitin", O_WRONLY);
        write(fd1, message, strlen(message));
        printf("\nParent written to fifo\n");
        wait(NULL);
    }

    unlink("jay");
}
