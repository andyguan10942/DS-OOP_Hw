#include "rational.h"

Rational::Rational(const int numerator, const int denominator){
    this->a = numerator;
    this->b = denominator;
	// Maybe you should do sth to let it be reduced form
	//化減 
	int GCD=gcd(abs(this->a),abs(this->b)); 
	this->a/=GCD;
	this->b/=GCD;
}

// TODO 
// write all functions here

int Rational::gcd(int num1,int num2){ //算最大公因數  
	if(num2==0)
	{
		return num1;
	} 
	return gcd(num2,num1%num2);
}

//1) Binary Arithmetic
const Rational Rational::operator+(const Rational & in){
	Rational temp(this->a,this->b);
	int tmp=temp.b;
	int ina=in.a;
	int inb=in.b;
	
	temp.a*=inb;
	temp.b*=inb;
	ina*=tmp;
	inb*=tmp;
	if (temp.b<0){
		temp.a*=(-1);
		temp.b*=(-1);
	}
	if (inb<0){
		ina*=(-1);
		inb*=(-1);		
	}
	temp.a+=ina;
	int GCD=gcd(abs(temp.a),temp.b);
	temp.a/=GCD;
	temp.b/=GCD;
	return temp;
}

const Rational Rational::operator-(const Rational & in){
	Rational temp(this->a,this->b);
	int tmp=temp.b;
	int ina=in.a;
	int inb=in.b;
	
	temp.a*=inb;
	temp.b*=inb;
	ina*=tmp;
	inb*=tmp;
	if (temp.b<0){
		temp.a*=(-1);
		temp.b*=(-1);
	}
	if (inb<0){
		ina*=(-1);
		inb*=(-1);		
	}
	temp.a-=ina;
	int GCD=gcd(abs(temp.a),temp.b);
	temp.a/=GCD;
	temp.b/=GCD;
	return temp;	
}

const Rational Rational::operator*(const Rational & in){
	Rational temp(this->a,this->b);
	temp.a*=in.a;
	temp.b*=in.b;
	if (temp.b<0){
		temp.a*=(-1);
		temp.b*=(-1);
	}
	int GCD=gcd(abs(temp.a),temp.b);
	temp.a/=GCD;
	temp.b/=GCD;
	return temp;
}

const Rational Rational::operator/(const Rational & in){
	Rational temp(this->a,this->b);
	temp.a*=in.b;
	temp.b*=in.a;
	if (temp.b<0){
		temp.a*=(-1);
		temp.b*=(-1);
	}
	int GCD=gcd(abs(temp.a),temp.b);	
	temp.a/=GCD;
	temp.b/=GCD;
	return temp;	
}
//2) Assignment
Rational& Rational::operator=(const Rational & in){
	this->a=in.a;
	this->b=in.b;
	return *this;
}

const Rational & Rational::operator+=(const Rational & in){
	*this=(*this)+in;
	return *this;
}

const Rational & Rational::operator-=(const Rational & in){
	*this=(*this)-in;
	return *this;
}

const Rational & Rational::operator*=(const Rational & in){
	*this=(*this)*in;
	return *this;
}

const Rational & Rational::operator/=(const Rational & in){
	*this=(*this)/in;
	return *this;
}

//3)Relational
bool Rational::operator>(const Rational & in){
	double num1,den1,num2,den2;
	num1=this->a;
	den1=this->b;

	num2=in.a;
	den2=in.b;
	return  (num1/den1)>(num2/den2);
}

bool Rational::operator<(const Rational & in){
	double num1,den1,num2,den2;
	num1=this->a;
	den1=this->b;

	num2=in.a;
	den2=in.b;
	return  (num1/den1)<(num2/den2);
}

bool Rational::operator>=(const Rational & in){
	double num1,den1,num2,den2;
	num1=this->a;
	den1=this->b;

	num2=in.a;
	den2=in.b;
	return  (num1/den1)>=(num2/den2);
}

bool Rational::operator<=(const Rational & in){
	double num1,den1,num2,den2;
	num1=this->a;
	den1=this->b;

	num2=in.a;
	den2=in.b;
	return  (num1/den1)<=(num2/den2);	
}

bool Rational::operator==(const Rational & in){
	double num1,den1,num2,den2;
	num1=this->a;
	den1=this->b;

	num2=in.a;
	den2=in.b;
	return  (num1/den1)==(num2/den2);	
}

bool Rational::operator!=(const Rational & in){
	double num1,den1,num2,den2;
	num1=this->a;
	den1=this->b;

	num2=in.a;
	den2=in.b;
	return  (num1/den1)!=(num2/den2);	
}

//4) Unary Arithmetic
Rational & Rational::operator++(){ //prefix++
	this->a+=this->b;
	if (this->b<0){
		this->a*=(-1);
		this->b*=(-1);
	}
	return *this;
}

Rational Rational::operator++(int){ //postfix++
	Rational temp(this->a,this->b);
	this->a+=this->b;
	if (this->b<0){
		this->a*=(-1);
		this->b*=(-1);
	}	
	return temp;
}

Rational & Rational::operator--(){ //prefix--
	this->a-=this->b;
	if (this->b<0){
		this->a*=(-1);
		this->b*=(-1);
	}	
	return *this;
}

Rational Rational::operator--(int){  //postfix--
	Rational temp(this->a,this->b);
	this->a-=this->b;
	if (this->b<0){
		this->a*=(-1);
		this->b*=(-1);
	}
	return temp;
}

Rational Rational::operator-(){
	Rational temp(-this->a,this->b);
	if (temp.b<0){
		temp.a*=(-1);
		temp.b*=(-1);
	}
	return temp;
}

//friend 
ostream & operator<<(ostream & os,const Rational & in){
	if (in.b<0){//如果分母為負
		os <<-in.a<< '/' <<-in.b<< endl;
	}else{//如果分母大於等於 0
		os <<in.a<< '/' <<in.b<< endl;
	}
	return os;
}

