#ifndef VECT_H_INCLUDED
#define VECT_H_INCLUDED
#include<iostream>

        class Vector
        {
        private:
                double x;
                double y;
                double mag;
                double any;
                char mode;
                void set_mag();
                void set_any();
                void set_x();
                void set_y();
        public:
                Vector();
                Vector(double n1,double n2,char form='r');
                void set(double n1,double n2,char form='r');
                ~Vector();
                double xval()const{return x;}
                double yval()const{return y;}
                double magval()const {return mag;}
                double angval()const{return any;}
                void polar_made();
                void rect_mode();
                Vector operator+(const Vector& b)const;
                Vector operator-(const Vector& b)const;
                Vector operator-()const;
                Vector operator*(double n)const;
                friend Vector operator*(double n,const Vector &a);
                friend  std::ostream operator<<(std::ostream &os,const Vector &v);
        };


#endif // VECT_H_INCLUDED
