#include "Classes.h"

void Avion::afficheAttribut()
{
    std::cout<<"Le type de cet avion est : "<<type<<std::endl;
    std::cout<<"La consomation au 100 Km de cet avion est : "<<consomation<<std::endl;
    std::cout<<"Le reservoir de cet avion est de : "<<reservoir<<std::endl;
    std::cout<<"La distance que cet avion peut parcourir en autonomie est : "<<DistanceAutonomie<<std::endl;
}

Avion::Avion(std::string _type):type(_type)
{
    if(_type == "Cours_Courrier")
    {
        ifstream fichier("Avion.txt");
        if(fichier)
        {
            std::string inutileString;
            fichier >> inutileString;
            fichier >> consomation;
            fichier >> reservoir;
            fichier >> DistanceAutonomie;
        }
        else {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }
    }
    else if(_type == "Moyen_Courrier")
    {
        ifstream fichier("Avion.txt");
        if(fichier)
        {
            std::string inutileString;
            int inutile;
            fichier >> inutileString;
            for(int i = 0;i<3;i++)
            {
                fichier >> inutile;
            }
            fichier >> inutileString;
            fichier >> consomation;
            fichier >> reservoir;
            fichier >> DistanceAutonomie;
        }
        else {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }
    else if(_type == "Long_Courrier")
    {
        ifstream fichier("Avion.txt");
        if(fichier)
        {
            std::string inutileString;
            int inutile;
            fichier >> inutileString;
            for(int i = 0;i<3;i++)
            {
                fichier >> inutile;
            }
            fichier >> inutileString;
            for(int i = 0;i<3;i++)
            {
                fichier >> inutile;
            }
            fichier >> inutileString;
            fichier >> consomation;
            fichier >> reservoir;
            fichier >> DistanceAutonomie;
        }
        else {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }
}


int Avion::getMin(int dist[], bool visited[]) {
    int key = 0;
    int min = INT_MAX;
    for(int i=0;i < nbs; i++){
        if(!visited[i] && dist[i]<min) {
            min = dist[i];
            key = i;
        }
    }
    return key ;
}

void Avion::display(int dist[], int par[], int end) {

    int temp = par[end];
    cout<< conversionSommetVille(end) + " <- ";
    while(temp!=-1) {
        cout<< conversionSommetVille(temp) + " <- ";
        temp = par[temp];
    }
    cout<<endl;
    cout<<"Distance = " << dist[end];
    cout<<endl;

}



void Avion::ParametrageGPSdijkstra()
{
    std::cout<<"le nom de fichier est:  "<<type<<std::endl;
    std::ifstream fichier(type+".txt");
    /// lecture du fichier ( structure du fichier est celui donné dans le tp )///
    if(fichier) {
        fichier>>nbs;
        for(int i=0; i<nbs; i++){
            for(int j=0; j<nbs; j++) {
                if(i==j){
                    cost[i][j]=0;
                }
                else{
                    cost[i][j]=999;
                }
            }
        }
        while(fichier>>Sommet_) {
            fichier>>Adjacence;
            fichier>>ponderation_;
            cost[Sommet_][Adjacence]=ponderation_;
        }
    }
    else {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}


void Avion::dijkstra(int src , int end) {
    int par[100], dist[100];
    bool visited[100] ={0};
    fill(dist, dist+nbs, INT_MAX );
    dist[src] =0;
    par[src] =-1;
    for(int g = 0; g<nbs-1; g++){
        int u = getMin(dist, visited );
        visited[u] = true ;
        for(int v =0 ; v< nbs ;v++){
            if(!visited[v] && (dist[u]+cost[u][v]) <  dist[v] && cost[u][v]!=999)
            {
                par[v] = u;
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }
    display(dist, par, end);
}

void Avion::trajet_de_lavion()
{
    std::cout<<"Voici les aeroport disponible pour ce type d'avion :";
    if(type == "Cours_Courrier")
    {
        /// afficher les trajet possible sur allegro et blinder les entré en dessous pour le choix des sommmet depart et arrivé
    }
    else if(type == "Moyen_Courrier")
    {
        /// afficher les trajet possible sur allegro et blinder les entré en dessous pour le choix des sommmet depart et arrivé
    }
    else if(type == "Long_Courrier")
    {
        /// afficher les trajet possible sur allegro et blinder les entré en dessous pour le choix des sommmet depart et arrivé
    }
    int i, j;
    std::cout<<std::endl;
    cout << "Sommet de depart\n";                       /// A therme on remplacera i par l'aeroport ou l'avion est arreté
    cin >> i;
    cout << "Sommet de d'arrivee\n";
    cin >> j;
    std::cout<<"BON VOL :)"<<std::endl;
    dijkstra(i, j);
}


Avion::~Avion() {}
