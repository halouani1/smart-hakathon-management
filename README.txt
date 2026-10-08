PROJET SMART + HACKATHON — GESTION DES EVALUATEURS

Version avec 2 métiers fonctionnels :
1. Tech Challenge Analyst
2. Délibération collaborative du jury

Les deux métiers sont accessibles directement depuis les boutons du pied de page.

METIER 1 — TECH CHALLENGE ANALYST
- Affiche des candidats/projets avec score et compatibilité.
- Sélection d'un candidat.
- Bouton "Analyser le candidat" affiche une analyse et une recommandation.

METIER 2 — DELIBERATION COLLABORATIVE DU JURY
- Sélection d'un évaluateur.
- Sélection d'un candidat.
- Vote Pour / Neutre / Contre.
- Enregistrement des votes.
- Calcul automatique de la décision : Validé / Refusé / À départager.
- Calcul du consensus global du jury.
- Réinitialisation des votes.

GESTION DES EVALUATEURS
- 6 évaluateurs d'exemple : 4 actifs et 2 inactifs.
- Ajouter / Modifier / Supprimer / Annuler.
- Recherche, tri et export CSV.
- Compteurs automatiques.

IMPORTANT POUR LE CRASH SIGSEGV
Le QTableWidget reste vide dans le .ui. Les lignes sont créées après setupUi() en C++.
Cela évite le crash QTableWidgetItem::setText() observé pendant setupUi().

OUVERTURE
Qt Creator : ouvrir SmartHackathon_GestionEvaluateurs.pro
Puis Clean, Run qmake, Rebuild et Run.
