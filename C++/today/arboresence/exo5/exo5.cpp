#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>


using namespace std;
namespace fs = std::filesystem;

struct Ville {
    string nom;
    size_t population;
    string departement;
    string region;
};

vector<Ville> lecture_fichiers(const fs::path& dirname)
{
    vector<Ville> villes;
    for (const auto& region_entry : fs::directory_iterator(dirname)) {
        if (fs::is_directory(region_entry.path())) {
            string region_name = region_entry.path().filename().string();
            for (const auto& dept_entry : fs::directory_iterator(region_entry.path())) {
                if (fs::is_directory(dept_entry.path())) {
                    string dept_name = dept_entry.path().filename().string();
                    for (const auto& ville_entry : fs::directory_iterator(dept_entry.path())) {
                        if (fs::is_regular_file(ville_entry.path())) {
                            string ville_name = ville_entry.path().stem().string();
                            ifstream file(ville_entry.path());
                            if (file.is_open()) {
                                size_t population;
                                file >> population;
                                file.close();
                                Ville ville = {ville_name, population, dept_name, region_name};
                                villes.push_back(ville);
                            }
                        }
                    }
                }
            }
        }
    }

    return villes;
}

size_t total_population_villes(const vector<Ville>& villes)
{   
    size_t total = 0;
    for (const Ville& villex : villes) {
        total += villex.population;
    }
    return total;   
    return 0;
}


bool comparateur_villes(const Ville& a,const Ville& b)
{
    return a.population > b.population;
}


void trier_villes(vector<Ville>& villes)
{
    sort(villes.begin(), villes.end(), comparateur_villes);

}

void ecrire_csv(const vector<Ville>& villes,const fs::path& resultat)
{
    ofstream file(resultat);
    if (file.is_open()) {
        file << "Nom;Population;Département;Région\n";
        for (const Ville& villex : villes) {
            file << villex.nom << ";" << villex.population << ";" << villex.departement << ";" << villex.region << "\n";
        }
        file.close();
    }
}

int main(int argc, char* argv[])
{
    fs::path dirname((argc == 2 ? argv[1] : "None")); // S'il y a bien une chaîne en paramètre, l'utiliser pour initialiser dirname.
    if(fs::is_directory(dirname))
    {
        vector<Ville> villes = lecture_fichiers(dirname);
        if(villes.size()==0)
            cout << "Vous n'avez chargé aucune ville !" << endl;
        else
        {
            cout << "Le total de la population de toutes les villes est de " << total_population_villes(villes) << " habitants." << endl;

            trier_villes(villes);

            fs::path resultat = fs::temp_directory_path() / "villes.csv";
            cout << "Écriture du fichier de résultat dans " << resultat << "." << endl;
            ecrire_csv(villes,resultat);

            cout << "Vous avez traité " << villes.size() << " villes pour une population urbaine totale de " << total_population_villes(villes) << "." << endl <<
                    "La plus peuplée est : " << villes[0].nom << " avec ses " << villes[0].population << " habitants en région " << villes[0].region << " (code département : " << villes[0].departement << ")." << endl <<
                    "La moins peuplée est : " << villes[villes.size() - 1].nom << " avec ses " << villes[villes.size() - 1].population << " habitants en région " << villes[villes.size() - 1].region << " (code département : " << villes[villes.size() - 1].departement << ")." << endl;
        }
    }
    else
    {
        cerr << "Merci d'indiquer en paramètre du programme le chemin du répertoire « Population » fourni et comportant les données, par exemple :" << endl
             << argv[0] << " /tmp/exo5/Population" << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
