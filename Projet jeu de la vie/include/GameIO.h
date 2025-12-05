#pragma once

#include <string>
#include "Game.h"
#include "ConwayRule.h"

// Charge un Game à partir d'un fichier texte.
// Format :
//   width height
//   lignes de 0/1
Game loadGameFromFile(const std::string& filePath);

// Sauvegarde l'état courant de la grille dans un fichier texte.
void saveGridToFile(const Game& game, const std::string& filePath);
