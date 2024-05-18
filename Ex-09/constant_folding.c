#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char s[20];
    char flag[20] = "//Constant";
    char result, equal, operator;
    double op1, op2, interrslt;
    int a;
    FILE *fp1, *fp2;

    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");

    fscanf(fp1, "%s", s);
    fprintf(fp2, "255 - SOWMIYA S \n");
    while (!feof(fp1)) {
        if (strcmp(s, flag) == 0) {
            fscanf(fp1, "%s", s); // Read the next line
            result = s[0];
            equal = s[1];
            if (isdigit(s[2]) && isdigit(s[4])) {
                if (s[3] == '+' || s[3] == '-' || s[3] == '*' || s[3] == '/') {
                    operator = s[3];
                    op1 = s[2] - '0';
                    op2 = s[4] - '0';
                    switch (operator) {
                        case '+':
                            interrslt = op1 + op2;
                            break;
                        case '-':
                            interrslt = op1 - op2;
                            break;
                        case '*':
                            interrslt = op1 * op2;
                            break;
                        case '/':
                            if (op2 != 0)
                                interrslt = op1 / op2;
                            else {
                                fprintf(fp2, "Error: Division by zero\n");
                                break;
                            }
                            break;
                        default:
                            interrslt = 0;
                            break;
                    }
                    
                    fprintf(fp2, "/Constant Folding/\n");
                    fprintf(fp2, "%c = %lf\n", result, interrslt);
                }
            } else {
                fprintf(fp2, "Not Optimized\n");
            }
        } else {
            fprintf(fp2, "%s\n", s);
        }
        fscanf(fp1, "%s", s);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
