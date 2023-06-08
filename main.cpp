#include <iostream>
#include <vector>
#include "List.h"
#include "TestList.h"
#include "Colectie.h"
#include "RepoATM.h"
#include "UI.h"

#include "Tranzactie.h";

using namespace std;

int main()
{
    TestList t;
    t.TestTot();
    Colectie c;
    //cout<<"MAIN\n";
    //cout<<c.GetSize()<<endl;
    //Colectie c;
    //Tranzactie t1(100,c);
    //cout<<t1;
    Repo r("Bancnote","Tranzactii");
    //RepoFile rf("Bancnote","Tranzactii");
    UI ui(r);
    ui.meniu();
    return 0;
}
