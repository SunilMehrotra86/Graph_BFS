#include<iostream>
#include <map>
#include<list>
#include<queue>
#include<string>

using namespace std;

template <typename T>
class Graph {

    map<T, list<T>> adjMatrix;
public:
    void InsertEntry(T arg1, T arg2) {
        adjMatrix[arg1].push_back(arg2);
        adjMatrix[arg2].push_back(arg1);
    }

    void BFS(T srcNode) {
        queue<T> qu;
        map<T, bool> visitedRecord;
        qu.push(srcNode);
        visitedRecord[srcNode] = true;
        do
        {
            auto data = qu.front();
            cout << data;
            for (auto Iter : adjMatrix[qu.front()])
            {
                if (!visitedRecord[Iter]) {
                    qu.push(Iter);
                    visitedRecord[Iter] = true;
                }
            }
            qu.pop();

        } while (!qu.empty());
    }
};



int main()
{
    Graph<string> gp;
    gp.InsertEntry("Rajat", "Rohit");
    gp.InsertEntry("Rajat", "Sunil");
    gp.InsertEntry("Sunil", "Amit");
    gp.InsertEntry("Amit", "Sarvesh");
    gp.InsertEntry("Sarvesh", "Ankit");
    gp.BFS("Ankit");
    return 0;
}


//row cols

