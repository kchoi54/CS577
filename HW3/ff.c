#include <stdio.h>
#define MAX_JOB 2000

struct Job {
    int start;
    int end;
} typedef Job;

//backward max-heap
void heapify(Job *array, int size, int index) 
{
    int min = index;
    int left = index*2 - size; 
    int right = index*2 - size -1;

    if(size < 1)
    { return; }
    
    if(left >= 0 && array[min].end > array[left].end)
    { min = left; }

    if(right >= 0 && array[min].end > array[right].end)
    { min = right; }

    if(min != index)
    {
        Job temp = array[index];
        array[index] = array[min];
        array[min] = temp;

        heapify(array, size, min);
    }
}

void heapifyAll(Job *array, int size)
{   
    for(int i = size - size/2; i < size; i++)
    { heapify(array, size, i); }
}

void removeConflict(Job *array, int *size, int end) 
{
    for(int i = *size - 1; i >=0; i--)
    {
        if(array[i].start < end)
        { array[i] = array[--(*size)]; }
    }
}

int main() 
{
    int t, size, count;
    Job job[MAX_JOB];

    //number of trials
    scanf("%d", &t);

    while((t--)>0)
    {
        //number of jobs
        scanf("%d", &size);

        if(size > MAX_JOB)
        { return -1; }

        for(int i=0; i<size; i++)
        {
            //scan interval
            scanf("%d", &job[i].start);
            scanf("%d", &job[i].end);
        }

        //heapify O(n*log(n))
        heapifyAll(job, size);

        count = 0;
        while((size--) > 0)
        {
            count++;
            removeConflict(job, &size, job[size].end);
            heapifyAll(job, size);
        }
        printf("%d\n", count);
    }
}