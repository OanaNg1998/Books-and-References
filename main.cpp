#include <iostream>
#include <typeinfo>
#include <string.h>

using namespace std;
class Referinta
{  protected: string titlu;
    public:

    virtual void citire(){
    cin>>titlu;}
    virtual void afisare(){ cout<<titlu<<" ";}
};
class Autor
{
    string nume,prenume;
    public:
   /* Autor (string n,string p)
    {
        nume=n;
        prenume=p;
    }*/
    void citire()
    {
        cin>>nume>>prenume;
    }
    void afisare()
    {
        cout<<nume<<" "<<endl;
    }
    bool operator==(string name)
    {
        if(this->nume==name) return 1;
         return 0;
    }
    friend class Articol;
    friend class Carte;
};
class Articol:public Referinta
{
    Autor v[20];
int nr_autori;

 int an_pubArt;
 string nume_rev;
 int nr_rev;
 int nr_pagRev;
 public:
     int get_anArt()
     {
         return an_pubArt;
     }
     int get_nrAut()
     {
         return nr_autori;
     }
     bool operator==(string name)
     {
         for(int i=0;i<this->nr_autori;i++)
            if(v[i]==name) return 1;
          return 0;
     }

     void citire()
     { Referinta::citire();
     cout<<"Citeste nr de autori"<<endl;
     cin>>nr_autori;
     for(int i=0;i<nr_autori;i++)
        v[i].citire();

    cin>>an_pubArt>>nume_rev>>nr_rev>>nr_pagRev;

     }
     void afisare ()
     { Referinta::afisare();
         cout<<nume_rev<<endl;
     }

};
class Carte:public Referinta
{
    Autor q[20];

    int an_pubCarte;
    int nr_aut;
    string nume_editura;
    string oras_editura;
public:
    int get_anCarte()
    {
        return an_pubCarte;
    }
    int get_nrAutpri()
     {
         return nr_aut;
     }
     bool operator==(string name)
     {
         for(int i=0;i<this->nr_aut;i++)
            if(q[i]==name) return 1;
          return 0;
     }
    void citire()
    {  Referinta::citire();
     cout<<"Citeste nr de autori"<<endl;
     cin>>nr_aut;
     for(int i=0;i<nr_aut;i++)
        q[i].citire();
        cout<<"restul"<<endl;
        cin>>nume_editura>>an_pubCarte;
    }
    void afisare()
    {   Referinta::afisare();
        cout<<nume_editura<<endl;
    }

};
class Web:public Referinta
{
    string prop;

    string url;
    int an;
public:
    string get_prop()
    {
        return prop;
    }
    void citire()
    { Referinta::citire();
        cin>>prop;
    }
    void afisare()
    { Referinta::afisare();
        cout<<prop<<endl;
    }
};

int main()
{
    int n;
    cout<<"Citeste n:"<<endl;
    cin>>n;
    char tip;
    Referinta **lista=new Referinta *[n];
     int op;
    cout<<"Citeste optiunea"<<endl;

    cin>>op;

   switch(op){
    case 1:{for (int i=0;i<n;i++)
    {  cout<<"Baga tip:"<<endl;
        cin>>tip;
        int k=0,k2=0;
        if(tip=='a')

           {
               k++;
               lista[i]=new Articol;

           }
        else if(tip=='c') {k++;lista[i]=new Carte;}
        else if(tip=='w'){ k2++;lista[i]=new Web;}
        cout<<"Citire:"<<endl;

        lista[i]->citire();
        if(k!=0) cout<<"Bibliografie"<<endl;
        if(k2!=0) cout<<"Webgrafie"<<endl;
        lista[i]->afisare();
    }
    }
   case 2:{ for (int i=0;i<n;i++)
    {  cout<<"Baga tip:"<<endl;
        cin>>tip;
        if(tip=='a')

            lista[i]=new Articol;

        else if(tip=='c') lista[i]=new Carte;
        else if(tip=='w')lista[i]=new Web;
        cout<<"Citire:"<<endl;
        lista[i]->citire();
        lista[i]->afisare();
    }
     int an;
       cout<<"Citeste anul:"<<endl;
        cin>>an;

        for(int i=0;i<n;i++)
        {
       // Articol*A=<dynamic_cast>(Articol*)lista[i];
            if(typeid(*lista[i]).name()==typeid(Articol).name())
            { Articol * a= dynamic_cast<Articol*>(lista[i]);
            if(a->get_anArt()==an)
                lista[i]->afisare();
            }
            if(typeid(*lista[i]).name()==typeid(Carte).name())
            { Carte * c= dynamic_cast<Carte*>(lista[i]);
            if(c->get_anCarte()==an)  lista[i]->afisare();
            }

        }
   }
   case 3:
    {
        for (int i=0;i<n;i++)
    {  cout<<"Baga tip:"<<endl;
        cin>>tip;
        if(tip=='a')

            lista[i]=new Articol;

        else if(tip=='c') lista[i]=new Carte;
        else if(tip=='w')lista[i]=new Web;
        cout<<"Citire:"<<endl;
        lista[i]->citire();
        lista[i]->afisare();
    }
     string name;
       cout<<"Citeste numele:"<<endl;
        cin>>name;

        for(int i=0;i<n;i++)
        {
       // Articol*A=<dynamic_cast>(Articol*)lista[i];
            if(typeid(*lista[i]).name()==typeid(Web).name())
            { Web * w= dynamic_cast<Web*>(lista[i]);

            if(w->get_prop()==name)  lista[i]->afisare();
            }


        }
    }
   case 4:
    { { for (int i=0;i<n;i++)
    {  cout<<"Baga tip:"<<endl;
        cin>>tip;
        if(tip=='a')

            lista[i]=new Articol;

        else if(tip=='c') lista[i]=new Carte;
        else if(tip=='w')lista[i]=new Web;
        cout<<"Citire:"<<endl;
        lista[i]->citire();
        lista[i]->afisare();
    }
    string nume;
    cout<<"Numele este:"<<endl;
    cin>>nume;
    for(int i=0;i<n;i++)
        {
       // Articol*A=<dynamic_cast>(Articol*)lista[i];
            if(typeid(*lista[i]).name()==typeid(Articol).name())
            { Articol * a= dynamic_cast<Articol*>(lista[i]);
            if((*a)==nume) lista[i]->afisare();
            }
            if(typeid(*lista[i]).name()==typeid(Carte).name())
            { Carte * c= dynamic_cast<Carte*>(lista[i]);

                if((*c)==nume) lista[i]->afisare();
            }

        }


    }
    }
   };



    return 0;
}
