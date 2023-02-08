#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
template <class T>
class vector {
private:
    T *v;
    int s;
public:
    vector(){
            s=0;
            v=NULL;
    }

    ~vector(){
            delete [] v;
    }

    int size() {
            return s;
    }

    void push_back(T ele) {
            T *temp;
            temp = new T[++s];
            for(int i=0; i<s-1; i++)
                temp[i]=v[i];
            delete [] v;
            v=temp;
            v[s-1]=ele;
    }

    vector(vector<T> &other){
        s = other.s;
        v = new T[s];
        for(int i = 0; i<s-1; i++)
                v[i]=other.v[i];
        cout << "copy" << endl;
        


    }

    void operator=(vector<T> &other){
        delete [] v;
        s = other.s;
        v = new T[s];
        for(int i = 0; i<s-1; i++)
                v[i]=other.v[i];
        cout << "assignment overload" << endl;


    }

T& operator[](int i){ //Returns the specified index
        return v[i];
}

T& at(int i){         //Returns index, but checks if out of bounds first
        if(i > s){
                cout << "Returned outbounds" << endl;
                return v[0];
                
        }
        else{
                cout << "Returned inbounds" << endl;
                return v[i];
        }
}

T& resize(vector<T> &other, int n){
        T *temp = new T[n];
        for (int i =0; i < n; i++){
                temp.v[i] = other.v[i];
        }
        delete[] other;
        return &temp;

        


}
};