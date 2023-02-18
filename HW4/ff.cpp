#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() 
{
    int num_instances;
    cin >> num_instances;

    for (int i=0; i<num_instances; i++) 
    {
        int cache_size, num_requests;
        cin >> cache_size >> num_requests;
        
        int *requests = new int[num_requests];
        for (int j = 0; j < num_requests; j++) 
        { cin >> requests[j]; }

        set<int> cache;
        priority_queue<pair<int, int> > ff;

        int num_faults=0;
        for(int j=0; j<num_requests; j++)
        {
            int page = requests[j];
            if (cache.count(page) <= 0)
            { 
                num_faults++; 

                if (num_faults > cache_size)
                {
                    cache.erase(ff.top().second);
                    ff.pop();
                }
            }

            cache.insert(page);
            int next = j+1;
            while(next<=num_requests && requests[next++] != page);
            ff.push(make_pair(next, page));
        }

        cout << num_faults << endl;
    }

    return 0;
}
