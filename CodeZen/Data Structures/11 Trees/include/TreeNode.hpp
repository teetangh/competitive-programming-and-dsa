#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:

    T data;
    vector<TreeNode<T> *> children;  //Could have multiple Children
    
    // T is implicit here
    // vector<TreeNode<> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
            delete children[i];
    }
};