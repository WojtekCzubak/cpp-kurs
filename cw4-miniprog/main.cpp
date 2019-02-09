#include <iostream>
#include <math.h>
using namespace std;

//cout<<bitset<8*sizeof(i3)>{i3}<<endl;

void showBits(void * start, int bits_amount){
    int *istart=(int *)start;
    for (int i=0; i<bits_amount; i=i+64)
    {
        cout << *istart << endl;
        istart++;
        istart++;
    }
}

void dumpNBytesFrom(unsigned char * p, int number_of_elems){
    for(int i=0; i<number_of_elems;i++)
    {
        printf("&a[%d]= %x, a[%d]=%x\n",i, p, i, *p);
        p++;
    }
}

void dump4NBytesFrom(unsigned int * p, int number_of_elems){
    for(int i=0; i<number_of_elems;i++)
    {
        printf("&a[%d]= %x, a[%d]=%x\n",i, p, i, *p);
        p++;
    }
}

void printArrayElements( unsigned short * p, int number_of_elems){
    unsigned int* pi = (unsigned int*)p;
    for(int i=0; i<number_of_elems;i++)
    {
        printf("a[%d]=%x\n", i, *pi);
        pi++;
    }
}

void printIntArrayElemWithBits( unsigned int * pi, int number_of_elems){
    unsigned char * pC = reinterpret_cast<unsigned char *>(pi);
    for(int i=0; i<(number_of_elems*4);i++)
    {   for(char j=0;j<8;j++){
            int maska = pow(2,j);
            // printf("%x-",*pC);
            //cout<<maska<<": ";
            if ((maska&(*pC))==0){cout<<0;}
            else{cout<<1;}
        }
        cout<<" ";
        pC++;
    }
}

unsigned int ConvertFloatToIntWithPointers(float f){
    float * pF = &f;
    unsigned int * pI = reinterpret_cast<unsigned int *>(pF);

    return *pI;
}

unsigned int ConvertFloatToInt(float f){ //exercising bits shifts
    float * pF = &f;
    unsigned char * pC = reinterpret_cast<unsigned char *>(pF);
    constexpr int size = sizeof(float);
    unsigned char chars_from_float[size];

    for(int i=0; i<sizeof(float);i++){
        chars_from_float[i]= *pC;
        //printf("pC %d =%x *pC=%x \n", i, pC, *pC);
        pC++;
    }

    pC--;
    //printf("pf =%x \n", reinterpret_cast<unsigned char *>(pF));
    //printf("pC=%x\n", pC);
    unsigned int int_from_float=0;
    unsigned int *pI=&int_from_float;
    for(int i=0; i<size-1;i++){
         int_from_float=((int_from_float|(*pC))<<8);
         pC--;
    }
    int_from_float=int_from_float|(*pC);

    return int_from_float;
}



int main(){
    cout << "Hello!" << endl;

    //----------------------zad2----------------------------------------
    printf("------------------------------------------------------------\n1.\n");
    unsigned int a[] = {0x11223344, 0x55667788, 0x99aabbcc, 0xddeeffba};
    constexpr int tab_length = sizeof(a)/sizeof(a[0]); //sizeof(*a) - surowo beirze wskaznik mniej bezpiecznie
    printArrayElements(reinterpret_cast<unsigned short *>(a), tab_length);
    //----------------------zad2cd--------------------------------------
    printf("------------------------------------------------------------\n1. print bits (as it is in memory)\n");
    printIntArrayElemWithBits(reinterpret_cast<unsigned int *>(a), tab_length);

    //--------drukowanie zawartosci pamieci od wskazanego miejsca-------
    printf("------------------------------------------------------------\n2.\n");
    dumpNBytesFrom(reinterpret_cast<unsigned char *>(a), tab_length*8); // mozna czytac pamiec bedaca dalej


    //---------------------zmiana float na int--------------------------
    printf("------------------------------------------------------------\n3.\n");
    //float f = -248.75f; // 0xC3 78 C0 00
    float f = 2.0f; // 0x40 00 00 00
    dumpNBytesFrom(reinterpret_cast<unsigned char *>(&f), 4);
    cout<<"your float number: "<<f<<" = "<<ConvertFloatToIntWithPointers(f)<<" when converted to integer :)"<<endl;


    return 0;
}
