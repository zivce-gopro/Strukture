#include "CPol.h"
#include <iostream>
using namespace std;

void CPolynomLL::addToList(int exp, double coef)
{
	if (coef == 0)
	{
		return; 
		//preskoci
	}

	Node* tmp = new Node(exp, coef);
	
	if (head == tail && head != nullptr)
	{
		//ako imamo jedan element
		//i ako se uklapa u sort
		if(head->getExp() < exp ){

			this->addToTail(tmp);

		}
		else
		{

			this->addToHead(tmp);

		}
		return;
	}


	if(head == nullptr)
	{
		head = tail = tmp;
		return;
	}
	else
	{
		Node* tmp1 = new Node();//naredni pokazivac
		Node* tmp0 = nullptr;//prethodni pokazivac
		
		tmp1 = head;
		bool p = false;
		while (tmp1 != nullptr)//jedan elem u listi
		{
			if (tmp1->getExp() == exp)
				return;

			if (tmp1->getExp() < exp){
				tmp0 = tmp1;
			}
			else {
				p = true;
			}
			if (p){
			
				break;//prvi veci element kraj!
			
			}
			tmp1 = tmp1->getNext();
		}
		

		tmp->setNext(tmp1);
		tmp0->setNext(tmp);
		
		if (tail->getNext() != nullptr)
			tail = tail->getNext();

	}


}


void CPolynomLL::addToHead(Node* A) 
{
	if (head == nullptr && head == tail)
	{
		head = A;
		tail = A;
	}
	else
	{
		Node* tmp = head;
		head = A;
		head->setNext(tmp);
		
	}

}
void CPolynomLL::addToTail(Node* A)
{
	if (tail == nullptr && head == tail)
	{
		head = A;
		tail = head;
	}
	else
	{

		tail->setNext(A);

		tail = tail->getNext();

	}

}

CPolynomLL* CPolynomLL::addPol(CPolynomLL& A) {

	CPolynomLL* TMP = new CPolynomLL();

	Node* tmpThis = this->head;

	Node* tmpANode = A.head;
	//ako je jedan od polinoma
	//prazan

	if (tmpThis == nullptr)
	{
		return &A;

	}
	if (tmpANode == nullptr)
	{
		return this;

	}


	if(tmpANode != nullptr || tmpThis != nullptr)
	//dovoljno je da je jedno tacno 
	// zbog raz dim polinoma!
	{
		//prodji kroz obe liste 
		// i pokupi eksponente i
		// doda ih u tmp
		
		Node* tmpA = A.head;
		
		int defaultr = 1;

		while (tmpA != nullptr) {
			TMP->addToList(tmpA->getExp(), defaultr);
			tmpA = tmpA->getNext();
		}
		
		tmpA = this->head;

		while (tmpA != nullptr) {

			//proveri dal vec nije dodat!

				TMP->addToList(tmpA->getExp(), defaultr);

			tmpA = tmpA->getNext();

		}

		delete tmpA;

		//granicni slucajevi
		//tmpANode == nullptr
	
		//onda je tmpThis != nullptr

		if(tmpANode == nullptr){
			Node* tmpHd = TMP->head;

			while (tmpThis != nullptr)
			{
				if (tmpHd->getExp() == tmpThis->getExp())
				{
					tmpHd->setKoef(tmpThis->getKoef());
				}//end if

				tmpThis = tmpThis->getNext();
				tmpHd = tmpHd->getNext();
			}//end while
			return TMP;
		}//end if

		// tmpThis == nullptr

		if (tmpThis == nullptr) {
			Node* tmpHd = TMP->head;

			while (tmpANode != nullptr)
			{
				if (tmpHd->getExp() == tmpANode->getExp())
				{
					tmpHd->setKoef(tmpANode->getKoef());
				}//end if

				tmpANode = tmpANode->getNext();
				tmpHd = tmpHd->getNext();
			}//end while
			return TMP;
		}//end if


		//nisu nullptr

		//cuvaju vrednosti pre ulaza u petlju
		Node* tmpAtmp = tmpANode;
		Node* tmpThistmp = tmpThis;
		Node* tmpHd = TMP->head;

		while (tmpANode != nullptr)
		{
			
			if (tmpHd->getExp() == tmpANode->getExp())
			{
				tmpHd->setKoef(tmpANode->getKoef());
			}//end if

			tmpANode = tmpANode->getNext();
			tmpHd = tmpHd->getNext();
		}//end while

		tmpANode = tmpAtmp;
		tmpThis = tmpThistmp;
		tmpHd = TMP->head;

		while (tmpThis != nullptr)
		{

			if (tmpHd->getExp() == tmpThis->getExp())
			{
				tmpHd->setKoef(tmpThis->getKoef() + tmpHd->getKoef());
			}//end if

			tmpThis = tmpThis->getNext();
			tmpHd = tmpHd->getNext();
		}//end while

		tmpANode = tmpAtmp;
		tmpThis = tmpThistmp;

	}//end while tmpThis Or tmpANode

	return TMP;
}


void CPolynomLL::printPolynom() {
	Node* tmp = this->head;
	int i = 0;
	while (tmp != nullptr)
	{	

		cout << "exp " << ++i << ": " << tmp->getExp() << endl;
		cout << "Koef: " << tmp->getKoef() << endl;
		tmp = tmp->ge


	}

}