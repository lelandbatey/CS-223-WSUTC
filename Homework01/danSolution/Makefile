CC = g++

all: homework1


%.o: %.c
	$(CC) -c -o $@ $<

homework1: homework1.o BinaryTree.o TreeNode.o
	$(CC) homework1.o BinaryTree.o TreeNode.o -o homework1

clean:
	@rm -f homework1 homework1.o BinaryTree.o TreeNode.o
