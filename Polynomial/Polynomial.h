#ifndef CPP_POLYNOMIAL_H
#define CPP_POLYNOMIAL_H

#include "iostream"
using namespace std;

class Polynomial {
private:
    class Term {
    public:
        int exp;
        int cf;
    };
    int termNo;
    Term* t;

public:
    explicit Polynomial(int termNo) {
        this->termNo = termNo;
        this->t = new Term[termNo];
    }

    ~Polynomial() {
        delete[] this->t;
    }

    Polynomial operator+(Polynomial& polynomial) {
        auto* res = new Polynomial(this->termNo > polynomial.termNo ? this->termNo : polynomial.termNo);
        int i = 0, j = 0, k = 0;

        while (i < this->termNo && j < polynomial.termNo) {
            if (this->t[i].exp > polynomial.t[j].cf)
                res->t[k++] = this->t[i++];
            else if (this->t[i].exp < polynomial.t[j].exp)
                res->t[k++] = polynomial.t[j++];
            else {
                res->t[k] = this->t[i];
                res->t[k++].cf = this->t[i++].cf + polynomial.t[j++].cf;
            }
        }

        return* res;
    }

    friend istream& operator>>(istream& istream, Polynomial& polynomial) {
        cout<<"Enter Coefficient Exponent"<<endl;

        for (int i = 0; i < polynomial.termNo; i++)
            cin>>polynomial.t[i].cf>>polynomial.t[i].exp;

        cout<<endl;
        return istream;
    }

    friend ostream& operator<<(ostream& ostream, Polynomial& polynomial) {
        cout<<"P(x) = ";

        for (int i = 0; i < polynomial.termNo; i++)
            cout<<polynomial.t[i].cf<<"x^"<<polynomial.t[i].exp<<" + ";

        cout<<endl;
        return ostream;
    }
};

#endif //CPP_POLYNOMIAL_H
