/*"Copyright 2017 <Copyright Shadow>"*/
#include <iostream>
#include <locale>
#include <limits>

using namespace std;

int pplus(int a, int b) {
	return a + b;
}
int mminus(int a, int b) {
	return a - b;
}
int proiz(int a, int b) {
	return a * b;
}
double chast(double a, double b) {
	return a / b;
}
double pw(double a, double b) {
	if (b > 0) {
		for (int i = 0, j = a; i < b - 1; i++) a *= j;
		return a;
	} else if (b < 0) {
		for (int i = 0, j = a; i < (b + 1) * (-1); i++) a *= j;
		return 1 / a;
	} else
		return 1;
}
int modul(int a, int b) {
	return (a % b);
}
int anbit(int a, int b) {
	return a & b;
}
int btright(int a) {
	return a >> 1;
}
int btleft(int a) {
	return a << 1;
}
int btili(int a, int b) {
	return a | b;
}
int otr(int a) {
	return !a;
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "RUS");
	char choice[1][1];
	choice[0][0] = 'y';
	while (choice[0][0] == 'y') {
		int op1, op2;
		char x[1][1];
		do {
			cout << "Âûáèðèòå îäíó èç îïåðàöèé[+.-.*,/,%,^,!,&,|,<,>]:" << endl;
			cin >> *x;
			if(x[0][0] != '+' && x[0][0] != '-' && x[0][0] != '*' &&
			        x[0][0] != '/' && x[0][0] != '%' && x[0][0] != '^' &&
			        x[0][0] != '!' && x[0][0] != '&' && x[0][0] != '|' &&
			        x[0][0] != '<' && x[0][0] != '>')
				cerr<<"Íåêîððåêòíûå Äàííûå!"<<endl;
		} while (x[0][0] != '+' && x[0][0] != '-' && x[0][0] != '*' &&
		         x[0][0] != '/' && x[0][0] != '%' && x[0][0] != '^' &&
		         x[0][0] != '!' && x[0][0] != '&' && x[0][0] != '|' &&
		         x[0][0] != '<' && x[0][0] != '>');
		if (x[0][0] == '+' || x[0][0] == '-' || x[0][0] == '*' || x[0][0] == '/' ||
		        x[0][0] == '%' || x[0][0] == '^' || x[0][0] == '|' || x[0][0] == '&') {
			bool test = true;
			do {
				cout << "Ââåäèòå ïåðâîå ÷èñëî:" << endl;
				cin>>op1;
				if ( !(test=cin.good()) )
					cout << "Îøèáêà: Âû ââåëè íå ÷èñëî!" << endl;
				cin.clear() ;
				cin.ignore( numeric_limits<streamsize>::max() , '\n') ;
			} while(!test);
			do {
				cout << "Ââåäèòå âòîðîå ÷èñëî:" << endl;
				cin>>op2;
				if ( !(test=cin.good()) )
					cout << "Îøèáêà: Âû ââåëè íå ÷èñëî!" << endl;
				cin.clear() ;
				cin.ignore( numeric_limits<streamsize>::max() , '\n') ;
			} while(!test);
			switch (x[0][0]) {
				case '+':
					cout << "Ñóììà:" << pplus(op1, op2) << endl;
					break;
				case '-':
					cout << "Ðàçíîñòü:" << mminus(op1, op2) << endl;
					break;
				case '*':
					cout << "ïðîèçâåäåíèå:" << proiz(op1, op2) << endl;
					break;
				case '/':
					if (op2 != 0)
						cout << "÷àñòíîå:" << chast(op1, op2) << endl;
					else
						cerr << "Îøèáêà:íà0 äåëèòü íåëüçÿ!" << endl;
					break;
				case '%':
					cout << "ìîäóëü:" << modul(op1, op2) << endl;
					break;
				case '^':
					cout << "Âîçâåäåíèå â ñòåïåíü:" << pw(op1, op2) << endl;
					break;
				case '&':
					cout << "Ïîáèòîâàÿ È:" << anbit(op1, op2) << endl;
					break;
				case '|':
					cout << "Ïîáèòîâîå ÈËÈ:" << btili(op1, op2) << endl;
					break;
				default:
					cerr << "Îøèáêà" << endl;
			}
		}
		if (x[0][0] == '!' || x[0][0] == '<' || x[0][0] == '>') {
			bool test=true;
			do {
				cout << "Ââåäèòå ïåðâîå ÷èñëî:" << endl;
				cin>>op1;
				if ( !(test=cin.good()) )
					cout << "Îøèáêà: Âû ââåëè íå ÷èñëî!" << endl;
				cin.clear() ;
				cin.ignore( numeric_limits<streamsize>::max() , '\n') ;
			} while(!test);
			switch (x[0][0]) {
				case '!':
					cout << otr(op1) << endl;
					break;
				case '>':
					cout << btright(op1)<<endl;
					break;
				case '<':
					cout << btleft(op1)<<endl;
					break;
				default:
					cerr << "Îøèáêà" << endl;
			}
		}
		cin.sync();
		do {
			cout << "Åñëè âû õîòèòå ïðîäîëæèòü ââåäèòå y,åñëè çàêîí÷èòü n" << endl;
			cin >>*choice;
			if(choice[0][0] != 'y' && choice[0][0] != 'n')
				cerr<<"Âû ââåëè íåâåðíûé ñèìâîë!"<<endl;
		} while (choice[0][0] != 'y' && choice[0][0] != 'n');
	}
	cout << "Äî ñâèäàíèÿ!" << endl;
	return 0;
}
