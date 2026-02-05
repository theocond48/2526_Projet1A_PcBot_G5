# 2526_Projet1A_PcBot_G5

## Rappels Git

### Clé SSH

Créer une clé :

```bash
ssh-keygen
```

Afficher la clé ssh

```bash
cat /c/Users/<USER>/.ssh/id_ed25519.pub
```

### Cloner un projet

Clonage = récupérer le projet. A faire une fois par projet. 

```bash
cd <chemin/vers/le/bon/dossier>
git clone git@github.com:theocond48/2526_Projet1A_PcBot_G5.git
```

### Voir l'état du projet

```bash
git status
```

### Pousser des modifications 

On dit "committer" ou "faire un commit".
A faire à chaque fois qu'on a une nouvelle version fonctionnelle.

```bash
git add .   # Ajoute tous les fichiers
git commit -m "Message"
git push    # Pousse les modifications
```

### Récupérer les dernières mises à jour

A faire à chaque fois qu'on commence à travailler.

```bash
git pull
```