#include<iostream>
#include<string>
using namespace std;

class Monster {
protected: //�ڼ��� ���� �����ϵ��� �����
	int hp;
	int attack;
	

public:
	Monster(int h,int a):hp(h),attack(a) {} //������


	int hit() {
		return this->attack;
		
	}
	
};

class Slime:public Monster { //��ӹ���
public:
	Slime(int h, int a):Monster(h,a){} // ������

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