#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int mat[131][131][10];
char alfabet[131],stari[10],stari_finale[10];

int main()
{
    ///ofstream g("iesire.out");
    ifstream f("input.in");
    int nr_litere,nr_stari,nr_tranzitii,nr_stari_finale=0;
    char stare1,stare2,tranzitie,loop;

    int i,j,k,l;

    f>>nr_stari;
    for(i=0; i<nr_stari; i++)
        f>>stari[i];

    f>>nr_litere;
    for(i=0; i<nr_litere; i++)
        f>>alfabet[i];

    f>>nr_tranzitii;
    for(l=0; l<nr_tranzitii; l++)
    {
        f>>stare1>>tranzitie>>stare2;

        if(stare2=='0' && tranzitie==';')
        {
            stari_finale[nr_stari_finale]=stare1;
            nr_stari_finale++;
        }
        if(stare2=='0' && tranzitie!=';')
            loop=tranzitie;

        for(j=1; j<131; j++)
            if(alfabet[j]==tranzitie)
                break;

        for(k=0; k<10; k++)
        {
            ///daca pozitia din "celula" respectiva a matricei nu a fost initializata o initializez si ies
            if(mat[stare1][alfabet[j]][k]==0)
            {
                mat[stare1][alfabet[j]][k]=stare2;
                break;
            }
        }
    }
    f.close();

   /* for(i=0; i<131; i++)
    {
        for(j=0; j<131; j++)
        {
            for(k=0; k<10; k++)
                if((int)mat[i][j][k]!=0)
                    g<<mat[i][j][k];
            g<<" ";
        }
        g<<endl;
    }*/

    char s[100];
    cout<<"Introduceti cuvantul pe care doriti sa il verificati ";
    cin>>s;

   /* for(i=0;i<nr_stari_finale;i++)
        g<<stari_finale[i]<< " ";
        g<<endl;*/

    int ok,curent[131],intermediar[131],index_cur=1,index_interm;
    curent[0]=0;
    ok=0;
    for(i=0; i<strlen(s); i++)
    {
        for(j=0; j<nr_litere; j++)
            if(s[i]==alfabet[j])
                ok=1;

        if(ok==0)
            break;
        index_interm=0;

        for(j=0; j<133; j++)
            for(k=0; k<10; k++)
                    if(mat[j][(int)s[i]][k]!=0)
                        intermediar[index_interm++]=mat[j][(int)s[i]][k];
        for(j=0; j<index_interm; j++)
            curent[j]=intermediar[j];

        index_cur=index_interm;
    }

    ok=0;

   /* for(i=0;i<index_cur;i++)
        g<<(char)curent[i]<<" ";*/

    for(i=0; i<index_cur && ok==0; i++)
        for(j=0; j<nr_stari_finale && ok==0; j++)
            if((char)curent[i]==stari_finale[j])
                ok=1;
    if(s[strlen(s)-1]==loop)
        ok=1;
    if(ok==0)
        cout<<"Cuvantul nu apartine limbajului ";
    else
        cout<<"Cuvantul apartine limbajului ";


    return 0;
}
