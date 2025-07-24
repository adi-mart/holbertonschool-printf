# _printf - Fonction printf personnalisée

## Description
Ce projet implémente une version personnalisée de la fonction `printf` de la bibliothèque standard C. La fonction `_printf` produit une sortie selon un format spécifié et écrit vers la sortie standard.

## Prototype
```c
int _printf(const char *format, ...);
```

## Fonctionnalités supportées

### Spécificateurs de format
- `%c` : Imprime un caractère unique
- `%s` : Imprime une chaîne de caractères
- `%d` : Imprime un entier décimal signé
- `%i` : Imprime un entier décimal signé (identique à %d)
- `%%` : Imprime un caractère littéral '%'

## Structure du projet

```
holbertonschool-printf/
├── _printf.c          # Fonction principale _printf
├── func_print.c       # Fonctions d'impression pour chaque type
├── main.h             # Fichier d'en-tête avec prototypes et structures
├── main.c             # Fichier de test principal
├── README.md          # Documentation du projet
├── man_3_printf       # Page de manuel personnalisée
└── flowchart_printf   # Diagramme de flux de l'algorithme (à ajouter)
```

## Fichiers

### `main.h`
Contient :
- Les prototypes de toutes les fonctions
- La structure `format_t` qui associe les spécificateurs aux fonctions
- Les includes nécessaires

### `_printf.c`
Fonction principale qui :
- Parse la chaîne de format
- Gère les arguments variables avec `va_list`
- Appelle les fonctions appropriées selon le spécificateur
- Retourne le nombre de caractères imprimés

### `func_print.c`
Contient les fonctions d'impression spécialisées :
- `_putchar()` : Écrit un caractère vers stdout
- `print_char()` : Imprime un caractère
- `print_string()` : Imprime une chaîne
- `print_prct()` : Imprime le caractère '%'
- `print_int()` : Imprime un entier
- `print_number()` : Fonction récursive pour l'affichage des nombres

## Installation et Utilisation

```bash
# Cloner et tester
git clone https://github.com/adi-mart/holbertonschool-printf.git
cd holbertonschool-printf
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
./printf

# Utiliser dans votre projet
# Copiez: _printf.c, func_print.c, main.h
# Compilez: gcc *.c votre_fichier.c -o votre_programme
```


### Exemple de code
```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("Number: %d\n", 42);
    _printf("Character: %c\n", 'A');
    _printf("Percentage: %%\n");
    return (0);
}
```

### Sortie attendue
```
Hello, World!
Number: 42
Character: A
Percentage: %
```

## Valeur de retour
La fonction `_printf` retourne :
- Le nombre de caractères imprimés (sans compter le '\0' terminal)
- `-1` en cas d'erreur (format NULL ou format se terminant par '%')

## Tests

Le fichier `main.c` contient des tests de base comparant la sortie de `_printf` avec la fonction `printf` standard.

Pour exécuter les tests :
```bash
./printf
```

## Algorithme

1. **Initialisation** : Déclaration de la va_list et du tableau de structures format_t
2. **Validation** : Vérification que le format n'est pas NULL
3. **Parcours** : Itération caractère par caractère dans la chaîne de format
4. **Détection** : Si '%' est trouvé, analyse du spécificateur suivant
5. **Exécution** : Appel de la fonction correspondante ou gestion d'erreur
6. **Comptage** : Accumulation du nombre de caractères imprimés


## Gestion des erreurs

- **Format NULL** : Retourne -1
- **Format se terminant par '%'** : Retourne -1
- **Spécificateur invalide** : Imprime '%' suivi du caractère invalide
- **String NULL** : Imprime "(null)"


## Manuel personnalisé

                        Library Functions Manual -  _printf

    NAME
        _printf - formatted output conversion

    LIBRARY
        Standard C library (libc, -lc)

    SYNOPSIS
    #include <stdio.h>
        int _printf(const char *format, ...);

    DESCRIPTION
        The functions in the printf() family produce output according to a
        format as described below.

        Format of the format string :
        The format string is a character string, beginning and ending in
        its initial shift state, if any. The format string is a character string composed of zero or
        more directives: ordinary characters (not %), which are
        copied unchanged to the output stream; and conversion
        specifications, each of which results in fetching zero or more
        subsequent arguments.  Each conversion specification is introduced
        by the character %, and ends with a conversion specifier.

    CONVERSION SPECIFIERS
        A character that specifies the type of conversion to be applied.
        The conversion specifiers and their meanings are:

        d, i   The int argument is converted to signed decimal notation.
                The precision, if any, gives the minimum number of digits
                that must appear; if the converted value requires fewer
                digits, it is padded on the left with zeros.  The default
                precision is 1.  When 0 is printed with an explicit
                precision 0, the output is empty.

        c      If no l modifier is present, the int argument is converted
                to an unsigned char, and the resulting character is
                written.

        s      If no l modifier is present: the const char * argument is
                expected to be a pointer to an array of character type
                (pointer to a string).  Characters from the array are
                written up to (but not including) a terminating null byte
                ('\0'); if a precision is specified, no more than the
                number specified are written.  If a precision is given, no
                null byte need be present; if the precision is not
                specified, or is greater than the size of the array, the
                array must contain a terminating null byte.

        %      A '%' is written.  No argument is converted.  The complete
                conversion specification is '%%'.

    RETURN VALUE
        Upon successful return, these functions return the number of bytes
        printed (excluding the null byte used to end output to strings).

    EXAMPLES

        #include <stdio.h>
        #include "main.h"

    int main(void)
    {
        _printf("Hello\n");
        _printf("%d", 39);
        _printf("%s", "This is a string");
        _printf("%c", H);

        return (0);
    }

    version 1.0                                                     July 2025                                                         _prinft


## Flowchart de l'algorithme

Un diagramme de flux détaillé illustrant le fonctionnement de `_printf` est disponible. Ce flowchart montre :
- Le processus de parsing de la chaîne de format
- La logique de décision pour chaque spécificateur
- La gestion des cas d'erreur
- Le flux de retour des valeurs

*[Insérer ici votre flowchart ou le lien vers le fichier image]*



## Limitations

Cette implémentation ne supporte pas :
- Les modificateurs de largeur (ex: %10d)
- Les modificateurs de précision (ex: %.2f)
- Les nombres en virgule flottante (%f, %g, %e)
- Les formats octaux (%o) et hexadécimaux (%x, %X)
- Les formats non signés (%u)
- Les modificateurs de longueur (l, h, etc.)


## Auteurs
Projet développé dans le cadre du cursus Holberton School.
Par Aurélie et Mohamed

## Licence
Ce projet est à des fins éducatives.

---

*Ce README documente l'implémentation actuelle de la fonction _printf. Les fonctionnalités peuvent être étendues dans les futures versions.*