#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int start;
    int finish;
} Show;

int compareShows(const void* a, const void* b) {
    Show* showA = (Show*)a;
    Show* showB = (Show*)b;
    return (showA->finish - showB->finish);
}

void scheduleShows(Show shows[], int n) {
    qsort(shows, n, sizeof(Show), compareShows);

    int scheduledShows = 1;
    int lastFinishTime = shows[0].finish;

    printf("\n");
    printf("Filmele programate:\n");
    printf("Film: %s, Ora de inceput: %d, Ora de final: %d\n", shows[0].name, shows[0].start, shows[0].finish);

    for (int i = 1; i < n; i++) {
        if (shows[i].start >= lastFinishTime) {
            scheduledShows++;
            lastFinishTime = shows[i].finish;
            printf("Film: %s, Ora de inceput: %d, Ora de final: %d\n", shows[i].name, shows[i].start, shows[i].finish);
        }
    }

    printf("Totalul filmelor programate: %d\n", scheduledShows);
}

int main() {
    int n;
    printf("Introdu numarul de filme: ");
    scanf("%d", &n);

    Show* shows = (Show*)malloc(n * sizeof(Show));

    printf("Introdu numele filmului, ora de inceput si ora de final\n");
    for (int i = 0; i < n; i++) {
        printf("Film %d:\n", i + 1);
        printf("Nume: ");
        scanf(" %[^\n]s", shows[i].name);
        printf("Ora de inceput: ");
        scanf("%d", &shows[i].start);
        printf("Ora de final: ");
        scanf("%d", &shows[i].finish);
    }

    scheduleShows(shows, n);

    free(shows);

    return 0;
}
