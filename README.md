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

# Projet PCBot:

**Objectif :** Concevoir un robot communicant (Swarm) pour la cartographie d'environnement.
**Volume horaire :** 40 heures (10 séances x 4h).

- Travail en groupe réalisé par: Youssef Chemrakhi, Théodore Condette, Rayan Taoussi, Samy, Maoua.


# I - Phase 1 : Conception et Saisie de Schéma
- **Séance 1 : Initialisation & Spécifications**

- **Définition du Besoin**
  - Liste des fonctionnalités
  - Schéma architectural
- **Planification et Matériel**
  - Planning prévisionnel
  - Choix des composants



# 1 - Liste des fonctionnalités
Le robot doit être capable de:
- **Navigation et Évitement d'obstacles :** Détection d'objets en temps réel via les capteurs **VL53L0X (TOF)** pour ajuster la trajectoire.
- **Localisation Relative:** Suivi du déplacement et de l'orientation grâce à la centrale inertielle **LSM6DSOX** (Accéléromètre/Gyroscope).
- **Cartographie Collaborative :** Envoi des points de données de l'environnement vers les autres robots ou une station de base via le module **nRF24**.
- **Gestion de Swarm :** Capacité à recevoir des instructions ou à partager sa position pour éviter que deux robots ne couvrent la même zone.
- **Pilotage de Puissance :** Contrôle précis de la vitesse et de la direction des micro-moteurs **DFR1224** via le driver **DRV8411A**.
- **Autonomie Énergétique :** Recharge sécurisée de la batterie Li-ion et monitoring de la tension via le contrôleur **BQ25896**.


# 2 - Schéma architectural

Le schéma ci-dessous illustre l'organisation du système. Le microcontrôleur (MCU) agit comme le cerveau central, coordonnant les capteurs (entrées), les actionneurs (sorties) et la communication.

```mermaid
graph TD
    %% Alimentation
    subgraph Power_System [Gestion Énergie]
        BAT[Batterie Li-ion] --- BMS[BMS: BQ25896]
        BMS --> MCU[STM32L476]
    end

    %% Capteurs
    subgraph Perception [Capteurs / Entrées]
        TOF[Télémètres: VL53L0X] -- I2C --> MCU
        IMU[Centrale Inertielle: LSM6DSOX] -- I2C --> MCU
    end

    %% Communication
    subgraph Comms [Lien Essaim]
        nRF[Radio: nRF24L01] <-->|SPI| MCU
    end

    %% Actionneurs
    subgraph Motion [Actionneurs / Sorties]
        MCU -- PWM --> DRV[Driver: DRV8411]
        DRV --> M1[Moteur Gauche: DFR1224]
        DRV --> M2[Moteur Droit: DFR1224]
    end

    %% Styles
    style MCU fill:#f9f,stroke:#333,stroke-width:2px
    style BMS fill:#dfd
    style nRF fill:#ddf
```



# 3 - Planning Prévisionnel - Projet PCBot

## Phase 1 : Conception et Saisie de Schéma
- **Séance 1 : Initialisation & Spécifications**
  - Formation du groupe.
  - Création du dépôt Git et ajout du professeur (laurent.fiack@ensea.fr).
  - Étude des composants : Capteurs TOF, Accéléromètre, nRF24, Batterie/Chargeur.
- **Séance 2 : Saisie de schéma**
  - Début de la saisie sur KiCad des blocs d'alimentation et du microcontrôleur.
- **Séance 3 : Revue de schéma & Finalisation**
  - Revue critique des connexions.
  - Finalisation du schéma complet avant les vacances de février.

## Phase 2 : Routage et Fabrication (Deadline Stricte)
- **Séance 4 : Placement et Routage**
  - Placement des composants sur le PCB.
  - Routage des pistes.
- **Séance 5 : Revue de routage & Commande**
  - **Jalon critique :** Validation finale du routage.
  - Génération et envoi des fichiers de fabrication (Gerber).

## Phase 3 : Firmware et Intégration
- **Séance 6 : Tests préliminaires & Firmware**
  - Tests sur cartes de développement.
  - Développement des drivers pour les capteurs TOF et le module nRF24.
- **Séance 7 : Développement Firmware**
  - Implémentation des algorithmes de cartographie et de communication Swarm.
- **Séance 8 : Firmware & Soudure**
  - Réception possible des PCB.
  - Assemblage (soudure) et tests de continuité.
- **Séance 9 : Intégration Finale & Débogage**
  - Tests en conditions réelles du robot.
  - Correction des derniers bugs du firmware.

## Phase 4 : Clôture
- **Séance 10 : Finitions & Démo**
  - 2h : Préparation finale et finitions.
  - 2h : Présentation et démonstration du projet.






graph TD
    %% Processeur Central
    STM[STM32L4 Microcontroller]

    %% Section Energie
    subgraph Power [GESTION ÉNERGIE]
        BMS[BMS: BQ25896]
        BAT((Batterie Li-ion))
    end

    %% Section Perception
    subgraph Sensors [PERCEPTION]
        TOF[Télémètre: VL53L0X]
        IMU[Centrale Inertielle: LSM6DSOX]
    end

    %% Section Comms
    subgraph Comms [COMMUNICATION]
        NRF[Radio: nRF24L01+]
    end

    %% Section Propulsion
    subgraph Drive [PROPULSION]
        DRV[Driver: DRV8411]
        M1(Moteur G: DFR1224)
        M2(Moteur D: DFR1224)
    end

    %% Connexions avec identification des BUS
    BAT --- BMS
    BMS -- "Bus I2C (Adresse 0x6B)" --> STM
    TOF -- "Bus I2C (Adresse 0x52)" --> STM
    IMU -- "Bus I2C (Adresse 0x6A)" --> STM
    
    NRF -- "Bus SPI (Fast Data)" --> STM
    
    STM -- "Signaux PWM (Timers)" --> DRV
    DRV -- "Phase A/B" --> M1
    DRV -- "Phase A/B" --> M2

    %% Styles de visibilité
    classDef mcu fill:#e63946,stroke:#333,stroke-width:2px,color:#fff;
    classDef pwr fill:#a8dadc,stroke:#457b9d,stroke-width:2px;
    classDef sns fill:#f1faee,stroke:#1d3557,stroke-width:2px;
    classDef rad fill:#457b9d,stroke:#1d3557,stroke-width:2px,color:#fff;
    classDef mot fill:#f4a261,stroke:#e76f51,stroke-width:2px;

    class STM mcu;
    class BMS,BAT pwr;
    class TOF,IMU sns;
    class NRF rad;
    class DRV,M1,M2 mot;