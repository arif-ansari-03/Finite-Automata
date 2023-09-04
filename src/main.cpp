#include <iostream>
#include <cmath>
#include "automata.cpp"

using namespace std;

int main()
{
    t[0]['b'] = 0;
    t[0]['a'] = 1;
    t[1]['a'] = 1;
    t[1]['b'] = 2;
    t[2]['b'] = 3;
    t[2]['a'] = 1;
    t[3]['a'] = 3;
    t[3]['b'] = 3;
    
    f[3] = 1;

    M = DFA(t, f);

    while (true)
    {
        int inp;

        cout << "1. DFA" << endl;
        cout << "2. Quit" << endl;
        cout << "Enter input: ";
        cin >> inp;

        if (inp == 1)
        {
            while (true)
            {
                cout << "1. Make DFA" << endl;
                cout << "2. Sample DFA" << endl;
                cout << "3. Quit DFA" << endl;

                cin >> inp;

                if (inp == 1)
                {
                    DFA M1;
                    cout << "Enter number of states: ";
                    int n;
                    cin >> n;

                    cout << "Enter transition table ((q1 a q2, a != '#', enter -1 in q1 to terminate): ";
                    M1.makeTransitionTable(n);

                    cout << "Enter final states (0-n-1) (-1 to terminate): ";
                    M1.setFinalStates();

                    while (true)
                    {
                        string s;
                        cout << "Enter string (\"#\" to terminate): ";
                        cin >> s;
                        if (s[0] == '#') break;

                        if (M1.accepts(s)) cout << "Accepted" << endl;
                        else cout << "Rejected" << endl;
                    }
                }
                else if (inp == 2)
                {
                    cout << "It accepts a string if it has substring \"abb\", otherwise rejects it.\n";
                    
                    while (true)
                    {
                        string s;
                        cout << "Enter string (\"#\" to terminate): ";
                        cin >> s;
                        if (s[0] == '#') break;

                        if (M.accepts(s)) cout << "Accepted" << endl;
                        else cout << "Rejected" << endl;
                    }
                }
                else if (inp == 3)
                {
                    break;
                }
            }
        }
        else if (inp == 2)
        {
            break;
        }
    }    
}