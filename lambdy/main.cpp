#include <iostream>
#include <vector>
#include <memory>


using namespace std;

template <typename T>
int sumGeneralElems(const vector<T> &elems){
    T sum =0;
    for (T elem : elems){
        sum = sum + elem;
    }
    return sum;
}

int sumElems(const vector<int> &elems){  //referencja do stalej - gwarancja, że nie bedziemy zmieniac, i nie trzeba kopiowac wektora wiec ref
    int sum = 0;
    for (int elem : elems){
        sum = sum + elem;
    }
    return sum;
}

int GeneralOperationOnElems(const vector<int> &elems, int (*operation)(int)){ //deklarcja lambdy - z wykorzystaniem szablonu
    int sum = 0;
    for (int elem : elems){
        sum = sum + operation(elem);
    }
    return sum;
}

int power(int x){
    return x*x;
}

class IntToIntMapper{
public:
    virtual int operator ()(int elem) = 0;
    virtual ~IntToIntMapper(){};
};

class squareSumFunktor : public IntToIntMapper{
public:
    int operator ()(int elem){return elem*elem;}
};

//int GeneralOperationOnElems(const vector<int> &elems, squareSumFunktor operation){ //z obiektem funkcyjnym bez interfacu
int GeneralOperationOnElems(const vector<int> &elems, IntToIntMapper &operation){ // z interfacem

    int sum = 0;
    for (int elem : elems){
        sum = sum + operation(elem);
    }
    return sum;
}

int GeneralOperationOnElemsWithLambda(const vector<int> &elems, function<int (int)> f){
    int sum = 0;
    for (int elem : elems){
        sum = sum + f(elem);
    }
    return sum;
}



int main()
{
    vector<int> myVec = {1, 2, 3, 4};

    cout << "1. sum: " << sumElems( myVec ) << endl;

    cout << "2. sum^2: " << GeneralOperationOnElems( myVec, power) << endl;

    vector<double> myVecD = {1.1, 2.2};
    cout << "2. sum d: " << sumGeneralElems( myVecD ) << endl;

    squareSumFunktor ss;
    cout << " sum -funktor: " << GeneralOperationOnElems( myVec, ss ) << endl;
    cout << " sum -lambda: " << GeneralOperationOnElemsWithLambda( myVec, [](int i){return i*i; } ) << endl;


  // auto wsk = uunique_pointer<> squareSumFunktor ss;

   cout << "size: " << sizeof(squareSumFunktor) << endl; // =1 bo adres muci byc nawet pustego obiektu iesli nei implementuje interface, jesli implementuje to 8

    return 0;
}
