#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;
typedef int DataType;

const int MAX = 100;


typedef class SeqList {
private:
    DataType * pData;
    int size;

    //Return true when the list is full.(size == MAX)
    //else return false.
    bool isFull();
    bool isEmpty();
    //Return true when pos is error
    bool posErr(int pos);
public:
    //Constrator: Create a list that is empty.
    SeqList() {
        pData = new DataType[MAX];
        memset(pData, 0, MAX * sizeof (DataType));
        size = 0;
    }

    //Push a element at the back of list.
    //Parameter DataType x is a element that will be push at the back of list.
    void pushBack(DataType x);
    //Insert a Element at given position
    void insertThisPos(DataType x, int pos);
    //Print all of the element in Sequence List
    void printList();
    //Make the List empty.
    void makeEmpty();



    
}SL;