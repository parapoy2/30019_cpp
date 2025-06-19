#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

struct Node {
    string data;
    vector<shared_ptr<Node>> children;

    Node(const string& d) : data(d) {}
};

void addChild(shared_ptr<Node> parent, shared_ptr<Node> child) {
    parent->children.push_back(child);
}

void printTree(const shared_ptr<Node>& node, int depth = 0) {
    for (int i = 0; i < depth; ++i) cout << "  ";
    cout << node->data << "\n";
    for (const shared_ptr<Node>& child : node->children) {
        printTree(child, depth + 1);
    }
}

int main() {
    auto root = make_shared<Node>("ceo");
    auto manager1 = make_shared<Node>("manager 1");
    auto manager2 = make_shared<Node>("anmager 2");
    auto employee1 = make_shared<Node>("employee A");
    auto employee2 = make_shared<Node>("employee B");

    addChild(root, manager1);
    addChild(root, manager2);
    addChild(manager1, employee1);
    addChild(manager2, employee2);

    printTree(root);

    cin.get();

    return 0;
}