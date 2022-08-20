#include "rational.h"
#include <iostream>

Rational::Rational(const int & numerator,const int & denominator){
	this->a=numerator;
	this->b=denominator;
	//化減 
	int GCD=gcd(abs(this->a),abs(this->b));
	this->a/=GCD; 
	this->b/=GCD; 
}
int Rational::gcd(int num1,int num2){ //算最大公因數  
	if(num2==0)
	{
		return num1;
	} 
	return gcd(num2,num1%num2);
}
void Rational::add(const Rational &in){
	int tmp=this->b;
	this->a*=in.b;
	this->b*=in.b;
	int ina=in.a;
	int inb=in.b;
	
	ina*=tmp;
	inb*=tmp;

	if (this->b<0){
		this->a*=(-1);
		this->b*=(-1);
	}
	if (inb<0){
		ina*=(-1);
		inb*=(-1);		
	}
	this->a+=ina;
	int GCD=gcd(abs(this->a),this->b);
	this->a/=GCD;
	this->b/=GCD;
}

void Rational::sub(const Rational &in){
	int tmp=this->b;
	this->a*=in.b;
	this->b*=in.b;
	
	int ina=in.a;
	int inb=in.b;
	
	ina*=tmp;
	inb*=tmp;
	
	if (this->b<0){
		this->a*=(-1);
		this->b*=(-1);
	}
	if (inb<0){
		ina*=(-1);
		inb*=(-1);		
	}
	this->a-=ina;
	int GCD=gcd(abs(this->a),this->b);
	this->a/=GCD;
	this->b/=GCD;
}

void Rational::mul(const Rational &in){
	this->a*=in.a;
	this->b*=in.b;
	if (this->b<0){
		this->a*=(-1);
		this->b*=(-1);
	}
	int GCD=gcd(abs(this->a),this->b);
	this->a/=GCD;
	this->b/=GCD;		
}

void Rational::div(const Rational &in){
	this->a*=in.b;
	this->b*=in.a;
	if (this->b<0){
		this->a*=(-1);
		this->b*=(-1);
	}
	int GCD=gcd(abs(this->a),this->b);
	this->a/=GCD;
	this->b/=GCD;	
}
void Rational::print(){
	if (this->b<0){//如果分母為負
		cout << -this->a << '/' << -this->b << endl;
	}else{//如果分母大於等於0
		cout << this->a << '/' << this->b << endl;
	}
}

// TODO all the member function
