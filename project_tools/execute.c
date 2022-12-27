#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    if (argc <= 1)return 0;
    for (int i = 1; i < argc; i++) {
        int result;
        if ((result = system(argv[i])) != 0) {
            return result;
        }
    }
    return 0;
}