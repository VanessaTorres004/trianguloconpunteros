#include <stdio.h>
#include <math.h>

float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2); 
float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f); 
float calcularArea(float a, float b, float c, float d, float e, float f); 
float calcularAreaSuperficial(float a, float b, float c, float d, float e, float f); 
float calcularVolumen(float a, float b, float c, float d, float e, float f);
int main(int argc, char *argv[])
{
	
	float puntos[4][3]={{0,0,0},{0,0,3},{3,0,0},{1,7,1}};
	float a,b,c,d,e,f;
	float perimetro = calcularPerimetro(puntos,&a,&b,&c,&d,&e,&f);
	printf("El perimetro de la piramide es %f\n", perimetro);
	float areaSuperficial = calcularAreaSuperficial(a,b,c,d,e,f);
	printf("El area superficial de la piramide es %f\n", areaSuperficial);
	float volumen = calcularVolumen(a,b,c,d,e,f);
	printf("El volumen de la piramide es %f\n", volumen);
	
	return 0;
}

float calcularDistancias(float x1, float y1, float z1, float x2, float y2, float z2){
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
}
	
	float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f){
		*a = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[1][0],puntos[1][1],puntos[1][2]);
		*b = calcularDistancias(puntos[1][0],puntos[1][1],puntos[1][2],puntos[2][0],puntos[2][1],puntos[2][2]);
		*c = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[2][0],puntos[2][1],puntos[2][2]);
		
		*d = calcularDistancias(puntos[0][0],puntos[0][1],puntos[0][2],puntos[3][0],puntos[3][1],puntos[3][2]);
		*e = calcularDistancias(puntos[1][0],puntos[1][1],puntos[1][2],puntos[3][0],puntos[3][1],puntos[3][2]);
		*f = calcularDistancias(puntos[2][0],puntos[2][1],puntos[2][2],puntos[3][0],puntos[3][1],puntos[3][2]);
		
		float per=*a+*b+*c+*d+*e+*f;
		return per;
	}
		float calcularArea(float a, float b, float c, float d, float e, float f){
			float s = (a+b+c+d+e+f)/2;
			float area =sqrt(s*(s-a)*(s-b)*(s-c)*(s-d)*(s-e)*(s-f));
			
			return area;
		}

		
			
		float calcularAreaSuperficial(float a, float b, float c, float d, float e, float f){
		float areabase = (a,b,c);
		float area1 = (a,e,d);
		float area2 = (c,e,f);
		float area3 = (b, d ,f);
		float areaSuperficial=areabase+area1+area2+area3;
		return areaSuperficial;
		}
void calcularBaricentro(float puntos[4][3], float baricentro[3]){
    baricentro[0] = (puntos[0][0] + puntos[1][0] + puntos[2][0]) / 3;
    baricentro[1] = (puntos[0][1] + puntos[1][1] + puntos[2][1]) / 3;
    baricentro[2] = (puntos[0][2] + puntos[1][2] + puntos[2][2]) / 3;
}

float calcularVolumen(float a, float b, float c, float puntos[4][3]){
    float areabase = calcularArea(a, b, c);
    float baricentro[3];
    calcularBaricentro(puntos, baricentro);
    float altura = calcularDistancias(baricentro[0], baricentro[1], baricentro[2], puntos[3][0], puntos[3][1], puntos[3][2]);
    float volumen = (areabase * altura) / 3;
    return volumen;
}
		
			
			
