#include <iostream>
#include <string>
#include <locale>

using namespace std;

bool automata(string, string);
void testAutomata(string*);

int main(int argc, char** argv) {
	string str, display, cont;
	setlocale(LC_ALL, "");
	
	cout << "=============== Proyecto 1 - Teoría de Automatas ===============" << endl << endl;
	
	cout << "\t --Integrantes:------------------------------ " << endl;
	cout << "\t| Vicente Garza Reyna              - 1847176 |" << endl;
	cout << "\t| Diana Lizeth Renteria Aguilera   - 1852889 |" << endl;
	cout << "\t| Andrés Isaac Montes Bartolo      - 1854017 |" << endl;
	cout << "\t -------------------------------------------- " << endl << endl;
	
	cout << "Presione enter para continuar..." << endl;
	fflush(stdin);
	getchar();
	
	do {
		system("cls");
		cout << "Nombre usado: Andres Isaac Montes Bartolo\tMatricula usada: 1854017" << endl << endl;
		cout << "Alfabeto = { 0, 1, 4, 5, 7, 8, a, b, c, d, e, i, l, m, n, o, r, s, t, '.' }" << endl;
		cout << "Ingrese una cadena de caracteres. Por ejemplo, \"0aimb.1854017\":" << endl;
		fflush(stdin);
		getline(cin, str);
		
		do{
			cout << "¿Desea ver lo que hace el autómata? [S/N]" << endl;
			cin >> display;
			display[0] = toupper( display[0] );
			if ( display != "S" && display != "N" ) {
				cout << "Favor de ingresar una respuesta válida" << endl << endl;
			}
		} while ( display != "S" && display != "N" );
		cout << endl;
		
		if ( automata(str, display) ){
			cout << "Cadena valida" << endl;
		} else {
			cout << "Cadena invalida" << endl;
		}
		
		do{
			cout << "¿Desea continuar ingresando cadenas? [S/N]" << endl;
			cin >> cont;
			cont[0] = toupper( cont[0] );
			if ( cont != "S" && cont != "N") {
				cout << "Favor de ingresar una respuesta válida" << endl << endl;
			}
		} while ( cont != "S" && cont != "N");
		
		
	} while ( cont == "S");
	
	cout << "Gracias por probar este programa." << endl << endl;
	cout << "Puede encontrar el código fuente en:" << endl << "https://github.com/Shotem/TdA-1" << endl << endl;
	cout << "Presione enter para continuar..." << endl;
	fflush(stdin);
	getchar();
	
}

bool automata(string str, string display) {
	typedef enum States{ q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, qA, qB, qC, qD, qE, qf, qm, states} States;
	int chars = 20;
	
	States matrix[states][chars] = {
	//	    0,  1,  4,  5,  7,  8,  a,  b,  c,  d,  e,  i,  l,  m,  n,  o,  r,  s,  t,  .
		{  q1, q1, q1, q1, q1, q1, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm }, //q0
		{  q1, q1, q1, q1, q1, q1, q3, q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, q2 }, //q1
		{  q1, q1, q1, q1, q1, q1, q3, q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, qm }, //q2
		{  q1, q1, q1, q1, q1, q1, q3, q1, q1, q1, q1, q4, q1, q1, q1, q1, q1, q1, q1, q2 }, //q3
		{  q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, q5, q1, q1, q1, q1, q1, q2 }, //q4
		{  q1, q1, q1, q1, q1, q1, q1, q6, q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, q1, q2 }, //q5
		{  qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, q7 }, //q6
		{  qE, q8, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qm }, //q7
		{  qE, qE, qE, qE, qE, q9, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE }, //q8
		{  qE, qE, qE, qA, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE }, //q9
		{  qE, qE, qB, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE }, //qA
		{  qC, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE }, //qB
		{  qE, qD, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE }, //qC
		{  qE, qE, qE, qE, qf, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE }, //qD
		{  qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, q7 }, //qE
		{  qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, qE, q7 }, //qf
		{  qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm, qm }  //qm
	};
	
	
	States curr_state = q0;
	
	for (int i = 0; i < str.length(); i++) {
		if (display == "S"){
			cout << "Estado: " << curr_state << "\tCaracter: " << str[i] << endl;	
		}
		switch(str[i]) {
			case '0':
				curr_state = matrix[curr_state][0];
				break;
			case '1':
				curr_state = matrix[curr_state][1];
				break;
			case '4':
				curr_state = matrix[curr_state][2];
				break;
			case '5':
				curr_state = matrix[curr_state][3];
				break;
			case '7':
				curr_state = matrix[curr_state][4];
				break;
			case '8':
				curr_state = matrix[curr_state][5];
				break;
			case 'a':
				curr_state = matrix[curr_state][6];
				break;
			case 'b':
				curr_state = matrix[curr_state][7];
				break;
			case 'c':
				curr_state = matrix[curr_state][8];
				break;
			case 'd':
				curr_state = matrix[curr_state][9];
				break;
			case 'e':
				curr_state = matrix[curr_state][10];
				break;
			case 'i':
				curr_state = matrix[curr_state][11];
				break;
			case 'l':
				curr_state = matrix[curr_state][12];
				break;
			case 'm':
				curr_state = matrix[curr_state][13];
				break;
			case 'n':
				curr_state = matrix[curr_state][14];
				break;
			case 'o':
				curr_state = matrix[curr_state][15];
				break;
			case 'r':
				curr_state = matrix[curr_state][16];
				break;
			case 's':
				curr_state = matrix[curr_state][17];
				break;
			case 't':
				curr_state = matrix[curr_state][18];
				break;
			case '.':
				curr_state = matrix[curr_state][19];
				break;
			
			default:
				cout << "ERROR: EL caracter '" << str[i] << "' en la posición " << i+1 << " de la cadena no es parte del alfabeto." << endl;
				curr_state = qm;
			 	break;
		}
		
		if (curr_state == qm) {
			if (display == "S"){
				cout << "Se alcanzó el estado muerto (" << qm << ")" << endl;
			}
			break;
		}
	}
	if (display == "S"){
		cout << "Estado: " << curr_state << endl << endl;
	}
	return (curr_state == qf);
	
}
