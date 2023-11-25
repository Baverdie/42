#include <stdio.h>
#include <stdarg.h>

void afficher_arguments(int nombre_arguments, ...) {
    va_list liste_arguments;
    va_start(liste_arguments, nombre_arguments);

    int i = 0;
    while (i < nombre_arguments) {
        int argument = va_arg(liste_arguments, int);
        printf("%d\n", argument);
        i++;
    }

    va_end(liste_arguments);
}

int main() {
    afficher_arguments(4, 1, 2, 3, 4);
    return 0;
}

