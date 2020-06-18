#include<iostream>
#include<string>
using namespace std;

string a = "";//存入字符串 
int adv = 0;//字符串小标，表示使IP指向下一输入符号
void E();
void E1();
void T();
void T1();
void F();

//规则E->TE'
void E(){
	cout << "E->TE" << endl;
	T();
	E1();
}

//规则E'->+TE'|ε
void E1(){
	if(a[adv] == '+'){
			cout << "E->+TE'" << endl;
			adv++;
			T();
			E1();
	}else{
		cout << "E->ε" << endl;
	}
} 

//规则T->ET' 
void T(){
	cout << "T->FT'" << endl;
	F();
	T1();
}

//规则T'->*FT' 
void T1(){
	if(a[adv] == '*'){
		cout << "T'->FE'" << endl;
		adv++;
		F();
		T1();
	}else{
		cout <<"T'->ε" << endl;
	}
}

//规则F->(E)|i 
void F(){
	if(a[adv] == '('){
		adv++;
		E();
		if(a[adv] == ')'){
			cout << "F->(E)" << endl;
			adv++;
		}else{
			cout << "err!" << endl;
			exit(0);
		}
	}else if(a[adv] == 'i'){
		cout << "E->i" << endl;
		adv++; 
	}else{
		cout << "err!" << endl;
		exit(0);
	}
}

int main(void){
	cin >> a; "输入字符串"
	E(); "入口程序"
	if(a[adv] == '#'){"如果匹配到结束符,说明匹配成功"
		cout << a << " is a match! " << endl;
	}else{
		cout << " err! " << endl;
	}
	return 0;
}
