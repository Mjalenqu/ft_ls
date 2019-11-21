Partie obligatoire

• Vous devez recoder la commande ls du système.

• Son comportement doit être identique à celui de la commands ls originale du système, avec les bémols suivants :

• Parmi les nombreuses options disponibles sur la ligne de commande, il vous est demandé de réaliser les suivantes : -l, -R, -a, -r et -t.

• Nous vous recommandons lourdement de prendre en compte les implications de l’option -R dès le début de votre code...

• Vous n’avez pas à gérer le formatage en plusieurs colonnes de la sortie quand l’option -l n’est pas passée.

• Vous n’êtes pas obligés de gérer les ACL et les attributs étendus.

• L’affichage général, selon chaque option, doit rester sensiblement identique à celui de la commande système. Une certaine tolérance est appliquée sur le padding et la mise en page, mais il ne doit manquer aucune information.

Partie bonus

Les bonus ne seront évalués que si votre partie obligatoire est EXCELLENTE. On entend par là qu’elle est entièrement réalisée, que votre gestion d’erreur est au point, même dans des cas vicieux, ou des cas de mauvaise utilisation. Dans le cas contraire, vos bonus seront intégralement IGNORÉS. Voici quelques idées de bonus intéressants à réaliser, voire même utiles. Vous pouvez évidemment ajouter des bonus de votre invention, qui seront évalués à la discrétion de vos correcteurs.

• Gestion des ACL et des attributs étendus

• Gestion des colonnes sans l’option -l. (man 4 tty)

• Gestion des options -u, -f, -g, -d, ...

• Gestion d’affichage en couleur (Similaire à l’option -G)

• Optimisation de votre code (Quel est le temps de réponse de votre ls sur un GROS ls -lR par exemple ?)
