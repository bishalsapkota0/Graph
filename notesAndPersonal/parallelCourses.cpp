int parallelCourses(int n, vector<vector<int>> &prerequisites)
{
    // Goal:
    // Find minimum number of semesters to finish all courses
    // If cycle exists (cannot finish all), return -1
    //
    // Idea:
    // Topological Sort using BFS (Kahn's Algorithm)
    // "One semester" = take ALL courses currently having indegree 0 (no prerequisites left)

    // 1) Create adjacency list graph: prereq -> course
    // adj[x] contains all courses that depend on x
    vector<vector<int>> adj(n + 1);

    // 2) Indegree array: indegree[i] = how many prerequisites course i still needs
    vector<int> indegree(n + 1, 0);

    // 3) Build graph + indegree
    for (auto edge : prerequisites)
    {
        int course = edge[0];
        int prereq = edge[1];

        // If edge means: to take "course" you must take "prereq" first
        // Then direction is prereq -> course
        adj[prereq].push_back(course);
        indegree[course]++;
    }

    // 4) Queue for BFS (Kahn's algo):
    // push all courses with indegree 0 (no prereq needed)
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // 5) BFS level-order:
    // Each BFS "level" = one semester
    int totalSemester = 0;

    // track how many courses we actually finished
    int takenCourses = 0;

    while (!q.empty())
    {
        // all courses currently in queue can be taken in THIS semester
        int size = q.size();

        // starting a new semester
        totalSemester++;

        // take all available courses this semester
        for (int i = 0; i < size; i++)
        {
            int currentCourse = q.front();
            q.pop();

            // we finished this course
            takenCourses++;

            // reduce indegree for all next courses dependent on currentCourse
            for (auto nextCourse : adj[currentCourse])
            {
                indegree[nextCourse]--;

                // if indegree becomes 0, it is ready for next semester
                if (indegree[nextCourse] == 0)
                {
                    q.push(nextCourse);
                }
            }
        }
    }

    // 6) If we took all courses, return semesters else cycle exists -> -1
    if (takenCourses == n)
    {
        return totalSemester;
    }
    else
    {
        return -1;
    }
}
