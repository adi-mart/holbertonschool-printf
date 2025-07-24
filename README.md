# 🖨️ holbertonschool-printf

## 📌 Description
Ce projet a été réalisé dans le cadre du cursus Holberton School.
L'objectif est de réimplémenter la fonction `printf` du langage C, afin d'apprendre à gérer les arguments variables, les chaînes de caractères, et à structurer un code modulaire.

## ✅ Fonctionnalités principales
- 📦 Affichage de texte formaté avec les spécificateurs :
  - `%c` : Affiche un caractère
  - `%s` : Affiche une chaîne
  - `%d`, `%i` : Affiche un entier signé
  - `%%` : Affiche un pourcentage

## 🗂️ Structure du projet

```bash
holbertonschool-printf/
├── _printf.c              # Fonction principale (_printf)
├── func_print.c           # Fonctions : print_char, print_string, print_prct
├── print_int.c            # Affichage récursif des entiers (%d, %i)
├── main.c                 # Fichier de test
├── main.h                 # Déclarations & structure format_t
├── man_3_printf           # Page de documentation man (optionnelle)
├── flowchart_printf.jpeg  # Image du flowchart (_printf)
└── README.md              # Ce fichier

## 🚀 Getting Started
### ✅ Prerequisites
- Un compilateur C (GCC recommandé)
- Système testé sur :
  - ✅ Ubuntu 20.04+
  - ✅ macOS
  - ✅ Windows (avec WSL ou MinGW)

### 🛠️ Compilation
```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o printf
```

## 💡 Exemple d’utilisation
```c
_printf("[INFO] Utilisateur : %s | Score : %d%%\n", "Alice", 98);
// Affiche : [INFO] Utilisateur : Alice | Score : 98%
```

## 🧠 Flowchart du fonctionnement de _printf
je veux mettre une image ici 👈 

## 🧾 Explication simple du flowchart
1. 🔁 On parcourt la chaîne de format caractère par caractère.
2. Si ce n’est pas un % → on affiche normalement.
3. Si on trouve % :
   - ✅ Si le caractère suivant est un format connu : on affiche avec la bonne fonction (`print_int`, `print_char`, etc.)
   - ❌ Sinon : on affiche % puis ce caractère.
4. 📏 On compte chaque caractère affiché.
5. 🧮 On retourne ce total à la fin.
