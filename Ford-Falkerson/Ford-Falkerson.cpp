#include <iostream.h>
#include <memory.h>
#include <stdio.h>
#include <conio.h>
char* rus (char* st
{
unsigned char* p = st;
while (*p)
{
if (*p >= 192)
if (*p<=239)
*p -= 64;
else
*p -= 16;
p++;
}
return st;
}
const int MAX_VERTICES = 40;
int NUM_VERTICES; 
const int INFINITY = 10000; 
int f[MAX_VERTICES][MAX_VERTICES];
int c[MAX_VERTICES][MAX_VERTICES];
int Flow[MAX_VERTICES];
int Link[MAX_VERTICES]; 
int Queue[MAX_VERTICES]; int QP, QC; 
int FindPath(int source, int target) 
{
QP = 0; QC = 1; Queue[0] = source;
Link[target] = -1; // ������ ����� ��� �����
int i;
int CurVertex;
memset(Flow, 0, sizeof(int)*NUM_VERTICES); 
Flow[source] = INFINITY; 
while (Link[target] == -1 && QP < QC)
{
CurVertex = Queue[QP];
for (i=0; i<NUM_VERTICES; i++)
if ((c[CurVertex][i] - f[CurVertex][i])>0 && Flow[i] == 0) 
{
Queue[QC] = i; QC++;
Link[i] = CurVertex; 
if (c[CurVertex][i]-f[CurVertex][i] < Flow[CurVertex])
Flow[i] = c[CurVertex][i];
else
Flow[i] = Flow[CurVertex];
}
QP++; 
}
if (Link[target] == -1) return 0; 
CurVertex = target;
while (CurVertex != source) 
{
f[Link[CurVertex]][CurVertex] +=Flow[target];
CurVertex = Link[CurVertex];
}
return Flow[target]; 
}
int MaxFlow(int source, int target) // source - �����, target - ����
{
memset(f, 0, sizeof(int)*MAX_VERTICES*MAX_VERTICES); 
int MaxFlow = 0; 
int AddFlow;
do
{
AddFlow = FindPath(source, target);
MaxFlow += AddFlow;
} while (AddFlow >0); 
return MaxFlow;
}
int main()
{
printf(rus("\n ���������� ������������� ������ \n"));
printf(rus("\n �������� �����-���������� \n\n"));
printf(rus("\n �������� ������ �� ���������� ���������� \n"));
printf(rus("\n ��������: ������ �.�. \n\n"));
printf(rus("\n\n ������� ����� ������� ��� �����������...."));
getch();
clrscr();
int source, target;
printf(rus("\n ������� ����� ������ � �����\n-->"));
scanf("%d", &NUM_VERTICES);
printf(rus("\n ������� �������� ������ � ����� \n-->"));
scanf("%d %d", &source, &target);
printf(rus("\n ������� ������� ���������� ����������� �����: \n "));
printf(rus("������ ������� - ����������� ����� �������� \n �� ������� � ������� ��� ������ � ������� � ������� ��� �������\n"));
int i, j;
for (i=0; i<NUM_VERTICES; i++)
for (j=0; j<NUM_VERTICES; j++)
scanf("%d",&c[i][j]);
printf(rus("\n ������������ ����� �����:"));
printf("%d", MaxFlow(source, target));
getch();
return 0;
}
