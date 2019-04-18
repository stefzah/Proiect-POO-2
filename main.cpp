#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("fisier.in");
ofstream fout("fisier.out");

///Clasa Nod

class Nod
{
    int info;
public:
    Nod():info(0) {}
    Nod(int info):info(info) {}
    Nod(const Nod &N)
    {
        info=N.info;
    }
    void operator = (Nod &N)
    {
        info=N.info;
    }
    int operator == (Nod &N)
    {
        return (info==N.info);
    }
    int operator != (Nod &N)
    {
        return info!=N.info;
    }
    int operator < (Nod &N)
    {
        return info<N.info;
    }
    int get_info()
    {
        return info;
    }
    ~Nod() {}
    friend istream & operator >>(istream& i, Nod&N);
    friend ostream & operator <<(ostream& out, Nod&N);
};
istream & operator >>(istream& i, Nod&N)
{
    i>>N.info;
}
ostream & operator <<(ostream& out, Nod&N)
{
    out<<N.info;
}

///clasa Nod_ABC

class Nod_ABC:public Nod
{
    Nod_ABC *st,*dr;
public:
    Nod_ABC(): Nod()
    {
        st=0;
        dr=0;
    }
    Nod_ABC(int info): Nod(info)
    {
        st=0;
        dr=0;
    }
    Nod_ABC(Nod *ST, Nod *DR): Nod()
    {
        st=(Nod_ABC*)ST;
        dr=(Nod_ABC*)DR;
    }
    Nod_ABC(const Nod_ABC &N): Nod(N) {}
    void operator = (Nod_ABC &N)
    {
        (Nod &)(*this)=N;
    }
    int operator == (Nod_ABC &N)
    {
        return (Nod &)(*this)==(Nod &)N;
    }
    int operator != (Nod_ABC &N)
    {
        return (Nod &)(*this)!=(Nod &)N;
    }
    int operator < (Nod_ABC &N)
    {
        return (Nod &)(*this)<(Nod &)N;
    }
//int get_info(Nod_ABC &N){return info;}
    void set_st(Nod_ABC N)
    {
        st=&N;
    }
    void set_dr(Nod_ABC N)
    {
        dr=&N;
    }
    void add_st(int x)
    {
        Nod_ABC *p;
        p=new Nod_ABC(x);
        st=p;
    }
    void add_dr(int x)
    {
        Nod_ABC *p;
        p=new Nod_ABC(x);
        dr=p;
    }
    Nod_ABC *get_st()
    {
        if(st!=0)return st;
        else return 0;
    }
    Nod_ABC *get_dr()
    {
        if(dr!=0)return dr;
        else return 0;
    }
    ~Nod_ABC()
    {
        delete st;
        delete dr;
        cout<<"\nThis is the destructor";
        //delete this;
    }
    friend istream & operator >>(istream& i, Nod_ABC&N);
    friend ostream & operator <<(ostream& out, Nod_ABC&N);
};
istream & operator >>(istream& i, Nod_ABC&N)
{
    i>>(Nod &)N;
}
ostream & operator <<(ostream& out, Nod_ABC&N)
{
    out<<(Nod &)N;
}

///clasa Nod_fiu_frate

class Nod_fiu_frate :public Nod
{
    int copii;
    Nod_fiu_frate *frate,*fiu_stang,*tata;
public:
    Nod_fiu_frate(): Nod()
    {
        frate=0;
        fiu_stang=0;
        copii=0;
    }
    Nod_fiu_frate(int x): Nod(x)
    {
        frate=0;
        fiu_stang=0;
        copii=0;
    }
    Nod_fiu_frate(int x, int y): Nod(x)
    {
        frate=0;
        fiu_stang=0;
        copii=y;
    }
    Nod_fiu_frate(const Nod_fiu_frate &N): Nod(N) {}
    void operator = (Nod_fiu_frate &N)
    {
        (Nod &)(*this)=N;
    }
    int operator == (Nod_fiu_frate &N)
    {
        return (Nod &)(*this)==(Nod &)N;
    }
    int operator != (Nod_fiu_frate &N)
    {
        return (Nod &)(*this)!=(Nod &)N;
    }
    int operator < (Nod_fiu_frate &N)
    {
        return (Nod &)(*this)<(Nod &)N;
    }
    void set_frate(Nod_fiu_frate *N)
    {
        frate=N;
        N->tata=tata;
    }
    void set_fiu_stang(Nod_fiu_frate *N)
    {
        fiu_stang=N;
        N->tata=this;
    }
    void add_frate(int x)
    {
        Nod_fiu_frate *p;
        p=new Nod_fiu_frate(x);
        frate=p;
        p->tata=tata;
        copii++;
    }
    void add_fiu_stang(int x)
    {
        if(fiu_stang==0)
        {
            Nod_fiu_frate *p;
            p=new Nod_fiu_frate(x);
            fiu_stang=p;
            p->tata=this;
            copii=1;

        }
    }

    Nod_fiu_frate *get_frate()
    {
        if(frate!=0)return frate;
        else return 0;
    }
    Nod_fiu_frate *get_fiu_stang()
    {
        if(fiu_stang!=0)return fiu_stang;
        else return 0;
    }
    ~Nod_fiu_frate()
    {
        delete fiu_stang;
        delete frate;
        cout<<"This is the destructor\n";
        //delete this;
    }
    friend istream & operator >>(istream& i, Nod_fiu_frate&N);
    friend ostream & operator <<(ostream& out, Nod_fiu_frate&N);
};
istream & operator >>(istream& i, Nod_fiu_frate&N)
{
    i>>(Nod &)N;
}
ostream & operator <<(ostream& out, Nod_fiu_frate&N)
{
    out<<(Nod &)N;
}




///clasa Arbore - abstracta

class Arbore
{
    int nr_noduri;
public:
    virtual void Afisare()=0;
    Arbore ():nr_noduri(0) {}
    Arbore (int x):nr_noduri(x) {}
    int NR()
    {
        return nr_noduri;
    }
    void set_nr_noduri(int info)
    {
        nr_noduri=info;
    }
    ~Arbore() {}
    //friend istream & operator >>(istream& i, Arbore&A);
    //friend ostream & operator <<(ostream& out, Arbore&A);
};
/*istream & operator >>(istream& i, Arbore&A)
{
    int x;
    i>>x;
    A.nr_noduri=x;
}
ostream & operator <<(ostream& out, Arbore&A)
{
    out<<A.nr_noduri;
}
*/
///clasa ABC

class ABC: public Arbore
{
    Nod_ABC *radacina;
public:
    ABC(): Arbore()
    {
        radacina=0;
    }
    ABC(int x): Arbore(x)
    {
        radacina=0;
    }
    /*ABC(const ABC &A)
    {
    //set_nr_noduri(A.NR());
    Nod_ABC *c,*N=new Nod_ABC((*A.radacina).get_info());
    //addfiu(p,Nod(A.radacina->info));
    radacina=N;
    Nod_ABC *C[NR()+1],*C2[NR()+1];
    int st=0,dr=0;
    C[dr]=A.radacina;
    C2[dr]=radacina;
    while(st<=dr)
    {
        N=C2[st];
        c=C[st];
        st++;
        if((*c).get_frate!=0)
        {
            add_frate(*((*c).get_frate()).get_info());
            dr++;
            C2[dr]=(*N).get_frate();
            C[dr]=(*c).get_frate();
        }
        if(c->fiu!=0)
        {
            add_fiu_stang(*((*c).get_fiu_stang()).get_info());
            dr++;
            C2[dr]=(*N).get_fiu_stang();
            C[dr]=(*c).get_fiu_stang();
        }
    }
    }*/
    void RSD(Nod_ABC* N)
    {
        fout<<(*N)<<" ";
        if((*N).get_st()!=0)
        {
            RSD((*N).get_st());
        }
        if((*N).get_dr()!=0)
        {
            RSD((*N).get_dr());
        }
    }
    void SRD(Nod_ABC* N)
    {
        if((*N).get_st()!=0)
        {
            SRD((*N).get_st());
        }
        fout<<(*N)<<" ";
        if((*N).get_dr()!=0)
        {
            SRD((*N).get_dr());
        }
    }
    void SDR(Nod_ABC* N)
    {
        if((*N).get_st()!=0)
        {
            SDR((*N).get_st());
        }
        if((*N).get_dr()!=0)
        {
            SDR((*N).get_dr());
        }
        fout<<(*N)<<" ";
    }
    void Afisare()
    {
        Nod_ABC *c;
        Nod_ABC *C[NR()+1];
        int ST=0,DR=0;
        C[DR]=radacina;
        fout<<"\nRSD: ";
        RSD(radacina);
        fout<<"\nSRD: ";
        SRD(radacina);
        fout<<"\nSDR: ";
        SDR(radacina);
        fout<<"\n";
    }
    ~ABC()
    {
        delete radacina;
    }

    friend istream & operator >>(istream& i, ABC&A);
    friend ostream & operator <<(ostream& out, ABC&A);
};
istream & operator >>(istream& i, ABC&A)
{
    int nr_nod,info,j;
    i>>nr_nod;
    i>>info;
    Nod_ABC *N=new Nod_ABC(info);
    A.radacina=N;
    for(j=1; j<=nr_nod-1; j++)
    {
        i>>info;
        N=A.radacina;
        while(N!=0)
        {
            if(info<(*N).get_info()&&(*N).get_st()!=0)
                N=(*N).get_st();
            else if(info>=(*N).get_info()&&(*N).get_dr()!=0)
                N=(*N).get_dr();
            else if(info<(*N).get_info())
            {
                (*N).add_st(info);
                break;
            }
            else
            {
                (*N).add_dr(info);
                break;
            }
        }
    }
}
ostream & operator <<(ostream& out, ABC&A)
{
    A.Afisare();
}

///clasa AB_oarecare

class AB_oarecare :public Arbore
{
    Nod_fiu_frate *radacina;
public:
    int NR_noduri;
    AB_oarecare(): Arbore()
    {
        radacina=0;
    }
    AB_oarecare(int x): Arbore(x)
    {
        radacina=0;
    }
    AB_oarecare(const AB_oarecare &A)
    {
        //int nrr=A.NR_noduri;
        set_nr_noduri(A.NR_noduri);
        Nod_fiu_frate *c,*N=new Nod_fiu_frate((*A.radacina).get_info());
        //addfiu(p,Nod(A.radacina->info));
        radacina=N;
        //fout<<(*A.radacina).get_info();
        Nod_fiu_frate *C[A.NR_noduri+1],*C2[A.NR_noduri+1];
        fout<<A.NR_noduri;
        int st=0,dr=0;
        C[dr]=A.radacina;
        C2[dr]=radacina;
        while(st<=dr)
        {
            N=C2[st];
            c=C[st];
            st++;
            if((*c).get_frate()!=0)
            {
                (*N).add_frate((*((*c).get_frate())).get_info());
                dr++;
                C2[dr]=(*N).get_frate();
                C[dr]=(*c).get_frate();
            }
            if((*c).get_fiu_stang()!=0)
            {
                (*N).add_fiu_stang((*((*c).get_fiu_stang())).get_info());
                dr++;
                C2[dr]=(*N).get_fiu_stang();
                C[dr]=(*c).get_fiu_stang();
            }
        }
    }
    void operator = (AB_oarecare &A)
    {
        //int nrr=A.NR_noduri;
        delete radacina;
        set_nr_noduri(A.NR_noduri);
        Nod_fiu_frate *c,*N=new Nod_fiu_frate((*A.radacina).get_info());
        //addfiu(p,Nod(A.radacina->info));
        radacina=N;
        //fout<<(*A.radacina).get_info();
        Nod_fiu_frate *C[A.NR_noduri+1],*C2[A.NR_noduri+1];
        //fout<<A.NR_noduri;
        int st=0,dr=0;
        C[dr]=A.radacina;
        C2[dr]=radacina;
        while(st<=dr)
        {
            N=C2[st];
            c=C[st];
            st++;
            if((*c).get_frate()!=0)
            {
                (*N).add_frate((*((*c).get_frate())).get_info());
                dr++;
                C2[dr]=(*N).get_frate();
                C[dr]=(*c).get_frate();
            }
            if((*c).get_fiu_stang()!=0)
            {
                (*N).add_fiu_stang((*((*c).get_fiu_stang())).get_info());
                dr++;
                C2[dr]=(*N).get_fiu_stang();
                C[dr]=(*c).get_fiu_stang();
            }
        }
    }
    bool operator > (AB_oarecare &A)
    {
        return NR_noduri>A.NR_noduri;
    }
    void operator + (AB_oarecare &A)
    {
        Nod_fiu_frate* N;
        NR_noduri+=A.NR_noduri;
        N=radacina;
        if((*N).get_fiu_stang()==0)
            (*N).set_fiu_stang(A.radacina);
        else
        {
            N=(*N).get_fiu_stang();
            while((*N).get_frate()!=0)N=(*N).get_frate();
            (*N).set_frate(A.radacina);
        }
    }
    void Afisare()
    {
        Nod_fiu_frate *c;
        Nod_fiu_frate *C[2*NR()],*C2[2*NR()];
        int ST=0,DR=0,DR2=0,ST2=1,q=0;
        C[DR]=radacina;
        fout<<"\nParcurgerea in latime: ";
        while(ST<=DR&&q<NR())
        {
            q++;
            c=C[ST];
            fout<<(*c).get_info()<<" ";
            if((*c).get_fiu_stang()!=0)
            {
                DR2++;
                C2[DR2]=(*c).get_fiu_stang();
            }
            ST++;
            if((*c).get_frate()!=0)
            {
                DR++;
                C[DR]=(*c).get_frate();
            }

            else
            {
                if(ST2<=DR2)
                {
                    DR++;
                    C[DR]=C2[ST2];
                    ST2++;
                }
            }
        }
        delete[]C;
        delete[]C2;
    }
    Nod_fiu_frate* getnod(int info)
    {
        int i;
        Nod_fiu_frate *C[NR()+1],*c;
        //fout<<NR();
        int st=0,dr=0;
        C[dr]=radacina;
        while(C[st]!=0)
        {
            c=C[st];
            //fout<<"*"<<(*c)<<"*";
            if((*c).get_info()==info)return c;
            st++;
            if((*c).get_fiu_stang()!=0)
            {
                dr++;
                C[dr]=(*c).get_fiu_stang();
            }
            if((*c).get_frate()!=0)
            {
                dr++;
                C[dr]=(*c).get_frate();
            }
        }

    }
    friend istream & operator >>(istream & i, AB_oarecare &A);
    friend ostream & operator <<(ostream & out, AB_oarecare &A);
    ~AB_oarecare()
    {
        delete radacina;
    }
};
istream & operator >>(istream & i, AB_oarecare &A)
{
    int info,nrnod,j,info_t,nrcopii,k;
    i>>nrnod>>info;
    A.set_nr_noduri(nrnod);
    A.NR_noduri=nrnod;
    Nod_fiu_frate *N=new Nod_fiu_frate(info);
    A.radacina=N;
    //A.set_nr_noduri(nrnod);
    for(j=2; j<=nrnod; j++)
    {
        i>>info>>info_t;
        N=A.getnod(info_t);
        if((*N).get_fiu_stang()!=0)
        {
            N=(*N).get_fiu_stang();
            while((*N).get_frate()!=0)
            {
                N=(*N).get_frate();
            }
            (*N).add_frate(info);
        }
        else (*N).add_fiu_stang(info);
    }
}
ostream & operator <<(ostream & out, AB_oarecare &A)
{
    A.Afisare();
}
int main()
{
    int i,N,tip;
    fin>>N;
    AB_oarecare *A = new AB_oarecare[N];
    for(i=0; i<N; i++)
    {
        fin>>(A[i]);
        fout<<(A[i]);
    }
    AB_oarecare B;
    B=A[0];
    fout<<B;
    delete[] A;

}
