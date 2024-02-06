#include <vector>
#include <queue>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        indegree.resize(numCourses);

        // 构造图 + 入度计算
        buldGraph(numCourses, prerequisites);

        // 将入度为零的点加入队列
        queue<int> q;
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // bfs遍历图
        int count = 0;
        while (!q.empty()) {
            count++;
            int curr = q.front();
            q.pop();
            for (auto sonId : graph[curr]) {
                indegree[sonId]--;
                if (indegree[sonId] == 0) {
                    q.push(sonId);
                }
            }
        }

        return count == numCourses;
    }

private:
    vector<int> indegree;
    vector<vector<int>> graph;

    void buldGraph(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; ++i) {
            graph[i] = vector<int>();
        }
        indegree = vector<int>(numCourses);

        for (const auto& data : prerequisites) {
            vector<int> edge = data;
            int from = edge[1];
            int to  = edge[0];
            graph[from].push_back(to); // 构造图
            indegree[to]++; // 计算入度
        }
    }
};

TEST(LEETCODE207, case1) {
    // numCourses = 2, prerequisites = [[1,0]]
    Solution s;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    bool ret = s.canFinish(numCourses, prerequisites);
    ASSERT_EQ(ret, true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
