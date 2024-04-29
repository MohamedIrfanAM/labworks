#innclude<stdio.h>

typedef process struct {
  int arrival_time;
  int burst_time;
}

void fcfs(){
  int n = 5;
  process p[n] = {{0, 3}, {1, 6}, {2, 4}, {3, 5}, {4, 2}};
  int waiting_time = 0;
  int turnaround_time = 0;
  int completion_time = 0;
  for(int i = 0; i < n; i++){
    if(i == 0){
      completion_time = p[i].arrival_time + p[i].burst_time;
      turnaround_time = completion_time - p[i].arrival_time;
      waiting_time = 0;
    }
    else{
      completion_time = completion_time + p[i].burst_time;
      turnaround_time = completion_time - p[i].arrival_time;
      waiting_time = completion_time - p[i].arrival_time - p[i].burst_time;
    }
    printf("Process %d\n", i + 1);
    printf("Arrival Time: %d\n", p[i].arrival_time);
    printf("Burst Time: %d\n", p[i].burst_time);
    printf("Waiting Time: %d\n", waiting_time);
    printf("Turnaround Time: %d\n", turnaround_time);
  }
}

void round_robin(){
  int n = 5;
  process p[n] = {{0, 3}, {1, 6}, {2, 4}, {3, 5}, {4, 2}};
  int quantum = 2;
  int waiting_time = 0;
  int turnaround_time = 0;
  int completion_time = 0;
  int remaining_time[n];
  for(int i = 0; i < n; i++){
    remaining_time[i] = p[i].burst_time;
  }
  int t = 0;
  while(1){
    int done = 1;
    for(int i = 0; i < n; i++){
      if(remaining_time[i] > 0){
        done = 0;
        if(remaining_time[i] > quantum){
          t += quantum;
          remaining_time[i] -= quantum;
        }
        else{
          t = t + remaining_time[i];
          waiting_time = t - p[i].burst_time;
          turnaround_time = t - p[i].arrival_time;
          remaining_time[i] = 0;
        }
      }
    }
    if(done == 1){
      break;
    }
  }
  printf("Process %d\n", i + 1);
  printf("Arrival Time: %d\n", p[i].arrival_time);
  printf("Burst Time: %d\n", p[i].burst_time);
  printf("Waiting Time: %d\n", waiting_time);
  printf("Turnaround Time: %d\n", turnaround_time);
}


void sjf(){
  int n = 5;
  process p[n] = {{0, 3}, {1, 6}, {2, 4}, {3, 5}, {4, 2}};
  int waiting_time = 0;
  int turnaround_time = 0;
  int completion_time = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(p[j].burst_time > p[j + 1].burst_time){
        process temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
      }
    }
  }
  for(int i = 0; i < n; i++){
    if(i == 0){
      completion_time = p[i].arrival_time + p[i].burst_time;
      turnaround_time = completion_time - p[i].arrival_time;
      waiting_time = 0;
    }
    else{
      completion_time = completion_time + p[i].burst_time;
      turnaround_time = completion_time - p[i].arrival_time;
      waiting_time = completion_time - p[i].arrival_time - p[i].burst_time;
    }
    printf("Process %d\n", i + 1);
    printf("Arrival Time: %d\n", p[i].arrival_time);
    printf("Burst Time: %d\n", p[i].burst_time);
    printf("Waiting Time: %d\n", waiting_time);
    printf("Turnaround Time: %d\n", turnaround_time);
  }
}

int main(){
  int n = 5;
  process p[n] = {{0, 3}, {1, 6}, {2, 4}, {3, 5}, {4, 2}};
   
}
