#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// part 1 unique_ptr
class TreeNode {
private:
    string name;
    vector<unique_ptr<TreeNode>> children;

public:
    TreeNode(const string& nodeName) : name(nodeName) {
        cout << "TreeNode created: " << name << endl;
    }

    ~TreeNode() {
        cout << "TreeNode destroyed: " << name << endl;
    }

    void addChild(unique_ptr<TreeNode> child) {
        children.push_back(move(child));
    }

    bool removeChild(const string& childName) {
        auto it = find_if(children.begin(), children.end(),
            [&childName](const unique_ptr<TreeNode>& child) {
                return child->getName() == childName;
            });

        if (it != children.end()) {
            children.erase(it);
            return true;
        }
        return false;
    }

    TreeNode* findNode(const string& nodeName) {
        if (name == nodeName) {
            return this;
        }

        for (auto& child : children) {
            TreeNode* found = child->findNode(nodeName);
            if (found) {
                return found;
            }
        }
        return nullptr;
    }

    string getName() const {
        return name;
    }

    void preOrderTraversal() {
        cout << name << " ";
        for (auto& child : children) {
            child->preOrderTraversal();
        }
    }

    void inOrderTraversal() {
        if (!children.empty()) {
            size_t mid = children.size() / 2;

            for (size_t i = 0; i < mid; ++i) {
                children[i]->inOrderTraversal();
            }

            cout << name << " ";

            for (size_t i = mid; i < children.size(); ++i) {
                children[i]->inOrderTraversal();
            }
        }
        else {
            cout << name << " ";
        }
    }

    void postOrderTraversal() {
        for (auto& child : children) {
            child->postOrderTraversal();
        }
        cout << name << " ";
    }
};

// part 2 shared_ptr
class ComplexNode : public enable_shared_from_this<ComplexNode> {
private:
    string name;
    vector<shared_ptr<ComplexNode>> children;

public:
    ComplexNode(const string& nodeName) : name(nodeName) {
        cout << "ComplexNode created: " << name << endl;
    }

    ~ComplexNode() {
        cout << "ComplexNode destroyed: " << name << endl;
    }

    void addChild(shared_ptr<ComplexNode> child) {
        children.push_back(child);
        cout << "Added child to " << name << ". Child reference count: "
            << child.use_count() << endl;
    }

    bool removeChild(const string& childName) {
        auto it = find_if(children.begin(), children.end(),
            [&childName](const shared_ptr<ComplexNode>& child) {
                return child->getName() == childName;
            });

        if (it != children.end()) {
            cout << "Removing child " << childName << " from " << name
                << ". Reference count before: " << it->use_count() << endl;
            shared_ptr<ComplexNode> temp = *it;
            children.erase(it);
            cout << "Reference count after: " << temp.use_count() << endl;
            return true;
        }
        return false;
    }

    shared_ptr<ComplexNode> findNode(const string& nodeName) {
        if (name == nodeName) {
            return shared_from_this();
        }

        for (auto& child : children) {
            shared_ptr<ComplexNode> found = child->findNode(nodeName);
            if (found) {
                return found;
            }
        }
        return nullptr;
    }

    string getName() const {
        return name;
    }

    void traverse() {
        cout << name << " (ref count: " << shared_from_this().use_count() << ") ";
        for (auto& child : children) {
            child->traverse();
        }
    }
};

int main() {
    cout << "=== Part 1: Using unique_ptr for tree ===" << endl;
    {
        auto root = make_unique<TreeNode>("Root");

        root->addChild(make_unique<TreeNode>("Child1"));
        root->addChild(make_unique<TreeNode>("Child2"));

        TreeNode* child1 = root->findNode("Child1");
        if (child1) {
            child1->addChild(make_unique<TreeNode>("Grandchild1"));
            child1->addChild(make_unique<TreeNode>("Grandchild2"));
        }

        cout << "\nPre-order traversal: ";
        root->preOrderTraversal();
        cout << "\nIn-order traversal: ";
        root->inOrderTraversal();
        cout << "\nPost-order traversal: ";
        root->postOrderTraversal();
        cout << endl;

        cout << "\nRemoving Child2..." << endl;
        root->removeChild("Child2");

        cout << "\nPre-order traversal after removal: ";
        root->preOrderTraversal();
        cout << endl;

        cout << "\nDestroying tree..." << endl;
    }

    cout << "\n=== Part 2: Using shared_ptr for complex structures ===" << endl;
    {
        auto node1 = make_shared<ComplexNode>("Node1");
        auto node2 = make_shared<ComplexNode>("Node2");
        auto node3 = make_shared<ComplexNode>("Node3");

        node1->addChild(node2);
        node1->addChild(node3);
        node2->addChild(node3);

        cout << "\nTraversing complex structure:" << endl;
        node1->traverse();
        cout << endl;

        cout << "\nRemoving Node3 from Node1..." << endl;
        node1->removeChild("Node3");

        cout << "\nTraversing complex structure after removal:" << endl;
        node1->traverse();
        cout << endl;

        cout << "\nDestroying complex structure..." << endl;
    }
}