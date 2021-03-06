#include <stdio.h>
#include <stdlib.h>

struct Ponto{
    int x;
    int y;
};
typedef struct Ponto ponto;

int calc(ponto a, ponto b, ponto p){
    int result;

    result = (((a.x - p.x)*(b.y - p.y)) - ((b.x - p.x)*(a.y - p.y)));

    return result;
}


int main()
{

    int resultado = 1, i, j, tipoOperacao;
    char screen[480][640];

    ponto P, s, p1, p2, p3;

    FILE *inPoints = fopen("TestPoints.txt", "r");
    FILE *in = fopen("TrianglePoints.txt", "r");
    FILE *out = fopen("Out.txt", "w");

    if (inPoints == NULL || in == NULL || out == NULL)
        perror("Erro ao abrir arquivo Clientes.\n");
    else{

        while (fscanf(inPoints, " %d %d\n", &P.x, &P.y) != EOF){
            while (fscanf(in, "%d %d %d %d %d %d\n", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) != EOF){

                if (calc(p1, p2, p3) <= 0) tipoOperacao = 0;
                else tipoOperacao = 1;


                resultado = 1;
                if (tipoOperacao == 0) {
                    if (calc(p1, p2, P) > 0) resultado = 0;
                    if (calc(p2, p3, P) > 0) resultado = 0;
                    if (calc(p3, p1, P) > 0) resultado = 0;
                }
                else {
                    if (calc(p1, p2, P) < 0) resultado = 0;
                    if (calc(p2, p3, P) < 0) resultado = 0;
                    if (calc(p3, p1, P) < 0) resultado = 0;
                }

                fprintf(out, "%d\n", resultado);


                for (i=0; i<480; i++){
                    for(j=0; j<640; j++){
                        resultado = 1;
                        s.x = j;
                        s.y = i;
                        if (tipoOperacao == 0) {
                            if (calc(p1, p2, s) > 0) resultado = 0;
                            if (calc(p2, p3, s) > 0) resultado = 0;
                            if (calc(p3, p1, s) > 0) resultado = 0;
                        }
                        else {
                            if (calc(p1, p2, s) < 0) resultado = 0;
                            if (calc(p2, p3, s) < 0) resultado = 0;
                            if (calc(p3, p1, s) < 0) resultado = 0;
                        }

                        if (resultado == 1){
                            screen[i][j] = '.';
                        }
                        else screen[i][j] = ' ';
                    }
                }


                screen[p1.y][p1.x] = 'A';
                screen[p2.y][p2.x] = 'B';
                screen[p3.y][p3.x] = 'C';
                screen[P.y][P.x] = 'P';

                /*//ATUALIZAR TELA
                for (i=0; i<480; i++){
                    for(j=0; j<640; j++){
                        printf("%c ", screen[i][j]);
                    }
                    printf("\n");
                }*/
            }
            rewind(in);
        }
    }

    fclose(inPoints);
    fclose(in);
    fclose(out);

    return 0;
}
