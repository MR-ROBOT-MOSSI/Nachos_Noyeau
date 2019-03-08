1/
Lors d'un changement de contexte il faut sauvegarder :
	- Les registres de la machine MIPS (SaveUserState)
	- Les registres de la machine hôte (SaveKernelState)
	
2/
Variable des liste des threads prêts à s'éxecuter : readyList
Le thread élu actif appartient à cette liste
On accède au thread actif avec la variable g_current_thread

3/
La variable g_alive sert à lister tout les threads crées (prêts, actifs, bloqués)
readyList ne recense que les threads prêts mais pas les threads bloqués

4/
Les listes sont des chainons (ListElement)
Un élément d'une liste est un pointeur vers l'élément mis en liste et sa priorité dans la liste qui détermine sa place dans la liste
Grâce à ce mécanisme, il n'y a pas besoin d'allouer ou désallouer de la mémoire

5/
Un thread bloqué sur un sémaphore va être placé dans la queue du sémaphore (ListInt *queue)

6/
Il faut masquer les interruptions avec g_machine->interrupt->SetStatus(INTERRUPTS_OFF)

7/
SwitchTo de g_scheduler sert a faire un changment de contexte, régule le CPU avec nextThread. Enregistre le contexte du thread courant (prêt ou bloqué) et charge le contexte du nouveau thread
Thread_context est une structure qui sert à contenir le contexte d'un thread
Simultor_context est une structure qui sert à contenir le contexte d'un simulateur du thread
SaveSimulatorState met le contexte courant dans thread_context
RestoreSimulatorState modifie le contexte courant avec le contexte de thread_context
SaveProcessorState devra sauver le contexte du thread et le contexte de la machine (simulator)
RestoreProcessorState devra restaurer le contexte du thread et le contexte de la machine (simulator)

8/
Le champ type est utilisé pour connaitre le type de l'objet utiliser par l'appel système pour vérifier que le bon type est attendue en comparant avec typeId

1/
Messages debugge disponibles option -s pour affichage des registres et exécution du programme utilisateur

2/
Oui car nachos s'exécute sur une machine virtuelle 

3/
Non car le programme est exécuté dans nachos et lui n'a pas directement de debugger mais il est possible de regarder l'état de nachos pour en déduire l'état du programme
