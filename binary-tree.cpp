#include <iostream>

using namespace std;

class binary_tree_node {    
    public:
        int v;
        binary_tree_node *l;
        binary_tree_node *r;

        binary_tree_node(int v) {
            this->v = v;
        }
};

class binary_search_tree {
    private:
        binary_tree_node *root;
        binary_tree_node **test_and_traverse(int v, binary_tree_node *cur) {
            return (cur->v < v) ? &cur->l : &cur->r;
        }
        int add_new_node(int v, binary_tree_node *cur) {
            binary_tree_node **pos = test_and_traverse(v, cur);
            if (!(*pos)) {
                *pos = new binary_tree_node(v);
                return 0;
            } else {
                return add_new_node(v, (*pos));
            }
        }
        void display_nodes(binary_tree_node *cur) {
            if (cur && (cur->v > 0)) {
                cout << cur->v << " ";
                display_nodes(cur->l);
                display_nodes(cur->r);
            }
        }
        binary_tree_node *search_node(int v, binary_tree_node *cur) {
            binary_tree_node **pos = test_and_traverse(v, cur);
            if (v == cur->v)
                return cur;

            if (!(*pos))
                return NULL;
            else return search_node(v, (*pos));
        }

    public:
        void add(int v) {
            if (root->v < 0)
                root->v = v;
            else add_new_node(v, root);
        }
        void disp(void) {
            display_nodes(root);
            cout << endl;
        }
        binary_tree_node *search(int v) {
            return search_node(v, root);
        }
        binary_search_tree() {
            root = new binary_tree_node(-1);
        }
};
 
int main(int argc, char *argv[])
{
    int cmd;
    int state = 0;
    int input_val;
    binary_search_tree *T = new binary_search_tree();

    do {
        cout << "Command: ";
        cin >> cmd;
        switch(cmd) {
            case 1:
                T->disp();
                break;
            case 2:
                cout << "New value to add: ";
                cin >> input_val;
                T->add(input_val);
                break;
            case 3:
                cout << "Search value: ";
                cin >> input_val;
                cout << "pos=" << T->search(input_val) << endl;
                break;
            default:
                state = 1;
                break;
        }
    } while(!state);
    
    return EXIT_SUCCESS;
}