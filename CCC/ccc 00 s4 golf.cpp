#include <iostream>
#include <climits>

using namespace std;

int main()
{
    // Fast input/output
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int distance; // Distance from TEE to HOLE (meters)
    int clubCount; // Number of unique clubs

    // INPUT -------------------------------------------

    // First line of input is distance from tee to hole
    cin >> distance;

    int clubs[clubCount]; // Array of unique club stroke distances
    int strokeCounts[distance]; // Number of strokes needed to get to every meter
    int shortestClub = INT_MAX; // shortest club for early return
    fill_n(strokeCounts, distance, INT_MAX); // Default to integer limit for number of strokes

    // Next line of input is number of clubs (0 to 32)
    cin >> clubCount;

    // For each club, another line of input is requried to get the distance of the club
    for (int i = 0; i < clubCount; i++)
    {
        cin >> clubs[i];
        strokeCounts[clubs[i] - 1] = 1;

        if (clubs[i] < shortestClub)
        {
            shortestClub = clubs[i];
        }
    }

    if (shortestClub > distance)
    {
        cout << "Roberta acknowledges defeat.\n";
    }

    // Algorithm -------------------------------------------

    for (int i = 0; i < distance; i++)
    {
        if (strokeCounts[i] != INT_MAX)
        {
            for (int club = 0; club < clubCount; club++)
            {
                int newStrokeCount = strokeCounts[i] + 1;

                if (i + clubs[club] < distance && newStrokeCount < strokeCounts[i + clubs[club]])
                {
                    strokeCounts[i + clubs[club]] = newStrokeCount;
                }
            }
        }
    }


    // OUTPUT
    if (strokeCounts[distance - 1] != INT_MAX)
    {
        cout << "Roberta wins in " << strokeCounts[distance - 1] << " strokes.\n";
    }
    else
    {
        cout << "Roberta acknowledges defeat.\n";
    }

    return 0;
}