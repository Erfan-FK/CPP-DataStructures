#ifndef CPP_SPARSE_H
#define CPP_SPARSE_H

#include "iostream"
using namespace std;

class Sparse{
private:
    class Element {
    public:
        int row;
        int column;
        int value;
    };
    int i;
    int j;
    int elementCount;
    Element* e;

public:
    Sparse(int i, int j, int elementCount) {
        this->i = i;
        this->j = j;
        this->elementCount = elementCount;
        this->e = new Element[elementCount];
    }

    ~Sparse() {
        delete[] this->e;
    }

    Sparse operator+(Sparse &sparse) {
        int x = 0, y = 0, z = 0;

        if (this->i != sparse.i || this->j != sparse.j)
            return {0, 0, 0};

        auto* res = new Sparse(this->i, this->j, this->elementCount + sparse.elementCount);

        while (x < this->elementCount && y < sparse.elementCount) {
            if (this->e[x].row < sparse.e[y].row)
                res->e[z++] = this->e[x++];
            else if (this->e[x].row > sparse.e[y].row)
                res->e[z++] = sparse.e[y++];
            else {
                if (this->e[x].column < sparse.e[y].column)
                    res->e[z++] = this->e[x++];
                else if (this->e[x].column > sparse.e[y].column)
                    res->e[z++] = sparse.e[y++];
                else {
                    res->e[z] = this->e[x];
                    res->e[z++].value = this->e[x++].value + sparse.e[y++].value;
                }
            }
        }

        while (x < this->elementCount)
            res->e[z++] = this->e[x++];

        while (y < sparse.elementCount)
            res->e[z++] = this->e[y++];

        return *res;
    }

    friend istream& operator>>(istream& istream, Sparse& sparse) {
        cout<<"Enter Row Column Value:"<<endl;
        
        for (int k = 0; k < sparse.elementCount; k++)
            cin>>sparse.e[k].row>>sparse.e[k].column>>sparse.e[k].value;

        return istream;
    }

    friend ostream& operator<<(ostream& ostream, Sparse& sparse) {
        int index = 0;

        cout<<"Your Matrix"<<endl;
        for (int k = 0; k < sparse.i; k++) {
            for (int l = 0; l < sparse.j; l++) {
                if(sparse.e[index].row == k && sparse.e[index].column == l)
                    cout<<sparse.e[index++].value<<" ";
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }

        return ostream;
    }
};

#endif //CPP_SPARSE_H
