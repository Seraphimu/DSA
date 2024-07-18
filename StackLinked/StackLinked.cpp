#include "StackLinked.hpp"


void StackLinked::Init() {
    Top = nullptr;
}

bool StackLinked::IsEmpty() {
    return Top == nullptr;
}

void StackLinked::MakeEmpty() {
	if (IsEmpty()) {
		cout << "Stack Is Empty!" << endl;
		exit(-1);
	}

	while (!IsEmpty()) {
		Pop();
	}
}

DataType StackLinked::GetTop() {
	if (IsEmpty()) {
		cout << "Stack Is Empty!" << endl;
		exit(-1);
	}

	return Top->A;
}

void StackLinked::Pop() {
	if (IsEmpty()) {
		cout << "Stack Is Empty!" << endl;
		exit(-1);
	}

	Node * Tmp = Top;
	Top = Top->Next;
	free(Tmp);
	Tmp = nullptr;
}

void StackLinked::Push(DataType X) {
	Node * NewNode = BuyNode(X);

	NewNode->Next = Top;
	Top = NewNode;
}

Node * StackLinked::BuyNode(DataType X) {
	Node * NewNode = (Node *)malloc(sizeof(Node));
	if (NewNode == nullptr) {
		cout << "Malloc Failed!" << endl;
		exit(-1);
	}

	NewNode->A = X;
	NewNode->Next = nullptr;

	return NewNode;
}