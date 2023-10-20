animal(elefante).
animal(leon).
animal(tigre).
animal(vaca).
animal(caballo).
animal(lobo).
animal(zorro).
animal(oveja).
animal(cebra).
animal(cerdo).

alimentacion(leon,carnivoro).
alimentacion(tigre,carnivoro).
alimentacion(lobo,carnivoro).
alimentacion(zorro,carnivoro).

alimentacion(vaca,herviboro).
alimentacion(caballo,herviboro).
alimentacion(oveja,herviboro).
alimentacion(cebra,herviboro).

caracteristicas(leon,tiene_melena).
caracteristicas(tigre,tiene_rayas).
caracteristicas(lobo,tiene_pelo).
caracteristicas(zorro,tiene_pelo).
caracteristicas(vaca,da_leche).

carnivoro(X):-alimentacion(X,carnivoro).
herviboro(X):-alimentacion(X,herviboro).

tiene_pelo(X):-caracteristicas(X,tiene_pelo).
tiene_melena(X):-caracteristicas(X,tiene_melena).