#include<iostream>
#include<string>
using namespace std;

class Monster {
protected: //자손이 접근 가능하도록 허용함
	int hp;
	int attack;
	

public:
	Monster(int h,int a):hp(h),attack(a) {} //생성자


	int hit() {
		return this->attack;
		
	}
	
};

class Slime:public Monster { //상속받음
public:
	Slime(int h, int a):Monster(h,a){} // 생성자

	int poison() {
		return attack * 2;
	}

	int wolf() {
		
	}
};

int main() {
	Slime blue(100,10);

	cout << blue.hit() << endl;
	cout << blue.poison() << endl;
}