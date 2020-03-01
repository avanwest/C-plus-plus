// Adam vanWestrienen

#ifndef SAFEARRAY_H_INCLUDED
#define SAFEARRAY_H_INCLUDED

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class SafeArray;

template <typename T>
ostream& operator<<(ostream& os, SafeArray<T> s);

template < typename T >
class SafeArray {
    private:
        int low, high;
        T* p;
    public:
        //default constructor
        SafeArray() 
        {
            low = 0;
            high = -1;
            p = NULL;
        }
        
        // two parameter constructor
        SafeArray(int l, int h)
        {
            if((h - l + 1) <= 0) 
            {
                cout << "constructor error in bounds definition" << endl;
                exit(1);
            }
            low=l;
            high=h;
            p = new T[h - l + 1];
        }
       
       // single parameter constructor
        SafeArray(int i) 
        {
            low = 0;
            high = i - 1;
            p = new T[i];
        }
        
        // copy constructor for pass by value and initialization 
        SafeArray(const SafeArray & s)
        {
            int size= s.high - s.low + 1;
            p = new T[size];
            for(int i = 0; i < size; i++) p[i] = s.p[i];
            low = s.low;
            high = s.high;
        }
        
        // destructor 
        ~SafeArray()
        {
            delete [] p;
        }
        
        // overloaded []
        T& operator[](int i){
            if(i < low || i > high)
            {
                cout << "index " << i << " out of range" << endl;
                exit(1);
            }
            return p[i-low];
        }

        // overloaded assignment lets us assign one SA to another
        SafeArray & operator=(const SafeArray & s)
        {
            if(this == &s) return *this;
            delete [] p;
            int size = s.high - s.low + 1;
            p = new T[size];
            for(int i=0; i<size; i++) p[i] = s.p[i];
            low = s.low;
            high = s.high;
            return *this;
        }
        
        // overloads << so we can directly print SAs 
        friend ostream& operator << <T>(ostream& os, SafeArray<T> s);
};

        template <class T>
        ostream & operator <<(ostream & os, SafeArray <T> s) 
        {
            int size = s.high - s.low + 1;
            for (int i = 0; i < size; i++) os << s.p[i] << endl;
            return os;
        };
        
#endif  // SafeArray.h