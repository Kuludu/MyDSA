#include "Tree.hpp"

namespace MyTreeNamespace {
    using std::max;

    template<class T>
    int MyTree<T>::get_diameter() {
        if (diameter != -1)
            return diameter;
        
        on_get_diameter(root);

        return diameter;
    }

    template<class T>
    int MyTree<T>::on_get_diameter(const std::shared_ptr<Node<T>>& cur) {
        if (cur == nullptr) {
            return 0;
        }

        int l = on_get_diameter(cur->left_son);
        int r = on_get_diameter(cur->right_son);
        diameter = max(diameter, l + r);

        return max(l, r) + 1;
    }
}