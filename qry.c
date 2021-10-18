#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "qry.h"

void o(char j[], char k[], char id[], char cor1[], char cor2[], FILE* saida, Lista listasQry[], Lista listaObjeto[])
{
    Info info1;
    Info info2;

    if(buscarCirculo(listaObjeto, j) != NULL && buscarCirculo(listaObjeto, k) != NULL)
    {
        info1 = getInfo(buscarCirculo(listaObjeto, j));
        info2 = getInfo(buscarCirculo(listaObjeto, k));
        circuloInt(info1, info2, saida, listasQry, id, cor1, cor2);
    }
    else if(buscarCirculo(listaObjeto, j) != NULL && buscarRetangulo(listaObjeto, k) != NULL)
    {
        info1 = getInfo(buscarCirculo(listaObjeto, j));
        info2 = getInfo(buscarRetangulo(listaObjeto, k));
        retanguloxCirculo(info1, info2, saida, listasQry, id, cor1, cor2);
    }
    else if(buscarRetangulo(listaObjeto, j) != NULL && buscarCirculo(listaObjeto, k) != NULL)
    {
        info1 = getInfo(buscarRetangulo(listaObjeto, j));
        info2 = getInfo(buscarCirculo(listaObjeto, k));
        retanguloxCirculo(info2, info1, saida, listasQry, id, cor1, cor2);
    }
    else if(buscarRetangulo(listaObjeto, j) != NULL && buscarRetangulo(listaObjeto, k) != NULL)
    {
        info1 = getInfo(buscarRetangulo(listaObjeto, j));
        info2 = getInfo(buscarRetangulo(listaObjeto, k));
        retanguloInt(info1, info2, saida, listasQry, id, cor1, cor2);
    }
}

void retanguloInt(Info r1, Info r2, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[])
{
    float x,w,y,h;

    x = min(getRetanguloX(r1),getRetanguloX(r2));
    w = max(getRetanguloX(r1) + getRetanguloW(r1),getRetanguloX(r2) + getRetanguloW(r2)) - x;
    y = min(getRetanguloY(r1),getRetanguloY(r2));
    h = max(getRetanguloY(r1) + getRetanguloH(r1),getRetanguloY(r2) + getRetanguloH(r2)) - y;

    Linha linha = criaLinha(id, getRetanguloX(r1), getRetanguloY(r1), getRetanguloX(r2), getRetanguloY(r2), "black");
    insert(listasQry[2], linha);

    if (w <= getRetanguloW(r1) + getRetanguloW(r2) && h <= getRetanguloH(r1) + getRetanguloH(r2))
    {
        fprintf(saida,"%s: retangulo %s: retangulo SIM\n", getRetanguloI(r1),getRetanguloI(r2));
        setRetanguloCorp(r1, cor1);
        setRetanguloCorp(r2, cor1);
    }
    else
    {
        fprintf(saida,"%s: retangulo %s: retangulo NAO\n", getRetanguloI(r1),getRetanguloI(r2));
        setRetanguloCorp(r1, cor2);
        setRetanguloCorp(r2, cor2);
    }
}

void circuloInt(Info c1, Info c2, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[])
{
    float dist;

    dist = distancia(getCirculoX(c1), getCirculoY(c1), getCirculoX(c2), getCirculoY(c2));

    Linha linha = criaLinha(id, getCirculoX(c1), getCirculoY(c1),  getCirculoX(c2), getCirculoY(c2), "black");
    insert(listasQry[2], linha);

    if(dist <= getCirculoR(c2) + getCirculoR(c1))
    {
        fprintf(saida,"%s: circulo %s: circulo SIM\n", getCirculoI(c1),getCirculoI(c2));
        setCirculoCorp(c1, cor1);
        setCirculoCorp(c2, cor1);

    }
    else
    {
        fprintf(saida,"%s: circulo %s: circulo NAO\n",getCirculoI(c1),getCirculoI(c2));
        setCirculoCorp(c1, cor2);
        setCirculoCorp(c2, cor2);

    }
}

void retanguloxCirculo(Info circ, Info ret, FILE* saida, Lista listasQry[], char id[], char cor1[], char cor2[])
{
    float deltaX, deltaY;

    if(getCirculoX(circ) > getRetanguloX(ret))
    {
        deltaX = pow(getRetanguloX(ret) + getRetanguloW(ret) - getCirculoX(ret),2);
    }
    else
    {
        deltaX = pow(getRetanguloX(ret) - getCirculoX(circ),2);
    }
    if(getCirculoY(circ) > getRetanguloY(ret))
    {
        deltaY = pow(getRetanguloY(ret) + getRetanguloH(ret) - getCirculoY(circ),2);
    }
    else
    {
        deltaY = pow(getRetanguloY(ret) - getCirculoY(circ),2);
    }

    Linha linha = criaLinha(id, getRetanguloX(ret), getRetanguloY(ret), getCirculoX(circ), getCirculoY(circ), "black");
    insert(listasQry[2], linha);

    if(sqrt(deltaX + deltaY) <= getCirculoR(circ))
    {
        fprintf(saida,"%s: circulo %s: retangulo SIM\n", getCirculoI(circ), getRetanguloI(ret));
        setCirculoCorp(circ, cor1);
        setRetanguloCorp(ret, cor1);
    }
    else
    {
        fprintf(saida,"%s: circulo %s: retangulo NAO\n", getCirculoI(circ), getRetanguloI(ret));
        setCirculoCorp(circ, cor2);
        setRetanguloCorp(ret, cor2);

    }
}

void i(Lista listaObjeto[], char j[],  double x, double y, FILE* saida, Lista listasQry[])
{
    No no = buscarCirculo(listaObjeto, j);

    if(no != NULL)
    {
        Info c = getInfo(no);

        if(getCirculoR(c) >= distancia(x, y, getCirculoX(c), getCirculoY(c)))
        {
            fprintf(saida,"CIRCULO: Ponto interno\n");

            Circulo circ = criaCirculo("0", 2, x, y, "1", "blue", "blue");
            insert(listasQry[0], circ);

            Linha lin = criaLinha("0", x, y, getCirculoX(c), getCirculoY(c), "blue");
            insert(listasQry[2], lin);
        }
        else
        {
            fprintf(saida,"CIRCULO: Ponto não interno\n");

            Circulo circ = criaCirculo("0", 2, x, y, "1", "magenta", "magenta");
            insert(listasQry[0], circ);

            Linha lin = criaLinha("0", x, y, getCirculoX(c), getCirculoY(c), "magenta");
            insert(listasQry[2], lin);
        }
    }

    no = buscarRetangulo(listaObjeto, j);

    if(no != NULL)
    {
        Info  r = getInfo(no);
        float difx = x - getRetanguloX(r);
        float dify = y - getRetanguloY(r);

        if(difx >= 0 && difx <= getRetanguloW(r) && dify >= 0 && dify <= getRetanguloH(r))
        {
            fprintf(saida,"RETANGULO: Ponto interno\n");

            Circulo circ = criaCirculo("0", 2, x, y, "1", "blue", "blue");
            insert(listasQry[0], circ);
            Linha lin = criaLinha("0", x, y, getRetanguloX(r) + getRetanguloW(r)/2, getRetanguloY(r) + getRetanguloH(r)/2, "blue");
            insert(listasQry[2], lin);
        }
        else
        {
            fprintf(saida,"RETANGULO: Ponto não interno\n");

            Circulo circ = criaCirculo("0", 2, x, y, "1", "magenta", "magenta");
            insert(listasQry[0], circ);
            Linha lin = criaLinha("0", x, y, getRetanguloX(r) + getRetanguloW(r)/2, getRetanguloY(r) + getRetanguloH(r)/2, "magenta");
            insert(listasQry[2], lin);
        }
    }

}

void pnt(Lista listaObjeto[], char j[], char corb[], char corp[], FILE* saida)
{
    No no = buscarCirculo(listaObjeto, j);

    if(no != NULL && getInfo(no) != NULL)
    {
        Info c = getInfo(no);
        fprintf(saida,"%lf %lf\n", getCirculoX(c), getCirculoY(c));
        setCirculoCorb(c, corb);
        setCirculoCorp(c, corp);
    }

    no = buscarRetangulo(listaObjeto, j);

    if(no != NULL && getInfo(no) != NULL)
    {
        Info r = getInfo(no);

        fprintf(saida,"%lf %lf\n", getRetanguloX(r), getRetanguloY(r));
        setRetanguloCorb(r, corb);
        setRetanguloCorp(r, corp);
    }
    
    no = buscarTexto(listaObjeto, j);

    if(no != NULL && getInfo(no) != NULL)
    {
        Info t = getInfo(no);

        fprintf(saida,"%lf %lf\n", getTextoX(t), getTextoY(t));
        setTextoCorb(t, corb);
        setTextoCorp(t, corp);
    }
}

void delf(Lista listaObjeto[], char j[], FILE* saida)
{
    if(buscarCirculo(listaObjeto, j) != NULL)
    {
        No cc = buscarCirculo(listaObjeto, j);
        Info c = getInfo(cc);
        fprintf(saida,"ID:%s R:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getCirculoI(c), getCirculoR(c), getCirculoX(c), getCirculoY(c), getCirculoCorb(c), getCirculoCorp(c));
        removerNo(listaObjeto[0], cc, NULL);
    }
    else if(buscarRetangulo(listaObjeto, j) != NULL)
    {
        No rr = buscarRetangulo(listaObjeto, j);
        Info r = getInfo(rr);
        fprintf(saida,"ID:%s W:%lf H:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getCirculoI(r), getRetanguloW(r), getRetanguloH(r), getRetanguloX(r), getRetanguloY(r), getRetanguloCorb(r), getRetanguloCorp(r));
        removerNo(listaObjeto[1], rr, NULL);
    }
    else if(buscarLinha(listaObjeto, j) != NULL)
    {
        No ll = buscarLinha(listaObjeto, j);
        Info l = getInfo(ll);
        fprintf(saida,"ID:%s X1:%lf X2:%lf Y1:%lf Y2:%lf COR:%s\n",getLinhaId(l), getLinhaX1(l), getLinhaX2(l), getLinhaY1(l), getLinhaY2(l), getLinhaCor(l));
        removerNo(listaObjeto[2], ll, NULL);
    }
    else if(buscarTexto(listaObjeto, j) != NULL)
    {
        No tt = buscarTexto(listaObjeto, j);
        Info t = getInfo(tt);
        fprintf(saida,"ID:%s X:%lf Y:%lf CORB:%s CORP:%s TEXTO:%s\n",getTextoI(t), getTextoX(t), getTextoY(t), getTextoCorb(t), getTextoCorp(t), getTextoTxto(t));
        removerNo(listaObjeto[3], tt, NULL);
    }
}

void psh(Lista listaObjeto[], char j[], Pilha pilha)
{
    if(buscarCirculo(listaObjeto, j) != NULL && getInfo(buscarCirculo(listaObjeto, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaObjeto, j));
        empilhar(pilha, c);
    }
    else if(buscarRetangulo(listaObjeto, j) != NULL && getInfo(buscarRetangulo(listaObjeto, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaObjeto, j));
        empilhar(pilha, r);        
    }
    else if(buscarLinha(listaObjeto, j) != NULL && getInfo(buscarLinha(listaObjeto, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaObjeto, j));
        empilhar(pilha, l);
    }
    else if(buscarTexto(listaObjeto, j) != NULL && getInfo(buscarTexto(listaObjeto, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaObjeto, j));
        empilhar(pilha, t);        
    }
}

void pshQ(Lista listaQry[], char j[], Pilha pilha)
{
    if(buscarCirculo(listaQry, j) != NULL && getInfo(buscarCirculo(listaQry, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaQry, j));
        empilhar(pilha, c);
    }
    else if(buscarRetangulo(listaQry, j) != NULL && getInfo(buscarRetangulo(listaQry, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaQry, j));
        empilhar(pilha, r);        
    }
    else if(buscarLinha(listaQry, j) != NULL && getInfo(buscarLinha(listaQry, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaQry, j));
        empilhar(pilha, l);
    }
    else if(buscarTexto(listaQry, j) != NULL && getInfo(buscarTexto(listaQry, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaQry, j));
        empilhar(pilha, t);        
    }
}

void pop(Lista listaQry[], Lista listaObjeto[], Pilha pilha, double dx, double dy, double prop, char i[], FILE *saida)
{
    Info notInfo = desempilha(pilha);
    double x;
    double y;
    
    if(buscarCirculo(listaObjeto, getCirculoI(notInfo)) != NULL)
    {
        double r;
        x = getCirculoX(notInfo);
        y = getCirculoY(notInfo);
        if(prop == 1.0)
        {
            r = getCirculoR(notInfo);
        }
        if(prop > 1.0)
        {
            r = getCirculoR(notInfo)*prop;
        }
        if(prop < 1.0)
        {
            r = getCirculoR(notInfo)/prop;
        }

        Circulo c = criaCirculo(i, r, x+dx, y+dy, "2", getCirculoCorp(notInfo), getCirculoCorb(notInfo));
        insert(listaQry[0], c);
        fprintf(saida,"ID:%s R:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getCirculoI(notInfo), getCirculoR(notInfo), getCirculoX(notInfo), getCirculoY(notInfo), getCirculoCorb(notInfo), getCirculoCorp(notInfo));
    }
    else if(buscarCirculo(listaQry, getCirculoI(notInfo)) != NULL)
    {
        double r;
        x = getCirculoX(notInfo);
        y = getCirculoY(notInfo);
        if(prop == 1.0)
        {
            r = getCirculoR(notInfo);
        }
        if(prop > 1.0)
        {
            r = getCirculoR(notInfo)*prop;
        }
        if(prop < 1.0)
        {
            r = getCirculoR(notInfo)/prop;
        }

        Circulo c = criaCirculo(i, r, x+dx, y+dy, "2", getCirculoCorp(notInfo), getCirculoCorb(notInfo));
        insert(listaQry[0], c);
        fprintf(saida,"ID:%s R:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getCirculoI(notInfo), getCirculoR(notInfo), getCirculoX(notInfo), getCirculoY(notInfo), getCirculoCorb(notInfo), getCirculoCorp(notInfo));
    }
    else if(buscarRetangulo(listaObjeto, getRetanguloI(notInfo)) != NULL)
    {
        double w;
        double h;
        x = getRetanguloX(notInfo);
        y = getRetanguloY(notInfo);
        if(prop == 1.0)
        {
            w = getRetanguloW(notInfo);
            h = getRetanguloH(notInfo);
        }
        if(prop > 1.0)
        {
            w = getRetanguloW(notInfo)*prop;
            h = getRetanguloH(notInfo)*prop;
        }
        if(prop < 1.0)
        {
            w = getRetanguloW(notInfo)/prop;
            h = getRetanguloH(notInfo)/prop;
        }

        Retangulo r = criaRetangulo(i, w, h, x+dx, y+dy, "2", getRetanguloCorp(notInfo), getRetanguloCorb(notInfo));
        insert(listaQry[1], r);
        fprintf(saida,"ID:%s W:%lf H:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getRetanguloI(notInfo), getRetanguloW(notInfo), getRetanguloH(notInfo), getRetanguloX(notInfo), getRetanguloY(notInfo), getRetanguloCorb(notInfo), getRetanguloCorp(notInfo));
    }
    else if(buscarRetangulo(listaQry, getRetanguloI(notInfo)) != NULL)
    {
        double w;
        double h;
        x = getRetanguloX(notInfo);
        y = getRetanguloY(notInfo);
        if(prop == 1.0)
        {
            w = getRetanguloW(notInfo);
            h = getRetanguloH(notInfo);
        }
        if(prop > 1.0)
        {
            w = getRetanguloW(notInfo)*prop;
            h = getRetanguloH(notInfo)*prop;
        }
        if(prop < 1.0)
        {
            w = getRetanguloW(notInfo)/prop;
            h = getRetanguloH(notInfo)/prop;
        }

        Retangulo r = criaRetangulo(i, w, h, x+dx, y+dy, "2", getRetanguloCorp(notInfo), getRetanguloCorb(notInfo));
        insert(listaQry[1], r);
        fprintf(saida,"ID:%s W:%lf H:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getRetanguloI(notInfo), getRetanguloW(notInfo), getRetanguloH(notInfo), getRetanguloX(notInfo), getRetanguloY(notInfo), getRetanguloCorb(notInfo), getRetanguloCorp(notInfo));
    }
    else if(buscarLinha(listaObjeto, getLinhaId(notInfo)) != NULL)
    {
        x = getLinhaX1(notInfo);
        y = getLinhaY1(notInfo);
        double x2 = getLinhaX2(notInfo);
        double y2 = getLinhaY2(notInfo);
        Linha l = criaLinha(i, x+dx, y+dy, x2+dx, y2+dy, getLinhaCor(notInfo));
        insert(listaQry[2], l);
        fprintf(saida,"ID:%s X1:%lf X2:%lf Y1:%lf Y2:%lf COR:%s\n",getLinhaId(notInfo), getLinhaX1(notInfo), getLinhaX2(notInfo), getLinhaY1(notInfo), getLinhaY2(notInfo), getLinhaCor(notInfo));
    }
    else if(buscarLinha(listaQry, getLinhaId(notInfo)) != NULL)
    {
        x = getLinhaX1(notInfo);
        y = getLinhaY1(notInfo);
        double x2 = getLinhaX2(notInfo);
        double y2 = getLinhaY2(notInfo);
        Linha l = criaLinha(i, x+dx, y+dy, x2+dx, y2+dy, getLinhaCor(notInfo));
        insert(listaQry[2], l);
        fprintf(saida,"ID:%s X1:%lf X2:%lf Y1:%lf Y2:%lf COR:%s\n",getLinhaId(notInfo), getLinhaX1(notInfo), getLinhaX2(notInfo), getLinhaY1(notInfo), getLinhaY2(notInfo), getLinhaCor(notInfo));
    }
    else if(buscarTexto(listaObjeto, getTextoI(notInfo)) != NULL)
    {
        x = getTextoX(notInfo);
        y = getTextoY(notInfo);
        Texto t = criaTexto(i, x+dx, y+dy, getTextoCorp(notInfo), getTextoCorb(notInfo), getTextoTxto(notInfo));
        insert(listaQry[3], t);
        fprintf(saida,"ID:%s X:%lf Y:%lf CORB:%s CORP:%s TEXTO:%s\n",getTextoI(notInfo), getTextoX(notInfo), getTextoY(notInfo), getTextoCorb(notInfo), getTextoCorp(notInfo), getTextoTxto(notInfo));
    }
    else if(buscarTexto(listaObjeto, getTextoI(notInfo)) != NULL)
    {
        x = getTextoX(notInfo);
        y = getTextoY(notInfo);
        Texto t = criaTexto(i, x+dx, y+dy, getTextoCorp(notInfo), getTextoCorb(notInfo), getTextoTxto(notInfo));
        insert(listaQry[3], t);
        fprintf(saida,"ID:%s X:%lf Y:%lf CORB:%s CORP:%s TEXTO:%s\n",getTextoI(notInfo), getTextoX(notInfo), getTextoY(notInfo), getTextoCorb(notInfo), getTextoCorp(notInfo), getTextoTxto(notInfo));
    }

}

void inf(Lista listaObjeto[], char j[], Fila fila)
{
    if(buscarCirculo(listaObjeto, j) != NULL && getInfo(buscarCirculo(listaObjeto, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaObjeto, j));
        insereFila(fila, c);
    }
    else if(buscarRetangulo(listaObjeto, j) != NULL && getInfo(buscarRetangulo(listaObjeto, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaObjeto, j));
        insereFila(fila, r);       
    }
    else if(buscarLinha(listaObjeto, j) != NULL && getInfo(buscarLinha(listaObjeto, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaObjeto, j));
        insereFila(fila, l);
    }
    else if(buscarTexto(listaObjeto, j) != NULL && getInfo(buscarTexto(listaObjeto, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaObjeto, j));
        insereFila(fila, t);       
    }
}

void infQ(Lista listaQry[], char j[], Fila fila)
{
    if(buscarCirculo(listaQry, j) != NULL && getInfo(buscarCirculo(listaQry, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaQry, j));
        insereFila(fila, c);
    }
    else if(buscarRetangulo(listaQry, j) != NULL && getInfo(buscarRetangulo(listaQry, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaQry, j));
        insereFila(fila, r);   
    }
    else if(buscarLinha(listaQry, j) != NULL && getInfo(buscarLinha(listaQry, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaQry, j));
        insereFila(fila, l);
    }
    else if(buscarTexto(listaQry, j) != NULL && getInfo(buscarTexto(listaQry, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaQry, j));
        insereFila(fila, t);         
    }
}

void rmf(Lista listaQry[], Lista listaObjeto[], Fila fila, double dx, double dy, double prop, char i[], FILE *saida)
{
    Info notInfo = retiraFila(fila);
    double x;
    double y;

    if(buscarCirculo(listaObjeto, getCirculoI(notInfo)) != NULL)
    {
        double r;
        x = getCirculoX(notInfo);
        y = getCirculoY(notInfo);

        if(prop == 1.0)
        {
            r = getCirculoR(notInfo);
        }
        if(prop > 1.0)
        {
            r = getCirculoR(notInfo)*prop;
        }
        if(prop < 1.0)
        {
            r = getCirculoR(notInfo)/prop;
        }
        
        Circulo c = criaCirculo(i, r, x+dx, y+dy, "2", getCirculoCorp(notInfo), getCirculoCorb(notInfo));
        insert(listaQry[0], c);
        fprintf(saida,"ID:%s R:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getCirculoI(notInfo), getCirculoR(notInfo), getCirculoX(notInfo), getCirculoY(notInfo), getCirculoCorb(notInfo), getCirculoCorp(notInfo));
    }
    else if(buscarCirculo(listaQry, getCirculoI(notInfo)) != NULL)
    {
        double r;
        x = getCirculoX(notInfo);
        y = getCirculoY(notInfo);

        if(prop == 1.0)
        {
            r = getCirculoR(notInfo);
        }
        if(prop > 1.0)
        {
            r = getCirculoR(notInfo)*prop;
        }
        if(prop < 1.0)
        {
            r = getCirculoR(notInfo)/prop;
        }
        
        Circulo c = criaCirculo(i, r, x+dx, y+dy, "2", getCirculoCorp(notInfo), getCirculoCorb(notInfo));
        insert(listaQry[0], c);
        fprintf(saida,"ID:%s R:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getCirculoI(notInfo), getCirculoR(notInfo), getCirculoX(notInfo), getCirculoY(notInfo), getCirculoCorb(notInfo), getCirculoCorp(notInfo));
    }
    else if(buscarRetangulo(listaObjeto, getRetanguloI(notInfo)) != NULL)
    {
        double w;
        double h;
        x = getRetanguloX(notInfo);
        y = getRetanguloY(notInfo);
        if(prop == 1.0)
        {
            w = getRetanguloW(notInfo);
            h = getRetanguloH(notInfo);
        }
        if(prop > 1.0)
        {
            w = getRetanguloW(notInfo)*prop;
            h = getRetanguloH(notInfo)*prop;
        }
        if(prop < 1.0)
        {
            w = getRetanguloW(notInfo)/prop;
            h = getRetanguloH(notInfo)/prop;
        }

        Retangulo r = criaRetangulo(i, w, h, x+dx, y+dy, "2", getRetanguloCorp(notInfo), getRetanguloCorb(notInfo));
        insert(listaQry[1], r);
        fprintf(saida,"ID:%s W:%lf H:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getRetanguloI(notInfo), getRetanguloW(notInfo), getRetanguloH(notInfo), getRetanguloX(notInfo), getRetanguloY(notInfo), getRetanguloCorb(notInfo), getRetanguloCorp(notInfo));
    }
    else if(buscarRetangulo(listaQry, getRetanguloI(notInfo)) != NULL)
    {
        double w;
        double h;
        x = getRetanguloX(notInfo);
        y = getRetanguloY(notInfo);
        if(prop == 1.0)
        {
            w = getRetanguloW(notInfo);
            h = getRetanguloH(notInfo);
        }
        if(prop > 1.0)
        {
            w = getRetanguloW(notInfo)*prop;
            h = getRetanguloH(notInfo)*prop;
        }
        if(prop < 1.0)
        {
            w = getRetanguloW(notInfo)/prop;
            h = getRetanguloH(notInfo)/prop;
        }

        Retangulo r = criaRetangulo(i, w, h, x+dx, y+dy, "2", getRetanguloCorp(notInfo), getRetanguloCorb(notInfo));
        insert(listaQry[1], r);
        fprintf(saida,"ID:%s W:%lf H:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getRetanguloI(notInfo), getRetanguloW(notInfo), getRetanguloH(notInfo), getRetanguloX(notInfo), getRetanguloY(notInfo), getRetanguloCorb(notInfo), getRetanguloCorp(notInfo));
    }
    else if(buscarLinha(listaObjeto, getLinhaId(notInfo)) != NULL)
    {
        x = getLinhaX1(notInfo);
        y = getLinhaY1(notInfo);
        double x2 = getLinhaX2(notInfo);
        double y2 = getLinhaY2(notInfo);
        Linha l = criaLinha(i, x+dx, y+dy, x2+dx, y2+dy, getLinhaCor(notInfo));
        insert(listaQry[2], l);
        fprintf(saida,"ID:%s X1:%lf X2:%lf Y1:%lf Y2:%lf COR:%s\n",getLinhaId(notInfo), getLinhaX1(notInfo), getLinhaX2(notInfo), getLinhaY1(notInfo), getLinhaY2(notInfo), getLinhaCor(notInfo));
    }
    else if(buscarLinha(listaQry, getLinhaId(notInfo)) != NULL)
    {
        x = getLinhaX1(notInfo);
        y = getLinhaY1(notInfo);
        double x2 = getLinhaX2(notInfo);
        double y2 = getLinhaY2(notInfo);
        Linha l = criaLinha(i, x+dx, y+dy, x2+dx, y2+dy, getLinhaCor(notInfo));
        insert(listaQry[2], l);
        fprintf(saida,"ID:%s X1:%lf X2:%lf Y1:%lf Y2:%lf COR:%s\n",getLinhaId(notInfo), getLinhaX1(notInfo), getLinhaX2(notInfo), getLinhaY1(notInfo), getLinhaY2(notInfo), getLinhaCor(notInfo));
    }
    else if(buscarTexto(listaObjeto, getTextoI(notInfo)) != NULL)
    {
        x = getTextoX(notInfo);
        y = getTextoY(notInfo);
        Texto t = criaTexto(i, x+dx, y+dy, getTextoCorp(notInfo), getTextoCorb(notInfo), getTextoTxto(notInfo));
        insert(listaQry[3], t);
        fprintf(saida,"ID:%s X:%lf Y:%lf CORB:%s CORP:%s TEXTO:%s\n",getTextoI(notInfo), getTextoX(notInfo), getTextoY(notInfo), getTextoCorb(notInfo), getTextoCorp(notInfo), getTextoTxto(notInfo));
    }
    else if(buscarTexto(listaObjeto, getTextoI(notInfo)) != NULL)
    {
        x = getTextoX(notInfo);
        y = getTextoY(notInfo);
        Texto t = criaTexto(i, x+dx, y+dy, getTextoCorp(notInfo), getTextoCorb(notInfo), getTextoTxto(notInfo));
        insert(listaQry[3], t);
        fprintf(saida,"ID:%s X:%lf Y:%lf CORB:%s CORP:%s TEXTO:%s\n",getTextoI(notInfo), getTextoX(notInfo), getTextoY(notInfo), getTextoCorb(notInfo), getTextoCorp(notInfo), getTextoTxto(notInfo));
    }
}

No ii(Lista listaObjeto[], Lista lista,char j[], No reg)
{
    No regis = reg;
    if(buscarCirculo(listaObjeto, j) != NULL && getInfo(buscarCirculo(listaObjeto, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaObjeto, j));
        regis = insertFirst(lista, c);        
    }
    else if(buscarRetangulo(listaObjeto, j) != NULL && getInfo(buscarRetangulo(listaObjeto, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaObjeto, j));
        regis = insertFirst(lista, r);        
    }
    else if(buscarLinha(listaObjeto, j) != NULL && getInfo(buscarLinha(listaObjeto, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaObjeto, j));
        regis = insertFirst(lista, l);
    }
    else if(buscarTexto(listaObjeto, j) != NULL && getInfo(buscarTexto(listaObjeto, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaObjeto, j));
        regis = insertFirst(lista, t);  
    }

    return regis;
   
}

No iiQ(Lista listaQry[], Lista lista,char j[], No reg)
{
    No regis = reg;

    if(buscarCirculo(listaQry, j) != NULL && getInfo(buscarCirculo(listaQry, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaQry, j));
        regis = insertFirst(lista, c);
    }
    else if(buscarRetangulo(listaQry, j) != NULL && getInfo(buscarRetangulo(listaQry, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaQry, j));
        regis = insertFirst(lista, r); 
    }
    else if(buscarLinha(listaQry, j) != NULL && getInfo(buscarLinha(listaQry, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaQry, j));
        regis = insertFirst(lista, l);
    }
    else if(buscarTexto(listaQry, j) != NULL && getInfo(buscarTexto(listaQry, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaQry, j));
        regis = insertFirst(lista, t);        
    }

    return regis;
}

No iF(Lista listaObjeto[], Lista lista, char j[], No reg)
{
    No regis = reg;

    if(buscarCirculo(listaObjeto, j) != NULL && getInfo(buscarCirculo(listaObjeto, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaObjeto, j));
        regis = insert(lista, c);
    }
    else if(buscarRetangulo(listaObjeto, j) != NULL && getInfo(buscarRetangulo(listaObjeto, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaObjeto, j));
        regis = insert(lista, r);        
    }
    else if(buscarLinha(listaObjeto, j) != NULL && getInfo(buscarLinha(listaObjeto, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaObjeto, j));
        regis = insert(lista, l);
    }
    else if(buscarTexto(listaObjeto, j) != NULL && getInfo(buscarTexto(listaObjeto, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaObjeto, j));
        regis = insert(lista, t);        
    }

    return regis;
}

No iFQ(Lista listaQry[], Lista lista, char j[], No reg)
{
    No regis = reg;

    if(buscarCirculo(listaQry, j) != NULL && getInfo(buscarCirculo(listaQry, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaQry, j));
        regis = insert(lista, c);
    }
    else if(buscarRetangulo(listaQry, j) != NULL && getInfo(buscarRetangulo(listaQry, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaQry, j));
        regis = insert(lista, r);       
    }
    else if(buscarLinha(listaQry, j) != NULL && getInfo(buscarLinha(listaQry, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaQry, j));
        regis = insert(lista, l);
    }
    else if(buscarTexto(listaQry, j) != NULL && getInfo(buscarTexto(listaQry, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaQry, j));
        regis = insert(lista, t);        
    }

    return regis;
}

No ia(Lista listaObjeto[], Lista lista, char j[], No r1, No r)
{
    No r2 = r;
    if(buscarCirculo(listaObjeto, j) != NULL && getInfo(buscarCirculo(listaObjeto, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaObjeto, j));
        r2 = insertBefore(lista, r1, c);
    }
    else if(buscarRetangulo(listaObjeto, j) != NULL && getInfo(buscarRetangulo(listaObjeto, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaObjeto, j));
        r2 = insertBefore(lista, r1, r);        
    }
    else if(buscarLinha(listaObjeto, j) != NULL && getInfo(buscarLinha(listaObjeto, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaObjeto, j));
        r2 = insertBefore(lista, r1, l);
    }
    else if(buscarTexto(listaObjeto, j) != NULL && getInfo(buscarTexto(listaObjeto, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaObjeto, j));
        r2 = insertBefore(lista, r1, t);        
    }

    return r2;
}

No iaQ(Lista listaQry[], Lista lista, char j[], No r1, No r)
{
    No r2 = r;

    if(buscarCirculo(listaQry, j) != NULL && getInfo(buscarCirculo(listaQry, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaQry, j));
        r2 = insertBefore(lista, r1, c);
    }
    else if(buscarRetangulo(listaQry, j) != NULL && getInfo(buscarRetangulo(listaQry, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaQry, j));
        r2 = insertBefore(lista, r1, r);      
    }
    else if(buscarLinha(listaQry, j) != NULL && getInfo(buscarLinha(listaQry, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaQry, j));
        r2 = insertBefore(lista, r1, l);
    }
    else if(buscarTexto(listaQry, j) != NULL && getInfo(buscarTexto(listaQry, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaQry, j));
        r2 = insertBefore(lista, r1, t);        
    }

    return r2;
}

No iD(Lista listaObjeto[], Lista lista, char j[], No r1, No r)
{
    No r2 = r;

    if(buscarCirculo(listaObjeto, j) != NULL && getInfo(buscarCirculo(listaObjeto, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaObjeto, j));
        r2 = insertAfter(lista, r1, c);
    }
    else if(buscarRetangulo(listaObjeto, j) != NULL && getInfo(buscarRetangulo(listaObjeto, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaObjeto, j));
        r2 = insertAfter(lista, r1, r);        
    }
    else if(buscarLinha(listaObjeto, j) != NULL && getInfo(buscarLinha(listaObjeto, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaObjeto, j));
        r2 = insertAfter(lista, r1, l);
    }
    else if(buscarTexto(listaObjeto, j) != NULL && getInfo(buscarTexto(listaObjeto, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaObjeto, j));
        r2 = insertAfter(lista, r1, t);        
    }

    return r2;
}

No idQ(Lista listaQry[], Lista lista, char j[], No r1, No r)
{
    No r2 = r;

    if(buscarCirculo(listaQry, j) != NULL && getInfo(buscarCirculo(listaQry, j)) != NULL)
    {
        Info c = getInfo(buscarCirculo(listaQry, j));
        r2 = insertAfter(lista, r1, c);
    }
    else if(buscarRetangulo(listaQry, j) != NULL && getInfo(buscarRetangulo(listaQry, j)) != NULL)
    {
        Info r = getInfo(buscarRetangulo(listaQry, j));
        r2 = insertAfter(lista, r1, r);      
    }
    else if(buscarLinha(listaQry, j) != NULL && getInfo(buscarLinha(listaQry, j)) != NULL)
    {
        Info l = getInfo(buscarLinha(listaQry, j));
        r2 = insertAfter(lista, r1, l);
    }
    else if(buscarTexto(listaQry, j) != NULL && getInfo(buscarTexto(listaQry, j)) != NULL)
    {
        Info t = getInfo(buscarTexto(listaQry, j));
        r2 = insertAfter(lista, r1, t);        
    }

    return r2;
}

void dpl(Lista listaQry[], Lista lista, double dx, double dy, char i[], double prop, double incprop , FILE *saida)
{
    for(No node = getFirst(lista); node != NULL; node = getNext(node))
    {
        printf("\na");
        double x;
        double y;

        if(strlen(getCirculoCorp(getInfo(node))) != 0)
        {
            double r;
            x = getCirculoX(getInfo(node));
            y = getCirculoY(getInfo(node));
            if(prop == 1.0)
            {
                r = getCirculoR(getInfo(node));
                prop = prop + incprop;
            }
            if(prop > 1.0)
            {
                r = getCirculoR(getInfo(node))*prop;
                prop = prop + incprop;
            }
            if(prop < 1.0)
            {
                r = getCirculoR(getInfo(node))/prop;
                prop = prop + incprop;
            }
            Circulo c = criaCirculo(i, r, x+dx, y+dy, "2", getCirculoCorp(getInfo(node)), getCirculoCorb(getInfo(node)));
            insert(listaQry[0], c);
            fprintf(saida,"ID:%s R:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getCirculoI(getInfo(node)), getCirculoR(getInfo(node)), getCirculoX(getInfo(node)), getCirculoY(getInfo(node)), getCirculoCorb(getInfo(node)), getCirculoCorp(getInfo(node)));
            i++;
        }
        if(strlen(getRetanguloCorp(getInfo(node))) != 0)
        {
            double w;
            double h;

            x = getRetanguloX(getInfo(node));
            y = getRetanguloY(getInfo(node));

            if(prop == 1.0)
            {
                w = getRetanguloW(getInfo(node));
                h = getRetanguloH(getInfo(node));
                prop = prop + incprop;
            }
            if(prop > 1.0)
            {
                w = getRetanguloW(getInfo(node))*prop;
                h = getRetanguloH(getInfo(node))*prop;
                prop = prop + incprop;
            }
            if(prop < 1.0)
            {
                w = getRetanguloW(getInfo(node))/prop;
                h = getRetanguloH(getInfo(node))/prop;
                prop = prop + incprop;
            }

            Retangulo r = criaRetangulo(i, w, h, x+dx, y+dy, "2", getRetanguloCorp(getInfo(node)), getRetanguloCorb(getInfo(node)));
            insert(listaQry[1], r);
            fprintf(saida,"ID:%s W:%lf H:%lf X:%lf Y:%lf CORB:%s CORP:%s \n", getRetanguloI(getInfo(node)), getRetanguloW(getInfo(node)), getRetanguloH(getInfo(node)), getRetanguloX(getInfo(node)), getRetanguloY(getInfo(node)), getRetanguloCorb(getInfo(node)), getRetanguloCorp(getInfo(node)));
            i++;
        }
        if(strlen(getLinhaCor(getInfo(node))) != 0)
        {
            x = getLinhaX1(getInfo(node));
            y = getLinhaY1(getInfo(node));
            double x2 = getLinhaX2(getInfo(node));
            double y2 = getLinhaY2(getInfo(node));

            Linha l = criaLinha(i, x+dx, y+dy, x2+dx, y2+dy, getLinhaCor(getInfo(node)));
            insert(listaQry[2], l);
            fprintf(saida,"ID:%s X1:%lf X2:%lf Y1:%lf Y2:%lf COR:%s\n",getLinhaId(getInfo(node)), getLinhaX1(getInfo(node)), getLinhaX2(getInfo(node)), getLinhaY1(getInfo(node)), getLinhaY2(getInfo(node)), getLinhaCor(getInfo(node)));
            i++;
        }
        if(strlen(getTextoCorp(getInfo(node))) != 0)
        {
            x = getTextoX(getInfo(node));
            y = getTextoY(getInfo(node));
            Texto t = criaTexto(i, x+dx, y+dy, getTextoCorp(getInfo(node)), getTextoCorb(getInfo(node)), getTextoTxto(getInfo(node)));
            insert(listaQry[3], t);
            fprintf(saida,"ID:%s X:%lf Y:%lf CORB:%s CORP:%s TEXTO:%s\n", getTextoI(getInfo(node)), getTextoX(getInfo(node)), getTextoY(getInfo(node)), getTextoCorb(getInfo(node)), getTextoCorp(getInfo(node)), getTextoTxto(getInfo(node)));
            i++;
        }
    }

    removeList(lista, NULL);
}