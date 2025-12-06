# Projet POO – Jeu de la Vie

## Membres du groupe
- **Tiachacht Younes**
- **Ziane Neil**

---

# Présentation du projet

Ce projet implémente le **Jeu de la Vie** de John Conway en **C++**, en appliquant les principes de la programmation orientée objet et les bonnes pratiques SOLID.

L’application propose :

- un **mode console** permettant de lire une grille, simuler des itérations et exporter les résultats ;
- un **mode graphique** utilisant **SFML**, permettant de visualiser la simulation en temps réel ;
- plusieurs **extensions bonus** : grille torique, obstacles, délai entre itérations, etc.

---

# Règles du Jeu de la Vie

À chaque itération :

- Une cellule morte ayant **exactement trois voisines vivantes** devient vivante.
- Une cellule vivante ayant **deux ou trois voisines vivantes** reste vivante, sinon elle meurt.
- Chaque cellule possède **8 voisines**.
- La grille peut être en **mode torique**, où les bords sont connectés entre eux.

---

# Fonctionnalités principales

## Mode console

- Lecture d’un fichier `grille.txt` décrivant la grille initiale.
- Exécution d’un nombre configurable d’itérations.
- Sauvegarde automatique des états successifs dans un dossier `<nom>_out/`.
- Format d’entrée conforme à l’énoncé.

## Mode graphique (SFML)

- Affichage temps réel de la simulation.
- Contrôles :

| Touche | Action |
|-------|--------|
| Espace | Pause / reprise |
| N | Itération suivante |
| R | Remplissage aléatoire |
| C | Effacer la grille |

### Couleurs :
- Vivante : **vert**  
- Morte : **gris foncé**  
- Obstacle : **rouge**

---

# Extensions implémentées (bonus)

## Grille torique
Les cellules des bords sont connectées entre elles.

## Cellules obstacles
- Ne changent jamais d’état.
- Représentées en rouge.
- Ignorées dans le calcul des règles.

---

# Architecture et conception

L’application suit une architecture claire, séparant la logique métier du rendu graphique.
```
src/
├── CellState.h / .cpp (classe abstraite d’état)
├── AliveState.h / .cpp (état vivant)
├── DeadState.h / .cpp (état mort)
├── ObstacleState.h / .cpp (état obstacle)
├── Cell.h / .cpp (représentation d’une cellule)
├── Grid.h / .cpp (grille de cellules)
├── Rule.h / .cpp (règles abstraites)
├── ConwayRule.h / .cpp (règle de Conway)
├── Game.h / .cpp (logique du jeu)
├── GridRenderer.h / .cpp (rendu SFML)
├── SfmlApp.h / .cpp (mode graphique)
├── GameIO.h / .cpp (lecture/écriture fichiers)
├── Tests.h / .cpp (tests unitaires)
├── main.cpp (entrée du programme)
```
---

# Format du fichier d’entrée (`grille.txt`)

Exemple :
```
5 10
0 1 0 0 0 0 0 0 0 0
1 1 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
```

# Fichiers de sortie

Un dossier est automatiquement généré :

- grille_out/
- step_0.txt
- step_1.txt
- step_2.txt
- ...

Chaque fichier représente une itération.

---

# Tests unitaires

Les tests permettent de vérifier :

- la stabilité des motifs (bloc 2×2) ;
- la cohérence des règles d’évolution ;
- le fonctionnement correct du mode torique ;
- la gestion des obstacles.

Les tests se trouvent dans `tests.cpp`.

---

# Compilation

## Linux / macOS (g++)
```bash
g++ -std=c++20 -Iinclude src/*.cpp -o JeuDeLaVie \
    -lsfml-graphics -lsfml-window -lsfml-system

Windows (Visual Studio)

Ajouter les fichiers .cpp au projet.

Configurer l’inclusion de SFML.

Lier les bibliothèques :

sfml-graphics

sfml-window

sfml-system
