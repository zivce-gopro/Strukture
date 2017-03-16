#pragma once
#include "Node.h"

#include <iostream>
using namespace std;

class CPolynomLL {
	Node* head;
	Node* tail;
public:
	~CPolynomLL() {
		if (head) {
			delete[] head;
		}


	}
	CPolynomLL() {
		head = tail = nullptr;
	}
	void addToTail(Node* A);
	void addToHead(Node* A);
	void addToList(int exp, double coef);
	void addToMulList(int exp, double coef);
	void addToTMPList(int exp, double coef);

	CPolynomLL* addPol(CPolynomLL& B);

	CPolynomLL* mulPol(CPolynomLL& A,CPolynomLL& B);


	void printPolynom();
};
