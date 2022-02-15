#include <iostream>
#include <fstream>
#include <math.h>
float f(float x){
    float pot=pow(x,2);
    float y= exp(-pot);
    return y;
}

float central_derivative(float x,float h){
    float d = (f(x+h)- f(x-h))/(2*h);
    return d;
}
int main(){
    std::ofstream *File;
    File = new std::ofstream[1];
    File[0].open("datos.txt",std::ofstream::trunc);
    float h=0.01;
    float lim_inf=-20.0;
    float lim_sup= 20.0;
    float i=lim_inf;
    while (i<lim_sup){
        float f_prima=central_derivative(i,h);
        File[0]<<i<<" "<<f_prima<<std::endl;
        i+=h;
    }
        

    File[0].close();
    return 0;
}

