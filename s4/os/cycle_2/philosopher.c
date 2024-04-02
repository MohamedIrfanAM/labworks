#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

char* state[5];
int semaphores[5] = {1, 1, 1, 1, 1};

void wait(int i) {
    while (semaphores[i] == 0 && strcmp(state[i], "HUNGRY") == 0){
        sleep(1);
    };
    semaphores[i] = 0;
}

void signal(int n) {
    if (semaphores[n] == 0) {
        semaphores[n] = 1;
    }
}

void eat(int philosopher) {
  if(philosopher % 2 == 0) {
    wait(philosopher);
    wait((philosopher + 1) % 5);
  }
  else{
    wait((philosopher + 1) % 5);
    wait(philosopher);
  }
    strcpy(state[philosopher], "EATING"); 
    while (1) {
        if (strcmp(state[philosopher], "EATING") == 0) {
            sleep(1);
            break;
        }
    }
}

void think(int philosopher) {
    strcpy(state[philosopher], "THINKING");
    while (1) {
        if (strcmp(state[philosopher], "THINKING") == 0) {
            sleep(1);
            break;
        }
    }
}

void printState() {
    printf("Current state of philosophers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Philosopher %d is %s\n", i + 1, state[i]);
    }
}


void* work(void* p) {
    int philosopher = *(int*)p;
    while (1) {
        if (strcmp(state[philosopher], "HUNGRY") == 0) {
            printState();
            eat(philosopher);
            printState();
        } else if (strcmp(state[philosopher], "THINKING") == 0) {
            printState();
            think(philosopher);
        }
        else if(strcmp(state[philosopher], "STOP_EATING") == 0){
            signal(philosopher);
            signal((philosopher + 1) % 5);
            strcpy(state[philosopher], "THINKING"); 
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        state[i] = malloc(sizeof(char) * 9); 
        strcpy(state[i], "THINKING"); 
    }

    pthread_t philosopher1, philosopher2, philosopher3, philosopher4, philosopher5;

    printState();

    int *ids = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        ids[i] = i;
    }
    pthread_create(&philosopher1, NULL, work, (void *)&ids[0]);
    pthread_create(&philosopher2, NULL, work, (void *)&ids[1]);
    pthread_create(&philosopher3, NULL, work, (void *)&ids[2]);
    pthread_create(&philosopher4, NULL, work, (void *)&ids[3]);
    pthread_create(&philosopher5, NULL, work, (void *)&ids[4]);

    strcpy(state[0], "HUNGRY");
    strcpy(state[4], "HUNGRY");
    sleep(5);
    strcpy(state[0], "STOP_EATING");
    // sleep(5);
    // strcpy(state[2], "HUNGRY");
    // sleep(5);
    // strcpy(state[1], "STOP_EATING");
    // sleep(5);
    // strcpy(state[3], "HUNGRY");
    // strcpy(state[4], "HUNGRY");

    pthread_join(philosopher1, NULL);
    pthread_join(philosopher2, NULL);
    pthread_join(philosopher3, NULL);
    pthread_join(philosopher4, NULL);
    pthread_join(philosopher5, NULL);

    for (int i = 0; i < 5; i++) {
        free(state[i]);
    }

    free(ids);
    return 0;
}
