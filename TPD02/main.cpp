#include <iostream>
using namespace std;

const unsigned short TAILLE_NOM = 31;
const unsigned short TAILLE_PRENOM = 31;

enum Position {
	GARDIEN_DE_BUT = 1,
	ATTAQUANT,
	DEFENSEUR,
	MILIEU_DE_TERRAIN
};

struct joueur {
	unsigned short noDeJoueur;
	char nom[TAILLE_NOM];
	char prenom[TAILLE_PRENOM];
	unsigned short nbButs;
	Position position;
};

unsigned short afficherMenu();
void ajouterJoueur(joueur joueurs[], unsigned short &nbJoueurs);
int rechercherJoueur(joueur joueurs[], unsigned short nbJoueurs);
void modifierJoueur(joueur &joueur);
void retirerJoueur(joueur joueurs[], unsigned short &nbJoueurs, int indiceJoueurARetirer);
void afficherInfoJoueur(const joueur &JOUEUR);
void ajouterButJoueur(joueur &joueur);
void retirerButJoueur(joueur &joueur);
void afficherJoueursParPosition(joueur joueurs[], unsigned short nbJoueurs);
void afficherTotalDeButDeLEquipe(joueur joueurs[], unsigned short nbJoueurs);
// Fonction supplémentaires
int lireEntierIntervalle(int min, int max);
void litChaine(char chaine[], unsigned short int nbCharMax);
void miniMenu();
void afficherJoueurParPosition(joueur joueurs[], int unPosition, int nbJoueurs);
int lireEntierIntervallePo(int min, int max);
int main() {
	setlocale(LC_ALL, "");
	int choix = 0;
	joueur joueurs[14];
	unsigned short nbJoueurs = 2;
	int indice;
	//créer des informations sur les joueurs
	joueur unJoueur;
	strcpy_s(unJoueur.nom, "Ho");
	strcpy_s(unJoueur.prenom, "Cong Tai");
	unJoueur.noDeJoueur = 9;
	unJoueur.nbButs = 8;
	unJoueur.position = MILIEU_DE_TERRAIN;
	joueurs[0] = unJoueur;

	//créer des informations sur les joueurs
	strcpy_s(unJoueur.nom, "Messi");
	strcpy_s(unJoueur.nom, "Leo");
	unJoueur.noDeJoueur = 10;
	unJoueur.nbButs = 3;
	unJoueur.position = ATTAQUANT;
	joueurs[1] = unJoueur;


	while (choix != 9)
	{

		choix = afficherMenu();
		switch (choix)
		{
		case 1:
			//ajouter joueur
			ajouterJoueur(joueurs, nbJoueurs);
			break;
		case 2:
			// modifier 1 joueur
			indice = rechercherJoueur(joueurs, nbJoueurs);
			if (indice != -1) {
				modifierJoueur(joueurs[indice]);
			}
			break;
		case 3:
			//retire un joueur
			indice = rechercherJoueur(joueurs, nbJoueurs);
			if (indice != -1) {
				retirerJoueur(joueurs, nbJoueurs, indice);
			}
			break;
		case 4:
			//Afficher les informations d’un joueur
			indice = rechercherJoueur(joueurs, nbJoueurs);
			if (indice != -1) {
				afficherInfoJoueur(joueurs[indice]);
			}
			break;
		case 5:
			//Ajouter un but
			indice = rechercherJoueur(joueurs, nbJoueurs);
			if (indice != -1) {
				ajouterButJoueur(joueurs[indice]);
			}
			break;
		case 6:
			//Retirer un but
			indice = rechercherJoueur(joueurs, nbJoueurs);
			if (indice != -1) {
				retirerButJoueur(joueurs[indice]);
			}
			break;
		case 7:
			//Afficher joueur par position
			afficherJoueursParPosition(joueurs, nbJoueurs);
		case 8:
			//Afficher le nombre total de buts
			afficherTotalDeButDeLEquipe(joueurs, nbJoueurs);
			break;
		case 9:
			//Quitter l'application
			cout << "Program terminer!" << endl;
			system("pause");
			exit(0);
		}
		cout << "Voulez-vous continuer avec le programme principal? Si non veuillez vous choisir (9) pour quitter l'application. ";
		cin >> choix;
	}


	system("pause");
	return 0;

}

/*
	Tâche : fonction qui fait apparaitre un menu, demande de faire un
			choix à l'utilisateur, récupère ce choix et le retourne.
	Paramètre(s) : aucun
	Retour : Le choix effectué par l'utilisateur
*/
unsigned short afficherMenu() {
	unsigned short choix = 0;
	cout << "========================= BIENVENUE AU CLUB BARCELONE ================================" << endl;
	cout << "1 – Ajouter un joueur. " << endl;
	cout << "2 – Modifier un joueur. " << endl;
	cout << "3 – Retirer un joueur. " << endl;
	cout << "4 – Afficher les informations d’un joueur selon son numéro de joueur. " << endl;
	cout << "5 – Ajouter un but à un joueur selon son numéro de joueur. " << endl;
	cout << "6 – Retirer un but à un joueur selon son numéro de joueur. " << endl;
	cout << "7 – Afficher tous les joueurs(avec option de filtre). " << endl;
	cout << "    *>  Gardien de but " << endl;
	cout << "    *>  Attaquant " << endl;
	cout << "    *>  Défenseur " << endl;
	cout << "    *>  Milieu de terrain " << endl;
	cout << "    *>  Tout types confondus " << endl;
	cout << "8 – Afficher le nombre total de buts comptés pour l’équipe. " << endl;
	cout << "9 – Quitter l'application. " << endl;
	cout << "Voulez-vous choisir: ";
	choix = lireEntierIntervalle(1, 9);
	cout << endl;
	cout << "====================================================================================" << endl;
	//À compléter

	// À remplacer car c'est seulement là pour que le code compile

	return choix;
}

/*
	Tâche : fonction qui sert à insérer UN SEUL nouveau joueur dans l'équipe. Demander une saisie pour chacune des informations d’un joueur, sauf pour le nombre de but, qui sera initialisé à 0 au moment de la création.
	Paramètre : un tableau de variable de type struct joueur
				le nombre de joueurs actuellement dans l'équipe
	Retour : aucun (sortie via les paramètres formels passés par adresse et/ou référence)
*/
void ajouterJoueur(joueur joueurs[], unsigned short &nbJoueurs) {
	char repondre = 'o';
	do
	{
		cout << "Entrez numéro de joueurs: ";
		int numeroJoueurSaisi = lireEntierIntervalle(1, 100);
		cout << "Entrez nom joueur: ";
		cin >> joueurs[nbJoueurs].nom;
		cout << "Entrez prenom joueur: ";
		cin >> joueurs[nbJoueurs].prenom;
		cout << "------------------------------" << endl;
		cout << "1> GARDIEN_DE_BUT " << endl;
		cout << "2> ATTAQUANT " << endl;
		cout << "3> DEFENSEUR " << endl;
		cout << "4> MILIEU_DE_TERRAIN  " << endl;
		int temp = lireEntierIntervallePo(1, 4);
		joueurs[nbJoueurs].position = (Position)temp;
		switch (joueurs[nbJoueurs].position)
		{
		case 1:
			cout << "Votre position vous avez choisir est  GARDIEN_DE_BUT  " << endl;
			break;
		case 2:
			cout << "Votre position vous avez choisir est  ATTAQUANT  " << endl;
			break;
		case 3:
			cout << "Votre position vous avez choisir est  DEFENSEUR  " << endl;
			break;
		case 4:
			cout << "Votre position vous avez choisir est  MILIEU_DE_TERRAIN  " << endl;
			break;
		}
		cout << "Voulez-vous continuer à ajouter des joueurs. Si oui choisir (O), si non choisir (N). ";
		cin >> repondre;
		joueurs[nbJoueurs].nbButs = 0;
		joueurs[nbJoueurs].noDeJoueur = numeroJoueurSaisi;
		nbJoueurs++;
		//À compléter
	} while (repondre == 'o' or repondre == 'O');

}

/*
	Tâche : fonction qui demande la saisie d'un numéro de joueur et
			cherche dans la liste des joueurs de l'équipe dans le
			but de retrouver ce joueur. Si le numéro du joueur saisi
			correspond au numéro d'un des joueurs de l'équipe, la
			fonction retourne l'indice ou se trouve le joueur dans
			le tableau, sinon la fonction affiche le message
			"Ce joueur n'existe pas" et retourne la valeur -1.
	Paramètre : un tableau de variable de type struct joueur
				le nombre de joueurs actuellement dans l'équipe
*/
int rechercherJoueur(joueur joueurs[], unsigned short nbJoueurs) {
	int numeroJoueurSaisir = lireEntierIntervalle(1, 100);
	//cout << numeroJoueurSaisir << endl;
	int i = 0;
	while (i < nbJoueurs)
	{
		if (numeroJoueurSaisir == joueurs[i].noDeJoueur) {
			return i;
		}
		i++;
	}
	cout << "Ce joueur n'existe pas" << endl;
	return -1;
}


/*
	Tâche : fonction qui permet de modifier les informations D'UN SEUL joueur
		 passé en paramètre. Les seules informations que vous pouvez modifier
		 pour un joueur sont le numéro du joueur, le nom, le prénom et la
		 position. Vous ne devez pas permettre de modifier le nombre de buts.
	Paramètre : une référence d'un joueur.
*/
void modifierJoueur(joueur &joueur) {
	char repondre = 'o';
	do
	{
		cout << "Veuillez sélectionner les informations ci-dessous pour effectuer le changement: " << endl;
		cout << "1> Numéro de joueur: " << endl;
		cout << "2> Nom: " << endl;
		cout << "3> Prenom: " << endl;
		cout << "4> Position: " << endl;
		int chagerJoueurSaisi = lireEntierIntervallePo(1, 4);
		switch (chagerJoueurSaisi)
		{
		case 1:
			cout << "Entrez nouveau numéro de joueur: ";
			joueur.noDeJoueur = lireEntierIntervalle(1, 100);
			break;
		case 2:
			cout << "Entrez nouveau nom de joueur: ";
			litChaine(joueur.nom, TAILLE_NOM);
			break;
		case 3:
			cout << "Entrez nouveau prenom de joueur: ";
			litChaine(joueur.prenom, TAILLE_NOM);

			break;
		case 4:
			int positionTemp;
			cout << "Entrez nouveau position de joueur: " << endl;
			cout << "1> GARDIEN_DE_BUT " << endl;
			cout << "2> ATTAQUANT " << endl;
			cout << "3> DEFENSEUR " << endl;
			cout << "4> MILIEU_DE_TERRAIN  " << endl;
			positionTemp = lireEntierIntervallePo(1, 4);
			joueur.position = (Position)positionTemp;
			switch (joueur.position)
			{
			case 1:
				cout << "Votre position vous avez choisir est  GARDIEN_DE_BUT  " << endl;
				break;
			case 2:
				cout << "Votre position vous avez choisir est  ATTAQUANT  " << endl;
				break;
			case 3:
				cout << "Votre position vous avez choisir est  DEFENSEUR  " << endl;
				break;
			case 4:
				cout << "Votre position vous avez choisir est  MILIEU_DE_TERRAIN  " << endl;
				break;
			}
		}
		cout << "Voulez-vous continuer à apporter des modifications aux joueurs ?. Si oui choisir (O), si non choisir (N). ";
		cin >> repondre;
	} while (repondre == 'o' or repondre == 'O');

	//À compléter
}


/*
	Tâche : fonction qui retire un joueur du tableau en fonction
			de l'indice où se trouve le joueur dans le tableau.
	Paramètre : un tableau de variable de type struct joueur
				le nombre de joueurs actuellement dans l'équipe
				l'indice où se trouve joueur dans le tableau
	Retour : aucun (sortie via les paramètres formels passés par
			 adresse et/ou référence)
*/
void retirerJoueur(joueur joueurs[], unsigned short &nbJoueurs, int indiceJoueurARetirer) {
	for (int i = indiceJoueurARetirer; i < nbJoueurs - 1; i++)
	{
		joueurs[i] = joueurs[i + 1];//Déplacer vers la gauche de la table joueurs 1 unité.
	}
	nbJoueurs--;
	//À compléter
}


/*
	Tâche : fonction qui affiche les informations D'UN SEUL joueur
			passé en paramètre.
	Paramètre : une référence constante d'un joueur pour éviter tout
				risque de modification du joueur dans la fonction.
	Retour : aucun (affichage seulement)
*/
void afficherInfoJoueur(const joueur &JOUEUR) {
	cout << "Numéro de joueur: " << JOUEUR.noDeJoueur << endl;
	cout << "Nom joueur: " << JOUEUR.nom << endl;
	cout << "Prenom joueur: " << JOUEUR.prenom << endl;
	cout << "Position de joueur:  " << JOUEUR.position << endl;
	cout << "Nombre des buts: " << JOUEUR.nbButs << endl;
	//À compléter
}

/*
	Tâche : fonction qui ajoute un but à un joueur passé par référence
			en paramètre.
	Paramètre : une référence d'un joueur
	Retour : aucun (sortie via les paramètres formels passés par
			 adresse et/ou référence)
*/
void ajouterButJoueur(joueur &joueur) {
	joueur.nbButs++;
	cout << "But ajouter " << endl;
	afficherInfoJoueur(joueur);
	//À compléter
}

/*
	Tâche : fonction qui retire un but à un joueur passé par référence
			en paramètre. La fonction doit prévoir que le nombre de but
			ne pourra pas jamais être inférieur à 0.
	Paramètre : une référence d'un joueur
	Retour : aucun (sortie via les paramètres formels passés par
			 adresse et/ou référence)
*/
void retirerButJoueur(joueur &joueur) {
	joueur.nbButs--;
	cout << "But retirer: " << endl;
	afficherInfoJoueur(joueur);
	//À compléter
}


/*
	Tâche : fonction qui affiche les joueurs de l'équipe après avoir
			demandé la saisie de la position à afficher. Aussi, ajouter
			une option permettant d'afficher tous les joueurs.
	Paramètre : un tableau de variable de type struct joueur
				le nombre de joueurs actuellement dans l'équipe
	Retour : aucun (affichage seulement)
*/
void afficherJoueursParPosition(joueur joueurs[], unsigned short nbJoueurs) {
	miniMenu();
	int positionSaisir = lireEntierIntervallePo(1, 5);
	joueurs[nbJoueurs].position = (Position)positionSaisir;
	switch (joueurs[nbJoueurs].position)
	{
	case GARDIEN_DE_BUT:
		cout << "Vous voulez affiche la position GARDIEN_DE_BUT  " << endl;
		afficherJoueurParPosition(joueurs, 1, nbJoueurs);
		break;
	case ATTAQUANT:
		cout << "Vous voulez affiche la position  ATTAQUANT  " << endl;
		afficherJoueurParPosition(joueurs, 2, nbJoueurs);
		break;
	case DEFENSEUR:
		cout << "Vous voulez affiche la position  DEFENSEUR  " << endl;
		afficherJoueurParPosition(joueurs, 3, nbJoueurs);
		break;
	case MILIEU_DE_TERRAIN:
		cout << "Vous voulez affiche la position  MILIEU_DE_TERRAIN  " << endl;
		afficherJoueurParPosition(joueurs, 4, nbJoueurs);
		break;
	default:
		cout << "Vous voulez affiche tout types confondus  " << endl;
		afficherJoueurParPosition(joueurs, 1, nbJoueurs);
		cout << "=========================================" << endl;
		afficherJoueurParPosition(joueurs, 2, nbJoueurs);
		cout << "=========================================" << endl;
		afficherJoueurParPosition(joueurs, 3, nbJoueurs);
		cout << "=========================================" << endl;
		afficherJoueurParPosition(joueurs, 4, nbJoueurs);

		break;
	}
	//À compléter
}

/*
	Tâche : fonction qui calcule et affiche le nombre total de but(s)
			marqué(s) pour toutes l'équipes.
	Paramètre : un tableau de variable de type struct joueur
				le nombre de joueurs actuellement dans l'équipe
	Retour : aucun (affichage seulement)
*/
void afficherTotalDeButDeLEquipe(joueur joueurs[], unsigned short nbJoueurs) {
	int TotalDeBut = 0;

	for (int i = 0; i < nbJoueurs; i++) {
		TotalDeBut += joueurs[i].nbButs;
	}
	cout << "Le nombre total de buts marqués par l'équipe est: " << TotalDeBut << endl;
	//À compléter
}

//Menu supplémentaire pour le menu principal dans l'article numéro 7
void miniMenu() {
	cout << "    1>  Gardien de but " << endl;
	cout << "    2>  Attaquant " << endl;
	cout << "    3>  Défenseur " << endl;
	cout << "    4>  Milieu de terrain " << endl;
	cout << "    5>  Tout types confondus " << endl;
}

//Lire entier entre min et max par numero de joueur
int lireEntierIntervalle(int min, int max) {
	int n;
	cout << "Veuillez saisir le numéro du joueur entre " << min << " et " << max << endl;
	cin >> n;
	while (cin.fail() or cin.peek() != '\n' or n<min or n>max)
	{
		cin.clear();
		cin.ignore(512, '\n');
		cout << "Erreur. Veuillez réessayer entrez le numéro entre " << min << " et " << max << endl;
		cin >> n;
	}
	cin.ignore(512, '\n');
	return n;
}

//Lire entier entre min et max par numero de position
int lireEntierIntervallePo(int min, int max) {
	int n;
	cout << "Veuillez entrer le numéro de position du joueur " << min << " et " << max << endl;
	cin >> n;
	while (cin.fail() or cin.peek() != '\n' or n<min or n>max)
	{
		cin.clear();
		cin.ignore(512, '\n');
		cout << "Erreur. Veuillez réessayer entrez le numéro entre " << min << " et " << max << endl;
		cin >> n;
	}
	cin.ignore(512, '\n');
	return n;
}

//fonction afficher joureur par position supplément
void afficherJoueurParPosition(joueur joueurs[], int unPosition, int nbJoueurs) {
	for (int i = 0; i < nbJoueurs; i++)
	{
		if (joueurs[i].position == unPosition)
		{
			afficherInfoJoueur(joueurs[i]);
		}
	}
}

void litChaine(char chaine[], unsigned short int nbCharMax) {
	cout << "Saisir un texte (max " << nbCharMax << " caractaires) : " << endl;
	cin.getline(chaine, nbCharMax);
	while (cin.fail()) {
		cin.clear();
		cin.ignore(512, '\n');
		cout << endl << "Erreur: Saisir un texte (max " << nbCharMax << " caractaires) : " << endl;
		cin.getline(chaine, nbCharMax);
	}
}