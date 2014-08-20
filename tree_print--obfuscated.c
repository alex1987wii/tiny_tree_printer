#include <stdio.h>
#include <math.h>

#define pc putchar

// Prints a line with nodes on it.
void p_l(int sbuff, int sp, int node_num, char node){
	int i = 0;
	for (i = 0; i < sbuff-1; ++i){
		pc(' ');
	}

	for (i = 0; i < node_num; ++i){
		pc(node);
		// Don't print spacers on last node
		if (i < node_num){
			int x;
			for (x = 0; x < sp; ++x){
				pc(' ');
			}
		}
	}
	for (i = 0; i < sbuff; ++i){
		pc(' ');
	}
	pc('\n');
}


void p_t(int ht){
	int st, i, x;
	for (st = 0; st < ht; ++st){
		int lv =  ht - st - 1;

		int ls = (int)pow(2.0, (double)lv);

		int sb = ls;
		int sp = (int)pow(2.0,(double)lv+1);

		// Creates the arrays with the nodes and columns
		int nc = (int)pow(2.0, (double)st);

		if (st){
			// Prints the "spanning" bars that connect nodes
			for (i = 0; i < sb-1; ++i){
				pc(' ');
			}

			for (i = 0; i < nc; ++i){
				// Determines whether to print a bar or empty space
				if (i%2){
					for (x = 0; x < sp-1; ++x){
						pc(' ');
					}
				} else {
					for (x = 0; x < sp+1; ++x){
						pc('=');
					}
				}
			}

			for (i = 0; i < sb; ++i){
				pc(' ');
			}
			pc('\n');
			p_l(sb, sp-1, nc, '|');
		}
		p_l(sb, sp-1, nc, 'O');
	}
}


int main(int argc, char const *argv[]){
	int ht=5;
	if (argc>1){
		ht = atoi(argv[1]);
	}
	int x[25][2] = {{201348139,116},{1308819461,110},{1248256,116},{5450323,115},{2820,108},{1116246,118},{5439758,115},{609943552,101},{285215570,114},{55576576,112},{1376583683,114},{285214474,118},{89718797,121},{1308626182,110},{33575955,116},{1530331136,101},{0,32},{0,32},{0,32},{0,32},{3286309,82},{134219016,105},{860754,114},{852226,110},{370540544,32}};
	int i,n;
	for (i = 0; i < 25; ++i) {
		for (n = 0; n < 4; ++n) {
			putchar(x[i][1] - (0x7F & x[i][0] >> 8 * n));
		};
	};
	p_t(ht);
	return 0;
}
