# Ft_select - 42 Project.

**Sujet:**

Des programmes comme votre shell, aptitude, top, tig, mcabber, dwarf fortress,
zangband ou herrie ont tous au moins deux points communs : ces programmes s’executent
dans un terminal et proposent une interface utilisateur avancée malgrès l’absence
d’interface graphique fenêtrée à laquelle Microsoft Windows et OSX (dans son utilisation
Starbucks) vous ont habitué.
Réaliser une interface utilisateur pour un programme qui s’execute dans un terminal
est possible et demande un travail de programmation qu’il est important de maitriser
car dans son mode "brut", un terminal ne fait pas grand chose. Pour vous en convaincre,
lancez la commande cat sans argument et appuyez sur des touches ou des combinaisons
de touches de votre clavier...
Dans cette manipulation, tant que vous appuyez sur des touches alphanumériques,
rien de particulier n’est à constater. Par contre, si vous appuyez sur les flèches, la touche
echap ou les touches fn par exemple, des caractères arbitraires s’affichent... Refaites la
manipulation dans votre shell maintenant. Vous êtes habitués à ce que la flèche gauche
recule le curseur d’une colone. Pourquoi ces différences entre cat et votre shell ?
Votre terminal gère beaucoup de choses pour vous sans que vous y prêtiez la moindre
attention, comme par exemple l’affichage des caractères au fur et à mesure que vous les
tapez ou encore la bufferisation par ligne.
Si maintenant vous vous demandez comment vous pouvez prendre le contrôle de votre
terminal, ce projet est fait pour vous. Vous y apprendrez à configurer votre termial via
la structure "struct termios" et à utiliser ses capacités, les fameux "termcaps".
