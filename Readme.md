# Navy

## Projet

Ce jeu a été réalisé en C sans librairie.

Dans ce projet, le but était de réussir à connecter deux terminaux ensemble grâce aux signaux pour pouvoir réalisé une bataille navale.

Alors certes le fait de devoir être sur le même ordinateur pour l'utiliser limite un peu sa réelle utilisation, mais le défis technique était de taille

## Résultat

<div style="display: flex; flex-wrap: wrap">
    <img src="/images/connection.png" width=315 height=300 />
    <img src="/images/boucle.png" width=315 height=300 />
    <img src="/images/victoire.png" width=315 height=300 />
</div>

Dans ce jeu, la gestion des tours, des erreurs dans les coups, de la victoire et défaite, ainsi que la gestion des cartes, sont entièrement fonctionnelles.

## Jouer au jeu

### Prérequis
    - C
    - Make

### Lancer le projet
```bash
make
#Player 1
./navy [map]
#Player 2
./navy [PID] [map]
```
