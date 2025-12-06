# Diagramme de Classes – Jeu de la Vie


---

# Présentation générale du modèle

Ce document présente et explique le diagramme de classes UML du projet Jeu de la Vie, implémenté en C++ dans une architecture orientée objet.
L’objectif de cette conception est d’obtenir un système :

- extensible,
- facile à maintenir,
- conforme aux principes SOLID,
- et adapté à l’évolution des règles du jeu.

L’élément central du modèle repose sur l’idée suivante :
une cellule ne stocke pas un simple booléen, mais un objet représentant son état (CellState).

---

# Architecture des classes

## 1. Classe abstraite CellState

CellState représente un état général possible d’une cellule.
Elle sert de classe de base pour tous les états concrets (vivante, morte, obstacle).

Méthodes principales :
- bool isAlive() const
- char toChar() const

---

## 2. Classe AliveState

Représente une cellule vivante.
- isAlive() → true
- toChar() → '1'

---

## 3. Classe DeadState

Représente une cellule morte.
- isAlive() → false
- toChar() → '0'

---

## 4. Classe ObstacleState

Représente une cellule bloquante.
- isAlive() → false
- toChar() → 'X'

---

## 5. Classe Cell

Cell modélise une cellule de la grille.
Contient :
- unique_ptr<CellState> m_state

Responsabilités :
- isAlive(), toChar() délégués à l’état
- setAlive(), setDead(), setObstacle()

---

# Relations entre les classes

Héritage :
CellState <|-- AliveState  
CellState <|-- DeadState  
CellState <|-- ObstacleState  

Composition :
Cell *---- CellState

---

# Conclusion

Ce modèle constitue la base du projet Jeu de la Vie, permettant une extension propre
des règles, de l’affichage SFML, et du moteur du jeu.
