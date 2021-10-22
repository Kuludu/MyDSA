package main

import "fmt"

// Node is the element of BST
type Node struct {
	value    int
	leftSon  *Node
	rightSon *Node
}

// BST is the Binary Search Tree
type BST struct {
	root   Node
	length int
}

func (tree *BST) insert(x int) {
	var insert func(*Node, int)
	insert = func(root *Node, x int) {
		if root.value == -1 {
			root.value = x
		}

		switch {
		case x < root.value:
			if root.leftSon == nil {
				root.leftSon = &Node{value: x}
			}
			insert(root.leftSon, x)
		case x > root.value:
			if root.rightSon == nil {
				root.rightSon = &Node{value: x}
			}
			insert(root.rightSon, x)
		}
	}
	insert(&tree.root, x)
	tree.length++
}

func (tree *BST) find(x int) int {
	var find func(*Node, int) int
	find = func(root *Node, x int) int {
		if root == nil {
			return -1
		}

		switch {
		case x == root.value:
			return x
		case x < root.value:
			return find(root.leftSon, x)
		default:
			return find(root.rightSon, x)
		}
	}

	return find(&tree.root, x)
}

func (tree *BST) traverse(fn func(*Node)) {
	var traverse func(*Node, func(*Node))
	traverse = func(root *Node, fn func(*Node)) {
		if root == nil {
			return
		}

		traverse(root.leftSon, fn)
		fn(root)
		traverse(root.rightSon, fn)
	}

	traverse(&tree.root, fn)
}

func (tree *BST) findMax() int {
	var findMax func(*Node) int
	findMax = func(root *Node) int {
		if root.rightSon == nil {
			return root.value
		}

		return findMax(root.rightSon)
	}

	return findMax(&tree.root)
}

func (tree *BST) findMin() int {
	var findMin func(*Node) int
	findMin = func(root *Node) int {
		if root.leftSon == nil {
			return root.value
		}

		return findMin(root.leftSon)
	}

	return findMin(&tree.root)
}

func main() {
	fmt.Println("Sample of BST.")
	var bst BST
	bst.root.value = -1

	for i := 0; i < 5; i++ {
		var input int
		fmt.Println("Insert a positive interger:")
		fmt.Scanln(&input)
		bst.insert(input)
	}

	bst.traverse(func(node *Node) { fmt.Print(node.value, " ") })

	fmt.Println()
	fmt.Println("Looking for 3:", bst.find(3))
	fmt.Println("Max:", bst.findMax())
	fmt.Println("Min:", bst.findMin())
}
