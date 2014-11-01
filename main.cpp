#include <iostream>
#include <cstring>
using namespace std;

enum TokenType {
	INVALID = -1, NUMBER = 0, LETTER = 1, PLUS = 2, MINUS = 3,
	MULTIPLY = 4, DIVIDE = 5, POWER = 6, OPEN_PAREN = 7, CLOSE_PAREN = 8
};

struct Token
{
	int value;
	TokenType type = INVALID;
};

bool is_digit(char c) {
	return '0' <= c && c <= '9';
}

int parse(Token tokens[], char f[], int i, int l) {
	int tc = 0;
	int j = i;
	while (j < i + l) {
		if (is_digit(f[j])) {
			int nr = 0;
			for (; j < i + l; j++) {
				if (is_digit(f[j])) {
					nr = nr * 10 + f[j] - '0';
				} else {
					break;
				}
			}
			Token t;
			t.value = nr;
			t.type = NUMBER;
			tokens[tc] = t;
			tc++;
		} else if (('a' <= f[j] && f[j] <= 'z') ||
					('A' <= f[j] && f[j] <= 'Z')) {
			Token t;
			t.value = f[j];
			t.type = LETTER;
			tokens[tc] = t;
			tc++;
			j++;
		} else if (f[j] == '+') {
			Token t;
			t.type = PLUS;
			tokens[tc++] = t;
			j++;
		} else {
			j++;
		}
	}
	return tc;
}

void print_tokens(Token tokens[], int length) {
	for (int i = 0; i < length; i++) {
		if (tokens[i].type == NUMBER) {
			cout << "Număr: " << tokens[i].value << endl;
		} else if (tokens[i].type == LETTER) {
			cout << "Variabilă: " << (char)tokens[i].value << endl;
		}
	}
}

const int MAX_TOKENS = 100;
const int MAX_INPUT = 100;

int main(int argc, char const *argv[])
{
	char f[MAX_INPUT + 1]; // 100 usable chars + \0
	cout << "f(x) = ";
	cin.getline(f, MAX_INPUT);

	int l = strlen(f);
	if (l == 0) {
		cout << "Șirul de caractere introdus este gol." << endl;
		return 0;
	}

	Token tokens[MAX_TOKENS];
	int tc = parse(tokens, f, 0, l);

	print_tokens(tokens, tc);
	return 0;
}