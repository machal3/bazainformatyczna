#include <iostream>
#include <vector>
#include <string>

struct Node
{
    int val;
    Node* next;
    Node (int v , Node* n) : val (v) , next (n) {}
};

int main ()
{
    int n;
    std::cin >> n;
    std::vector<Node*> version (n + 1 , nullptr);
    for (int i = 1; i <= n; ++i)
    {
        std::string op;
        std::cin >> op;
        if (op == "+")
        {
            int x;
            std::cin >> x;
            version[i] = new Node (x , version[i - 1]);
        }
        else if (op == "-")
        {
            if (version[i - 1])
            {
                version[i] = version[i - 1]->next;
            }
            else
            {
                version[i] = nullptr;
            }
        }
        else if (op == "*")
        {
            int y;
            std::cin >> y;
            version[i] = version[y - 1];
        }
        if (version[i])
        {
            std::cout << version[i]->val << "\n";
        }
        else
        {
            std::cout << "-1\n";
        }
    }
    return 0;
}