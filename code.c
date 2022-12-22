#include<stdio.h>
int choice;
//fcfs code{

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n,
						int bt[], int wt[])
{
	// waiting time for first process is 0
	wt[0] = 0;

	// calculating waiting time
	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}

// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n,
				int bt[], int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

//Function to calculate average time
void findavgTime( int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	//Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt);

	//Function to find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);

	//Display processes along with all details
	printf("Processes\tBurst time\tWaiting time\tTurn around time\n");

	// Calculate total waiting time and total turn around time
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf(" %d\t\t ",(i+1));
		printf(" %d\t\t ", bt[i] );
		printf(" %d\t\t",wt[i] );
		printf(" %d\t\t \n",tat[i] );
	}
	float s=(float)total_wt / (float)n;
	float t=(float)total_tat / (float)n;
	printf("Average waiting time = %f",s);
	printf("\n");
	printf("Average turn around time = %f ",t);
}
int fcfs()
{
	int n; // no. of process.
	//process id's
	int processes[10];
	//Burst time of all processes
	int burst_time[10];
    printf("Enter number of process: ");
	scanf("%d", &n);
    printf("Enter Burst time:\n");
    // User Input Burst Time and alloting Process Id.
	for (int i = 0; i < n; i++) {
		printf("P%d: ", i + 1);
		scanf("%d", &burst_time[i]);
		burst_time[i] = i + 1;
        processes[i]=i+1;
	}
    
	findavgTime(processes, n, burst_time);
	return 0;
}
// }

//sjf code
int sjf()
{
	int A[100][4]; // Matrix for storing Process Id, Burst
				// Time, Average Waiting Time & Average
				// Turn Around Time.
	int i, j, n, total = 0, index, temp;
	float avg_wt, avg_tat;
	printf("Enter number of process: ");
	scanf("%d", &n);
	printf("Enter Burst Time:\n");
	// User Input Burst Time and alloting Process Id.
	for (i = 0; i < n; i++) {
		printf("P%d: ", i + 1);
		scanf("%d", &A[i][1]);
		A[i][0] = i + 1;
	}
	// Sorting process according to their Burst Time.
	for (i = 0; i < n; i++) {
		index = i;
		for (j = i + 1; j < n; j++)
			if (A[j][1] < A[index][1])
				index = j;
		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;

		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;
	}
	A[0][2] = 0;
	// Calculation of Waiting Times
	for (i = 1; i < n; i++) {
		A[i][2] = 0;
		for (j = 0; j < i; j++)
			A[i][2] += A[j][1];
		total += A[i][2];
	}
	avg_wt = (float)total / n;
	total = 0;
	printf("P	 BT	 WT	 TAT\n");
	// Calculation of Turn Around Time and printing the data.
	for (i = 0; i < n; i++) {
		A[i][3] = A[i][1] + A[i][2];
		total += A[i][3];
		printf("P%d	 %d	 %d	 %d\n", A[i][0],
			A[i][1], A[i][2], A[i][3]);
	}
	avg_tat = (float)total / n;
	printf("Average Waiting Time= %f\n", avg_wt);
	printf("\nAverage Turnaround Time= %f", avg_tat);
}


  
int srtf() 
{
      int arrival_time[10], burst_time[10], temp[10];
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("Enter the Total Number of Processes:");
      scanf("%d", &limit); 
     // printf("Enter Details of %d Processes", limit);
      for(i = 0; i < limit; i++)
      {
            printf("Enter Arrival Time of P%d:",i+1);
            scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time:of P%d:",i+1);
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      }
      burst_time[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
      average_waiting_time = wait_time / limit; 
      average_turnaround_time = turnaround_time / limit;
      printf("Average Waiting Time:%f\n", average_waiting_time);

      printf("Average Turnaround Time:%f", average_turnaround_time);
      return 1;
}

int main()
{
	printf("enter your choices:\n1.fcfs\n2.sjf\n3.srtf\n");
	scanf("%d",&choice);
    switch(choice)
	{
		case 1:
		{
			fcfs();
			break;
		}
		case 2:
		{
			sjf();
			break;
		}
		case 3:
		{
			srtf();
			break;
		}
		default:
		printf("invalid choice\n");
		break;
	
}

return 0;
}
 