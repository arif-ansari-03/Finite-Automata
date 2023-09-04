#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class DFA
{
    vector<vector<int>> T;
    unordered_map<int, bool> F;
    int q0 = 0;

public:
    DFA() {}

    DFA(vector<vector<int>> t, unordered_map<int, bool> f)
    {
        T = t;
        F = f;
    }

    void setTransition(vector<vector<int>> t)
    { T = t; }

    bool accepts(string s)
    {
        int q = q0;
        for (int i = 0; i < s.length(); i++)
        {
            q = T[q][s[i]];
            if (q == -1) return 0;
        }

        if (F.count(q)) return 1;
        return 0;
    }

    void makeTransitionTable(int n)
    {
        int q1, q2;
        char a;
        T = vector<vector<int>>(n, vector<int>(256, -1));

        cin >> q1;
        while (q1 != -1)
        {
            cin >> a >> q2;
            T[q1][a] = q2;

            cin >> q1;
        }
    }

    void setFinalStates()
    {
        int q;
        cin >> q;
        while (q != -1)
        {
            F[q] = 1;
            cin >> q;
        }
    }
};




// sample dfa

vector<vector<int>> t(4, vector<int>(256, -1));
unordered_map<int, bool> f;

DFA M(t, f);