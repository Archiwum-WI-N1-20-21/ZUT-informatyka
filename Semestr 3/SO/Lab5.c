#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc == 1 || argc > 2) {
        fprintf(stderr, "%s", "Liczba argumentow wieksza niz 1 lub brak argumentow\n");
        return 1;
    }
    char * ptr;
    long int retStr = strtol(argv[1], &ptr, 10);
    //printf("%ld", ret);
    if (retStr == 0) {
        fprintf(stderr, "%s", "Argument nie jest liczba naturalna\n");
        return 2;
    }
    if (retStr < 1 || retStr > 13) {
        fprintf(stderr, "%s", "Liczba poza zakresem 1-13\n");
        return 3;        
    }
    if (retStr == 1 || retStr == 2) {
        //fprintf(stderr, "%s", "Argument wynosi 1 lub 2\n");
        return 1;
    }

    int pid;
    int pidChildren[2];
    int argsFC[2] = {retStr - 1, retStr - 2};
    
    for (int i = 0; i < 2; i++) {
        pid = fork();
        if (pid == 0) { // w dziecku
            char argArr[3];
            sprintf(argArr, "%d", argsFC[i]);
            execlp("./prog", "/prog", argArr, NULL);
            return 1;
        } 
        if (pid != 0) pidChildren[i] = pid;
    }
    
    int retVal = 0, statusVal = 0;

    for (int i = 0; i < 2; i++) {
        int status;
        int waitChildren = waitpid(pidChildren[i], &status, 0);
        statusVal = WEXITSTATUS(status);
        retVal += statusVal;
        printf("%d\t%d\t%d\t%d\n", getpid(), pidChildren[i], argsFC[i], statusVal);
        }
    
    printf("%d\t%d\n\n", getpid(), retVal);

    return retVal;
}